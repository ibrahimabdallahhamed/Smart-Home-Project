/* 
 * File:   PushButton_interface.h
 * Author: dell
 *
 * Created on October 7, 2023, 8:59 PM
 */

#ifndef PUSHBUTTON_INTERFACE_H
#define	PUSHBUTTON_INTERFACE_H
typedef struct 
{
    u8 Port ;
    u8 Pin ;
    u8 Status; 
}PushButton_T;

void PushButton_voidPushButtonInt(PushButton_T* Copy_stPushButton);
u8   PushButton_u8Pressed(PushButton_T* Copy_stPushButton);

#define PULLUP      1
#define PULLDOWN    0


#define PRESSED    1
#define UNPRESSED  0


#endif	/* PUSHBUTTON_INTERFACE_H */

