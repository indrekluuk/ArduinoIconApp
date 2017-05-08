//
// Created by indrek on 6.05.2017.
//

#include "ColorPicker.h"
#include "PBlocksUserInterface.h"


void ColorPicker::init(uint16_t x, uint16_t y, uint8_t w, uint8_t h) {
  pickerX = x;
  pickerY = y;
  pickerW = w;
  pickerH = h;
}






bool ColorPicker::tap(uint16_t x, uint16_t y, bool hold) {
  if (!isActive) {
    return false;
  }

  if (isTapBetween(x, pickerX, pickerX + pickerW) && isTapBetween(y, pickerY, pickerY + pickerH)) {
    for (uint8_t c = 0; c<COLOR_COUNT; c++) {
      uint16_t cX = getColorX2(c);
      uint16_t cY = getColorY(c) + (pickerH / 2);
      if (x < cX && y < cY) {
        (view->*callbackMethod)((Palette)c);
        break;
      }
    }
    return true;
  }
  return false;
}



void ColorPicker::draw() {
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



uint16_t ColorPicker::getColorX(uint8_t c) {
  return pickerX + ((uint16_t)pickerW) * ((uint16_t)c) / ((uint16_t)COLOR_COUNT / 2);
}

uint16_t ColorPicker::getColorX1(uint8_t c) {
  return getColorX(c & 0x07);
}

uint16_t ColorPicker::getColorX2(uint8_t c) {
  return getColorX((c & 0x07) + 1);
}


uint16_t ColorPicker::getColorY(uint8_t c) {
  return pickerY + (c >= (COLOR_COUNT / 2) ? pickerH / 2 : 0);
}


void ColorPicker::setActive(bool active) {
  isActive = active;
}
