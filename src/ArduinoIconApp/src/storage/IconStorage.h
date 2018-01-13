//
// Created by indrek on 7.05.2017.
//

#ifndef PBLOCKICONS_ICONSTORAGE_H
#define PBLOCKICONS_ICONSTORAGE_H



#include <stdint.h>
#include "../icons/Icon.h"



struct StorageHeader {
    uint8_t dataStructureVersion;
};

struct IconStorageData {
    uint16_t bitmap[Icon::BITMAP_HEIGHT];
    uint16_t foregroundColor;
    uint16_t backgroundColor;
    uint16_t borderColor;
    uint8_t hasBorder : 1;
    uint8_t is3d : 1;
    uint8_t scale : 6;
};


class IconStorage {
    static const uint8_t STRUCTURE_VERSION = 1;

public:
    static const uint16_t ICON_COUNT = (1000 - sizeof(StorageHeader)) / sizeof(IconStorageData);

    struct StorageStructure {
        StorageHeader header;
        IconStorageData data[ICON_COUNT];
    };


    IconStorage();

    IconStorageData readIconData(uint16_t iconIndex, IconStorageData & data);
    void writeIconData(uint16_t iconIndex, IconStorageData & data);

private:
    StorageStructure * structure = 0;

    uint8_t getCurrentStructureVersion();
    void saveCurrentStructureVersion();

    uint8_t readMemByte(void * addr);
    void readMemBytes(void * addr, uint16_t cnt, void * toAddr);
    void writeMemByte(void * addr, uint8_t byte);
    void writeMemBytes(void * addr, uint16_t cnt, void * fromAddr);

};


#endif //PBLOCKICONS_ICONSTORAGE_H
