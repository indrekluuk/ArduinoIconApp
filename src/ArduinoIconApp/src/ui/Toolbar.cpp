//
// Created by indrek on 7.05.2017.
//

#include "Toolbar.h"
#include "ArduinoIconApp.h"





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
      y2 = TOOLBAR_Y + ((row+(uint8_t)1) * TOOLBAR_H) / (MAX_BUTTON_COUNT / (uint8_t)2);
      h = y2 - y1;
      x = TOOLBAR_X;
      row++;
    }
    buttons[i].init(x, y1, getHalfButtonWidth(i), h);
  }
}


uint8_t Toolbar::getHalfButtonWidth(uint8_t buttonIndex) {
  if (buttonIndex & 1) {
    return TOOLBAR_W - (TOOLBAR_W >> 1);
  } else {
    return TOOLBAR_W >> 1;
  }
}


void Toolbar::reset() {
  buttonIndexStart = 0;
  buttonIndexEnd = MAX_BUTTON_COUNT - 1;
  for (uint8_t i = 0; i<MAX_BUTTON_COUNT; i++) {
    buttons[i].setActive(false);
  }
}


Button1<Tools, uint8_t> & Toolbar::addButton(bool wide, bool end) {
  uint8_t currentButton;
  if (end) {
    currentButton = buttonIndexEnd;
    buttonIndexEnd -= wide ? 2 : 1;
  } else {
    currentButton = buttonIndexStart;
    buttonIndexStart += wide ? 2 : 1;
  }

  buttons[currentButton].setActive(true);
  if (wide) {
    buttons[currentButton].buttonW = TOOLBAR_W;
  } else {
    buttons[currentButton].buttonW = getHalfButtonWidth(currentButton);
  }

  return buttons[currentButton];
}




void Toolbar::draw() {
  for (uint8_t i=0; i<MAX_BUTTON_COUNT; i++) {
    if (buttons[i].isButtonActive()) {
      buttons[i].draw();
    } else if (!(i & 1)) {
      UI->tft.fillRect(TOOLBAR_X, buttons[i].buttonY, TOOLBAR_W, buttons[i].buttonH, COLOR_BLACK);
    }
  }

}





