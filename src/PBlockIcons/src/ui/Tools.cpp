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
      .setCallback(this, &Tools::showEditToolbar, 0)
      .setIcon(&iconEdit);
  toolbar.addButton()
      .setCallback(this, &Tools::showSaveToolbar, 0)
      .setIcon(&iconSave);
  toolbar.addButton()
      .setCallback(this, &Tools::showLoadToolbar, 0)
      .setIcon(&iconLoad);
  toolbar.addButton()
      .setCallback(this, &Tools::showSendToolbar, 0)
      .setIcon(&iconSend);
  draw(true);
}


void Tools::showEditToolbar(uint8_t) {
  toolbar.reset();
  toolbar.addButton()
      .setCallback(this, &Tools::invertIcon, 0)
      .setIcon(&iconInvert);

  toolbar.addButton()
      .setCallback(this, &Tools::moveIconUp, 0)
      .setIcon(&iconUp);
  toolbar.addButton()
      .setCallback(this, &Tools::moveIconDown, 0)
      .setIcon(&iconDown);
  toolbar.addButton()
      .setCallback(this, &Tools::moveIconLeft, 0)
      .setIcon(&iconLeft);
  toolbar.addButton()
      .setCallback(this, &Tools::moveIconRight, 0)
      .setIcon(&iconRight);

  toolbar.addButton()
      .setCallback(this, &Tools::clearIcon, 0)
      .setIcon(&iconClear);
  toolbar.addButton()
      .setCallback(this, &Tools::showMainToolbar, 0)
      .setIcon(&iconReturn);
  draw(true);
}


void Tools::showSaveToolbar(uint8_t) {
  reloadButtonIcons();
  toolbar.reset();
  for (uint8_t i=0; i<SAVED_ICON_COUNT; i++) {
    toolbar.addButton()
        .setCallback(this, &Tools::saveIcon, i)
        .setIcon(&buttonIcons[i])
        .showArrow(false, true);
  }
  toolbar.addButton()
      .setCallback(this, &Tools::showMainToolbar, 0)
      .setIcon(&iconReturn);
  draw(true);
}

void Tools::showLoadToolbar(uint8_t) {
  reloadButtonIcons();
  toolbar.reset();
  for (uint8_t i=0; i<SAVED_ICON_COUNT; i++) {
    toolbar.addButton()
        .setCallback(this, &Tools::loadIcon, i)
        .setIcon(&buttonIcons[i])
        .showArrow(false, false);
  }
  toolbar.addButton()
      .setCallback(this, &Tools::showMainToolbar, 0)
      .setIcon(&iconReturn);
  draw(true);
}

void Tools::showSendToolbar(uint8_t) {
  reloadButtonIcons();
  toolbar.reset();
  for (uint8_t i=0; i<SAVED_ICON_COUNT; i++) {
    toolbar.addButton()
        .setCallback(this, &Tools::sendIcon, i)
        .setIcon(&buttonIcons[i])
        .showArrow(true, true);
  }
  toolbar.addButton()
      .setCallback(this, &Tools::showMainToolbar, 0)
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
  UI->draw(true);
}

void Tools::moveIconUp(uint8_t) {
  for (uint8_t i=0; i<Icon::BITMAP_HEIGHT-1; i++) {
    UI->activeIcon.bitmap[i] = UI->activeIcon.bitmap[i+1];
  }
  UI->activeIcon.bitmap[Icon::BITMAP_HEIGHT-1] = 0;
  UI->draw(true);
}

void Tools::moveIconDown(uint8_t) {
  for (uint8_t i=Icon::BITMAP_HEIGHT-1; i>0; i--) {
    UI->activeIcon.bitmap[i] = UI->activeIcon.bitmap[i-1];
  }
  UI->activeIcon.bitmap[0] = 0;
  UI->draw(true);
}

void Tools::moveIconLeft(uint8_t) {
  for (uint8_t i=0; i<Icon::BITMAP_HEIGHT; i++) {
    UI->activeIcon.bitmap[i] <<= 1;
  }
  UI->draw(true);
}

void Tools::moveIconRight(uint8_t) {
  for (uint8_t i=0; i<Icon::BITMAP_HEIGHT; i++) {
    UI->activeIcon.bitmap[i] >>= 1;
  }
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



