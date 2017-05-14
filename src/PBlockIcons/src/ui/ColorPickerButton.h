//
// Created by indrek on 6.05.2017.
//

#ifndef PBLOCKICONS_COLORPICKERBUTTON_H
#define PBLOCKICONS_COLORPICKERBUTTON_H


#include "TouchHandler.h"
#include "src/screen/Colors.h"
#include "Button.h"


class ExampleView;


class ColorPickerButton : public Touchable {
public:
    typedef void (ExampleView::*CallbackMethod)(RgbColor color);

private:


    uint16_t pickerButtonX;
    uint16_t pickerButtonY;
    uint8_t pickerButtonW;
    uint8_t pickerButtonH;

    ExampleView* view;
    CallbackMethod callbackMethod;
    bool isActive = true;
    Button0<ColorPickerButton> button;

public:

    ColorPickerButton(ExampleView* view, CallbackMethod callbackMethod) :
        view(view),
        callbackMethod(callbackMethod)
    {};

    void init(uint16_t x, uint16_t y, uint8_t w, uint8_t h, Icon * icon);

    void setActive(bool active);
    void setOff();

    bool touch(uint16_t x, uint16_t y);
    void hold(uint16_t x, uint16_t y);
    void release(uint16_t x, uint16_t y);

    void togglePalette();
    void colorSelected(RgbColor color);

    void draw();

};


#endif //PBLOCKICONS_COLORPICKERBUTTON_H
