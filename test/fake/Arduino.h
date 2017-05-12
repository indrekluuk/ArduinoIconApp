//
// Created by indrek on 29.10.2016.
//

#ifndef PBLOCKMAIN_ARDUINO_H
#define PBLOCKMAIN_ARDUINO_H


#include <stdint.h>


extern uint8_t dummy;


#define __AVR_ATmega328P__ dummy
#define ARDUINO 180

#define boolean bool

#define PINB 0
#define PINC 0
#define PIND 0
#define A1 0
#define A2 0
#define A3 0
#define A4 0
#define A5 0
#define A6 0
#define INPUT 0
#define OUTPUT 1

#define HIGH 1
#define LOW 0


#define PROGMEM
#define TCCR2A dummy
#define _BV(p) p
#define COM2A1 dummy
#define COM2B1 dummy
#define WGM21 dummy
#define WGM20 dummy
#define TCCR2B dummy
#define WGM22 dummy
#define CS20 dummy
#define OCR2A dummy
#define OCR2B dummy


#define abs(x) ((x)>0?(x):-(x))

void pinMode(int, int);
void delay(int);
uint8_t pgm_read_byte(const uint8_t * pByte);
void digitalWrite(int, int);
int analogRead(int);
int map(int, int, int, int, int);

unsigned long millis();


class FakeSerial {

public:
    void begin(int) {};
    void print(const char * c) {};
    void print(int) {};
    void println() {};
    void println(const char * c) {};
};


extern FakeSerial Serial;

#endif //PBLOCKMAIN_ARDUINO_H



