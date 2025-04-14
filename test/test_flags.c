#include "test_flags.h"
#include "cpu/mos6502.h"
#include "cpu/mos6502_flags.h"
#include "cpu/mos6502_types.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ELEMS(arr) (sizeof(arr) / sizeof(arr[0]))

static const uint8_t testBytes[] = {0x00, 0xff, 0xf0};

void test_set_negative_flag(Mos6502 *cpu) {
  for (size_t i = 0; i < NUM_ELEMS(testBytes); ++i) {
    cpu->flags = 0;
    Mos6502_set_negative_flag(cpu, testBytes[i]);
    assert((cpu->flags & NEGATIVE) == (testBytes[i] & NEGATIVE));
  }

  for (int i = 0; i < 10; ++i) {
    uint8_t testByteRand = rand();

    cpu->flags = 0;
    Mos6502_set_negative_flag(cpu, testByteRand);
    assert((cpu->flags & NEGATIVE) == (testByteRand & NEGATIVE));
  }

  puts("[PASS] set_negative_flag");
}

void test_set_zero_flag(Mos6502 *cpu) {
  for (size_t i = 0; i < NUM_ELEMS(testBytes); ++i) {
    cpu->flags = 0;
    Mos6502_set_zero_flag(cpu, testBytes[i]);
    assert((cpu->flags & ZERO) == (testBytes[i] == 0 ? ZERO : 0));
  }

  for (int i = 0; i < 10; ++i) {
    uint8_t testByteRand = rand();

    cpu->flags = 0;
    Mos6502_set_zero_flag(cpu, testByteRand);
    assert((cpu->flags & ZERO) == (testByteRand == 0 ? ZERO : 0));
  }

  puts("[PASS] set_zero_flag");
}

void test_set_negative_zero_flag(Mos6502 *cpu) {
  for (size_t i = 0; i < NUM_ELEMS(testBytes); ++i) {
    cpu->flags = 0;
    Mos6502_set_negative_zero_flag(cpu, testBytes[i]);
    assert((cpu->flags & ZERO) == (testBytes[i] == 0 ? ZERO : 0));
    assert((cpu->flags & NEGATIVE) == (testBytes[i] & NEGATIVE));
  }

  for (int i = 0; i < 10; ++i) {
    uint8_t testByteRand = rand();

    cpu->flags = 0;
    Mos6502_set_negative_zero_flag(cpu, testByteRand);
    assert((cpu->flags & ZERO) == (testByteRand == 0 ? ZERO : 0));
    assert((cpu->flags & NEGATIVE) == (testByteRand & NEGATIVE));
  }

  puts("[PASS] set_negative_zero_flag");
}

void test_get_status(Mos6502 *cpu) {
  uint8_t status;

  for (size_t i = 0; i < NUM_ELEMS(testBytes); ++i) {
    cpu->flags = testBytes[i];

    status = Mos6502_get_status(cpu, MOS6502_PHP);
    assert(status == (cpu->flags | UNUSED | BREAK));

    status = Mos6502_get_status(cpu, MOS6502_BRK);
    assert(status == (cpu->flags | UNUSED | BREAK));

    status = Mos6502_get_status(cpu, MOS6502_IRQ);
    assert(status == ((cpu->flags | UNUSED) & ~BREAK));

    status = Mos6502_get_status(cpu, MOS6502_NMI);
    assert(status == ((cpu->flags | UNUSED) & ~BREAK));
  }

  puts("[PASS] get_status");
}

void test_update_status(Mos6502 *cpu) {
  for (size_t i = 0; i < NUM_ELEMS(testBytes); ++i) {
    cpu->flags = 0;
    Mos6502_update_status(cpu, testBytes[i]);
    assert(cpu->flags == ((testBytes[i]) & ~(UNUSED | BREAK)));
  }

  for (size_t i = 0; i < 10; ++i) {
    uint8_t testByteRand = rand();

    cpu->flags = 0;
    Mos6502_update_status(cpu, testByteRand);
    assert(cpu->flags == ((testByteRand) & ~(UNUSED | BREAK)));
  }

  puts("[PASS] update_status");
}

void test_flags(Mos6502 *cpu) {
  srand(time(NULL));
  *cpu = (Mos6502){0};

  test_set_negative_flag(cpu);
  test_set_zero_flag(cpu);
  test_set_negative_zero_flag(cpu);
  test_get_status(cpu);
  test_update_status(cpu);
}
