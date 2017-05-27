//
// Created by indrek on 7.05.2017.
//

#ifndef PBLOCKICONS_ICONMEM_H
#define PBLOCKICONS_ICONMEM_H



#include <stdint.h>
#include "src/icons/Icon.h"





struct IconStorageData {
    uint16_t bitmap[Icon::BITMAP_HEIGHT];
    uint16_t foregroundColor;
    uint16_t backgroundColor;
    uint16_t borderColor;
    uint8_t hasBorder : 1;
    uint8_t is3d : 1;
    uint8_t scale : 6;
};



class IconMem {

public:
    static const uint16_t MEM_COUNT = 1000 / sizeof(IconStorageData);

    IconMem();

    IconStorageData readIconData(uint16_t memIndex, IconStorageData & data);
    void writeIconData(uint16_t memIndex, IconStorageData & data);

private:
    void * getMemAddress(uint16_t memSlotIndex, uint16_t cnt);
    uint8_t readMemByte(void * addr);
    void readMemBytes(void * addr, uint16_t cnt, void * toAddr);
    void writeMemByte(void * addr, uint8_t byte);
    void writeMemBytes(void * addr, uint16_t cnt, void * fromAddr);

};


#endif //PBLOCKICONS_ICONMEM_H
