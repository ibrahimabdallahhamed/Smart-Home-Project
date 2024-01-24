/*
 * File:   DCMotor_interface.h
 * Author: dell
 *
 * Created on October 8, 2023, 10:57 PM
 */

#ifndef DCMOTOR_INTERFACE_H
#define DCMOTOR_INTERFACE_H
#include "../../LIB/BITMATH.h"
#include "../../LIB/STDTYPES.h"
#include "../../MCAL/GPIO/GPIO_Interface.h"
#include "../../MCAL/CCP/CCP.h"

typedef struct
{
    u8 Port;
    u8 EN_PIN : 1;
    u8 Pin[2];
} DcMotor_T;

void DCMOTOR_voidDcMotorInt(DcMotor_T *Copy_stDcMotor);
void DCMOTOR_voidDcMotoroTurnOff(DcMotor_T *Copy_stDcMotor);
void DCMOTOR_voidDcMotoroTurnForward(DcMotor_T *Copy_stDcMotor, u8 Copy_u8Speed);
void DCMOTOR_voidDcMotoroTurnReverse(DcMotor_T *Copy_stDcMotor, u8 Copy_u8Speed);

#endif /* DCMOTOR_INTERFACE_H */
