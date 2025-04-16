#include "cpu/instructions/instructions_address_modes.h"
#include "bus/bus.h"
#include "cpu/mos6502.h"

//==============================================================================
// Helper functions
//==============================================================================

static uint16_t address_16_from(const Mos6502 *cpu, uint16_t addr,
                                uint16_t addrNext) {
  uint8_t loByte = Bus_read(cpu->bus, addr);
  uint8_t hiByte = Bus_read(cpu->bus, addrNext);

  return (hiByte << 8) | loByte;
}

static uint16_t address_zeropage_indexed(const Mos6502 *cpu, uint8_t reg) {
  uint8_t pageIndex = Bus_read(cpu->bus, cpu->PC);

  return 0x0000 | (uint8_t)(pageIndex + reg);
}

static uint16_t address_jmp_indirect(const Mos6502 *cpu, uint16_t addrLookup) {
  uint16_t addrLookupNext = (addrLookup & 0xff00) | (uint8_t)(addrLookup + 1);

  return address_16_from(cpu, addrLookup, addrLookupNext);
}

static uint16_t address_zeropage_indirect(const Mos6502 *cpu,
                                          uint8_t addrLookup) {
  uint8_t addrLookupNext = (uint8_t)(addrLookup + 1);

  return address_16_from(cpu, addrLookup, addrLookupNext);
}

static uint8_t page_crossed(uint16_t addr1, uint16_t addr2) {
  return ((addr1 & 0xff00) != (addr2 & 0xff00));
}

//==============================================================================
// Absolute address modes
//==============================================================================

Mos6502_DecodedAddress Mos6502_decode_absolute(const Mos6502 *cpu) {
  uint16_t address = address_16_from(cpu, cpu->PC, cpu->PC + 1);

  return (Mos6502_DecodedAddress){
      .address = address,
      .extraCycles = 0,
      .bytesRead = 2,
  };
}

Mos6502_DecodedAddress Mos6502_decode_absolute_x(const Mos6502 *cpu) {
  uint16_t addrTemp = address_16_from(cpu, cpu->PC, cpu->PC + 1);
  uint16_t addrFinal = addrTemp + cpu->regX;

  return (Mos6502_DecodedAddress){
      .address = addrFinal,
      .extraCycles = page_crossed(addrTemp, addrFinal),
      .bytesRead = 2,
  };
}

Mos6502_DecodedAddress Mos6502_decode_absolute_y(const Mos6502 *cpu) {
  uint16_t addrTemp = address_16_from(cpu, cpu->PC, cpu->PC + 1);
  uint16_t addrFinal = addrTemp + cpu->regY;

  return (Mos6502_DecodedAddress){
      .address = addrFinal,
      .extraCycles = page_crossed(addrTemp, addrFinal),
      .bytesRead = 2,
  };
}

//==============================================================================
// Indirect address modes
//==============================================================================

Mos6502_DecodedAddress Mos6502_decode_indirect(const Mos6502 *cpu) {
  uint16_t addressLookup = address_16_from(cpu, cpu->PC, cpu->PC + 1);
  uint16_t address = address_jmp_indirect(cpu, addressLookup);

  return (Mos6502_DecodedAddress){
      .address = address,
      .extraCycles = 0,
      .bytesRead = 2,
  };
}

Mos6502_DecodedAddress Mos6502_decode_indirect_x(const Mos6502 *cpu) {
  uint8_t zeropageLookup = address_zeropage_indexed(cpu, cpu->regX);
  uint16_t address = address_zeropage_indirect(cpu, zeropageLookup);

  return (Mos6502_DecodedAddress){
      .address = address,
      .extraCycles = 0,
      .bytesRead = 1,
  };
}

Mos6502_DecodedAddress Mos6502_decode_indirect_y(const Mos6502 *cpu) {
  uint8_t pageIndex = Bus_read(cpu->bus, cpu->PC);
  uint16_t addrTemp = address_zeropage_indirect(cpu, pageIndex);
  uint16_t addrFinal = addrTemp + cpu->regY;

  return (Mos6502_DecodedAddress){
      .address = addrFinal,
      .extraCycles = page_crossed(addrTemp, addrFinal),
      .bytesRead = 1,
  };
}

//==============================================================================
// Relative address mode
//==============================================================================

Mos6502_DecodedAddress Mos6502_decode_relative(const Mos6502 *cpu) {
  int8_t offset = (int8_t)Bus_read(cpu->bus, cpu->PC);
  uint16_t addrBase = cpu->PC + 1;
  uint16_t addrFinal = addrBase + offset;

  return (Mos6502_DecodedAddress){
      .address = addrFinal,
      .extraCycles = page_crossed(addrBase, addrFinal),
      .bytesRead = 1,
  };
}

//==============================================================================
// Zeropage address modes
//==============================================================================

Mos6502_DecodedAddress Mos6502_decode_zeropage(const Mos6502 *cpu) {
  uint16_t address = Bus_read(cpu->bus, cpu->PC);

  return (Mos6502_DecodedAddress){
      .address = address,
      .extraCycles = 0,
      .bytesRead = 1,
  };
}

Mos6502_DecodedAddress Mos6502_decode_zeropage_x(const Mos6502 *cpu) {
  uint16_t address = address_zeropage_indexed(cpu, cpu->regX);

  return (Mos6502_DecodedAddress){
      .address = address,
      .extraCycles = 0,
      .bytesRead = 1,
  };
}

Mos6502_DecodedAddress Mos6502_decode_zeropage_y(const Mos6502 *cpu) {
  uint16_t address = address_zeropage_indexed(cpu, cpu->regY);

  return (Mos6502_DecodedAddress){
      .address = address,
      .extraCycles = 0,
      .bytesRead = 1,
  };
}
