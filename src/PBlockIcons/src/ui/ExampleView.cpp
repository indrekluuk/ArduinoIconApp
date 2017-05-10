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
  toggle3DButton
      .setCallback(this, &ExampleView::toggle3d)
      .init(BUTTONS_X, BUTTONS_Y + buttonH, buttonW, buttonH)
      .setLabel("3D");
  toggleBorderButton
      .setCallback(this, &ExampleView::toggleBorder)
      .init(BUTTONS_X + buttonW, BUTTONS_Y + buttonH, buttonW, buttonH)
      .setIcon(&iconBorder);

  uint8_t pickerH = PICKERS_H / 3;
  bgColorPicker.init(PICKERS_X, PICKERS_Y + GAP, PICKERS_W, pickerH - GAP);
  fgColorPicker.init(PICKERS_X, PICKERS_Y + pickerH + GAP, PICKERS_W, pickerH - GAP);
  bColorPicker.init(PICKERS_X, PICKERS_Y + PICKERS_H - pickerH + GAP, PICKERS_W, pickerH - GAP);
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


void ExampleView::toggle3d() {
  is3D = !is3D;
  hasBorder = false;
  bColorPicker.setActive(false);
  bColorPicker.draw();
  reDrawExamples();
}


void ExampleView::toggleBorder() {
  hasBorder = !hasBorder;
  is3D = false;
  bColorPicker.setActive(hasBorder);
  bColorPicker.draw();
  reDrawExamples();
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
    toggle3DButton.draw();
    toggleBorderButton.draw();
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

