/**
Chamadas
**/
#ifndef _CALLS_H_
#define _CALLS_H_

#include <zephyr.h>

typedef enum {STOPPED, WAITING, GOING_UP, GOING_DOWN} state_t;
typedef enum {INSIDE, OUTSIDE, ARRIVE} calls_t;
typedef enum {GROUND, FIRST, SECOND, THIRD} floor_t;

void update_level(floor_t level);

void update_inside(floor_t destination, u8_t value);

void update_outside(floor_t destination, u8_t value);

floor_t check_level();

u8_t check_inside(floor_t destination);

u8_t check_outside(floor_t destination);

u8_t check_calls(floor_t destination);

u8_t check_calls_up(floor_t atual);

u8_t check_calls_down(floor_t atual);

void update_calls(calls_t source, floor_t destination);

#endif
