/***********************Includes*****************/
#include "CCP.h"
/*******************Static FUNCTIONS Declarations******************/
static void CCP_Modeconfig(CCP_t *Copy_stCCP);
static void CCP_CaptureModeConfig(CCP_t *Copy_stCCP);
static void CCP_CompareModeConfig(CCP_t *Copy_stCCP);
static void CCP_PWM_ModeConfig(CCP_t *Copy_stCCP);
static void CCP_Interruptconfig(CCP_t *Copy_stCCP);
/* ----------------- Data Type Declarations -----------------*/
void (*CCP1_InterruptHandeler)(void) = NULL;
void (*CCP2_InterruptHandeler)(void) = NULL;

/***************Function Definitions************/
void CCP_voidInit(CCP_t *Copy_stCCP) {
    if (NULL != Copy_stCCP) {
        /*Disable CCP Module*/
        CCP1_MODE_SELECT(CCP_DISABLE);
        CCP2_MODE_SELECT(CCP_DISABLE);
        /*Mode config*/
        CCP_Modeconfig(Copy_stCCP);
        /*CCP1 Interrupt config*/
        CCP_Interruptconfig(Copy_stCCP);
    }
}

void CCP_voidDeinit(CCP_t *Copy_stCCP) {
    if (NULL != Copy_stCCP) {
        switch (Copy_stCCP->ccp_select) {
            case CCP1:
                CCP1_MODE_SELECT(CCP_DISABLE);
                CCP1_DISABLE_INTERRUPT();
                break;
            case CCP2:
                CCP2_MODE_SELECT(CCP_DISABLE);
                CCP2_DISABLE_INTERRUPT();
                break;
        }
    }
}

u8 CCP_u8IsCapturedDataReady(CCP_t *Copy_stCCP) {
    if (NULL != Copy_stCCP) {
        switch (Copy_stCCP->ccp_select) {
            case CCP1:
#if CCP_1_SELECT_MODE == CCP_CAPTURE_MODE
                if (CAPTURE_READY == PIR1bits.CCP1IF) {
                    CCP1_CLEAR_FLAG();
                    return CAPTURE_READY;
                } else {
                    return CAPTURE_NOT_READY;
                }
#endif
                break;

            case CCP2:
#if CCP_2_SELECT_MODE == CCP_CAPTURE_MODE
                if (CAPTURE_READY == PIR2bits.CCP2IF) {
                    CCP2_CLEAR_FLAG();
                    return CAPTURE_READY;
                } else {
                    return CAPTURE_NOT_READY;
                }
#endif
                break;
        }
    }
}

u16 CCP_u16CaptureReadValue(CCP_t *Copy_stCCP) {
    if (NULL != Copy_stCCP) {
        CCP_REG_t CCP_Reg_temp = {.CCPR_HIGH = 0, .CCPR_LOW = 0};

        switch (Copy_stCCP->ccp_select) {
            case CCP1:
#if (CCP_1_SELECT_MODE == CCP_CAPTURE_MODE)
                CCP_Reg_temp.CCPR_LOW = CCPR1L;
                CCP_Reg_temp.CCPR_HIGH = CCPR1H;
                return CCP_Reg_temp.CCPR_16_BIT;
#endif
                break;

            case CCP2:
#if (CCP_2_SELECT_MODE == CCP_CAPTURE_MODE)
                CCP_Reg_temp.CCPR_LOW = CCPR2L;
                CCP_Reg_temp.CCPR_HIGH = CCPR2H;
                return CCP_Reg_temp.CCPR_16_BIT;
#endif
                break;
        }
    }
}

u8 CCP_u8IsComparedDataReady(CCP_t *Copy_stCCP) {
    if (NULL != Copy_stCCP) {
        switch (Copy_stCCP->ccp_select) {
            case CCP1:
#if CCP_1_SELECT_MODE == CCP_COMPARE_MODE
                if (COMPARE_READY == PIR1bits.CCP1IF) {
                    CCP1_CLEAR_FLAG();
                    return COMPARE_READY;
                } else {
                    return COMPARE_NOT_READY;
                }
#endif
                break;

            case CCP2:
#if CCP_2_SELECT_MODE == CCP_COMPARE_MODE
                if (COMPARE_READY == PIR2bits.CCP2IF) {
                    CCP2_CLEAR_FLAG();
                    return COMPARE_READY;
                } else {
                    return COMPARE_NOT_READY;
                }
#endif
                break;
        }
    }
}

