//
// Created by indrek on 6.05.2017.
//

#ifndef PBLOCKICONS_BUTTON_H
#define PBLOCKICONS_BUTTON_H


#include "TouchHandler.h"
#include "src/icons/Icon.h"


class ButtonBase : public Touchable {

    const void * decoration = nullptr;

    uint8_t isPressed : 1;
    uint8_t isActive : 1;
    uint8_t isDecorationIcon : 1;
    uint8_t isDecorationLabel : 1;
    uint8_t reserve : 4;

public:

    uint16_t buttonX;
    uint16_t buttonY;
    uint8_t buttonW;
    uint8_t buttonH;

    ButtonBase() {
      isPressed = false;
      isActive = false;
      isDecorationIcon = false;
      isDecorationLabel = false;
    }


    void init(uint16_t x, uint16_t y, uint8_t w, uint8_t h, Icon * icon);
    void init(uint16_t x, uint16_t y, uint8_t w, uint8_t h, const char * label);

    void setActive(bool active);

    bool tap(uint16_t x, uint16_t y, bool hold) override;
    virtual void action() = 0;

    void draw();

private:
    void drawIcon(Icon * buttonIcon, uint16_t x, uint16_t y, uint8_t w, uint8_t h);
    void drawLabel(const char * buttonLabel, uint16_t x, uint16_t y, uint8_t w, uint8_t h);

};




template<class TObj>
class Button : public ButtonBase {

public:
    typedef void (TObj::*CallbackMethod)(void);
    typedef void (TObj::*CallbackMethodWithParam)(uint8_t param);

    Button(TObj* object, CallbackMethod callbackMethod) :
        object(object),
        callbackMethod(callbackMethod),
        callbackMethodWithParam(nullptr),
        methodParam(0) {};

    Button(TObj* object, CallbackMethodWithParam callbackMethod, uint8_t param) :
        object(object),
        callbackMethod(nullptr),
        callbackMethodWithParam(callbackMethod),
        methodParam(param) {};

    void action() override {
      if (callbackMethod != nullptr) {
        (object->*callbackMethod)();
      }
      if (callbackMethodWithParam != nullptr) {
        (object->*callbackMethodWithParam)(methodParam);
      }
    }

private:
    TObj* object;
    CallbackMethod callbackMethod;
    CallbackMethodWithParam callbackMethodWithParam;
    uint8_t methodParam;

};




#endif //PBLOCKICONS_BUTTON_H
