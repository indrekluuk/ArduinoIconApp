//
// Created by indrek on 7.05.2017.
//

#include "Tools.h"
#include "PBlocksUserInterface.h"





void Tools::init() {
  initSavedIconsPage(0);
  toolbar.init();
  initMainToolbar();
}


void Tools::initSavedIconsPage(uint8_t newPage) {
  page = newPage;
  for (uint8_t i=0; i<ICON_BUTTON_COUNT; i++) {
    savedIcons[i] = UI->iconStorage.getStoredIconData(page * ICON_BUTTON_COUNT + i).icon;
  }
}


void Tools::draw() {
  toolbar.draw();

  TFT & tft = UI->tft;
  tft.setTextSize(1);
  tft.setTextColor(COLOR_WHITE, COLOR_BLACK);
  tft.setCursor(Toolbar::TOOLBAR_X + Toolbar::TOOLBAR_W - 6 * 3 - 1, 5);
  if (showPageNumber) {
    tft.print(page+1);
    tft.print("/");
    tft.print(ICON_PAGE_COUNT);
  } else {
    tft.print("     ");
  }
}


void Tools::reset() {
  toolbar.reset();
  showPageNumber = false;
}


void Tools::initMainToolbar() {
  reset();

  toolbar.addButton(true)
      .setCallback(this, &Tools::showEditToolbar, 0)
      .reset()
      .setIcon(&iconEdit);
  toolbar.addButton(true)
      .setCallback(this, &Tools::showIconButtonsToolbar, TOOLBAR_ICONS_SAVE)
      .reset()
      .setIcon(&iconSave);
  toolbar.addButton(true)
      .setCallback(this, &Tools::showIconButtonsToolbar, TOOLBAR_ICONS_LOAD)
      .reset()
      .setIcon(&iconLoad);
  toolbar.addButton(true)
      .setCallback(this, &Tools::showIconButtonsToolbar, TOOLBAR_ICONS_SEND)
      .reset()
      .setIcon(&iconSend);
}


void Tools::showMainToolbar(uint8_t) {
  initMainToolbar();
  draw();
}


void Tools::showEditToolbar(uint8_t) {
  reset();

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
      .reset()
      .setToggle(true)
      .setToggleStatus(UI->activeIcon.color.hasBorder && !UI->activeIcon.color.hasBorder3d)
      .setIcon(&iconBorder);
  toolbar.addButton(false)
      .setCallback(this, &Tools::setBorder3D, 0)
      .reset()
      .setToggle(true)
      .setToggleStatus(UI->activeIcon.color.hasBorder && UI->activeIcon.color.hasBorder3d)
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


void Tools::showIconButtonsToolbar(uint8_t action) {
  reset();
  showPageNumber = true;

  Toolbar::ToobarButton::CallbackMethod iconButtonCallback = nullptr;
  bool isPlacementRight = false;
  bool isDirectionRight = false;
  if (action == TOOLBAR_ICONS_SAVE) {
    iconButtonCallback = &Tools::saveIcon;
    isPlacementRight = false;
    isDirectionRight = true;
  } else if (action == TOOLBAR_ICONS_LOAD) {
    iconButtonCallback = &Tools::loadIcon;
    isPlacementRight = false;
    isDirectionRight = false;
  } else if (action == TOOLBAR_ICONS_SEND) {
    iconButtonCallback = &Tools::sendIcon;
    isPlacementRight = true;
    isDirectionRight = true;
  }

  toolbar.addButton(false)
      .setCallback(this, &Tools::moveIconPage, -1)
      .reset()
      .setLabel("<");
      //.setIcon(&iconLeft);
  toolbar.addButton(false)
      .setCallback(this, &Tools::moveIconPage, 1)
      .reset()
      .setLabel(">");
      //.setIcon(&iconRight);

  for (uint8_t i=0; i<ICON_BUTTON_COUNT; i++) {
    toolbar.addButton(true)
        .setCallback(this, iconButtonCallback, i)
        .reset()
        .setIcon(&savedIcons[i])
        .showArrow(isPlacementRight, isDirectionRight);
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
  UI->activeIcon.color.hasBorder = !UI->activeIcon.color.hasBorder || UI->activeIcon.color.hasBorder3d;
  UI->activeIcon.color.hasBorder3d = false;
  showEditToolbar(0);
  UI->iconUpdated(false, true, false);
}



void Tools::setBorder3D(uint8_t) {
  if (UI->activeIcon.color.hasBorder3d) {
    UI->activeIcon.color.hasBorder = false;
    UI->activeIcon.color.hasBorder3d = false;
  } else {
    UI->activeIcon.color.hasBorder = true;
    UI->activeIcon.color.hasBorder3d = true;
  }
  showEditToolbar(0);
  UI->iconUpdated(false, true, false);
}


void Tools::clearIcon(uint8_t) {
  for (uint8_t i=0; i<Icon::BITMAP_HEIGHT; i++) {
    UI->activeIcon.bitmap[i] = 0;
  }
  showMainToolbar(0);
  UI->iconUpdated(true, false, false);
}



void Tools::moveIconPage(uint8_t direction) {

  int8_t newPage = page + direction;
  if (newPage < 0) {
    newPage = 0;
  } else if (newPage >= ICON_PAGE_COUNT) {
    newPage = ICON_PAGE_COUNT - 1;
  }
  if (newPage != page) {
    initSavedIconsPage(newPage);
    draw();
  }
}


void Tools::saveIcon(uint8_t slotIndex) {
  showMainToolbar(0);
  UI->iconStorage.saveIcon(
      ICON_BUTTON_COUNT * page + slotIndex,
      UI->activeIcon,
      COLOR_foreground,
      COLOR_background,
      COLOR_border,
      UI->exampleView.scale
  );
}


void Tools::loadIcon(uint8_t slotIndex) {
  showMainToolbar(0);
  IconColor color = UI->activeIcon.color;
  IconStorageData & data = UI->iconStorage.getStoredIconData(ICON_BUTTON_COUNT * page + slotIndex);
  UI->activeIcon = data.icon;
  UI->activeIcon.color = color;
  UI->activeIcon.color.hasBorder = data.hasBorder;
  UI->activeIcon.color.hasBorder3d = data.is3d;
  UI->exampleView.setScale(data.scale);
  COLOR_foreground = data.foregroundColor;
  COLOR_background = data.backgroundColor;
  COLOR_border = data.borderColor;
  UI->iconUpdated(true, true, true);
}


void Tools::sendIcon(uint8_t slotIndex) {
  IconBufferMem & icon = UI->iconStorage.getStoredIconData(ICON_BUTTON_COUNT * page + slotIndex).icon;
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



