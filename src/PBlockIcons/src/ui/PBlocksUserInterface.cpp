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
  bool isReDrawGrid = false;
  bool isReDrawExampleView = false;
  bool isUpdatePreview = false;

  if (pixels || border) {
    if (!drawingGrid.isActive) {
      pickerView.deactivate();
      drawingGrid.setActive(true);
      isReDrawGrid = true;
    }
  }
  if (pixels) {
    isReDrawGrid = true;
  }

  if (border) {
    exampleView.evaluateIconData();
    isReDrawExampleView = true;
  } else if (pixels || colors) {
    isUpdatePreview = true;
  }

  if (isReDrawGrid) {
    drawingGrid.draw();
  }
  if (isReDrawExampleView) {
    exampleView.draw();
  } else if (isUpdatePreview) {
    exampleView.updatePreview();
  }
}



void PBlocksUserInterface::run() {
  touchHandler.check();
}


