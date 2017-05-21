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


void Tools::showMainToolbar(uint8_t) {
  toolbar.reset();
  toolbar.addButton(true)
      .setCallback(this, &Tools::showEditToolbar, 0)
      .reset()
      .setIcon(&iconEdit);
  toolbar.addButton(true)
      .setCallback(this, &Tools::showSaveToolbar, 0)
      .reset()
      .setIcon(&iconSave);
  toolbar.addButton(true)
      .setCallback(this, &Tools::showLoadToolbar, 0)
      .reset()
      .setIcon(&iconLoad);
  toolbar.addButton(true)
      .setCallback(this, &Tools::showSendToolbar, 0)
      .reset()
      .setIcon(&iconSend);
  draw();
}


void Tools::showEditToolbar(uint8_t) {
  toolbar.reset();
  toolbar.addButton(true)
      .setCallback(this, &Tools::invertIcon, 0)
      .reset()
      .setIcon(&iconInvert);

  toolbar.addButton(false)
      .setCallback(this, &Tools::moveIconUp, 0)
      .reset()
      .setIcon(&iconUp);
  toolbar.addButton(false)
      .setCallback(this, &Tools::moveIconDown, 0)
      .reset()
      .setIcon(&iconDown);
  toolbar.addButton(false)
      .setCallback(this, &Tools::moveIconLeft, 0)
      .reset()
      .setIcon(&iconLeft);
  toolbar.addButton(false)
      .setCallback(this, &Tools::moveIconRight, 0)
      .reset()
      .setIcon(&iconRight);

  toolbar.addButton(false)
      .setCallback(this, &Tools::flipIcon, 0)
      .reset()
      .setIcon(&iconFlip);
  toolbar.addButton(false)
      .setCallback(this, &Tools::rotateIcon, 0)
      .reset()
      .setIcon(&iconRotate);

  toolbar.addButton(false)
      .setCallback(this, &Tools::setBorder, 0)
      .setToggle(true)
      .reset()
      .setIcon(&iconBorder);
  toolbar.addButton(false)
      .setCallback(this, &Tools::setBorder3D, 0)
      .setToggle(true)
      .reset()
      .setIcon(&iconBorder3D);

  toolbar.addButton(true)
      .setCallback(this, &Tools::clearIcon, 0)
      .reset()
      .setIcon(&iconClear);
  toolbar.addButton(true)
      .setCallback(this, &Tools::showMainToolbar, 0)
      .reset()
      .setIcon(&iconReturn);
  draw();
}


void Tools::showSaveToolbar(uint8_t) {
  toolbar.reset();
  for (uint8_t i=0; i<SAVED_ICON_COUNT; i++) {
    toolbar.addButton(true)
        .setCallback(this, &Tools::saveIcon, i)
        .reset()
        .setIcon(buttonIcons[i])
        .showArrow(false, true);
  }
  toolbar.addButton(true)
      .setCallback(this, &Tools::showMainToolbar, 0)
      .reset()
      .setIcon(&iconReturn);
  draw();
}

void Tools::showLoadToolbar(uint8_t) {
  toolbar.reset();
  for (uint8_t i=0; i<SAVED_ICON_COUNT; i++) {
    toolbar.addButton(true)
        .setCallback(this, &Tools::loadIcon, i)
        .reset()
        .setIcon(buttonIcons[i])
        .showArrow(false, false);
  }
  toolbar.addButton(true)
      .setCallback(this, &Tools::showMainToolbar, 0)
      .reset()
      .setIcon(&iconReturn);
  draw();
}

void Tools::showSendToolbar(uint8_t) {
  toolbar.reset();
  for (uint8_t i=0; i<SAVED_ICON_COUNT; i++) {
    toolbar.addButton(true)
        .setCallback(this, &Tools::sendIcon, i)
        .reset()
        .setIcon(buttonIcons[i])
        .showArrow(true, true);
  }
  toolbar.addButton(true)
      .setCallback(this, &Tools::showMainToolbar, 0)
      .reset()
      .setIcon(&iconReturn);
  draw();
}