void CCP_voidCompareSetValue(CCP_t *Copy_stCCP, u16 Copy_u16Value) {
    if (NULL != Copy_stCCP) {

        CCP_REG_t CCP_Reg_temp = {.CCPR_LOW = 0, .CCPR_HIGH = 0};
        CCP_Reg_temp.CCPR_16_BIT = Copy_u16Value;
        switch (Copy_stCCP->ccp_select) {
            case CCP1:
#if CCP_1_SELECT_MODE == CCP_COMPARE_MODE
                CCPR1L = CCP_Reg_temp.CCPR_LOW;
                CCPR1H = CCP_Reg_temp.CCPR_HIGH;
#endif

                break;

            case CCP2:
#if CCP_2_SELECT_MODE == CCP_COMPARE_MODE

                CCPR2L = CCP_Reg_temp.CCPR_LOW;
                CCPR2H = CCP_Reg_temp.CCPR_HIGH;

#endif
                break;
        }
    }
}

void CCP_voidSetDuty(CCP_t *Copy_stCCP, const u16 Copy_u16Duty) {
    if (NULL != Copy_stCCP) {
        u16 Local_u16DuityTemp = 0;
        switch (Copy_stCCP->ccp_select) {

            case CCP1:
#if CCP_1_SELECT_MODE == CCP_PWM_MODE
                Local_u16DuityTemp = (u16) ((PR2 + 1) * (Copy_u16Duty / 100.0) * 4);
                CCP1CONbits.DC1B = Local_u16DuityTemp & 3;
                CCPR1L = (u8) (Local_u16DuityTemp >> 2);
#endif
                break;

            case CCP2:
#if CCP_2_SELECT_MODE == CCP_PWM_MODE

                Local_u16DuityTemp = (u16) ((PR2 + 1) * (Copy_u16Duty / 100.0) * 4);
                CCP2CONbits.DC2B = Local_u16DuityTemp & 3;
                CCPR2L = (u8) (Local_u16DuityTemp >> 2);
#endif
                break;
        }
    }
}

void CCP_voidPWM_Start(CCP_t *Copy_stCCP) {
    if (NULL != Copy_stCCP) {

        switch (Copy_stCCP->ccp_select) {
            case CCP1:
#if CCP_1_SELECT_MODE == CCP_PWM_MODE

                CCP1_MODE_SELECT(PWM_MODE);
#endif
                break;

            case CCP2:
#if CCP_2_SELECT_MODE == CCP_PWM_MODE

                CCP2_MODE_SELECT(PWM_MODE);
#endif
                break;
        }
    }
}

void CCP_voidPWM_Stop(CCP_t *Copy_stCCP) {
    switch (Copy_stCCP->ccp_select) {
        case CCP1:
#if CCP_1_SELECT_MODE == CCP_PWM_MODE

            CCP1_MODE_SELECT(CCP_DISABLE);
#endif
            break;

        case CCP2:
#if CCP_2_SELECT_MODE == CCP_PWM_MODE

            CCP2_MODE_SELECT(CCP_DISABLE);
#endif
            break;
    }
}

static void CCP_Modeconfig(CCP_t *Copy_stCCP) {
    if (NULL != Copy_stCCP) {
        switch (Copy_stCCP->ccp_select) {
            case CCP1:
                switch (Copy_stCCP->mode) {
                    case Capture_Mode:
                        CCP_CaptureModeConfig(Copy_stCCP);
                        break;

                    case Compare_Mode:
#if (CCP_1_SELECT_MODE == CCP_COMPARE_MODE) || (CCP_2_SELECT_MODE == CCP_COMPARE_MODE)

                        CCP_CompareModeConfig(Copy_stCCP);
#endif
                        break;

                    case PWM_Mode:
                        CCP_PWM_ModeConfig(Copy_stCCP);
                        break;
                }

                break;
            case CCP2:
                switch (Copy_stCCP->mode) {
                    case Capture_Mode:
                        CCP_CaptureModeConfig(Copy_stCCP);
                        break;

                    case Compare_Mode:
#if (CCP_1_SELECT_MODE == CCP_COMPARE_MODE) || (CCP_2_SELECT_MODE == CCP_COMPARE_MODE)

                        CCP_CompareModeConfig(Copy_stCCP);
#endif
                        break;

                    case PWM_Mode:
                        CCP_PWM_ModeConfig(Copy_stCCP);
                        break;
                }

                break;
        }
    }
}

