#ifndef INSTRUCTIONS_COMPARISONS_H
#define INSTRUCTIONS_COMPARISONS_H

#include "cpu/mos6502_types.h"

// CMP - Compare memory with accumulator
Mos6502_instruction Mos6502_CMP_immediate;
Mos6502_instruction Mos6502_CMP_zeropage;
Mos6502_instruction Mos6502_CMP_zeropage_x;
Mos6502_instruction Mos6502_CMP_absolute;
Mos6502_instruction Mos6502_CMP_absolute_x;
Mos6502_instruction Mos6502_CMP_absolute_y;
Mos6502_instruction Mos6502_CMP_indirect_x;
Mos6502_instruction Mos6502_CMP_indirect_y;

// CPX - Compare memory with X register
Mos6502_instruction Mos6502_CPX_immediate;
Mos6502_instruction Mos6502_CPX_zeropage;
Mos6502_instruction Mos6502_CPX_absolute;

// CPY - Compare memory with Y register
Mos6502_instruction Mos6502_CPY_immediate;
Mos6502_instruction Mos6502_CPY_zeropage;
Mos6502_instruction Mos6502_CPY_absolute;

#endif // INSTRUCTIONS_COMPARISONS_H
