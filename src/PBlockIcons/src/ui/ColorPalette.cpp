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


bool ColorPalette::tap(uint16_t x, uint16_t y, bool hold) {
  if (!active) {
    return false;
  }

  return false;
}


void ColorPalette::draw(bool redrawAll) {
  if (!active) {
    return;
  }

  if (redrawAll) {
    TFT & tft = UI->tft;
    tft.fillRect(PALETTE_X + 1, PALETTE_Y + 1, PALETTE_W - 2, PALETTE_H - 2, COLOR_RED);
  }
}

