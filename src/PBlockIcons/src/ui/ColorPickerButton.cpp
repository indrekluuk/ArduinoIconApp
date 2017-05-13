//
// Created by indrek on 6.05.2017.
//

#include "ColorPickerButton.h"
#include "PBlocksUserInterface.h"


void ColorPickerButton::init(uint16_t x, uint16_t y, uint8_t w, uint8_t h) {
  pickerX = x;
  pickerY = y;
  pickerW = w;
  pickerH = h;
}



bool ColorPickerButton::touch(uint16_t x, uint16_t y) {
  if (isActive && isTouchOnColorPicker(x, y)) {
    return true;
  } else {
    return false;
  }
}

void ColorPickerButton::hold(uint16_t x, uint16_t y) {
  if (isTouchOnColorPicker(x, y)) {
    for (uint8_t c = 0; c<COLOR_COUNT; c++) {
      uint16_t cX = getColorX2(c);
      uint16_t cY = getColorY(c) + (pickerH / 2);
      if (x < cX && y < cY) {
        (view->*callbackMethod)((Palette)c);
        break;
      }
    }
  }
}

void ColorPickerButton::release(uint16_t x, uint16_t y) {
}


bool ColorPickerButton::isTouchOnColorPicker(uint16_t x, uint16_t y) {
  return isTapIn(x, pickerX, pickerW) && isTapIn(y, pickerY, pickerH);
}





void ColorPickerButton::draw() {
  if (isActive) {
    for (uint8_t c=0; c<COLOR_COUNT; c++) {
      uint16_t cx = getColorX1(c);
      uint16_t cy = getColorY(c);
      uint16_t cw = getColorX2(c) - cx;
      UI->tft.fillRect(cx, cy, cw, pickerH/2, RgbColor((Palette)c).colorCode);
    }
  } else {
    UI->tft.fillRect(pickerX, pickerY, pickerW, pickerH, COLOR_BLACK);
  }
}



uint16_t ColorPickerButton::getColorX(uint8_t c) {
  return pickerX + ((uint16_t)pickerW) * ((uint16_t)c) / ((uint16_t)COLOR_COUNT / 2);
}

uint16_t ColorPickerButton::getColorX1(uint8_t c) {
  return getColorX(c & 0x07);
}

uint16_t ColorPickerButton::getColorX2(uint8_t c) {
  return getColorX((c & 0x07) + 1);
}


uint16_t ColorPickerButton::getColorY(uint8_t c) {
  return pickerY + (c >= (COLOR_COUNT / 2) ? pickerH / 2 : 0);
}


void ColorPickerButton::setActive(bool active) {
  isActive = active;
}
