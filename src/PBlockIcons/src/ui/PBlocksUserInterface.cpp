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

  copyActiveIconTo(undoBuffer[undoStart]);
}



void PBlocksUserInterface::draw() {
  if (calibration.isActive) {
    calibration.draw();
  } else {
    drawingGrid.draw();
    pickerView.draw();
    exampleView.draw();
    tools.draw();
  }
}

void PBlocksUserInterface::activeIconReloaded() {
  refreshUpdatedActiveIcon(true, true, true);
  saveActiveIconToUndoBuffer();
}

void PBlocksUserInterface::activeIconPixelsUpdated() {
  refreshUpdatedActiveIcon(true, false, false);
  saveActiveIconToUndoBuffer();
}

void PBlocksUserInterface::activeIconBorderUpdated() {
  refreshUpdatedActiveIcon(false, true, false);
}

void PBlocksUserInterface::activeIconColorUpdated() {
  refreshUpdatedActiveIcon(false, false, true);
  saveActiveIconToUndoBuffer();
}



void PBlocksUserInterface::refreshUpdatedActiveIcon(bool pixels, bool border, bool colors) {
  if (!drawingGrid.isActive) {
    if (pixels || border) showDrawingGrid();
  } else {
    if (pixels) drawingGrid.drawPixels(false);
  }

  if (border) {
    exampleView.evaluateIconData();
    exampleView.draw();
  } else if (pixels || colors) {
    exampleView.updatePreview();
  }
}



void PBlocksUserInterface::saveActiveIconToUndoBuffer() {
  undoIndex++;
  if (undoIndex >= UNDO_BUFFER_DEPTH) undoIndex = 0;
  undoEnd = undoIndex;

  if (undoEnd == undoStart) {
    undoStart++;
    if (undoStart >= UNDO_BUFFER_DEPTH) undoStart = 0;
  }
  copyActiveIconTo(undoBuffer[undoEnd]);
  tools.checkUndoAndRedo(true);
}


void PBlocksUserInterface::undo() {
  if (undoIndex != undoStart) {
    if (undoIndex == 0) {
      undoIndex = UNDO_BUFFER_DEPTH - 1;
    } else {
      undoIndex--;
    }
    loadActiveIconFromUndoBuffer();
  }
}


void PBlocksUserInterface::redo() {
  if (undoIndex != undoEnd) {
    undoIndex++;
    if (undoIndex >= UNDO_BUFFER_DEPTH) undoIndex = 0;
    loadActiveIconFromUndoBuffer();
  }
}


void PBlocksUserInterface::loadActiveIconFromUndoBuffer() {
  uint8_t scale = exampleView.scale;
  uint8_t hasBorder = activeIcon.color.hasBorder;
  uint8_t hasBorder3d = activeIcon.color.hasBorder3d;
  setActiveIcon(undoBuffer[undoIndex]);
  exampleView.scale = scale;
  activeIcon.color.hasBorder = hasBorder;
  activeIcon.color.hasBorder3d = hasBorder3d;

  tools.checkUndoAndRedo(true);
  refreshUpdatedActiveIcon(true, true, true);
}



bool PBlocksUserInterface::isUndoAvailable() {
  return undoIndex != undoStart;
}



bool PBlocksUserInterface::isRedoAvailable() {
  return undoIndex != undoEnd;
}



void PBlocksUserInterface::setActiveIcon(IconStorageData & data) {
  IconColor color = UI->activeIcon.color;
  for (uint8_t i=0; i<Icon::BITMAP_HEIGHT; i++) {
    UI->activeIcon.bitmap[i] = data.bitmap[i];
  }
  UI->activeIcon.color = color;
  UI->activeIcon.color.hasBorder = data.hasBorder;
  UI->activeIcon.color.hasBorder3d = data.is3d;
  UI->exampleView.setScale(data.scale);
  COLOR_foreground = data.foregroundColor;
  COLOR_background = data.backgroundColor;
  COLOR_border = data.borderColor;
}


void PBlocksUserInterface::copyActiveIconTo(IconStorageData & data) {
  for (uint8_t i=0; i<Icon::BITMAP_HEIGHT; i++) {
    data.bitmap[i] = UI->activeIcon.bitmap[i];
  }
  data.hasBorder = UI->activeIcon.color.hasBorder;
  data.is3d = UI->activeIcon.color.hasBorder3d;
  data.foregroundColor = COLOR_foreground;
  data.backgroundColor = COLOR_background;
  data.borderColor = COLOR_border;
  data.scale = UI->exampleView.scale;
}



void PBlocksUserInterface::showDrawingGrid() {
  drawingGrid.setActive(true);
  pickerView.deactivate();
  drawingGrid.draw();
}


void PBlocksUserInterface::showColorPicker(ColorPickerButton * button) {
  drawingGrid.setActive(false);
  pickerView.setActive(button);
  pickerView.draw();
}



void PBlocksUserInterface::run() {
  touchHandler.check();
}


