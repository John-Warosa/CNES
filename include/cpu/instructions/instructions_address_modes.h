#ifndef INSTRUCTIONS_ADDRESS_MODES_H
#define INSTRUCTIONS_ADDRESS_MODES_H

#include <stdint.h>

typedef struct Bus Bus;

uint8_t Mos6502_get_byte_absolute(Bus *bus);
uint8_t Mos6502_get_byte_absolute_x(Bus *bus);
uint8_t Mos6502_get_byte_absolute_y(Bus *bus);

uint8_t Mos6502_get_byte_indirect(Bus *bus);
uint8_t Mos6502_get_byte_indirect_x(Bus *bus);
uint8_t Mos6502_get_byte_indirect_y(Bus *bus);

uint8_t Mos6502_get_byte_relative(Bus *bus);

uint8_t Mos6502_get_byte_zeropage(Bus *bus);
uint8_t Mos6502_get_byte_zeropage_x(Bus *bus);
uint8_t Mos6502_get_byte_zeropage_y(Bus *bus);

#endif // INSTRUCTIONS_ADDRESS_MODES_H
