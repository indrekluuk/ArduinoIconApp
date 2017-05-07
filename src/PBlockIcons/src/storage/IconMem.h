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
    IconStorageData(uint8_t slotIndex) : slotIndex(slotIndex) {};
};



class IconMem {


public:
    uint16_t MEM_COUNT = EEPROM.length() / sizeof(IconStorageData);


    uint8_t getSlotNumber(uint16_t memIndex);
    void setSlotNumber(uint16_t memIndex, uint8_t slotNumber);
    IconBufferMem readIconData(uint16_t memIndex);
    void writeIconData(uint16_t memIndex, IconBufferMem & icon);


private:
    IconStorageData * getMemAddress(uint16_t memSlotIndex);
    uint8_t readMemByte(void * addr);
    void readMemBytes(void * addr, uint16_t cnt, void * toAddr);
    void writeMemByte(void * addr, uint8_t byte);
    void writeMemBytes(void * addr, uint16_t cnt, void * fromAddr);

};


#endif //PBLOCKICONS_ICONMEM_H
