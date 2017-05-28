//
// Created by indrek on 6.04.2017.
//

#ifndef PBLOCKMAIN_ICONCOLOR_H
#define PBLOCKMAIN_ICONCOLOR_H


#include "../screen/Colors.h"



struct IconColor {

    union {
        uint16_t rawData;
        struct {
            uint8_t fgColor : 4;
            uint8_t bgColor : 4;
            uint8_t bColor : 4;
            uint8_t hasBorder : 1;
            uint8_t hasBorder3d : 1;
            uint8_t reserved : 2;
        };
    };

    constexpr IconColor(uint16_t rawData) :
        rawData(rawData)
    {}

    constexpr IconColor(
        Palette fgColor,
        Palette bgColor,
        Palette bColor,
        bool hasBorder,
        bool hasBorder3d
    ) :
        fgColor(fgColor),
        bgColor(bgColor),
        bColor(bColor),
        hasBorder(hasBorder),
        hasBorder3d(hasBorder3d),
        reserved(0)
    {}

    constexpr IconColor() :
        fgColor(Palette::WHITE),
        bgColor(Palette::BLACK),
        bColor(Palette::BLACK),
        hasBorder(false),
        hasBorder3d(false),
        reserved(0)
    {}

    void setForegroundColor(Palette p) {fgColor = p;};
    void setBackgroundColor(Palette p) {bgColor = p;};
    void setBorderColor(Palette p) {bColor = p; hasBorder = true; hasBorder3d = false; };
    void setBorder3d() {hasBorder = true; hasBorder3d = true; };
    void setNoBorder() {hasBorder = false;}

    RgbColor getForegroundColor() { return RgbColor((Palette)fgColor); }
    RgbColor getBackgroundColor() { return RgbColor((Palette)bgColor); }
    RgbColor getBorderColor() { return RgbColor((Palette)bColor); }
};




#endif //PBLOCKMAIN_ICONCOLOR_H
