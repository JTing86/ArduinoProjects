#include "Led_Matrix.h"
#include <Arduino.h>

const int GPIO_SR_CLK = 5;
const int GPIO_SR_LATCH = 4; // pins connected to shift registors
const int GPIO_SR_DATA = 3;

int GPIO_MATRIX_COLS [8] = {6, 7, 8, 9, 10, 11, 12, 13}; // maps column 1-8


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

int interval = 200;
int matrix_len = 8;
//-----------------------------------------------------------------------------------------------------
// Setup and Main

// being called in the loop
void LED_Matrix__Run(void)
{
   for (int k = 0; k < interval; k++) {
    LED_Matrix__Draw_Patteren(I);
   }
   for (int k = 0; k < interval; k++) {
    LED_Matrix__Draw_Patteren(HEART);
   }
   for (int k = 0; k < interval; k++) {
    LED_Matrix__Draw_Patteren(MOM);
   }
}

// bring called in the setup
void LED_Matrix__Setup(void)
{
    // 8x8 matrix Pin configuration
    pinMode(GPIO_SR_LATCH, OUTPUT);
    pinMode(GPIO_SR_CLK, OUTPUT);
    pinMode(GPIO_SR_DATA, OUTPUT);

    for (int i = 0; i < matrix_len; i++) {
        pinMode(GPIO_MATRIX_COLS[i], OUTPUT);
        digitalWrite(GPIO_MATRIX_COLS[i], HIGH);
    }
    digitalWrite(GPIO_SR_LATCH, LOW);
    shiftRegister_Write(GPIO_SR_DATA, GPIO_SR_CLK, MSBFIRST, B11111111);
    digitalWrite(GPIO_SR_LATCH, HIGH);
}

//-----------------------------------------------------------------------------------------------------
// Public Prototypes

/******************************************************************************************************
 * needed feature for matrix mapping:
 * input coordinate int x_value y_value in the range of 0-7
 ******************************************************************************************************/

void LED_Matrix__Reset(void)
{
    //turn off all pins by setting all rows and colns to high
    //set all cols to high
    for (int i=0;i<matrix_len;i++)
    {
        digitalWrite(GPIO_MATRIX_COLS[i],HIGH);
    }

    //set all row to high
    digitalWrite(GPIO_SR_LATCH, LOW);
    shiftRegister_Write(GPIO_SR_DATA, GPIO_SR_CLK, MSBFIRST, B11111111);
    digitalWrite(GPIO_SR_LATCH, HIGH);
}

void LED_Matrix__Home_Screen(void)
{
    //turn off all pins by setting all rows and colns to high
    //set all cols to high
    for (int i=0;i<matrix_len;i++)
    {
        digitalWrite(GPIO_MATRIX_COLS[i],LOW);
    }

    //set all row to high
    digitalWrite(GPIO_SR_LATCH, LOW);
    shiftRegister_Write(GPIO_SR_DATA, GPIO_SR_CLK, MSBFIRST, B11111111);
    digitalWrite(GPIO_SR_LATCH, HIGH);

    delay(500);
}

void LED_Matrix__Draw_Pixel(int x_value, int y_value) //x: col,  y: row
{
  // to turn on col3,row4, just need to pull col high and attatch row 4 to groud

    digitalWrite(GPIO_SR_LATCH, LOW);
    digitalWrite(GPIO_MATRIX_COLS[x_value], LOW);

    uint8_t row_map = 1 << (matrix_len - y_value);

    shiftRegister_Write(GPIO_SR_DATA, GPIO_SR_CLK, MSBFIRST, row_map);
    digitalWrite(GPIO_SR_LATCH, HIGH); //SR would copy data from internal storage to output when LATCH goes from LOW to HIGH
  
    delay(500);
  
    digitalWrite(GPIO_SR_LATCH, LOW);
    shiftRegister_Write(GPIO_SR_DATA, GPIO_SR_CLK, MSBFIRST, B00000000);
    digitalWrite(GPIO_SR_LATCH, HIGH);
    digitalWrite(GPIO_MATRIX_COLS[x_value], HIGH);
}

void LED_Matrix__Draw_Patteren(byte ch[8])
{
  for (int j = 0; j < matrix_len; j++) {
    digitalWrite(GPIO_SR_LATCH, LOW);
    digitalWrite(GPIO_MATRIX_COLS[j], LOW); // turn on the whole column

    shiftRegister_Write(GPIO_SR_DATA, GPIO_SR_CLK, MSBFIRST, ch[j]);// only the rows with a one would make a voltage difference with the LOW column
    digitalWrite(GPIO_SR_LATCH, HIGH); //SR would copy data from internal storage to output when LATCH goes from LOW to HIGH
    //delay(1);
    digitalWrite(GPIO_SR_LATCH, LOW);
    shiftRegister_Write(GPIO_SR_DATA, GPIO_SR_CLK, MSBFIRST, B00000000); // to get rid of flicker
    digitalWrite(GPIO_SR_LATCH, HIGH);//turn off the whole column
    digitalWrite(GPIO_MATRIX_COLS[j], HIGH);

  }
}

//-----------------------------------------------------------------------------------------------------
// Private Prototypes

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
