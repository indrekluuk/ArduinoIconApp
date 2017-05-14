//
// Created by indrek on 7.05.2017.
//

#include "IconStorage.h"


IconStorage::IconStorage() {
  for (uint8_t i=0; i<SLOT_COUNT; i++) {
    initSlot(i);
  }
}



void IconStorage::initSlot(uint8_t slotIndex) {
  slots[slotIndex].storedData.slotIndex = slotIndex;

  for (uint16_t i=0; i<iconMem.MEM_COUNT; i++) {
    if (iconMem.getSlotNumber(i) == slotIndex) {
      if (slots[slotIndex].memIndex < 0) {
        slots[slotIndex].memIndex = i;
        slots[slotIndex].storedData = iconMem.readIconData(i);
      } else {
        iconMem.clearSlotNumber(i);
      }
    }
  }
}



IconStorageData & IconStorage::getStoredIconData(uint8_t slotIndex) {
  return slots[slotIndex].storedData;
}


void IconStorage::saveIcon(uint8_t slotIndex, IconBufferMem & icon) {
  slots[slotIndex].storedData.icon = icon;
  slots[slotIndex].storedData.icon.color = IconColor(Palette::WHITE, Palette::BLACK, Palette::BLACK, false, false);
  saveSlot(slotIndex);
}



void IconStorage::saveSlot(uint8_t slotIndex) {
  // Find next free slot and mark current one as available when saving.
  // This is necessary to get more equal wear over memory.

  int16_t currentMemIndex = slots[slotIndex].memIndex;
  if (currentMemIndex >= 0) {
    iconMem.clearSlotNumber(currentMemIndex);
  }
  for (uint16_t i=0; i<iconMem.MEM_COUNT; i++) {
    uint16_t memIndex = (currentMemIndex + 1 + i) % iconMem.MEM_COUNT;
    if (iconMem.getSlotNumber(memIndex) >= SLOT_COUNT) {
      iconMem.writeIconData(memIndex, slots[slotIndex].storedData);
      slots[slotIndex].memIndex = memIndex;
      break;
    }
  }
}

