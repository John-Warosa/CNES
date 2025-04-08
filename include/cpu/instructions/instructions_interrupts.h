#ifndef INSTRUCTIONS_INTERRUPTS_H
#define INSTRUCTIONS_INTERRUPTS_H

#include "instructions_type.h"

// BRK - Software interrupt
Mos6502_instruction Mos6502_BRK_implied;

// RTI - Return from interrupt
Mos6502_instruction Mos6502_RTS_implied;

#endif // INSTRUCTIONS_INTERRUPTS_H
