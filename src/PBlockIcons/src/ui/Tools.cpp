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

}

void Tools::showLoadToolbar() {

}

void Tools::showSendToolbar() {

}


void Tools::invertIcon() {
  for (uint8_t i=0; i<Icon::BITMAP_HEIGHT; i++) {
    UI->activeIcon.bitmap[i] = ~UI->activeIcon.bitmap[i];
  }
  cancelEdit();
  UI->draw(true);
}

void Tools::clearIcon() {
  for (uint8_t i=0; i<Icon::BITMAP_HEIGHT; i++) {
    UI->activeIcon.bitmap[i] = 0;
  }
  cancelEdit();
  UI->draw(true);
}

void Tools::cancelEdit() {
  setActiveToolbar(&mainToolbar);
}


