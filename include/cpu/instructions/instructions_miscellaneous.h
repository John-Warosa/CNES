#ifndef INSTRUCTIONS_MISCELLANEOUS_H
#define INSTRUCTIONS_MISCELLANEOUS_H

#include "instructions_type.h"

// BIT - Test bits in memory with accumulator
Mos6502_instruction Mos6502_BIT_zeropage;
Mos6502_instruction Mos6502_BIT_absolute;

// NOP - No operation
Mos6502_instruction Mos6502_NOP_implied;

#endif // INSTRUCTIONS_MISCELLANEOUS_H
