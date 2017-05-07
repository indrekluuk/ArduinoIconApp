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






    Toolbar mainToolbar;
    Button<Tools> showEditButton;
    Button<Tools> showSaveButton;
    Button<Tools> showLoadButton;
    Button<Tools> showSendButton;

    Toolbar editToolbar;
    Button<Tools> invertIconButton;
    Button<Tools> clearIconButton;
    Button<Tools> cancelEditButton;

    Toolbar saveToolbar;
    Button<Tools> saveButtons[SAVED_ICON_COUNT];
    Button<Tools> cancelSaveButton;

    Toolbar loadToolbar;
    Button<Tools> loadButtons[SAVED_ICON_COUNT];
    Button<Tools> cancelLoadButton;

    Toolbar sendToolbar;
    Button<Tools> sendButtons[SAVED_ICON_COUNT];
    Button<Tools> cancelSendButton;


    Toolbar * activeToolbar = &mainToolbar;

public:
    Tools() :
        showEditButton(this, &Tools::showEditToolbar),
        showSaveButton(this, &Tools::showSaveToolbar),
        showLoadButton(this, &Tools::showLoadToolbar),
        showSendButton(this, &Tools::showSendToolbar),

        invertIconButton(this, &Tools::invertIcon),
        clearIconButton(this, &Tools::clearIcon),
        cancelEditButton(this, &Tools::returnToMain),

        saveButtons{
            {this, &Tools::saveIcon, 0},
            {this, &Tools::saveIcon, 1},
            {this, &Tools::saveIcon, 2},
            {this, &Tools::saveIcon, 3},
            {this, &Tools::saveIcon, 4},
            {this, &Tools::saveIcon, 5}},
        cancelSaveButton(this, &Tools::returnToMain),

        loadButtons{
            {this, &Tools::loadIcon, 0},
            {this, &Tools::loadIcon, 1},
            {this, &Tools::loadIcon, 2},
            {this, &Tools::loadIcon, 3},
            {this, &Tools::loadIcon, 4},
            {this, &Tools::loadIcon, 5}},
        cancelLoadButton(this, &Tools::returnToMain),

        sendButtons{
            {this, &Tools::sendIcon, 0},
            {this, &Tools::sendIcon, 1},
            {this, &Tools::sendIcon, 2},
            {this, &Tools::sendIcon, 3},
            {this, &Tools::sendIcon, 4},
            {this, &Tools::sendIcon, 5}},
        cancelSendButton(this, &Tools::returnToMain)
    {};


    void init();
    void draw(bool redrawAll);

private:
    void setActiveToolbar(Toolbar * toolbar);

    void showEditToolbar();
    void showSaveToolbar();
    void showLoadToolbar();
    void showSendToolbar();
    void reloadButtonIcons();

    void invertIcon();
    void clearIcon();

    void saveIcon(uint8_t slotIndex);
    void loadIcon(uint8_t slotIndex);
    void sendIcon(uint8_t slotIndex);

    void returnToMain();

};


#endif //PBLOCKICONS_TOOLS_H
