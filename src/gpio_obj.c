#include "main.h"
#include "gpio_obj.h"




void gpio_init()
{
	bcm2835_gpio_fsel(DEBUG_PIN_0, BCM2835_GPIO_FSEL_OUTP);
	
	bcm2835_gpio_fsel(ADDR_A0, BCM2835_GPIO_FSEL_OUTP);
	bcm2835_gpio_write(ADDR_A0, LOW); // close SPI communication	
	bcm2835_gpio_fsel(ADDR_A1, BCM2835_GPIO_FSEL_OUTP);          	
	bcm2835_gpio_write(ADDR_A1, LOW); // close SPI communication	
	bcm2835_gpio_fsel(ADDR_A2, BCM2835_GPIO_FSEL_OUTP);          	
	bcm2835_gpio_write(ADDR_A2, LOW); // close SPI communication	
	bcm2835_gpio_fsel(ADDR_A3, BCM2835_GPIO_FSEL_OUTP);          	
	bcm2835_gpio_write(ADDR_A3, LOW); // close SPI communication	
	bcm2835_gpio_fsel(ADDR_A4, BCM2835_GPIO_FSEL_OUTP);          	
	bcm2835_gpio_write(ADDR_A4, LOW); // close SPI communication	
}

void gpio_debug_pin_set()
{
	bcm2835_gpio_write(DEBUG_PIN_0, HIGH); 
}
void gpio_debug_pin_reset()
{
	bcm2835_gpio_write(DEBUG_PIN_0, LOW); 
}

