//
// Created by indrek on 7.05.2017.
//

#include "IconMem.h"



uint8_t IconMem::getSlotNumber(uint16_t memIndex) {
  IconStorageData * mem = getMemAddress(memIndex);
  return readMemByte(&mem->slotIndex);
}

void IconMem::setSlotNumber(uint16_t memIndex, uint8_t slotNumber) {
  IconStorageData * mem = getMemAddress(memIndex);
  writeMemByte(&mem->slotIndex, slotNumber);
}

IconBufferMem IconMem::readIconData(uint16_t memIndex) {
  IconBufferMem icon;
  IconStorageData * mem = getMemAddress(memIndex);
  readMemBytes(&mem->icon, sizeof(mem->icon), &icon);
  return icon;
}

void IconMem::writeIconData(uint16_t memIndex, IconBufferMem & icon) {
  IconStorageData * mem = getMemAddress(memIndex);
  writeMemBytes(&mem->icon, sizeof(mem->icon), &icon);
}


IconStorageData * IconMem::getMemAddress(uint16_t memIndex) {
  return (IconStorageData *)(sizeof(IconStorageData) * memIndex);
}

uint8_t IconMem::readMemByte(void * addr) {
  return EEPROM.read((int)(addr));
}

void IconMem::readMemBytes(void * addr, uint16_t cnt, void * toAddr) {
  for (uint16_t i=0; i<cnt; i++) {
    ((uint8_t*)toAddr)[i] = readMemByte(&(((uint8_t*)addr)[i]));
  }
}

void IconMem::writeMemByte(void * addr, uint8_t byte) {
  EEPROM.write((int)(addr), byte);
}

void IconMem::writeMemBytes(void * addr, uint16_t cnt, void * fromAddr) {
  for (uint16_t i=0; i<cnt; i++) {
    writeMemByte(&(((uint8_t*)addr)[i]), ((uint8_t*)fromAddr)[i]);
  }
}





