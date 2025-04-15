#include "bus/bus.h"
#include "cpu/mos6502.h"
#include "test_address_modes.h"
#include "test_flags.h"
#include <stdlib.h>
#include <time.h>

#include <assert.h>
#include <stdio.h>
int main() {
  Bus bus = {0};
  Mos6502 cpu = {.bus = &bus};

  srand(time(NULL));

  test_flags(cpu);
  test_address_modes(cpu);
}
