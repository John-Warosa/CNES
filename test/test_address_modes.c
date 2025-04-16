#include "test_address_modes.h"
#include "bus/bus.h"
#include "cpu/instructions/instructions_address_modes.h"
#include "cpu/mos6502.h"
#include "cpu/mos6502_types.h"
#include "test_utils.h"
#include <stdbool.h>
#include <string.h>

//===============================================================================
// Test structs and data
//===============================================================================

typedef struct {
  uint16_t PC;
  uint8_t byte1;
  uint8_t byte2;
  uint16_t expected;
} TestAbsolute;

// NOTE: 0xffff should wrap around back to 0x0000
static const TestAbsolute testsAbsolute[] = {
    {0x0000, 0x00, 0x00, 0x0000}, {0x1000, 0x00, 0xff, 0xff00},
    {0x00ff, 0xff, 0x00, 0x00ff}, {0xffff, 0xff, 0xff, 0xffff},
    {0xaaaa, 0x43, 0xd1, 0xd143}, {0x1284, 0x01, 0xfe, 0xfe01},
};

typedef struct {
  uint16_t PC;
  uint8_t byte1;
  uint8_t byte2;
  uint8_t reg;
  bool overflow;
  uint16_t expected;
} TestAbsoluteXY;

static const TestAbsoluteXY testsAbsoluteXY[] = {
    // No page crossing
    {0x0000, 0x00, 0xff, 0x10, false, 0xff10},
    {0xfd37, 0x8d, 0x34, 0x01, false, 0x348e},
    {0xffff, 0x54, 0x12, 0x50, false, 0x12a4},
    // Page crossing
    {0x0000, 0xd3, 0xfd, 0x87, true, 0xfe5a},
    {0xfd37, 0x8d, 0x34, 0xc0, true, 0x354d},
    {0xffff, 0xfa, 0xff, 0x06, true, 0x0000},
};

typedef struct {
  uint16_t PC;
  uint8_t offset;
  bool overflow;
  uint16_t expected;
} TestRelative;

// NOTE: PC gets increased after reading a Byte
static const TestRelative testsRelative[] = {
    // No page crossing, positive offset
    {0x0000, 0x00, false, 0x0001},
    {0x0100, 0x7f, false, 0x0180},
    {0x0200, 0x47, false, 0x0248},
    // No page crossing, negative offset
    {0x03fe, 0xff, false, 0x03fe},
    {0x04fe, 0x80, false, 0x047f},
    {0x05fe, 0xb2, false, 0x05b1},
    // Page crossing, positive offset
    {0x10fe, 0x01, true, 0x1100},
    {0x11a7, 0x7f, true, 0x1227},
    {0x12e2, 0x47, true, 0x132a},
    // Page crossing, negative offset
    {0x12ff, 0xff, true, 0x12ff},
    {0x1465, 0x80, true, 0x13e6},
    {0x1523, 0xb2, true, 0x14d6},
    // Special edge case
    {0xffff, 0xff, true, 0xffff},
};

typedef struct {
  uint16_t PC;
  uint8_t byte;
  uint16_t expected;
} TestZeropage;

TestZeropage testsZeropage[] = {
    {0x0000, 0x00, 0x00}, {0x0001, 0x0f, 0x000f}, {0x0002, 0xf0, 0x00f0},
    {0x0003, 0xff, 0xff}, {0x0004, 0xaa, 0x00aa}, {0x0005, 0xb5, 0x00b5},
    {0x0006, 0xd2, 0xd2}, {0x0007, 0x69, 0x0069},
};

typedef struct {
  uint16_t PC;
  uint8_t byte;
  uint8_t reg;
  uint16_t expected;
} TestZeropageXY;

