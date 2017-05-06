//
// Created by indrek on 25.03.2017.
//

#ifndef PBLOCKMAIN_TOUCHHANDLER_H
#define PBLOCKMAIN_TOUCHHANDLER_H



#include <Arduino.h>
#include <TouchScreen.h>



#define YP A1   //[A1], A3 for ILI9320, A2 for ST7789V
#define YM 7    //[ 7], 9             , 7
#define XM A2   //[A2], A2 for ILI9320, A1 for ST7789V
#define XP 6    //[ 6], 8             , 6




class Touchable {
public:
    Touchable();
    ~Touchable();
    virtual bool tap(uint16_t x, uint16_t y, bool hold) = 0;
    Touchable * nextRegion = nullptr;
protected:
    bool isTapIn(int16_t v, int16_t start, int16_t length);
    bool isTapBetween(int16_t v, int16_t begin, int16_t end);
};



class TouchHandler {

    uint16_t screenW;
    uint16_t screenH;
    Touchable * tapOnTouchable = nullptr;
    TouchScreen touchScreen = TouchScreen(XP, YP, XM, YM, 300);
    int16_t x;
    int16_t y;
    uint8_t holdCounter : 7;
    uint8_t isHold : 1;

public:
    TouchHandler() {
      holdCounter = 0;
      isHold = false;
    }

    void init(uint16_t screenW, uint16_t screenH);

    void check();
    uint8_t getRegionCount();

private:
    void readResistiveTouch();


};


#endif //PBLOCKMAIN_TOUCHHANDLER_H
