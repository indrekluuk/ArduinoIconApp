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

  loadActiveIcon(undoBuffer[undoStart]);
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



void PBlocksUserInterface::iconUpdated(bool pixels, bool border, bool colors, bool updatePreviewOnly, bool saveUndo) {
  refreshUpdatedIcon(pixels, border, colors, updatePreviewOnly);
  if (saveUndo && (pixels || colors)) {
    saveToUndoBuffer();
  }
}



void PBlocksUserInterface::refreshUpdatedIcon(bool pixels, bool border, bool colors, bool updatePreviewOnly) {
  if (!updatePreviewOnly) {
    if (!drawingGrid.isActive && (pixels || border)) {
      showDrawingGrid();
    } else if (pixels) {
      drawingGrid.draw();
    }
  }

  if (border) {
    exampleView.evaluateIconData();
    exampleView.draw();
  } else if (pixels || colors) {
    exampleView.updatePreview();
  }
}



void PBlocksUserInterface::saveToUndoBuffer() {
  undoIndex++;
  if (undoIndex >= UNDO_BUFFER_DEPTH) undoIndex = 0;
  undoEnd = undoIndex;

  if (undoEnd == undoStart) {
    undoStart++;
    if (undoStart >= UNDO_BUFFER_DEPTH) undoStart = 0;
  }
  loadActiveIcon(undoBuffer[undoEnd]);
}


void PBlocksUserInterface::undo() {
  if (undoIndex != undoStart) {
    if (undoIndex == 0) {
      undoIndex = UNDO_BUFFER_DEPTH - 1;
    } else {
      undoIndex--;
    }
    loadFromUndoBuffer();
  }
}


void PBlocksUserInterface::redo() {
  if (undoIndex != undoEnd) {
    undoIndex++;
    if (undoIndex >= UNDO_BUFFER_DEPTH) undoIndex = 0;
    loadFromUndoBuffer();
  }
}


void PBlocksUserInterface::loadFromUndoBuffer() {
  uint8_t scale = exampleView.scale;
  uint8_t hasBorder = activeIcon.color.hasBorder;
  uint8_t hasBorder3d = activeIcon.color.hasBorder3d;
  setActiveIcon(undoBuffer[undoIndex]);
  exampleView.scale = scale;
  activeIcon.color.hasBorder = hasBorder;
  activeIcon.color.hasBorder3d = hasBorder3d;
  refreshUpdatedIcon(true, true, true, false);
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


void PBlocksUserInterface::loadActiveIcon(IconStorageData & data) {
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


