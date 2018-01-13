//
// Created by indrek on 13.01.2018.
//

#ifndef ARDUINOICONAPP_UNDOBUFFER_H
#define ARDUINOICONAPP_UNDOBUFFER_H

#include "Arduino.h"
#include "../storage/IconStorage.h"



class UndoBuffer {

    static const uint8_t UNDO_BUFFER_DEPTH = 10;
    IconStorageData undoBuffer[UNDO_BUFFER_DEPTH];
    uint8_t undoStart = 0;
    uint8_t undoEnd = 0;
    uint8_t undoIndex = 0;


public:
    void init();


    void undo();
    void redo();

    bool isUndoAvailable();
    bool isRedoAvailable();

    void saveActiveIconToUndoBuffer();
    void loadActiveIconFromUndoBuffer();



};


#endif //ARDUINOICONAPP_UNDOBUFFER_H
