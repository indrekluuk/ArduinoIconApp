//
// Created by indrek on 6.05.2017.
//

#include "Button.h"
#include "PBlocksUserInterface.h"





void ButtonBase::init(uint16_t x, uint16_t y, uint8_t w, uint8_t h, Icon * icon) {
  buttonX = x;
  buttonY = y;
  buttonW = w;
  buttonH = h;
  buttonIcon = icon;

}

void ButtonBase::init(uint16_t x, uint16_t y, uint8_t w, uint8_t h, const char * label) {
  buttonX = x;
  buttonY = y;
  buttonW = w;
  buttonH = h;
  buttonLabel = label;
}


void ButtonBase::setActive(bool active) {
  isActive = active;
}


bool ButtonBase::tap(uint16_t x, uint16_t y, bool hold) {
  if (!isActive) {
    return false;
  }

  if (isTapBetween(x, buttonX, buttonX + buttonW) && isTapBetween(y, buttonY, buttonY + buttonH)) {
    if (hold) {
      if (!isPressed) {
        isPressed = true;
        draw();
      }
    } else {
      isPressed = false;
      draw();
      action();
    }
    return true;
  } else {
    if (isPressed) {
      isPressed = false;
      draw();
    }
    return false;
  }
}



void ButtonBase::draw() {
  TFT &tft = UI->tft;

  tft.drawFastHLine(buttonX, buttonY, buttonW, isPressed ? COLOR_GRAY33 : COLOR_WHITE);
  tft.drawFastVLine(buttonX, buttonY, buttonH, isPressed ? COLOR_GRAY33 : COLOR_WHITE);
  tft.drawFastHLine(buttonX, buttonY + buttonH - 1, buttonW, isPressed ? COLOR_WHITE : COLOR_GRAY33);
  tft.drawFastVLine(buttonX + buttonW - 1, buttonY, buttonH, isPressed ? COLOR_WHITE : COLOR_GRAY33);


  uint16_t x = buttonX + (uint16_t)1;
  uint16_t y = buttonY + 1;
  uint8_t w = buttonW - 2;
  uint8_t h = buttonH - 2;

  if (buttonIcon != nullptr) {
    drawIcon(x, y, w, h);
  } else if (buttonLabel != nullptr) {
    drawLabel(x, y, w, h);
  } else {
    tft.fillRect(x, y, w, h, isPressed ? COLOR_GRAY66 : COLOR_GRAY85);
  }
}






void ButtonBase::drawIcon(uint16_t x, uint16_t y, uint8_t w, uint8_t h) {
  if (isPressed) {
    IconColor color = buttonIcon->getColor();

    color.setBackgroundColor(Palette::GRAY85);
    color.setNoBorder();

    UI->tft.drawIcon(x, y, *buttonIcon, color, w, h, 2, 2, 2, 2);
  } else {
    IconColor color = buttonIcon->getColor();

    color.setBackgroundColor(Palette::GRAY66);
    color.setNoBorder();

    UI->tft.drawIcon(x, y, *buttonIcon, color, w, h, 0, 0, 2, 2);
  }
}





void ButtonBase::drawLabel(uint16_t x, uint16_t y, uint8_t w, uint8_t h) {

  TFT & tft = UI->tft;
  if (isPressed) {
    tft.setTextColor(COLOR_WHITE, COLOR_GRAY85);
  } else {
    tft.setTextColor(COLOR_WHITE, COLOR_GRAY66);
  }
  tft.setTextSize(2);

  uint8_t cX = 10;
  uint8_t cY = (h >> 1) - (uint8_t)6;
  if (isPressed) {
    cX+=2;
    cY+=2;
  }
  tft.startTextFillBox(x, y, w, h, cX, cY);
  if (buttonLabel) {
    tft.print(buttonLabel);
  }
  tft.finishTextFillBox();
}


