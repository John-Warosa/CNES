#include "bus/bus.h"
#include "cpu/mos6502.h"

int main(int argc, char **argv) {
  (void)argc;
  (void)argv;
  Bus bus = {0};
  Mos6502 cpu;
  Mos6502_connect(&cpu, &bus);
}
