/*****************************************************************************************************
 * This Module contains code for
 * leds
 * push button
 * 4x4 keypads
 * 8x8 Led Matrix
 *****************************************************************************************************/
// cmd+P to open command palatte, type '>' for all Arduino menu options
// disabled vscode-clang c/c++ command adapter extension to get rid of arduino.h file not found red underline


// #include <Particle.h>  // for particle projects
#include <Arduino.h>
//#include <Keypad.h>

//use Arduino Library Manager to install and include new libraries
//#include "Keypad_defs.h"
#include "Led_Matrix.h"


//-----------------------------------------------------------------------------------------------------
// pin initializations
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
/*
typedef enum{
    PUSHBUTTON_OFF = 0,
    PUSHBUTTON_ON  = 1,
}PUSHBUTTON_STATE_e;
*/

//-----------------------------------------------------------------------------------------------------
// variables
int pushCounter_redButton = 0;
//int state_redButton = 0;
int button_red_curr_state = LOW;
int button_red_prev_state = LOW;


//-----------------------------------------------------------------------------------------------------
void setup()
{
    printf("JT's arduino project ready");

    // inputs
    /*
    pinMode(GPIO_BUTTON_RED, INPUT);
    */
    //outputs
    /*
    pinMode(GPIO_LED_RED, OUTPUT);
    pinMode(GPIO_LED_BLUE, OUTPUT);
    */
    LedMatrix_Setup();

    //Serial.begin(9600);
}
//-----------------------------------------------------------------------------------------------------
// Main loop
void loop()
{
    LedMatrix_Run();
    /*
    pushButton_control(GPIO_BUTTON_RED);

    if (IsButtonToggled(pushCounter_redButton))
    {
        digitalWrite(GPIO_LED_RED, HIGH);
    }else{
        digitalWrite(GPIO_LED_RED, LOW);
    }

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

}
//-----------------------------------------------------------------------------------------------------
// Public Prototypes

//this function detects rising edge and increment the pushButtonCounter
void pushButton_control(int pinIN)
{
    button_red_curr_state = digitalRead(pinIN);

    if (button_red_curr_state != button_red_prev_state)// state changes
    {
        if (button_red_curr_state == HIGH) //rising edge
        {
            pushCounter_redButton++;

        }
        else{
            //falling edge
        }
        delay(50); //avoid bouncing
    }
    button_red_prev_state = button_red_curr_state;
}

bool IsButtonToggled(int buttonCounter)
{
    if(buttonCounter % 2 == 0)
    {
        return true;
    }
    return false;
}