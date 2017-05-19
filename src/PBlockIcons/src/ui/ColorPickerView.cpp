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
  activeButton = button;
  resetColor(button->selectedColor);
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

  tft.setTextSize(1);
  tft.setTextColor(COLOR_WHITE, COLOR_BLACK);
  tft.setCursor(PICKER_X, PICKER_Y + PICKER_H + 4);
  setCursor(0);
  tft.print("24bit:");
  setCursor(16);
  tft.print("16bit:");

  tft.drawRect(PICKER_X, PICKER_Y, PICKER_W, PICKER_H, COLOR_BLACK);
  brightnessBar.draw();
  tft.fillRect(
      BAR_X + ColorPickerBrightnessBar::BAR_W,
      PICKER_Y + 1,
      PALETTE_X - BAR_X - ColorPickerBrightnessBar::BAR_W,
      PICKER_H - 2,
      COLOR_BLACK);
  palette.draw();
}


void ColorPickerView::resetColor(RgbColor color) {
  RgbToHsv hsv(color);
  brightnessBar.brightnessBarGenerator.setHue(hsv.H);
  brightnessBar.brightnessBarGenerator.setSaturation(hsv.S);
  palette.paletteGenerator.setValue(hsv.V);
  colorSelected(color);
}



void ColorPickerView::colorSelected(RgbColor color) {
  if (activeButton != nullptr) {

    uint32_t color24bit =
        ((((uint32_t)color.colorR)*255/31) << 16)
        | ((((uint32_t)color.colorG)*255/63) << 8)
        | ((((uint32_t)color.colorB)*255/31));

    TFT & tft = UI->tft;
    tft.setTextSize(1);
    tft.setTextColor(COLOR_WHITE, COLOR_BLACK);
    printColorCode(7, 6, color24bit);
    printColorCode(23, 4, color.colorCode);

    activeButton->colorSelected(color);
  }
}


void ColorPickerView::setCursor(uint8_t at) {
  UI->tft.setCursor(PICKER_X + at*6, PICKER_Y + PICKER_H + 4);
};

void ColorPickerView::printColorCode(uint8_t at, uint8_t cnt, uint32_t code) {
  setCursor(at);
  TFT & tft = UI->tft;
  while ((cnt > 1) && (code < ((uint32_t)1 << ((cnt-1)*4)))) {
    tft.print("0");
    cnt --;
  }
  tft.print(code, HEX);
}


