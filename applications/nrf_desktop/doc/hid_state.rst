.. _nrf_desktop_hid_state:

HID state module
################

.. contents::
   :local:
   :depth: 2

The |hid_state| is required for generating reports from input data.
It is responsible for the following operations:

* Aggregating data from user input sources.
* Tracking state of the HID report subscriptions.
* Forming the HID reports in either report or boot protocol.
* Transmitting the HID reports to the right subscriber.
* Sending :c:struct:`led_event` based on the HID keyboard LED output reports.

Module events
*************

.. include:: event_propagation.rst
    :start-after: table_hid_state_start
    :end-before: table_hid_state_end

.. note::
    |nrf_desktop_module_event_note|

Configuration
*************

To enable the |hid_state|, use the :ref:`CONFIG_DESKTOP_HID_STATE_ENABLE <config_desktop_app_options>` Kconfig option that is implied by the :ref:`CONFIG_DESKTOP_ROLE_HID_PERIPHERAL <config_desktop_app_options>` option.
An nRF Desktop peripheral uses the |hid_state| to generate HID reports based on the user input.
For details related to HID configuration in the nRF Desktop, see the :ref:`nrf_desktop_hid_configuration` documentation.

To send boot reports, enable the respective Kconfig option:

* :ref:`CONFIG_DESKTOP_HID_BOOT_INTERFACE_KEYBOARD <config_desktop_app_options>` - This option enables sending keyboard boot reports.
* :ref:`CONFIG_DESKTOP_HID_BOOT_INTERFACE_MOUSE <config_desktop_app_options>` - This option enables sending mouse boot reports.

Number of supported HID data subscribers
========================================

If your application configuration supports more than one HID data subscriber, you must align the maximum number of HID data subscribers that can be supported simultaneously (:ref:`CONFIG_DESKTOP_HID_STATE_SUBSCRIBER_COUNT <config_desktop_app_options>`).
For example, to use a configuration that allows to simultaneously subscribe for HID reports from HID over GATT (BLE) and a single USB HID instance, set the value of this Kconfig option to ``2``.
See the `Tracking state of transports`_ section for more details about HID subscribers.

HID keymap
==========

The HID state module uses the :ref:`nrf_desktop_hid_keymap` to map an application-specific key ID to a HID report ID and HID usage ID pair.
The module selects the :ref:`CONFIG_DESKTOP_HID_KEYMAP <config_desktop_app_options>` Kconfig option to enable the utility.
Make sure to configure the HID keymap utility.
See the utility's documentation for details.

HID keyboard LEDs
=================

You must define which hardware LEDs are used to display state of the HID keyboard LEDs report and LED effects that should be used to display the state.
See documentation of :ref:`caf_leds` for details about LED effects.

You must create a configuration file with the following data:

* ``keyboard_led_on`` - LED effect defined to represent LED turned on by the host.
* ``keyboard_led_off`` - LED effect defined to represent LED turned off by the host.
* ``keyboard_led_map`` - IDs of the hardware LEDs used to represent state of the HID keyboard LED.

For example, the file contents should look like follows:

.. code-block:: c

	#include "hid_keyboard_leds.h"

	static const struct led_effect keyboard_led_on = LED_EFFECT_LED_ON(LED_COLOR(255, 255, 255));
	static const struct led_effect keyboard_led_off = LED_EFFECT_LED_OFF();

	static const uint8_t keyboard_led_map[] = {
		[HID_KEYBOARD_LEDS_NUM_LOCK] = 2,
		[HID_KEYBOARD_LEDS_CAPS_LOCK] = 3,
		[HID_KEYBOARD_LEDS_SCROLL_LOCK] = LED_UNAVAILABLE,
		[HID_KEYBOARD_LEDS_COMPOSE] = LED_UNAVAILABLE,
		[HID_KEYBOARD_LEDS_KANA] = LED_UNAVAILABLE,
	};

You must define all of the mentioned data in this configuration file, and specify its location with the :ref:`CONFIG_DESKTOP_HID_STATE_HID_KEYBOARD_LEDS_DEF_PATH <config_desktop_app_options>` Kconfig option.

