#ifndef SERVO_H
#define SERVO_H
/***********************Includes*****************/
#include "../../LIB/pic18f4620.h"
#include "../../LIB/STDTYPES.h"
#include "../../LIB/BITMATH.h"
#include "../../MCAL/CCP/CCP.h"
#include "../../MCAL/GPIO/GPIO_Interface.h"
#include "../../MCAL/TIMER3/TIMER3.h"


/*******************MACRO DECLERATIONS***************/

/*******************MACRO FUNCTIONS******************/
/* ----------------- Data Type Declarations -----------------*/
void SERVO_voidServoInit(void);
void SERVO_voidSetAngle(u8 Copy_u8Angle);
f32 map(f32 number, f32 start_1, f32 finish_1, f32 start_2, f32 finish_2);
void Servo_ISR(void);

#endif /* SERVO_H */
