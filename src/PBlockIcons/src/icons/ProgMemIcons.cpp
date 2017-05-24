//
// Created by indrek on 1.04.2017.
//


#include "ProgMemIcons.h"
#include <Arduino.h>



const PROGMEM IconBufferProgMem::IconData ICON_RETURN = {
    IconColor(Palette::BLACK, Palette::GRAY50, Palette::BLACK, false, false),
    {
        (uint16_t) 0b0000000000000000,
        (uint16_t) 0b0000000000000000,
        (uint16_t) 0b0111111111110000,
        (uint16_t) 0b0111111111111100,
        (uint16_t) 0b0111111111111110,
        (uint16_t) 0b0000000000011110,
        (uint16_t) 0b0000000000001111,
        (uint16_t) 0b0000000000000111,
        (uint16_t) 0b0000000000000111,
        (uint16_t) 0b0001000000001111,
        (uint16_t) 0b0011000000011110,
        (uint16_t) 0b0111111111111110,
        (uint16_t) 0b1111111111111100,
        (uint16_t) 0b0111111111110000,
        (uint16_t) 0b0011000000000000,
        (uint16_t) 0b0001000000000000,
    }
};




const PROGMEM IconBufferProgMem::IconData ICON_EDIT = {
    IconColor(Palette::BLACK, Palette::WHITE, Palette::BLACK, false, false),
    {
        (uint16_t) 0b1000000000000001,
        (uint16_t) 0b1100000000000011,
        (uint16_t) 0b0110000000000110,
        (uint16_t) 0b0111000000001110,
        (uint16_t) 0b0011100000011100,
        (uint16_t) 0b0001110000111000,
        (uint16_t) 0b0000111001110000,
        (uint16_t) 0b0000011111100000,
        (uint16_t) 0b0000001111000000,
        (uint16_t) 0b0000001111000000,
        (uint16_t) 0b0000011111100000,
        (uint16_t) 0b0111111001111110,
        (uint16_t) 0b1100110000110011,
        (uint16_t) 0b1000100000010001,
        (uint16_t) 0b1101100000011011,
        (uint16_t) 0b0111000000001110,
    }
};



const PROGMEM IconBufferProgMem::IconData ICON_SAVE = {
    IconColor(Palette::BLACK, Palette::WHITE, Palette::BLACK, false, false),
    {
        (uint16_t) 0b0000000000000000,
        (uint16_t) 0b0000000000000000,
        (uint16_t) 0b0000000000000000,
        (uint16_t) 0b0000011111111111,
        (uint16_t) 0b0000010101111001,
        (uint16_t) 0b0000010101111001,
        (uint16_t) 0b1000010111111001,
        (uint16_t) 0b1100010000000001,
        (uint16_t) 0b1110010000000001,
        (uint16_t) 0b1100010111111101,
        (uint16_t) 0b1000010000000001,
        (uint16_t) 0b0000010111111101,
        (uint16_t) 0b0000010000000001,
        (uint16_t) 0b0000011111111111,
        (uint16_t) 0b0000000000000000,
        (uint16_t) 0b0000000000000000,
    }
};




const PROGMEM IconBufferProgMem::IconData ICON_LOAD = {
    IconColor(Palette::BLACK, Palette::WHITE, Palette::BLACK, false, false),
    {
        (uint16_t) 0b0000000000000000,
        (uint16_t) 0b0000000000000000,
        (uint16_t) 0b0000000000111000,
        (uint16_t) 0b0000000011101000,
        (uint16_t) 0b0000001110001011,
        (uint16_t) 0b0000011000001111,
        (uint16_t) 0b0010010000111111,
        (uint16_t) 0b0110010000111111,
        (uint16_t) 0b1110011000111111,
        (uint16_t) 0b0110001000111110,
        (uint16_t) 0b0010001001111110,
        (uint16_t) 0b0000001101111110,
        (uint16_t) 0b0000000101111100,
        (uint16_t) 0b0000000111110000,
        (uint16_t) 0b0000000011000000,
        (uint16_t) 0b0000000000000000,
    }
};



