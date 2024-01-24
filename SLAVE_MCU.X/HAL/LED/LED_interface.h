/*
 * File:   LED_interface.h
 * Author: dell
 *
 * Created on October 7, 2023, 7:04 PM
 */

#ifndef LED_INTERFACE_H
#define LED_INTERFACE_H

#include "../../LIB/STDTYPES.h"
#include "../../LIB/BITMATH.h"
typedef struct
{
    u8 Port;
    u8 Pin;
    u8 Stauts;
} LED_T;

void LED_voidLedInt(LED_T *Copy_stLed);
void LED_voidLedOn(LED_T *Copy_stLed);
void LED_voidLedOff(LED_T *Copy_stLed);

#define CommonAnode   1
#define CommonCathode 0

#endif /* LED_INTERFACE_H */
