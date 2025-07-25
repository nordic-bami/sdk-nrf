/*
 * Copyright (c) 2025, Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: LicenseRef-Nordic-5-Clause
 */

#include <zephyr/kernel.h>
#include <zephyr/drivers/i2s.h>
#include <zephyr/ztest.h>
#include <zephyr/drivers/counter.h>

#define WORDS_COUNT		       16
#define TIMEOUT_MS		       2000
#define NUM_RX_BLOCKS		       4
#define NUM_TX_BLOCKS		       4
#define NUMBER_OF_CHANNELS	       1
#define TEST_TIMER_COUNT_TIME_LIMIT_MS 500

const struct device *const i2s_dev = DEVICE_DT_GET(DT_NODELABEL(i2s_dut));
const struct device *const tst_timer_dev = DEVICE_DT_GET(DT_ALIAS(tst_timer));

static const int16_t test_data[WORDS_COUNT] = {1,  9,  2,  10, 4,  12, 8,   16,
					       16, 24, 32, 40, 64, 72, 128, 136};

#define BLOCK_SIZE (sizeof(test_data))

K_MEM_SLAB_DEFINE(rx_mem_slab, BLOCK_SIZE, NUM_RX_BLOCKS, 32);
K_MEM_SLAB_DEFINE(tx_mem_slab, BLOCK_SIZE, NUM_TX_BLOCKS, 32);

void configure_test_timer(const struct device *timer_dev, uint32_t count_time_ms)
{
	struct counter_alarm_cfg counter_cfg;

	counter_cfg.flags = 0;
	counter_cfg.ticks = counter_us_to_ticks(timer_dev, (uint64_t)count_time_ms * 1000);
	counter_cfg.user_data = &counter_cfg;
}

static void fill_tx_buffer(int16_t *tx_block)
{
	for (int i = 0; i < WORDS_COUNT; i++) {
		tx_block[i] = test_data[i];
	}
}

static int verify_rx_buffer(int16_t *rx_block)
{
	int last_word = WORDS_COUNT;

	for (int i = 0; i < last_word; i++) {
		if (rx_block[i] != test_data[i]) {
			TC_PRINT("Error: data mismatch at position %d, expected %d, actual %d\n", i,
				 test_data[i], rx_block[i]);
			return -TC_FAIL;
		}
	}

	return TC_PASS;
}

static void configure_i2s(const struct device *dev, uint32_t frame_clk_freq)
{
	int ret;
	struct i2s_config i2s_cfg;

	i2s_cfg.word_size = 16U;
	i2s_cfg.channels = NUMBER_OF_CHANNELS;
	i2s_cfg.format = I2S_FMT_DATA_FORMAT_I2S;
	i2s_cfg.frame_clk_freq = frame_clk_freq;
	i2s_cfg.block_size = BLOCK_SIZE;
	i2s_cfg.timeout = TIMEOUT_MS;
	i2s_cfg.options = I2S_OPT_FRAME_CLK_MASTER | I2S_OPT_BIT_CLK_MASTER;

	i2s_cfg.mem_slab = &tx_mem_slab;
	ret = i2s_configure(i2s_dev, I2S_DIR_TX, &i2s_cfg);
	zassert_ok(ret, "Failed to configure I2S TX stream: %d", ret);

	i2s_cfg.mem_slab = &rx_mem_slab;
	ret = i2s_configure(i2s_dev, I2S_DIR_RX, &i2s_cfg);
	zassert_ok(ret, "Failed to configure I2S RX stream: %d", ret);
}

static void test_i2s_transmission_latency(const struct device *dev, uint32_t frame_clk_freq)
{
	int ret;
	void *rx_block[1];
	void *tx_block;
	size_t rx_size;
	uint32_t tst_timer_value;
	uint64_t timer_value_us;

	/* Configure I2S Dir Both transfer. */
	configure_i2s(dev, frame_clk_freq);

	/* Prefill TX queue */
	ret = k_mem_slab_alloc(&tx_mem_slab, &tx_block, K_FOREVER);
	zassert_equal(ret, 0, "TX mem slab allocation failed");
	fill_tx_buffer((uint16_t *)tx_block);

	configure_test_timer(tst_timer_dev, TEST_TIMER_COUNT_TIME_LIMIT_MS);

	ret = i2s_write(i2s_dev, tx_block, BLOCK_SIZE);
	zassert_equal(ret, 0);

	TC_PRINT("TX starts\n");

	counter_reset(tst_timer_dev);
	counter_start(tst_timer_dev);
	ret = i2s_trigger(i2s_dev, I2S_DIR_BOTH, I2S_TRIGGER_START);
	zassert_equal(ret, 0, "RX/TX START trigger failed\n");
	/* All data written, drain TX queue and stop both streams. */
	ret = i2s_trigger(i2s_dev, I2S_DIR_BOTH, I2S_TRIGGER_DRAIN);
	zassert_equal(ret, 0, "RX/TX DRAIN trigger failed");
	ret = i2s_read(i2s_dev, rx_block, &rx_size);
	counter_get_value(tst_timer_dev, &tst_timer_value);
	counter_stop(tst_timer_dev);

	timer_value_us = counter_ticks_to_us(tst_timer_dev, tst_timer_value);
	TC_PRINT("Measured transmission time (for FRCLK = %uHz) [us]: %llu\n", frame_clk_freq,
		 timer_value_us);

	zassert_equal(ret, 0);
	zassert_equal(rx_size, BLOCK_SIZE);

	TC_PRINT("RX done\n");

	/* Verify received data */
	ret = verify_rx_buffer((uint16_t *)rx_block[0]);
	zassert_equal(ret, 0, "TX data does not match RX data");
	k_mem_slab_free(&rx_mem_slab, rx_block[0]);
}

void *test_setup(void)
{
	zassert_true(device_is_ready(i2s_dev), "I2S device is not ready");
	return NULL;
}

ZTEST(i2s_latency, ites_i2s_latency_sampling_rate_8k)
{
	test_i2s_transmission_latency(i2s_dev, 8000);
}

ZTEST_SUITE(i2s_latency, NULL, test_setup, NULL, NULL, NULL);
