#ifndef _JOYSTICK_H_
#define _JOYSTICK_H_

#ifdef __cplusplus
extern "C" {
#endif

typedef struct{
    int x_pos;
    int y_pos;
}PIXEL_t;

PIXEL_t JoyStick__Get_Position(void);

#ifdef __cplusplus
}
#endif

#endif //_JOYSTICK_H_