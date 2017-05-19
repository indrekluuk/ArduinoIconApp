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
    static const uint8_t PALETTE_COLOR_W = 16;
    static const uint8_t PALETTE_COLOR_H = 19;
    static const uint8_t PALETTE_SCALE_W = 15;
    static const uint8_t PALETTE_SCALE_H = 15;
    static const uint16_t PALETTE_W = PALETTE_COLOR_W * PALETTE_SCALE_W;
    static const uint16_t PALETTE_H = PALETTE_COLOR_H * PALETTE_SCALE_H;


    // 6*n+1
    PaletteGeneratorSH<PALETTE_COLOR_W, PALETTE_COLOR_H> paletteGenerator;
    uint16_t paletteX;
    uint16_t paletteY;

    ColorPickerPalette(uint16_t x, uint16_t y, ColorPickerView & pickerView) :
        pickerView(pickerView),
        paletteX(x),
        paletteY(y) {};

    void setActive(bool active);
    bool isActive();

    bool touch(uint16_t x, uint16_t y);
    void hold(uint16_t x, uint16_t y);
    void release(uint16_t x, uint16_t y);
    void colorSelected(uint16_t x, uint16_t y);


    void draw();
};


#endif //PBLOCKICONS_COLORPICKERPALETTE_H
