//
// Created by indrek on 10.05.2017.
//

#ifndef PBLOCKICONS_COLORPICKERVIEW_H
#define PBLOCKICONS_COLORPICKERVIEW_H


#include "DrawingGrid.h"
#include "ColorPickerPalette.h"
#include "ColorPickerBrightnessBar.h"



class ColorPickerButton;



class ColorPickerView {
public:
    static const uint16_t PICKER_X = DrawingGrid::GRID_X + 1;
    static const uint16_t PICKER_Y = DrawingGrid::GRID_Y + 1;
    static const uint16_t PICKER_W = DrawingGrid::GRID_W - 2;
    static const uint16_t PICKER_H = DrawingGrid::GRID_H - 2;

    static const uint16_t BAR_X = PICKER_X + 1;
    static const uint16_t PALETTE_X = PICKER_X + PICKER_W - ColorPickerPalette::PALETTE_W - 1;

private:

    ColorPickerButton * activeButton = nullptr;
public:
    ColorPickerBrightnessBar brightnessBar;
    ColorPickerPalette palette;


    ColorPickerView() :
        brightnessBar(BAR_X, PICKER_Y + 1, *this),
        palette(PALETTE_X, PICKER_Y + 1, *this)
    {}

    void setActive(ColorPickerButton * button);
    void deactivate();
    ColorPickerButton * getActiveButton();

    void draw();

    void resetColor(RgbColor color);
    void colorSelected(RgbColor color);

private:
    void setCursor(uint8_t at);
    void printColorCode(uint8_t at, uint8_t cnt, uint32_t code);


};


#endif //PBLOCKICONS_COLORPICKERVIEW_H
