#ifndef _LED_MATRIX_H_
#define _LED_MATRIX_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

//-----------------------------------------------------------------------------------------------------
// Public Prototypes

void LED_Matrix__Run(void);
void LED_Matrix__Setup(void);
void LED_Matrix__Reset(void);
void LED_Matrix__Home_Screen(void);

void LED_Matrix__Draw_Pixel(int x_value, int y_value);
void LED_Matrix__Draw_Patteren(uint8_t ch[8]);


//-----------------------------------------------------------------------------------------------------
// Private Prototypes
void shiftRegister_Write(uint8_t dataPin, uint8_t clockPin, uint8_t bitOrder, uint8_t val);

#ifdef __cplusplus
}
#endif

#endif

/*
#ifndef _JOYSTICK_H_
#define _JOYSTICK_H_

//#include <Arduino.h>



void JoyStick_Run(void);

#endif //_JOYSTICK_H_
*/

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



// below is called in loop
*/ 

    /*
    //keypad controls
    char key = kpd.getKey();
    if(key)
    {
        switch(key)
        {
            case '1':
            digitalWrite(GPIO_LED_BLUE, HIGH);
            break;
            case '2':
            digitalWrite(GPIO_LED_BLUE, LOW);
            break;
        }
    }
    */