/*
 * File:   TIMER0.h
 * Author: dell
 *
 * Created on November 4, 2023, 11:53 AM
 */

#ifndef TIMER0_H
#define TIMER0_H
/*****************INCLUDES**************************/
#include "pic18f4620.h"
#include "../../LIB/STDTYPES.h"
#include "../../LIB/BITMATH.h"
#include "../GPIO/GPIO_Interface.h"
#include "../Interrupt/Interrupt_interface.h"
/*******************MACRO DECLERATIONS***************/
#define SIZE_8_BIT 0
#define SIZE_16_BIT 1

#define COUNTER_MODE 0
#define TIMER_MODE 1

#define RISING_EDGE 1
#define FALLING_EDGE 0

#define PRESCALER_ASS 1
#define PRESCALER_N_ASS 0
/*******************MACRO FUNCTIONS******************/
/*Enable timer module*/
#define TIMER0_ENABLE() (T0CONbits.TMR0ON = 1)
/*Disable timer module*/
#define TIMER0_DISABLE() (T0CONbits.TMR0ON = 0)
/****select size of timer 8_bit / 16_bit*******/
#define TIMER0_8_BIT_SIZE() (T0CONbits.T08BIT = 1)
#define TIMER0_16_BIT_SIZE() (T0CONbits.T08BIT = 0)
/**************select clock sourse********  */
/*selecting external clock source */
#define TIMER0_CounterMode() (T0CONbits.T0CS = 1)
/*Selecting internal clock source */
#define TIMER0_TimerMode() (T0CONbits.T0CS = 0)
/******selecting edge of T0CKI***********/
#define TIMER0_T0CKI_RISING() (T0CONbits.T0SE = 0)
#define TIMER0_T0CKI_FALLING() (T0CONbits.T0SE = 1)
/**********Timer0 Prescaler Assignment bit***********/
#define TIMER0_ENABLE_Prescaler() (T0CONbits.PSA = 0)
#define TIMER0_DISABLE_Prescaler() (T0CONbits.PSA = 1)
/****************Timer0 Interrupt*************/
#define TIMER0_ENABLE_INTERRUPT() (INTCONbits.TMR0IE = 1)
#define TIMER0_DISABLE_INTERRUPT() (INTCONbits.TMR0IE = 0)
#define TIMER0_CLEAR_FLAG() (INTCONbits.TMR0IF = 0)
#define TIMER0_HIGH_PRIORITY() (INTCON2bits.TMR0IP = 1)
#define TIMER0_LOW_PRIORITY() (INTCON2bits.TMR0IP = 1)

/* ----------------- Data Type Declarations -----------------*/
typedef enum {
    PRESCALE_DIV_2 = 0,
    PRESCALE_DIV_4,
    PRESCALE_DIV_8,
    PRESCALE_DIV_16,
    PRESCALE_DIV_32,
    PRESCALE_DIV_64,
    PRESCALE_DIV_128,
    PRESCALE_DIV_256
} timer0_prescale_select_t;

typedef struct {
#if TIMER0_INTERRUPT_ENABLE == INTERRUPT_FEATURE_ENABLE
    void (*TIMER0_InterruptHandeler)(void);
#if INTERRUPT_PRIORITY_level == INTERRUPT_FEATURE_ENABLE
    InterruptPriority_T priority;
#endif
#endif
    timer0_prescale_select_t prescaler;
    u16 preloadValue;
    u8 Size_of_timer : 1;
    u8 TimerMode : 1;
    u8 CounterEdge : 1;
    u8 Prescaler_Ass : 1;
    u8 reserved : 4;

} timer0_config_t;
/***********************Function Declerations*******************/
/*Function to Intialization TIMER0 */
void TIMER0_voidTmerInit(timer0_config_t *Copy_stTimer);
/*Function to Deintialization TIMER0 */
void TIMER0_voidTmerDeinit(timer0_config_t *Copy_stTimer);
/*Function to write value in timer*/
void TIMER0_voidWriteReg(timer0_config_t *Copy_stTimer, u16 Copy_u8Value);
/*Function to Read value in timer*/
u16 TIMER0_u16ReadReg(timer0_config_t *Copy_stTimer);
#endif /* TIMER0_H */