void Tools::invertIcon(uint8_t) {
  for (uint8_t i=0; i<Icon::BITMAP_HEIGHT; i++) {
    UI->activeIcon.bitmap[i] = ~UI->activeIcon.bitmap[i];
  }
  UI->iconUpdated(true, false, false);
}

void Tools::moveIconUp(uint8_t) {
  for (uint8_t i=0; i<Icon::BITMAP_HEIGHT-1; i++) {
    UI->activeIcon.bitmap[i] = UI->activeIcon.bitmap[i+1];
  }
  UI->activeIcon.bitmap[Icon::BITMAP_HEIGHT-1] = 0;
  UI->iconUpdated(true, false, false);
}

void Tools::moveIconDown(uint8_t) {
  for (uint8_t i=Icon::BITMAP_HEIGHT-1; i>0; i--) {
    UI->activeIcon.bitmap[i] = UI->activeIcon.bitmap[i-1];
  }
  UI->activeIcon.bitmap[0] = 0;
  UI->iconUpdated(true, false, false);
}

void Tools::moveIconLeft(uint8_t) {
  for (uint8_t i=0; i<Icon::BITMAP_HEIGHT; i++) {
    UI->activeIcon.bitmap[i] <<= 1;
  }
  UI->iconUpdated(true, false, false);
}

void Tools::moveIconRight(uint8_t) {
  for (uint8_t i=0; i<Icon::BITMAP_HEIGHT; i++) {
    UI->activeIcon.bitmap[i] >>= 1;
  }
  UI->iconUpdated(true, false, false);
}


void Tools::flipIcon(uint8_t) {
  for (uint8_t i=0; i<Icon::BITMAP_HEIGHT; i++) {
    uint16_t fromMask = 0x8000;
    uint16_t toMask = 0x0001;
    uint16_t newRow = 0;
    while (fromMask > 0) {
      if (UI->activeIcon.bitmap[i] & fromMask) newRow |= toMask;
      fromMask >>= 1;
      toMask <<= 1;
    }
    UI->activeIcon.bitmap[i] = newRow;
  }
  UI->iconUpdated(true, false, false);
}


void Tools::rotateIcon(uint8_t) {
  uint16_t rotatedBitmap[Icon::BITMAP_HEIGHT];
  uint16_t fromMask = 0x8000;
  for (uint8_t j=0; j<Icon::BITMAP_WIDTH; j++) {
    rotatedBitmap[j] = 0;
    uint16_t toMask = 0x0001;
    for (uint8_t i=0; i<Icon::BITMAP_HEIGHT; i++) {
      if (UI->activeIcon.bitmap[i] & fromMask) {
        rotatedBitmap[j] |= toMask;
      }
      toMask <<= 1;
    }
    fromMask >>= 1;
  }
  for (uint8_t i=0; i<Icon::BITMAP_HEIGHT; i++) {
    UI->activeIcon.bitmap[i] = rotatedBitmap[i];
  }
  UI->iconUpdated(true, false, false);
}


void Tools::setBorder(uint8_t) {

}



void Tools::setBorder3D(uint8_t) {

}


void Tools::clearIcon(uint8_t) {
  for (uint8_t i=0; i<Icon::BITMAP_HEIGHT; i++) {
    UI->activeIcon.bitmap[i] = 0;
  }
  showMainToolbar(0);
  UI->iconUpdated(true, false, false);
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
  UI->activeIcon = data.icon;
  UI->activeIcon.color = color;
  UI->activeIcon.color.hasBorder = data.hasBorder;
  UI->activeIcon.color.hasBorder3d = data.is3d;
  COLOR_foreground = data.foregroundColor;
  COLOR_background = data.backgroundColor;
  COLOR_border = data.borderColor;
  UI->iconUpdated(true, true, true);
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



