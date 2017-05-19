//
// Created by indrek on 10.05.2017.
//

#include "ColorPickerView.h"
#include "PBlocksUserInterface.h"
#include "src/palette/RgbToHsv.h"


void ColorPickerView::setActive(ColorPickerButton * button) {
  deactivate();
  palette.setActive(true);
  brightnessBar.setActive(true);

  RgbToHsv hsv(button->selectedColor);
  brightnessBar.brightnessBarGenerator.setHue(hsv.H);
  brightnessBar.brightnessBarGenerator.setSaturation(hsv.S);
  palette.paletteGenerator.setValue(hsv.V);

  activeButton = button;
}

void ColorPickerView::deactivate() {
  if (activeButton) {
    activeButton->setOff();
  }
  palette.setActive(false);
  brightnessBar.setActive(false);
  activeButton = nullptr;
}

ColorPickerButton * ColorPickerView::getActiveButton() {
  return activeButton;
}



void ColorPickerView::draw() {
  if (activeButton == nullptr) {
    return;
  }
  TFT & tft = UI->tft;

  uint32_t time = millis();

  tft.fillRect(PICKER_X, PICKER_Y, PICKER_W, PICKER_H, COLOR_BLACK);
  palette.draw();
  brightnessBar.draw();


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
    activeButton->colorSelected(color);
  }
}

