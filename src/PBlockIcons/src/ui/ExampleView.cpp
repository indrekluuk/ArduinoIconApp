//
// Created by indrek on 6.05.2017.
//

#include "ExampleView.h"


#include "PBlocksUserInterface.h"
#include "src/icons/Icon.h"
#include "DrawingGrid.h"




void ExampleView::init() {

}



bool ExampleView::tap(uint16_t x, uint16_t y, bool hold) {

}


void ExampleView::draw(bool redrawAll) {
  reDrawExamples();
}



void ExampleView::reDrawExamples() {
  uint8_t size = 2;
  IconColor color = UI->activeIcon.getColor();
  color.setBackgroundColor(Palette::DARK_GREEN);
  UI->tft.drawIcon(0, DrawingGrid::GRID_Y, UI->activeIcon, color, DrawingGrid::GRID_X, DrawingGrid::GRID_X, 0, 0, size, size);
}


