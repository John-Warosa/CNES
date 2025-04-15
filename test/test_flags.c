#include "test_flags.h"
#include "cpu/mos6502.h"
#include "cpu/mos6502_flags.h"
#include "test_utils.h"

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

  printf("%s set_negative_flag\n", passText);
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

  printf("%s set_zero_flag\n", passText);
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

  printf("%s set_negative_zero_flag\n", passText);
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

  printf("%s get_status\n", passText);
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

  printf("%s update_status\n", passText);
}

void test_flags(Mos6502 cpu) {
  cpu = (Mos6502){0};

  puts("Testing Flag behaviour...");

  test_set_negative_flag(&cpu);
  test_set_zero_flag(&cpu);
  test_set_negative_zero_flag(&cpu);
  test_get_status(&cpu);
  test_update_status(&cpu);

  putchar('\n');
}
