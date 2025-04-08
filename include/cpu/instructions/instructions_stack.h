#ifndef INSTRUCTIONS_STACK_H
#define INSTRUCTIONS_STACK_H

/*==============================================================================

Stack instructions

The following interface defines instructions used to manipulate
the stack.
The stack is located on page $01, pushing to the stack
decrements the stack pointer, while popping increases it

==============================================================================*/

#include "instructions_type.h"

// PHA - Push accumulator onto stack
Mos6502_instruction Mos6502_PHA_implied;

// PHP - Push procesor flags onto stack
Mos6502_instruction Mos6502_PHP_implied;

// PLA - Pull accumulator from stack
Mos6502_instruction Mos6502_PLA_implied;

// PLA - Pull processor flags from stack
Mos6502_instruction Mos6502_PLP_implied;

#endif // INSTRUCTIONS_STACK_H
