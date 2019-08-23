#ifndef _CD4511_H_
#define _CD4511_H_

#include <device.h>
#include <gpio.h>

struct cd4511{
    struct device *device;
    char *dev_label;
    u32_t digit_one;
    u32_t digit_two;
    u8_t state_digit_one;
    u8_t state_digit_two;
};

typedef struct cd4511 cd4511_t;

/** 
 * Essa função tem como objetivo iniciar o driver do decoder,
 * ou seja, iniciar o device. 
 * @param decoder 
 *
 * @return 
 */
int decoder_open(cd4511_t *decoder, char *dev_label);

/** 
 * Essa função tem como objetivo configurar o pino do decoder
 * de acordo com suas flags.
 * @param decoder 
 * @param digit_one
 * @param digit_two 
 * @param flags 
 *
 * @return 
 */
int decoder_configure(cd4511_t *decoder, u32_t digit_one, u32_t digit_two, int flags);

/** 
 * Essa função tem como objetivo setar o estado do pino de
 * saída de acordo com o andar setado.
 * @param decoder
 * @param floor
 *
 * @return 
 */
int decoder_set(cd4511_t *decoder, u8_t floor);

/** 
 * Essa função tem como objetivo verificar se o device do
 * decoder foi inicializado apropriadamente.
 * @param decoder
 *
 * @return 
 */
int decoder_check_error(cd4511_t *decoder);

/** 
 * Essa função tem como objetivo criar o novo device de decoder
 * fazendo as chamadas padrão de open e configure
 * @param decoder
 * @param dev_label
 * @param digit_one_pin
 * @param digit_two_pin
 *
 * @return 
 */
int new_decoder(cd4511_t *decoder, char *dev_label, u32_t digit_one_pin, u32_t digit_two_pin);

#endif