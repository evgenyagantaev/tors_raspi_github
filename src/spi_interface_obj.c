#include "spi_interface_obj.h"
#include "gpio_obj.h"

void spi_init(void)
{
	// Inicializiruyem SPI                                                      
	bcm2835_spi_begin();                                                        	
	bcm2835_spi_setBitOrder(BCM2835_SPI_BIT_ORDER_MSBFIRST);		// DEFAULT  	
	bcm2835_spi_setDataMode(BCM2835_SPI_MODE0);						// DEFAULT	
	bcm2835_spi_setClockDivider(BCM2835_SPI_CLOCK_DIVIDER_64);		// 3.09 MHz   	
	bcm2835_spi_chipSelect(BCM2835_SPI_CS_NONE);					// DEFAULT  	
	//bcm2835_spi_setChipSelectPolarity(BCM2835_SPI_CS0, LOW);		// DEFAULT	
}


//#include "udp_send_thread.c"
//#include "metab_udp_thread.c"

void pause(void)
{
	int i;
	int x, y = 5;
	for(i=0; i<100; i++)
		x = y;
}

void one_usec_delay(void)
{
	volatile int i = 0;
	for(i=0; i<33; i++)
	{
		i++;
		i--;
	}
}

void chipselhigh()
{
	long i;

	// test delay
	for(i=0; i<10; i++)
	{
		i++;
		i--;
	}


	bcm2835_gpio_write(ADDR_A4, HIGH); 	
	bcm2835_gpio_write(ADDR_A0, HIGH); 	
	bcm2835_gpio_write(ADDR_A1, HIGH); 	
	bcm2835_gpio_write(ADDR_A2, HIGH); 	
	bcm2835_gpio_write(ADDR_A3, HIGH); 	
}

void set_address(uint8_t address)
{

	int i;
	uint8_t mask = 0x01;
	for(i=0; i<5; i++)
	{
		if(address & mask)
			bcm2835_gpio_write(addressA[i], HIGH); 
		else
			bcm2835_gpio_write(addressA[i], LOW); 
		mask = mask << 1;

	}

}



uint8_t read_byte(int address)
{

	struct timespec sleep_interval;

	sleep_interval.tv_sec = 0;
	sleep_interval.tv_nsec = 1000;	// 

	uint8_t return_data;
	uint8_t data_out;

	chipselhigh();

	//bcm2835_gpio_write(CHIP_SEL, LOW); // open SPI communication
	set_address(address_a);
	nanosleep(&sleep_interval, NULL);
	data_out = (uint8_t)0x80 | (uint8_t)address;
	bcm2835_spi_transfer(data_out);// send command (read register)
	return_data = bcm2835_spi_transfer(data_out);// read register data
	//bcm2835_gpio_write(CHIP_SEL, HIGH); // close SPI communication	
	chipselhigh();
	nanosleep(&sleep_interval, NULL);

	return return_data;
}


/*
void read_data_from_4x_board()
{
	int i;

	struct timespec sleep_interval;
	struct timespec long_sleep_interval;
	struct timespec long1_sleep_interval;

	sleep_interval.tv_sec = 0;
	sleep_interval.tv_nsec = 1000;	// 1 uSec
	long_sleep_interval.tv_sec = 0;
	long_sleep_interval.tv_nsec = 4000000;	// 4 mSec 
	long1_sleep_interval.tv_sec = 0;
	long1_sleep_interval.tv_nsec = 2000000;	// 50 uSec 

	int16_t return_data;
	uint8_t data_msb;
	uint8_t data_lsb;
	uint8_t data_out;
	uint16_t data_aux;

	chipselhigh();
	set_address(address_a);
	nanosleep(&sleep_interval, NULL);
	data_out = 0x21; // komanda chteniya
	bcm2835_spi_transfer(data_out);// send data
	//data_out = 0; // index v massive dannyh
	//bcm2835_spi_transfer(data_out);// send data
	chipselhigh();
	//set_address(address_a);
	nanosleep(&sleep_interval, NULL);  // wait for controller loads appropriate data

	for(i=0; i<9; i++)
	{
		set_address(address_a);                                    	
	    data_out = 0x00;
	    data_msb = bcm2835_spi_transfer(data_out);// read data
	    data_lsb = bcm2835_spi_transfer(data_out);// read data
	    chipselhigh();
	    nanosleep(&sleep_interval, NULL);
                                                                   
	    data_aux = ((uint16_t)data_msb)<<8 + (uint16_t)data_lsb;
	    data_4x_board[i] = (int16_t)data_aux;                           
		//printf("%7d   ");	
		//nanosleep(&long1_sleep_interval, NULL);  // wait for controller loads appropriate data
	}
	//printf("\r\n");

}
*/


void write_byte(int address, uint8_t data)
{

	struct timespec sleep_interval;

	sleep_interval.tv_sec = 0;
	sleep_interval.tv_nsec = 1000;	// 

	uint8_t data_out;

	chipselhigh();

	//bcm2835_gpio_write(CHIP_SEL, LOW); // open SPI communication
	set_address(address_a);
	nanosleep(&sleep_interval, NULL);
	data_out = (uint8_t)address;
	bcm2835_spi_transfer(data_out);// send command (write register)
	bcm2835_spi_transfer(data);// write register data
	//bcm2835_gpio_write(CHIP_SEL, HIGH); // close SPI communication	
	chipselhigh();
	nanosleep(&sleep_interval, NULL);
}

int16_t read_word(int high_address, int low_address)
{

	struct timespec sleep_interval;

	sleep_interval.tv_sec = 0;
	sleep_interval.tv_nsec = 1000;	// 

	uint8_t high_byte;
	uint8_t low_byte;
	uint8_t data_out;
	uint16_t buffer;
	int16_t result;

	chipselhigh();

	//bcm2835_gpio_write(CHIP_SEL, LOW); // open SPI communication
	set_address(address_a);
	nanosleep(&sleep_interval, NULL);
	data_out = (uint8_t)0x80 | (uint8_t)high_address;
	bcm2835_spi_transfer(data_out);// send command (read register)
	high_byte = bcm2835_spi_transfer(data_out);// read register data
	//bcm2835_gpio_write(CHIP_SEL, HIGH); // close SPI communication	
	chipselhigh();
	nanosleep(&sleep_interval, NULL);
	//bcm2835_gpio_write(CHIP_SEL, LOW); // open SPI communication
	set_address(address_a);
	nanosleep(&sleep_interval, NULL);
	data_out = (uint8_t)0x80 | (uint8_t)low_address;
	bcm2835_spi_transfer(data_out);// send command (read register)
	low_byte = bcm2835_spi_transfer(data_out);// read register data
	//bcm2835_gpio_write(CHIP_SEL, HIGH); // close SPI communication	
	chipselhigh();
	nanosleep(&sleep_interval, NULL);
	
	buffer = ((uint16_t)high_byte)<<8;
	buffer |= (uint16_t)low_byte;
	result = (int16_t)buffer;

	return result;
}
