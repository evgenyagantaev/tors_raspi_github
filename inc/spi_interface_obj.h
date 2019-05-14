#ifndef SPI_INTERFACE_OBJ_H
#define SPI_INTERFACE_OBJ_H

#include "main.h"

void spi_init(void);
void pause(void);
void one_usec_delay(void);
void chipselhigh();
void set_address(uint8_t address);
uint8_t read_byte(int address);
void write_byte(int address, uint8_t data);
int16_t read_word(int high_address, int low_address);

#endif
