#ifndef INSTRUCTIONS_JUMPS_H
#define INSTRUCTIONS_JUMPS_H

#include "cpu/mos6502_types.h"

// JMP - Jump to given address
Mos6502_instruction Mos6502_JMP_absolute;
Mos6502_instruction Mos6502_JMP_indirect;

// JSR - Jump to subroutine
Mos6502_instruction Mos6502_JSR_absolute;

// RTS - Return from subroutine
Mos6502_instruction Mos6502_RTS_implied;

#endif // INSTRUCTIONS_JUMPS_H
