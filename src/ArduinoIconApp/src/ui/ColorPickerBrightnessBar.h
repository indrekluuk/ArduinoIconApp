//
// Created by indrek on 17.05.2017.
//

#ifndef PBLOCKICONS_COLORPICKERBRIGHTNESSBAR_H
#define PBLOCKICONS_COLORPICKERBRIGHTNESSBAR_H



#include "TouchHandler.h"
#include "../palette/PaletteGenerator.h"
#include "ColorPickerPalette.h"


class ColorPickerView;



class ColorPickerBrightnessBar : public Touchable {

    bool active = false;
    ColorPickerView & pickerView;

public:
    static const uint8_t BAR_COLOR_W = 1;
    static const uint8_t BAR_COLOR_H = ColorPickerPalette::PALETTE_COLOR_H;
    static const uint8_t BAR_SCALE_W = 30;
    static const uint8_t BAR_SCALE_H = ColorPickerPalette::PALETTE_SCALE_H;
    static const uint16_t BAR_W = BAR_COLOR_W * BAR_SCALE_W;
    static const uint16_t BAR_H = BAR_COLOR_H * BAR_SCALE_H;

    PaletteGeneratorSV<BAR_COLOR_W, BAR_COLOR_H> brightnessBarGenerator;
    uint16_t barX;
    uint16_t barY;

    ColorPickerBrightnessBar(uint16_t x, uint16_t y, ColorPickerView & pickerView) :
    pickerView(pickerView),
    barX(x),
    barY(y) {};

    void setActive(bool active);
    bool isActive();

    bool touch(uint16_t x, uint16_t y);
    void hold(uint16_t x, uint16_t y);
    void release(uint16_t x, uint16_t y);
    void colorSelected(uint16_t x, uint16_t y, bool final);


    void draw();
};


#endif //PBLOCKICONS_COLORPICKERBRIGHTNESSBAR_H
