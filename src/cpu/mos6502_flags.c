#include "cpu/mos6502_flags.h"
#include "cpu/mos6502.h"
#include <stdbool.h>

enum Mos6502_Flags {
  CARRY = 0b00000001,
  ZERO = 0b00000010,
  INTERRUPT = 0b00000100,
  DECIMAL = 0b00001000,
  BREAK = 0b00010000,
  UNUSED = 0b00100000,
  OVERFLOW = 0b01000000,
  NEGATIVE = 0b10000000,
};

void Mos6502_set_negative_flag(Mos6502 *cpu, uint8_t byte) {
  cpu->flags &= ~NEGATIVE;
  cpu->flags |= (byte & NEGATIVE);
}

void Mos6502_set_zero_flag(Mos6502 *cpu, uint8_t byte) {
  cpu->flags &= ~ZERO;
  cpu->flags |= (byte == 0) ? ZERO : 0;
}

void Mos6502_set_negative_zero_flag(Mos6502 *cpu, uint8_t byte) {
  Mos6502_set_negative_flag(cpu, byte);
  Mos6502_set_zero_flag(cpu, byte);
}

uint8_t Mos6502_get_status(Mos6502 *cpu, Mos6502_PushType pushType) {
  bool interrupt = (pushType == MOS6502_IRQ || pushType == MOS6502_NMI);
  uint8_t status = cpu->flags | UNUSED;
  status |= interrupt ? 0 : BREAK;

  return status;
}

void Mos6502_update_status(Mos6502 *cpu, uint8_t status) {
  cpu->flags = status & ~(BREAK | UNUSED);
}
