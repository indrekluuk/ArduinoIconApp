//
// Created by indrek on 13.05.2017.
//

#ifndef PBLOCKICONS_PALETTEGENERATOR_H
#define PBLOCKICONS_PALETTEGENERATOR_H


#include "src/screen/Colors.h"
#include "Arduino.h"



class PaletteGeneratorBase {


public:

    virtual uint16_t getWidth() = 0;
    virtual uint16_t getHeight() = 0;
    virtual void reset(uint16_t x, uint16_t y) = 0;
    virtual void nextLine() = 0;
    virtual RgbColor nextPixel() = 0;

};



template <uint8_t w, uint8_t h>
class PaletteGenerator : public PaletteGeneratorBase {

    uint8_t scaleW;
    uint8_t scaleH;

    uint8_t xCnt;
    uint8_t curSaturation;
    uint8_t yCnt;
    uint8_t curHue;

    float hueSection = (h-1) / 6.0f;
    uint16_t hueSection1 = hueSection * 1;
    uint16_t hueSection2 = hueSection * 2;
    uint16_t hueSection3 = hueSection * 3;
    uint16_t hueSection4 = hueSection * 4;
    uint16_t hueSection5 = hueSection * 5;
    float V;
    float dS;
    RgbColor line[w];

public:

    PaletteGenerator(uint8_t scaleW, uint8_t scaleH, float V) :
        scaleW(scaleW),
        scaleH(scaleH),
        V(V),
        dS((1.0f / (w - 1.0f)) * V)
    {
      reset(0, 0);
    }


    uint16_t getWidth() { return (uint16_t)w * (uint16_t)scaleW; };
    uint16_t getHeight() { return (uint16_t)h * (uint16_t)scaleH; };


    void reset(uint16_t x, uint16_t y) {
      xCnt = x % scaleW;
      curSaturation = x / scaleW;
      yCnt = y % scaleH;
      curHue = y / scaleH;
      initLine(curHue);
    }

    void nextLine() {
      xCnt = 0;
      curSaturation = 0;
      if (yCnt == scaleH) {
        yCnt = 0;
        curHue++;
        initLine(curHue);
      }
      yCnt++;
    };

    RgbColor nextPixel() {
      if (xCnt == scaleW) {
        xCnt = 0;
        curSaturation++;
      }
      xCnt++;
      return getPixel(curSaturation);
    };


protected:

    RgbColor getPixel(uint8_t saturation) {
      return line[saturation];
    };

    void initLine(uint8_t hue) {
      float hueDiv = (hue / hueSection);
      uint16_t hueIntDiv = (uint16_t)hueDiv;
      float hueMod = hueIntDiv % 2 + (hueDiv - (hueIntDiv + (uint16_t)1));
      float hueMultiplier = (1.0f - abs(hueMod));

      float saturation = 0;
      for (uint8_t saturationCnt = 0; saturationCnt < w; saturationCnt++) {

        float X = saturation * hueMultiplier;

        float Rp;
        float Gp;
        float Bp;

        if (hue < hueSection1) {
          Rp = saturation;
          Gp = X;
          Bp = 0;
        } else if (hue < hueSection2) {
          Rp = X;
          Gp = saturation;
          Bp = 0;
        } else if (hue < hueSection3) {
          Rp = 0;
          Gp = saturation;
          Bp = X;
        } else if (hue < hueSection4) {
          Rp = 0;
          Gp = X;
          Bp = saturation;
        } else if (hue < hueSection5) {
          Rp = X;
          Gp = 0;
          Bp = saturation;
        } else {
          Rp = saturation;
          Gp = 0;
          Bp = X;
        }

        float m = V - saturation;
        if (m < 0) m = 0;

        line[saturationCnt] = RgbColor(
            (Rp + m) * (uint16_t)31,
            (Gp + m) * (uint16_t)63,
            (Bp + m) * (uint16_t)31);

        saturation+=dS;
      }
    }

};




#endif //PBLOCKICONS_PALETTEGENERATOR_H
