#include "spi_interface_obj.h"

spi_init()
{
	// Inicializiruyem SPI                                                      
	bcm2835_spi_begin();                                                        	
	bcm2835_spi_setBitOrder(BCM2835_SPI_BIT_ORDER_MSBFIRST);		// DEFAULT  	
	bcm2835_spi_setDataMode(BCM2835_SPI_MODE0);						// DEFAULT	
	bcm2835_spi_setClockDivider(BCM2835_SPI_CLOCK_DIVIDER_16);		// 15.6 MHz   	
	bcm2835_spi_chipSelect(BCM2835_SPI_CS_NONE);					// DEFAULT  	
	//bcm2835_spi_setChipSelectPolarity(BCM2835_SPI_CS0, LOW);		// DEFAULT	
}
