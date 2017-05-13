//
// Created by indrek on 10.05.2017.
//

#ifndef PBLOCKICONS_COLORPICKERVIEW_H
#define PBLOCKICONS_COLORPICKERVIEW_H


#include "DrawingGrid.h"
#include "ColorPickerPalette.h"



class ColorPickerView {

    ColorPickerPalette palette;

    bool active = false;
public:
    static const uint16_t PICKER_X = DrawingGrid::GRID_X;
    static const uint16_t PICKER_Y = DrawingGrid::GRID_Y;
    static const uint16_t PICKER_W = DrawingGrid::GRID_W;
    static const uint16_t PICKER_H = DrawingGrid::GRID_H;


    ColorPickerView() : palette(PICKER_X + 2, PICKER_Y + 2) {}


    void setActive(bool active);
    bool isActive();

    void draw();

};


#endif //PBLOCKICONS_COLORPICKERVIEW_H
