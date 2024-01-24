/*
 * File:   GPIO_Interface.h
 * Author: dell
 *
 * Created on October 7, 2023, 11:39 AM
 */

#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H
#include "../../LIB/STDTYPES.h"
#include "GPIO_REG.h"

typedef struct
{
    u8 Port : 3;
    u8 Pin : 3;
    u8 Direction : 1;
    u8 Logic : 1;
} PinConfig_T;
void GPIO_VoidSetPortDirection(u8 Copy_u8Port, u8 Copy_u8Direction);
void GPIO_VoidSetPortMode(u8 Copy_u8Port, u8 Copy_u8Mode);
void GPIO_VoidWriteLogicPortDirection(u8 Copy_u8Port, u8 Copy_u8LogicDirection);
void GPIO_VoidWriteLogicPortMode(u8 Copy_u8Port, u8 Copy_u8LogicMode);

void GPIO_VoidSetPinDirection(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Direction);
void GPIO_VoidSetPinMode(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Mode);
void GPIO_VoidWriteLogicPinDirection(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8LogicDirection);
void GPIO_VoidWriteLogicPinMode(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8LogicMode);
u8 GPIO_u8ReadPin(u8 Copy_u8Port, u8 Copy_u8Pin);

#define PORT_A 0
#define PORT_B 1
#define PORT_C 2
#define PORT_D 3
#define PORT_E 4

#define PIN_0 0
#define PIN_1 1
#define PIN_2 2
#define PIN_3 3
#define PIN_4 4
#define PIN_5 5
#define PIN_6 6
#define PIN_7 7

#define OUTPUT 0
#define INPUT 1

#define HIGH 1
#define LOW 0

#endif /* GPIO_INTERFACE_H */
