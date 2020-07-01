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

//use Arduino Library Manager to install and include new libraries
// #include <Particle.h>  // for particle projects
#include <Arduino.h>
//#include <Keypad.h>

#include "Led_Matrix.h"
#include "JoyStick.h"
#include "PushButton.h"

//-----------------------------------------------------------------------------------------------------
// pin initializations


//-----------------------------------------------------------------------------------------------------
// variables


//-----------------------------------------------------------------------------------------------------
void setup()
{
    Serial.begin(9600);
    Serial.println("JT's arduino project ready\n");

    // inputs

    // outputs
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


 int convert_analogIn(int data)
 {
    return (data * 9 / 1024) + 48;
 }

