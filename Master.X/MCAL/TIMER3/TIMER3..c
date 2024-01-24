/***********************Includes*****************/
#include "TIMER3.h"
/***************static function decleration ***********/
static void mode_config(TIMER3_t *Copy_stTimer);
static void interrupt_config(TIMER3_t *Copy_stTimer);
static void RW_mode_config(TIMER3_t *Copy_stTimer);
/****************Data Types **********/
u16 GLOP_u16Timer3Preload = 0;
void (*Timer3InterruptHandeler)(void) = NULL;

/********************function defintion*************/

void TIMER3_voidInit(TIMER3_t *Copy_stTimer) {
    if (NULL != Copy_stTimer) {

        /*Disable Timer3 Module*/
        TIMER3_DISABLE();
        /*prescaler config */
        TIMER3_SET_PRESCALER(Copy_stTimer->prescaler);
        /*Mode config */
        mode_config(Copy_stTimer);
        /*RW Mode config */
        RW_mode_config(Copy_stTimer);
        /*set preload value*/
        GLOP_u16Timer3Preload = Copy_stTimer->preload;
        TIMER3_voidWriteReg(Copy_stTimer, GLOP_u16Timer3Preload);
        /*interrupt config */
        interrupt_config(Copy_stTimer);
        /*enable timer3 module*/
        TIMER3_ENABLE();
    }
}

void TIMER3_voidDeinit(TIMER3_t *Copy_stTimer) {
    if (NULL != Copy_stTimer) {
        TIMER3_DISABLE();
        TIMER3_DISABLE_INTERRUPT();
    }
}

void TIMER3_voidWriteReg(TIMER3_t *Copy_stTimer, u16 Copy_u16Value) {
    if (NULL != Copy_stTimer) {
        TMR3H = Copy_u16Value >> 8;
        TMR3L = (u8) Copy_u16Value;
    }
}

u16 TIMER3_u16ReadReg(TIMER3_t *Copy_stTimer) {
    if (NULL != Copy_stTimer) {
        u16 Local_u16ReturnedTimer3 = 0;
        Local_u16ReturnedTimer3 = (TMR3H * 256);
        Local_u16ReturnedTimer3 += TMR3L;
        return Local_u16ReturnedTimer3;
    }
}

/*************static function defintion*************/
static void mode_config(TIMER3_t *Copy_stTimer) {
    if (NULL != Copy_stTimer) {
        switch (Copy_stTimer->mode) {
            case COUNTER_MODE:
                TIMER3_COUNTER_MODE();
                switch (Copy_stTimer->ext_clk_synch) {
                    case N_SYNCH_CLK:
                        TIMER3_N_SYNCH_CLK();
                        break;
                    case SYNCH_CLK:
                        TIMER3_SYNCH_CLK();
                        break;
                }
                break;
            case TIMER_MODE:
                TIMER3_TIMER_MODE();
                break;
        }
    }
}

static void RW_mode_config(TIMER3_t *Copy_stTimer) {
    if (NULL != Copy_stTimer) {
        switch (Copy_stTimer->RW_Mode) {
            case RW_16_BIT:
                TIMER3_RW_16_BIT();
                break;
            case RW_8_BIT:
                TIMER3_RW_8_BIT();
                break;
        }
    }
}

static void interrupt_config(TIMER3_t *Copy_stTimer) {
    if (NULL != Copy_stTimer) {
#if TIMER3_INTERRUPT_ENABLE == INTERRUPT_FEATURE_ENABLE

        TIMER3_CLEAR_FLAG();
        Timer3InterruptHandeler = Copy_stTimer->TIMER3_InterruptHandeler;
        TIMER3_ENABLE_INTERRUPT();
        Interrupt_GLOP_InterruptEnable();
#if INTERRUPT_PRIORITY_level == INTERRUPT_FEATURE_ENABLE
        switch (Copy_stTimer->priority) {
            case INTERRUPT_Interrupt_HighPriority:
                TIMER3_HIGH_PRIORITY();
                break;
            case INTERRUPT_Interrupt_LowPriority:
                TIMER3_LOW_PRIORITY();
                break;
        }
#endif
#endif
    }
}

void TIMER3_ISR(void) {
    TIMER3_CLEAR_FLAG();
    TMR3H = GLOP_u16Timer3Preload >> 8;
    TMR3L = (u8) GLOP_u16Timer3Preload;
    if (Timer3InterruptHandeler) {
        Timer3InterruptHandeler();
    }
}
