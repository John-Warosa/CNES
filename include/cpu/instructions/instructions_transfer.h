#ifndef INSTRUCTIONS_TRANSFER_H
#define INSTRUCTIONS_TRANSFER_H

/*==============================================================================

Transfer instructions

The following interface defines the instructions that are used
to transfer registers, stack pointer and accumulator

==============================================================================*/

#include "cpu/instructions/instructions_type.h"

// LDA - Load value into accumulator
Mos6502_instruction Mos6502_LDA_immediate;
Mos6502_instruction Mos6502_LDA_zeropage;
Mos6502_instruction Mos6502_LDA_zeropage_x;
Mos6502_instruction Mos6502_LDA_absolute;
Mos6502_instruction Mos6502_LDA_absolute_x;
Mos6502_instruction Mos6502_LDA_absolute_y;
Mos6502_instruction Mos6502_LDA_indirect_x;
Mos6502_instruction Mos6502_LDA_indirect_y;

// LDX - Load value into X register
Mos6502_instruction Mos6502_LDX_immediate;
Mos6502_instruction Mos6502_LDX_zeropage;
Mos6502_instruction Mos6502_LDX_zeropage_y;
Mos6502_instruction Mos6502_LDX_absolute;
Mos6502_instruction Mos6502_LDX_absolute_y;

// LDY - Load value into Y register
Mos6502_instruction Mos6502_LDY_immediate;
Mos6502_instruction Mos6502_LDY_zeropage;
Mos6502_instruction Mos6502_LDY_zeropage_x;
Mos6502_instruction Mos6502_LDY_absolute;
Mos6502_instruction Mos6502_LDY_absolute_x;

// STA - Store accumulator in memory
Mos6502_instruction Mos6502_STA_zeropage;
Mos6502_instruction Mos6502_STA_zeropage_x;
Mos6502_instruction Mos6502_STA_zeropage_y;
Mos6502_instruction Mos6502_STA_absolute;
Mos6502_instruction Mos6502_STA_absolute_x;
Mos6502_instruction Mos6502_STA_indirect_x;
Mos6502_instruction Mos6502_STA_indirect_y;

// STX - Store X register in memory
Mos6502_instruction Mos6502_STX_zeropage;
Mos6502_instruction Mos6502_STX_zerpage_y;
Mos6502_instruction Mos6502_STX_absolute;

// STY - Store Y register in memory
Mos6502_instruction Mos6502_STY_zeropage;
Mos6502_instruction Mos6502_STY_zeropage_x;
Mos6502_instruction Mos6502_STY_absolute;

// TAX - Transfer accumulator to X register
Mos6502_instruction Mos6502_TAX_implied;

// TAY - Transfer accumulator to Y register
Mos6502_instruction Mos6502_TAY;

// TSX - Transfer stack pointer to X register
Mos6502_instruction Mos6502_TSX;

// TXA - Transfer X register to accumulator
Mos6502_instruction Mos6502_TXA;

// TXS - Transfer X register to stack pointer
Mos6502_instruction Mos6502_TXS;

// TYA - Transfer Y register to acumulator
Mos6502_instruction Mos6502_TYA;

#endif // INSTRUCTIONS_TRANSFER_H
