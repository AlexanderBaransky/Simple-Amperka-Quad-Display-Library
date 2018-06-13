#ifndef SIMPLE_AMPERKA_QUAD_DISPLAY
#define SIMPLE_AMPERKA_QUAD_DISPLAY

#include <Arduino.h>
#include "pins_arduino.h"
#include <inttypes.h> 
#include <SPI.h>
/*

    ___7___
   /       \
  |         |
 2|         |6
   \___1___/
   /       \
  |         |
 3|         |5
   \___4___/
               *0
 */

#define qd_none 0b11111111
#define qd_dot 0b11111110
#define qd_minus 0b11111101

#define qd__ 0b11101111
#define qd_degree 0b00111001
#define qd_under_degree 0b11000101


#define qd_0 0b00000011
#define qd_1 0b10011111
#define qd_2 0b00100101
#define qd_3 0b00001101
#define qd_4 0b10011001
#define qd_5 0b01001001
#define qd_6 0b01000001
#define qd_7 0b00011111
#define qd_8 0b00000001
#define qd_9 0b00001001

#define qd_A 0b00010001
#define qd_a 0b00000101
#define qd_b 0b11000001
#define qd_C 0b01100011
#define qd_c 0b11100101
#define qd_d 0b10000101
#define qd_E 0b01100001
#define qd_f 0b01110001
#define qd_F qd_f
#define qd_G qd_6
#define qd_H 0b10010001
#define qd_h 0b11010001
#define qd_I qd_1
#define qd_J 0b10001111
#define qd_K qd_H
#define qd_L 0b11100011
#define qd_n 0b11010101
#define qd_o 0b11000101
#define qd_O qd_0
#define qd_P 0b00110001
#define qd_r 0b11110101
#define qd_S 0b01001001
#define qd_t 0b11100001
#define qd_u 0b11000111
#define qd_U 0b10000011
#define qd_V qd_U
#define qd_X qd_H
#define qd_Y 0b10001001
#define qd_Z qd_2

class QuadDisplay
{
private:
    unsigned long _startMillis = millis();
    bool _state;
    uint8_t _pinSCK;
    uint8_t _pinDI;
    uint8_t _pinCS;
    void beginWrite();
    void writeData(uint8_t data, uint8_t n = 8);
    void writeData(uint32_t data, uint8_t n = 32);
    void endWrite();
public:
    QuadDisplay(uint8_t pinCS);
    QuadDisplay(uint8_t pinCS, uint8_t pinMOSI, uint8_t pinSCK);
    void begin();
    void end();
    void displayInt(int val, bool padZeros = false, uint8_t dots = 0x00);
    void displayFloat(float val, uint8_t precision, bool padZeros = false);
    void displayDigits(uint8_t digit1, uint8_t digit2, uint8_t digit3, uint8_t digit4);
    void displaySegments(uint32_t digits);
    void displayTemperatureC(int val, bool padZeros = false);
    void displayHumidity(int val, bool padZeros = false);
    void displayScore(int hour, int minute, bool blink = false);
    void displayClear();

};

#endif
