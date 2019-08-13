#include "L298N.h"

#define ERROR_CODE -1
#define HIGH 1
#define LOW 0
#define L298N_FLAGS GPIO_DIR_OUT

int bridge_open(l298n_t *bridge, char *dev_label)
{
    bridge->device = device_get_binding(dev_label);
    if(bridge_check_error(bridge)) return ERROR_CODE;
    bridge->dev_label = dev_label;
    bridge->enable_pin = (u32_t) NULL;
    bridge->pin_one = (u32_t) NULL;
    bridge->pin_two = (u32_t) NULL;
    bridge->enable = LOW;
    bridge->state_one = LOW;
    bridge->state_two = LOW;
    printk("New H bridge initialized succesfully in the device %s\n", dev_label);
    return 0;
}

int bridge_configure(l298n_t *bridge, u32_t pin1, u32_t pin2, u32_t enable_pin, int flags)
{
    if(bridge_check_error(bridge)) return ERROR_CODE;
    bridge->enable_pin = enable_pin;
    bridge->pin_one = pin1;
    bridge->pin_two = pin2;
    gpio_pin_configure(bridge->device, enable_pin, flags);
    gpio_pin_configure(bridge->device, pin1, flags);
    gpio_pin_configure(bridge->device, pin2, flags);
    gpio_pin_write(bridge->device, bridge->enable_pin, bridge->enable);
    gpio_pin_write(bridge->device, bridge->pin_one, bridge->state_one);
    gpio_pin_write(bridge->device, bridge->pin_two, bridge->state_two);
    printk("New H bridge configured succesfully in the device %s\n", bridge->dev_label);
    return 0;
}

int bridge_enable(l298n_t *bridge)
{
    if(bridge_check_error(bridge)) return ERROR_CODE;
    else if(bridge->enable_pin == (u32_t) NULL)
    {
        printk("ERROR! First configure device\n");
        return ERROR_CODE;
    }
    bridge->enable = HIGH;
    gpio_pin_write(bridge->device, bridge->enable_pin, bridge->enable);
    printk("Bridge enabled succesfully!\n");
    return 0;
}

int bridge_set(l298n_t *bridge)
{
    if(bridge_check_error(bridge)) return ERROR_CODE;
    else if(bridge->pin_one == (u32_t) NULL || bridge->pin_two == (u32_t) NULL)
    {
        printk("ERROR! First configure device\n");
        return ERROR_CODE;
    }
    gpio_pin_write(bridge->device, bridge->pin_one, bridge->state_one);
    gpio_pin_write(bridge->device, bridge->pin_two, bridge->state_two);
    printk("State one: %d\n", bridge->state_one);
    printk("State two: %d\n", bridge->state_two);
    return 0;
}

int stop_motor(l298n_t *bridge)
{
    if(bridge_check_error(bridge)) return ERROR_CODE;
    bridge->state_one = HIGH;
    bridge->state_two = HIGH;
    bridge_set(bridge);
    return 0;
}

int turn_left_motor(l298n_t *bridge)
{
    if(bridge_check_error(bridge)) return ERROR_CODE;
    bridge->state_one = LOW;
    bridge->state_two = HIGH;
    bridge_set(bridge);
    return 0;
}

int turn_right_motor(l298n_t *bridge)
{
    if(bridge_check_error(bridge)) return ERROR_CODE;
    bridge->state_one = HIGH;
    bridge->state_two = LOW;
    bridge_set(bridge);
    return 0;
}

int bridge_check_error(l298n_t *bridge)
{
    if(!bridge->device)
    {
        printk("ERROR! First iniatilize device\n");
        return ERROR_CODE;
    }
    return 0;
}

int new_bridge(l298n_t *bridge, char *dev_label, u32_t enable_pin, u32_t pin_one, u32_t pin_two)
{
    int error;
    printk("Initializing new H bridge...\n");
    error = bridge_open(bridge, dev_label);
    if(error) return error;
    printk("Setting the new H bridge...\n");
    error = bridge_configure(bridge, pin_one, pin_two, enable_pin, L298N_FLAGS);
    if(error) return error;
    printk("Enabling the new H bridge...\n");
    error = bridge_enable(bridge);
    if(error) return error;
    printk("New H bridge initialized succesfully\n");
    return 0;
}