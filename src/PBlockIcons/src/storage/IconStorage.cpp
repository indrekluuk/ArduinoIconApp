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
  for (uint16_t i=0; i<iconMem.MEM_COUNT; i++) {
    if (iconMem.getSlotNumber(i) == slotIndex) {
      if (slots[slotIndex].memIndex < 0) {
        slots[slotIndex].memIndex = i;
        slots[slotIndex].icon = iconMem.readIconData(i);
      } else {
        iconMem.setSlotNumber(i, 0xFF);
      }
    }
  }
}



void IconStorage::saveIcon(uint8_t slotIndex, IconBufferMem & icon) {
  slots[slotIndex].icon = icon;
  saveSlot(slotIndex);
}


void IconStorage::loadIcon(uint8_t slotIndex, IconBufferMem & icon) {
  icon = slots[slotIndex].icon;
}




void IconStorage::saveSlot(uint8_t slotIndex) {
  int16_t currentMemIndex = slots[slotIndex].memIndex;
  if (currentMemIndex >= 0) {
    iconMem.setSlotNumber(currentMemIndex, 0xFF);
  }
  for (uint16_t i=0; i<iconMem.MEM_COUNT; i++) {
    uint16_t memIndex = (currentMemIndex + 1 + i) % iconMem.MEM_COUNT;
    if (iconMem.getSlotNumber(memIndex) >= SLOT_COUNT) {
      iconMem.setSlotNumber(memIndex, slotIndex);
      iconMem.writeIconData(memIndex, slots[slotIndex].icon);
      slots[slotIndex].memIndex = memIndex;
      break;
    }
  }
}

