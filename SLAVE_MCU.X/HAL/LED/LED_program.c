#include "../../MCAL/GPIO/GPIO_Interface.h"
#include "LED_interface.h"

void LED_voidLedInt(LED_T *Copy_stLed) {
    GPIO_VoidSetPinDirection(Copy_stLed->Port, Copy_stLed->Pin, OUTPUT);
    switch (Copy_stLed->Stauts) {
        case CommonAnode:
            GPIO_VoidSetPinMode(Copy_stLed->Port, Copy_stLed->Pin, HIGH);
            break;

        case CommonCathode:
            GPIO_VoidSetPinMode(Copy_stLed->Port, Copy_stLed->Pin, LOW);
            break;
    }
}

void LED_voidLedOn(LED_T * Copy_stLed) {
    switch (Copy_stLed->Stauts) {
        case CommonAnode:
            GPIO_VoidSetPinMode(Copy_stLed->Port, Copy_stLed->Pin, LOW);
            break;

        case CommonCathode:
            GPIO_VoidSetPinMode(Copy_stLed->Port, Copy_stLed->Pin, HIGH);

            break;

        default:
            break;
    }
}

void LED_voidLedOff(LED_T * Copy_stLed) {
    switch (Copy_stLed->Stauts) {
        case CommonAnode:
            GPIO_VoidSetPinMode(Copy_stLed->Port, Copy_stLed->Pin, HIGH);
            break;

        case CommonCathode:
            GPIO_VoidSetPinMode(Copy_stLed->Port, Copy_stLed->Pin, LOW);
            break;

        default:
            break;
    }
}
