//
// Created by indrek on 7.05.2017.
//

#include "IconMem.h"
#include <EEPROM.h>



IconStorageData IconMem::readIconData(uint16_t memIndex) {
  if (memIndex >= MEM_COUNT) memIndex = MEM_COUNT - 1;

  IconStorageData data;
  IconStorageData * addr = getMemAddress(memIndex);
  readMemBytes(addr, sizeof(IconStorageData), &data);
  return data;
}


void IconMem::writeIconData(uint16_t memIndex, IconStorageData & data) {
  if (memIndex >= MEM_COUNT) memIndex = MEM_COUNT - 1;

  IconStorageData * addr = getMemAddress(memIndex);
  writeMemBytes(addr, sizeof(IconStorageData), &data);
}


IconStorageData * IconMem::getMemAddress(uint16_t memIndex) {
  return (IconStorageData *)(sizeof(IconStorageData) * memIndex);
}

uint8_t IconMem::readMemByte(void * addr) {
  return EEPROM.read((uint64_t)(addr));
}

void IconMem::readMemBytes(void * addr, uint16_t cnt, void * toAddr) {
  for (uint16_t i=0; i<cnt; i++) {
    ((uint8_t*)toAddr)[i] = readMemByte(&(((uint8_t*)addr)[i]));
  }
}

void IconMem::writeMemByte(void * addr, uint8_t byte) {
  EEPROM.write((uint64_t)(addr), byte);
}

void IconMem::writeMemBytes(void * addr, uint16_t cnt, void * fromAddr) {
  for (uint16_t i=0; i<cnt; i++) {
    writeMemByte(&(((uint8_t*)addr)[i]), ((uint8_t*)fromAddr)[i]);
  }
}





