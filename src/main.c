#include <zephyr.h>
#include <misc/printk.h>
#include <misc/util.h>
#include "define.h"
#include "L298N.h"

l298n_t h_bridge;

int main(void)
{
    new_bridge(&h_bridge, BRIDGE_DEVICE, BRIDGE_ENABLE, BRIDGE_PIN1, BRIDGE_PIN2);
    while(1)
    {
        printk("Turning motor to left...\n");
        turn_left_motor(&h_bridge);
        k_sleep(3000);
        printk("Stopping motor...\n");
        stop_motor(&h_bridge);
        k_sleep(500);
        printk("Turning motor to right...\n");
        turn_right_motor(&h_bridge);
        k_sleep(3000);
        printk("Stopping motor...\n");
        stop_motor(&h_bridge);
        k_sleep(500);
    }
    return 0;
}