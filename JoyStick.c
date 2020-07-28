#include "JoyStick.h"
#include <Arduino.h>

//no setting up GPIO direction is required for Joystick analog pin

//-----------------------------------------------------------------------------------------------------
// pin initializations
/*
// game controller button (4 directions)
const int GPIO_JOY_X = A0;
const int GPIO_JOY_Y = A1;


//-----------------------------------------------------------------------------------------------------
// variables

int joy_X_value,joy_Y_value, xMap, yMap = 0;

//-----------------------------------------------------------------------------------------------------
// Public Prototypes

PIXEL_t JoyStick__Get_Position(void)
{
    PIXEL_t current_pos;
    joy_X_value = analogRead(GPIO_JOY_X);
    joy_Y_value = analogRead(GPIO_JOY_Y);

    current_pos.x_pos = map(joy_X_value, 0,1021, 0, 7);
    current_pos.y_pos = map(joy_Y_value, 0,1021, 7, 0);

    return current_pos;
  //print the values with to plot or view
  /*
    Serial.print(xMap);
    Serial.print(",\t");
    Serial.println(yMap);
}
    */

