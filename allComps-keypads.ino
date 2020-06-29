/*****************************************************************************************************
 * This Module contains code for
 * leds
 * push button
 * 4x4 keypads
 *****************************************************************************************************/
// cmd+P to open command palatte, type '>' for all Arduino menu options
// #include <Particle.h>  // for particle projects
#include <Arduino.h>
//#include <Keypad.h>

//use Arduino Library Manager to install and include new libraries
//#include "Keypad_defs.h"
//#include "Led_Matrix.h"


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
                
int GPIO_SR_CLK = 5;
int GPIO_SR_LATCH = 4; // pins connected to shift registors
int GPIO_SR_DATA = 3;

int GPIO_MATRIX_COLS [8] = {6, 7, 8, 9, 10, 11, 12, 13}; // maps column 1-8


void display_Character(byte ch[8]);
void shiftRegister_Write(uint8_t dataPin, uint8_t clockPin, uint8_t bitOrder, uint8_t val);
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

    // 8x8 matrix Pin configuration
    pinMode(GPIO_SR_LATCH, OUTPUT);
    pinMode(GPIO_SR_CLK, OUTPUT);
    pinMode(GPIO_SR_DATA, OUTPUT);

    for (int i = 0; i < 8; i++) {
        pinMode(GPIO_MATRIX_COLS[i], OUTPUT);
        digitalWrite(GPIO_MATRIX_COLS[i], HIGH);
    }

    //Serial.begin(9600);
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

void display_Character(byte ch[8])
{
  for (int j = 0; j < 8; j++) {
    digitalWrite(GPIO_SR_LATCH, LOW);
    digitalWrite(GPIO_MATRIX_COLS[j], LOW);

    shiftRegister_Write(GPIO_SR_DATA, GPIO_SR_CLK, MSBFIRST, ch[j]);
    digitalWrite(GPIO_SR_LATCH, HIGH);
    //delay(1);
    digitalWrite(GPIO_SR_LATCH, LOW);
    shiftRegister_Write(GPIO_SR_DATA, GPIO_SR_CLK, MSBFIRST, B00000000); // to get rid of flicker when
    digitalWrite(GPIO_SR_LATCH, HIGH);
    digitalWrite(GPIO_MATRIX_COLS[j], HIGH);

  }
}

void shiftRegister_Write(uint8_t dataPin, uint8_t clockPin, uint8_t bitOrder, uint8_t val)
{
	uint8_t i;

	for (i = 0; i < 8; i++)  {
		if (bitOrder == LSBFIRST)
			digitalWrite(dataPin, !!(val & (1 << i)));
		else	
			digitalWrite(dataPin, !!(val & (1 << (7 - i))));
			
		digitalWrite(clockPin, HIGH);
		digitalWrite(clockPin, LOW);		
	}
}


//-----------------------------------------------------------------------------------------------------
// Main loop
void loop()
{

   for (int k = 0; k < 1000; k++) {
    display_Character(I);
   }
   for (int k = 0; k < 1000; k++) {
    display_Character(HEART);
   }
   for (int k = 0; k < 1000; k++) {
    display_Character(MOM);
   }

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