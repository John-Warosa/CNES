#ifndef INSTRUCTIONS_ADDRESS_MODES_H
#define INSTRUCTIONS_ADDRESS_MODES_H

/*==============================================================================

The following interface defines funtions that can be used to get the address
after decoding the address mode
For this purpose, a special struct is returned that contains both
the decoded address and the number of extra cycles from page crossing

The only excluded address modes are:

  - Accumulator, as it only reads from the accumulator

  - Immediate, as it directly takes the given byte

  - Implied, as it does not fetch any bytes


The address modes work as follows:

  - Absolute: Get byte from 16 bit address HiLo

  - Absolute,X: Get byte from 16 bit address HiLo + X register
                If Lo overflows into Hi, add one CPU cycle

  - Absolute,Y: Same as Absolute,X but with Y register

  - Indirect:

  - X,Indirect:

  - Indirect,Y:

  - Relative: NOTE: maybe unneeded?

  - Zeropage: Get byte from 16 bit address 00Lo

  - Zeropage,X: Get byte from 16 bit address 00Lo + X register
                Lo can overflow, but it does not affect the Hi byte

  - Zeropage,Y: Same as Zeropage,X but with Y register

==============================================================================*/

#include "cpu/mos6502_types.h"
#include <stdint.h>

typedef struct {
  uint16_t address;
  uint8_t extraCycles;
  uint8_t bytesRead;
} Mos6502_DecodedAddress;

Mos6502_DecodedAddress Mos6502_decode_absolute(const Mos6502 *cpu);
Mos6502_DecodedAddress Mos6502_decode_absolute_x(const Mos6502 *cpu);
Mos6502_DecodedAddress Mos6502_decode_absolute_y(const Mos6502 *cpu);

Mos6502_DecodedAddress Mos6502_decode_indirect(const Mos6502 *cpu);
Mos6502_DecodedAddress Mos6502_decode_indirect_x(const Mos6502 *cpu);
Mos6502_DecodedAddress Mos6502_decode_indirect_y(const Mos6502 *cpu);

Mos6502_DecodedAddress Mos6502_decode_relative(const Mos6502 *cpu);

Mos6502_DecodedAddress Mos6502_decode_zeropage(const Mos6502 *cpu);
Mos6502_DecodedAddress Mos6502_decode_zeropage_x(const Mos6502 *cpu);
Mos6502_DecodedAddress Mos6502_decode_zeropage_y(const Mos6502 *cpu);

#endif // INSTRUCTIONS_ADDRESS_MODES_H
