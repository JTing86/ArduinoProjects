#include "Led_Matrix.h"
/*

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
*/