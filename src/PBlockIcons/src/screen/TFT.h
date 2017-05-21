//
// Created by indrek on 26.03.2017.
//

#ifndef PBLOCKMAIN_TFT_H
#define PBLOCKMAIN_TFT_H


#include "src/lib/MCUFRIEND_kbv_mod/MCUFRIEND_kbv.h"
#include "src/lib/MCUFRIEND_kbv_mod/utility/mcufriend_shield.h"
#include "src/icons/Icon.h"
#include "src/palette/PaletteGenerator.h"


class TFT : public MCUFRIEND_kbv {

private:
    // _MW is private in MCUFRIEND_kbv_mod.h
    uint16_t _MW = 0x2C;

    int16_t textFillBoxX = 0;
    int16_t textFillBoxY = 0;
    uint8_t textFillBoxW = 0;
    uint8_t textFillBoxH = 0;

public:
    void drawIcon(uint16_t x, uint16_t y, Icon & icon, IconColor iconColor, uint8_t w, uint8_t h, uint8_t dx, uint8_t dy, uint8_t scaleW, uint8_t scaleH);
    void startTextFillBox(uint16_t x, uint16_t y, uint8_t w, uint8_t h, uint8_t cursorX, uint8_t cursorY);
    void finishTextFillBox();

    void drawPalette(uint16_t x, uint16_t y, PaletteGeneratorBase & generator, uint8_t scaleW, uint8_t scaleH);

    // Adafruit's "write" is terribly slow
    size_t write(uint8_t c) override;

private:
    void write8bitmap(
        RgbColor color,
        RgbColor bgColor,
        uint16_t bitmap,
        uint8_t scale);

    void write8bitmapWithBorder(
        RgbColor color,
        RgbColor bgColor,
        RgbColor bTopColor,
        RgbColor bBottomColor,
        uint16_t prvBitmap,
        uint16_t curBitmap,
        uint16_t nxtBitmap,
        uint8_t scale);

    void writeColorN(RgbColor color, uint16_t n);


};



#endif //PBLOCKMAIN_TFT_H
