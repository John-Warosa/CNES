#include "cpu/mos6502.h"

void Mos6502_connect(Mos6502 *cpu, Bus *bus) { cpu->bus = bus; }

void Mos6502_power_on(Mos6502 *cpu) { (void)cpu; }

void Mos6502_reset(Mos6502 *cpu);
