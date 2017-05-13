//
// Created by indrek on 13.05.2017.
//

#ifndef PBLOCKICONS_COLORPICKERPALETTE_H
#define PBLOCKICONS_COLORPICKERPALETTE_H


#include "TouchHandler.h"
#include "src/palette/PaletteGenerator.h"



class ColorPickerPalette : public Touchable {

    bool active = false;

public:
    // 6*n+1
    PaletteGenerator<10, 19> generator = PaletteGenerator<10, 19>(15, 15, 1);
    uint16_t paletteX;
    uint16_t paletteY;

    ColorPickerPalette(uint16_t x, uint16_t y) : paletteX(x), paletteY(y) {};

    void setActive(bool active);
    bool isActive();

    bool touch(uint16_t x, uint16_t y);
    void hold(uint16_t x, uint16_t y);
    void release(uint16_t x, uint16_t y);

    void draw();
};


#endif //PBLOCKICONS_COLORPICKERPALETTE_H
