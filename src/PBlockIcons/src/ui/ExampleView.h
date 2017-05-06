//
// Created by indrek on 6.05.2017.
//

#ifndef PBLOCKICONS_EXAMPLEVIEW_H
#define PBLOCKICONS_EXAMPLEVIEW_H


#include "TouchHandler.h"
#include "Button.h"
#include "DrawingGrid.h"


class ExampleView {

    Button<ExampleView> scaleUpButton;
    Button<ExampleView> scaleDownButton;
    uint8_t scale = 2;

public:

    static const uint16_t VIEW_X = 0;
    static const uint16_t VIEW_Y = DrawingGrid::GRID_Y;
    static const uint8_t VIEW_W = DrawingGrid::GRID_X - 10;
    static const uint8_t VIEW_H = VIEW_W;

    static const uint16_t SCALE_BUTTONS_X = VIEW_X;
    static const uint16_t SCALE_BUTTONS_Y = VIEW_Y + VIEW_H;
    static const uint8_t SCALE_BUTTONS_W = VIEW_W;
    static const uint8_t SCALE_BUTTONS_H = 50;


    ExampleView() :
        scaleUpButton(this, &ExampleView::scaleUp),
        scaleDownButton(this, &ExampleView::scaleDown) {}

    void init();

    void scaleUp();
    void scaleDown();

    void draw(bool redrawAll);
    void reDrawExamples();
    void printScale();

};


#endif //PBLOCKICONS_EXAMPLEVIEW_H
