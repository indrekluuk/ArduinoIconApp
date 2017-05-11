//
// Created by indrek on 10.05.2017.
//

#ifndef PBLOCKICONS_COLORPALETTE_H
#define PBLOCKICONS_COLORPALETTE_H


#include "TouchHandler.h"
#include "DrawingGrid.h"



class ColorPalette : public Touchable {


    bool active = false;

public:
    static const uint16_t PALETTE_X = DrawingGrid::GRID_X;
    static const uint16_t PALETTE_Y = DrawingGrid::GRID_Y;
    static const uint16_t PALETTE_W = DrawingGrid::GRID_W;
    static const uint16_t PALETTE_H = DrawingGrid::GRID_H;


    void setActive(bool active);
    bool isActive();

    bool touch(uint16_t x, uint16_t y);
    void hold(uint16_t x, uint16_t y);
    void release(uint16_t x, uint16_t y);

    void draw(bool redrawAll);

};


#endif //PBLOCKICONS_COLORPALETTE_H
