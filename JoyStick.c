#include "JoyStick.h"


//-----------------------------------------------------------------------------------------------------
// pin initializations

// game controller button (4 directions)
const int GPIO_JOY_X = A0;
const int GPIO_JOY_Y = A1;


//-----------------------------------------------------------------------------------------------------
// variables

int joy_X_value,joy_Y_value, xMap, yMap = 0;

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