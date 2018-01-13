//
// Created by indrek on 6.05.2017.
//

#include "ColorPickerButton.h"
#include "ArduinoIconApp.h"


void ColorPickerButton::init(uint16_t x, uint16_t y, uint8_t w, uint8_t h, Icon * icon) {

  button
      .setCallback(this, &ColorPickerButton::togglePalette)
      .init(x, y, w/2, h)
      .setToggle(true)
      .setIcon(icon);

  pickerButtonX = x;
  pickerButtonY = y;
  pickerButtonW = w;
  pickerButtonH = h;
}


void ColorPickerButton::setSelectedColor(RgbColor color) {
  selectedColor = color;
}


void ColorPickerButton::setActive(bool active) {
  button.setActive(active);
  isActive = active;
}


void ColorPickerButton::setOff() {
  button.setToggleStatus(false);
  button.draw();
}


bool ColorPickerButton::touch(uint16_t x, uint16_t y) {
  if (isActive && isInPickedColor(x, y)) {
    return true;
  } else {
    return false;
  }
}

void ColorPickerButton::hold(uint16_t x, uint16_t y) {
}

void ColorPickerButton::release(uint16_t x, uint16_t y) {
  if (isInPickedColor(x, y)) {
    UI->pickerView.resetColor(selectedColor);
    UI->pickerView.draw();
  }
}


bool ColorPickerButton::isInPickedColor(uint16_t x, uint16_t y) {
  uint8_t length = pickerButtonW / 2;
  return isTapIn(x, pickerButtonX + length, length) && isTapIn(y, pickerButtonY, pickerButtonH);
}


void ColorPickerButton::togglePalette() {
  if (UI->pickerView.getActiveButton() == this) {
    UI->showDrawingGrid();
  } else {
    UI->showColorPicker(this);
  }
}


void ColorPickerButton::colorSelected(RgbColor color, bool final) {
  selectedColor = color;
  drawPickedColor();
  (view->*callbackMethod)(color);
  if (final) {
    UI->activeIconColorUpdated();
  } else {
    UI->exampleView.updatePreview();
  }
}


void ColorPickerButton::draw() {
  if (isActive) {
    button.draw();
    drawPickedColor();
  } else {
    UI->tft.fillRect(pickerButtonX, pickerButtonY, pickerButtonW, pickerButtonH, COLOR_BLACK);
  }
}


void ColorPickerButton::drawPickedColor() {
  uint8_t length = pickerButtonW / 2;
  UI->tft.fillRect(pickerButtonX + length, pickerButtonY, length, pickerButtonH, selectedColor.colorCode);
}





