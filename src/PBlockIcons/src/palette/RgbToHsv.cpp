//
// Created by indrek on 18.05.2017.
//

#include "RgbToHsv.h"



RgbToHsv::RgbToHsv(RgbColor rgb) {
  calculate(
      ((float)rgb.colorR) / 31,
      ((float)rgb.colorG) / 63,
      ((float)rgb.colorB) / 31);
}


RgbToHsv::RgbToHsv(uint8_t R, uint8_t G, uint8_t B) {
  calculate(
      ((float)R) / 255,
      ((float)G) / 255,
      ((float)B) / 255);
}


void RgbToHsv::calculate(float R, float G, float B) {
  float Cmax = R;
  if (Cmax < G) Cmax = G;
  if (Cmax < B) Cmax = B;

  float Cmin = R;
  if (Cmin > G) Cmin = G;
  if (Cmin > B) Cmin = B;

  float D = Cmax - Cmin;

  if (D == 0) {
    H = 0;
  } else if (Cmax == R) {
    float hh = ((G-B)/D);
    int16_t intHh = (int)hh;
    H = intHh % 6 + (hh - intHh);
    if (H < 0) H = ((float)6) + H;
  } else if (Cmax == G) {
    H = (B-R) / D + 2;
  } else { // Cmax == B
    H = (R-G) / D  + 4;
  }

  S = Cmax == 0 ? 0 : D / Cmax;
  V = Cmax;
  H = H / 6;
}


