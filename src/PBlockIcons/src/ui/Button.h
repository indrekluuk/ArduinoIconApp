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
    uint8_t isDecorationIcon : 1;
    uint8_t isShowArrow : 1;
    uint8_t arrowPlacementRight : 1;
    uint8_t arrowDirectionRight : 1;
    uint8_t reserve : 3;

public:

    uint16_t buttonX;
    uint16_t buttonY;
    uint8_t buttonW;
    uint8_t buttonH;

    ButtonBase() {
      isPressed = false;
      isShowArrow = false;
    }


    ButtonBase & init(uint16_t x, uint16_t y, uint8_t w, uint8_t h);
    ButtonBase & setIcon(Icon * icon);
    ButtonBase & setLabel(const char * label);
    ButtonBase & showArrow(bool isPlacementRight, bool isDirectionRight);
    void deactivate();

    bool touch(uint16_t x, uint16_t y);
    void hold(uint16_t x, uint16_t y);
    void release(uint16_t x, uint16_t y);
    bool isTouchOnButton(uint16_t x, uint16_t y);

    virtual void action() = 0;

    void draw();

private:
    void drawIcon(Icon * buttonIcon, uint16_t x, uint16_t y, uint8_t w, uint8_t h);
    void drawLabel(const char * buttonLabel, uint16_t x, uint16_t y, uint8_t w, uint8_t h);
    void drawArrow(uint16_t x, uint16_t y);

};




template<class TObj>
class Button0 : public ButtonBase {

public:
    using CallbackMethod = void (TObj::*)();

    Button0 & setCallback(TObj * obj, CallbackMethod method) {
      object = obj;
      callbackMethod = method;
      return *this;
    }

    void action() override {
      if (callbackMethod != nullptr) {
        (object->*callbackMethod)();
      }
    }

private:
    TObj* object = nullptr;
    CallbackMethod callbackMethod = nullptr;
};




template<class TObj, typename TParam>
class Button1 : public ButtonBase {

public:
    using CallbackMethod = void (TObj::*)(TParam param);

    Button1 & setCallback(TObj * obj, CallbackMethod method, TParam param) {
      object = obj;
      callbackMethod = method;
      methodParam = param;
      return *this;
    }

    void action() override {
      if (callbackMethod != nullptr) {
        (object->*callbackMethod)(methodParam);
      }
    }

private:
    TObj* object = nullptr;
    CallbackMethod callbackMethod = nullptr;
    TParam methodParam;
};





#endif //PBLOCKICONS_BUTTON_H
