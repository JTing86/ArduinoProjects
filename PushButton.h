#ifndef _PUSHBUTTON_H_
#define _PUSHBUTTON_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

void PushButton_control_led_setup(void);
void PushButton_control_led_run(void);

void pushButton_control(int pinIN);
bool IsButtonToggled(int buttonCounter);

#ifdef __cplusplus
}
#endif

#endif // _PUSHBUTTON_H_



