#include "calls.h"

static u8_t calls_in[4] = {0, 0, 0, 0};
static u8_t calls_out[4] = {0, 0, 0, 0};
static floor_t atual_level = GROUND;

K_SEM_DEFINE(elevator_in, 1, 1);
K_SEM_DEFINE(elevator_out, 1, 1);
K_SEM_DEFINE(elevator_level, 1, 1);

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

void update_outside(floor_t destination, u8_t value)
{
    k_sem_take(&elevator_out, K_FOREVER);
    calls_out[destination] = value;
    k_sem_give(&elevator_out);
}

floor_t check_level()
{
    //printk("Checando andar...\n");
    k_sem_take(&elevator_level, K_FOREVER);
    floor_t return_level = atual_level;
    k_sem_give(&elevator_level);
    return return_level;
}

u8_t check_inside(floor_t destination)
{
    k_sem_take(&elevator_in, K_FOREVER);
    u8_t there_is_a_call = calls_in[destination];
    k_sem_give(&elevator_in);
    return there_is_a_call;
}

u8_t check_outside(floor_t destination)
{
    k_sem_take(&elevator_out, K_FOREVER);
    u8_t there_is_a_call = calls_out[destination];
    k_sem_give(&elevator_out);
    return there_is_a_call;
}