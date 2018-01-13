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


class ArduinoIconAppUserInterface {

    static const uint8_t UNDO_BUFFER_DEPTH = 10;
    IconStorageData undoBuffer[UNDO_BUFFER_DEPTH];
    uint8_t undoStart = 0;
    uint8_t undoEnd = 0;
    uint8_t undoIndex = 0;


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



    ArduinoIconAppUserInterface();
    void init();

    void draw();
    void activeIconReloaded();
    void activeIconPixelsUpdated();
    void activeIconBorderUpdated();
    void activeIconColorUpdated();

    void undo();
    void redo();
    bool isUndoAvailable();
    bool isRedoAvailable();

    void setActiveIcon(IconStorageData & data);
    void copyActiveIconTo(IconStorageData & data);
    void showDrawingGrid();
    void showColorPicker(ColorPickerButton * button);
    void run();


private:
    void refreshUpdatedActiveIcon(bool pixels, bool border, bool colors);

    void saveActiveIconToUndoBuffer();
    void loadActiveIconFromUndoBuffer();


};


extern ArduinoIconAppUserInterface * UI;

#endif //ARDUINOICONAPP_USER_INTERFACE_H
