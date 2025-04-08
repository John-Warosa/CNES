#ifndef INSTRUCTIONS_INCREMENT_DECREMENT_H
#define INSTRUCTIONS_INCREMENT_DECREMENT_H

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
