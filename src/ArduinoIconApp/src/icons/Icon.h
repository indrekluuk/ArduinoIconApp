//
// Created by indrek on 26.03.2017.
//

#ifndef PBLOCKMAIN_ICON_H
#define PBLOCKMAIN_ICON_H


#include <avr/pgmspace.h>
#include <stdint.h>
#include "IconColor.h"





class Icon {
public:
    static const uint8_t BITMAP_WIDTH = 16;
    static const uint8_t BITMAP_HEIGHT = 16;

    virtual IconColor getColor() = 0;
    virtual uint16_t getRow(uint8_t index) = 0;
};




class IconBufferMem : public Icon {
public:
    IconColor color;
    uint16_t bitmap[BITMAP_HEIGHT];

    IconColor getColor() override {return color; }
    uint16_t getRow(uint8_t index) override {return bitmap[index];};
};



class IconBufferProgMem : public Icon {
public:
    struct IconData {
        IconColor color;
        uint16_t bitmap[BITMAP_HEIGHT];
    };

private:
    const IconData * pData;

public:

    IconBufferProgMem(const IconData * pData) : pData(pData) {};

    IconColor getColor() override {
        return (IconColor)pgm_read_word_near(&(pData->color));
    }
    uint16_t getRow(uint8_t index) override {
        return pgm_read_word_near(&(pData->bitmap[index]));
    };
};




#endif //PBLOCKMAIN_ICON_H
