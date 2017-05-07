//
// Created by indrek on 7.05.2017.
//

#include "Toolbar.h"
#include "PBlocksUserInterface.h"





void Toolbar::init() {
  reset();
  for (uint8_t i = 0; i<MAX_BUTTON_COUNT; i++) {
    buttons[i].init(TOOLBAR_X, TOOLBAR_Y + i*TOOLBAR_BUTTON_H, TOOLBAR_W, TOOLBAR_BUTTON_H);
  }
}


void Toolbar::reset() {
  buttonCount = 0;
  for (uint8_t i = 0; i<MAX_BUTTON_COUNT; i++) {
    buttons[i].setActive(false);
    buttons[i].removeArrow();
  }
}


Button<Tools> & Toolbar::addButton() {
  if (buttonCount < MAX_BUTTON_COUNT) {
    buttons[buttonCount].setActive(true);
    buttonCount++;
  }
  return buttons[buttonCount - 1];
}




void Toolbar::draw(bool redrawAll) {
  if (redrawAll) {
    uint16_t bottom = TOOLBAR_Y;
    for (uint8_t i=0; i<buttonCount; i++) {
      buttons[i].draw();
      bottom = buttons[i].buttonY + buttons[i].buttonH;
    }
    UI->tft.fillRect(TOOLBAR_X, bottom, TOOLBAR_W, TOOLBAR_Y + TOOLBAR_H - bottom, COLOR_BLACK);
  }
}





