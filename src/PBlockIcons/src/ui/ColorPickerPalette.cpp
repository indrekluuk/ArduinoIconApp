//
// Created by indrek on 13.05.2017.
//

#include "ColorPickerPalette.h"
#include "ColorPickerView.h"
#include "PBlocksUserInterface.h"



void ColorPickerPalette::setActive(bool active) {
  this->active = active;
}

bool ColorPickerPalette::isActive() {
  return active;
}



bool ColorPickerPalette::touch(uint16_t x, uint16_t y) {
  if (active && isTapIn(x, paletteX, PALETTE_W * PALETTE_SCALE_W) && isTapIn(y, paletteY, PALETTE_H * PALETTE_SCALE_H)) {
    return true;
  } else {
    return false;
  }
}

void ColorPickerPalette::hold(uint16_t x, uint16_t y) {
  pickerView.colorSelected(getSelectedColor(x, y), false);
}

void ColorPickerPalette::release(uint16_t x, uint16_t y) {
  //pickerView.colorSelected(getSelectedColor(x, y), true);
}


RgbColor ColorPickerPalette::getSelectedColor(uint16_t x, uint16_t y) {
  int16_t pickerX = (int16_t)x - paletteX;
  int16_t pickerY = (int16_t)y - paletteY;
  if (pickerX < 0) pickerX = 0;
  if (pickerY < 0) pickerY = 0;
  if (pickerX >= PALETTE_W * PALETTE_SCALE_W) pickerX = PALETTE_W * PALETTE_SCALE_W - 1;
  if (pickerY >= PALETTE_H * PALETTE_SCALE_H) pickerY = PALETTE_H * PALETTE_SCALE_H - 1;
  generator.reset(pickerY / PALETTE_SCALE_H);
  return generator.getPixel(pickerX / PALETTE_SCALE_W);
}




void ColorPickerPalette::draw() {
  TFT & tft = UI->tft;
  uint32_t time = millis();

  tft.drawPalette(paletteX, paletteY, generator, PALETTE_SCALE_W, PALETTE_SCALE_H);

  tft.setCursor(paletteX, paletteY + PALETTE_H * PALETTE_SCALE_H + 4);
  tft.setTextSize(1);
  tft.print(millis() - time);
  tft.print(" ms        ");
}





