#ifndef BUS_H
#define BUS_H

#include <stdint.h>

typedef struct Memory Memory;

typedef struct Bus {
  // Memory *Memory;
  uint8_t data[0xffff + 1];
} Bus;

uint8_t Bus_read(Bus *bus, uint16_t address);
void Bus_write(Bus *bus, uint16_t address, uint8_t byte);

#endif // BUS_H
