//
// Created by indrek on 21.05.2017.
//

#include "CalibrationView.h"
#include "ArduinoIconApp.h"


bool CalibrationView::touch(uint16_t x, uint16_t y) {
  if (isActive) {
    isPressed = true;
    detectTimer = millis() + HOLD_TIME;
    draw();
    return true;
  } else {
    return false;
  }
}



void CalibrationView::hold(uint16_t x, uint16_t y) {
  TSPoint point = UI->touchHandler.lastTouchPoint;

  if (detectTimer > 0) {
    if ((abs(detectedPoint.x - point.x) > HOLD_D || abs(detectedPoint.y - point.y) > HOLD_D)) {
      detectTimer = millis() + HOLD_TIME;
      detectedPoint = point;
    }

    if (millis() > detectTimer) {
      detectedPoint = point;
      detectTimer = 0;
      draw();
    }
  }
}


void CalibrationView::release(uint16_t x, uint16_t y) {
  isPressed = false;

  if (detectTimer == 0) {
    if (calibrationStep == 0) {
      UI->touchHandler.setBottomLeftCalibration(detectedPoint.y, detectedPoint.x, stepX[0], stepY[0]);
    }
    if (calibrationStep == 1) {
      UI->touchHandler.setTopRightCalibration(detectedPoint.y, detectedPoint.x , stepX[1]-2, stepY[1]);
    }

    calibrationStep ++;
    draw();
    if (calibrationStep >= STEP_COUNT) {
      isActive = false;
      UI->draw();
    }
  } else {
    draw();
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

  uint16_t color;
  if (isClear) {
    color = COLOR_BLACK;
  } else {
    if (!isPressed) {
      color = COLOR_GRAY66;
    } else {
      color = detectTimer == 0 ? COLOR_GREEN : COLOR_GRAY85;
    }
  }

  tft.fillRect(
      x-TARGET_SIZE/2,
      y-TARGET_SIZE/2,
      TARGET_SIZE,
      TARGET_SIZE,
      color);

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
