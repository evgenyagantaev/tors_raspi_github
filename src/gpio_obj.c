#include "main.h"
#include "gpio_obj.h"


void gpio_debug_pin_set()
{
	bcm2835_gpio_write(DEBUG_PIN_0, HIGH); 
}
void gpio_debug_pin_reset()
{
	bcm2835_gpio_write(DEBUG_PIN_0, LOW); 
}

