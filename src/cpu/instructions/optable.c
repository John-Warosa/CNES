#include "cpu/instructions/optable.h"
#include "cpu/instructions/instructions_type.h"

Mos6502_instruction *const optable[256] = {
    [0x00 ... 0x50] = 0,
};
