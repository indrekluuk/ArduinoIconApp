//
// Created by indrek on 18.05.2017.
//

#ifndef PBLOCKICONS_EEPROM_H_H
#define PBLOCKICONS_EEPROM_H_H


class FakeEEPROM {

public:
    int length() { return 0; }
    int read(int) { return 0; }
    int write(int, int) {}
};


extern FakeEEPROM EEPROM;


#endif //PBLOCKICONS_EEPROM_H_H