const PROGMEM IconBufferProgMem::IconData ICON_SEND = {
    IconColor(Palette::BLACK, Palette::WHITE, Palette::BLACK, false, false),
    {
        (uint16_t) 0b0000000000000000,
        (uint16_t) 0b0000000000000000,
        (uint16_t) 0b0000011111111110,
        (uint16_t) 0b0000010000000010,
        (uint16_t) 0b0000010111111010,
        (uint16_t) 0b0000010111111010,
        (uint16_t) 0b1000010111111010,
        (uint16_t) 0b1100010000000010,
        (uint16_t) 0b1110011111111110,
        (uint16_t) 0b1100000000000000,
        (uint16_t) 0b1000000111111000,
        (uint16_t) 0b0000001010101100,
        (uint16_t) 0b0000011111111110,
        (uint16_t) 0b0000110100001101,
        (uint16_t) 0b0000111111111111,
        (uint16_t) 0b0000000000000000,
    }
};





const PROGMEM IconBufferProgMem::IconData ICON_INVERT = {
    IconColor(Palette::BLACK, Palette::WHITE, Palette::BLACK, false, false),
    {
        (uint16_t) 0b1111111111111111,
        (uint16_t) 0b1111111111111110,
        (uint16_t) 0b1111111111111100,
        (uint16_t) 0b1110000011111000,
        (uint16_t) 0b1110001111110000,
        (uint16_t) 0b1110000111100000,
        (uint16_t) 0b1110100011000000,
        (uint16_t) 0b1110110010000000,
        (uint16_t) 0b1111111101001000,
        (uint16_t) 0b1111111011101000,
        (uint16_t) 0b1111110001111000,
        (uint16_t) 0b1111100000111000,
        (uint16_t) 0b1111000011111000,
        (uint16_t) 0b1110000000000000,
        (uint16_t) 0b1100000000000000,
        (uint16_t) 0b1000000000000000,
    }
};



const PROGMEM IconBufferProgMem::IconData ICON_UP = {
    IconColor(Palette::BLACK, Palette::WHITE, Palette::BLACK, false, false),
    {
        (uint16_t) 0b0000001111000000,
        (uint16_t) 0b0000001111000000,
        (uint16_t) 0b0000111111110000,
        (uint16_t) 0b0000111111110000,
        (uint16_t) 0b0011111111111100,
        (uint16_t) 0b0011111111111100,
        (uint16_t) 0b1111111111111111,
        (uint16_t) 0b1111111111111111,
        (uint16_t) 0b0000001111000000,
        (uint16_t) 0b0000001111000000,
        (uint16_t) 0b0000001111000000,
        (uint16_t) 0b0000001111000000,
        (uint16_t) 0b0000001111000000,
        (uint16_t) 0b0000001111000000,
        (uint16_t) 0b0000001111000000,
        (uint16_t) 0b0000001111000000,
    }
};



const PROGMEM IconBufferProgMem::IconData ICON_DOWN = {
    IconColor(Palette::BLACK, Palette::WHITE, Palette::BLACK, false, false),
    {
        (uint16_t) 0b0000001111000000,
        (uint16_t) 0b0000001111000000,
        (uint16_t) 0b0000001111000000,
        (uint16_t) 0b0000001111000000,
        (uint16_t) 0b0000001111000000,
        (uint16_t) 0b0000001111000000,
        (uint16_t) 0b0000001111000000,
        (uint16_t) 0b0000001111000000,
        (uint16_t) 0b1111111111111111,
        (uint16_t) 0b1111111111111111,
        (uint16_t) 0b0011111111111100,
        (uint16_t) 0b0011111111111100,
        (uint16_t) 0b0000111111110000,
        (uint16_t) 0b0000111111110000,
        (uint16_t) 0b0000001111000000,
        (uint16_t) 0b0000001111000000,
    }
};



