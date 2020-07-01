#include "Led_Matrix.h"

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


// being called in the loop
void LedMatrix_Run(void)
{
   for (int k = 0; k < interval; k++) {
    display_Character(I);
   }
   for (int k = 0; k < interval; k++) {
    display_Character(HEART);
   }
   for (int k = 0; k < interval; k++) {
    display_Character(MOM);
   }
}

// bring called in the setup
void LedMatrix_Setup(void)
{
    // 8x8 matrix Pin configuration
    pinMode(GPIO_SR_LATCH, OUTPUT);
    pinMode(GPIO_SR_CLK, OUTPUT);
    pinMode(GPIO_SR_DATA, OUTPUT);

    for (int i = 0; i < 8; i++) {
        pinMode(GPIO_MATRIX_COLS[i], OUTPUT);
        digitalWrite(GPIO_MATRIX_COLS[i], HIGH);
    }
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
