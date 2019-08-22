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

l298n_t h_bridge;
hcsr04_t ultrasonic;
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
        update_calls(INSIDE, GROUND);
    }
    if(pin & 1 << IN_FIRST_F)
    {
        update_calls(INSIDE, FIRST);
    }
    if(pin & 1 << IN_SECOND_F)
    {
        update_calls(INSIDE, SECOND);
    }
    if(pin & 1 << IN_THIRD_F)
    {
        update_calls(INSIDE, THIRD);
    }
}

void out_down_button_callback(struct device *dev, struct gpio_callback *cb, u32_t pin)
{
    if(pin & 1 << OUT_FIRST_DOWN)
    {
        update_calls(OUT_DOWN, FIRST);
    }
    if(pin & 1 << OUT_SECOND_DOWN)
    {
        update_calls(OUT_DOWN, SECOND);
    }
    if(pin & 1 << OUT_THIRD)
    {
        update_calls(OUT_DOWN, THIRD);
    }
}

void out_up_button_callback(struct device *dev, struct gpio_callback *cb, u32_t pin)
{
    if(pin & 1 << OUT_GROUND)
    {
        update_calls(OUT_UP, GROUND);
    }
    if(pin & 1 << OUT_FIRST_DOWN)
    {
        update_calls(OUT_UP, FIRST);
    }
    if(pin & 1 << OUT_SECOND_DOWN)
    {
        update_calls(OUT_UP, SECOND);
    }
}

void read_ultrasonic(void)
{
    int distance = get_distance(&ultrasonic);
    return;
}

void control_motor(void)
{
    return;
}

// Threads
void buttonsThread(void)
{   
    while(1)
    {
        u32_t value = 0U;
        button_read(&in_ground, &value);
        button_read(&in_first, &value);
        button_read(&in_second, &value);
        button_read(&in_third, &value);
        button_read(&out_ground, &value);
        button_read(&out_first_up, &value);
        button_read(&out_first_down, &value);
        button_read(&out_second_up, &value);
        button_read(&out_second_down, &value);
        button_read(&out_third, &value);
        k_sleep(SLEEP_TIME);
    }
}
void ledsThread(void)
{

    return;   
}

// Def Threads
//K_THREAD_DEFINE(check_b, STACKSIZE, buttonsThread, NULL, NULL, NULL, PRIORITY - 1, 0, K_NO_WAIT);
//K_THREAD_DEFINE(check_l, STACKSIZE, ledsThread, NULL, NULL, NULL, PRIORITY, 0, K_NO_WAIT);

u8_t timeout()
{
    k_sleep(K_SECONDS(5));
    return 1;
}

void state_machine()
{
    static floor_t atual_level;
    static floor_t next_level;
    static state_t atual = STOPPED;
    static state_t next = STOPPED;
    static state_t previous = STOPPED;
    atual_level = check_level();
    switch(atual)
    {
        case STOPPED:
            printk("Elevator stopped at %d floor...\n", atual_level);
            if(check_calls(atual_level)) next = WAITING;
            else if(check_calls_up(atual_level))
            {
                next = GOING_UP;
                next_level = atual_level + 1;
            } 
            else if(check_calls_down(atual_level))
            {
                next = GOING_DOWN;
                next_level = atual_level - 1;
            }
            else next = STOPPED;
        case GOING_UP:
            printk("Elevator rising up from %d floor to %d floor...\n", atual_level, next_level);
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
        case GOING_DOWN:
            printk("Elevator falling down from %d floor to %d floor...\n", atual_level, next_level);
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
        case WAITING:
            printk("Elevator waiting for timeout..."\n);
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
        default:
            next = STOPPED;
            break;
    }
    atual = next;
}

void initializing(void)
{
    new_bridge(&h_bridge, DEVICE, BRIDGE_ENABLE, BRIDGE_PIN1, BRIDGE_PIN2);
    new_ultrasonic(&ultrasonic, DEVICE, US_TRIG_PIN, US_ECHO_PIN);
    new_button(&in_ground, DEVICE, IN_GROUND_F, in_button_callback);
    new_button(&in_first, DEVICE, IN_FIRST_F, in_button_callback);
    new_button(&in_second, DEVICE, IN_SECOND_F, in_button_callback);
    new_button(&in_third, DEVICE, IN_THIRD_F, in_button_callback);
    new_button(&out_ground, DEVICE, OUT_GROUND, out_up_button_callback);
    new_button(&out_first_up, DEVICE, OUT_FIRST_UP, out_up_button_callback);
    new_button(&out_first_down, DEVICE, OUT_FIRST_DOWN, out_down_button_callback);
    new_button(&out_second_up, DEVICE, OUT_SECOND_UP, out_up_button_callback);
    new_button(&out_second_down, DEVICE, OUT_SECOND_DOWN, out_down_button_callback);
    new_button(&out_third, DEVICE, OUT_THIRD, out_down_button_callback);
    new_led(&led_up, DEVICE, LED_UP);
    new_led(&led_down, DEVICE, LED_DOWN);
    new_led(&led_door, DEVICE, LED_DOOR);
}

void test(void)
{
    floors = GROUND;
    update_level(floors);
    k_sleep(K_SECONDS(3));
    calls = OUT_DOWN;
    floors = SECOND;
    update_calls(calls, floors);
    k_sleep(K_SECONDS(5));
    floors = FIRST;
    update_level(floors);
    k_sleep(K_SECONDS(3));
    floors = SECOND;
    update_level(floors);
    floors = FIRST;
    calls = INSIDE;
    update_calls(calls, floors);
    k_sleep(K_SECONDS(4));
    update_level(floors);
}

K_THREAD_DEFINE(test, STACKSIZE, test, NULL, NULL, NULL, PRIORITY, 0, K_NO_WAIT);
// Main
int main(void)
{
    initializing();
    while(1)
    {
        state_machine();
    }
    return 0;
}