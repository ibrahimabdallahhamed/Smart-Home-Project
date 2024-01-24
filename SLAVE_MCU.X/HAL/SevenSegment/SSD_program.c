#include "../../MCAL/GPIO/GPIO_Interface.h"
#include "SSD_config.h"
#include "SSD_interface.h"
#if TYPE_CONNECTION == WITHOUT_BCD

void SSD_voidSSDInt(SSD_T *Copy_stSSD)
{
    GPIO_VoidSetPortDirection(Copy_stSSD->Port, OUTPUT);
}
void SSD_voidSSDWriteNumber(SSD_T *Copy_stSSD, u8 Copy_u8SSDNumber)
{
    if (Copy_u8SSDNumber < 10)
    {
        switch (Copy_stSSD->Status)
        {
        case CommonCathode:

            GPIO_VoidWriteLogicPortMode(Copy_stSSD->Port, SSD_Au8Numbers[Copy_u8SSDNumber]);
            break;

        case CommonAnode:

            GPIO_VoidWriteLogicPortMode(Copy_stSSD->Port, ~SSD_Au8Numbers[Copy_u8SSDNumber]);
            break;

        default:
            break;
        }
    }
    else
    {
        /*nothing*/
    }
}
#endif
#if (TYPE_CONNECTION == WITH_BCD)

void SSD_voidSSD_BCDInt(SSD_T *Copy_stSSD)
{
    GPIO_VoidSetPinDirection(Copy_stSSD->PinConfig[0].Port, Copy_stSSD->PinConfig[0].Pin, OUTPUT);
    GPIO_VoidSetPinDirection(Copy_stSSD->PinConfig[1].Port, Copy_stSSD->PinConfig[1].Pin, OUTPUT);
    GPIO_VoidSetPinDirection(Copy_stSSD->PinConfig[2].Port, Copy_stSSD->PinConfig[2].Pin, OUTPUT);
    GPIO_VoidSetPinDirection(Copy_stSSD->PinConfig[3].Port, Copy_stSSD->PinConfig[3].Pin, OUTPUT);
}
void SSD_voidSSD_BCDWriteNumber(SSD_T *Copy_stSSD, u8 Copy_u8SSDNumber)
{
    GPIO_VoidWriteLogicPinMode(Copy_stSSD->PinConfig[0].Port, Copy_stSSD->PinConfig[0].Pin, (Copy_u8SSDNumber >> 0) & 1);
    GPIO_VoidWriteLogicPinMode(Copy_stSSD->PinConfig[1].Port, Copy_stSSD->PinConfig[1].Pin, (Copy_u8SSDNumber >> 1) & 1);
    GPIO_VoidWriteLogicPinMode(Copy_stSSD->PinConfig[2].Port, Copy_stSSD->PinConfig[2].Pin, (Copy_u8SSDNumber >> 2) & 1);
    GPIO_VoidWriteLogicPinMode(Copy_stSSD->PinConfig[3].Port, Copy_stSSD->PinConfig[3].Pin, (Copy_u8SSDNumber >> 3) & 1);
}

#endif
