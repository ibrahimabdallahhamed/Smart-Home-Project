/*
 * File:   TIMER1.h
 * Author: dell
 *
 * Created on November 8, 2023, 11:34 PM
 */

#ifndef TIMER1_H
#define TIMER1_H
/***********************Includes*****************/
#include "pic18f4620.h"
#include "../../LIB/STDTYPES.h"
#include "../../LIB/BITMATH.h"
#include "../GPIO/GPIO_Interface.h"
#include "../Interrupt/Interrupt_interface.h"
/*******************MACRO DECLERATIONS***************/
#define COUNTER_MODE 0
#define TIMER_MODE 1

#define MODE_8_BIT 0
#define MODE_16_BIT 1

#define EX_CLK_SYNCH 1
#define EX_CLK_ASYNCH 0

#define ENABLE_OSCILLATOR 1
#define DISABLE_OSCILLATOR 0

#define HIGH_PRIORITY 1
#define LOW_PRIORITY 0

/*******************MACRO FUNCTIONS******************/

/*function to enable timer1*/
#define TIMER1_ENABLE() (T1CONbits.TMR1ON = 1)
/*function to disable timer1*/
#define TIMER1_DISABLE() (T1CONbits.TMR1ON = 0)

/*fuctions to Timer1 Clock Source Select bit
 *timer1 as a counter mode*/
#define TIMER1_COUNTER_MODE() (T1CONbits.TMR1CS = 1)
/*timer1 as a timer mode*/
#define TIMER1_TIMER_MODE() (T1CONbits.TMR1CS = 0)

/*FUNCTIONS Timer1 External Clock Input Synchronization Select bit*/
/*function Do not synchronize external clock input*/
#define TIMER1_ASYNCH_EXT_CLOCK() (T1CONbits.T1SYNC = 1)
/*Synchronize external clock input*/
#define TIMER1_SYNCH_EXT_CLOCK() (T1CONbits.T1SYNC = 0)

/* Timer1 Oscillator Enable bit*/
/*Function to enable Oscillator*/
#define TIMER1_OSCILLATOR_ENABLE() (T1CONbits.T1OSCEN = 1)
/*Function to disable Oscillator*/
#define TIMER1_OSCILLATOR_DISABLE() (T1CONbits.T1OSCEN = 0)

/*Timer1 System Clock Status bit*/
#define TIMER1_SYSTEM_CLOCK_STATUS() (T1CONbits.T1RUN)

/*16-bit OR 8-bit Read/Write Mode Enable bit*/
/*Function to enable 16-bit Reg*/
#define TIMER1_16_BIT_REG() (T1CONbits.RD16 = 1)
/*Function to enable 8-bit Reg*/
#define TIMER1_8_BIT_REG() (T1CONbits.RD16 = 0)

/******************Timer1 interrupts************/
/*enable timer1 interrupt*/
#define TIMER1_InterruptEnable() (PIE1bits.TMR1IE = 1)
/*Disable timer1 interrupt*/
#define TIMER1_InterruptDisable() (PIE1bits.TMR1IE = 0)
/*clear flag timer1 interrupt*/
#define TIMER1_CLEAR_FLAG() (PIR1bits.TMR1IF = 0)
/*Enable timer1 high priority*/
#define TIMER1_HIGH_PRIORITY() (IPR1bits.TMR1IP = 1)
/*Enable timer1 low priority*/
#define TIMER1_LOW_PRIORITY() (IPR1bits.TMR1IP = 0)

/* ----------------- Data Type Declarations -----------------*/

/*enum to  timer1 prescaler*/
typedef enum {
    PrescalerDiv_1 = 0,
    PrescalerDiv_2,
    PrescalerDiv_4,
    PrescalerDiv_8,
} timer1_prescaler_t;

typedef struct  {
    timer1_prescaler_t prescaler;
    u16 preload;

    u8 mode : 1;
    u8 wr_reg_mode : 1;
    u8 ext_clk : 1;
    u8 oscillator : 1;
#if TIMER1_INTERRUPT_ENABLE==INTERRUPT_FEATURE_ENABLE
    void (*TIMER1_InterruptHandeler)(void);

#if INTERRUPT_PRIORITY_level==INTERRUPT_FEATURE_ENABLE
    u8 priority : 1;

#endif
#endif
} TIMER1_t;

/***********************Function Declerations*******************/
/*Function to Intialization TIMER1 */
void TIMER1_voidTimerInit(TIMER1_t *Copy_stTimer);
/*Function to Deintialization TIMER1 */
void TIMER1_voidTmerDeinit(TIMER1_t *Copy_stTimer);
/*Function to write value in timer*/
void TIMER1_voidWriteReg(TIMER1_t *Copy_stTimer, u16 Copy_u16Value);
/*Function to Read value in timer*/
u16 TIMER1_u16ReadReg(TIMER1_t *Copy_stTimer);

#endif /* TIMER1_H */
