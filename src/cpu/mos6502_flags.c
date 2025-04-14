#include "cpu/mos6502_flags.h"
#include "cpu/mos6502.h"
#include <stdbool.h>

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
  uint8_t status = (cpu->flags & ~BREAK) | UNUSED;
  if (pushType == MOS6502_PHP || pushType == MOS6502_BRK) {
    status |= BREAK;
  }

  return status;
}

void Mos6502_update_status(Mos6502 *cpu, uint8_t status) {
  cpu->flags = status & ~(BREAK | UNUSED);
}
