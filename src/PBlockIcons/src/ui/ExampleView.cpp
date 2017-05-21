//
// Created by indrek on 6.05.2017.
//

#include "ExampleView.h"


#include "PBlocksUserInterface.h"


void ExampleView::init() {

  uint8_t buttonW = BUTTONS_W / 2;

  uint16_t buttonY1 = BUTTONS_Y;
  uint16_t buttonY2 = BUTTONS_Y + BUTTONS_H * 1 / 4;
  scaleUpButton
      .setCallback(this, &ExampleView::scaleUp)
      .init(BUTTONS_X, buttonY1, buttonW, buttonY2 - buttonY1)
      .setIcon(&iconZoomIn);
  scaleDownButton
      .setCallback(this, &ExampleView::scaleDown)
      .init(BUTTONS_X + buttonW, buttonY1, buttonW, buttonY2 - buttonY1)
      .setIcon(&iconZoomOut);

  buttonY1 = buttonY2;
  buttonY2 = BUTTONS_Y + BUTTONS_H * 2 / 4;
  foregroundColorButton
      .init(BUTTONS_X, buttonY1, BUTTONS_W, buttonY2 - buttonY1, &iconForeground);
  buttonY1 = buttonY2;
  buttonY2 = BUTTONS_Y + BUTTONS_H * 3 / 4;
  backgroundColorButton
      .init(BUTTONS_X, buttonY1, BUTTONS_W, buttonY2 - buttonY1, &iconBackground);
  buttonY1 = buttonY2;
  buttonY2 = BUTTONS_Y + BUTTONS_H * 4 / 4;
  borderColorButton
      .init(BUTTONS_X, buttonY1, BUTTONS_W, buttonY2 - buttonY1, &iconBorder);

  evaluateIconData();
}


void ExampleView::evaluateIconData() {
  borderColorButton.setActive(UI->activeIcon.color.hasBorder && !UI->activeIcon.color.hasBorder3d);
  foregroundColorButton.setSelectedColor(COLOR_foreground);
  backgroundColorButton.setSelectedColor(COLOR_background);
  borderColorButton.setSelectedColor(COLOR_border);
}


bool ExampleView::touch(uint16_t x, uint16_t y) {
  if (isTouchOnView(x, y)) {
    UI->showDrawingGrid();
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



void ExampleView::scaleUp() {
  setScale(scale + 1);

}


void ExampleView::scaleDown() {
  setScale(scale - 1);

}


void ExampleView::setScale(uint8_t newScale) {
  if (newScale > MAX_SCALE) {
    scale = MAX_SCALE;
  } else if (newScale < 1) {
    scale = 1;
  } else {
    scale = newScale;
  }
  updatePreview();
  printScale();
}


void ExampleView::setForegroundColor(RgbColor color) {
  COLOR_foreground = color.colorCode;
  UI->iconUpdated(false, false, true);
}


void ExampleView::setBackgroundColor(RgbColor color) {
  COLOR_background = color.colorCode;
  UI->iconUpdated(false, false, true);
}


void ExampleView::setBorderColor(RgbColor color) {
  COLOR_border = color.colorCode;
  UI->iconUpdated(false, false, true);
}




void ExampleView::draw() {
  updatePreview();
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



void ExampleView::updatePreview() {
  IconColor color = UI->activeIcon.getColor();
  UI->tft.drawIcon(VIEW_X, VIEW_Y, UI->activeIcon, color, VIEW_W, VIEW_H, 0, 0, scale, scale);
}

void ExampleView::printScale() {
  UI->tft.setTextColor(COLOR_WHITE, COLOR_BLACK);
  UI->tft.setTextSize(1);
  UI->tft.setCursor(5, 5);
  UI->tft.print((int)scale);
}

