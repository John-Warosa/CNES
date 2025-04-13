#ifndef INSTRUCTIONS_SHIFT_ROTATE_H
#define INSTRUCTIONS_SHIFT_ROTATE_H

#include "cpu/mos6502_types.h"

// ASL - Arithmetic shift left
Mos6502_instruction Mos6502_ASL_accumulator;
Mos6502_instruction Mos6502_ASL_zeropage;
Mos6502_instruction Mos6502_ASL_zeropage_x;
Mos6502_instruction Mos6502_ASL_absolute;
Mos6502_instruction Mos6502_ASL_absolute_x;

// LSR - Logical shift right
Mos6502_instruction Mos6502_LSR_accumulator;
Mos6502_instruction Mos6502_LSR_zeropage;
Mos6502_instruction Mos6502_LSR_zeropage_x;
Mos6502_instruction Mos6502_LSR_absolute;
Mos6502_instruction Mos6502_LSR_absolute_x;

// ROL - Rotate left with carry bit
Mos6502_instruction Mos6502_ROL_accumulator;
Mos6502_instruction Mos6502_ROL_zeropage;
Mos6502_instruction Mos6502_ROL_zeropage_x;
Mos6502_instruction Mos6502_ROL_absolute;
Mos6502_instruction Mos6502_ROL_absolute_x;

// ROR - Rotate right with zero bit
Mos6502_instruction Mos6502_ROR_accumulator;
Mos6502_instruction Mos6502_ROR_zeropage;
Mos6502_instruction Mos6502_ROR_zeropage_x;
Mos6502_instruction Mos6502_ROR_absolute;
Mos6502_instruction Mos6502_ROR_absolute_x;

#endif // INSTRUCTIONS_SHIFT_ROTATE_H
