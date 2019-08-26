#include <zephyr.h>
#include <misc/printk.h>
#include <misc/util.h>
#include <sys_clock.h>
#include <shell/shell.h>
#include "define.h"
#include "L298N.h" // Ponte H
#include "HCSR04.h" // Sensor Ultrassônico
#include "button.h" // Botão
#include "led.h" // Led
#include "calls.h" // Chamada
#include "CD4511.h" // Decodificador

l298n_t h_bridge;
hcsr04_t ultrasonic;
cd4511_t decoder;
button_t in_ground, in_first, in_second, in_third, out_ground, out_first, out_second, out_third;
led_t led_up, led_down, led_door;

void in_button_callback(struct device *dev, struct gpio_callback *cb, u32_t pin)
{
    if(pin & 1 << IN_GROUND)
    {
        printk("Ground floor called from inside\n");
        update_calls(INSIDE, GROUND);
    }
    if(pin & 1 << IN_FIRST)
    {
        printk("First floor called from inside\n");
        update_calls(INSIDE, FIRST);
    }
    if(pin & 1 << IN_SECOND)
    {
        printk("Second floor called from inside\n");
        update_calls(INSIDE, SECOND);
    }
    if(pin & 1 << IN_THIRD)
    {
        printk("Third floor called from inside\n");
        update_calls(INSIDE, THIRD);
    }
}

void out_button_callback(struct device *dev, struct gpio_callback *cb, u32_t pin)
{
    if(pin & 1 << OUT_GROUND)
    {
        printk("Ground floor called from outside\n");
        update_calls(OUTSIDE, GROUND);
    }
    if(pin & 1 << OUT_FIRST)
    {
        printk("First floor called from outside\n");
        update_calls(OUTSIDE, FIRST);
    }
    if(pin & 1 << OUT_SECOND)
    {
        printk("Second floor called from outside\n");
        update_calls(OUTSIDE, SECOND);
    }
    if(pin & 1 << OUT_THIRD)
    {
        printk("Third floor called from outside\n");
        update_calls(OUTSIDE, THIRD);
    }
}

void read_ultrasonic(void)
{
    floor_t floor = GROUND;
    while(1)
    {
        int distance = get_distance(&ultrasonic);
        if(distance >= 4 && distance <= 6) floor = GROUND;
        else if(distance >= 24 && distance <= 26) floor = FIRST;
        else if(distance >= 44 && distance <= 46) floor = SECOND;
        else if(distance >= 64 && distance <= 66) floor = THIRD;
        update_level(floor);
        //printk("Distancia atual: %d\n", distance);
    }
}

K_THREAD_DEFINE(read, STACKSIZE, read_ultrasonic, NULL, NULL, NULL, PRIORITY, 0, K_NO_WAIT);

void control_outputs(state_t atual, floor_t atual_level)
{
    printk("Controling outputs...\n");
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
            stop_motor(&h_bridge);
            break;
        default:
            led_set(&led_up, 1);
            led_set(&led_down, 1);
            led_set(&led_door, 1);
            stop_motor(&h_bridge);
            break;
    }
}

// Timeout de 5 segundos
u8_t timeout()
{
    k_sleep(K_SECONDS(5));
    return 1;
}

// Máquina de Estados
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
            break;
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
            break;
        case WAITING:
            printk("Elevator waiting for timeout...\n");
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
    printk("Andar atual: %d\n", atual_level);
}

void initializing_elevator(void)
{
    new_bridge(&h_bridge, DEVICE, BRIDGE_ENABLE, BRIDGE_PIN1, BRIDGE_PIN2);
    new_ultrasonic(&ultrasonic, DEVICE, US_TRIG_PIN, US_ECHO_PIN);
    new_decoder(&decoder, DEVICE, DECODER_PIN1, DECODER_PIN2);
    new_led(&led_up, DEVICE, LED_UP);
    new_led(&led_down, DEVICE, LED_DOWN);
    new_led(&led_door, DEVICE, LED_DOOR);
    new_button(&out_ground, DEVICE, OUT_GROUND, out_button_callback);
    new_button(&out_first, DEVICE, OUT_FIRST, out_button_callback);
    new_button(&out_second, DEVICE, OUT_SECOND, out_button_callback);
    new_button(&out_third, DEVICE, OUT_THIRD, out_button_callback);
    new_button(&in_ground, DEVICE, IN_GROUND, in_button_callback);
    new_button(&in_first, DEVICE, IN_FIRST, in_button_callback);
    new_button(&in_second, DEVICE, IN_SECOND, in_button_callback);
    new_button(&in_third, DEVICE, IN_THIRD, in_button_callback);
    calls_t calls = INSIDE;
    floor_t floors = GROUND;
    update_calls(calls, floors); 
}

int cmd_test_calls(const struct shell *shell, size_t argc, char **argv)
{
    int floor = *(*(argv + 1));
    shell_print(shell, "Calling elevator on floor %d...\n", floor);
    update_inside(floor, 1);
    shell_print(shell, "Called succesfully!\n");
    return 0;
}

int cmd_test_leds(const struct shell *shell, size_t argc, char **argv)
{
    shell_print(shell, "Testing leds of elevator going up...\n");
    led_set(&led_up, 0);
    k_sleep(SLEEP_TIME);
    led_set(&led_up, 1);
    shell_print(shell, "Testing leds of elevator going down...\n");
    led_set(&led_down, 0);
    k_sleep(SLEEP_TIME);
    led_set(&led_down, 1);
    shell_print(shell, "Test ended!\n");
    return 0;
}

int cmd_test_door(const struct shell *shell, size_t argc, char **argv)
{
    shell_print(shell, "Opening door and waiting for timeout...\n");
    led_set(&led_door, 0);
    if(timeout())
    {
        shell_print(shell, "Timeout reached! Closing door...\n");
        led_set(&led_door, 1);
    }
    shell_print(shell, "Test door ended\n");
    return 0;
}

SHELL_STATIC_SUBCMD_SET_CREATE(sub_test,
    SHELL_CMD_ARG(door, NULL, "Acione animaçao SPIN.", cmd_test_door, 1, NULL),
	SHELL_CMD_ARG(call, NULL, "Acione um Led.", cmd_test_calls, 2, NULL),
    SHELL_CMD_ARG(led, NULL, "Acione todos os Leds.", cmd_test_leds, 1, NULL),
	SHELL_SUBCMD_SET_END
);

SHELL_CMD_REGISTER(test, &sub_test, "Test comands for elevator 3000", NULL);

// Main
int main(void)
{
    initializing_elevator();
    while(1)
    {
        state_machine();
        k_sleep(K_SECONDS(1));
    }
    return 0;
}
