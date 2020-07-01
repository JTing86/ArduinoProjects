#ifndef _PUSHBUTTON_H_
#define _PUSHBUTTON_H_


void PushButton_control_led_setup(void);
void PushButton_control_led_run(void);

void pushButton_control(int pinIN);
bool IsButtonToggled(int buttonCounter);


#endif // _PUSHBUTTON_H_



