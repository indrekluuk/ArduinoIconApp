//
// Created by indrek on 6.05.2017.
//

#include "ColorPickerButton.h"
#include "PBlocksUserInterface.h"


void ColorPickerButton::init(uint16_t x, uint16_t y, uint8_t w, uint8_t h, Icon * icon) {

  button
      .setCallback(this, &ColorPickerButton::togglePalette)
      .init(x, y, w/2, h)
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



bool ColorPickerButton::touch(uint16_t x, uint16_t y) {
  if (isActive) {
    return false;
  } else {
    return false;
  }
}

void ColorPickerButton::hold(uint16_t x, uint16_t y) {
}

void ColorPickerButton::release(uint16_t x, uint16_t y) {
}



void ColorPickerButton::togglePalette() {
  ColorPickerView & pickerView = UI->pickerView;
  DrawingGrid & drawingGrid = UI->drawingGrid;

  if (pickerView.isActive(this)) {
    drawingGrid.setActive(true);
    pickerView.deactivate();
    drawingGrid.draw();
  } else {
    drawingGrid.setActive(false);
    pickerView.setActive(this, &ColorPickerButton::colorSelected);
    pickerView.draw();
  }
}


void ColorPickerButton::colorSelected(RgbColor color) {
  (view->*callbackMethod)(color);
}


void ColorPickerButton::draw() {
  if (isActive) {
    button.draw();
  } else {
    UI->tft.fillRect(pickerButtonX, pickerButtonY, pickerButtonW, pickerButtonH, COLOR_BLACK);
  }
}



