//
// Created by indrek on 6.05.2017.
//

#include "Button.h"
#include "PBlocksUserInterface.h"





void ButtonBase::init(uint16_t x, uint16_t y, uint8_t w, uint8_t h) {
  buttonX = x;
  buttonY = y;
  buttonW = w;
  buttonH = h;
}

void ButtonBase::init(uint16_t x, uint16_t y, uint8_t w, uint8_t h, Icon * icon) {
  buttonX = x;
  buttonY = y;
  buttonW = w;
  buttonH = h;
  setIcon(icon);
}

void ButtonBase::init(uint16_t x, uint16_t y, uint8_t w, uint8_t h, const char * label) {
  buttonX = x;
  buttonY = y;
  buttonW = w;
  buttonH = h;
  setLabel(label);
}


ButtonBase & ButtonBase::setIcon(Icon * icon) {
  decoration = icon;
  isDecorationIcon = true;
  return *this;
}


ButtonBase & ButtonBase::setLabel(const char * label) {
  decoration = label;
  isDecorationLabel = true;
  return *this;
}


ButtonBase & ButtonBase::showArrow(bool isPlacementRight, bool isDirectionRight) {
  isShowArrow = true;
  arrowPlacementRight = isPlacementRight;
  arrowDirectionRight = isDirectionRight;
  return *this;
}


ButtonBase & ButtonBase::removeArrow() {
  isShowArrow = false;
  return *this;
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

  if (isDecorationIcon) {
    drawIcon((Icon *)decoration, x, y, w, h);
  } else if (isDecorationLabel) {
    drawLabel((const char *)decoration, x, y, w, h);
  } else {
    tft.fillRect(x, y, w, h, isPressed ? COLOR_GRAY66 : COLOR_GRAY85);
  }

  if (isShowArrow) {
    uint16_t arrX = arrowPlacementRight ? buttonX + buttonW - 10 : buttonX + 4 ;
    uint16_t arrY = buttonY + 4;
    drawArrow(arrX, arrY);
  }
}






void ButtonBase::drawIcon(Icon * buttonIcon, uint16_t x, uint16_t y, uint8_t w, uint8_t h) {

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





void ButtonBase::drawLabel(const char * buttonLabel, uint16_t x, uint16_t y, uint8_t w, uint8_t h) {
  TFT & tft = UI->tft;

  if (isPressed) {
    tft.setTextColor(COLOR_BLACK, COLOR_GRAY85);
  } else {
    tft.setTextColor(COLOR_BLACK, COLOR_GRAY66);
  }
  tft.setTextSize(2);

  ;
  uint8_t cX = (w >> 1) - ((strlen(buttonLabel)*10) >> 1);
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


void ButtonBase::drawArrow(uint16_t x, uint16_t y) {
  TFT & tft = UI->tft;

  if (isPressed) {
    x += 2;
    y += 2;
  }

  tft.fillRect(x + (arrowDirectionRight ? 0 : 4), y + 0, 2, 10, COLOR_BLACK);
  tft.fillRect(x + (arrowDirectionRight ? 2 : 2), y + 2, 2, 6, COLOR_BLACK);
  tft.fillRect(x + (arrowDirectionRight ? 4 : 0), y + 4, 2, 2, COLOR_BLACK);
}


