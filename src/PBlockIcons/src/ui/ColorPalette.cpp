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
  if (active) {
    return false;
  } else {
    return false;
  }
}

void ColorPalette::hold(uint16_t x, uint16_t y) {

}

void ColorPalette::release(uint16_t x, uint16_t y) {

}



void ColorPalette::draw(bool redrawAll) {
  if (!active) {
    return;
  }

  if (redrawAll) {
    TFT & tft = UI->tft;
    tft.drawPalette(PALETTE_X + 1, PALETTE_Y + 1, PALETTE_W - 2, PALETTE_H - 2);
  }
}

