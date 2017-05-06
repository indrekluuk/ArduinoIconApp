//
// Created by indrek on 6.05.2017.
//

#include "ExampleView.h"


#include "PBlocksUserInterface.h"
#include "src/icons/Icon.h"





void ExampleView::init() {

  uint8_t buttonW = BUTTONS_W / 2;
  uint8_t buttonH = BUTTONS_H / 2;
  scaleUpButton.init(BUTTONS_X, BUTTONS_Y, buttonW, buttonH, "+");
  scaleDownButton.init(BUTTONS_X + buttonW, BUTTONS_Y, buttonW, buttonH, "-");
  toggle3DButton.init(BUTTONS_X, BUTTONS_Y + buttonH, buttonW, buttonH, "3d");
  toggleBorderButton.init(BUTTONS_X + buttonW, BUTTONS_Y + buttonH, buttonW, buttonH, "O");
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
  reDrawExamples();
}


void ExampleView::toggleBorder() {
  hasBorder = !hasBorder;
  is3D = false;
  reDrawExamples();
}




void ExampleView::draw(bool redrawAll) {
  if (redrawAll) {
    reDrawExamples();
    scaleUpButton.draw();
    scaleDownButton.draw();
    toggle3DButton.draw();
    toggleBorderButton.draw();
    printScale();
  }
}



void ExampleView::reDrawExamples() {
  IconColor color = UI->activeIcon.getColor();
  color.setBackgroundColor(Palette::DARK_GREEN);
  if (is3D) {
    color.setBorder3d();
  } else if (hasBorder) {
    color.setBorderColor(Palette::BLACK);
  }
  UI->tft.drawIcon(VIEW_X, VIEW_Y, UI->activeIcon, color, VIEW_W, VIEW_H, 0, 0, scale, scale);
}

void ExampleView::printScale() {
  UI->tft.setTextColor(COLOR_WHITE, COLOR_BLACK);
  UI->tft.setTextSize(1);
  UI->tft.setCursor(5, 5);
  UI->tft.print((int)scale);
}

