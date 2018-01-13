//
// Created by indrek on 7.05.2017.
//

#include "IconStorage.h"
#include <EEPROM.h>

IconStorage::IconStorage() {
}


uint8_t IconStorage::getCurrentStructureVersion() {
  return readMemByte(&(structure->header.dataStructureVersion));
}

void IconStorage::saveCurrentStructureVersion() {
  writeMemByte(&(structure->header.dataStructureVersion), STRUCTURE_VERSION);
}



IconStorageData IconStorage::readIconData(uint16_t iconIndex, IconStorageData & data) {
  if (iconIndex >= ICON_COUNT) iconIndex = ICON_COUNT - 1;
  readMemBytes(&(structure->data[iconIndex]), sizeof(IconStorageData), &data);
  return data;
}


void IconStorage::writeIconData(uint16_t iconIndex, IconStorageData & data) {
  if (iconIndex >= ICON_COUNT) iconIndex = ICON_COUNT - 1;
  writeMemBytes(&(structure->data[iconIndex]), sizeof(IconStorageData), &data);

  if (getCurrentStructureVersion() != STRUCTURE_VERSION) {
    saveCurrentStructureVersion();
  }
}


uint8_t IconStorage::readMemByte(void * addr) {
  return EEPROM.read((uint64_t)(addr));
}

void IconStorage::readMemBytes(void * addr, uint16_t cnt, void * toAddr) {
  for (uint16_t i=0; i<cnt; i++) {
    ((uint8_t*)toAddr)[i] = readMemByte(&(((uint8_t*)addr)[i]));
  }
}

void IconStorage::writeMemByte(void * addr, uint8_t byte) {
  EEPROM.write((uint64_t)(addr), byte);
}

void IconStorage::writeMemBytes(void * addr, uint16_t cnt, void * fromAddr) {
  for (uint16_t i=0; i<cnt; i++) {
    writeMemByte(&(((uint8_t*)addr)[i]), ((uint8_t*)fromAddr)[i]);
  }
}





