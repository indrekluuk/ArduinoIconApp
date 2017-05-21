//
// Created by indrek on 7.05.2017.
//

#ifndef PBLOCKICONS_TOOLS_H
#define PBLOCKICONS_TOOLS_H


#include <src/storage/IconStorage.h>
#include "Toolbar.h"
#include "Button.h"
#include "src/icons/ProgMemIcons.h"


class Tools {

    static const uint8_t SAVED_ICON_COUNT = IconStorage::SLOT_COUNT;
    IconBufferMem * buttonIcons[SAVED_ICON_COUNT];

    IconBufferProgMem iconReturn = IconBufferProgMem(&ICON_RETURN);
    IconBufferProgMem iconEdit = IconBufferProgMem(&ICON_EDIT);
    IconBufferProgMem iconSave = IconBufferProgMem(&ICON_SAVE);
    IconBufferProgMem iconLoad = IconBufferProgMem(&ICON_LOAD);
    IconBufferProgMem iconSend = IconBufferProgMem(&ICON_SEND);
    IconBufferProgMem iconInvert = IconBufferProgMem(&ICON_INVERT);
    IconBufferProgMem iconUp = IconBufferProgMem(&ICON_UP);
    IconBufferProgMem iconDown = IconBufferProgMem(&ICON_DOWN);
    IconBufferProgMem iconLeft = IconBufferProgMem(&ICON_LEFT);
    IconBufferProgMem iconRight = IconBufferProgMem(&ICON_RIGHT);
    IconBufferProgMem iconFlip = IconBufferProgMem(&ICON_FLIP);
    IconBufferProgMem iconBorder = IconBufferProgMem(&ICON_BORDER_SMALL);
    IconBufferProgMem iconBorder3D = IconBufferProgMem(&ICON_BORDER_SMALL_3D);
    IconBufferProgMem iconRotate = IconBufferProgMem(&ICON_ROTATE);
    IconBufferProgMem iconClear = IconBufferProgMem(&ICON_CLEAR);

    Toolbar toolbar;

public:

    Tools() {}

    void init();
    void draw();

private:

    void showMainToolbar(uint8_t);
    void showEditToolbar(uint8_t);
    void showSaveToolbar(uint8_t);
    void showLoadToolbar(uint8_t);
    void showSendToolbar(uint8_t);

    void invertIcon(uint8_t);
    void moveIconUp(uint8_t);
    void moveIconDown(uint8_t);
    void moveIconLeft(uint8_t);
    void moveIconRight(uint8_t);
    void flipIcon(uint8_t);
    void rotateIcon(uint8_t);
    void setBorder(uint8_t);
    void setBorder3D(uint8_t);
    void clearIcon(uint8_t);

    void saveIcon(uint8_t slotIndex);
    void loadIcon(uint8_t slotIndex);
    void sendIcon(uint8_t slotIndex);

};


#endif //PBLOCKICONS_TOOLS_H