const PROGMEM IconBufferProgMem::IconData ICON_LEFT = {
    IconColor(Palette::BLACK, Palette::WHITE, Palette::BLACK, false, false),
    {
        (uint16_t) 0b0000001100000000,
        (uint16_t) 0b0000001100000000,
        (uint16_t) 0b0000111100000000,
        (uint16_t) 0b0000111100000000,
        (uint16_t) 0b0011111100000000,
        (uint16_t) 0b0011111100000000,
        (uint16_t) 0b1111111111111111,
        (uint16_t) 0b1111111111111111,
        (uint16_t) 0b1111111111111111,
        (uint16_t) 0b1111111111111111,
        (uint16_t) 0b0011111100000000,
        (uint16_t) 0b0011111100000000,
        (uint16_t) 0b0000111100000000,
        (uint16_t) 0b0000111100000000,
        (uint16_t) 0b0000001100000000,
        (uint16_t) 0b0000001100000000,
    }
};




const PROGMEM IconBufferProgMem::IconData ICON_RIGHT = {
    IconColor(Palette::BLACK, Palette::WHITE, Palette::BLACK, false, false),
    {
        (uint16_t) 0b0000000011000000,
        (uint16_t) 0b0000000011000000,
        (uint16_t) 0b0000000011110000,
        (uint16_t) 0b0000000011110000,
        (uint16_t) 0b0000000011111100,
        (uint16_t) 0b0000000011111100,
        (uint16_t) 0b1111111111111111,
        (uint16_t) 0b1111111111111111,
        (uint16_t) 0b1111111111111111,
        (uint16_t) 0b1111111111111111,
        (uint16_t) 0b0000000011111100,
        (uint16_t) 0b0000000011111100,
        (uint16_t) 0b0000000011110000,
        (uint16_t) 0b0000000011110000,
        (uint16_t) 0b0000000011000000,
        (uint16_t) 0b0000000011000000,
    }
};



const PROGMEM IconBufferProgMem::IconData ICON_FLIP = {
    IconColor(Palette::BLACK, Palette::WHITE, Palette::BLACK, false, false),
    {
        (uint16_t) 0b1100000000000011,
        (uint16_t) 0b1100000000000011,
        (uint16_t) 0b1111000000001111,
        (uint16_t) 0b1111000000001111,
        (uint16_t) 0b1111110000111011,
        (uint16_t) 0b1111110000110011,
        (uint16_t) 0b1111111111100011,
        (uint16_t) 0b1111111111000011,
        (uint16_t) 0b1111111111000011,
        (uint16_t) 0b1111111111100011,
        (uint16_t) 0b1111110000110011,
        (uint16_t) 0b1111110000111011,
        (uint16_t) 0b1111000000001111,
        (uint16_t) 0b1111000000001111,
        (uint16_t) 0b1100000000000011,
        (uint16_t) 0b1100000000000011,
    }
};






const PROGMEM IconBufferProgMem::IconData ICON_ROTATE = {
    IconColor(Palette::BLACK, Palette::WHITE, Palette::BLACK, false, false),
    {
        (uint16_t) 0b0000000111110000,
        (uint16_t) 0b0000000111110000,
        (uint16_t) 0b0000000000011100,
        (uint16_t) 0b0000000000011100,
        (uint16_t) 0b0001100000000111,
        (uint16_t) 0b0001100000000111,
        (uint16_t) 0b0111111000000111,
        (uint16_t) 0b0111111000000111,
        (uint16_t) 0b1111111100000111,
        (uint16_t) 0b1111111100000111,
        (uint16_t) 0b0001100000001111,
        (uint16_t) 0b0001100000001111,
        (uint16_t) 0b0001111000111100,
        (uint16_t) 0b0001111111111100,
        (uint16_t) 0b0000011111110000,
        (uint16_t) 0b0000011111110000,
    }
};






