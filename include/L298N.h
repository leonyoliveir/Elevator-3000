#ifndef _L298N_H_
#define _L298N_H_

#include <device.h>
#include <gpio.h>

struct l298n {
    struct device *device;
    char *dev_label;
    u32_t enable_pin;
    u32_t pin_one;
    u32_t pin_two;
    u8_t enable;
    u8_t state_one;
    u8_t state_two;
};

typedef struct l298n l298n_t;

/** 
 * Essa função tem como objetivo iniciar o driver l298n,
 * ou seja, iniciar o device. 
 * @param bridge
 *
 * @return 
 */
int bridge_open(l298n_t *bridge, char *dev_label);

/** 
 * Essa função tem como objetivo configurar o pino de saída
 * de acordo com suas flags.
 * @param bridge
 * @param pin1
 * @param pin2
 * @param enable 
 * @param flags 
 *
 * @return 
 */
int bridge_configure(l298n_t *bridge, u32_t pin1, u32_t pin2, u32_t enable_pin, int flags);

/** 
 * Essa função tem como objetivo habilitar o funcionamento
 * do motor.
 * @param bridge 
 *
 * @return 
 */
int bridge_enable(l298n_t *bridge);

/** 
 * Essa função tem como objetivo escrever os valores dos pinos
 * do motor.
 * @param bridge 
 *
 * @return 
 */
int bridge_set(l298n_t *bridge);

/** 
 * Essa função tem como objetivo realizar a parada
 * do motor.
 * @param bridge 
 *
 * @return 
 */
int stop_motor(l298n_t *bridge);

/** 
 * Essa função tem como objetivo acionar o mecanismo de
 * rotação à esquerda do motor
 * @param bridge 
 *
 * @return 
 */
int turn_left_motor(l298n_t *bridge);

/** 
 * Essa função tem como objetivo acionar o mecanismo de
 * rotação à direita do motor
 * @param bridge 
 *
 * @return 
 */
int turn_right_motor(l298n_t *bridge);

/** 
 * Essa função tem como objetivo verificar se o device do
 * motor foi inicilizado apropriadamente.
 * @param out
 *
 * @return 
 */
int bridge_check_error(l298n_t *bridge);

/** 
 * Essa função tem como objetivo criar o novo device da ponte H
 * fazendo as chamadas padrão de open e configure
 * @param bridge
 * @param dev_label
 * @param enable_pin
 * @param pin_one
 * @param pin_two
 *
 * @return 
 */
int new_bridge(l298n_t *bridge, char *dev_label, u32_t enable_pin, u32_t pin_one, u32_t pin_two);

#endif