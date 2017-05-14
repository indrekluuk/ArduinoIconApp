//
// Created by indrek on 10.05.2017.
//

#ifndef PBLOCKICONS_COLORPICKERVIEW_H
#define PBLOCKICONS_COLORPICKERVIEW_H


#include "DrawingGrid.h"
#include "ColorPickerPalette.h"



class ColorPickerButton;



class ColorPickerView {
public:
    static const uint16_t PICKER_X = DrawingGrid::GRID_X + 1;
    static const uint16_t PICKER_Y = DrawingGrid::GRID_Y + 1;
    static const uint16_t PICKER_W = DrawingGrid::GRID_W - 2;
    static const uint16_t PICKER_H = DrawingGrid::GRID_H - 2;

    using CallbackMethod = void (ColorPickerButton::*)(RgbColor color);

private:
    ColorPickerPalette palette;

    ColorPickerButton * activeButton;
    CallbackMethod activeButtonCallback;


    bool active = false;
public:

    ColorPickerView() : palette(PICKER_X + 1, PICKER_Y + 1, *this) {}

    void setActive(bool active, ColorPickerButton * button, CallbackMethod callback);
    bool isActive();

    void draw();

    void colorSelected(RgbColor color);


};


#endif //PBLOCKICONS_COLORPICKERVIEW_H