const PROGMEM IconBufferProgMem::IconData ICON_CLEAR = {
    IconColor(Palette::BLACK, Palette::WHITE, Palette::BLACK, false, false),
    {
        (uint16_t) 0b0000000000000000,
        (uint16_t) 0b0000001110000000,
        (uint16_t) 0b0000011111100000,
        (uint16_t) 0b0000000111110000,
        (uint16_t) 0b0000000001111000,
        (uint16_t) 0b0000000000011000,
        (uint16_t) 0b0001111111111000,
        (uint16_t) 0b0001111111110000,
        (uint16_t) 0b0000101010100000,
        (uint16_t) 0b0000101010100000,
        (uint16_t) 0b0000101010100000,
        (uint16_t) 0b0000101010100000,
        (uint16_t) 0b0000101010100000,
        (uint16_t) 0b0000101010100000,
        (uint16_t) 0b0000101010100000,
        (uint16_t) 0b0000111111100000,
    }
};






const PROGMEM IconBufferProgMem::IconData ICON_ZOOM_IN = {
    IconColor(Palette::BLACK, Palette::WHITE, Palette::BLACK, false, false),
    {
        (uint16_t) 0b0000000000000000,
        (uint16_t) 0b0000000011111000,
        (uint16_t) 0b0000000110001100,
        (uint16_t) 0b0000001100100110,
        (uint16_t) 0b0000001000100010,
        (uint16_t) 0b0000001011111010,
        (uint16_t) 0b0000001000100010,
        (uint16_t) 0b0000001100100110,
        (uint16_t) 0b0000001110001100,
        (uint16_t) 0b0000011111111000,
        (uint16_t) 0b0000111000000000,
        (uint16_t) 0b0001110000000000,
        (uint16_t) 0b0011100000000000,
        (uint16_t) 0b0111000000000000,
        (uint16_t) 0b0110000000000000,
        (uint16_t) 0b0000000000000000,
    }
};




const PROGMEM IconBufferProgMem::IconData ICON_ZOOM_OUT = {
    IconColor(Palette::BLACK, Palette::WHITE, Palette::BLACK, false, false),
    {
        (uint16_t) 0b0000000000000000,
        (uint16_t) 0b0000000011111000,
        (uint16_t) 0b0000000110001100,
        (uint16_t) 0b0000001100000110,
        (uint16_t) 0b0000001000000010,
        (uint16_t) 0b0000001011111010,
        (uint16_t) 0b0000001000000010,
        (uint16_t) 0b0000001100000110,
        (uint16_t) 0b0000001110001100,
        (uint16_t) 0b0000011111111000,
        (uint16_t) 0b0000111000000000,
        (uint16_t) 0b0001110000000000,
        (uint16_t) 0b0011100000000000,
        (uint16_t) 0b0111000000000000,
        (uint16_t) 0b0110000000000000,
        (uint16_t) 0b0000000000000000,
    }
};




const PROGMEM IconBufferProgMem::IconData ICON_FOREGROUND = {
    IconColor(Palette::BLACK, Palette::WHITE, Palette::BLACK, false, false),
    {
        (uint16_t) 0b0000000000000000,
        (uint16_t) 0b0000000000000000,
        (uint16_t) 0b0000000000000000,
        (uint16_t) 0b0001111111111000,
        (uint16_t) 0b0001010010011000,
        (uint16_t) 0b0001100100101000,
        (uint16_t) 0b0001001001001000,
        (uint16_t) 0b0001010010011000,
        (uint16_t) 0b0001100100101000,
        (uint16_t) 0b0001001001001000,
        (uint16_t) 0b0001010010011000,
        (uint16_t) 0b0001100100101000,
        (uint16_t) 0b0001111111111000,
        (uint16_t) 0b0000000000000000,
        (uint16_t) 0b0000000000000000,
        (uint16_t) 0b0000000000000000,
    }
};




