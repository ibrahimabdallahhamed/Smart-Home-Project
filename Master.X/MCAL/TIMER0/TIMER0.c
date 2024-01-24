#include "TIMER0.h"
void (*TIMER0_InterruptHandeler)(void);

static void TIMER0_SizeConfig(timer0_config_t *Copy_stTimer);
static void TIMER0_ModeConfig(timer0_config_t *Copy_stTimer);
static void TIMER0_PrescalerConfig(timer0_config_t *Copy_stTimer);
u16 preload = 0;

/*Function to Intialization TIMER0 */

void TIMER0_voidTmerInit(timer0_config_t *Copy_stTimer) {
    /*Disable timer module*/
    TIMER0_DISABLE();
    /*Select Size of Reg*/
    TIMER0_SizeConfig(Copy_stTimer);
    /*select mode of timer*/
    TIMER0_ModeConfig(Copy_stTimer);
    /*Timer0 Prescaler Assignment*/
    TIMER0_PrescalerConfig(Copy_stTimer);
    TIMER0_voidWriteReg(Copy_stTimer, Copy_stTimer->preloadValue);
    preload = Copy_stTimer->preloadValue;
    /*TIMER0 Interrupt config*/
#if TIMER0_INTERRUPT_ENABLE == INTERRUPT_FEATURE_ENABLE
    Interrupt_GLOP_InterruptEnable();
    TIMER0_CLEAR_FLAG();
    TIMER0_InterruptHandeler = Copy_stTimer->TIMER0_InterruptHandeler;
    TIMER0_ENABLE_INTERRUPT();
#if INTERRUPT_PRIORITY_level == INTERRUPT_FEATURE_ENABLE
    if (Copy_stTimer->priority == INTERRUPT_Interrupt_LowPriority) {
        TIMER0_LOW_PRIORITY();
    } else {
        TIMER0_HIGH_PRIORITY();
    }
#endif
#endif
    /*Enable Timer module*/
    TIMER0_ENABLE();
}

/*Function to Deintialization TIMER0 */
void TIMER0_voidTmerDeinit(timer0_config_t *Copy_stTimer) {
    TIMER0_DISABLE();
    TIMER0_DISABLE_INTERRUPT();
}

/*Function to write value in timer*/
void TIMER0_voidWriteReg(timer0_config_t *Copy_stTimer, u16 Copy_u8Value) {
    TMR0H = Copy_u8Value >> 8;
    TMR0L = (u8) Copy_u8Value;
}

/*Function to Read value in timer*/
u16 TIMER0_u16ReadReg(timer0_config_t *Copy_stTimer) {
    u16 Local_u16ReturnedValue = 0;
    Local_u16ReturnedValue = (TMR0H * 256);
    Local_u16ReturnedValue += TMR0L;
    return Local_u16ReturnedValue;
}

static void TIMER0_SizeConfig(timer0_config_t *Copy_stTimer) {
    switch (Copy_stTimer->Size_of_timer) {
        case SIZE_8_BIT:
            TIMER0_8_BIT_SIZE();
            break;
        case SIZE_16_BIT:
            TIMER0_16_BIT_SIZE();
            break;
    }
}

static void TIMER0_ModeConfig(timer0_config_t *Copy_stTimer) {
    switch (Copy_stTimer->TimerMode) {
        case COUNTER_MODE:
            TIMER0_CounterMode();
            switch (Copy_stTimer->CounterEdge) {
                case RISING_EDGE:
                    TIMER0_T0CKI_RISING();
                    break;
                case FALLING_EDGE:
                    TIMER0_T0CKI_FALLING();
                    break;
            }

            break;
        case TIMER_MODE:
            TIMER0_TimerMode();
            break;
    }
}

static void TIMER0_PrescalerConfig(timer0_config_t *Copy_stTimer) {
    switch (Copy_stTimer->Prescaler_Ass) {
        case PRESCALER_ASS:
            TIMER0_ENABLE_Prescaler();
            T0CONbits.T0PS = Copy_stTimer->prescaler;
            break;
        case PRESCALER_N_ASS:
            TIMER0_DISABLE_Prescaler();
            break;
    }
}

void TIMER0_ISR() {
    TIMER0_CLEAR_FLAG();
    TMR0H = preload >> 8;
    TMR0L = (u8) preload;
    if (TIMER0_InterruptHandeler) {
        TIMER0_InterruptHandeler();
    }
}