//
// Created by indrek on 17.05.2017.
//

#include "ColorPickerBrightnessBar.h"
#include "PBlocksUserInterface.h"



void ColorPickerBrightnessBar::setActive(bool active) {
  this->active = active;
}

bool ColorPickerBrightnessBar::isActive() {
  return active;
}



bool ColorPickerBrightnessBar::touch(uint16_t x, uint16_t y) {
  if (active && isTapIn(x, barX, BAR_COLOR_W * BAR_SCALE_W) && isTapIn(y, barY, BAR_COLOR_H * BAR_SCALE_H)) {
    return true;
  } else {
    return false;
  }
}

void ColorPickerBrightnessBar::hold(uint16_t x, uint16_t y) {
  colorSelected(x, y, false);
}

void ColorPickerBrightnessBar::release(uint16_t x, uint16_t y) {
  colorSelected(x, y, true);
}


void ColorPickerBrightnessBar::colorSelected(uint16_t x, uint16_t y, bool final) {
  int16_t pickerX = (int16_t)x - barX;
  int16_t pickerY = (int16_t)y - barY;
  if (pickerX < 0) pickerX = 0;
  if (pickerY < 0) pickerY = 0;
  if (pickerX >= BAR_COLOR_W * BAR_SCALE_W) pickerX = BAR_COLOR_W * BAR_SCALE_W - 1;
  if (pickerY >= BAR_COLOR_H * BAR_SCALE_H) pickerY = BAR_COLOR_H * BAR_SCALE_H - 1;
  brightnessBarGenerator.generateLine(pickerY / BAR_SCALE_H);
  pickerView.colorSelected(brightnessBarGenerator.getPixel(pickerX / BAR_SCALE_W));

  if (final) {
    pickerView.palette.paletteGenerator.setValue(
        brightnessBarGenerator.getValue(pickerY / BAR_SCALE_H));
    pickerView.palette.draw();
  }
}




void ColorPickerBrightnessBar::draw() {
  TFT & tft = UI->tft;
  tft.drawPalette(barX, barY, brightnessBarGenerator, BAR_SCALE_W, BAR_SCALE_H);
}


