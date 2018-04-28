#include "main.h"
#include "data_out_channel_obj.h"


static int frame[LENGTH_OF_FRAME];

void data_frame_add_value(int value, int frame_index);
void data_frame_flush_data();
