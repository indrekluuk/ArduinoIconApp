//
// Created by indrek on 29.10.2016.
//


#include "Arduino.h"


FakeSerial Serial;





uint8_t dummy;


void pinMode(int, int) {

}


void delay(int) {

}


uint8_t pgm_read_byte(const uint8_t * pByte) {
  return *pByte;
}


void digitalWrite(int, int) {
}

int analogRead(int) {
}


int map(int, int, int, int, int) {
}


unsigned long millis() {
  return 0;
};


