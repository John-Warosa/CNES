#include "test_address_modes.h"
#include "bus/bus.h"
#include "cpu/instructions/instructions_address_modes.h"
#include "cpu/mos6502.h"
#include "cpu/mos6502_types.h"
#include "test_utils.h"
#include <string.h>

//===============================================================================
// Helper functions to test decoding
//===============================================================================

static void test_zeropage(Mos6502 *cpu, uint16_t PC, uint8_t byte,
                          uint16_t expected);
static void test_zeropage_x(Mos6502 *cpu, uint16_t PC, uint8_t byte,
                            uint8_t regX, uint16_t expected);
static void test_zeropage_y(Mos6502 *cpu, uint16_t PC, uint8_t byte,
                            uint8_t regY, uint16_t expected);

//===============================================================================
// Zeropage decoding test
//===============================================================================

void test_decode_zeropage(Mos6502 *cpu) {
  struct {
    uint16_t PC;
    uint8_t byte;
    uint16_t expected;
  } tests[] = {
      {0x0000, 0x00, 0x00}, {0x0001, 0x0f, 0x000f}, {0x0002, 0xf0, 0x00f0},
      {0x0003, 0xff, 0xff}, {0x0004, 0xaa, 0x00aa}, {0x0005, 0xb5, 0x00b5},
      {0x0006, 0xd2, 0xd2}, {0x0007, 0x69, 0x0069},
  };

  for (size_t i = 0; i < NUM_ELEMS(tests); ++i) {
    test_zeropage(cpu, tests[i].PC, tests[i].byte, tests[i].expected);
  }

  printf("%s decode_zeropage\n", passText);
}

static void test_zeropage(Mos6502 *cpu, uint16_t PC, uint8_t byte,
                          uint16_t expected) {
  cpu->PC = PC;
  cpu->bus->data[PC] = byte;

  Mos6502_DecodedAddress decoded = Mos6502_decode_zeropage(cpu);

  assert(decoded.address == expected);
  assert(decoded.extraCycles == 0);
  assert(decoded.bytesRead == 1);
}

//===============================================================================
// Zeropage,X decoding test
//===============================================================================

void test_decode_zeropage_x(Mos6502 *cpu) {
  struct {
    uint16_t PC;
    uint8_t byte;
    uint8_t regX;
    uint16_t expected;
  } tests[] = {
      // No wraparound
      {0x0000, 0x00, 0x00, 0x0000},
      {0x0001, 0x0f, 0x00, 0x000f},
      {0x0002, 0xf0, 0x00, 0x00f0},
      {0x0003, 0xff, 0x00, 0x00ff},
      // wraparound
      {0x0000, 0x40, 0xf0, 0x0030},
      {0x0001, 0x80, 0xf0, 0x0070},
      {0x0002, 0xb0, 0xf0, 0x00a0},
      {0x0003, 0xff, 0xf0, 0x00ef},
  };

  for (size_t i = 0; i < NUM_ELEMS(tests); ++i) {
    test_zeropage_x(cpu, tests[i].PC, tests[i].byte, tests[i].regX,
                    tests[i].expected);
  }

  printf("%s decode_zeropage_x\n", passText);
}

static void test_zeropage_x(Mos6502 *cpu, uint16_t PC, uint8_t byte,
                            uint8_t regX, uint16_t expected) {
  cpu->PC = PC;
  cpu->bus->data[PC] = byte;
  cpu->regX = regX;

  Mos6502_DecodedAddress decoded = Mos6502_decode_zeropage_x(cpu);

  assert(decoded.address == expected);
  assert(decoded.extraCycles == 0);
  assert(decoded.bytesRead == 1);
}

//===============================================================================
// Zeropage,Y decoding test
//===============================================================================

void test_decode_zeropage_y(Mos6502 *cpu) {
  struct {
    uint16_t PC;
    uint8_t byte;
    uint8_t regY;
    uint16_t expected;
  } tests[] = {
      // No wraparound
      {0x0000, 0x00, 0x00, 0x0000},
      {0x0001, 0x0f, 0x00, 0x000f},
      {0x0002, 0xf0, 0x00, 0x00f0},
      {0x0003, 0xff, 0x00, 0x00ff},
      // wraparound
      {0x0000, 0x40, 0xf0, 0x0030},
      {0x0001, 0x80, 0xf0, 0x0070},
      {0x0002, 0xb0, 0xf0, 0x00a0},
      {0x0003, 0xff, 0xf0, 0x00ef},
  };

  for (size_t i = 0; i < NUM_ELEMS(tests); ++i) {
    test_zeropage_y(cpu, tests[i].PC, tests[i].byte, tests[i].regY,
                    tests[i].expected);
  }

  printf("%s decode_zeropage_y\n", passText);
}

static void test_zeropage_y(Mos6502 *cpu, uint16_t PC, uint8_t byte,
                            uint8_t regY, uint16_t expected) {
  cpu->PC = PC;
  cpu->bus->data[PC] = byte;
  cpu->regY = regY;

  Mos6502_DecodedAddress decoded = Mos6502_decode_zeropage_y(cpu);

  assert(decoded.address == expected);
  assert(decoded.extraCycles == 0);
  assert(decoded.bytesRead == 1);
}

void test_address_modes(Mos6502 cpu) {

  puts("Testing address mode decoding...");

  test_decode_zeropage(&cpu);
  test_decode_zeropage_x(&cpu);
  test_decode_zeropage_y(&cpu);

  putchar('\n');
}
