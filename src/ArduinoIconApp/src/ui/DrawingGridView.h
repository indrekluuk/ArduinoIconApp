//
// Created by indrek on 6.05.2017.
//

#ifndef ARDUINOICONAPP_DRAWINGGRIDVIEW_H
#define ARDUINOICONAPP_DRAWINGGRIDVIEW_H


#include "../icons/Icon.h"
#include "TouchHandler.h"

#include "UiConstants.h"



class DrawingGridView : public Touchable {

    static const uint8_t COUNT = 16;
    static const uint8_t SIZE = 18;

    uint16_t bitmap[Icon::BITMAP_HEIGHT];

public:
    uint8_t selectedColor : 1;
    uint8_t isActive : 7;

    static const uint16_t GRID_X = 130;
    static const uint16_t GRID_Y = (SCREEN_HEIGHT - COUNT * SIZE) / 2;
    static const uint16_t GRID_W = COUNT * SIZE + 1;
    static const uint16_t GRID_H = COUNT * SIZE + 1;

    DrawingGridView() :
        selectedColor(false),
        isActive(true) {}

    void init();
    void setActive(bool active);
    bool touch(uint16_t x, uint16_t y) override;
    void hold(uint16_t x, uint16_t y) override;
    void release(uint16_t x, uint16_t y) override;
    bool isTouchOnGrid(uint16_t x, uint16_t y);
    void draw();
    void drawPixels(bool forceRedrawAll);

private:

    void drawGrid();
    void drawPixel(uint8_t x, uint8_t y, bool redrawAll);

    void setActiveIconPixel(uint8_t x, uint8_t y, bool pixel);
    uint16_t getPixelMask(uint8_t x);

};


#endif //ARDUINOICONAPP_DRAWINGGRIDVIEW_H
