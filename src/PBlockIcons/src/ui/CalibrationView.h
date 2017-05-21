//
// Created by indrek on 21.05.2017.
//

#ifndef PBLOCKICONS_CALIBRATIONVIEW_H
#define PBLOCKICONS_CALIBRATIONVIEW_H


#include "TouchHandler.h"
#include "UiConstants.h"


class CalibrationView : public Touchable {

    static const uint32_t HOLD_TIME = 500;
    static const uint32_t HOLD_D = 5;

    static const uint8_t STEP_COUNT = 2;
    static const uint8_t TARGET_SIZE = 30;

    uint16_t stepX[STEP_COUNT] = {
        TARGET_SIZE / 2,
        SCREEN_WIDTH - TARGET_SIZE / 2
    };
    uint16_t stepY[STEP_COUNT] = {
        SCREEN_HEIGHT - TARGET_SIZE / 2,
        TARGET_SIZE / 2
    };

    uint8_t calibrationStep = 0;
    uint32_t detectTimer = 0;
    TSPoint detectedPoint;

public:
    bool isActive = true;
    bool isPressed = false;

    bool touch(uint16_t x, uint16_t y);
    void hold(uint16_t x, uint16_t y);
    void release(uint16_t x, uint16_t y);

    void draw();

private:
    void drawTarget(uint16_t x, uint16_t y, bool isClear);


};


#endif //PBLOCKICONS_CALIBRATIONVIEW_H
