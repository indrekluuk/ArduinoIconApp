//
// Created by indrek on 29.10.2016.
//


#include "Arduino.h"
#include "EEPROM.h"

FakeSerial Serial;
FakeEEPROM EEPROM;




uint8_t dummy;


void pinMode(int, int) {

}


void delay(int) {

}


uint8_t pgm_read_byte(const uint8_t * pByte) {
  return *pByte;
}

uint16_t pgm_read_word(const uint16_t * pWord) {
  return *pWord;
}

void digitalWrite(int, int) {
}

int analogRead(int) {
}


int map(int, int, int, int, int) {
}


uint8_t * malloc(uint8_t) {
  return 0;
}

void free(void *) {
}


unsigned long millis() {
  return 0;
};


