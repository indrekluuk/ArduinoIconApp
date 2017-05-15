//
// Created by indrek on 25.03.2017.
//


#include "PBlocksUserInterface.h"



PBlocksUserInterface * UI;



PBlocksUserInterface::PBlocksUserInterface() {
  UI = this;
  activeIcon.color.setForegroundColor(Palette::ICON_COLOR_FOREGROUND);
  activeIcon.color.setBackgroundColor(Palette::ICON_COLOR_BACKGROUND);
  activeIcon.color.setBorderColor(Palette::ICON_COLOR_BORDER);
  activeIcon.color.setNoBorder();
}


void PBlocksUserInterface::init() {
  tft.begin(0x9488);
  tft.setRotation(1);
  tft.fillScreen(COLOR_BLACK);

  drawingGrid.init();
  exampleView.init();
  tools.init();
  touchHandler.init((uint16_t)tft.width(), (uint16_t)tft.height());

}



void PBlocksUserInterface::draw() {
  drawingGrid.draw();
  pickerView.draw();
  exampleView.draw();
  tools.draw();
}



void PBlocksUserInterface::iconUpdated(bool pixels, bool border, bool colors) {

  if (!drawingGrid.isActive && (pixels || border)) {
    showDrawingGrid();
  } else if (pixels) {
    drawingGrid.draw();
  }

  if (border) {
    exampleView.evaluateIconData();
    exampleView.draw();
  } else if (pixels || colors) {
    exampleView.updatePreview();
  }
}


void PBlocksUserInterface::showDrawingGrid() {
  drawingGrid.setActive(true);
  pickerView.deactivate();
  drawingGrid.draw();
}


void PBlocksUserInterface::showColorPicker(ColorPickerButton * button) {
  bool isRedraw = pickerView.getActiveButton() == nullptr;
  drawingGrid.setActive(false);
  pickerView.setActive(button);
  if (isRedraw) {
    pickerView.draw();
  }
}



void PBlocksUserInterface::run() {
  touchHandler.check();
}


