#include "../../LIB/BITMATH.h"
#include "../../LIB/STDTYPES.h"
#include "../../MCAL/GPIO/GPIO_Interface.h"
#include "PushButton_interface.h"

void PushButton_voidPushButtonInt(PushButton_T *Copy_stPushButton)
{
    GPIO_VoidSetPinDirection(Copy_stPushButton->Port, Copy_stPushButton->Pin, INPUT);
}
u8 PushButton_u8Pressed(PushButton_T *Copy_stPushButton)
{
    u8 Local_u8Returned = 0;
    u8 Local_u8ReadPushButton = 0;
    Local_u8ReadPushButton = GPIO_u8ReadPin(Copy_stPushButton->Port, Copy_stPushButton->Pin);

    switch (Copy_stPushButton->Status)
    {
    case PULLUP:
        if (Local_u8ReadPushButton == 1)
        {
            Local_u8Returned = 1;
        }
        else
        {
            Local_u8Returned = 0;
        }
        break;

    case PULLDOWN:
        if (Local_u8ReadPushButton == 1)
        {
            Local_u8Returned = 0;
        }
        else
        {
            Local_u8Returned = 1;
        }
        break;
    }
    return Local_u8Returned;
}
