//
// Created by indrek on 10.05.2017.
//

#include "ColorPickerView.h"
#include "PBlocksUserInterface.h"


void ColorPickerView::setActive(bool active, ColorPickerButton * button, CallbackMethod callback) {
  palette.setActive(active);
  activeButton = button;
  activeButtonCallback = callback;
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

  tft.fillRect(PICKER_X, PICKER_Y, PICKER_W, PICKER_H, COLOR_BLACK);
  palette.draw();


  tft.setCursor(PICKER_X, PICKER_Y + PICKER_H + 2);
  tft.setTextSize(1);
  tft.print(millis() - time);
  tft.print(" ms        ");
}




void ColorPickerView::colorSelected(RgbColor color) {

  TFT & tft = UI->tft;
  tft.setCursor(PICKER_X + 100, PICKER_Y + PICKER_H + 2);
  tft.setTextSize(1);
  tft.print((int)color.colorR);
  tft.print(" ");
  tft.print((int)color.colorG);
  tft.print(" ");
  tft.print((int)color.colorB);
  tft.print("                     ");

  if (activeButton != nullptr) {
    (activeButton->*activeButtonCallback)(color);
  }
}

