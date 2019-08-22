#include <zephyr.h>
#include <misc/printk.h>
#include <misc/util.h>
#include <sys_clock.h>
#include "define.h"
#include "L298N.h"
#include "HCSR04.h"
#include "button.h"
#include "led.h"

l298n_t h_bridge;
hcsr04_t ultrasonic;
button_t in_ground, in_first, in_second, in_third, out_ground, out_first_up, out_first_down, out_second_up, out_second_down, out_third;
led_t led_up, led_down, led_door;

typedef enum {STOPPED, WAITING, GOING_UP, GOING_DOWN} state_t;
typedef enum {INSIDE, OUT_UP, OUT_DOWN, ARRIVE} calls_t;
typedef enum {GROUND, FIRST, SECOND, THIRD} floor_t;

// Def Semaf
K_SEM_DEFINE(elevator_in, 0, 1);
K_SEM_DEFINE(elevator_out_up, 0, 1);
K_SEM_DEFINE(elevator_out_down, 0, 1);
K_SEM_DEFINE(elevator_level, 0, 1);

static u8_t calls_in[4] = {0, 0, 0, 0};
static u8_t calls_up_out[3] = {0, 0, 0};
static u8_t calls_down_out[3] = {0, 0, 0};
static u8_t atual_level = 0;

void update_level(floor_t level)
{
    k_sem_take(&elevator_level, K_FOREVER);
    atual_level = level;
    k_sem_give(&elevator_level);
}

void update_inside(floor_t destination, u8_t value)
{
    k_sem_take(&elevator_in, K_FOREVER);
    calls_in[destination] = value;
    k_sem_give(&elevator_in);
}

void update_outside_up(floor_t destination, u8_t value)
{
    k_sem_take(&elevator_out_up, K_FOREVER);
    calls_up_out[destination] = value;
    k_sem_give(&elevator_out_up);
}

void update_outside_down(floor_t destination, u8_t value)
{
    k_sem_take(&elevator_out_down, K_FOREVER);
    calls_down_out[destination - 1] = value;
    k_sem_give(&elevator_in);
}

u8_t check_calls(int i)
{
    if(calls_in[i] == 1 || (i > 0 && calls_down_out[i-1] == 1) || (i < 3 && calls_up_out[i]))
    {
        return 1;
    }
    return 0;
}

u8_t check_calls_up()
{
    for(int i = atual_level; i <= 3; i++)
    {
        if(check_calls(i)) return 1;
    }
    return 0;
}

u8_t check_calls_down()
{
    for(int i = 0; i <= atual_level; i++)
    {
        if(check_calls(i)) return 1;
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
K_THREAD_DEFINE(check_b, STACKSIZE, buttonsThread, NULL, NULL, NULL,
        PRIORITY - 1, 0, K_NO_WAIT);
K_THREAD_DEFINE(check_l, STACKSIZE, ledsThread, NULL, NULL, NULL,
        PRIORITY, 0, K_NO_WAIT);

u8_t timeout()
{
    return 1;
}

void state_machine()
{
    static state_t atual = STOPPED;
    static state_t next = STOPPED;
    switch(atual)
    {
        case STOPPED:
            if(check_calls(atual_level)) next = WAITING;
            else if(check_calls_down()) next = GOING_DOWN;
            else if(check_calls_up()) next = GOING_UP;
            else next = STOPPED;
            break;
        case GOING_UP:
            if(check_calls(atual_level)) next = STOPPED;
            else next = GOING_UP;
            break;
        case GOING_DOWN:
            if(check_calls(atual_level)) next = STOPPED;
            else next = GOING_DOWN;
            break;
        case WAITING:
            if(timeout())
            {
                update_calls(ARRIVE, atual_level);
                next = STOPPED;
            }
            else next = WAITING;
            break;
        default:
            break;
    }
    atual = next;
}

// Main
int main(void)
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
    return 0;
}