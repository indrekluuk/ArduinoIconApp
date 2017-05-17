//
// Created by indrek on 13.05.2017.
//

#ifndef PBLOCKICONS_COLORPICKERPALETTE_H
#define PBLOCKICONS_COLORPICKERPALETTE_H


#include "TouchHandler.h"
#include "src/palette/PaletteGenerator.h"



class ColorPickerView;


class ColorPickerPalette : public Touchable {

    bool active = false;
    ColorPickerView & pickerView;

public:
    static const uint8_t PALETTE_W = 10;
    static const uint8_t PALETTE_H = 19;
    static const uint8_t PALETTE_SCALE_W = 15;
    static const uint8_t PALETTE_SCALE_H = 15;

    // 6*n+1
    PaletteGenerator<PALETTE_W, PALETTE_H> generator;
    uint16_t paletteX;
    uint16_t paletteY;

    ColorPickerPalette(uint16_t x, uint16_t y, ColorPickerView & pickerView) :
        pickerView(pickerView),
        generator(PaletteGenerator<PALETTE_W, PALETTE_H>(1)),
        paletteX(x),
        paletteY(y) {};

    void setActive(bool active);
    bool isActive();

    bool touch(uint16_t x, uint16_t y);
    void hold(uint16_t x, uint16_t y);
    void release(uint16_t x, uint16_t y);
    RgbColor getSelectedColor(uint16_t x, uint16_t y);


    void draw();
};


#endif //PBLOCKICONS_COLORPICKERPALETTE_H
