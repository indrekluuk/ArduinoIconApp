//
// Created by indrek on 18.05.2017.
//

#ifndef ARDUINOICONAPP_EEPROM_H
#define ARDUINOICONAPP_EEPROM_H


class FakeEEPROM {

public:
    int length() { return 0; }
    int read(int) { return 0; }
    int write(int, int) {}
};


extern FakeEEPROM EEPROM;


#endif //ARDUINOICONAPP_EEPROM_H
