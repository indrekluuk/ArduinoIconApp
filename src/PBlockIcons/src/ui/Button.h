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
