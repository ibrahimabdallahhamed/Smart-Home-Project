/***********************Includes*****************/
#include "TIMER1.h"
/***********static function prototype************/
static void SizeConfig(TIMER1_t *Copy_stTimer);
static void ModeConfig(TIMER1_t *Copy_stTimer);
static void EXT_CLK_Config(TIMER1_t *Copy_stTimer);
static void OscillatorConfig(TIMER1_t *Copy_stTimer);
static void PrescalerConfig(TIMER1_t *Copy_stTimer);
static void InterruptConfig(TIMER1_t *Copy_stTimer);
/*******************Global variables***************************/
void (*Timer1InterruptHandeler)(void);
u16 PreloadVlaue = 0;
/*******************Function Defintions************ */

/*Function to Intialization TIMER1 */
void TIMER1_voidTimerInit(TIMER1_t *Copy_stTimer) {
    /*disable timer1 module*/
    TIMER1_DISABLE();
    /*SIZE config*/
    SizeConfig(Copy_stTimer);
    /*Timer mode config*/
    ModeConfig(Copy_stTimer);
    /*External clock config*/
    EXT_CLK_Config(Copy_stTimer);
    /*oscillator config*/
    OscillatorConfig(Copy_stTimer);
    /*prescaler config*/
    PrescalerConfig(Copy_stTimer);
    /*preload value config*/
    TIMER1_voidWriteReg(Copy_stTimer, Copy_stTimer->preload);
    PreloadVlaue = Copy_stTimer->preload;
    /*timer1 interrupt config*/
#if TIMER1_INTERRUPT_ENABLE == INTERRUPT_FEATURE_ENABLE
    TIMER1_CLEAR_FLAG();
    Interrupt_GLOP_InterruptEnable();
    InterruptConfig(Copy_stTimer);
#endif
    /*Enable timer module*/
    TIMER1_ENABLE();
}

/*Function to Deintialization TIMER1 */
void TIMER1_voidTmerDeinit(TIMER1_t *Copy_stTimer) {
    /*disable timer1 module*/
    TIMER1_DISABLE();
    TIMER1_InterruptDisable();
}

/*Function to write value in timer*/
void TIMER1_voidWriteReg(TIMER1_t *Copy_stTimer, u16 Copy_u16Value) {

    TMR1H = Copy_u16Value >> 8;
    TMR1L = (u8) Copy_u16Value;
}

/*Function to Read value in timer*/
u16 TIMER1_u16ReadReg(TIMER1_t *Copy_stTimer) {
    u16 Local_u16ReturnedValue = 0;
    Local_u16ReturnedValue = (TMR1H * 256);
    Local_u16ReturnedValue += TMR1L;
    return Local_u16ReturnedValue;
}

/*******************static Function Defintions************ */
static void SizeConfig(TIMER1_t *Copy_stTimer) {
    if (Copy_stTimer->wr_reg_mode == MODE_8_BIT) {
        TIMER1_8_BIT_REG();
    } else {
        TIMER1_16_BIT_REG();
    }
}

static void ModeConfig(TIMER1_t *Copy_stTimer) {
    if (Copy_stTimer->mode == COUNTER_MODE) {
        TIMER1_COUNTER_MODE();
    } else {
        TIMER1_TIMER_MODE();
    }
}

static void EXT_CLK_Config(TIMER1_t *Copy_stTimer) {
    if (Copy_stTimer->ext_clk == EX_CLK_SYNCH) {
        TIMER1_SYNCH_EXT_CLOCK();
    } else {
        TIMER1_ASYNCH_EXT_CLOCK();
    }
}

static void OscillatorConfig(TIMER1_t *Copy_stTimer) {
    if (Copy_stTimer->oscillator == ENABLE_OSCILLATOR) {
        TIMER1_OSCILLATOR_ENABLE();
    } else {
        TIMER1_OSCILLATOR_DISABLE();
    }
}

static void PrescalerConfig(TIMER1_t *Copy_stTimer) {
    T1CONbits.T1CKPS = Copy_stTimer->prescaler;
}

static void InterruptConfig(TIMER1_t *Copy_stTimer) {
#if TIMER1_INTERRUPT_ENABLE == INTERRUPT_FEATURE_ENABLE
    Timer1InterruptHandeler = Copy_stTimer->TIMER1_InterruptHandeler;
    TIMER1_InterruptEnable();

#if INTERRUPT_PRIORITY_level == INTERRUPT_FEATURE_ENABLE

    if (Copy_stTimer->priority == HIGH_PRIORITY) {
        TIMER1_HIGH_PRIORITY();
    } else if (Copy_stTimer->priority == LOW_PRIORITY) {
        TIMER1_LOW_PRIORITY();
    }
#endif
#endif
}

void TIMER1_ISR(void) {
    TIMER1_CLEAR_FLAG();
    TMR1H = PreloadVlaue >> 8;
    TMR1L = (u8) PreloadVlaue;
    if (Timer1InterruptHandeler) {
        Timer1InterruptHandeler();
    }
}
