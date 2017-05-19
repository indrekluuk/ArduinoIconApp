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
  if (active && isTapIn(x, paletteX, PALETTE_COLOR_W * PALETTE_SCALE_W)
      && isTapIn(y, paletteY, PALETTE_COLOR_H * PALETTE_SCALE_H)) {
    return true;
  } else {
    return false;
  }
}

void ColorPickerPalette::hold(uint16_t x, uint16_t y) {
  colorSelected(x, y);
}

void ColorPickerPalette::release(uint16_t x, uint16_t y) {
}




void ColorPickerPalette::colorSelected(uint16_t x, uint16_t y) {
  int16_t pickerX = (int16_t)x - paletteX;
  int16_t pickerY = (int16_t)y - paletteY;
  if (pickerX < 0) pickerX = 0;
  if (pickerY < 0) pickerY = 0;
  if (pickerX >= PALETTE_COLOR_W * PALETTE_SCALE_W) pickerX = PALETTE_COLOR_W * PALETTE_SCALE_W - 1;
  if (pickerY >= PALETTE_COLOR_H * PALETTE_SCALE_H) pickerY = PALETTE_COLOR_H * PALETTE_SCALE_H - 1;

  pickerView.brightnessBar.brightnessBarGenerator.setHue(
      paletteGenerator.getHue(pickerY / PALETTE_SCALE_H));
  pickerView.brightnessBar.brightnessBarGenerator.setSaturation(
      paletteGenerator.getSaturation(pickerX / PALETTE_SCALE_W));
  pickerView.brightnessBar.draw();

  paletteGenerator.generateLine(pickerY / PALETTE_SCALE_H);
  pickerView.colorSelected(paletteGenerator.getPixel(pickerX / PALETTE_SCALE_W));
}




void ColorPickerPalette::draw() {
  TFT & tft = UI->tft;
  tft.drawPalette(paletteX, paletteY, paletteGenerator, PALETTE_SCALE_W, PALETTE_SCALE_H);
}





