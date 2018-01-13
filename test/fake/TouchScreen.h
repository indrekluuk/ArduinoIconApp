//
// Created by indrek on 26.03.2017.
//

#ifndef ARDUINOICONAPP_TOUCHSCREEN_H
#define ARDUINOICONAPP_TOUCHSCREEN_H



class TSPoint {
public:
    TSPoint(void) {};
    TSPoint(int16_t x, int16_t y, int16_t z) {};

    bool operator==(TSPoint);
    bool operator!=(TSPoint);

    int16_t x, y, z;
};


class TouchScreen {

public:
    TouchScreen(uint8_t xp, uint8_t yp, uint8_t xm, uint8_t ym, uint16_t rx) {};

    TSPoint getPoint() { return TSPoint();};

};


#endif //ARDUINOICONAPP_TOUCHSCREEN_H