static const TestZeropageXY testsZeropageXY[] = {
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

//===============================================================================
// Helper functions to test decoding
//===============================================================================

static void test_absolute(Mos6502 *cpu, TestAbsolute test);
static void test_absolute_x(Mos6502 *cpu, TestAbsoluteXY test);
static void test_absolute_y(Mos6502 *cpu, TestAbsoluteXY test);
static void test_relative(Mos6502 *cpu, TestRelative test);
static void test_zeropage(Mos6502 *cpu, TestZeropage test);
static void test_zeropage_x(Mos6502 *cpu, TestZeropageXY test);
static void test_zeropage_y(Mos6502 *cpu, TestZeropageXY test);

//===============================================================================
// Absolute decoding test
//===============================================================================

void test_decode_absolute(Mos6502 *cpu) {

  for (size_t i = 0; i < NUM_ELEMS(testsAbsolute); ++i) {
    test_absolute(cpu, testsAbsolute[i]);
  }

  printf("%s decode_absolute\n", passText);
}

static void test_absolute(Mos6502 *cpu, TestAbsolute test) {
  cpu->PC = test.PC;
  cpu->bus->data[test.PC] = test.byte1;
  cpu->bus->data[(uint16_t)(test.PC + 1)] = test.byte2;

  Mos6502_DecodedAddress decoded = Mos6502_decode_absolute(cpu);

  assert(decoded.address == test.expected);
  assert(decoded.extraCycles == 0);
  assert(decoded.bytesRead == 2);
}

//===============================================================================
// Absolute,X decoding test
//===============================================================================

void test_decode_absolute_x(Mos6502 *cpu) {
  for (size_t i = 0; i < NUM_ELEMS(testsAbsoluteXY); ++i) {
    test_absolute_x(cpu, testsAbsoluteXY[i]);
  }

  printf("%s decode_absolute_x\n", passText);
}

static void test_absolute_x(Mos6502 *cpu, TestAbsoluteXY test) {
  cpu->PC = test.PC;
  cpu->regX = test.reg;
  cpu->bus->data[test.PC] = test.byte1;
  cpu->bus->data[(uint16_t)(test.PC + 1)] = test.byte2;

  Mos6502_DecodedAddress decoded = Mos6502_decode_absolute_x(cpu);

  assert(decoded.address == test.expected);
  assert(decoded.extraCycles == test.overflow);
  assert(decoded.bytesRead == 2);
}

//===============================================================================
// Absolute,X decoding test
//===============================================================================

void test_decode_absolute_y(Mos6502 *cpu) {
  for (size_t i = 0; i < NUM_ELEMS(testsAbsoluteXY); ++i) {
    test_absolute_y(cpu, testsAbsoluteXY[i]);
  }

  printf("%s decode_absolute_y\n", passText);
}

static void test_absolute_y(Mos6502 *cpu, TestAbsoluteXY test) {
  cpu->PC = test.PC;
  cpu->regY = test.reg;
  cpu->bus->data[test.PC] = test.byte1;
  cpu->bus->data[(uint16_t)(test.PC + 1)] = test.byte2;

  Mos6502_DecodedAddress decoded = Mos6502_decode_absolute_y(cpu);

  assert(decoded.address == test.expected);
  assert(decoded.extraCycles == test.overflow);
  assert(decoded.bytesRead == 2);
}

//===============================================================================
// Relative decoding test
//===============================================================================

void test_decode_relative(Mos6502 *cpu) {
  for (size_t i = 0; i < NUM_ELEMS(testsRelative); ++i) {
    test_relative(cpu, testsRelative[i]);
  }

  printf("%s decode_relative\n", passText);
}

static void test_relative(Mos6502 *cpu, TestRelative test) {
  cpu->PC = test.PC;
  cpu->bus->data[test.PC] = test.offset;

  Mos6502_DecodedAddress decoded = Mos6502_decode_relative(cpu);

  assert(decoded.address == test.expected);
  assert(decoded.extraCycles == test.overflow);
  assert(decoded.bytesRead == 1);
}

//===============================================================================
// Zeropage decoding test
//===============================================================================

void test_decode_zeropage(Mos6502 *cpu) {
  for (size_t i = 0; i < NUM_ELEMS(testsZeropage); ++i) {
    test_zeropage(cpu, testsZeropage[i]);
  }

  printf("%s decode_zeropage\n", passText);
}

static void test_zeropage(Mos6502 *cpu, TestZeropage test) {
  cpu->PC = test.PC;
  cpu->bus->data[test.PC] = test.byte;

  Mos6502_DecodedAddress decoded = Mos6502_decode_zeropage(cpu);

  assert(decoded.address == test.expected);
  assert(decoded.extraCycles == 0);
  assert(decoded.bytesRead == 1);
}

//===============================================================================
// Zeropage,X decoding test
//===============================================================================

void test_decode_zeropage_x(Mos6502 *cpu) {
  for (size_t i = 0; i < NUM_ELEMS(testsZeropageXY); ++i) {
    test_zeropage_x(cpu, testsZeropageXY[i]);
  }

  printf("%s decode_zeropage_x\n", passText);
}

static void test_zeropage_x(Mos6502 *cpu, TestZeropageXY test) {
  cpu->PC = test.PC;
  cpu->bus->data[test.PC] = test.byte;
  cpu->regX = test.reg;

  Mos6502_DecodedAddress decoded = Mos6502_decode_zeropage_x(cpu);

  assert(decoded.address == test.expected);
  assert(decoded.extraCycles == 0);
  assert(decoded.bytesRead == 1);
}

//===============================================================================
// Zeropage,Y decoding test
//===============================================================================

void test_decode_zeropage_y(Mos6502 *cpu) {
  for (size_t i = 0; i < NUM_ELEMS(testsZeropageXY); ++i) {
    test_zeropage_y(cpu, testsZeropageXY[i]);
  }

  printf("%s decode_zeropage_y\n", passText);
}

static void test_zeropage_y(Mos6502 *cpu, TestZeropageXY test) {
  cpu->PC = test.PC;
  cpu->bus->data[test.PC] = test.byte;
  cpu->regY = test.reg;

  Mos6502_DecodedAddress decoded = Mos6502_decode_zeropage_y(cpu);

  assert(decoded.address == test.expected);
  assert(decoded.extraCycles == 0);
  assert(decoded.bytesRead == 1);
}

void test_address_modes(Mos6502 cpu) {

  puts("Testing address mode decoding...");

  test_decode_absolute(&cpu);
  test_decode_absolute_x(&cpu);
  test_decode_absolute_y(&cpu);
  test_decode_relative(&cpu);
  test_decode_zeropage(&cpu);
  test_decode_zeropage_x(&cpu);
  test_decode_zeropage_y(&cpu);

  putchar('\n');
}
