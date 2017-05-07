//
// Created by indrek on 7.05.2017.
//

#ifndef PBLOCKICONS_TOOLS_H
#define PBLOCKICONS_TOOLS_H


#include "Toolbar.h"
#include "Button.h"


class Tools {

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
    Toolbar loadToolbar;
    Toolbar sendToolbar;


    Toolbar * activeToolbar = &mainToolbar;

public:
    Tools() :
        showEditButton(this, &Tools::showEditToolbar),
        showSaveButton(this, &Tools::showSaveToolbar),
        showLoadButton(this, &Tools::showLoadToolbar),
        showSendButton(this, &Tools::showSendToolbar),

        invertIconButton(this, &Tools::invertIcon),
        clearIconButton(this, &Tools::clearIcon),
        cancelEditButton(this, &Tools::cancelEdit)
    {};


    void init();
    void draw(bool redrawAll);

private:
    void setActiveToolbar(Toolbar * toolbar);

    void showEditToolbar();
    void showSaveToolbar();
    void showLoadToolbar();
    void showSendToolbar();

    void invertIcon();
    void clearIcon();
    void cancelEdit();

};


#endif //PBLOCKICONS_TOOLS_H
