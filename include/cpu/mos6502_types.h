#ifndef MOS6502_TYPES_H
#define MOS6502_TYPES_H

typedef struct Mos6502 Mos6502;

typedef enum Mos6502_PushType Mos6502_PushType;

typedef void(Mos6502_instruction)(Mos6502 *cpu);

#endif // MOS6502_TYPES_H
