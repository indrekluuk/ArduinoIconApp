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
        (uint16_t) 0b0000000000000000,
        (uint16_t) 0b0000011111111111,
        (uint16_t) 0b0000010101111001,
        (uint16_t) 0b0000010101111001,
        (uint16_t) 0b0010010111111001,
        (uint16_t) 0b0110010000000001,
        (uint16_t) 0b1110010000000001,
        (uint16_t) 0b0110010111111101,
        (uint16_t) 0b0010010000000001,
        (uint16_t) 0b0000010111111101,
        (uint16_t) 0b0000010000000001,
        (uint16_t) 0b0000011111111111,
        (uint16_t) 0b0000000000000000,
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

