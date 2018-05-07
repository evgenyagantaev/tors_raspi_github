#ifndef GPIO
#define GPIO

#include "main.h"

#define ADDR_A0 RPI_BPLUS_GPIO_J8_29
#define ADDR_A1 RPI_BPLUS_GPIO_J8_31
#define ADDR_A2 RPI_BPLUS_GPIO_J8_33
#define ADDR_A3 RPI_BPLUS_GPIO_J8_35
#define ADDR_A4 RPI_BPLUS_GPIO_J8_37

#define DEBUG_PIN_0 RPI_BPLUS_GPIO_J8_40


void gpio_debug_pin_set();
void gpio_debug_pin_reset();

#endif
