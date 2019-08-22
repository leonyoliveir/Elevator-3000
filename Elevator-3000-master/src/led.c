#include "led.h"
#include <misc/printk.h>

#define ERROR_CODE -1
#define LED_FLAGS    GPIO_DIR_OUT

int led_open(led_t *out, char *dev_label)
{
    out->device = device_get_binding(dev_label);
    out->dev_label = dev_label;
    out->state = 1;
    out->pin = (u32_t) NULL;
    if(led_check_error(out))
    {
        return ERROR_CODE;
    }
    printk("New led initialized succesfully in the device %s\n", dev_label);
    return 0;
}

int led_configure(led_t *out, u32_t pin, int flags)
{
    if(led_check_error(out))
    {
        return ERROR_CODE;
    }
    out->pin = pin;
    gpio_pin_configure(out->device, pin, flags);
    gpio_pin_write(out->device, pin, out->state);
    printk("led configured succesfully at pin %d\n", pin);
    return 0; 
}

int led_set(led_t *out, u8_t value)
{
    if(led_check_error(out))
    {
        return ERROR_CODE;
    }
    else if(out->pin == (u32_t) NULL)
    {
        printk("ERROR! First configure device\n");
        return ERROR_CODE;
    }
    out->state = value;
    gpio_pin_write(out->device, out->pin, out->state);
    printk("led at pin %d changed state to %d\n", out->pin, out->state);
    return 0;
}

int led_digital_invert(led_t *out)
{
    if(led_check_error(out))
    {
        return ERROR_CODE;
    }
    u8_t inverted = ~out->state & 1;
    led_set(out, inverted);
    return 0;
}

int led_check_error(led_t *out)
{
    if(!out->device)
    {
        printk("ERROR! First iniatilize device\n");
        return ERROR_CODE;
    }
    return 0;
}

int new_led(led_t *out, char* dev_label, u32_t pin)
{
    printk("Initializing new led...\n");
    led_open(out, dev_label);
    printk("Setting the new led...\n");
    led_configure(out, pin, LED_FLAGS);
    printk("Finished new led initializing succesfully!\n");
    return 0;
}