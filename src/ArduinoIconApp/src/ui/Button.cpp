//
// Created by indrek on 6.05.2017.
//

#include "Arduino.h"
#include "Button.h"
#include "ArduinoIconAppUserInterface.h"





ButtonBase & ButtonBase::init(uint16_t x, uint16_t y, uint8_t w, uint8_t h) {
  buttonX = x;
  buttonY = y;
  buttonW = w;
  buttonH = h;
  reset();
  return *this;
}


ButtonBase & ButtonBase::reset() {
  decoration = nullptr;
  isShowArrow = false;
  isPressed = false;
  isToggleButton = false;
  isToggleOn = false;
  setActive(true);
  isDisabled = false;
  return *this;
}


ButtonBase & ButtonBase::setToggle(bool isToggle) {
  isToggleButton = isToggle;
  return *this;
}


ButtonBase & ButtonBase::setIcon(Icon * icon) {
  decoration = icon;
  isDecorationIcon = true;
  return *this;
}


ButtonBase & ButtonBase::setLabel(const char * label) {
  decoration = label;
  isDecorationIcon = false;
  return *this;
}


ButtonBase & ButtonBase::showArrow(bool isDirectionRight) {
  isShowArrow = true;
  arrowDirectionRight = isDirectionRight;
  return *this;
}


void ButtonBase::setActive(bool active) {
  isActive = active;
}


bool ButtonBase::isButtonActive() {
  return isActive;
}


void ButtonBase::setDisabled(bool disabled) {
  isDisabled = disabled;
}


bool ButtonBase::isButtonDisabled() {
  return isDisabled;
}


ButtonBase & ButtonBase::setToggleStatus(bool isOn) {
  isToggleOn = isOn;
  isPressed = isOn;
  return *this;
}


bool ButtonBase::touch(uint16_t x, uint16_t y) {
  if (isActive && !isDisabled && isTouchOnButton(x, y)) {
    isPressed = true;
    draw();
    return true;
  } else {
    return false;
  }
}

void ButtonBase::hold(uint16_t x, uint16_t y) {
  if (isTouchOnButton(x, y)) {
    if (!isPressed) {
      isPressed = true;
      draw();
    }
  } else {
    if (isPressed) {
      if (!isToggleOn) {
        isPressed = false;
        draw();
      }
    }
  }
}

void ButtonBase::release(uint16_t x, uint16_t y) {
  bool isOnButton = isTouchOnButton(x, y);

  if (isPressed) {
    if (isToggleButton) {
      if (isOnButton) {
        isToggleOn = !isToggleOn;
      }
    } else {
      isToggleOn = false;
    }
    isPressed = isToggleOn;
    draw();
  }

  if (isOnButton) {
    action();
  }
}


bool ButtonBase::isTouchOnButton(uint16_t x, uint16_t y) {
  return isTapIn(x, buttonX, buttonW) && isTapIn(y, buttonY, buttonH);
}




void ButtonBase::draw() {
  if (!isActive) {
    return;
  }

  TFT &tft = UI->tft;

  tft.drawFastHLine(buttonX, buttonY, buttonW, isPressed ? COLOR_GRAY33 : COLOR_GRAY66);
  tft.drawFastVLine(buttonX, buttonY, buttonH, isPressed ? COLOR_GRAY33 : COLOR_GRAY66);
  tft.drawFastHLine(buttonX, buttonY + buttonH - 1, buttonW, isPressed ? COLOR_WHITE : COLOR_GRAY33);
  tft.drawFastVLine(buttonX + buttonW - 1, buttonY, buttonH, isPressed ? COLOR_WHITE : COLOR_GRAY33);


  uint16_t x = buttonX + (uint16_t)1;
  uint16_t y = buttonY + 1;
  uint8_t w = buttonW - 2;
  uint8_t h = buttonH - 2;

  if (decoration != nullptr) {
    if (isDecorationIcon) {
      drawIcon((Icon *)decoration, x, y, w, h);
    } else {
      drawLabel((const char *)decoration, x, y, w, h);
    }
  } else {
    tft.fillRect(x, y, w, h, isPressed ? COLOR_GRAY66 : COLOR_GRAY85);
  }

  if (isShowArrow) {
    uint16_t arrX = buttonX + 4;
    uint16_t arrY = buttonY + 4;
    drawArrow(arrX, arrY);
  }
}






void ButtonBase::drawIcon(Icon * buttonIcon, uint16_t x, uint16_t y, uint8_t w, uint8_t h) {
  uint8_t scale = (buttonW < (uint8_t)34) || (buttonH < (uint8_t)34) ? (uint8_t)1 : (uint8_t)2;

  IconColor color = buttonIcon->getColor();
  color.setNoBorder();

  if (isPressed) {
    color.setBackgroundColor(Palette::GRAY85);
    UI->tft.drawIcon(x, y, *buttonIcon, color, w, h, 2, 2, scale, scale);
  } else {
    color.setBackgroundColor(Palette::GRAY66);
    if (isDisabled) {
      color.setForegroundColor(Palette::GRAY50);
    }
    UI->tft.drawIcon(x, y, *buttonIcon, color, w, h, 0, 0, scale, scale);
  }
}





void ButtonBase::drawLabel(const char * buttonLabel, uint16_t x, uint16_t y, uint8_t w, uint8_t h) {
  TFT & tft = UI->tft;

  if (isPressed) {
    tft.setTextColor(COLOR_BLACK, COLOR_GRAY85);
  } else {
    tft.setTextColor(isDisabled ? COLOR_GRAY50 : COLOR_BLACK, COLOR_GRAY66);
  }
  tft.setTextSize(2);

  ;
  uint8_t cX = (w >> 1) - ((strlen(buttonLabel)*10) >> 1);
  uint8_t cY = (h >> 1) - (uint8_t)6;
  if (isPressed) {
    cX+=2;
    cY+=2;
  }

  // quick and dirty hack to move "scroll left" to center
  if (buttonLabel[0] == '<') cX -= 2;

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

  uint16_t arrowColor = isDisabled ? COLOR_GRAY50 : COLOR_BLACK;

  tft.fillRect(x + (arrowDirectionRight ? 0 : 4), y + 0, 2, 10, arrowColor);
  tft.fillRect(x + (arrowDirectionRight ? 2 : 2), y + 2, 2, 6, arrowColor);
  tft.fillRect(x + (arrowDirectionRight ? 4 : 0), y + 4, 2, 2, arrowColor);
}


