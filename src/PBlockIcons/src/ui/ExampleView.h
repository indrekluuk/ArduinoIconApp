//
// Created by indrek on 6.05.2017.
//

#ifndef PBLOCKICONS_EXAMPLEVIEW_H
#define PBLOCKICONS_EXAMPLEVIEW_H


#include "TouchHandler.h"
#include "Button.h"
#include "DrawingGrid.h"
#include "ColorPicker.h"


class ExampleView {

    Button<ExampleView> scaleUpButton;
    Button<ExampleView> scaleDownButton;
    Button<ExampleView> toggle3DButton;
    Button<ExampleView> toggleBorderButton;

    ColorPicker bgColorPicker;
    ColorPicker fgColorPicker;
    ColorPicker bColorPicker;

    uint8_t scale = 2;
    bool is3D = false;
    bool hasBorder = false;
    Palette bgColor = Palette::GRAY33;
    Palette fgColor = Palette::GRAY85;
    Palette bColor = Palette::BLACK;

public:
    static const uint16_t GAP = 2;

    static const uint16_t VIEW_X = 0;
    static const uint16_t VIEW_Y = DrawingGrid::GRID_Y;
    static const uint8_t VIEW_W = DrawingGrid::GRID_X - GAP;
    static const uint8_t VIEW_H = VIEW_W;

    static const uint16_t BUTTONS_X = VIEW_X;
    static const uint16_t BUTTONS_Y = VIEW_Y + VIEW_H + GAP;
    static const uint8_t BUTTONS_W = VIEW_W;
    static const uint8_t BUTTONS_H = 60;

    static const uint16_t PICKERS_X = VIEW_X;
    static const uint16_t PICKERS_Y = BUTTONS_Y + BUTTONS_H;
    static const uint16_t PICKERS_W = VIEW_W;
    static const uint16_t PICKERS_H = DrawingGrid::GRID_Y + DrawingGrid::GRID_H - PICKERS_Y + 1;



    ExampleView() :
        scaleUpButton(this, &ExampleView::scaleUp),
        scaleDownButton(this, &ExampleView::scaleDown),
        toggle3DButton(this, &ExampleView::toggle3d),
        toggleBorderButton(this, &ExampleView::toggleBorder),
        bgColorPicker(this, &ExampleView::setBackgroundColor),
        fgColorPicker(this, &ExampleView::setForegroundColor),
        bColorPicker(this, &ExampleView::setBorderColor)
    {}

    void init();

    void scaleUp();
    void scaleDown();
    void toggle3d();
    void toggleBorder();
    void setBackgroundColor(Palette c);
    void setForegroundColor(Palette c);
    void setBorderColor(Palette c);

    void draw(bool redrawAll);
    void reDrawExamples();
    void printScale();

};


#endif //PBLOCKICONS_EXAMPLEVIEW_H
