#include "bus/bus.h"

uint8_t Bus_read(Bus *bus, uint16_t address) { return bus->data[address]; }

void Bus_write(Bus *bus, uint16_t address, uint8_t byte) {
  bus->data[address] = byte;
}
