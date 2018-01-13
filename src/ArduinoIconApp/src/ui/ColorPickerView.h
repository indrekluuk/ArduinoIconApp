//
// Created by indrek on 10.05.2017.
//

#ifndef ARDUINOICONAPP_COLORPICKERVIEW_H
#define ARDUINOICONAPP_COLORPICKERVIEW_H


#include "DrawingGridView.h"
#include "ColorPickerPalette.h"
#include "ColorPickerBrightnessBar.h"



class ColorPickerButton;



class ColorPickerView {
public:
    static const uint16_t PICKER_X = DrawingGridView::GRID_X + 1;
    static const uint16_t PICKER_Y = DrawingGridView::GRID_Y + 1;
    static const uint16_t PICKER_W = DrawingGridView::GRID_W - 2;
    static const uint16_t PICKER_H = DrawingGridView::GRID_H - 2;

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
    void colorSelected(RgbColor color, bool final);

private:
    void setCursor(uint8_t at);
    void printColorCode(uint8_t at, uint8_t cnt, uint32_t code);


};


#endif //ARDUINOICONAPP_COLORPICKERVIEW_H
