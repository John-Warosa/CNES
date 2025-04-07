#ifndef MEMORYMAP_H
#define MEMORYMAP_H

#include <stdint.h>

enum Mmap_MemoryMap {
  MMAP_RAM_START = 0x0000,
  MMAP_PPU_REG_START = 0x2000,
  MMAP_APU_IO_START = 0x4000,
  MMAP_DISABLED_START = 0x4018,
  MMAP_UNMAPPED_START = 0x4020,
};

enum Mmap_MemorySize {
  MMAP_RAM_SIZE = 0x0800,
  MMAP_PPU_REG_SIZE = 0x0008,
  MMAP_APU_IO_SIZE = 0x0018,
  MMAP_DISABLED_SIZE = 0x0008,
  MMAP_UNMAPPED_SIZE = 0xbfe0,
};

typedef enum Mmap_MemoryRegion {
  MMAP_RAM,
  MMAP_PPU_REG,
  MMAP_APU_IO,
  MMAP_DISABLED,
  MMAP_UNMAPPED,
} Mmap_MemoryRegion;

Mmap_MemoryRegion Mmap_get_memory_region(uint16_t address);
uint16_t Mmap_get_region_index(uint16_t address);

#endif // MEMORYMAP_H
