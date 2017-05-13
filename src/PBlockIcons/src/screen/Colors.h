//
// Created by indrek on 21.03.2017.
//

#ifndef PBLOCKMAIN_COLORS_H_H
#define PBLOCKMAIN_COLORS_H_H


#include <stdint.h>



#define COLOR_WHITE       0xFFFF
#define COLOR_GRAY85      0xDEDB
#define COLOR_GRAY66      0xAD55
#define COLOR_GRAY50      0x7BEF
#define COLOR_GRAY33      0x52AA
#define COLOR_BLACK       0x0000

#define COLOR_BLUE        0x001F
#define COLOR_RED         0xF800
#define COLOR_DARK_RED    0xC800
#define COLOR_GREEN       0x0600
#define COLOR_DARK_GREEN  0X0300
#define COLOR_CYAN        0x07FF
#define COLOR_MAGENTA     0xF81F
#define COLOR_YELLOW      0xFFE0




enum Palette {
    WHITE = 0,
    GRAY85 = 1,
    GRAY66 = 2,
    GRAY50 = 3,
    GRAY33 = 4,
    BLACK = 5,
    RED = 6,
    GREEN = 7,
    BLUE = 8,
    DARK_RED = 9,
    DARK_GREEN = 10,
    DARK_BLUE = 11,
    YELLOW = 12,
    CYAN = 13,
    MAGENTA = 14,
    ORANGE = 15
};





struct RgbColor {

    RgbColor() {colorCode = COLOR_BLACK;};
    RgbColor(uint16_t c) {colorCode = c;}
    RgbColor(uint8_t r, uint8_t g, uint8_t b) {
      colorR = r;
      colorG = g;
      colorB = b;
    }

    RgbColor(Palette p) {
      switch (p) {
        default:
        case Palette::WHITE:
          colorCode = COLOR_WHITE;
          break;
        case Palette::GRAY85:
          colorCode = COLOR_GRAY85;
          break;
        case Palette::GRAY66:
          colorCode = COLOR_GRAY66;
          break;
        case Palette::GRAY50:
          colorCode = COLOR_GRAY50;
          break;
        case Palette::GRAY33:
          colorCode = COLOR_GRAY33;
          break;
        case Palette::BLACK:
          colorCode = COLOR_BLACK;
          break;
        case Palette::RED:
          colorCode = COLOR_RED;
          break;
        case Palette::GREEN:
          colorCode = COLOR_GREEN;
          break;
        case Palette::BLUE:
          colorCode = COLOR_BLUE;
          break;
        case Palette::DARK_RED:
          colorCode = COLOR_DARK_RED;
          break;
        case Palette::DARK_GREEN:
          colorCode = COLOR_DARK_GREEN;
          break;
        case Palette::DARK_BLUE:
          colorCode = COLOR_BLUE; // todo
          break;
        case Palette::YELLOW:
          colorCode = COLOR_YELLOW;
          break;
        case Palette::MAGENTA:
          colorCode = COLOR_MAGENTA;
          break;
        case Palette::CYAN:
          colorCode = COLOR_CYAN;
          break;
        case Palette::ORANGE:
          colorCode = COLOR_YELLOW; // todo
          break;
      }
    }

    union {
        uint16_t colorCode;
        struct {
            uint8_t colorL;
            uint8_t colorH;
        };
        struct {
            uint16_t colorB : 5;
            uint16_t colorG : 6;
            uint16_t colorR : 5;
        };
    };
};





#endif //PBLOCKMAIN_COLORS_H_H