static void CCP_Interruptconfig(CCP_t *Copy_stCCP) {
    if (NULL != Copy_stCCP) {
        switch (Copy_stCCP->ccp_select) {
            case CCP1:
#if CCP1_INTERRUPT_ENABLE == INTERRUPT_FEATURE_ENABLE
                CCP1_DISABLE_INTERRUPT();
                CCP1_CLEAR_FLAG();
                Interrupt_GLOP_InterruptEnable();
                CCP1_InterruptHandeler = Copy_stCCP->CCP1_InterruptHandeler;
                CCP1_ENABLE_INTERRUPT();
#if INTERRUPT_PRIORITY_level == INTERRUPT_FEATURE_ENABLE
                switch (Copy_stCCP->ccp1_priority) {
                    case INTERRUPT_Interrupt_LowPriority:
                        CCP1_LOW_PRIORITY();
                        break;
                    case INTERRUPT_Interrupt_HighPriority:
                        CCP1_HIGH_PRIORITY();
                        break;
                }
#endif
#endif

                break;

            case CCP2:
#if CCP2_INTERRUPT_ENABLE == INTERRUPT_FEATURE_ENABLE
                CCP2_DISABLE_INTERRUPT();
                CCP2_CLEAR_FLAG();
                Interrupt_GLOP_InterruptEnable();
                CCP2_InterruptHandeler = Copy_stCCP->CCP2_InterruptHandeler;
                CCP2_ENABLE_INTERRUPT();
#if INTERRUPT_PRIORITY_level == INTERRUPT_FEATURE_ENABLE
                switch (Copy_stCCP->ccp2_priority) {
                    case INTERRUPT_Interrupt_LowPriority:
                        CCP2_LOW_PRIORITY();
                        break;
                    case INTERRUPT_Interrupt_HighPriority:
                        CCP2_HIGH_PRIORITY();
                        break;
                }
#endif
#endif

                break;
        }
    }
}

#if CCP1_INTERRUPT_ENABLE == INTERRUPT_FEATURE_ENABLE

#if INTERRUPT_PRIORITY_level == INTERRUPT_FEATURE_ENABLE

#endif
#endif

static void CCP_CaptureModeConfig(CCP_t *Copy_stCCP) {
    switch (Copy_stCCP->ccp_select) {

        case CCP1:
#if CCP_1_SELECT_MODE == CCP_CAPTURE_MODE

            GPIO_VoidSetPinDirection(PORTC, PIN2, INPUT);
            switch (Copy_stCCP->CPP_Variant) {
                case CAPTURE_EVERY_FALLING:
                    CCP1_MODE_SELECT(CAPTURE_EVERY_FALLING);
                    break;

                case CAPTURE_EVERY_RISING:
                    CCP1_MODE_SELECT(CAPTURE_EVERY_RISING);
                    break;

                case CAPTURE_EVERY_4TH_RISING:
                    CCP1_MODE_SELECT(CAPTURE_EVERY_4TH_RISING);
                    break;

                case CAPTURE_EVERY_16TH_RISING:
                    CCP1_MODE_SELECT(CAPTURE_EVERY_16TH_RISING);
                    break;
            }
            /*Timer3 and Timer1 to CCPx Enable bits*/
            switch (Copy_stCCP->timer3_timer1_ccp) {
                case TIMER3_CCP:
                    T3CONbits.T3CCP1 = 0;
                    T3CONbits.T3CCP2 = 1;
                    break;
                case TIMER3_CCP2_TIMER1_CCP1:
                    T3CONbits.T3CCP1 = 1;
                    T3CONbits.T3CCP2 = 0;
                    break;
                case TIMER1_CCP:
                    T3CONbits.T3CCP1 = 0;
                    T3CONbits.T3CCP2 = 0;
                    break;
            }
#endif
            break;

        case CCP2:
#if CCP_2_SELECT_MODE == CCP_CAPTURE_MODE

            GPIO_VoidSetPinDirection(PORTC, PIN1, INPUT);
            switch (Copy_stCCP->CPP_Variant) {
                case CAPTURE_EVERY_FALLING:
                    CCP2_MODE_SELECT(CAPTURE_EVERY_FALLING);
                    break;

                case CAPTURE_EVERY_RISING:
                    CCP2_MODE_SELECT(CAPTURE_EVERY_RISING);
                    break;

                case CAPTURE_EVERY_4TH_RISING:
                    CCP2_MODE_SELECT(CAPTURE_EVERY_4TH_RISING);
                    break;

                case CAPTURE_EVERY_16TH_RISING:
                    CCP2_MODE_SELECT(CAPTURE_EVERY_16TH_RISING);
                    break;
            }
            /*Timer3 and Timer1 to CCPx Enable bits*/
            switch (Copy_stCCP->timer3_timer1_ccp) {
                case TIMER3_CCP:
                    T3CONbits.T3CCP1 = 0;
                    T3CONbits.T3CCP2 = 1;
                    break;
                case TIMER3_CCP2_TIMER1_CCP1:
                    T3CONbits.T3CCP1 = 1;
                    T3CONbits.T3CCP2 = 0;
                    break;
                case TIMER1_CCP:
                    T3CONbits.T3CCP1 = 0;
                    T3CONbits.T3CCP2 = 0;
                    break;
            }
#endif
            break;
    }
}
#if (CCP_1_SELECT_MODE == CCP_COMPARE_MODE) || (CCP_2_SELECT_MODE == CCP_COMPARE_MODE)

