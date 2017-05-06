//
// Created by indrek on 25.03.2017.
//

#ifndef PBLOCKMAIN_PBLOCKSUSER_INTERFACE_H
#define PBLOCKMAIN_PBLOCKSUSER_INTERFACE_H


#include "TouchHandler.h"
#include "src/screen/TFT.h"
#include "DrawingGrid.h"
#include "ExampleView.h"
#include "src/icons/Icon.h"


class PBlocksUserInterface {
public:
    TFT tft;
    TouchHandler touchHandler;
    DrawingGrid drawingGrid;
    ExampleView exampleView;
    IconBufferMem activeIcon;


    PBlocksUserInterface();
    void init();

    void draw(bool redrawAll);
    void iconUpdated();
    void run();



};


extern PBlocksUserInterface * UI;

#endif //PBLOCKMAIN_PBLOCKSUSER_INTERFACE_H
