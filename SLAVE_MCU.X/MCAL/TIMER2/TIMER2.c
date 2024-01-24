/*****************INCLUDES**************************/
#include "TIMER2.h"
/********************Static Function Decleration*******************/
static void InterruptConfig(timer2_t *Copy_stTimer);

/* ----------------- Data Type Declarations -----------------*/
void (*Timer2InterruptHandeler)(void) = NULL;
static u8 GLOP_u8Timer2Preload;
/***********************Function Definition*******************/
/*Function to Intialization TIMER2 */
void TIMER2_voidTmerInit(timer2_t *Copy_stTimer)
{
    if (NULL != Copy_stTimer)
    {

        /*Disable Timer2 module*/
        TIMER2_DISABLE();
        /*set timer2 postscaler*/
        TIMER2_SET_POSTSCALER(Copy_stTimer->postscaler);
        /*set timer2 prescaler */
        TIMER2_SET_PRESCALER(Copy_stTimer->prescaler);
        /*set preload value*/
        GLOP_u8Timer2Preload = Copy_stTimer->preload;
        TMR2 = GLOP_u8Timer2Preload;
#if TIMER1_INTERRUPT_ENABLE == INTERRUPT_FEATURE_ENABLE
        InterruptConfig(Copy_stTimer);
#endif
        TIMER2_ENABLE();
    }
}
/*Function to Deintialization TIMER2 */
void TIMER2_voidTmerDeinit(timer2_t *Copy_stTimer)
{
    if (NULL != Copy_stTimer)
    {
        TIMER2_DISABLE();
        TIMER2_DISABLE_INTERRUPT();
    }
}
/*Function to write value in timer*/
void TIMER2_voidWriteReg(timer2_t *Copy_stTimer, u8 Copy_u8Value)
{
    if (NULL != Copy_stTimer)
    {
        TMR2 = (u8)Copy_u8Value;
    }
}
/*Function to Read value in timer*/
u8 TIMER2_u8ReadReg(timer2_t *Copy_stTimer)
{
    if (NULL != Copy_stTimer)
    {
        return TMR2;
    }
}

static void InterruptConfig(timer2_t *Copy_stTimer)
{
    if (NULL != Copy_stTimer)
    {
#if TIMER2_INTERRUPT_ENABLE == INTERRUPT_FEATURE_ENABLE
        TIMER2_CLEAR_FLAG();
        Timer2InterruptHandeler = Copy_stTimer->TIMER2_InterruptHandeler;
        Interrupt_GLOP_InterruptEnable();
        TIMER2_ENABLE_INTERRUPT();

#if INTERRUPT_PRIORITY_level == INTERRUPT_FEATURE_ENABLE

        if (Copy_stTimer->priority == HIGH_PRIORITY)
        {
            TIMER2_HIGH_PRIORITY();
        }
        else if (Copy_stTimer->priority == LOW_PRIORITY)
        {
            TIMER2_LOW_PRIORITY();
        }
#endif
#endif
    }
}
void TIMER2_ISR(void)
{
    TMR2 = GLOP_u8Timer2Preload;
    TIMER2_CLEAR_FLAG();
    if (Timer2InterruptHandeler)
    {
        Timer2InterruptHandeler();
    }
}
