//
// Created by indrek on 25.03.2017.
//

#ifndef PBLOCKMAIN_PBLOCKSUSER_INTERFACE_H
#define PBLOCKMAIN_PBLOCKSUSER_INTERFACE_H


#include "TouchHandler.h"
#include "src/screen/TFT.h"
#include "CalibrationView.h"
#include "DrawingGrid.h"
#include "ColorPickerView.h"
#include "ExampleView.h"
#include "Tools.h"
#include "src/icons/Icon.h"
#include "src/storage/IconStorage.h"


class PBlocksUserInterface {
public:
    TFT tft;
    TouchHandler touchHandler;
    CalibrationView calibration;
    DrawingGrid drawingGrid;
    ColorPickerView pickerView;
    ExampleView exampleView;
    Tools tools;
    IconBufferMem activeIcon;
    IconStorage iconStorage;



    PBlocksUserInterface();
    void init();

    void draw();
    void iconUpdated(bool pixels, bool border, bool colors);
    void showDrawingGrid();
    void showColorPicker(ColorPickerButton * button);
    void run();



};


extern PBlocksUserInterface * UI;

#endif //PBLOCKMAIN_PBLOCKSUSER_INTERFACE_H
