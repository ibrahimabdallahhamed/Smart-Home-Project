/*
 * File:   KEYPAD_interface.h
 * Author: dell
 *
 * Created on October 12, 2023, 1:44 PM
 */

#ifndef KEYPAD_INTERFACE_H
#define KEYPAD_INTERFACE_H
#include "../../LIB/BITMATH.h"
#include "../../LIB/STDTYPES.h"
#include "../../MCAL/GPIO/GPIO_Interface.h"
#define ROW 4
#define COULM 4

typedef struct
{
    u8 Port;
    u8 Pin;

} PinConfig;

typedef struct
{
    PinConfig RowPinConfig[ROW];
    PinConfig CoulmPinConfig[COULM];
} KeyPad_T;

u8 Au8elements[ROW][COULM] = {
    {7, 8, 9, '/'},
    {4, 5, 6, '*'},
    {1, 2, 3, '-'},
    {'c', 0, '=', '+'}};
void KEYPAD_voidKeyPadInt(KeyPad_T *Copy_stKeyPad);
u8 KEYPAD_u8KeyPadPressed(KeyPad_T *Copy_stKeyPad);
u16 KEYPAD_u16KeypadReturnNumber(KeyPad_T *Copy_stKeyPad);
#endif /* KEYPAD_INTERFACE_H */
