#ifndef INSTRUCTIONS_ARITHMETIC_H
#define INSTRUCTIONS_ARITHMETIC_H

#include "instructions_type.h"

// ADC - Add to accumulator with carry
Mos6502_instruction Mos6502_ADC_immediate;
Mos6502_instruction Mos6502_ADC_zeropage;
Mos6502_instruction Mos6502_ADC_zeropage_x;
Mos6502_instruction Mos6502_ADC_absolute;
Mos6502_instruction Mos6502_ADC_absolute_x;
Mos6502_instruction Mos6502_ADC_absolute_y;
Mos6502_instruction Mos6502_ADC_indirect_x;
Mos6502_instruction Mos6502_ADC_indirect_y;

// SEC - Subtract from accumulator with carry
Mos6502_instruction Mos6502_SBC_immediate;
Mos6502_instruction Mos6502_SBC_zeropage;
Mos6502_instruction Mos6502_SBC_zeropage_x;
Mos6502_instruction Mos6502_SBC_absolute;
Mos6502_instruction Mos6502_SBC_absolute_x;
Mos6502_instruction Mos6502_SBC_absolute_y;
Mos6502_instruction Mos6502_SBC_indirect_x;
Mos6502_instruction Mos6502_SBC_indirect_y;

#endif // INSTRUCTIONS_ARITHMETIC_H
