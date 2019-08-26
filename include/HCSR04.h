/**
Sensor Ultrassônico
**/

#ifndef _HCRS04_H_
#define _HCRS04_H_

#include <device.h>
#include <gpio.h>

struct hcsr04 {
    struct device *device;
    char *dev_label;
    u32_t pin_echo;
    u32_t pin_trigger;
};

typedef struct hcsr04 hcsr04_t;

/** 
 * Essa função tem como objetivo iniciar o driver hcsr04,
 * ou seja, iniciar o device. 
 * @param ultrasonic
 *
 * @return 
 */
int ultrasonic_open(hcsr04_t *ultrasonic, char *dev_label);

/** 
 * Essa função tem como objetivo configurar o pino de saída
 * de acordo com suas flags.
 * @param ultrasonic
 * @param pin_trigger
 * @param pin_echo
 * @param flags_trigger
 * @param flags_echo
 *
 * @return 
 */
int ultrasonic_configure(hcsr04_t *ultrasonic, u32_t pin_trigger, u32_t pin_echo, int flags_trigger, int flags_echo);

/** 
 * Essa função tem como objetivo verificar a distancia
 * do objeto em relacao ao sensor ultrasonico.
 * @param ultrasonic
 *
 * @return distance
 */
int get_distance(hcsr04_t *ultrasonic);

/** 
 * Essa função tem como objetivo verificar se o device do
 * sensor ultrasonico foi inicilizado apropriadamente.
 * @param ultrasonic
 *
 * @return 
 */
int ultrasonic_check_error(hcsr04_t *ultrasonic);

/** 
 * Essa função tem como objetivo criar o novo device da ponte H
 * fazendo as chamadas padrão de open e configure
 * @param bridge
 * @param dev_label
 * @param enable_pin
 * @param pin_trigger
 * @param pin_echo
 *
 * @return 
 */
int new_ultrasonic(hcsr04_t *ultrasonic, char *dev_label, u32_t pin_trigger, u32_t pin_echo);

#endif