.. note::
   The configuration file should be included only by the configured module.
   Do not include the configuration file in other source files.

Queuing keypresses
==================

The module selects the :ref:`CONFIG_DESKTOP_HID_EVENTQ <config_desktop_app_options>` Kconfig option to enable the :ref:`nrf_desktop_hid_eventq`.
The utility is used to temporarily queue key state changes (presses and releases) before the connection with the HID host is established.
When a key state changes (it is pressed or released) before the connection is established, an element containing this key's usage ID is pushed onto the queue.

Queue size
----------

With the :ref:`CONFIG_DESKTOP_HID_EVENT_QUEUE_SIZE <config_desktop_app_options>` Kconfig option, you can set the number of elements on the queue where the keys are stored before the connection is established.
If there is no space in the queue to enqueue a new key state change, the oldest element is released.

Report expiration
-----------------

With the :ref:`CONFIG_DESKTOP_HID_REPORT_EXPIRATION <config_desktop_app_options>` Kconfig option, you can set the amount of time after which a queued key will be considered expired.
The higher the value, the longer the period from which the nRF Desktop application will recall pressed keys when the connection with HID host is established.

Handling keys state
===================

The module selects the :ref:`CONFIG_DESKTOP_KEYS_STATE <config_desktop_app_options>` Kconfig option to enable the :ref:`nrf_desktop_keys_state`.
The utility is used to track the state of active keys after the connection with the HID host is established.

Implementation details
**********************

The |hid_state| provides a routing mechanism between sources of input data and transport modules.
This can be associated with:

* Receiving input events from :ref:`caf_buttons`, :ref:`nrf_desktop_wheel`, and :ref:`nrf_desktop_motion`.
* Sending out HID reports to HID transports, for example, :ref:`nrf_desktop_hids` and :ref:`nrf_desktop_usb_state`.

For the routing mechanism to work, the module performs the following operations:

* `Linking input data with the right HID report`_
* `Storing input data before the connection`_
* `Tracking state of transports`_
* `Tracking state of HID report notifications`_
* `Forming HID reports`_

Apart from the routing mechanism, the module is also responsible for `Handling HID keyboard LED state`_.

Linking input data with the right HID report
============================================

Out of all available input data types, the following types are collected by the |hid_state|:

* `Relative value data`_ (axes)
* `Absolute value data`_ (buttons)

Both types are stored in the :c:struct:`report_data` structure.

Relative value data
-------------------

This type of input data is related to the pointer coordinates and the wheel rotation.
Both ``motion_event`` and ``wheel_event`` are sources of this type of data.

To indicate a change to this input data, overwrite the value that is already stored.

When either ``motion_event`` or ``wheel_event`` is received, the |hid_state| selects the :c:struct:`report_data` structure associated with the mouse HID report and stores the values at the right position within this structure's ``axes`` member.

.. note::
    The values of axes are stored every time the input data is received, but these values are cleared when a report is connected to the subscriber.
    Consequently, values outside of the connection period are never retained.

Absolute value data
-------------------

This type of input data is related to buttons.
The ``button_event`` is the source of this type of data.

To indicate a change to this input data, overwrite the value that is already stored.

Since keys on the board can be associated to a HID usage ID, and thus be part of different HID reports, the first step is to identify which report the key belongs to and what usage it represents.
This is done by obtaining the key mapping from the :ref:`nrf_desktop_hid_keymap`.

Once the mapping is obtained, the application checks if the report to which the usage belongs is connected:

* If the report is connected, the :ref:`nrf_desktop_keys_state` instance is used to track the state of active keys associated with a given HID report.
* If the report is not connected, the value is stored in the :ref:`nrf_desktop_hid_eventq` instance in the same structure.

The difference between these operations is that storing value onto the queue (second case) preserves the order of input events.
See the following section for more information about storing data before the connection.

Storing input data before the connection
========================================

The storing approach before the connection depends on the data type:

* The relative value data is not stored outside of the connection period.
* The absolute value data is stored before the connection.

The reason for this operation is to allow to track key presses that happen right after the device is woken up, but before it is able to connect to the HID host.

