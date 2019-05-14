#include "main.h"
#include "gpio_obj.h"
#include "spi_interface_obj.h"


int main()
{
	long_sleep_interval.tv_sec = 0;
	long_sleep_interval.tv_nsec = 1000000;	// 1 mSec
	
	// Inicializiruem periferiyu
	if(!bcm2835_init())
	{
		printf("\nbcm2835 initialization failed\n");
		return 1;
	}
	else // Everything OK with periphery
	{
		printf("\nbcm2835 initialization successful\n");
		
		gpio_init();
		spi_init();

		while(1)
	    {

			//*
	    	// set debug pin
	    	gpio_debug_pin_set();
	    	// pause (1 msec)
	        nanosleep(&long_sleep_interval, NULL);
	    	// reset debug pin
	    	gpio_debug_pin_reset();
	    	// pause (1 msec)
	        nanosleep(&long_sleep_interval, NULL);
	    	printf("Hello? Master!\r\n");                
			//*/




		}

	}
}
