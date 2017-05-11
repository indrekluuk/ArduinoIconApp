//
// Created by indrek on 6.05.2017.
//

#ifndef PBLOCKICONS_EXAMPLEVIEW_H
#define PBLOCKICONS_EXAMPLEVIEW_H


#include "TouchHandler.h"
#include "Button.h"
#include "DrawingGrid.h"
#include "ColorPicker.h"
#include "src/icons/ProgMemIcons.h"


class ExampleView : public Touchable {

    IconBufferProgMem iconZoomIn = IconBufferProgMem(&ICON_ZOOM_IN);
    IconBufferProgMem iconZoomOut = IconBufferProgMem(&ICON_ZOOM_OUT);

    Button0<ExampleView> scaleUpButton;
    Button0<ExampleView> scaleDownButton;

    Button0<ExampleView> showPaletteButton;
    ColorPicker bgColorPicker;
    ColorPicker fgColorPicker;
    ColorPicker bColorPicker;

    uint8_t scale : 6;
    uint8_t is3D : 1;
    uint8_t hasBorder : 1;
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
    static const uint8_t BUTTONS_H = 80;

    static const uint16_t PICKERS_X = VIEW_X;
    static const uint16_t PICKERS_Y = BUTTONS_Y + BUTTONS_H;
    static const uint16_t PICKERS_W = VIEW_W;
    static const uint16_t PICKERS_H = DrawingGrid::GRID_Y + DrawingGrid::GRID_H - PICKERS_Y;


    ExampleView() :
        bgColorPicker(this, &ExampleView::setBackgroundColor),
        fgColorPicker(this, &ExampleView::setForegroundColor),
        bColorPicker(this, &ExampleView::setBorderColor)
    {
        scale = 2;
        is3D = false;
        hasBorder = false;
    }


    void init();

    bool touch(uint16_t x, uint16_t y);
    void hold(uint16_t x, uint16_t y);
    void release(uint16_t x, uint16_t y);
    bool isTouchOnView(uint16_t x, uint16_t y);

    void nextBorderStyle();
    void togglePalette();
    void scaleUp();
    void scaleDown();
    void setBackgroundColor(Palette c);
    void setForegroundColor(Palette c);
    void setBorderColor(Palette c);

    void draw(bool redrawAll);
    void reDrawExamples();
    void printScale();

};


#endif //PBLOCKICONS_EXAMPLEVIEW_H
