//
// Created by indrek on 25.03.2017.
//

#include "TouchHandler.h"
#include "PBlocksUserInterface.h"


Touchable * firstTouchable = nullptr;




Touchable::Touchable() {
  if (firstTouchable == nullptr) {
    firstTouchable = this;
  } else {
    Touchable * touchable = firstTouchable;
    while (touchable->nextRegion != nullptr) {
      touchable = touchable->nextRegion;
    }
    touchable->nextRegion = this;
  }
};


Touchable::~Touchable() {
  if (firstTouchable == this) {
    firstTouchable = this->nextRegion;
  } else if (firstTouchable != nullptr) {
    Touchable * touchable = firstTouchable;
    while (touchable->nextRegion != nullptr) {
      if (touchable->nextRegion == this) {
        touchable->nextRegion = this->nextRegion;
        return;
      }
      touchable = touchable->nextRegion;
    }
  }
}



bool Touchable::isTapIn(int16_t v, int16_t start, int16_t length) {
  return isTapBetween(v, start, start+length);
}

bool Touchable::isTapBetween(int16_t v, int16_t begin, int16_t end) {
  return (v > begin) && (v < end);
}



uint8_t TouchHandler::getRegionCount() {
  uint8_t count = 0;
  Touchable * touchable = firstTouchable;
  while(touchable != nullptr) {
    count++;
    touchable = touchable->nextRegion;
  }
  return count;
}



#define TOUCH_Z_THRESHOLD_LOW 100
#define TOUCH_Z_THRESHOLD_HIGH 1000
#define TOUCH_SAMPLE_COUNT 5



void TouchHandler::check() {
  readResistiveTouch();

  if (holdCounter == TOUCH_SAMPLE_COUNT && !isHold) {
    tapOnTouchable = nullptr;
    Touchable * touchable = firstTouchable;
    while(touchable != nullptr) {
      if (touchable->touch(x, y)) {
        tapOnTouchable = touchable;
        break;
      } else {
        touchable = touchable->nextRegion;
      }
    }
    isHold = true;
  }

  if (isHold) {
    if (holdCounter == 0) {
      isHold = false;
    }
    if (tapOnTouchable) {
      if (isHold) {
        if (holdCounter == TOUCH_SAMPLE_COUNT) {
          tapOnTouchable->hold(x, y);
        }
      } else {
        tapOnTouchable->release(x, y);
      }
    }
    if (!isHold) {
      tapOnTouchable = nullptr;
    }
    //UI->tft.drawRect(x, y, 1, 1, COLOR_YELLOW); // comment out
  }
}



TSPoint TouchHandler::readResistiveTouch() {
  TSPoint tp = touchScreen.getPoint();

  if (tp.z > TOUCH_Z_THRESHOLD_LOW && tp.z < TOUCH_Z_THRESHOLD_HIGH) {
    if (holdCounter < TOUCH_SAMPLE_COUNT) holdCounter++;
    if (holdCounter == TOUCH_SAMPLE_COUNT) {
      x = (uint16_t)map(tp.y, touchLeft, touchRight, refLeft, refRight);
      y = (uint16_t)map(tp.x, touchTop, touchBottom, refTop, refBottom);
      lastTouchPoint = tp;
    }
  } else {
    if (holdCounter > 0) holdCounter--;
  }

  pinMode(YP, OUTPUT);      //restore shared pins
  pinMode(XM, OUTPUT);
  digitalWrite(YP, HIGH);   //because TFT control pins
  digitalWrite(XM, HIGH);

  return tp;
}



void TouchHandler::setBottomLeftCalibration(uint16_t x, uint16_t y) {
  refBottom = y;
  refLeft = x;
  touchBottom = lastTouchPoint.x;
  touchLeft = lastTouchPoint.y;

  Serial.print("refBottom = ");
  Serial.println((int)refBottom);
  Serial.print("refLeft = ");
  Serial.println((int)refLeft);

  Serial.print("touchBottom = ");
  Serial.println((int)touchBottom);
  Serial.print("touchLeft = ");
  Serial.println((int)touchLeft);
}


void TouchHandler::setTopRightCalibration(uint16_t x, uint16_t y) {
  refTop = y;
  refRight = x;
  touchTop = lastTouchPoint.x;
  touchRight = lastTouchPoint.y;

  Serial.print("refTop = ");
  Serial.println((int)refTop);
  Serial.print("refRight = ");
  Serial.println((int)refRight);

  Serial.print("touchTop = ");
  Serial.println((int)touchTop);
  Serial.print("touchRight = ");
  Serial.println((int)touchRight);
}



