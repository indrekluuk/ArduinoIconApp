//
// Created by indrek on 25.03.2017.
//

#ifndef ARDUINOICONAPP_USER_INTERFACE_H
#define ARDUINOICONAPP_USER_INTERFACE_H


#include "TouchHandler.h"
#include "../screen/TFT.h"
#include "CalibrationView.h"
#include "DrawingGridView.h"
#include "ColorPickerView.h"
#include "ExampleView.h"
#include "Tools.h"
#include "../icons/Icon.h"
#include "../storage/IconStorage.h"
#include "UndoBuffer.h"


class ArduinoIconAppUserInterface {

public:
    TFT tft;
    TouchHandler touchHandler;
    CalibrationView calibrationView;
    DrawingGridView drawingGridView;
    ColorPickerView pickerView;
    ExampleView exampleView;
    Tools tools;
    IconBufferMem activeIcon;
    IconStorage iconStorage;
    UndoBuffer undoBuffer;



    ArduinoIconAppUserInterface();
    void init();

    void draw();
    void activeIconReloaded();
    void activeIconPixelsUpdated();
    void activeIconBorderUpdated();
    void activeIconColorUpdated();
    void refreshUpdatedActiveIcon(bool pixels, bool border, bool colors);


    void setActiveIcon(IconStorageData & data);
    void copyActiveIconTo(IconStorageData & data);
    void showDrawingGrid();
    void showColorPicker(ColorPickerButton * button);
    void run();


};


extern ArduinoIconAppUserInterface * UI;

#endif //ARDUINOICONAPP_USER_INTERFACE_H
