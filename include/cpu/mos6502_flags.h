#ifndef MOS6502_FLAGS_H
#define MOS6502_FLAGS_H

/*==============================================================================

  6502 Flag register

  The following interface defines functionality to interact with the 6502
  status register.

  The status register is comprised of 8 flags as follows:

    - Bit 0: carry flag
    - Bit 1: zero flag
    - Bit 2: interrupt disable flag
    - Bit 3: decimal mode flag        (ignored on NES)
    - Bit 4: break flag
    - Bit 5: unused flag              (always set to 1)
    - Bit 6: overflow flag
    - Bit 7: negative flag

  Note that the unused flag and the break flag do not actually exist
  and get only set when pushed to the stack
  The unused flag always gets set to 1 while the break flag gets set
  to 1 if the push happened from BRK or PHP instead of an interrupt

  Use the set_*_flag function to set a flag to true or false
  Note that some flags require logic while others can be set directly

  Use the get_status to get the byte representation to push onto the stack
  Use the update_status to update the status register from a byte

==============================================================================*/

#include "cpu/mos6502_types.h"
#include <stdbool.h>
#include <stdint.h>

//==============================================================================
// Flags set without condition
//==============================================================================

void Mos6502_set_interrupt_flag(Mos6502 *cpu, bool value);
void Mos6502_set_decimal_flag(Mos6502 *cpu, bool value);

//==============================================================================
// Flags derived from logic
//==============================================================================

void Mos6502_set_negative_flag(Mos6502 *cpu, uint8_t byte); // Set if bit 7 is 1
void Mos6502_set_zero_flag(Mos6502 *cpu, uint8_t byte);     // Set if byte is 0

/*
 * Sets both the negative and zero flag based on result
 * Used in instructions like INC, DEC, ...
 */
void Mos6502_set_negative_zero_flag(Mos6502 *cpu, uint8_t byte);

//==============================================================================
// Stack functionality
//==============================================================================

enum Mos6502_PushType {
  MOS6502_PHP,
  MOS6502_BRK,
  MOS6502_IRQ,
  MOS6502_NMI,
};

/*
 * Sets the unused bit to 1 and the break bit to 0 or 1
 * Note that this function leaves the status register untouched and returns a
 * copy of the it with the appropriate flags set
 */
uint8_t Mos6502_get_status(Mos6502 *cpu, Mos6502_PushType pushType);

/*
 * Clears the unused and break bit and updates the status register
 * This function is used to update the cpu state after a return
 */
void Mos6502_update_status(Mos6502 *cpu, uint8_t status);

#endif // MOS6502_FLAGS_H
