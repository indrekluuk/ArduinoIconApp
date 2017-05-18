//
// Created by indrek on 13.05.2017.
//

#ifndef PBLOCKICONS_PALETTEGENERATOR_H
#define PBLOCKICONS_PALETTEGENERATOR_H


#include "src/screen/Colors.h"
#include "Arduino.h"



class PaletteGeneratorBase {

    RgbColor * line;
    const uint8_t width;
    const uint8_t height;

public:

    const uint8_t getWidth() { return width; };
    const uint8_t getHeight() { return height; };
    virtual void generateLine(uint8_t y) = 0;

    RgbColor getPixel(uint8_t x) {
      return line[x];
    };

protected:

    PaletteGeneratorBase(RgbColor * line, const uint8_t w, const uint8_t h) :
        line(line),
        width(w),
        height(h)
    {};

    static constexpr float hueSectionSize = 1.0f / 6.0f;
    static constexpr float getHueSection(const uint8_t index) {
      return hueSectionSize * index;
    };

    void initLinePixels(float hue, float value);
    float calculateHueMultiplier(float hue);
    RgbColor calculateRGB(float hue, float hueMultiplier, float saturation, float value);

};



template <uint8_t w, uint8_t h>
class PaletteGeneratorSH : public PaletteGeneratorBase {
    RgbColor line[w];
public:
    PaletteGeneratorSH() : PaletteGeneratorBase(line, w, h) {};

    void generateLine(uint8_t y) {
      float hue = ((float)y) / (h - 1);
      float value = 1; // max brightness
      initLinePixels(hue, value);
    }

};


template <uint8_t w, uint8_t h>
class PaletteGeneratorSV : public PaletteGeneratorBase {
    RgbColor line[w];
public:
    PaletteGeneratorSV() : PaletteGeneratorBase(line, w, h) {};

    void generateLine(uint8_t y) {
      float hue = 0;
      float value = ((float)y)/(h-1);
      initLinePixels(hue, value);
    }

};




#endif //PBLOCKICONS_PALETTEGENERATOR_H
