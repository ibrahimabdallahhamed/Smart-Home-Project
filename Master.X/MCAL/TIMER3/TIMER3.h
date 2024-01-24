#ifndef TIMER3_H
#define TIMER3_H
/***********************Includes*****************/
#include "../../LIB/pic18f4620.h"
#include "../../LIB/STDTYPES.h"
#include "../../LIB/BITMATH.h"
#include "../GPIO/GPIO_Interface.h"
#include "../Interrupt/Interrupt_interface.h"
/*******************MACRO DECLERATIONS***************/
/*TIMER3 Prescaler values*/
#define TIMER3_PRESCALER_DIV_BY_1 0
#define TIMER3_PRESCALER_DIV_BY_2 1
#define TIMER3_PRESCALER_DIV_BY_4 2
#define TIMER3_PRESCALER_DIV_BY_8 3

#define N_SYNCH_CLK 1
#define SYNCH_CLK 0

#define COUNTER_MODE 1
#define TIMER_MODE 0

#define RW_16_BIT 1
#define RW_8_BIT 0

/*******************MACRO FUNCTIONS******************/
/*Function to enable timer3 module*/
#define TIMER3_ENABLE() (T3CONbits.TMR3ON = 1)
/*Function to Disable timer3 module*/
#define TIMER3_DISABLE() (T3CONbits.TMR3ON = 0)
/*Function to Counter Mode*/
#define TIMER3_COUNTER_MODE() (T3CONbits.TMR3CS = 1)
/*Function to Timer Mode*/
#define TIMER3_TIMER_MODE() (T3CONbits.TMR3CS = 0)
/*Function to Not synchronize external clock input*/
#define TIMER3_N_SYNCH_CLK() (T3CONbits.T3SYNC = 1)
/*Function to synchronize external clock input*/
#define TIMER3_SYNCH_CLK() (T3CONbits.T3SYNC = 0)
/*Function to set timer3 prescaler*/
#define TIMER3_SET_PRESCALER(config) (T3CONbits.T3CKPS = config)
/*Function to RW 16-bit */
#define TIMER3_RW_16_BIT() (T3CONbits.RD16 = 1)
/*Function to RW 8-bit */
#define TIMER3_RW_8_BIT() (T3CONbits.RD16 = 0)
/*******TIMER3 INTERRUPT*****/
/*Function to enable timer3 interrupt*/
#define TIMER3_ENABLE_INTERRUPT() (PIE2bits.TMR3IE = 1)
/*Function to Disable timer3 interrupt*/
#define TIMER3_DISABLE_INTERRUPT() (PIE2bits.TMR3IE = 0)
/*Function to clear timer3 interrupt flag*/
#define TIMER3_CLEAR_FLAG() (PIR2bits.TMR3IF = 0)
/*Function to high priority timer3 interrupt*/
#define TIMER3_HIGH_PRIORITY() (IPR2bits.TMR3IP = 1)
/*Function to low priority timer3 interrupt*/
#define TIMER3_LOW_PRIORITY() (IPR2bits.TMR3IP = 0)

/* ----------------- Data Type Declarations -----------------*/
typedef struct {
    u8 prescaler : 2;
    u8 RW_Mode : 1;
    u8 ext_clk_synch : 1;
    u8 mode : 1;
    u8 reserved : 2;
    u16 preload;
#if TIMER3_INTERRUPT_ENABLE == INTERRUPT_FEATURE_ENABLE
#if INTERRUPT_PRIORITY_level == INTERRUPT_FEATURE_ENABLE
    InterruptPriority_T priority;
#endif
    void (*TIMER3_InterruptHandeler)(void);
#endif

} TIMER3_t;

void TIMER3_voidInit(TIMER3_t *Copy_stTimer);
void TIMER3_voidDeinit(TIMER3_t *Copy_stTimer);
void TIMER3_voidWriteReg(TIMER3_t *Copy_stTimer, u16 Copy_u16Value);
u16 TIMER3_u16ReadReg(TIMER3_t *Copy_stTimer);

#endif /* TIMER3_H */
