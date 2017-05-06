//
// Created by indrek on 6.05.2017.
//

#include "ExampleView.h"


#include "PBlocksUserInterface.h"
#include "src/icons/Icon.h"





void ExampleView::init() {

  uint8_t buttonW = SCALE_BUTTONS_W / 2;
  scaleUpButton.init(SCALE_BUTTONS_X, SCALE_BUTTONS_Y, buttonW, SCALE_BUTTONS_H, "+");
  scaleDownButton.init(SCALE_BUTTONS_X + buttonW, SCALE_BUTTONS_Y, buttonW, SCALE_BUTTONS_H, "-");
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



void ExampleView::draw(bool redrawAll) {
  if (redrawAll) {
    reDrawExamples();
    scaleUpButton.draw();
    scaleDownButton.draw();
    printScale();
  }
}



void ExampleView::reDrawExamples() {
  IconColor color = UI->activeIcon.getColor();
  color.setBackgroundColor(Palette::DARK_GREEN);
  UI->tft.drawIcon(VIEW_X, VIEW_Y, UI->activeIcon, color, VIEW_W, VIEW_H, 0, 0, scale, scale);
}

void ExampleView::printScale() {
  UI->tft.setTextColor(COLOR_WHITE, COLOR_BLACK);
  UI->tft.setTextSize(2);
  UI->tft.setCursor(0, 0);
  UI->tft.print((int)scale);
}

