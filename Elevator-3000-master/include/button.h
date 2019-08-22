#ifndef _button_H_
#define _button_H_

#include <device.h>
#include <gpio.h>

struct button {
    struct device *device;
    struct gpio_callback gpio_callback;
    char *dev_label;
    u32_t pin;
};

typedef struct button button_t;

/** 
 * Essa função tem como objetivo iniciar o device do driver
 * de entrada.
 * @param in 
 *
 * @return 
 */
int button_open(button_t *in, char *dev_label);

/** 
 * Essa função tem como objetivo configurar o pino de entrada.
 *
 * @param in 
 * @param pin 
 * @param flags 
 * @param cb 
 *
 * @return 
 */
int button_configure(button_t *in, u32_t pin, int flags, gpio_callback_handler_t cb);

/** 
 * Essa função tem como objetivo fazer uma leitura do pino
 * de entrada.
 * @param in 
 * @param state 
 *
 * @return 
 */
int button_read(button_t *in, u32_t *state);

/** 
 * Essa função tem como objetivo verificar se o device de
 * entrada foi inicilizado apropriadamente.
 * @param in 
 *
 * @return 
 */
int button_check_error(button_t *in);

/** 
 * Essa função tem como objetivo criar o novo device de entrada
 * fazendo as chamadas padrão de open e configure
 * @param out
 * @param dev_label
 * @param pin
 *
 * @return 
 */
int new_button(button_t *in, char* dev_label, u32_t pin, gpio_callback_handler_t cb);

#endif
