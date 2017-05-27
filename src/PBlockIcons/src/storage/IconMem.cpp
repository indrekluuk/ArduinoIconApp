//
// Created by indrek on 7.05.2017.
//

#include "IconMem.h"
#include <EEPROM.h>

IconMem::IconMem() {
}


uint8_t IconMem::getCurrentStructureVersion() {
  return readMemByte(&(structure->header.dataStructureVersion));
}

void IconMem::saveCurrentStructureVersion() {
  writeMemByte(&(structure->header.dataStructureVersion), STRUCTURE_VERSION);
}



IconStorageData IconMem::readIconData(uint16_t iconIndex, IconStorageData & data) {
  if (iconIndex >= ICON_COUNT) iconIndex = ICON_COUNT - 1;
  readMemBytes(&(structure->data[iconIndex]), sizeof(IconStorageData), &data);
  return data;
}


void IconMem::writeIconData(uint16_t iconIndex, IconStorageData & data) {
  if (iconIndex >= ICON_COUNT) iconIndex = ICON_COUNT - 1;
  writeMemBytes(&(structure->data[iconIndex]), sizeof(IconStorageData), &data);

  if (getCurrentStructureVersion() != STRUCTURE_VERSION) {
    saveCurrentStructureVersion();
  }
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





