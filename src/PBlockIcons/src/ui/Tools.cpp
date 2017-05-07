//
// Created by indrek on 7.05.2017.
//

#include "Tools.h"
#include "PBlocksUserInterface.h"





void Tools::init() {
  mainToolbar.addButton(showEditButton, "E");
  mainToolbar.addButton(showSaveButton, "S");
  mainToolbar.addButton(showLoadButton, "L");
  mainToolbar.addButton(showSendButton, "snd");

  editToolbar.addButton(invertIconButton, "inv");
  editToolbar.addButton(clearIconButton, "clr");
  editToolbar.addButton(cancelEditButton, "R");

  for (uint8_t i=0; i<SAVED_ICON_COUNT; i++) {
    saveToolbar.addButton(saveButtons[i], &buttonIcons[i]);
  }
  saveToolbar.addButton(cancelSaveButton, "R");

  for (uint8_t i=0; i<SAVED_ICON_COUNT; i++) {
    loadToolbar.addButton(loadButtons[i], &buttonIcons[i]);
  }
  loadToolbar.addButton(cancelLoadButton, "R");

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

void Tools::returnToMain() {
  setActiveToolbar(&mainToolbar);
}


