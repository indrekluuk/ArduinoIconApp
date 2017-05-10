//
// Created by indrek on 6.05.2017.
//

#include "ExampleView.h"


#include "PBlocksUserInterface.h"
#include "src/icons/Icon.h"





void ExampleView::init() {

  uint8_t buttonW = BUTTONS_W / 2;
  uint8_t buttonH = BUTTONS_H / 2;

  scaleUpButton
      .setCallback(this, &ExampleView::scaleUp)
      .init(BUTTONS_X, BUTTONS_Y, buttonW, buttonH)
      .setIcon(&iconZoomIn);
  scaleDownButton
      .setCallback(this, &ExampleView::scaleDown)
      .init(BUTTONS_X + buttonW, BUTTONS_Y, buttonW, buttonH)
      .setIcon(&iconZoomOut);

  showPaletteButton
      .setCallback(this, &ExampleView::togglePalette)
      .init(BUTTONS_X, BUTTONS_Y + buttonH, buttonW, buttonH)
      .setLabel("P");

  uint8_t pickerH = PICKERS_H / 3;
  bgColorPicker.init(PICKERS_X, PICKERS_Y + GAP, PICKERS_W, pickerH - GAP);
  fgColorPicker.init(PICKERS_X, PICKERS_Y + pickerH + GAP, PICKERS_W, pickerH - GAP);
  bColorPicker.init(PICKERS_X, PICKERS_Y + PICKERS_H - pickerH + GAP, PICKERS_W, pickerH - GAP);
}


bool ExampleView::tap(uint16_t x, uint16_t y, bool hold) {
  if (isTapIn(x, VIEW_X, VIEW_W) && isTapIn(y, VIEW_Y, VIEW_H)) {
    if (!hold) {
      nextBorderStyle();
    }
    return true;
  } else {
    return false;
  }
}



void ExampleView::nextBorderStyle() {
  if (!is3D && !hasBorder) {
    hasBorder = true;
  } else if (hasBorder) {
    hasBorder = false;
    is3D = true;
  } else {
    hasBorder = false;
    is3D = false;
  }
  bColorPicker.setActive(hasBorder);
  bColorPicker.draw();
  reDrawExamples();
}



void ExampleView::togglePalette() {
  if (UI->palette.isActive()) {
    UI->drawingGrid.setActive(true);
    UI->palette.setActive(false);
    UI->drawingGrid.draw(true);
  } else {
    UI->drawingGrid.setActive(false);
    UI->palette.setActive(true);
    UI->palette.draw(true);
  }
}


void ExampleView::scaleUp() {
  if ((scale+1)*16 <= VIEW_W) {
    scale++;
    reDrawExamples();
    printScale();
  };
}


void ExampleView::scaleDown() {
  if (scale > 1) {
    scale--;
    reDrawExamples();
    printScale();
  };
}


void ExampleView::setBackgroundColor(Palette c) {
  bgColor = c;
  reDrawExamples();
}


void ExampleView::setForegroundColor(Palette c) {
  fgColor = c;
  reDrawExamples();
}


void ExampleView::setBorderColor(Palette c) {
  bColor = c;
  reDrawExamples();
}



void ExampleView::draw(bool redrawAll) {
  if (redrawAll) {
    reDrawExamples();
    scaleUpButton.draw();
    scaleDownButton.draw();
    showPaletteButton.draw();
    bgColorPicker.draw();
    fgColorPicker.draw();
    bColorPicker.setActive(hasBorder);
    bColorPicker.draw();
    printScale();
  }
}



void ExampleView::reDrawExamples() {
  IconColor color = UI->activeIcon.getColor();
  color.setBackgroundColor(Palette::DARK_GREEN);
  if (is3D) {
    color.setBorder3d();
  } else if (hasBorder) {
    color.setBorderColor(bColor);
  }
  color.setBackgroundColor(bgColor);
  color.setForegroundColor(fgColor);
  UI->tft.drawIcon(VIEW_X, VIEW_Y, UI->activeIcon, color, VIEW_W, VIEW_H, 0, 0, scale, scale);
}

void ExampleView::printScale() {
  UI->tft.setTextColor(COLOR_WHITE, COLOR_BLACK);
  UI->tft.setTextSize(1);
  UI->tft.setCursor(5, 5);
  UI->tft.print((int)scale);
}