When the device is disconnected and the input event with the absolute value data is received, the data is stored onto the :ref:`nrf_desktop_hid_eventq` instance, a member of :c:struct:`report_data` structure.
This queue preserves an order at which input data events are received.

Storing limitations
-------------------

The number of events that can be inserted into the queue is limited using the :ref:`CONFIG_DESKTOP_HID_EVENT_QUEUE_SIZE <config_desktop_app_options>` Kconfig option.

Discarding events
    When there is no space for a new input event, the |hid_state| tries to free space by discarding the oldest event in the queue.
    Events stored in the queue are automatically discarded after the period defined by :ref:`CONFIG_DESKTOP_HID_REPORT_EXPIRATION <config_desktop_app_options>` option.

    When discarding an event from the queue, the module checks if the key associated with the event is pressed.
    This is to avoid missing key releases for earlier key presses when the keys from the queue are replayed to the host.
    If a key release is missed, the host could stay with a key that is permanently pressed.
    The discarding mechanism ensures that the host will always receive the correct key sequence.

    .. note::
        The |hid_state| can only discard an event if the event does not overlap any button that was pressed but not released, or if the button itself is pressed.
        The event is released only when the following conditions are met:

        * The associated key is not pressed anymore.
        * Every key that was pressed after the associated key had been pressed is also released.

If there is no space to store the input event in the queue and no old event can be discarded, the entire content of the queue is dropped to ensure the sanity.

Once connection is established, the elements of the queue are replayed one after the other to the host, in a sequence of consecutive HID reports.

Tracking state of transports
============================

The |hid_state| tracks the state of modules that forward the HID data to a HID host (HID transports) by listening to :c:struct:`hid_report_subscriber_event`.
The |hid_state| refers collectively to all transports as *subscribers*.
When the connection to the host is indicated by this event, the |hid_state| will create a subscriber associated with the transport.
Each subscriber reports its priority as part of the :c:struct:`hid_report_subscriber_event`.
The subscriber priority must be unique, that mean two or more subscribers cannot share the same priority value.

By default, the subscriber that is associated with USB has priority over any Bluetooth LE peer subscriber.
As a result, when the host connected through the USB subscribes for a HID report, the HID report will be routed to the USB.

Tracking state of HID report notifications
==========================================

For each subscriber, the |hid_state| tracks the state of notifications for each of the available HID reports.
These are tracked in the subscriber's structure :c:struct:`subscriber`.
This structure's member ``state`` is an array of :c:struct:`report_state` structures.
Each element corresponds to one available HID report.

The subscriber connects to the HID reports by submitting :c:struct:`hid_report_subscription_event`.
Depending on the connection method, this event can be submitted:

* For Bluetooth, when the notification is enabled for a given HID report.
* For USB, when the device is connected to USB.

The :c:struct:`report_state` structure serves the following purposes:

* Tracks the state of the connection.
* Contains the link connecting the object to the right :c:struct:`report_data` structure from which the data is taken when the HID report is formed.
* Tracks the number of reports of the associated type that were sent to the subscriber.

Forming HID reports
===================

When a HID report is to be sent to the subscriber, the |hid_state| calls the function responsible for the report generation.
The :c:struct:`report_data` structure is passed as an argument to this function.

.. note::
    The HID report formatting function must work according to the HID report descriptor (``hid_report_desc``).
    The source file containing the descriptor is provided by the :ref:`CONFIG_DESKTOP_HID_REPORT_DESC <config_desktop_app_options>` Kconfig option.

Handling HID keyboard LED state
===============================

When the |hid_state| receives a :c:struct:`hid_report_event` that contains a HID output report, it updates the remembered information about the state of the HID output report of the appropriate subscriber.

By default, nRF Desktop supports only HID keyboard LED output report.
The nRF Desktop peripheral displays the state of the keyboard LEDs that was specified by the HID subscriber that subscribed for keyboard key HID input report.
When the subscriber is changed or it updates the state of the keyboard LEDs, the |hid_state| sends :c:struct:`leds_event` to update the state of the hardware LEDs.
