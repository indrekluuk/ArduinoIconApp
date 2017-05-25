//
// Created by indrek on 7.05.2017.
//

#ifndef PBLOCKICONS_ICONSTORAGE_H
#define PBLOCKICONS_ICONSTORAGE_H


#include <stdint.h>
#include "IconMem.h"




struct IconsSlots {
    int16_t memIndex = -1;
    IconStorageData storedData;

    IconsSlots(uint8_t slotIndex) : storedData(slotIndex) {}
};



class IconStorage {


public:
    IconMem iconMem;
    static const uint8_t SLOT_COUNT = 10;
    IconsSlots slots[SLOT_COUNT] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};


    IconStorage();
    IconStorageData & getStoredIconData(uint8_t slotIndex);
    void saveIcon(
        uint8_t slotIndex,
        IconBufferMem & icon,
        uint16_t foregroundColor,
        uint16_t backgroundColor,
        uint16_t borderColor,
        uint8_t scale
    );

private:
    void initSlot(uint8_t slotIndex);
    void saveSlot(uint8_t slotIndex);



};


#endif //PBLOCKICONS_ICONSTORAGE_H
