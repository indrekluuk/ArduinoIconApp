//
// Created by indrek on 7.05.2017.
//

#include "Toolbar.h"
#include "PBlocksUserInterface.h"





void Toolbar::init() {
  reset();
  uint16_t y1 = 0;
  uint16_t y2 = TOOLBAR_Y;
  uint8_t h = 0;
  uint8_t row = 0;
  for (uint8_t i = 0; i<MAX_BUTTON_COUNT; i++) {
    uint16_t x;
    if (i & 1) {
      x = TOOLBAR_X + TOOLBAR_W / 2;
    } else {
      y1 = y2;
      y2 = TOOLBAR_Y + ((row+(uint8_t)1) * TOOLBAR_H) / MAX_BUTTON_COUNT * (uint8_t)2;
      h = y2 - y1;
      x = TOOLBAR_X;
      row++;
    }
    buttons[i].init(x, y1, TOOLBAR_W / 2, h);
  }
}


void Toolbar::reset() {
  buttonCount = 0;
  for (uint8_t i = 0; i<MAX_BUTTON_COUNT; i++) {
    buttons[i].setActive(false);
  }
}


Button1<Tools, uint8_t> & Toolbar::addButton(bool wide) {
  if (wide && (buttonCount & 1)) buttonCount++;
  if (buttonCount < MAX_BUTTON_COUNT) {
    buttonCount++;
  }
  uint8_t currentButton = buttonCount - 1;
  buttons[currentButton].setActive(true);
  if (wide) {
    buttons[currentButton].buttonW = TOOLBAR_W;
    buttonCount++;
  } else {
    buttons[currentButton].buttonW = TOOLBAR_W / 2;
  }

  return buttons[currentButton];
}




void Toolbar::draw() {
  uint16_t bottom = TOOLBAR_Y;
  for (uint8_t i=0; i<buttonCount; i++) {
    buttons[i].draw();
    bottom = buttons[i].buttonY + buttons[i].buttonH;
  }
  UI->tft.fillRect(TOOLBAR_X, bottom, TOOLBAR_W, TOOLBAR_Y + TOOLBAR_H - bottom, COLOR_BLACK);
}





