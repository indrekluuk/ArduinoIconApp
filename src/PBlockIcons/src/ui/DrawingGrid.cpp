//
// Created by indrek on 6.05.2017.
//

#include "DrawingGrid.h"
#include "PBlocksUserInterface.h"



void DrawingGrid::init() {

}



void DrawingGrid::setActive(bool active) {
  isActive = active;
}


bool DrawingGrid::touch(uint16_t x, uint16_t y) {
  if (isActive && isTouchOnGrid(x, y)) {
    uint8_t px = (x - GRID_X) / SIZE;
    uint8_t py = (y - GRID_Y) / SIZE;
    selectedColor = !(UI->activeIcon.bitmap[py] & getPixelMask(px));
    return true;
  } else {
    return false;
  }
}

void DrawingGrid::hold(uint16_t x, uint16_t y) {
  if (isTouchOnGrid(x, y)) {
    uint8_t px = (x - GRID_X) / SIZE;
    uint8_t py = (y - GRID_Y) / SIZE;
    setActiveIconPixel(px, py, selectedColor);
    drawPixel(px, py, false);
  }
}

void DrawingGrid::release(uint16_t x, uint16_t y) {
  UI->iconPixelsUpdated();
}


bool DrawingGrid::isTouchOnGrid(uint16_t x, uint16_t y) {
  return isTapIn(x, GRID_X, GRID_W - 1) && isTapIn(y, GRID_Y, GRID_H - 1);
}




void DrawingGrid::draw() {
  if (!isActive) {
    return;
  }

  UI->tft.fillRect(GRID_X, GRID_Y + GRID_H, GRID_W, SCREEN_HEIGHT - GRID_H - GRID_Y, COLOR_BLACK);
  drawGrid();
  drawPixels(true);
}


void DrawingGrid::drawPixels(bool forceRedrawAll) {
  for (uint8_t y=0; y<COUNT; y++) {
    if (forceRedrawAll || (bitmap[y] != UI->activeIcon.bitmap[y]))
    for (uint8_t x=0; x<COUNT; x++) {
      drawPixel(x, y, forceRedrawAll);
    }
  }
}


void DrawingGrid::drawGrid() {
  TFT & tft = UI->tft;
  for (uint8_t i=0; i<COUNT+1; i++) {
    tft.drawFastVLine(GRID_X + i*SIZE, GRID_Y, SIZE*COUNT + 1, COLOR_GRAY50);
    tft.drawFastHLine(GRID_X, GRID_Y + i*SIZE, SIZE*COUNT + 1, COLOR_GRAY50);
  }
}


void DrawingGrid::drawPixel(uint8_t x, uint8_t y, bool forceRedrawAll) {
  TFT & tft = UI->tft;

  uint16_t pMask = getPixelMask(x);
  bool bit = ((UI->activeIcon.bitmap[y]) & pMask);
  if (forceRedrawAll || (bit != (bitmap[y] & pMask))) {
    uint16_t color = bit ? COLOR_WHITE : COLOR_BLACK;
    tft.fillRect(GRID_X + x*SIZE+1, GRID_Y + y*SIZE+1, SIZE-1, SIZE-1, color);
    if (bit) {
      bitmap[y] |= pMask;
    } else {
      bitmap[y] &= ~pMask;
    }
  }
}

void DrawingGrid::setActiveIconPixel(uint8_t x, uint8_t y, bool pixel) {
  uint16_t pMask = getPixelMask(x);
  if (pixel) {
    UI->activeIcon.bitmap[y] |= pMask;
  } else {
    UI->activeIcon.bitmap[y] &= ~pMask;
  }
}

uint16_t DrawingGrid::getPixelMask(uint8_t x) {
  return (1<<(COUNT-x-1));
}




