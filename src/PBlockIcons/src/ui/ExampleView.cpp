//
// Created by indrek on 6.05.2017.
//

#include "ExampleView.h"


#include "PBlocksUserInterface.h"


void ExampleView::init() {

  uint8_t buttonW = BUTTONS_W / 2;
  uint8_t buttonH = BUTTONS_H / 2; //todo

  scaleUpButton
      .setCallback(this, &ExampleView::scaleUp)
      .init(BUTTONS_X, BUTTONS_Y, buttonW, buttonH)
      .setIcon(&iconZoomIn);
  scaleDownButton
      .setCallback(this, &ExampleView::scaleDown)
      .init(BUTTONS_X + buttonW, BUTTONS_Y, buttonW, buttonH)
      .setIcon(&iconZoomOut);

  foregroundColorButton
      .init(BUTTONS_X, BUTTONS_Y + buttonH, BUTTONS_W, buttonH, &iconForeground);
  backgroundColorButton
      .init(BUTTONS_X, BUTTONS_Y + buttonH * 2, BUTTONS_W, buttonH, &iconBackground);
  borderColorButton
      .init(BUTTONS_X, BUTTONS_Y + buttonH * 3, BUTTONS_W, buttonH, &iconBorder);

  borderColorButton.setActive(hasBorder);

}


bool ExampleView::touch(uint16_t x, uint16_t y) {
  if (isTouchOnView(x, y)) {
    nextBorderStyle();
    return true;
  } else {
    return false;
  }
}

void ExampleView::hold(uint16_t x, uint16_t y) {

}

void ExampleView::release(uint16_t x, uint16_t y) {

}

bool ExampleView::isTouchOnView(uint16_t x, uint16_t y) {
  return isTapIn(x, VIEW_X, VIEW_W) && isTapIn(y, VIEW_Y, VIEW_H);
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
  borderColorButton.setActive(hasBorder);
  borderColorButton.draw();
  reDrawExamples();
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



void ExampleView::setForegroundColor(RgbColor color) {
  COLOR_foreground = color.colorCode;
  UI->exampleView.draw();
}


void ExampleView::setBackgroundColor(RgbColor color) {
  COLOR_background = color.colorCode;
  UI->exampleView.draw();
}


void ExampleView::setBorderColor(RgbColor color) {
  COLOR_border = color.colorCode;
  UI->exampleView.draw();
}




void ExampleView::draw() {
  reDrawExamples();
  scaleUpButton.draw();
  scaleDownButton.draw();
  foregroundColorButton.draw();
  backgroundColorButton.draw();
  borderColorButton.draw();
  foregroundColorButton.draw();
  backgroundColorButton.draw();
  borderColorButton.draw();
  printScale();
}



void ExampleView::reDrawExamples() {
  IconColor color = UI->activeIcon.getColor();
  if (is3D) {
    color.setBorder3d();
  } else if (hasBorder) {
    color.setBorderColor(Palette::ICON_COLOR_BORDER);
  }
  UI->tft.drawIcon(VIEW_X, VIEW_Y, UI->activeIcon, color, VIEW_W, VIEW_H, 0, 0, scale, scale);
}

void ExampleView::printScale() {
  UI->tft.setTextColor(COLOR_WHITE, COLOR_BLACK);
  UI->tft.setTextSize(1);
  UI->tft.setCursor(5, 5);
  UI->tft.print((int)scale);
}

