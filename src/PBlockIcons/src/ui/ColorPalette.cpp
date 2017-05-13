//
// Created by indrek on 10.05.2017.
//

#include "ColorPalette.h"
#include "PBlocksUserInterface.h"


void ColorPalette::setActive(bool active) {
  this->active = active;
}

bool ColorPalette::isActive() {
  return active;
}

bool ColorPalette::touch(uint16_t x, uint16_t y) {
  if (active && isTapIn(x, PALETTE_X, PALETTE_W) && isTapIn(y, PALETTE_Y, PALETTE_H)) {
    return true;
  } else {
    return false;
  }
}

void ColorPalette::hold(uint16_t x, uint16_t y) {
  int16_t pickerX = (int16_t)x - (int16_t)PALETTE_X;
  int16_t pickerY = (int16_t)y - (int16_t)PALETTE_Y;
  if (pickerX < 0) pickerX = 0;
  if (pickerY < 0) pickerY = 0;
  if (pickerX >= (int16_t)generator.getWidth()) pickerX = generator.getWidth() - 1;
  if (pickerY >= (int16_t)generator.getHeight()) pickerY = generator.getHeight() - 1;
  generator.reset(pickerX, pickerY);
  RgbColor color = generator.nextPixel();

  TFT & tft = UI->tft;
  tft.setCursor(PALETTE_X+100, PALETTE_Y + PALETTE_H + 2);
  tft.setTextSize(1);
  tft.print((int)color.colorR);
  tft.print(" ");
  tft.print((int)color.colorG);
  tft.print(" ");
  tft.print((int)color.colorB);
  tft.print("                     ");
}

void ColorPalette::release(uint16_t x, uint16_t y) {

}



void ColorPalette::draw(bool redrawAll) {
  if (!active) {
    return;
  }

  if (redrawAll) {
    TFT & tft = UI->tft;
    uint32_t time = millis();

    tft.drawPalette(PALETTE_X + 1+1, PALETTE_Y + 1 + 1, generator);

    tft.setCursor(PALETTE_X, PALETTE_Y + PALETTE_H + 2);
    tft.setTextSize(1);
    tft.print(millis() - time);
    tft.print(" ms        ");

  }
}

