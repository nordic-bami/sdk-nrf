/*
 * Copyright (c) 2026 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: LicenseRef-Nordic-5-Clause
 */

#include <zephyr/kernel.h>

int main(void)
{
	const size_t step = 1024;
	size_t set_size = 1024;
	uint8_t *test_ptr;
	uint32_t counter = 1;
	uint8_t test_array[CONFIG_MAIN_STACK_SIZE / 2];

	printk("Hello %s\n", CONFIG_BOARD_TARGET);
	printk("Set array stored on stack gradually, until crash\n");

	while(1) {

		printk("Setting array: %u bytes\n", set_size);
		test_ptr = memset(test_array, 0xAB, set_size);
		printk("Test array ptr %p\n", test_ptr);
		set_size += step;
		printk("Go to sleep: %u\n", counter++);
		k_msleep(1000);
		printk("Wake up\n");
	}
	
	return 0;
}
