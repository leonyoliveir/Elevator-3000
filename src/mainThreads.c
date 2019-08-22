/*Teste para utilizar 
Theads e interrupções 
no projeto*/
/*
Criar Thread para botão
e leds pois vão estar rodando em paralelo*/

#include <zephyr.h>
#include <device.h>
#include <gpio.h>
#include <misc/printk.h>
#include <misc/__assert.h>
#include <string.h>

/* size of stack area used by each thread */
#define STACKSIZE 1024

/* scheduling priority used by each thread */
#define PRIORITY 7

/*----------------------------------------------------leds-----------------------------------------------

/* Change this if you have an LED connected to a custom port */
#ifndef LED0_GPIO_CONTROLLER
#define LED0_GPIO_CONTROLLER 	LED0_GPIO_PORT
#endif
#ifndef LED1_GPIO_CONTROLLER
#define LED1_GPIO_CONTROLLER 	LED1_GPIO_PORT
#endif
#ifndef LED2_GPIO_CONTROLLER
#define LED1_GPIO_CONTROLLER 	LED1_GPIO_PORT
#endif
#ifndef LED3_GPIO_CONTROLLER
#define LED1_GPIO_CONTROLLER 	LED1_GPIO_PORT
#endif

#define PORT0	 LED0_GPIO_CONTROLLER
#define PORT1	 LED1_GPIO_CONTROLLER


/* Change this if you have an LED connected to a custom pin */
#define LED0    LED0_GPIO_PIN
#define LED1    LED1_GPIO_PIN
#define LED2	LED2_GPIO_PIN
#define LED3	LED3_GPIO_PIN

/*----------------------------------------------------buttons-----------------------------------------------
/* change this to use another GPIO port */
#ifndef SW0_GPIO_CONTROLLER
#ifdef SW0_GPIO_NAME
#define SW0_GPIO_CONTROLLER SW0_GPIO_NAME
#else
#error SW0_GPIO_NAME or SW0_GPIO_CONTROLLER needs to be set in board.h
#endif
#endif
#define PORT	SW0_GPIO_CONTROLLER

/* change this to use another GPIO pin */
#ifdef SW0_GPIO_PIN
#define PIN     SW0_GPIO_PIN
#else
#error SW0_GPIO_PIN needs to be set in board.h
#endif

/* change to use another GPIO pin interrupt config */
#ifdef SW0_GPIO_FLAGS
#define EDGE    (SW0_GPIO_FLAGS | GPIO_INT_EDGE)
#else
/*
 * If SW0_GPIO_FLAGS not defined used default EDGE value.
 * Change this to use a different interrupt trigger
 */
#define EDGE    (GPIO_INT_EDGE | GPIO_INT_ACTIVE_LOW)
#endif

/* change this to enable pull-up/pull-down */
#ifndef SW0_GPIO_FLAGS
#ifdef SW0_GPIO_PIN_PUD
#define SW0_GPIO_FLAGS SW0_GPIO_PIN_PUD
#else
#define SW0_GPIO_FLAGS 0
#endif
#endif
#define PULL_UP SW0_GPIO_FLAGS

/* Sleep time */
#define SLEEP_TIME	500

struct printk_data_t {
	void *fifo_reserved; /* 1st word reserved for use by fifo */
	u32_t led;
	u32_t cnt;
};

K_FIFO_DEFINE(printk_fifo);

void blink(const char *port, u32_t sleep_ms, u32_t led, u32_t id) // Função para acender led
{
	int cnt = 0;
	struct device *gpio_dev;

	gpio_dev = device_get_binding(port);
	__ASSERT_NO_MSG(gpio_dev != NULL);

	gpio_pin_configure(gpio_dev, led, GPIO_DIR_OUT);

	while (1) {
		gpio_pin_write(gpio_dev, led, cnt % 2);

		struct printk_data_t tx_data = { .led = id, .cnt = cnt };

		size_t size = sizeof(struct printk_data_t);
		char *mem_ptr = k_malloc(size);
		__ASSERT_NO_MSG(mem_ptr != 0);

		memcpy(mem_ptr, &tx_data, size);

		k_fifo_put(&printk_fifo, mem_ptr);

		k_sleep(sleep_ms);
		cnt++;
	}
}

void pressed(){

	struct device *gpiob;

	printk("Press the user defined button on the board\n");
	gpiob = device_get_binding(PORT);
	if (!gpiob) {
		printk("error\n");
		return;
	}
	gpio_pin_configure(gpiob, PIN,
			   GPIO_DIR_IN | GPIO_INT |  PULL_UP | EDGE);

	gpio_init_callback(&gpio_cb, button_pressed, BIT(PIN));

	gpio_add_callback(gpiob, &gpio_cb);
	gpio_pin_enable_callback(gpiob, PIN);
}

void button_pressed(struct device *gpiob, struct gpio_callback *cb, u32_t pins){

	printk("Button pressed at %d\n", k_cycle_get_32());

}

void blink1(void) // Lógica para acender o led de cada andar
{
	blink(PORT0, 100, LED0, 0);
}



K_THREAD_DEFINE(button1_id, STACKSIZE, button_pressed, NULL, NULL, NULL, PRIORITY - 1, 0, K_NO_WAIT)

K_THREAD_DEFINE(blink1_id, STACKSIZE, blink1, NULL, NULL, NULL, PRIORITY, 0, K_NO_WAIT);

