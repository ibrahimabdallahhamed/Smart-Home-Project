#ifndef CCP_H
#define CCP_H

/***********************Includes*****************/
#include "../../LIB/pic18f4620.h"
#include "../../LIB/STDTYPES.h"
#include "../../LIB/BITMATH.h"
#include "../GPIO/GPIO_Interface.h"
#include "../Interrupt/Interrupt_interface.h"
#include "CCP_Config.h"

/*******************MACRO DECLERATIONS***************/
#define CCP1 0
#define CCP2 1

#define CCP_DISABLE 0
#define COMPARE_TOG_OUTPUT 2
#define CAPTURE_EVERY_FALLING 4
#define CAPTURE_EVERY_RISING 5
#define CAPTURE_EVERY_4TH_RISING 6
#define CAPTURE_EVERY_16TH_RISING 7
#define COMPARE_CCP_LOW 8
#define COMPARE_CCP_HIGH 9
#define COMPARE_GENERATE_SW_INTERRUPT 10
#define COMPARE_TRIGGER_SPECIAL_EVENT 11
#define PWM_MODE 12

#define CAPTURE_READY 1
#define CAPTURE_NOT_READY 0
#define COMPARE_READY 1
#define COMPARE_NOT_READY 0
/*timer2 postscaler*/
#define CCP_POSTSCALER_DIV_BY_1 1
#define CCP_POSTSCALER_DIV_BY_2 2
#define CCP_POSTSCALER_DIV_BY_3 3
#define CCP_POSTSCALER_DIV_BY_4 4
#define CCP_POSTSCALER_DIV_BY_5 5
#define CCP_POSTSCALER_DIV_BY_6 6
#define CCP_POSTSCALER_DIV_BY_7 7
#define CCP_POSTSCALER_DIV_BY_8 8
#define CCP_POSTSCALER_DIV_BY_9 9
#define CCP_POSTSCALER_DIV_BY_10 10
#define CCP_POSTSCALER_DIV_BY_11 11
#define CCP_POSTSCALER_DIV_BY_12 12
#define CCP_POSTSCALER_DIV_BY_13 13
#define CCP_POSTSCALER_DIV_BY_14 14
#define CCP_POSTSCALER_DIV_BY_15 15
#define CCP_POSTSCALER_DIV_BY_16 16

/*Timer2 prescaler*/
#define CCP_PRESCALER_DIV_BY_1 1
#define CCP_PRESCALER_DIV_BY_4 4
#define CCP_PRESCALER_DIV_BY_16 16

/*Timer3 and Timer1 to CCPx Enable bits*/
#define TIMER3_CCP 2
#define TIMER3_CCP2_TIMER1_CCP1 1
#define TIMER1_CCP 0

/*******************MACRO FUNCTIONS******************/
#define CCP1_MODE_SELECT(config) (CCP1CONbits.CCP1M = config)
#define CCP2_MODE_SELECT(config) (CCP2CONbits.CCP2M = config)
/***CCP1 Interrupt functions*****/
#define CCP1_ENABLE_INTERRUPT() (PIE1bits.CCP1IE = 1)
#define CCP1_DISABLE_INTERRUPT() (PIE1bits.CCP1IE = 0)
#define CCP1_CLEAR_FLAG() (PIR1bits.CCP1IF = 0)
#define CCP1_HIGH_PRIORITY() (IPR1bits.CCP1IP = 1)
#define CCP1_LOW_PRIORITY() (IPR1bits.CCP1IP = 0)

/***CCP2 Interrupt functions*****/
#define CCP2_ENABLE_INTERRUPT() (PIE2bits.CCP2IE = 1)
#define CCP2_DISABLE_INTERRUPT() (PIE2bits.CCP2IE = 0)
#define CCP2_CLEAR_FLAG() (PIR2bits.CCP2IF = 0)
#define CCP2_HIGH_PRIORITY() (IPR2bits.CCP2IP = 1)
#define CCP2_LOW_PRIORITY() (IPR2bits.CCP2IP = 0)

/* ----------------- Data Type Declarations -----------------*/

typedef union
{
    struct
    {
        u8 CCPR_LOW;
        u8 CCPR_HIGH;
    };

    struct
    {
        u16 CCPR_16_BIT;
    };
} CCP_REG_t;

typedef enum
{
    Capture_Mode = 0,
    Compare_Mode,
    PWM_Mode

} CCP_MODE_t;

typedef struct
{
    CCP_MODE_t mode;
    u8 CPP_Variant;
    u8 ccp_select : 1;
    u8 timer3_timer1_ccp : 2;

#if CCP1_INTERRUPT_ENABLE == INTERRUPT_FEATURE_ENABLE
    void (*CCP1_InterruptHandeler)(void);
#if INTERRUPT_PRIORITY_level == INTERRUPT_FEATURE_ENABLE
    InterruptPriority_T ccp1_priority;
#endif
#endif
#if CCP2_INTERRUPT_ENABLE == INTERRUPT_FEATURE_ENABLE
    void (*CCP2_InterruptHandeler)(void);
#if INTERRUPT_PRIORITY_level == INTERRUPT_FEATURE_ENABLE
    InterruptPriority_T ccp2_priority;
#endif
#endif
#if ((CCP_1_SELECT_MODE == CCP_PWM_MODE) || (CCP_2_SELECT_MODE == CCP_PWM_MODE))
    u32 PWM_FREQ;
    u8 Postscaler ;
    u8 Prescaler ;
#endif

} CCP_t;

/***************Function Declerations************/

void CCP_voidInit(CCP_t *Copy_stCCP);
void CCP_voidDeinit(CCP_t *Copy_stCCP);
#if ((CCP_1_SELECT_MODE == CCP_CAPTURE_MODE) || (CCP_2_SELECT_MODE == CCP_CAPTURE_MODE))

u8 CCP_u8IsCapturedDataReady(CCP_t *Copy_stCCP);
u16 CCP_u16CaptureReadValue(CCP_t *Copy_stCCP);
#endif
#if ((CCP_1_SELECT_MODE == CCP_COMPARE_MODE) || (CCP_2_SELECT_MODE == CCP_COMPARE_MODE))

u8 CCP_u8IsComparedDataReady(CCP_t *Copy_stCCP);
void CCP_voidCompareSetValue(CCP_t *Copy_stCCP, u16 Copy_u16Value);
#endif
#if ((CCP_1_SELECT_MODE == CCP_PWM_MODE) || (CCP_2_SELECT_MODE == CCP_PWM_MODE))

void CCP_voidSetDuty(CCP_t *Copy_stCCP, const u16 Copy_u16Duty);
void CCP_voidPWM_Start(CCP_t *Copy_stCCP);
void CCP_voidPWM_Stop(CCP_t *Copy_stCCP);
#endif
#endif /* CCP_H */
