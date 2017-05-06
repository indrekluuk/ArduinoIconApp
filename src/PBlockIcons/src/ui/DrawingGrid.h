//
// Created by indrek on 6.05.2017.
//

#ifndef PBLOCKICONS_DRAWINGGRID_H
#define PBLOCKICONS_DRAWINGGRID_H



#include "TouchHandler.h"

#include "UiConstants.h"



class DrawingGrid : public Touchable {


    static const uint8_t COUNT = 16;
    static const uint8_t SIZE = 18;

    bool isColorSelected = false;
    bool selectedColor = false;

public:
    static const uint16_t GRID_X = 130;
    static const uint16_t GRID_Y = (SCREEN_HEIGHT - COUNT * SIZE) / 2;

    void init();
    bool tap(uint16_t x, uint16_t y, bool hold) override;
    void draw(bool redrawAll);


private:

    void drawGrid();
    void drawPixel(uint8_t x, uint8_t y);

    bool getPixel(uint8_t x, uint8_t y);
    void setPixel(uint8_t x, uint8_t y, bool pixel);

};


#endif //PBLOCKICONS_DRAWINGGRID_H
