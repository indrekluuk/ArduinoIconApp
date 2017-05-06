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
  if (isTapBetween(x, pickerX, pickerX + pickerW) && isTapBetween(y, pickerY, pickerY + pickerH)) {
    for (uint8_t c = 0; c<COLOR_COUNT; c++) {
      uint16_t cX = getColorX(c+1);
      if (x < cX) {
        (view->*callbackMethod)((Palette)c);
        break;
      }
    }
    return true;
  }
  return false;
}



void ColorPicker::draw() {
  for (uint8_t c=0; c<COLOR_COUNT; c++) {
    uint16_t x = getColorX(c);
    uint16_t w = getColorX(c+1) - x;
    UI->tft.fillRect(pickerX + x, pickerY, w, pickerH, RgbColor((Palette)c).colorCode);
  }
}



uint16_t ColorPicker::getColorX(uint8_t c) {
  return ((uint16_t)pickerW) * ((uint16_t)c) / ((uint16_t)COLOR_COUNT);
}




