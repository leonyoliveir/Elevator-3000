#include <zephyr.h>
#include <misc/printk.h>
#include <device.h>
#include <gpio.h>
#include <sys_clock.h>
#include <misc/util.h>
#include <limits.h>

#define GPIO_OUT_PIN 1
#define GPIO_INT_PIN 3
#define PORT "GPIOA"

void main(void)
{
	uint32_t cycles_spent;
	uint32_t nanseconds_spent;
	uint32_t val;
	uint32_t cm;
	uint32_t stop_time;
	uint32_t start_time;
	struct device *dev;
	dev = device_get_binding(PORT);
	gpio_pin_configure(dev, GPIO_OUT_PIN, GPIO_DIR_OUT);
	gpio_pin_configure(dev, GPIO_INT_PIN,
			   (GPIO_DIR_IN | GPIO_INT_EDGE | GPIO_INT_ACTIVE_HIGH |
			    GPIO_INT_DEBOUNCE));

	while (1) {
		gpio_pin_write(dev, GPIO_OUT_PIN, 1);
		k_sleep(K_MSEC(10));
		gpio_pin_write(dev, GPIO_OUT_PIN, 0);
		do {
			gpio_pin_read(dev, GPIO_INT_PIN, &val);
		} while (val == 0);
		start_time = k_cycle_get_32();

		do {
			gpio_pin_read(dev, GPIO_INT_PIN, &val);
			stop_time = k_cycle_get_32();
			cycles_spent = stop_time - start_time;
			if (cycles_spent > 1266720) //260cm for 84MHz (((MAX_RANGE * 58000) / 1000000000) * (CLOCK * 1000000))
			{
				break;
			}
		} while (val == 1);
		nanseconds_spent = SYS_CLOCK_HW_CYCLES_TO_NS(cycles_spent);
		cm = nanseconds_spent / 58000;
		printk("%d\n", cm);
		k_sleep(100);
	}
}
