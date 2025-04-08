#ifndef INSTRUCTIONS_BRANCH_H
#define INSTRUCTIONS_BRANCH_H

#include "instructions_type.h"

// BCC - Branch on carry clear
Mos6502_instruction Mos6502_BCC_relative;

// BCS - Branch on carry set
Mos6502_instruction Mos6502_BCC_relative;

// BEQ - Branch on equal (zero flag set)
Mos6502_instruction Mos6502_BCC_relative;

// BMI - Branch on minus (negative flag set)
Mos6502_instruction Mos6502_BCC_relative;

// BNE - Branch on not equal (zero flag clear)
Mos6502_instruction Mos6502_BCC_relative;

// BPL - Branch on plus (zero flag clear)
Mos6502_instruction Mos6502_BCC_relative;

// BVC - Branch on overflow clear
Mos6502_instruction Mos6502_BCC_relative;

// BVS - Branch on overflow set
Mos6502_instruction Mos6502_BCC_relative;

#endif // INSTRUCTIONS_BRANCH_H
