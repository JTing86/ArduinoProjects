#include <MQTT.h>
#include <MQTTClient.h>
#include <IRremote.h>
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

//#include "JoyStick.h"
//#include "PushButton.h"
//#include "Led_Matrix.h"


//-----------------------------------------------------------------------------------------------------
// pin initializations


//-----------------------------------------------------------------------------------------------------
// variables
IRsend irsend;

const int RECV_PIN = 7; // define input pin on Arduino 
IRrecv irrecv(RECV_PIN); 
decode_results results; // decode_results class is defined in IRremote.h



//-----------------------------------------------------------------------------------------------------
void setup()
{
    Serial.begin(9600);
    Serial.println("JT's arduino project ready\n");
    /*
    LED_Matrix__Setup();
    LED_Matrix__Home_Screen();
    LED_Matrix__Reset();
    */
    //irrecv.enableIRIn();
    //irrecv.blink13(true);
    irrecv.enableIRIn(); // Start the receiver
}
//-----------------------------------------------------------------------------------------------------
// Main loop
//PIXEL_t current_pixel;
void loop()
{
	if (irrecv.decode(&results)) {
		Serial.println(results.value, HEX); 
		irrecv.resume(); // Receive the next value 
	}
	delay (100); // small delay to prevent reading errors

   for (int i = 0; i < 50; i++) { 
     irsend.sendSony(0xa90, 12); // Sony TV power code
     delay(40);
   }
    /*
    //Serial.print("Led matrix starting: \n");
    current_pixel = JoyStick__Get_Position();
    Serial.print(current_pixel.x_pos);
    Serial.print(",\t");
    Serial.println(current_pixel.y_pos);

    LED_Matrix__Reset();
    //LED_Matrix__Draw_Pixel(5, 3);
    LED_Matrix__Draw_Pixel(current_pixel.x_pos, current_pixel.y_pos);
    delay(1);
    */
}
//-----------------------------------------------------------------------------------------------------
// Public Prototypes
