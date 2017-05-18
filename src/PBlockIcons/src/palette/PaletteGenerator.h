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

    void initSaturationLine(float saturationFrom, float saturationTo, float hue, float value);
    float calculateHueMultiplier(float hue);
    RgbColor calculateRGB(float hue, float hueMultiplier, float saturation, float value);

};



template <uint8_t w, uint8_t h>
class PaletteGeneratorSH : public PaletteGeneratorBase {
    RgbColor line[w];
    float value = 1; // max brightness
public:
    PaletteGeneratorSH() : PaletteGeneratorBase(line, w, h) {};

    void setValue(float value) {
      this->value = value;
    }

    float getHue(uint8_t y) {
      return ((float)y) / (h - 1);
    }

    float getSaturation(uint8_t x) {
      return ((float)x) / (w - 1);
    }

    void generateLine(uint8_t y) {
      float hue = ((float)y) / (h - 1);
      initSaturationLine(0, 1, hue, value);
    }

};


template <uint8_t w, uint8_t h>
class PaletteGeneratorSV : public PaletteGeneratorBase {
    RgbColor line[w];
    float hue = 0.5;
    float satFrom = 1;
    float satTo = 1;
public:
    PaletteGeneratorSV() : PaletteGeneratorBase(line, w, h) {};

    void setHue(float hue) {
      this->hue = hue;
    }

    void setSaturation(float saturation) {
      satFrom = saturation;
      satTo = saturation;
    }

    float getValue(uint8_t y) {
      return ((float)y) / (h - 1);
    }

    void generateLine(uint8_t y) {
      float value = ((float)y)/(h-1);
      initSaturationLine(satFrom, satTo, hue, value);
    }

};




#endif //PBLOCKICONS_PALETTEGENERATOR_H
