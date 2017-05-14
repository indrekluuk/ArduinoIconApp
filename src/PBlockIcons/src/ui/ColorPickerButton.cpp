//
// Created by indrek on 6.05.2017.
//

#include "ColorPickerButton.h"
#include "PBlocksUserInterface.h"


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



void ColorPickerButton::setActive(bool active) {
  button.setActive(active);
  isActive = active;
}


void ColorPickerButton::setOff() {
  button.setOff();
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
    UI->pickerView.colorSelected(selectedColor, true);
  }
}


bool ColorPickerButton::isInPickedColor(uint16_t x, uint16_t y) {
  uint8_t length = pickerButtonW / 2;
  return isTapIn(x, pickerButtonX + length, length) && isTapIn(y, pickerButtonY, pickerButtonH);
}


void ColorPickerButton::togglePalette() {
  ColorPickerView & pickerView = UI->pickerView;
  DrawingGrid & drawingGrid = UI->drawingGrid;

  if (pickerView.getActiveButton() == this) {
    drawingGrid.setActive(true);
    pickerView.deactivate();
    drawingGrid.draw();
  } else {
    bool isRedraw = pickerView.getActiveButton() == nullptr;
    drawingGrid.setActive(false);
    pickerView.setActive(this, &ColorPickerButton::colorSelected);
    if (isRedraw) {
      pickerView.draw();
    }
  }
}


void ColorPickerButton::colorSelected(RgbColor color, bool isFinal) {
  selectedColor = color;
  drawPickedColor();
  if (isFinal) {
    (view->*callbackMethod)(color);
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





