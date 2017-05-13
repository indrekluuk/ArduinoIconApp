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
    virtual RgbColor getNextPixel() = 0;
};



template <uint16_t w, uint16_t h>
class PaletteGenerator : public PaletteGeneratorBase {

    float Hsection = (h-1) / 6.0f;
    uint16_t Hsection1 = Hsection * 1;
    uint16_t Hsection2 = Hsection * 2;
    uint16_t Hsection3 = Hsection * 3;
    uint16_t Hsection4 = Hsection * 4;
    uint16_t Hsection5 = Hsection * 5;
    float V;
    float dS;

    uint16_t H = 0;
    float Hmult;
    float S = 0;
    uint16_t Scnt = w-1;

public:

    PaletteGenerator(float V) : V(V), dS((1.0f / (w - 1.0f)) * V) {}

    uint16_t getWidth() {return w;};
    uint16_t getHeight() {return h;};


    RgbColor getNextPixel() {
      Scnt++;
      if (Scnt == w) {
        S = 0;
        Scnt = 0;
        H++;
        float Hdiv = (H / Hsection);
        uint16_t HIntDiv = (uint16_t)Hdiv;
        float Hmod = HIntDiv % 2 + (Hdiv - (HIntDiv + (uint16_t)1));
        Hmult = (1.0f - abs(Hmod));
      } else {
        S += dS;
        if (S > 1) S = 1;
      }

      float X = S * Hmult;

      float Rp;
      float Gp;
      float Bp;

      if (H < Hsection1) {
        Rp = S;
        Gp = X;
        Bp = 0;
      } else if (H < Hsection2) {
        Rp = X;
        Gp = S;
        Bp = 0;
      } else if (H < Hsection3) {
        Rp = 0;
        Gp = S;
        Bp = X;
      } else if (H < Hsection4) {
        Rp = 0;
        Gp = X;
        Bp = S;
      } else if (H < Hsection5) {
        Rp = X;
        Gp = 0;
        Bp = S;
      } else {
        Rp = S;
        Gp = 0;
        Bp = X;
      }

      float m = V - S;
      if (m < 0) m = 0;

      return RgbColor(
          (Rp + m) * (uint16_t)31,
          (Gp + m) * (uint16_t)63,
          (Bp + m) * (uint16_t)31);
    };

};




#endif //PBLOCKICONS_PALETTEGENERATOR_H
