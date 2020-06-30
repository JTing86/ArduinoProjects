#ifndef _MATRIX_PATTERENS_H_
#define _MATRIX_PATTERENS_H_

#include <Arduino.h>


byte I[8] = {     B01111100,
                  B00010000,
                  B00010000,
                  B00010000,
                  B00010000,
                  B00010000,
                  B00010000,
                  B01111100
                };
byte HEART[8] = { B00000000,
                  B01101100,
                  B11111110,
                  B01111100,
                  B00111000,
                  B00010000,
                  B00000000,
                  B00000000
                };

byte LIN[8] = {   B00000100,
                  B00100100,
                  B11111111,
                  B01110100,
                  B10101110,
                  B10110101,
                  B00100100,
                  B00000100
                };  
byte MOM[8] = {   B00001110,
                  B10100010,
                  B11101010,
                  B10101111,
                  B01000001,
                  B10101101,
                  B00000001,
                  B00000111
                };


// PIN initializations for keypad
/*
int GPIO_LED_RED = 8;
int GPIO_LED_BLUE = 9;
int GPIO_BUTTON_RED = 2;

//4x4 keypad 
// wiring instruction, Left -> Right: R1-R4,C1-C4
int GPIO_KEYPAD_R1 = 10;
int GPIO_KEYPAD_R2 = 11;
int GPIO_KEYPAD_R3 = 12;
int GPIO_KEYPAD_R4 = 13;
int GPIO_KEYPAD_C1 = 19; //pin A5-A0 =19-16
int GPIO_KEYPAD_C2 = 18;
int GPIO_KEYPAD_C3 = 17;
int GPIO_KEYPAD_C4 = 16;

const byte ROWS = 4; // Four rows
const byte COLS = 4; // Four columns

// Define the Keymap
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'#','0','*','D'}
};

byte colPins[COLS] = { 19, 18, 17, 16 }; // Row 0 to 3
byte rowPins[ROWS] = { 10, 11, 12, 13 }; // Col 0 to 3

Keypad kpd = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

*/

#endif