#include "cpu/mos6502.h"
#include "test_flags.h"

int main() {
  struct Mos6502 cpu = {0};

  test_flags(&cpu);
}
