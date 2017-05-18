//
// Created by indrek on 18.05.2017.
//

#include "PaletteGenerator.h"




void PaletteGeneratorBase::initLinePixels(float hue, float value) {
  float hueMultiplier = calculateHueMultiplier(hue);
  float saturation;
  float dS;
  if (width > 1) {
    saturation = 0;
    dS = (1.0f / (width - 1)) * value;
  } else {
    saturation = value;
    dS = 0;
  }

  for (uint8_t i = 0; i < width; i++) {
    line[i] = calculateRGB(hue, hueMultiplier, saturation, value);
    saturation+=dS;
  }
}



RgbColor PaletteGeneratorBase::calculateRGB(float hue, float hueMultiplier, float saturation, float value) {
  float X = saturation * hueMultiplier;

  float Rp;
  float Gp;
  float Bp;

  if (hue < getHueSection(1)) {
    Rp = saturation;
    Gp = X;
    Bp = 0;
  } else if (hue < getHueSection(2)) {
    Rp = X;
    Gp = saturation;
    Bp = 0;
  } else if (hue < getHueSection(3)) {
    Rp = 0;
    Gp = saturation;
    Bp = X;
  } else if (hue < getHueSection(4)) {
    Rp = 0;
    Gp = X;
    Bp = saturation;
  } else if (hue < getHueSection(5)) {
    Rp = X;
    Gp = 0;
    Bp = saturation;
  } else {
    Rp = saturation;
    Gp = 0;
    Bp = X;
  }

  float m = value - saturation;
  if (m < 0) m = 0;

  return RgbColor(
      (Rp + m) * (uint16_t)31,
      (Gp + m) * (uint16_t)63,
      (Bp + m) * (uint16_t)31);
}




float PaletteGeneratorBase::calculateHueMultiplier(float hue) {
  float hueDiv = (hue / hueSectionSize);
  uint16_t hueIntDiv = (uint16_t)hueDiv;
  float hueMod = hueIntDiv % 2 + (hueDiv - (hueIntDiv + (uint16_t)1));
  return (1.0f - abs(hueMod));
}

