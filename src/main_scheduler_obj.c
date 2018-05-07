#include "main.h"
#include "gpio_obj.h"


int main()
{
	long_sleep_interval.tv_sec = 0;
	long_sleep_interval.tv_nsec = 1000000;	// 1 mSec

	while(1)
	{
		// set debug pin
		//gpio_debug_pin_set();
		// pause (1 msec)
	    nanosleep(&long_sleep_interval, NULL);

		// reset debug pin
		//gpio_debug_pin_reset();
		// pause (1 msec)
	    nanosleep(&long_sleep_interval, NULL);

		printf("Hello? Master!\r\n");
	}
}
