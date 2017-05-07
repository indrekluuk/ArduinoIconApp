//
// Created by indrek on 7.05.2017.
//

#include "Tools.h"
#include "PBlocksUserInterface.h"





void Tools::init() {
  toolbar.init();
  showMainToolbar(0);
}



void Tools::draw(bool redrawAll) {
  if (redrawAll) {
    toolbar.draw(redrawAll);
  }
}


void Tools::showMainToolbar(uint8_t) {
  toolbar.reset();
  toolbar.addButton()
      .setCallback(this, &Tools::showEditToolbar)
      .setIcon(&iconEdit);
  toolbar.addButton()
      .setCallback(this, &Tools::showSaveToolbar)
      .setIcon(&iconSave);
  toolbar.addButton()
      .setCallback(this, &Tools::showLoadToolbar)
      .setIcon(&iconLoad);
  toolbar.addButton()
      .setCallback(this, &Tools::showSendToolbar)
      .setIcon(&iconSend);
  draw(true);
}


void Tools::showEditToolbar(uint8_t) {
  toolbar.reset();
  toolbar.addButton()
      .setCallback(this, &Tools::invertIcon)
      .setIcon(&iconInvert);
  toolbar.addButton()
      .setCallback(this, &Tools::clearIcon)
      .setIcon(&iconClear);
  toolbar.addButton()
      .setCallback(this, &Tools::showMainToolbar)
      .setIcon(&iconReturn);
  draw(true);
}


void Tools::showSaveToolbar(uint8_t) {
  reloadButtonIcons();
  toolbar.reset();
  for (uint8_t i=0; i<SAVED_ICON_COUNT; i++) {
    toolbar.addButton()
        .setCallback(this, &Tools::saveIcon, i)
        .setIcon(&buttonIcons[i]);
  }
  toolbar.addButton()
      .setCallback(this, &Tools::showMainToolbar)
      .setIcon(&iconReturn);
  draw(true);
}

void Tools::showLoadToolbar(uint8_t) {
  reloadButtonIcons();
  toolbar.reset();
  for (uint8_t i=0; i<SAVED_ICON_COUNT; i++) {
    toolbar.addButton()
        .setCallback(this, &Tools::loadIcon, i)
        .setIcon(&buttonIcons[i]);
  }
  toolbar.addButton()
      .setCallback(this, &Tools::showMainToolbar)
      .setIcon(&iconReturn);
  draw(true);
}

void Tools::showSendToolbar(uint8_t) {
  reloadButtonIcons();
  toolbar.reset();
  for (uint8_t i=0; i<SAVED_ICON_COUNT; i++) {
    toolbar.addButton()
        .setCallback(this, &Tools::sendIcon, i)
        .setIcon(&buttonIcons[i]);
  }
  toolbar.addButton()
      .setCallback(this, &Tools::showMainToolbar)
      .setIcon(&iconReturn);
  draw(true);
}


void Tools::reloadButtonIcons() {
  for (uint8_t i = 0; i < SAVED_ICON_COUNT; i++) {
    UI->iconStorage.loadIcon(i, buttonIcons[i]);
  }
}


void Tools::invertIcon(uint8_t) {
  for (uint8_t i=0; i<Icon::BITMAP_HEIGHT; i++) {
    UI->activeIcon.bitmap[i] = ~UI->activeIcon.bitmap[i];
  }
  showMainToolbar(0);
  UI->draw(true);
}

void Tools::clearIcon(uint8_t) {
  for (uint8_t i=0; i<Icon::BITMAP_HEIGHT; i++) {
    UI->activeIcon.bitmap[i] = 0;
  }
  showMainToolbar(0);
  UI->draw(true);
}



void Tools::saveIcon(uint8_t slotIndex) {
  showMainToolbar(0);
  UI->iconStorage.saveIcon(slotIndex, UI->activeIcon);
}


void Tools::loadIcon(uint8_t slotIndex) {
  showMainToolbar(0);
  UI->iconStorage.loadIcon(slotIndex, UI->activeIcon);
  UI->draw(true);
}


void Tools::sendIcon(uint8_t slotIndex) {
  IconBufferMem icon;
  UI->iconStorage.loadIcon(slotIndex, icon);
  Serial.println();
  for (uint8_t row = 0; row < Icon::BITMAP_HEIGHT; row++) {
    Serial.print("(uint16_t) 0b");
    uint32_t mask = 0x10000;
    for (uint8_t i=0; i<16; i++) {
      mask >>= 1;
      Serial.print(icon.bitmap[row] & mask ? "1" : "0");
    }
    Serial.println(",");
  }
}



