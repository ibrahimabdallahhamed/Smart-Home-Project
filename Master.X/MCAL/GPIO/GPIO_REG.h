/* 
 * File:   GPIO_REG.h
 * Author: dell
 *
 * Created on October 7, 2023, 11:40 AM
 */

#ifndef GPIO_REG_H
#define	GPIO_REG_H
#include "../../LIB/STDTYPES.h"

/*TRIS register is to select direction of port*/
#define  TRISA_REG    (*(volatile u8 *)0xF92)
#define  TRISB_REG    (*(volatile u8 *)0xF93)
#define  TRISC_REG    (*(volatile u8 *)0xF94)
#define  TRISD_REG    (*(volatile u8 *)0xF95)
#define  TRISE_REG    (*(volatile u8 *)0xF96)

/*LAT Register to select Mode of PORT*/
#define  LATA_REG    (*(volatile u8 *)0xF89)
#define  LATB_REG    (*(volatile u8 *)0xF8A)
#define  LATC_REG    (*(volatile u8 *)0xF8B)
#define  LATD_REG    (*(volatile u8 *)0xF8C)
#define  LATE_REG    (*(volatile u8 *)0xF8D)

/*Port Register to read the value from it */

#define  PORTA_REG  (*(volatile u8 *)0x0F80)
#define  PORTB_REG  (*(volatile u8 *)0x0F81)
#define  PORTC_REG  (*(volatile u8 *)0x0F82)
#define  PORTD_REG  (*(volatile u8 *)0x0F83)
#define  PORTE_REG  (*(volatile u8 *)0x0F84)



#endif	/* GPIO_REG_H */

