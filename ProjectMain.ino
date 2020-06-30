/*****************************************************************************************************
 * This Module contains code for
 * leds
 * push button
 * 4x4 keypads
 * 8x8 Led Matrix
 *****************************************************************************************************/
// cmd+P to open command palatte, type '>' for all Arduino menu options
// disabled vscode-clang c/c++ command adapter extension to get rid of arduino.h file not found red underline
// added "defines" : [ "USBCON"] to get rid of Serial red underline


// #include <Particle.h>  // for particle projects
#include <Arduino.h>
//#include <Keypad.h>

//use Arduino Library Manager to install and include new libraries
//#include "Keypad_defs.h"
//#include "Led_Matrix.h"
#include "JoyStick.h"

//-----------------------------------------------------------------------------------------------------
// pin initializations

/*
typedef enum{
    PUSHBUTTON_OFF = 0,
    PUSHBUTTON_ON  = 1,
}PUSHBUTTON_STATE_e;
*/
// game controller button (4 directions)
const int GPIO_JOY_X = A0;
const int GPIO_JOY_Y = A1;

//-----------------------------------------------------------------------------------------------------
// variables
int pushCounter_redButton = 0;
//int state_redButton = 0;
int button_red_curr_state = LOW;
int button_red_prev_state = LOW;

int joy_X_value,joy_Y_value, xMap, yMap = 0;


//-----------------------------------------------------------------------------------------------------
void setup()
{
    Serial.begin(9600);
    Serial.println("JT's arduino project ready\n");


    // inputs
    /*
    pinMode(GPIO_BUTTON_RED, INPUT);
    */
    //outputs
    /*
    pinMode(GPIO_LED_RED, OUTPUT);
    pinMode(GPIO_LED_BLUE, OUTPUT);
    */
    //LedMatrix_Setup();
}
//-----------------------------------------------------------------------------------------------------
// Main loop
void loop()
{
    //Serial.print("Led matrix starting: \n");
    //LedMatrix_Run();

    JoyStick_Run();

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
void JoyStick_Run(void)
{
    joy_X_value = analogRead(GPIO_JOY_X);
    joy_Y_value = analogRead(GPIO_JOY_Y);

    xMap = map(joy_X_value, 0,1023, 0, 7);
    yMap = map(joy_Y_value,0,1023,7,0);
  //print the values with to plot or view
    Serial.print(xMap);
    Serial.print(",\t");
    Serial.println(yMap);
}

 int convert_analogIn(int data)
 {
    return (data * 9 / 1024) + 48;
 }

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