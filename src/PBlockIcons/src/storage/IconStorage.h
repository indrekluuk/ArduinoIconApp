//
// Created by indrek on 7.05.2017.
//

#ifndef PBLOCKICONS_ICONSTORAGE_H
#define PBLOCKICONS_ICONSTORAGE_H


#include <stdint.h>
#include "IconMem.h"




struct IconsSlots {
    int16_t memIndex = -1;
    IconBufferMem icon;
};



class IconStorage {


public:
    IconMem iconMem;
    static const uint8_t SLOT_COUNT = 6;
    IconsSlots slots[SLOT_COUNT];


    IconStorage();
    void saveIcon(uint8_t slotIndex, IconBufferMem & icon);
    void loadIcon(uint8_t slotIndex, IconBufferMem & icon);


private:
    void initSlot(uint8_t slotIndex);
    void saveSlot(uint8_t slotIndex);



};


#endif //PBLOCKICONS_ICONSTORAGE_H
