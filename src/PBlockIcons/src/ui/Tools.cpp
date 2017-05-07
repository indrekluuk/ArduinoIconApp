//
// Created by indrek on 7.05.2017.
//

#include "Tools.h"
#include "PBlocksUserInterface.h"





void Tools::init() {
  mainToolbar.addButton(showEditButton, &iconEdit);
  mainToolbar.addButton(showSaveButton, &iconSave);
  mainToolbar.addButton(showLoadButton, &iconLoad);
  mainToolbar.addButton(showSendButton, &iconSend);

  editToolbar.addButton(invertIconButton, &iconInvert);
  editToolbar.addButton(clearIconButton, &iconClear);
  editToolbar.addButton(cancelEditButton, &iconReturn);

  for (uint8_t i=0; i<SAVED_ICON_COUNT; i++) {
    saveToolbar.addButton(saveButtons[i], &buttonIcons[i]);
  }
  saveToolbar.addButton(cancelSaveButton, &iconReturn);

  for (uint8_t i=0; i<SAVED_ICON_COUNT; i++) {
    loadToolbar.addButton(loadButtons[i], &buttonIcons[i]);
  }
  loadToolbar.addButton(cancelLoadButton, &iconReturn);

  for (uint8_t i=0; i<SAVED_ICON_COUNT; i++) {
    sendToolbar.addButton(sendButtons[i], &buttonIcons[i]);
  }
  sendToolbar.addButton(cancelSendButton, &iconReturn);

  setActiveToolbar(&mainToolbar);
}



void Tools::draw(bool redrawAll) {
  if (redrawAll) {
    activeToolbar->draw(redrawAll);
  }
}


void Tools::setActiveToolbar(Toolbar * toolbar) {
  activeToolbar->setActive(false);
  activeToolbar = toolbar;
  activeToolbar->setActive(true);
  activeToolbar->draw(true);
}


void Tools::showEditToolbar() {
  setActiveToolbar(&editToolbar);
}

void Tools::showSaveToolbar() {
  reloadButtonIcons();
  setActiveToolbar(&saveToolbar);
}

void Tools::showLoadToolbar() {
  reloadButtonIcons();
  setActiveToolbar(&loadToolbar);
}

void Tools::showSendToolbar() {
  reloadButtonIcons();
  setActiveToolbar(&sendToolbar);
}


void Tools::reloadButtonIcons() {
  for (uint8_t i = 0; i < SAVED_ICON_COUNT; i++) {
    UI->iconStorage.loadIcon(i, buttonIcons[i]);
  }
}


void Tools::invertIcon() {
  for (uint8_t i=0; i<Icon::BITMAP_HEIGHT; i++) {
    UI->activeIcon.bitmap[i] = ~UI->activeIcon.bitmap[i];
  }
  returnToMain();
  UI->draw(true);
}

void Tools::clearIcon() {
  for (uint8_t i=0; i<Icon::BITMAP_HEIGHT; i++) {
    UI->activeIcon.bitmap[i] = 0;
  }
  returnToMain();
  UI->draw(true);
}



void Tools::saveIcon(uint8_t slotIndex) {
  returnToMain();
  UI->draw(true);
  UI->iconStorage.saveIcon(slotIndex, UI->activeIcon);
}


void Tools::loadIcon(uint8_t slotIndex) {
  returnToMain();
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



void Tools::returnToMain() {
  setActiveToolbar(&mainToolbar);
}


