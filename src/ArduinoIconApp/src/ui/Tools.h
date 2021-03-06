//
// Created by indrek on 7.05.2017.
//

#ifndef ARDUINOICONAPP_TOOLS_H
#define ARDUINOICONAPP_TOOLS_H


#include "../storage/IconStorage.h"
#include "Toolbar.h"
#include "Button.h"
#include "../icons/ProgMemIcons.h"


class Tools {

    static const uint8_t ICON_BUTTON_COUNT = 5;
    static const uint8_t ICON_PAGE_COUNT = IconStorage::ICON_COUNT / ICON_BUTTON_COUNT;
    uint8_t page : 7;
    uint8_t showPageNumber : 1;
    ButtonBase * undoButton = nullptr;
    ButtonBase * redoButton = nullptr;
    IconBufferMem savedIcons[ICON_BUTTON_COUNT];

    static const uint8_t TOOLBAR_ICONS_SAVE = 0;
    static const uint8_t TOOLBAR_ICONS_LOAD = 1;


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
    IconBufferProgMem iconUndo = IconBufferProgMem(&ICON_UNDO);
    IconBufferProgMem iconRedo = IconBufferProgMem(&ICON_REDO);

    Toolbar toolbar;

public:

    Tools() : page(0), showPageNumber(false) {}

    void init();
    void draw();
    void checkUndoAndRedo(bool redraw);

private:
    void initSavedIconsPage(uint8_t newPage);

    void reset();

    void initMainToolbar();

    void showMainToolbar(uint8_t);
    void showEditToolbar(uint8_t);
    void showIconButtonsToolbar(uint8_t action);

    void undo(uint8_t);
    void redo(uint8_t);

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

    void moveIconPage(uint8_t direction);
    void saveIcon(uint8_t slotIndex);
    void loadIcon(uint8_t slotIndex);

    void sendIcon(uint8_t);

};


#endif //ARDUINOICONAPP_TOOLS_H
