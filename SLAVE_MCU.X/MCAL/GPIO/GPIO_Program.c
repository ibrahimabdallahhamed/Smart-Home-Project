#include "../../LIB/STDTYPES.h"
#include "../../LIB/BITMATH.h"
#include "GPIO_Interface.h"
#include "../../LIB/pic18f4620.h"

/* Reference to the Data Direction Control Registers */
volatile u8 *tris_registers[] = {&TRISA, &TRISB, &TRISC, &TRISD, &TRISE};
/* Reference to the Data Latch Register (Read and Write to Data Latch) */
volatile u8 *lat_registers[] = {&LATA, &LATB, &LATC, &LATD, &LATE};
/* Reference to the Port Status Register  */
volatile u8 *port_registers[] = {&PORTA, &PORTB, &PORTC, &PORTD, &PORTE};

void GPIO_VoidSetPortDirection(u8 Copy_u8Port, u8 Copy_u8Direction) {

    switch (Copy_u8Direction) {
        case INPUT:
            *tris_registers[Copy_u8Port] = 0xff;
            break;
        case OUTPUT:
            *tris_registers[Copy_u8Port] = 0X00;
            break;

    }

}

void GPIO_VoidSetPortMode(u8 Copy_u8Port, u8 Copy_u8Mode) {
    switch (Copy_u8Mode) {
        case HIGH:
            *lat_registers[Copy_u8Port] = 0xff;
            break;
        case LOW:
            *lat_registers[Copy_u8Port] = 0X00;
            break;

    }
}

void GPIO_VoidSetPinDirection(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Direction) {

    switch (Copy_u8Direction) {
        case INPUT:
            SET_BIT(*tris_registers[Copy_u8Port], Copy_u8Pin);
            break;
        case OUTPUT:
            CLR_BIT(*tris_registers[Copy_u8Port], Copy_u8Pin);

            break;
    }
}

u8 GPIO_u8ReadPin(u8 Copy_u8Port, u8 Copy_u8Pin) {
    u8 Localu8Returned = 0;
    Localu8Returned = READ_BIT(*port_registers[Copy_u8Port], Copy_u8Pin);
    return Localu8Returned;
}

void GPIO_VoidWriteLogicPortDirection(u8 Copy_u8Port, u8 Copy_u8LogicDirection) {
    *tris_registers[Copy_u8Port] = Copy_u8LogicDirection;

}

void GPIO_VoidWriteLogicPortMode(u8 Copy_u8Port, u8 Copy_u8LogicMode) {


    *lat_registers[Copy_u8Port] = Copy_u8LogicMode;
}

void GPIO_VoidSetPinMode(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Mode) {
    switch (Copy_u8Mode) {
        case HIGH:
            SET_BIT(*lat_registers[Copy_u8Port], Copy_u8Pin);
            break;
        case LOW:
            CLR_BIT(*lat_registers[Copy_u8Port], Copy_u8Pin);

            break;
    }

}



