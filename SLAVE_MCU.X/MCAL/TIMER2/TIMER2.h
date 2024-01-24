#ifndef TIMER2_H
#define TIMER2_H
/*--------------------Include Files---------------*/
#include "../../LIB/pic18f4620.h"
#include "../../LIB/STDTYPES.h"
#include "../../LIB/BITMATH.h"
#include "../../LIB/device_config.h"
#include "../GPIO/GPIO_Interface.h"
#include "../Interrupt/Interrupt_interface.h"
/*------------------Macro Declerations--------------*/
/*timer2 postscaler*/
#define TIMER2_POSTSCALER_DIV_BY_1 0
#define TIMER2_POSTSCALER_DIV_BY_2 1
#define TIMER2_POSTSCALER_DIV_BY_3 2
#define TIMER2_POSTSCALER_DIV_BY_4 3
#define TIMER2_POSTSCALER_DIV_BY_5 4
#define TIMER2_POSTSCALER_DIV_BY_6 5
#define TIMER2_POSTSCALER_DIV_BY_7 6
#define TIMER2_POSTSCALER_DIV_BY_8 7
#define TIMER2_POSTSCALER_DIV_BY_9 8
#define TIMER2_POSTSCALER_DIV_BY_10 9
#define TIMER2_POSTSCALER_DIV_BY_11 10
#define TIMER2_POSTSCALER_DIV_BY_12 11
#define TIMER2_POSTSCALER_DIV_BY_13 12
#define TIMER2_POSTSCALER_DIV_BY_14 13
#define TIMER2_POSTSCALER_DIV_BY_15 14
#define TIMER2_POSTSCALER_DIV_BY_16 15

#define TIMER2_PRESCALER_DIV_BY_1 0
#define TIMER2_PRESCALER_DIV_BY_4 1
#define TIMER2_PRESCALER_DIV_BY_16 3

#define HIGH_PRIORITY 1
#define LOW_PRIORITY 0
/*------------------Maro Functions-------------------*/
/*Function to enable Timer2 module*/
#define TIMER2_ENABLE() (T2CONbits.TMR2ON = 1)
/*Function to Disable Timer2 module*/
#define TIMER2_DISABLE() (T2CONbits.TMR2ON = 0)
/*Function to set timer2 prescaler */
#define TIMER2_SET_PRESCALER(config) (T2CONbits.T2CKPS = config)
/*Function to set timer2 postscaler */
#define TIMER2_SET_POSTSCALER(config) (T2CONbits.TOUTPS = config)
/*****Function for Timer2 Interrupt*****/
/*function to enable timer2 interrupt*/
#define TIMER2_ENABLE_INTERRUPT() (PIE1bits.TMR2IE = 1)
/*function to Disable timer2 interrupt*/
#define TIMER2_DISABLE_INTERRUPT() (PIE1bits.TMR2IE = 0)
/*Function to clear timer2 interrupt flag*/
#define TIMER2_CLEAR_FLAG() (PIR1bits.TMR2IF = 0)
/*Function to set priority of timer2 interrupt*/
#define TIMER2_HIGH_PRIORITY() (IPR1bits.TMR2IP = 1)
#define TIMER2_LOW_PRIORITY() (IPR1bits.TMR2IP = 0)

/*------------------Data types Decalerations-----------*/
typedef struct {
    u8 prescaler;
    u8 postscaler;
    u8 preload;
#if TIMER2_INTERRUPT_ENABLE == INTERRUPT_FEATURE_ENABLE
    void (*TIMER2_InterruptHandeler)(void);
#if INTERRUPT_PRIORITY_level == INTERRUPT_FEATURE_ENABLE
    InterruptPriority_T priority;
#endif
#endif
} timer2_t;
/***********************Function Declerations*******************/
/*Function to Intialization TIMER2 */
void TIMER2_voidTmerInit(timer2_t *Copy_stTimer);
/*Function to Deintialization TIMER2 */
void TIMER2_voidTmerDeinit(timer2_t *Copy_stTimer);
/*Function to write value in timer*/
void TIMER2_voidWriteReg(timer2_t *Copy_stTimer, u8 Copy_u8Value);
/*Function to Read value in timer*/
u8 TIMER2_u8ReadReg(timer2_t *Copy_stTimer);

#endif /* TIMER2_H */
