#ifndef INSTRUCTIONS_INCREMENT_DECREMENT_H
#define INSTRUCTIONS_INCREMENT_DECREMENT_H

/*==============================================================================

Increment and Decrement instructions

Defined here are the DEC, DEX, DEY, INC, INX and INY instructions
for the 6502
These instructions are used by the processor to increment and decrement
registers and memory. The instructions set the negative and zero flag
based on the result

==============================================================================*/

#include "instructions_type.h"

// DEC - Decrement memory
Mos6502_instruction Mos6502_DEC_zeropage;
Mos6502_instruction Mos6502_DEC_zeropage_x;
Mos6502_instruction Mos6502_DEC_absolute;
Mos6502_instruction Mos6502_DEC_absolute_x;

// DEX - Decrement X register
Mos6502_instruction Mos6502_DEX_implied;

// DEX - Decrement Y register
Mos6502_instruction Mos6502_DEY_implied;

// INC - Increment memory
Mos6502_instruction Mos6502_INC_zeropage;
Mos6502_instruction Mos6502_INC_zeropage_x;
Mos6502_instruction Mos6502_INC_absolute;
Mos6502_instruction Mos6502_INC_absolute_x;

// INX - Increment X register
Mos6502_instruction Mos6502_INX_implied;

// INY - Increment Y register
Mos6502_instruction Mos6502_INY_implied;

#endif // INSTRUCTIONS_INCREMENT_DECREMENT_H
