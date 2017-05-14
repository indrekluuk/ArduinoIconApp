//
// Created by indrek on 7.05.2017.
//

#include "Tools.h"
#include "PBlocksUserInterface.h"





void Tools::init() {

  for (uint8_t i = 0; i < SAVED_ICON_COUNT; i++) {
    buttonIcons[i] = &UI->iconStorage.getStoredIconData(i).icon;
  }

  toolbar.init();
  showMainToolbar(0);
}



void Tools::draw() {
  toolbar.draw();
}


void Tools::updateIcon() {
  UI->pickerView.deactivate();
  UI->drawingGrid.setActive(true);
  UI->exampleView.evaluateIconData();
  UI->exampleView.draw();
  UI->drawingGrid.draw();
}


void Tools::showMainToolbar(uint8_t) {
  toolbar.reset();
  toolbar.addButton()
      .setCallback(this, &Tools::showEditToolbar, 0)
      .reset()
      .setIcon(&iconEdit);
  toolbar.addButton()
      .setCallback(this, &Tools::showSaveToolbar, 0)
      .reset()
      .setIcon(&iconSave);
  toolbar.addButton()
      .setCallback(this, &Tools::showLoadToolbar, 0)
      .reset()
      .setIcon(&iconLoad);
  toolbar.addButton()
      .setCallback(this, &Tools::showSendToolbar, 0)
      .reset()
      .setIcon(&iconSend);
  draw();
}


void Tools::showEditToolbar(uint8_t) {
  toolbar.reset();
  toolbar.addButton()
      .setCallback(this, &Tools::invertIcon, 0)
      .reset()
      .setIcon(&iconInvert);

  toolbar.addButton()
      .setCallback(this, &Tools::moveIconUp, 0)
      .reset()
      .setIcon(&iconUp);
  toolbar.addButton()
      .setCallback(this, &Tools::moveIconDown, 0)
      .reset()
      .setIcon(&iconDown);
  toolbar.addButton()
      .setCallback(this, &Tools::moveIconLeft, 0)
      .reset()
      .setIcon(&iconLeft);
  toolbar.addButton()
      .setCallback(this, &Tools::moveIconRight, 0)
      .reset()
      .setIcon(&iconRight);

  toolbar.addButton()
      .setCallback(this, &Tools::clearIcon, 0)
      .reset()
      .setIcon(&iconClear);
  toolbar.addButton()
      .setCallback(this, &Tools::showMainToolbar, 0)
      .reset()
      .setIcon(&iconReturn);
  draw();
}


void Tools::showSaveToolbar(uint8_t) {
  toolbar.reset();
  for (uint8_t i=0; i<SAVED_ICON_COUNT; i++) {
    toolbar.addButton()
        .setCallback(this, &Tools::saveIcon, i)
        .reset()
        .setIcon(buttonIcons[i])
        .showArrow(false, true);
  }
  toolbar.addButton()
      .setCallback(this, &Tools::showMainToolbar, 0)
      .reset()
      .setIcon(&iconReturn);
  draw();
}

void Tools::showLoadToolbar(uint8_t) {
  toolbar.reset();
  for (uint8_t i=0; i<SAVED_ICON_COUNT; i++) {
    toolbar.addButton()
        .setCallback(this, &Tools::loadIcon, i)
        .reset()
        .setIcon(buttonIcons[i])
        .showArrow(false, false);
  }
  toolbar.addButton()
      .setCallback(this, &Tools::showMainToolbar, 0)
      .reset()
      .setIcon(&iconReturn);
  draw();
}

void Tools::showSendToolbar(uint8_t) {
  toolbar.reset();
  for (uint8_t i=0; i<SAVED_ICON_COUNT; i++) {
    toolbar.addButton()
        .setCallback(this, &Tools::sendIcon, i)
        .reset()
        .setIcon(buttonIcons[i])
        .showArrow(true, true);
  }
  toolbar.addButton()
      .setCallback(this, &Tools::showMainToolbar, 0)
      .reset()
      .setIcon(&iconReturn);
  draw();
}



void Tools::invertIcon(uint8_t) {
  for (uint8_t i=0; i<Icon::BITMAP_HEIGHT; i++) {
    UI->activeIcon.bitmap[i] = ~UI->activeIcon.bitmap[i];
  }
  updateIcon();
}

void Tools::moveIconUp(uint8_t) {
  for (uint8_t i=0; i<Icon::BITMAP_HEIGHT-1; i++) {
    UI->activeIcon.bitmap[i] = UI->activeIcon.bitmap[i+1];
  }
  UI->activeIcon.bitmap[Icon::BITMAP_HEIGHT-1] = 0;
  updateIcon();
}

void Tools::moveIconDown(uint8_t) {
  for (uint8_t i=Icon::BITMAP_HEIGHT-1; i>0; i--) {
    UI->activeIcon.bitmap[i] = UI->activeIcon.bitmap[i-1];
  }
  UI->activeIcon.bitmap[0] = 0;
  updateIcon();
}

void Tools::moveIconLeft(uint8_t) {
  for (uint8_t i=0; i<Icon::BITMAP_HEIGHT; i++) {
    UI->activeIcon.bitmap[i] <<= 1;
  }
  updateIcon();
}

void Tools::moveIconRight(uint8_t) {
  for (uint8_t i=0; i<Icon::BITMAP_HEIGHT; i++) {
    UI->activeIcon.bitmap[i] >>= 1;
  }
  updateIcon();
}

void Tools::clearIcon(uint8_t) {
  for (uint8_t i=0; i<Icon::BITMAP_HEIGHT; i++) {
    UI->activeIcon.bitmap[i] = 0;
  }
  showMainToolbar(0);
  updateIcon();
}



void Tools::saveIcon(uint8_t slotIndex) {
  showMainToolbar(0);
  UI->iconStorage.saveIcon(
      slotIndex,
      UI->activeIcon,
      COLOR_foreground,
      COLOR_background,
      COLOR_border);
}


void Tools::loadIcon(uint8_t slotIndex) {
  showMainToolbar(0);
  IconColor color = UI->activeIcon.color;
  IconStorageData & data = UI->iconStorage.getStoredIconData(slotIndex);
  UI->activeIcon =data.icon;
  UI->activeIcon.color = color;
  UI->activeIcon.color.hasBorder = data.hasBorder;
  UI->activeIcon.color.hasBorder3d = data.is3d;
  COLOR_foreground = data.foregroundColor;
  COLOR_background = data.backgroundColor;
  COLOR_border = data.borderColor;
  updateIcon();
}


void Tools::sendIcon(uint8_t slotIndex) {
  IconBufferMem & icon = UI->iconStorage.getStoredIconData(slotIndex).icon;
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



