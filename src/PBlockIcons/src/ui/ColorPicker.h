//
// Created by indrek on 6.05.2017.
//

#ifndef PBLOCKICONS_COLORPICKER_H
#define PBLOCKICONS_COLORPICKER_H


#include "TouchHandler.h"
#include "src/screen/Colors.h"

class ExampleView;


class ColorPicker : public Touchable {

    static const uint8_t COLOR_COUNT = 16;

    uint16_t pickerX;
    uint16_t pickerY;
    uint8_t pickerW;
    uint8_t pickerH;

    bool isActive = true;

public:
    typedef void (ExampleView::*CallbackMethod)(Palette c);

    ColorPicker(ExampleView* view, CallbackMethod callbackMethod) :
        view(view),
        callbackMethod(callbackMethod) {};

    void init(uint16_t x, uint16_t y, uint8_t w, uint8_t h);
    bool tap(uint16_t x, uint16_t y, bool hold) override;
    void draw();

    void setActive(bool active);

private:


    uint16_t getColorX(uint8_t c);
    uint16_t getColorX1(uint8_t c);
    uint16_t getColorX2(uint8_t c);
    uint16_t getColorY(uint8_t c);

    ExampleView* view;
    CallbackMethod callbackMethod;



};


#endif //PBLOCKICONS_COLORPICKER_H
