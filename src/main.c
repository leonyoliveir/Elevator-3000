#include <zephyr.h>
#include <misc/printk.h>
#include <misc/util.h>
#include <sys_clock.h>
#include "define.h"
#include "L298N.h"
#include "HCSR04.h"

l298n_t h_bridge;
hcsr04_t ultrasonic;

typedef enum {STOPPED, WAITING, GOING_UP, GOING_DOWN} state_t;
typedef enum {INSIDE, OUT_UP, OUT_DOWN, ARRIVE} calls_t;
typedef enum {GROUND, FIRST, SECOND, THIRD} floor_t;

K_SEM_DEFINE(elevator_in, 0, 1);
K_SEM_DEFINE(elevator_out_up, 0, 1);
K_SEM_DEFINE(elevator_out_down, 0, 1);

void update_level(floor_t level)
{
    static u8_t atual_level = level;
}

void update_inside(floor_t destination, u8_t value)
{
    static u8_t calls_in[4] = {0, 0, 0, 0};
    k_sem_take(elevator_in, K_FOREVER);
    calls_in[destination] = value;
    k_sem_give(elevator_in);
}

void update_outside_up(floor_t destination, u8_t value)
{
    static u8_t calls_up_out[3] = {0, 0, 0};
    k_sem_take(elevator_out_up, K_FOREVER);
    calls_up_out[destination] = value;
    k_sem_give(elevator_out_up);
}

void update_outside_down(floor_t destination, u8_t value)
{
    static u8_t calls_down_out[3] = {0, 0, 0};
    k_sem_take(elevator_out_down, K_FOREVER);
    calls_down_out[destination - 1] = value;
    k_sem_give(elevator_in);
}

void update_calls(calls_t source, floor_t destination)
{
    switch (source)
    {
        case INSIDE:
            update_inside(destination, 1);
            break;
        case OUT_UP:
            update_outside_up(destination, 1);
            break;
        case OUT_DOWN:
            update_outside_down(destination, 1);
            break;
        case ARRIVE:
            update_inside(destination, 0);
            update_outside_up(destination, 0);
            update_outside_down(destination, 0);
            break;
        default:
            break;
    }
}

void read_ultrasonic(void)
{
    int distance = get_distance(ultrasonic);
    return;
}

void control_motor(void)
{
    return;
}

int main(void)
{
    new_bridge(&h_bridge, DEVICE, BRIDGE_ENABLE, BRIDGE_PIN1, BRIDGE_PIN2);
    new_ultrasonic(&ultrasonic, DEVICE, US_TRIG_PIN, US_ECHO_PIN);
    return 0;
}