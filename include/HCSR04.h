#ifndef _HCRS04_H_
#define _HCRS04_H_

struct hcsr04 {
    struct device *device;
    struct gpio_callback gpio_callback;
    char *dev_label;
    u32_t pin;
};

typedef struct hcsr04 hcsr04_t;

#endif