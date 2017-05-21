//
// Created by indrek on 25.03.2017.
//

#ifndef PBLOCKMAIN_TOUCHHANDLER_H
#define PBLOCKMAIN_TOUCHHANDLER_H



#include <Arduino.h>
#include <TouchScreen.h>
#include "UiConstants.h"




#define YP A1   //[A1], A3 for ILI9320, A2 for ST7789V
#define YM 7    //[ 7], 9             , 7
#define XM A2   //[A2], A2 for ILI9320, A1 for ST7789V
#define XP 6    //[ 6], 8             , 6




class Touchable {
public:
    Touchable();
    ~Touchable();
    virtual bool touch(uint16_t x, uint16_t y) = 0;
    virtual void hold(uint16_t x, uint16_t y) = 0;
    virtual void release(uint16_t x, uint16_t y) = 0;
    Touchable * nextRegion = nullptr;
protected:
    bool isTapIn(int16_t v, int16_t start, int16_t length);
    bool isTapBetween(int16_t v, int16_t begin, int16_t end);
};



class TouchHandler {

    Touchable * tapOnTouchable = nullptr;
    TouchScreen touchScreen = TouchScreen(XP, YP, XM, YM, 300);
    int16_t x;
    int16_t y;
    uint8_t holdCounter;
    bool isHold;

    TSPoint lastTouchPoint;
    uint16_t touchLeft = 960;
    uint16_t touchRight = 155;
    uint16_t touchTop = 138;
    uint16_t touchBottom = 924;
    uint16_t refLeft = 0;
    uint16_t refRight = SCREEN_WIDTH;
    uint16_t refTop = 0;
    uint16_t refBottom = SCREEN_HEIGHT;


public:


    TouchHandler() {
      holdCounter = 0;
      isHold = false;
    }

    void check();
    uint8_t getRegionCount();
    TSPoint readResistiveTouch();

    void setBottomLeftCalibration(uint16_t x, uint16_t y);
    void setTopRightCalibration(uint16_t x, uint16_t y);


};


#endif //PBLOCKMAIN_TOUCHHANDLER_H
