#include "PushButton.h"
#include <stdbool.h>
#include <Arduino.h>

const int GPIO_BUTTON_RED = 3;
const int GPIO_LED_BLUE = 4;
const int GPIO_LED_RED = 5;
//-----------------------------------------------------------------------------------------------------
// variables
int pushCounter_redButton = 0;

int button_red_curr_state = LOW;
int button_red_prev_state = LOW;



void PushButton_control_led_setup(void)
{
    pinMode(GPIO_BUTTON_RED, INPUT);

    pinMode(GPIO_LED_RED, OUTPUT);
    pinMode(GPIO_LED_BLUE, OUTPUT);
}
void PushButton_control_led_run(void)
{
    pushButton_control(GPIO_BUTTON_RED);

    if (IsButtonToggled(pushCounter_redButton))
    {
        digitalWrite(GPIO_LED_RED, HIGH);
    }else{
        digitalWrite(GPIO_LED_RED, LOW);
    }
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
