#include "cpu/instructions/optable.h"
#include "cpu/instructions/instructions_increment_decrement.h"

Mos6502_instruction *const optable[256] = {
    // Increment / Decrement
    [0xc6] = Mos6502_DEC_zeropage, [0xd6] = Mos6502_DEC_zeropage_x,
    [0xce] = Mos6502_DEC_absolute, [0xde] = Mos6502_DEC_absolute_x,

    [0xca] = Mos6502_DEX_implied,

    [0x88] = Mos6502_DEY_implied,

    [0xe6] = Mos6502_INC_zeropage, [0xf6] = Mos6502_INC_zeropage_x,
    [0xee] = Mos6502_INC_absolute, [0xfe] = Mos6502_INC_absolute_x,

    [0xe8] = Mos6502_INX_implied,

    [0xc8] = Mos6502_INY_implied,

    // TODO: next section
};
