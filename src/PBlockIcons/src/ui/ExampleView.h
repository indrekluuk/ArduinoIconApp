//
// Created by indrek on 6.05.2017.
//

#ifndef PBLOCKICONS_EXAMPLEVIEW_H
#define PBLOCKICONS_EXAMPLEVIEW_H


#include "TouchHandler.h"
#include "Button.h"
#include "DrawingGrid.h"
#include "ColorPickerButton.h"
#include "../icons/ProgMemIcons.h"


class ExampleView : public Touchable {

    IconBufferProgMem iconZoomIn = IconBufferProgMem(&ICON_ZOOM_IN);
    IconBufferProgMem iconZoomOut = IconBufferProgMem(&ICON_ZOOM_OUT);
    IconBufferProgMem iconForeground = IconBufferProgMem(&ICON_FOREGROUND);
    IconBufferProgMem iconBackground = IconBufferProgMem(&ICON_BACKGROUND);
    IconBufferProgMem iconBorder = IconBufferProgMem(&ICON_BORDER);

    Button0<ExampleView> scaleUpButton;
    Button0<ExampleView> scaleDownButton;

    ColorPickerButton foregroundColorButton;
    ColorPickerButton backgroundColorButton;
    ColorPickerButton borderColorButton;


public:
    uint8_t scale;

    static const uint16_t GAP = 2;

    static const uint16_t VIEW_X = 0;
    static const uint16_t VIEW_Y = DrawingGrid::GRID_Y;
    static const uint8_t VIEW_W = DrawingGrid::GRID_X - GAP;
    static const uint8_t VIEW_H = VIEW_W;
    static const uint8_t MAX_SCALE = VIEW_W / 16;

    static const uint16_t BUTTONS_X = VIEW_X;
    static const uint16_t BUTTONS_Y = VIEW_Y + VIEW_H + GAP;
    static const uint8_t BUTTONS_W = VIEW_W;
    static const uint8_t BUTTONS_H = DrawingGrid::GRID_Y + DrawingGrid::GRID_H - BUTTONS_Y;

    static const uint16_t PICKERS_X = VIEW_X;
    static const uint16_t PICKERS_Y = BUTTONS_Y + BUTTONS_H;
    static const uint16_t PICKERS_W = VIEW_W;
    static const uint16_t PICKERS_H = DrawingGrid::GRID_Y + DrawingGrid::GRID_H - PICKERS_Y;


    ExampleView() :
        foregroundColorButton(COLOR_foreground, this, &ExampleView::setForegroundColor),
        backgroundColorButton(COLOR_background, this, &ExampleView::setBackgroundColor),
        borderColorButton(COLOR_border, this, &ExampleView::setBorderColor)
    {
        scale = 4;
    }


    void init();
    void evaluateIconData();

    bool touch(uint16_t x, uint16_t y);
    void hold(uint16_t x, uint16_t y);
    void release(uint16_t x, uint16_t y);
    bool isTouchOnView(uint16_t x, uint16_t y);

    void scaleUp();
    void scaleDown();
    void setScale(uint8_t newScale);

    void setForegroundColor(RgbColor color);
    void setBackgroundColor(RgbColor color);
    void setBorderColor(RgbColor color);

    void draw();
    void updatePreview();
    void printScale();

};


#endif //PBLOCKICONS_EXAMPLEVIEW_H
