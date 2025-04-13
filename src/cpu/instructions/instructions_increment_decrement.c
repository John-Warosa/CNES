#include "cpu/instructions/instructions_increment_decrement.h"
#include "bus/bus.h"
#include "cpu/instructions/instructions_address_modes.h"
#include "cpu/mos6502.h"
#include "cpu/mos6502_flags.h"

/*==============================================================================

  NOTE: This file contains Read-Modify-Write (RMW) instructions
  These instructions always reread the final address even if
  no page crossing occurred. They always take a fixed number of cycles

==============================================================================*/

//==============================================================================
// DEC / DEX / DEY
//==============================================================================

void Mos6502_DEC_zeropage(Mos6502 *cpu) {
  Mos6502_DecodedAddress decoded = Mos6502_decode_zeropage(cpu);
  uint8_t byte = Bus_read(cpu->bus, decoded.address);
  uint8_t result = byte - 1;

  Bus_write(cpu->bus, decoded.address, result);
  Mos6502_set_negative_zero_flag(cpu, result);

  cpu->PC += decoded.bytesRead;
  cpu->cycles += 5; // RMW - fixed cycles
}

void Mos6502_DEC_zeropage_x(Mos6502 *cpu) {
  Mos6502_DecodedAddress decoded = Mos6502_decode_zeropage_x(cpu);
  uint8_t byte = Bus_read(cpu->bus, decoded.address);
  uint8_t result = byte - 1;

  Bus_write(cpu->bus, decoded.address, result);
  Mos6502_set_negative_zero_flag(cpu, result);

  cpu->PC += decoded.bytesRead;
  cpu->cycles += 6; // RMW - fixed cycles
}

void Mos6502_DEC_absolute(Mos6502 *cpu) {
  Mos6502_DecodedAddress decoded = Mos6502_decode_absolute(cpu);
  uint8_t byte = Bus_read(cpu->bus, decoded.address);
  uint8_t result = byte - 1;

  Bus_write(cpu->bus, decoded.address, result);
  Mos6502_set_negative_zero_flag(cpu, result);

  cpu->PC += decoded.bytesRead;
  cpu->cycles += 6; // RMW - fixed cycles
}

void Mos6502_DEC_absolute_x(Mos6502 *cpu) {
  Mos6502_DecodedAddress decoded = Mos6502_decode_absolute_x(cpu);
  uint8_t byte = Bus_read(cpu->bus, decoded.address);
  uint8_t result = byte - 1;

  Bus_write(cpu->bus, decoded.address, result);
  Mos6502_set_negative_zero_flag(cpu, result);

  cpu->PC += decoded.bytesRead;
  cpu->cycles += 7; // RMW - fixed cycles
}

void Mos6502_DEX_implied(Mos6502 *cpu) {
  uint8_t byte = cpu->regX;
  uint8_t result = byte - 1;

  cpu->regX = result;
  Mos6502_set_negative_zero_flag(cpu, result);

  cpu->cycles += 2;
}

void Mos6502_DEY_implied(Mos6502 *cpu) {
  uint8_t byte = cpu->regY;
  uint8_t result = byte - 1;

  cpu->regY = result;
  Mos6502_set_negative_zero_flag(cpu, result);

  cpu->cycles += 2;
}

//==============================================================================
// INC / INX / INY
//==============================================================================

void Mos6502_INC_zeropage(Mos6502 *cpu) {
  Mos6502_DecodedAddress decoded = Mos6502_decode_zeropage(cpu);
  uint8_t byte = Bus_read(cpu->bus, decoded.address);
  uint8_t result = byte + 1;

  Bus_write(cpu->bus, decoded.address, result);
  Mos6502_set_negative_zero_flag(cpu, result);

  cpu->PC += decoded.bytesRead;
  cpu->cycles += 5; // RMW - fixed cycles
}

void Mos6502_INC_zeropage_x(Mos6502 *cpu) {
  Mos6502_DecodedAddress decoded = Mos6502_decode_zeropage_x(cpu);
  uint8_t byte = Bus_read(cpu->bus, decoded.address);
  uint8_t result = byte + 1;

  Bus_write(cpu->bus, decoded.address, result);
  Mos6502_set_negative_zero_flag(cpu, result);

  cpu->PC += decoded.bytesRead;
  cpu->cycles += 6; // RMW - fixed cycles
}

void Mos6502_INC_absolute(Mos6502 *cpu) {
  Mos6502_DecodedAddress decoded = Mos6502_decode_absolute(cpu);
  uint8_t byte = Bus_read(cpu->bus, decoded.address);
  uint8_t result = byte + 1;

  Bus_write(cpu->bus, decoded.address, result);
  Mos6502_set_negative_zero_flag(cpu, result);

  cpu->PC += decoded.bytesRead;
  cpu->cycles += 6; // RMW - fixed cycles
}

void Mos6502_INC_absolute_x(Mos6502 *cpu) {
  Mos6502_DecodedAddress decoded = Mos6502_decode_absolute_x(cpu);
  uint8_t byte = Bus_read(cpu->bus, decoded.address);
  uint8_t result = byte + 1;

  Bus_write(cpu->bus, decoded.address, result);
  Mos6502_set_negative_zero_flag(cpu, result);

  cpu->PC += decoded.bytesRead;
  cpu->cycles += 7; // RMW - fixed cycles
}

void Mos6502_INX_implied(Mos6502 *cpu) {
  uint8_t byte = cpu->regX;
  uint8_t result = byte + 1;

  cpu->regX = result;
  Mos6502_set_negative_zero_flag(cpu, result);

  cpu->cycles += 2;
}

void Mos6502_INY_implied(Mos6502 *cpu) {
  uint8_t byte = cpu->regY;
  uint8_t result = byte + 1;

  cpu->regY = result;
  Mos6502_set_negative_zero_flag(cpu, result);

  cpu->cycles += 2;
}
