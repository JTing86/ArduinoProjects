//#include <Keypad.h>
#include <stdint.h>
#include "Keypad_JTLib.h"


//TODO need to make cuztomized lib, c class can't be used in C
// For now to use Keypad just copy everything here to the ProjectMain.ino


//4x4 keypad 
// wiring instruction, Left -> Right: R1-R4,C1-C4
const int GPIO_KEYPAD_R1 = 10;
const int GPIO_KEYPAD_R2 = 11;
const int GPIO_KEYPAD_R3 = 12;
const int GPIO_KEYPAD_R4 = 13;
const int GPIO_KEYPAD_C1 = 19; //pin A5-A0 =19-16
const int GPIO_KEYPAD_C2 = 18;
const int GPIO_KEYPAD_C3 = 17;
const int GPIO_KEYPAD_C4 = 16;

#define  ROW_LEN 4 
#define  COL_LEN  4 //size of an array can't be variables, has to be defined

// Define the Keymap
char keys[ROW_LEN][COL_LEN] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'#','0','*','D'}
};

uint8_t colPins[COL_LEN] = { 19, 18, 17, 16 }; // Row 0 to 3
uint8_t rowPins[ROW_LEN] = { 10, 11, 12, 13 }; // Col 0 to 3

//Keypad kpd = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );


