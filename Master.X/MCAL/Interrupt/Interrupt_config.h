/*
 * File:   Interrupt_config.h
 * Author: dell
 *
 * Created on October 19, 2023, 8:29 PM
 */

#ifndef INTERRUPT_CONFIG_H
#define INTERRUPT_CONFIG_H
/*--------------Includes--------------*/
#include "pic18f4620.h"
#include "../../LIB/BITMATH.h"
#include "../../LIB/STDTYPES.h"
#include "Interrupt_generation_config.h"
#include "../GPIO/GPIO_Interface.h"
/*--------------Macro Declerations--------------*/
#define INTERRUPT_ENABLE             1
#define INTERRUPT_DISABLE            0
#define INTERRUPT_PRIORITY_ENABLE    1
#define INTERRUPT_PRIORITY_DISABLE   0
#define INTERRUPT_OCCUR              1
#define INTERRUPT_NOT_OCCUR          0
/*----------Macro Function-------------- */
#if INTERRUPT_PRIORITY_level == INTERRUPT_FEATURE_ENABLE
/* This macro will enable priority levels on interrupts. */
#define INTERRUPT_PriorityLevelsEnable()  (RCONbits.IPEN = 1)

/*function to enable global interrupt high priority */
#define INTERRUPT_GlobalInterruptHighEnable()   (INTCONbits.GIEH=1)
/*function to disable global interrupt high priority */
#define INTERRUPT_GlobalInterruptHighDisable()  (INTCONbits.GIEH=0)
/*function to enable global interrupt Low priority */
#define INTERRUPT_GlobalInterruptLowEnable()    (INTCONbits.GIEL=1)
/*function to disable global interrupt Low priority */
#define INTERRUPT_GlobalInterruptLowDisable()   (INTCONbits.GIEL=0)
#else 
/* This macro will disable  priority levels on interrupts. */
#define INTERRUPT_PriorityLevelsDisable() (RCONbits.IPEN = 0)
/*function to enable global interrupt  priority */
#define INTERRUPT_GlobalInterruptEnable()        (INTCONbits.GIE=1)
/*function to disable global interrupt  priority */
#define INTERRUPT_GlobalInterruptDisable()       (INTCONbits.GIE=0)
/*function to Enable Peripheral interrupt  */
#define INTERRUPT_PeripheralInterrupEnable()      (INTCONbits.PEIE=1)
/*function to DISable Peripheral interrupt  */
#define INTERRUPT_PeripheralInterruptDisable()    (INTCONbits.PEIE=0)
#endif

#endif /* INTERRUPT_CONFIG_H */
