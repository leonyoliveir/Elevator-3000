#include "CD4511.h"
#include <misc/printk.h>

#define ERROR_CODE -1
#define DECODER_FLAGS GPIO_DIR_OUT

int decoder_open(cd4511_t *decoder, char *dev_label)
{
    decoder->device = device_get_binding(dev_label);
    if(decoder_check_error(decoder)) return ERROR_CODE;
    decoder->dev_label = dev_label;
    decoder->digit_one = (u32_t) NULL;
    decoder->digit_two = (u32_t) NULL;
    if(decoder_check_error(decoder)) return ERROR_CODE;
    printk("New decoder initialized succesfullt in the device %s\n", dev_label);
    return 0;
}

int decoder_configure(cd4511_t *decoder, u32_t digit_one, u32_t digit_two, int flags)
{
    if(decoder_check_error(decoder)) return ERROR_CODE;
    decoder->digit_one = digit_one;
    decoder->digit_two = digit_two;
    decoder->state_digit_one = 0;
    decoder->state_digit_two = 0;
    gpio_pin_configure(decoder->device, digit_one, flags);
    gpio_pin_configure(decoder->device, digit_two, flags);
    gpio_pin_write(decoder->device, digit_one, decoder->state_digit_one);
    gpio_pin_write(decoder->device, digit_two, decoder->state_digit_two);
    printk("Decoder configured succesfully at pins %d, %d\n", digit_one, digit_two);
    return 0;
}

int decoder_set(cd4511_t *decoder, u8_t floor)
{
    if(decoder_check_error(decoder)) return ERROR_CODE;
    else if(decoder->digit_one == (u32_t) NULL || decoder->digit_two == (u32_t) NULL)
    {
        printk("ERROR! First configure device\n");
        return ERROR_CODE;
    }
    decoder->state_digit_one = floor & 1;
    decoder->state_digit_two = (floor >> 1) & 1;
    gpio_pin_write(decoder->device, decoder->digit_one, decoder->state_digit_one);
    gpio_pin_write(decoder->device, decoder->digit_two, decoder->state_digit_two);
    printk("Decoder value changed to %d\n", floor);
    return 0;
}

int decoder_check_error(cd4511_t *decoder)
{
    if(!decoder->device)
    {
        printk("ERROR! First initialize device\n");
        return ERROR_CODE;
    }
    return 0;
}

int new_decoder(cd4511_t *decoder, char *dev_label, u32_t digit_one_pin, u32_t digit_two_pin)
{
    printk("Initializing new decoder...\n");
    decoder_open(decoder, dev_label);
    printk("Setting the new decoder...\n");
    decoder_configure(decoder, digit_one_pin, digit_two_pin, DECODER_FLAGS);
    printk("Finished new decoder succesfully!\n");
    return 0;
}