//
// Created by indrek on 21.05.2017.
//

#include "CalibrationView.h"
#include "PBlocksUserInterface.h"


bool CalibrationView::touch(uint16_t x, uint16_t y) {
  if (isActive) {
    isPressed = true;
    draw();
    return true;
  } else {
    return false;
  }
}



void CalibrationView::hold(uint16_t x, uint16_t y) {


}


void CalibrationView::release(uint16_t x, uint16_t y) {
  isPressed = false;

  if (calibrationStep == 0) {
    UI->touchHandler.setBottomLeftCalibration(stepX[0], stepY[0]);
  }
  if (calibrationStep == 1) {
    UI->touchHandler.setTopRightCalibration(stepX[1], stepY[1]);
  }

  calibrationStep ++;
  draw();
  if (calibrationStep >= STEP_COUNT) {
    isActive = false;
    UI->draw();
  }
}



void CalibrationView::draw() {
  if (calibrationStep > 0) {
    drawTarget(stepX[calibrationStep-1], stepY[calibrationStep-1], true);
  }
  if (calibrationStep < STEP_COUNT) {
    drawTarget(stepX[calibrationStep], stepY[calibrationStep], false);
  }
}



void CalibrationView::drawTarget(uint16_t x, uint16_t y, bool isClear) {
  TFT &tft = UI->tft;
  tft.fillRect(
      x-TARGET_SIZE/2,
      y-TARGET_SIZE/2,
      TARGET_SIZE,
      TARGET_SIZE,
      isClear ? COLOR_BLACK : (isPressed ? COLOR_GRAY85 : COLOR_GRAY66));

  if (!isClear) {
    tft.fillRect(
        x-1,
        y-10,
        2,
        20,
        COLOR_BLACK);

    tft.fillRect(
        x-10,
        y-1,
        20,
        2,
        COLOR_BLACK);
  }
}
