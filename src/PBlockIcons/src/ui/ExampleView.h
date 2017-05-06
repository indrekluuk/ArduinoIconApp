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
    Button<ExampleView> toggle3DButton;
    Button<ExampleView> toggleBorderButton;

    uint8_t scale = 2;
    bool is3D = false;
    bool hasBorder = false;

public:

    static const uint16_t VIEW_X = 0;
    static const uint16_t VIEW_Y = DrawingGrid::GRID_Y;
    static const uint8_t VIEW_W = DrawingGrid::GRID_X - 10;
    static const uint8_t VIEW_H = VIEW_W;

    static const uint16_t BUTTONS_X = VIEW_X;
    static const uint16_t BUTTONS_Y = VIEW_Y + VIEW_H;
    static const uint8_t BUTTONS_W = VIEW_W;
    static const uint8_t BUTTONS_H = 60;


    ExampleView() :
        scaleUpButton(this, &ExampleView::scaleUp),
        scaleDownButton(this, &ExampleView::scaleDown),
        toggle3DButton(this, &ExampleView::toggle3d),
        toggleBorderButton(this, &ExampleView::toggleBorder)
    {}

    void init();

    void scaleUp();
    void scaleDown();
    void toggle3d();
    void toggleBorder();

    void draw(bool redrawAll);
    void reDrawExamples();
    void printScale();

};


#endif //PBLOCKICONS_EXAMPLEVIEW_H
