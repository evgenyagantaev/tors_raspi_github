#include "main.h"


struct udp_packet_type
{
	int sensors_data[NUMBER_OF_SENSORS][LENGTH_OF_FRAME];
	int id;
};
union data_out_union
{
	struct udp_packet_type sensors_data_array;
	uint8_t byte_array[SIZEOFINT*NUMBER_OF_SENSORS*LENGTH_OF_FRAME + SIZEOFINT];
};

//**********************************************************

static uint8_t *data_out_pointer;

static union data_out_union data_out;

//**********************************************************

void data_out_channel_add_value(int value, int sensor_number, int frame_index);
void data_out_channel_flush_data();


