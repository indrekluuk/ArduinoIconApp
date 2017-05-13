//
// Created by indrek on 10.05.2017.
//

#include "ColorPickerView.h"
#include "PBlocksUserInterface.h"


void ColorPickerView::setActive(bool active) {
  palette.setActive(active);
  this->active = active;
}

bool ColorPickerView::isActive() {
  return active;
}



void ColorPickerView::draw() {
  if (!active) {
    return;
  }
  TFT & tft = UI->tft;

  uint32_t time = millis();

  palette.draw();

  tft.setCursor(PICKER_X, PICKER_Y + PICKER_H + 2);
  tft.setTextSize(1);
  tft.print(millis() - time);
  tft.print(" ms        ");
}

