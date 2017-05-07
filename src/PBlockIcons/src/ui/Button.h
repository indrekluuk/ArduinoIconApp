//
// Created by indrek on 6.05.2017.
//

#ifndef PBLOCKICONS_BUTTON_H
#define PBLOCKICONS_BUTTON_H


#include "TouchHandler.h"
#include "src/icons/Icon.h"


class ButtonBase : public Touchable {

    Icon * buttonIcon = nullptr;
    const char * buttonLabel = nullptr;

    bool isPressed = false;
    bool isActive = true;

public:

    uint16_t buttonX;
    uint16_t buttonY;
    uint8_t buttonW;
    uint8_t buttonH;


    void init(uint16_t x, uint16_t y, uint8_t w, uint8_t h, Icon * icon);
    void init(uint16_t x, uint16_t y, uint8_t w, uint8_t h, const char * label);

    void setActive(bool active);

    bool tap(uint16_t x, uint16_t y, bool hold) override;
    virtual void action() = 0;

    void draw();

private:
    void drawIcon(uint16_t x, uint16_t y, uint8_t w, uint8_t h);
    void drawLabel(uint16_t x, uint16_t y, uint8_t w, uint8_t h);

};




template<class TObj>
class Button : public ButtonBase {

public:
    typedef void (TObj::*CallbackMethod)(void);

    Button(TObj* object, CallbackMethod callbackMethod) :
        object(object),
        callbackMethod(callbackMethod) {};

    void action() override {
      (object->*callbackMethod)();
    }

private:
    TObj* object;
    CallbackMethod callbackMethod;

};




#endif //PBLOCKICONS_BUTTON_H
