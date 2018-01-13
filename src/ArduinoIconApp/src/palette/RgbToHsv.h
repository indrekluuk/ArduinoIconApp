//
// Created by indrek on 18.05.2017.
//

#ifndef ARDUINOICONAPP_RGBTOHSV_H
#define ARDUINOICONAPP_RGBTOHSV_H

#include "../screen/Colors.h"


class RgbToHsv {

public:
    float H;
    float S;
    float V;

    RgbToHsv(RgbColor rgb);
    RgbToHsv(uint8_t R, uint8_t G, uint8_t B);

private:
    void calculate(float R, float G, float B);

};


#endif //ARDUINOICONAPP_RGBTOHSV_H
