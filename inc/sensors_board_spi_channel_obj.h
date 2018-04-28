#include "main.h"

static uint8_t address;
static uint8_t board_index;
static uint8_t sensor_index;


//**********************************************************

void spi_channel_apply_address(uint8_t address);

void spi_channel_receive_frame();
