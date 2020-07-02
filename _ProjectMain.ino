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
// need extern C macro otherwise functions in the header file would be undefined, this enabled calling a C fcn from a C++ fcn


//use Arduino Library Manager to install and include new libraries
// #include <Particle.h>  // for particle projects
#include <Arduino.h>
#include <stdint.h>

#include "JoyStick.h"
#include "PushButton.h"
#include "Led_Matrix.h"


//-----------------------------------------------------------------------------------------------------
// pin initializations


//-----------------------------------------------------------------------------------------------------
// variables


//-----------------------------------------------------------------------------------------------------
void setup()
{
    Serial.begin(9600);
    Serial.println("JT's arduino project ready\n");
    
    LED_Matrix__Setup();
    LED_Matrix__Home_Screen();
    LED_Matrix__Reset();
    
}
//-----------------------------------------------------------------------------------------------------
// Main loop
PIXEL_t current_pixel;
void loop()
{
    //Serial.print("Led matrix starting: \n");
    
    current_pixel = JoyStick__Get_Position();
    Serial.print(current_pixel.x_pos);
    Serial.print(",\t");
    Serial.println(current_pixel.y_pos);

    LED_Matrix__Reset();
    //LED_Matrix__Draw_Pixel(5, 3);
    LED_Matrix__Draw_Pixel(current_pixel.x_pos, current_pixel.y_pos);
    delay(1);
}
//-----------------------------------------------------------------------------------------------------
// Public Prototypes
