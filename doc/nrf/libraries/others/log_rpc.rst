.. _log_rpc:

Logging Remote Procedure Call
#############################

.. contents::
   :local:
   :depth: 2

The Logging Remote Procedure Call (RPC) library enables receiving and managing log messages from a remote device or processor.

Overview
********

The library supports the following main features:

  * Log streaming, which allows for receiving log messages over RPC in real-time as they are generated by the remote device.
  * Log history, which allows for saving log messages in a ring buffer in RAM or persistent memory, and retrieving them over RPC when needed.

The library also supports retrieving a core dump stored in the remote device's memory, and setting the current time used for log timestamping.

Implementation
==============

The logging RPC consists of the following components:

* Zephyr's :ref:`zephyr:logging_api` backend that implements sending log messages using :ref:`nrf_rpc`.
  It also accepts RPC commands for managing the logging backend.
* A log forwarder, which implements receiving log messages from a remote device and passing them to the local logging subsystem.
  It also implements RPC commands for managing the logging backend on the remote device.

Configuration
*************

To enable the logging RPC backend, set the :kconfig:option:`CONFIG_LOG_BACKEND_RPC` Kconfig option.

To enable the logging RPC forwarder, set the :kconfig:option:`CONFIG_LOG_FORWARDER_RPC` Kconfig option.

Samples using the library
*************************

The following |NCS| samples use this library:

* :ref:`nrf_rpc_protocols_serialization_client`
* :ref:`nrf_rpc_protocols_serialization_server`

Dependencies
************

The library has the following dependencies:

  * :ref:`nrf_rpc`
  * :ref:`zephyr:logging_api`

.. _log_rpc_api:

API documentation
*****************

| Header file: :file:`include/logging/log_rpc.h`
| Source files: :file:`subsys/logging`

.. doxygengroup:: log_rpc
