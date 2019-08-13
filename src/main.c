#include <zephyr.h>
#include <misc/printk.h>
#include <misc/util.h>
#include "define.h"
#include "L298N.h"
#include "HCSR04.h"

l298n_t h_bridge;
hcsr04_t ultrasonic;

int main(void)
{
    new_bridge(&h_bridge, DEVICE, BRIDGE_ENABLE, BRIDGE_PIN1, BRIDGE_PIN2);
    new_ultrasonic(&ultrasonic, DEVICE, US_TRIG_PIN, US_ECHO_PIN);
    while(1)
    {
        int dist = get_distance(&ultrasonic);
        printk("Atual distance: %d cm\n", dist);
        k_sleep(500);
        /*
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
        */
    }
    return 0;
}