int main(void){
	while (1) {
		u32_t val = 0U;

		gpio_pin_read(gpiob, PIN, &val);
		k_sleep(SLEEP_TIME);
	}
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------



#include <zephyr.h>
#include <device.h>
#include <gpio.h>

#define PORT_LED0   LED0_GPIO_CONTROLLER
#define PORT_LED1   LED1_GPIO_CONTROLLER
#define PORT_LED2   LED2_GPIO_CONTROLLER
#define PORT_LED3   LED3_GPIO_CONTROLLER
#define PIN_LED0    LED0_GPIO_PIN
#define PIN_LED1    LED1_GPIO_PIN
#define PIN_LED2    LED2_GPIO_PIN
#define PIN_LED3    LED3_GPIO_PIN

#define PORT_SW0	SW0_GPIO_CONTROLLER
#define PORT_SW1    SW1_GPIO_CONTROLLER
#define PORT_SW2    SW2_GPIO_CONTROLLER
#define PORT_SW3    SW3_GPIO_CONTROLLER
#define PIN_SW0     SW0_GPIO_PIN
#define PIN_SW1     SW1_GPIO_PIN
#define PIN_SW2     SW2_GPIO_PIN
#define PIN_SW3     SW3_GPIO_PIN

#define INTERRUPT   GPIO_INT
#define FALL_EDGE   (GPIO_INT_EDGE | GPIO_INT_ACTIVE_LOW)
#define DEBOUNCE    GPIO_INT_DEBOUNCE
#define PULL_UP     GPIO_PUD_PULL_UP

#define SW_FLAGS    (GPIO_DIR_IN | INTERRUPT | FALL_EDGE | DEBOUNCE | PULL_UP)

#define SLEEP_TIME 500

struct start_led{
	bool led_1: 1;
	bool led_2: 1;
	bool led_3: 1;
	bool led_4: 1;
};


struct device *button1;
struct device *button2;
struct device *button3;
struct device *button4;

struct device *led_1;
struct device *led_2;
struct device *led_3;
struct device *led_4;

static struct gpio_callback cb_1;
static struct gpio_callback cb_2;
static struct gpio_callback cb_3;
static struct gpio_callback cb_4;
static struct start_led l = {1, 1, 1, 1};

void call_led(int n)
{
	switch(n){
		case 1:
		l.led_1 = !l.led_1;
		gpio_pin_write(led_1, PIN_LED0, l.led_1);
		break;
		case 2:
		l.led_2 = !l.led_2;
		gpio_pin_write(led_2, PIN_LED1, l.led_2);
		break;
		case 3:
		l.led_3 = !l.led_3;
		gpio_pin_write(led_3, PIN_LED2, l.led_3);
		break;
		case 4:
		l.led_4 = !l.led_4;
		gpio_pin_write(led_4, PIN_LED3, l.led_4);
	}
}

void reset_leds(){
	gpio_pin_write(led_1, PIN_LED0, 1);
	gpio_pin_write(led_2, PIN_LED1, 1);
	gpio_pin_write(led_3, PIN_LED2, 1);
	gpio_pin_write(led_4, PIN_LED3, 1);
}

void sw1_callback(struct device *sw, struct gpio_callback *cb, u32_t pins){
	call_led(1);
}
void sw2_callback(struct device *sw, struct gpio_callback *cb, u32_t pins){
	call_led(2);
}
void sw3_callback(struct device *sw, struct gpio_callback *cb, u32_t pins){
	call_led(3);
}
void sw4_callback(struct device *sw, struct gpio_callback *cb, u32_t pins){
	call_led(4);
}

void main(){
	button1 = device_get_binding(PORT_SW0);
    button2 = device_get_binding(PORT_SW1);
    button3 = device_get_binding(PORT_SW2);
    button4 = device_get_binding(PORT_SW3);

    led_1 = device_get_binding(PORT_LED0);
    led_2 = device_get_binding(PORT_LED1);
    led_3 = device_get_binding(PORT_LED2);
    led_4 = device_get_binding(PORT_LED3);

    gpio_pin_configure(button1, PIN_SW0, SW_FLAGS);
    gpio_pin_configure(button2, PIN_SW1, SW_FLAGS);
    gpio_pin_configure(button3, PIN_SW2, SW_FLAGS);
    gpio_pin_configure(button4, PIN_SW3, SW_FLAGS);

    gpio_pin_configure(led_1, PIN_LED0, GPIO_DIR_OUT);
    gpio_pin_configure(led_2, PIN_LED1, GPIO_DIR_OUT);
    gpio_pin_configure(led_3, PIN_LED2, GPIO_DIR_OUT);
    gpio_pin_configure(led_4, PIN_LED3, GPIO_DIR_OUT);

    gpio_init_callback(&cb_1, sw1_callback, BIT(PIN_SW0));
    gpio_init_callback(&cb_2, sw2_callback, BIT(PIN_SW1));
    gpio_init_callback(&cb_3, sw3_callback, BIT(PIN_SW2));
    gpio_init_callback(&cb_4, sw4_callback, BIT(PIN_SW3));

    gpio_add_callback(button1, &cb_1);
    gpio_add_callback(button2, &cb_2);
    gpio_add_callback(button3, &cb_3);
    gpio_add_callback(button4, &cb_4);

    gpio_pin_enable_callback(button1, PIN_SW0);
    gpio_pin_enable_callback(button2, PIN_SW1);
    gpio_pin_enable_callback(button3, PIN_SW2);
    gpio_pin_enable_callback(button4, PIN_SW3);

    reset_leds();
    while(1)
    {
        u32_t value = 0U;

        gpio_pin_read(button1, PIN_SW0, &value);
        gpio_pin_read(button2, PIN_SW1, &value);
        gpio_pin_read(button3, PIN_SW2, &value);
        gpio_pin_read(button4, PIN_SW3, &value);

		k_sleep(SLEEP_TIME);
    }   
}