static void CCP_CompareModeConfig(CCP_t *Copy_stCCP) {
    /*Timer3 and Timer1 to CCPx Enable bits*/
    switch (Copy_stCCP->timer3_timer1_ccp) {
        case TIMER3_CCP:
            T3CONbits.T3CCP1 = 0;
            T3CONbits.T3CCP2 = 1;
            break;
        case TIMER3_CCP2_TIMER1_CCP1:
            T3CONbits.T3CCP1 = 1;
            T3CONbits.T3CCP2 = 0;
            break;
        case TIMER1_CCP:
            T3CONbits.T3CCP1 = 0;
            T3CONbits.T3CCP2 = 0;
            break;
    }
    switch (Copy_stCCP->ccp_select) {

        case CCP1:
#if CCP_1_SELECT_MODE == CCP_COMPARE_MODE

            GPIO_VoidSetPinDirection(PORTC, PIN2, OUTPUT);

            switch (Copy_stCCP->CPP_Variant) {
                case COMPARE_CCP_LOW:
                    CCP1_MODE_SELECT(COMPARE_CCP_LOW);
                    break;

                case COMPARE_CCP_HIGH:
                    CCP1_MODE_SELECT(COMPARE_CCP_HIGH);
                    break;

                case COMPARE_GENERATE_SW_INTERRUPT:
                    CCP1_MODE_SELECT(COMPARE_GENERATE_SW_INTERRUPT);
                    break;

                case COMPARE_TRIGGER_SPECIAL_EVENT:
                    CCP1_MODE_SELECT(COMPARE_TRIGGER_SPECIAL_EVENT);
                    break;

                case COMPARE_TOG_OUTPUT:
                    CCP1_MODE_SELECT(COMPARE_TOG_OUTPUT);
                    break;
            }
#endif

            break;

        case CCP2:
#if CCP_2_SELECT_MODE == CCP_COMPARE_MODE

            GPIO_VoidSetPinDirection(PORTC, PIN1, OUTPUT);

            switch (Copy_stCCP->CPP_Variant) {
                case COMPARE_CCP_LOW:
                    CCP2_MODE_SELECT(COMPARE_CCP_LOW);
                    break;

                case COMPARE_CCP_HIGH:
                    CCP2_MODE_SELECT(COMPARE_CCP_HIGH);
                    break;

                case COMPARE_GENERATE_SW_INTERRUPT:
                    CCP2_MODE_SELECT(COMPARE_GENERATE_SW_INTERRUPT);
                    break;

                case COMPARE_TRIGGER_SPECIAL_EVENT:
                    CCP2_MODE_SELECT(COMPARE_TRIGGER_SPECIAL_EVENT);
                    break;

                case COMPARE_TOG_OUTPUT:
                    CCP2_MODE_SELECT(COMPARE_TOG_OUTPUT);
                    break;
            }
#endif
            break;
    }
}
#endif

static void CCP_PWM_ModeConfig(CCP_t *Copy_stCCP) {
    PR2 = (u8) ((_XTAL_FREQ / (Copy_stCCP->PWM_FREQ * 4.0 * Copy_stCCP->Postscaler * Copy_stCCP->Prescaler)) - 1.0);

    switch (Copy_stCCP->ccp_select) {

        case CCP1:
#if CCP_1_SELECT_MODE == CCP_PWM_MODE
            GPIO_VoidSetPinDirection(PORTC, PIN_2, OUTPUT);
            CCP1_MODE_SELECT(PWM_MODE);

#endif
            break;

        case CCP2:
#if CCP_2_SELECT_MODE == CCP_PWM_MODE
            GPIO_VoidSetPinDirection(PORTC, PIN_1, OUTPUT);
            CCP2_MODE_SELECT(PWM_MODE);

#endif
            break;
    }
}

void CCP1_ISR(void) {
    CCP1_CLEAR_FLAG();
    if (CCP1_InterruptHandeler) {
        CCP1_InterruptHandeler();
    }
}

void CCP2_ISR(void) {
    CCP2_CLEAR_FLAG();
    if (CCP2_InterruptHandeler) {
        CCP2_InterruptHandeler();
    }
}