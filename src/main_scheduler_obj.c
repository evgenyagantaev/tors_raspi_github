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

			/*
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


			uint8_t i;
			
#define DATA_LENGTH 3000
#define NUMBER_OF_CHANNELS 4

			int16_t data_array[NUMBER_OF_CHANNELS][DATA_LENGTH];
			int j;

			uint8_t ms_byte;
			uint8_t ls_byte;
			uint16_t data_sample;

			i = 0x03;
			set_address(i);
			// read data from i-th MC
			for(j=0; j<DATA_LENGTH; j++)
			{
				 ms_byte = bcm2835_spi_transfer(0x55);// read ms byte
				 ls_byte = bcm2835_spi_transfer(0x55);// read ls byte

				 data_sample = 0;
				 data_sample += ms_byte;
				 data_sample <<= 8;
				 data_sample += ls_byte;
				 data_array[i][j] = (int16_t)data_sample;

			}
			chipselhigh();
	        nanosleep(&long_sleep_interval, NULL);
			i = 0x06;
			set_address(i);
			// read data from i-th MC
			for(j=0; j<DATA_LENGTH; j++)
			{
				 ms_byte = bcm2835_spi_transfer(0x55);// read ms byte
				 ls_byte = bcm2835_spi_transfer(0x55);// read ls byte

				 data_sample = 0;
				 data_sample += ms_byte;
				 data_sample <<= 8;
				 data_sample += ls_byte;
				 data_array[i][j] = (int16_t)data_sample;

			}
			chipselhigh();
	        nanosleep(&long_sleep_interval, NULL);
			i = 0x00;
			set_address(i);
			// read data from i-th MC
			for(j=0; j<DATA_LENGTH; j++)
			{
				 ms_byte = bcm2835_spi_transfer(0x55);// read ms byte
				 ls_byte = bcm2835_spi_transfer(0x55);// read ls byte

				 data_sample = 0;
				 data_sample += ms_byte;
				 data_sample <<= 8;
				 data_sample += ls_byte;
				 data_array[i][j] = (int16_t)data_sample;

			}
			chipselhigh();
	        nanosleep(&long_sleep_interval, NULL);
			i = 0x05;
			set_address(i);
			// read data from i-th MC
			for(j=0; j<DATA_LENGTH; j++)
			{
				 ms_byte = bcm2835_spi_transfer(0x55);// read ms byte
				 ls_byte = bcm2835_spi_transfer(0x55);// read ls byte

				 data_sample = 0;
				 data_sample += ms_byte;
				 data_sample <<= 8;
				 data_sample += ls_byte;
				 data_array[i][j] = (int16_t)data_sample;

			}
			chipselhigh();
	        nanosleep(&long_sleep_interval, NULL);

		}

	}
}
