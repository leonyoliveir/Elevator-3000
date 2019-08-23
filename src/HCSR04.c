#include "HCSR04.h"

#define ERROR_CODE -1
#define HIGH 1
#define LOW 0
#define TRIG_FLAGS GPIO_DIR_OUT
#define ECHO_FLAGS GPIO_DIR_IN //| GPIO_INT | GPIO_INT_EDGE | GPIO_INT_ACTIVE_HIGH | GPIO_INT_DEBOUNCE

int ultrasonic_open(hcsr04_t *ultrasonic, char *dev_label)
{
	ultrasonic->device = device_get_binding(dev_label);
	if(ultrasonic_check_error(ultrasonic)) return ERROR_CODE;
	ultrasonic->dev_label = dev_label;
	ultrasonic->pin_echo = (u32_t) NULL;
	ultrasonic->pin_trigger = (u32_t) NULL;
	printk("New Ultrasonic initialized succesfully in the device %s\n", dev_label);
    return 0;
}

int ultrasonic_configure(hcsr04_t *ultrasonic, u32_t pin_trigger, u32_t pin_echo, int flags_trigger, int flags_echo)
{
	if(ultrasonic_check_error(ultrasonic)) return ERROR_CODE;
	ultrasonic->pin_echo = pin_echo;
	ultrasonic->pin_trigger = pin_trigger;
	gpio_pin_configure(ultrasonic->device, pin_echo, flags_echo);
	gpio_pin_configure(ultrasonic->device, pin_trigger, flags_trigger);
	printk("New Ultrasonic configured succesfully in the device %s\n", ultrasonic->dev_label);
	return 0;
}

int ultrasonic_check_error(hcsr04_t *ultrasonic)
{
    if(!ultrasonic->device)
    {
        printk("ERROR! First iniatilize device\n");
        return ERROR_CODE;
    }
    return 0;
}

int get_distance(hcsr04_t *ultrasonic)
{
	if(ultrasonic_check_error(ultrasonic)) return ERROR_CODE;
	else if(ultrasonic->pin_echo == (u32_t) NULL || ultrasonic->pin_trigger == (u32_t) NULL)
	{
		printk("ERROR! First configure device!");
		return ERROR_CODE;
	}
	uint32_t cycles_spent, nanseconds_spent, val, cm, stop_time, start_time;
	gpio_pin_write(ultrasonic->device, ultrasonic->pin_trigger, 0);
	k_sleep(20);
	gpio_pin_write(ultrasonic->device, ultrasonic->pin_trigger, 1);
	k_sleep(12);
	gpio_pin_write(ultrasonic->device, ultrasonic->pin_trigger, 0);
	printk("Gretchen\n");
	do {
		gpio_pin_read(ultrasonic->device, ultrasonic->pin_echo, &val);
		printk("%d\n", val);
	} while (val == 0);
	printk("Tame!\n");
	start_time = k_cycle_get_32();
	do {
		gpio_pin_read(ultrasonic->device, ultrasonic->pin_echo, &val);
		stop_time = k_cycle_get_32();
		cycles_spent = stop_time - start_time;
		if (cycles_spent > 1266720) //260cm for 84MHz (((MAX_RANGE * 58000) / 1000000000) * (CLOCK * 1000000))
		{
			break;
		}
	} while (val == 1);
	nanseconds_spent = SYS_CLOCK_HW_CYCLES_TO_NS(cycles_spent);
	cm = nanseconds_spent / 58000;
	return cm;
}

int new_ultrasonic(hcsr04_t *ultrasonic, char *dev_label, u32_t pin_trigger, u32_t pin_echo)
{
	int error;
    printk("Initializing new Ultrasonic sensor...\n");
    error = ultrasonic_open(ultrasonic, dev_label);
    if(error) return error;
    printk("Setting the new Ultrasonic...\n");
    error = ultrasonic_configure(ultrasonic, pin_trigger, pin_echo, TRIG_FLAGS, ECHO_FLAGS);
    if(error) return error;
    printk("New Ultrasonic initialized succesfully\n");
    return 0;
}