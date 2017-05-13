//
// Created by indrek on 13.05.2017.
//

#include "ColorPickerPalette.h"
#include "PBlocksUserInterface.h"



void ColorPickerPalette::setActive(bool active) {
  this->active = active;
}

bool ColorPickerPalette::isActive() {
  return active;
}



bool ColorPickerPalette::touch(uint16_t x, uint16_t y) {
  if (active && isTapIn(x, paletteX, generator.getWidth()) && isTapIn(y, paletteY, generator.getHeight())) {
    return true;
  } else {
    return false;
  }
}

void ColorPickerPalette::hold(uint16_t x, uint16_t y) {
  int16_t pickerX = (int16_t)x - paletteX;
  int16_t pickerY = (int16_t)y - paletteY;
  if (pickerX < 0) pickerX = 0;
  if (pickerY < 0) pickerY = 0;
  if (pickerX >= (int16_t)generator.getWidth()) pickerX = generator.getWidth() - 1;
  if (pickerY >= (int16_t)generator.getHeight()) pickerY = generator.getHeight() - 1;
  generator.reset(pickerX, pickerY);
  RgbColor color = generator.nextPixel();

  TFT & tft = UI->tft;
  tft.setCursor(paletteX+100, paletteY + generator.getHeight() + 4);
  tft.setTextSize(1);
  tft.print((int)color.colorR);
  tft.print(" ");
  tft.print((int)color.colorG);
  tft.print(" ");
  tft.print((int)color.colorB);
  tft.print("                     ");
}

void ColorPickerPalette::release(uint16_t x, uint16_t y) {

}





void ColorPickerPalette::draw(bool redrawAll) {
  if (redrawAll) {
    TFT & tft = UI->tft;
    uint32_t time = millis();

    tft.drawPalette(paletteX, paletteY, generator);

    tft.setCursor(paletteX, paletteY + generator.getHeight() + 4);
    tft.setTextSize(1);
    tft.print(millis() - time);
    tft.print(" ms        ");
  }
}





