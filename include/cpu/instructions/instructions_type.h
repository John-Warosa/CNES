#ifndef INSTRUCTION_TYPE_H
#define INSTRUCTION_TYPE_H

typedef struct Mos6502 Mos6502;

typedef void(Mos6502_instruction)(Mos6502 *cpu);

#endif // INSTRUCTION_TYPE_H
