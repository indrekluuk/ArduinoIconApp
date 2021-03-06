//
// Created by indrek on 7.05.2017.
//

#ifndef ARDUINOICONAPP_TOOLBAR_H
#define ARDUINOICONAPP_TOOLBAR_H


#include "Button.h"
#include "DrawingGridView.h"
#include "UiConstants.h"


class Tools;


class Toolbar {

public:
    using ToobarButton = Button1<Tools, uint8_t>;

private:

    static const uint8_t MAX_BUTTON_COUNT = 14;
    ToobarButton buttons[MAX_BUTTON_COUNT];
    uint8_t buttonIndexStart : 4;
    uint8_t buttonIndexEnd : 4;

public:

    static const uint16_t TOOLBAR_X = DrawingGridView::GRID_X +  DrawingGridView::GRID_W + 2;
    static const uint16_t TOOLBAR_Y = DrawingGridView::GRID_Y;
    static const uint16_t TOOLBAR_W = SCREEN_WIDTH - TOOLBAR_X;
    static const uint16_t TOOLBAR_H = DrawingGridView::GRID_H;


    Toolbar() {}

    void init();
    void reset();

    Button1<Tools, uint8_t> & addButton(bool wide, bool end);

    void draw();

private:
    uint8_t getHalfButtonWidth(uint8_t buttonIndex);



};


#endif //ARDUINOICONAPP_TOOLBAR_H
