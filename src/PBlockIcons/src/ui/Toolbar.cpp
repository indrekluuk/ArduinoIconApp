//
// Created by indrek on 7.05.2017.
//

#include "Toolbar.h"
#include "PBlocksUserInterface.h"





void Toolbar::init() {

}


void Toolbar::addButton(ButtonBase & button, const char * label) {
  if (buttonCount < MAX_BUTTON_COUNT) {
    button.init(TOOLBAR_X, TOOLBAR_Y + buttonCount*TOOLBAR_BUTTON_H, TOOLBAR_W, TOOLBAR_BUTTON_H, label);
    buttons[buttonCount] = &button;
    button.setActive(false);
    buttonCount++;
  }
}



void Toolbar::addButton(ButtonBase & button, Icon * icon) {
  if (buttonCount < MAX_BUTTON_COUNT) {
    button.init(TOOLBAR_X, TOOLBAR_Y + buttonCount*TOOLBAR_BUTTON_H, TOOLBAR_W, TOOLBAR_BUTTON_H, icon);
    buttons[buttonCount] = &button;
    button.setActive(false);
    buttonCount++;
  }
}




void Toolbar::setActive(bool active) {
  for (uint8_t i=0; i<buttonCount; i++) {
    buttons[i]->setActive(active);
  }
}


void Toolbar::draw(bool redrawAll) {
  if (redrawAll) {
    uint16_t bottom = TOOLBAR_Y;
    for (uint8_t i=0; i<buttonCount; i++) {
      buttons[i]->draw();
      bottom = buttons[i]->buttonY + buttons[i]->buttonH;
    }
    UI->tft.fillRect(TOOLBAR_X, bottom, TOOLBAR_W, TOOLBAR_Y + TOOLBAR_H - bottom, COLOR_BLACK);
  }
}