const PROGMEM IconBufferProgMem::IconData ICON_BACKGROUND = {
    IconColor(Palette::BLACK, Palette::WHITE, Palette::BLACK, false, false),
    {
        (uint16_t) 0b0000000000000000,
        (uint16_t) 0b0000000000000000,
        (uint16_t) 0b0010010010010000,
        (uint16_t) 0b0000100100100100,
        (uint16_t) 0b0001001001001000,
        (uint16_t) 0b0010011111110000,
        (uint16_t) 0b0000111111100100,
        (uint16_t) 0b0001011111101000,
        (uint16_t) 0b0010011111110000,
        (uint16_t) 0b0000111111100100,
        (uint16_t) 0b0001011111101000,
        (uint16_t) 0b0010010010010000,
        (uint16_t) 0b0000100100100100,
        (uint16_t) 0b0001001001001000,
        (uint16_t) 0b0000000000000000,
        (uint16_t) 0b0000000000000000,
    }
};




const PROGMEM IconBufferProgMem::IconData ICON_BORDER = {
    IconColor(Palette::BLACK, Palette::WHITE, Palette::BLACK, false, false),
    {
        (uint16_t) 0b0000000000000000,
        (uint16_t) 0b0000000000000000,
        (uint16_t) 0b0000000000000000,
        (uint16_t) 0b0001111111111000,
        (uint16_t) 0b0001000000001000,
        (uint16_t) 0b0001000000001000,
        (uint16_t) 0b0001000000001000,
        (uint16_t) 0b0001000000001000,
        (uint16_t) 0b0001000000001000,
        (uint16_t) 0b0001000000001000,
        (uint16_t) 0b0001000000001000,
        (uint16_t) 0b0001000000001000,
        (uint16_t) 0b0001111111111000,
        (uint16_t) 0b0000000000000000,
        (uint16_t) 0b0000000000000000,
        (uint16_t) 0b0000000000000000,
    }
};



const PROGMEM IconBufferProgMem::IconData ICON_BORDER_SMALL = {
    IconColor(Palette::BLACK, Palette::WHITE, Palette::BLACK, false, false),
    {
        (uint16_t) 0b1111111111111111,
        (uint16_t) 0b1111111111111111,
        (uint16_t) 0b1100000000000011,
        (uint16_t) 0b1100000000000011,
        (uint16_t) 0b1100000000000011,
        (uint16_t) 0b1100000000000011,
        (uint16_t) 0b1100000000000011,
        (uint16_t) 0b1100000000000011,
        (uint16_t) 0b1100000000000011,
        (uint16_t) 0b1100000000000011,
        (uint16_t) 0b1100000000000011,
        (uint16_t) 0b1100000000000011,
        (uint16_t) 0b1100000000000011,
        (uint16_t) 0b1100000000000011,
        (uint16_t) 0b1111111111111111,
        (uint16_t) 0b1111111111111111,
    }
};



const PROGMEM IconBufferProgMem::IconData ICON_BORDER_SMALL_3D = {
    IconColor(Palette::BLACK, Palette::WHITE, Palette::BLACK, false, false),
    {
        (uint16_t) 0b1111111111111111,
        (uint16_t) 0b1000000000000011,
        (uint16_t) 0b1011111111111111,
        (uint16_t) 0b1010000000000111,
        (uint16_t) 0b1010000000000111,
        (uint16_t) 0b1010000000000111,
        (uint16_t) 0b1010000000000111,
        (uint16_t) 0b1010000000000111,
        (uint16_t) 0b1010000000000111,
        (uint16_t) 0b1010000000000111,
        (uint16_t) 0b1010000000000111,
        (uint16_t) 0b1010000000000111,
        (uint16_t) 0b1010000000000111,
        (uint16_t) 0b1011111111111111,
        (uint16_t) 0b1111111111111111,
        (uint16_t) 0b1111111111111111,
    }
};
