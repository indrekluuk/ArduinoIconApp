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
    IconBufferMem buttonIcons[SAVED_ICON_COUNT];

    IconBufferProgMem iconReturn = IconBufferProgMem(&ICON_RETURN);
    IconBufferProgMem iconEdit = IconBufferProgMem(&ICON_EDIT);
    IconBufferProgMem iconSave = IconBufferProgMem(&ICON_SAVE);
    IconBufferProgMem iconLoad = IconBufferProgMem(&ICON_LOAD);
    IconBufferProgMem iconSend = IconBufferProgMem(&ICON_SEND);
    IconBufferProgMem iconInvert = IconBufferProgMem(&ICON_INVERT);
    IconBufferProgMem iconClear = IconBufferProgMem(&ICON_CLEAR);

    Toolbar toolbar;

public:

    Tools() {}

    void init();
    void draw(bool redrawAll);

private:

    void showMainToolbar(uint8_t);
    void showEditToolbar(uint8_t);
    void showSaveToolbar(uint8_t);
    void showLoadToolbar(uint8_t);
    void showSendToolbar(uint8_t);
    void reloadButtonIcons();

    void invertIcon(uint8_t);
    void clearIcon(uint8_t);

    void saveIcon(uint8_t slotIndex);
    void loadIcon(uint8_t slotIndex);
    void sendIcon(uint8_t slotIndex);

};


#endif //PBLOCKICONS_TOOLS_H
