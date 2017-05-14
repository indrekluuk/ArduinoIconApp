//
// Created by indrek on 7.05.2017.
//

#ifndef PBLOCKICONS_ICONMEM_H
#define PBLOCKICONS_ICONMEM_H


#include <EEPROM.h>
#include <stdint.h>
#include "src/icons/Icon.h"





struct IconStorageData {
    uint8_t slotIndex;
    IconBufferMem icon;
    uint16_t foregroundColor;
    uint16_t backgroundColor;
    uint16_t borderColor;
    uint8_t hasBorder : 1;
    uint8_t is3d : 1;
    uint8_t reserve : 6;
    IconStorageData(uint8_t slotIndex) : slotIndex(slotIndex) {};
};



class IconMem {


public:
    uint16_t MEM_COUNT = EEPROM.length() / sizeof(IconStorageData);


    uint8_t getSlotNumber(uint16_t memIndex);
    void clearSlotNumber(uint16_t memIndex);

    IconStorageData readIconData(uint16_t memIndex);
    void writeIconData(uint16_t memIndex, IconStorageData & data);


private:
    IconStorageData * getMemAddress(uint16_t memSlotIndex);
    uint8_t readMemByte(void * addr);
    void readMemBytes(void * addr, uint16_t cnt, void * toAddr);
    void writeMemByte(void * addr, uint8_t byte);
    void writeMemBytes(void * addr, uint16_t cnt, void * fromAddr);

};


#endif //PBLOCKICONS_ICONMEM_H
