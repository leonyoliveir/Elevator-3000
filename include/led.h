#ifndef _led_H_
#define _led_H_

#include <device.h>
#include <gpio.h>

struct led {
    struct device *device;
    char *dev_label;
    u32_t pin;
    u8_t state;
};

typedef struct led led_t;

/** 
 * Essa função tem como objetivo iniciar o driver led,
 * ou seja, iniciar o device. 
 * @param led
 *
 * @return 
 */
int led_open(led_t *out, char *dev_label);

/** 
 * Essa função tem como objetivo configurar o pino do led
 * de acordo com suas flags.
 * @param out 
 * @param pin 
 * @param flags 
 *
 * @return 
 */
int led_configure(led_t *out, u32_t pin, int flags);

/** 
 * Essa função tem como objetivo setar o estado do pino de
 * saída para algum valor.
 * @param out 
 * @param value 
 *
 * @return 
 */
int led_set(led_t *out, u8_t value);

/** 
 * Essa função tem como objetivo verificar se o device de
 * saída foi inicializado apropriadamente.
 * @param out
 *
 * @return 
 */
int led_check_error(led_t *out);

/** 
 * Essa função tem como objetivo criar o novo device de saída
 * fazendo as chamadas padrão de open e configure
 * @param out
 * @param dev_label
 * @param pin
 *
 * @return 
 */
int new_led(led_t *out, char* dev_label, u32_t pin);
#endif
