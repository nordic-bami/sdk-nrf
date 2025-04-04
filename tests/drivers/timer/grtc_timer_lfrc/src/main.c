/*
 * Copyright (c) 2022, Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: Apache-2.0
 */
#include <zephyr/ztest.h>
#include <zephyr/drivers/timer/nrf_grtc_timer.h>
#include <hal/nrf_grtc.h>
#include <zephyr/devicetree/clocks.h>
#include <zephyr/drivers/clock_control/nrf_clock_control.h>

#define REQUEST_SERVING_WAIT_TIME_US 10000

const struct device *lfclk_dev = DEVICE_DT_GET(DT_NODELABEL(lfclk));
static volatile uint8_t compare_isr_call_counter;

const struct nrf_clock_spec lfclk_lfrc_mode = 
{
	.frequency = 32768,
	.accuracy = 0,
	.precision = NRF_CLOCK_CONTROL_PRECISION_DEFAULT,
};

const struct nrf_clock_spec lfclk_synth_mode = 
{
	.frequency = 32768,
	.accuracy = 30,
	.precision = NRF_CLOCK_CONTROL_PRECISION_DEFAULT,
};

static void request_clock_spec(const struct device *clk_dev, 
	const struct nrf_clock_spec *clk_spec)
{
	int ret = 0;
	int res = 0;
	struct onoff_client cli;
	uint32_t rate;

	TC_PRINT("Clock: %s, requesting frequency=%d, accuracy=%d, precision=%d\n",
		clk_dev->name, clk_spec->frequency, clk_spec->accuracy, clk_spec->precision);
	sys_notify_init_spinwait(&cli.notify);
	ret = nrf_clock_control_request(clk_dev, clk_spec, &cli);
	zassert_equal(ret, 0);
	do {
		ret = sys_notify_fetch_result(&cli.notify, &res);
		k_yield();
	} while (ret == -EAGAIN);
	zassert_equal(ret, 0);
	zassert_equal(res, 0);
	ret = clock_control_get_rate(clk_dev, NULL, &rate);
	if (ret != -ENOSYS) {
		zassert_equal(ret, 0);
		zassert_equal(rate, clk_spec->frequency);
		k_busy_wait(REQUEST_SERVING_WAIT_TIME_US);
		ret = nrf_clock_control_release(clk_dev, clk_spec);
		zassert_equal(ret, ONOFF_STATE_ON);
	}
}

/* GRTC timer compare interrupt handler */
static void timer_compare_interrupt_handler(int32_t id, uint64_t expire_time, void *user_data)
{
	compare_isr_call_counter++;
	TC_PRINT("Compare value reached, user data: '%s'\n", (char *)user_data);
	TC_PRINT("Call counter: %d\n", compare_isr_call_counter);
}

static void test_timer_compare(uint32_t timer_count_time_ms, bool request_clock_change_during_operation)
{
	int err;
	uint64_t test_ticks = 0;
	uint64_t compare_value = 0;
	char user_data[] = "test_timer_count_in_compare_mode\n";
	int32_t channel = z_nrf_grtc_timer_chan_alloc();

	TC_PRINT("Allocated GRTC channel %d\n", channel);
	if (channel < 0) {
		TC_PRINT("Failed to allocate GRTC channel, chan=%d\n", channel);
		ztest_test_fail();
	}

	compare_isr_call_counter = 0;
	test_ticks = z_nrf_grtc_timer_get_ticks(K_MSEC(timer_count_time_ms));
	err = z_nrf_grtc_timer_set(channel, test_ticks, timer_compare_interrupt_handler,
				   (void *)user_data);

	zassert_equal(err, 0, "z_nrf_grtc_timer_set raised an error: %d", err);

	z_nrf_grtc_timer_compare_read(channel, &compare_value);
	zassert_true(K_TIMEOUT_EQ(K_TICKS(compare_value), K_TICKS(test_ticks)),
		     "Compare register set failed");
	zassert_equal(err, 0, "Unexpected error raised when setting timer, err: %d", err);

	if(request_clock_change_during_operation)
	{
		TC_PRINT("Changing clock source of the GRTC while waiting for compare callback\n");
		request_clock_spec(lfclk_dev, &lfclk_synth_mode);
	}

	k_sleep(K_MSEC(2 * timer_count_time_ms));

	TC_PRINT("Compare event generated ?: %d\n", z_nrf_grtc_timer_compare_evt_check(channel));
	zassert_equal(compare_isr_call_counter, 1, "Compare isr call counter: %d",
		      compare_isr_call_counter);
	z_nrf_grtc_timer_chan_free(channel);
}

ZTEST(grtc_timer_lfrc, test_timer_count_in_compare_mode_lfclk_source_from_lfrc)
{
	uint32_t timer_count_time_ms = 50;

	request_clock_spec(lfclk_dev, &lfclk_lfrc_mode);
	test_timer_compare(timer_count_time_ms, false);
}


ZTEST(grtc_timer_lfrc, test_timer_count_in_compare_mode_lfclk_source_from_synth)
{
	uint32_t timer_count_time_ms = 50;

	request_clock_spec(lfclk_dev, &lfclk_synth_mode);
	test_timer_compare(timer_count_time_ms, false);
}

ZTEST(grtc_timer_lfrc, test_timer_count_in_compare_mode_lfclk_runtime_update)
{
	uint32_t timer_count_time_ms = 2000;

	request_clock_spec(lfclk_dev, &lfclk_lfrc_mode);
	test_timer_compare(timer_count_time_ms, true);
}


ZTEST_SUITE(grtc_timer_lfrc, NULL, NULL, NULL, NULL, NULL);
