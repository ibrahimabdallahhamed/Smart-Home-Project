#include "../../LIB/BITMATH.h"
#include "../../LIB/STDTYPES.h"
#include "../../MCAL/GPIO/GPIO_Interface.h"
#include "KEYPAD_interface.h"

void KEYPAD_voidKeyPadInt(KeyPad_T *Copy_stKeyPad)
{
    for (u8 i = 0; i < ROW; i++)
    {
        GPIO_VoidSetPinDirection(Copy_stKeyPad->RowPinConfig[i].Port, Copy_stKeyPad->RowPinConfig[i].Pin, OUTPUT);
    }
    for (u8 i = 0; i < COULM; i++)
    {
        GPIO_VoidSetPinDirection(Copy_stKeyPad->CoulmPinConfig[i].Port, Copy_stKeyPad->CoulmPinConfig[i].Pin, INPUT);
    }
}
u8 KEYPAD_u8KeyPadPressed(KeyPad_T *Copy_stKeyPad)
{
    u8 Local_u8KeypadPressed = 0xFF;
    u8 Local_u8GPIOReturned = 0;
    for (u8 i = 0; i < ROW; i++)
    {

        for (u8 q = 0; q < ROW; q++)
        {

            GPIO_VoidSetPinMode(Copy_stKeyPad->RowPinConfig[q].Port, Copy_stKeyPad->RowPinConfig[q].Pin, LOW);
        }
        GPIO_VoidSetPinMode(Copy_stKeyPad->RowPinConfig[i].Port, Copy_stKeyPad->RowPinConfig[i].Pin, HIGH);
        __delay_ms(10);
        for (u8 j = 0; j < COULM; j++)
        {

            Local_u8GPIOReturned = GPIO_u8ReadPin(Copy_stKeyPad->CoulmPinConfig[j].Port, Copy_stKeyPad->CoulmPinConfig[j].Pin);
            if (Local_u8GPIOReturned == 1)
            {
                Local_u8KeypadPressed = Au8elements[i][j];
            }
        }
    }
    return Local_u8KeypadPressed;
}
u16 KEYPAD_u16KeypadReturnNumber(KeyPad_T *Copy_stKeyPad)
{
    u8 Local_Au8Number[6] = {0};
    u8 Local_u8KeyPadPreesed = 0;
    u8 Local_u8Counter = 0;
    u16 Local_u16ReturnNumber = 0;
    while (Local_u8KeyPadPreesed != 'c')
    {

        Local_u8KeyPadPreesed = KEYPAD_u8KeyPadPressed(Copy_stKeyPad);
        if (Local_u8KeyPadPreesed == 0xff)
        {
        }
        else if (Local_u8KeyPadPreesed != 'c' && Local_u8KeyPadPreesed != '=' && Local_u8KeyPadPreesed != '+' && Local_u8KeyPadPreesed != '*' && Local_u8KeyPadPreesed != '/' && Local_u8KeyPadPreesed != '-')
        {
            Local_Au8Number[Local_u8Counter] = Local_u8KeyPadPreesed;
            Local_u8Counter++;
        }
    }
    if (Local_u8Counter != 0)
    {
        for (u8 i = 0; i < Local_u8Counter; i++)
        {
            Local_u16ReturnNumber *= 10;
            Local_u16ReturnNumber += Local_Au8Number[i];
        }
    }
    return Local_u16ReturnNumber;
}
