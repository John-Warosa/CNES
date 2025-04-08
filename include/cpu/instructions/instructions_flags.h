#ifndef INSTRUCTIONS_FLAGS_H
#define INSTRUCTIONS_FLAGS_H

#include "instructions_type.h"

// CLC - Clear carry flag
Mos6502_instruction Mos6502_CLC_implied;

// CLD - Clear decimal flag
Mos6502_instruction Mos6502_CLD_implied;

// CLI - Clear interrupt disable flag
Mos6502_instruction Mos6502_CLI_implied;

// CLV - Clear overflow flag
Mos6502_instruction Mos6502_CLV_implied;

// SEC - Set carry flag
Mos6502_instruction Mos6502_SEC_implied;

// SED - Set decimal flag
Mos6502_instruction Mos6502_SED_implied;

// SEI - Set interrupt disable flag
Mos6502_instruction Mos6502_SEI_implied;

#endif // INSTRUCTIONS_FLAGS_H
