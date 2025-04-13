#ifndef MOS6502
#define MOS6502

#include "bus/bus_types.h"
#include "mos6502_types.h"
#include <stddef.h>
#include <stdint.h>

struct Mos6502 {
  uint8_t regX;
  uint8_t regY;
  uint8_t Acc;

  uint8_t SP;
  uint16_t PC;

  uint8_t flags;
  uint8_t opcode;

  size_t cycles;

  Bus *bus;
};

void Mos6502_connect(Mos6502 *cpu, Bus *bus);
void Mos6502_power_on(Mos6502 *cpu);
void Mos6502_reset(Mos6502 *cpu);

#endif // MOS6502
