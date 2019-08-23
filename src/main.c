#include <zephyr.h>
#include <misc/printk.h>
#include <misc/util.h>
#include <sys_clock.h>
#include "define.h"
#include "L298N.h"
#include "HCSR04.h"
#include "button.h"
#include "led.h"
#include "calls.h"
#include "CD4511.h"

l298n_t h_bridge;
hcsr04_t ultrasonic;
cd4511_t decoder;
button_t in_ground, in_first, in_second, in_third, out_ground, out_first_up, out_first_down, out_second_up, out_second_down, out_third;
led_t led_up, led_down, led_door;
floor_t floors;
calls_t calls;
state_t states;

u8_t check_calls(floor_t destination)
{
    if(check_inside(destination) || (destination > GROUND && check_outside_down(destination)) || (destination < THIRD && check_outside_up(destination))) return 1;
    return 0;
}

u8_t check_calls_up(floor_t atual)
{
    floor_t level;
    for(level = atual; level <= THIRD; level++)
    {
        if(check_inside(level) || (level < THIRD && check_outside_up(level))) return 1;
    }
    return 0;
}

u8_t check_calls_down(floor_t atual)
{
    floor_t level;
    for(level = GROUND; level <= atual; level++)
    {
        if(check_inside(level) || (level > GROUND && check_outside_down(atual))) return 1;
    }
    return 0;
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

void in_button_callback(struct device *dev, struct gpio_callback *cb, u32_t pin)
{
    if(pin & 1 << IN_GROUND_F)
    {
        printk("Ground floor called from inside\n");
        update_calls(INSIDE, GROUND);
    }
    if(pin & 1 << IN_FIRST_F)
    {
        printk("First floor called from inside\n");
        update_calls(INSIDE, FIRST);
    }
    if(pin & 1 << IN_SECOND_F)
    {
        printk("Second floor called from inside\n");
        update_calls(INSIDE, SECOND);
    }
    if(pin & 1 << IN_THIRD_F)
    {
        printk("Third floor called from inside\n");
        update_calls(INSIDE, THIRD);
    }
}

void out_down_button_callback(struct device *dev, struct gpio_callback *cb, u32_t pin)
{   

    if(pin & 1 << OUT_FIRST_DOWN)
    {
        printk("First floor called from outside down\n");
        update_calls(OUT_DOWN, FIRST);
    }
    if(pin & 1 << OUT_SECOND_DOWN)
    {
        printk("Second floor called from outside down\n");
        update_calls(OUT_DOWN, SECOND);
    }
    if(pin & 1 << OUT_THIRD)
    {
        printk("Third floor called from outside down\n");
        update_calls(OUT_DOWN, THIRD);
    }
}

void out_up_button_callback(struct device *dev, struct gpio_callback *cb, u32_t pin)
{
    if(pin & 1 << OUT_GROUND)
    {
        printk("Ground floor called from outside up\n");
        update_calls(OUT_UP, GROUND);
    }
    if(pin & 1 << OUT_FIRST_UP)
    {
        printk("First floor called from outside up\n");
        update_calls(OUT_UP, FIRST);
    }
    if(pin & 1 << OUT_SECOND_UP)
    {
        printk("Second floor called from outside up\n");
        update_calls(OUT_UP, SECOND);
    }
}

void read_ultrasonic(void)
{
    while(1)
    {
        int distance = get_distance(&ultrasonic);
        floor_t floor;
        if(distance < 30) floor = GROUND;
        else if(distance < 60) floor = FIRST;
        else if(distance < 90) floor = SECOND;
        else floor = THIRD;
        update_level(floor);
        printk("%d\n", distance);
    }
}

K_THREAD_DEFINE(read, STACKSIZE, read_ultrasonic, NULL, NULL, NULL, PRIORITY, 0, K_NO_WAIT);

void control_outputs(state_t atual, floor_t atual_level)
{
    decoder_set(&decoder, atual_level);
    switch(atual)
    {
        case GOING_UP:
            turn_left_motor(&h_bridge);
            led_set(&led_up, 0);
            led_set(&led_down, 1);
            led_set(&led_door, 1);
            break;
        case GOING_DOWN:
            turn_right_motor(&h_bridge);
            led_set(&led_up, 1);
            led_set(&led_down, 0);
            led_set(&led_door, 1);
            break;
        case WAITING:
            led_set(&led_up, 1);
            led_set(&led_down, 1);
            led_set(&led_door, 0);
        default:
            stop_motor(&h_bridge);
            break;
    }
}

// // Threads
// void buttonsThread(void)
// {   
//     while(1)
//     {
//         u32_t value = 0U;
//         button_read(&out_ground, &value);
//         button_read(&out_first_up, &value);
//         button_read(&out_first_down, &value);
//         button_read(&out_second_up, &value);
//         button_read(&out_second_down, &value);
//         button_read(&out_third, &value);
//         k_sleep(SLEEP_TIME);
//     }
// }

// void buttonsInsideThread(void)
// {
//     while(1)
//     {
//         u32_t value = 0U;
//         button_read(&in_ground, &value);
//         button_read(&in_first, &value);
//         button_read(&in_second, &value);
//         button_read(&in_third, &value);
//         k_sleep(SLEEP_TIME);
//     }
// }

// // Def Threads
// K_THREAD_DEFINE(check_b, STACKSIZE, buttonsThread, NULL, NULL, NULL, PRIORITY, 0, K_NO_WAIT);
// K_THREAD_DEFINE(check_bi, STACKSIZE, buttonsInsideThread, NULL, NULL, NULL, PRIORITY-1, 0, K_NO_WAIT);
//K_THREAD_DEFINE(check_l, STACKSIZE, ledsThread, NULL, NULL, NULL, PRIORITY, 0, K_NO_WAIT);

u8_t timeout()
{
    k_sleep(K_SECONDS(5));
    return 1;
}

void state_machine()
{
    //printk("To na state machine\n");
    static floor_t atual_level;
    static floor_t next_level;
    static state_t atual = STOPPED;
    static state_t next = STOPPED;
    static state_t previous = STOPPED;
    //printk("Variaveis\n");
    atual_level = check_level();
    switch(atual)
    {
        case STOPPED:
            //printk("Elevator stopped at %d floor...\n", atual_level);
            if(check_calls(atual_level)) next = WAITING;
            else if(check_calls_up(atual_level))
            {
                printk("Call received up...\n");
                next = GOING_UP;
                next_level = atual_level + 1;
            } 
            else if(check_calls_down(atual_level))
            {
                next = GOING_DOWN;
                next_level = atual_level - 1;
            }
            else next = STOPPED;
            break;
        case GOING_UP:
            //printk("Elevator rising up from %d floor to %d floor...\n", atual_level, next_level);
            if(atual_level == next_level && check_calls(atual_level))
            {
                next = WAITING;
                previous = GOING_UP;
            }
            else 
            {
                next = GOING_UP;
                next_level = atual_level + 1;
            }
            break;
        case GOING_DOWN:
            //printk("Elevator falling down from %d floor to %d floor...\n", atual_level, next_level);
            if(atual_level == next_level && check_calls(atual_level))
            {
                next = WAITING;
                previous = GOING_DOWN;  
            }
            else
            {
                next = GOING_DOWN;
                next_level = atual_level - 1;
            } 
            break;
        case WAITING:
            //printk("Elevator waiting for timeout...\n");
            if(timeout())
            {
                calls_t source = ARRIVE;
                update_calls(source, atual_level);
                if(previous == GOING_UP && check_calls_up(atual_level))
                {
                    next = GOING_UP;
                    next_level = next_level + 1;
                } 
                else if(previous == GOING_DOWN && check_calls_down(atual_level))
                {
                    next = GOING_DOWN;
                    next_level = next_level + 1;
                } 
                else next = STOPPED;
            }
            else next = WAITING;
            break;
        default:
            next = STOPPED;
            break;
    }
    atual = next;
    control_outputs(atual, atual_level);
}

void initializing_elevator_sensors(void)
{
    new_bridge(&h_bridge, DEVICE, BRIDGE_ENABLE, BRIDGE_PIN1, BRIDGE_PIN2);
    new_ultrasonic(&ultrasonic, DEVICE, US_TRIG_PIN, US_ECHO_PIN);
    new_decoder(&decoder, DEVICE, DECODER_PIN1, DECODER_PIN2);
    new_led(&led_up, DEVICE, LED_UP);
    new_led(&led_down, DEVICE, LED_DOWN);
    new_led(&led_door, DEVICE, LED_DOOR);
}

void initializing_inside_buttons(void)
{
    new_button(&in_ground, DEVICE, IN_GROUND_F, in_button_callback);
    
    
    new_button(&in_third, DEVICE, IN_THIRD_F, in_button_callback);
}

void initializing_outside_buttons(void)
{
    new_button(&out_ground, DEVICE, OUT_GROUND, out_up_button_callback);
    new_button(&out_first_up, DEVICE, OUT_FIRST_UP, out_up_button_callback);
    new_button(&out_first_down, DEVICE, OUT_FIRST_DOWN, out_down_button_callback);
    new_button(&out_second_up, DEVICE, OUT_SECOND_UP, out_up_button_callback);
    new_button(&out_second_down, DEVICE, OUT_SECOND_DOWN, out_down_button_callback);
    new_button(&out_third, DEVICE, OUT_THIRD, out_down_button_callback);
    new_button(&in_first, DEVICE, IN_FIRST_F, in_button_callback);
    new_button(&in_second, DEVICE, IN_SECOND_F, in_button_callback);
    new_button(&in_third, DEVICE, IN_THIRD_F, in_button_callback);
}

void test(void)
{
    stop_motor(&h_bridge);
    k_sleep(500);
    turn_left_motor(&h_bridge);
    k_sleep(500);
    stop_motor(&h_bridge);
    k_sleep(500);
    turn_right_motor(&h_bridge);
    k_sleep(500);
    stop_motor(&h_bridge);
}

K_THREAD_DEFINE(lungalunga, STACKSIZE, read_ultrasonic, NULL, NULL, NULL, PRIORITY, 0, K_NO_WAIT);
// Main
int main(void)
{
    initializing_elevator_sensors();
    initializing_outside_buttons();
    initializing_inside_buttons();
    while(1)
    {
        state_machine();
        k_sleep(K_SECONDS(1));
    }
    return 0;
}