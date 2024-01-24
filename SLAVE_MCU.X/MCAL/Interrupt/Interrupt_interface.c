
#include "Interrupt_interface.h"

void Interrupt_GLOP_InterruptDisable(void) {
#if INTERRUPT_PRIORITY_level == INTERRUPT_FEATURE_ENABLE
    /*function to enable global interrupt high priority */
    INTERRUPT_GlobalInterruptHighDisable();
    /*function to enable global interrupt Low priority */
    INTERRUPT_GlobalInterruptLowDisable();
#else
    /*function to enable global interrupt  priority */
    INTERRUPT_GlobalInterruptDisable();
    /*function to Enable Peripheral interrupt  */
    INTERRUPT_PeripheralInterruptDisable();
#endif
}

void Interrupt_GLOP_InterruptEnable(void) {
#if INTERRUPT_PRIORITY_level == INTERRUPT_FEATURE_ENABLE
    /*Function to choose priorty feature*/
    INTERRUPT_PriorityLevelsEnable();
    /*function to enable global interrupt high priority */
    INTERRUPT_GlobalInterruptHighEnable();
    /*function to enable global interrupt Low priority */
    INTERRUPT_GlobalInterruptLowEnable();
#else
    /*function to enable global interrupt  priority */
    INTERRUPT_PriorityLevelsDisable();
    INTERRUPT_GlobalInterruptEnable();
    /*function to Enable Peripheral interrupt  */
    INTERRUPT_PeripheralInterrupEnable();
#endif
}

#if INTERRUPT_EXTERNAL_INTERRUPT==INTERRUPT_FEATURE_ENABLE
static void (*INT0_InterruptHandeler)(void) = NULL;
static void (*INT1_InterruptHandeler)(void) = NULL;
static void (*INT2_InterruptHandeler)(void) = NULL;

static void (*RB4_InterruptHandeler_High)(void) = NULL;
static void (*RB5_InterruptHandeler_High)(void) = NULL;
static void (*RB6_InterruptHandeler_High)(void) = NULL;
static void (*RB7_InterruptHandeler_High)(void) = NULL;
static void (*RB4_InterruptHandeler_Low)(void) = NULL;
static void (*RB5_InterruptHandeler_Low)(void) = NULL;
static void (*RB6_InterruptHandeler_Low)(void) = NULL;
static void (*RB7_InterruptHandeler_Low)(void) = NULL;

static void Interrupt_INTX_Enable(Interrupt_INTX_T *Copy_stINTX);
static void Interrupt_INTX_Disable(Interrupt_INTX_T *Copy_stINTX);
static void Interrupt_INTX_PriorityLevel(Interrupt_INTX_T *Copy_stINTX);
static void Interrupt_INTX_EdgeUnit(Interrupt_INTX_T *Copy_stINTX);
static void Interrupt_INTX_PinUnit(Interrupt_INTX_T *Copy_stINTX);
static void Interrupt_INTX_ClearFlag(Interrupt_INTX_T *Copy_stINTX);
static void Interrupt_INT0_SetInterruptHandeler(void (*InterruptHandeler)(void));
static void Interrupt_INT1_SetInterruptHandeler(void (*InterruptHandeler)(void));
static void Interrupt_INT2_SetInterruptHandeler(void (*InterruptHandeler)(void));

static void Interrupt_INTX_SetInterruptHandeler(Interrupt_INTX_T *Copy_stINTX);

static void Interrupt_RBX_Enable(Interrupt_RBX_T *Copy_stRBX);
static void Interrupt_RBX_Disable(Interrupt_RBX_T *Copy_stRBX);
static void Interrupt_RBXX_PriorityLevel(Interrupt_RBX_T *Copy_stRBX);
static void Interrupt_RBX_PinUnit(Interrupt_RBX_T *Copy_stRBX);
static void Interrupt_RBX_ClearFlag(Interrupt_RBX_T *Copy_stRBX);

static void Interrupt_RBX_SetInterruptHandeler(Interrupt_RBX_T *Copy_stRBX);

#if INTERRUPT_EXTERNAL_INTERRUPT_INTX==INTERRUPT_FEATURE_ENABLE

void Interrupt_INTX_Init(Interrupt_INTX_T *Copy_stINTX) {
    /*Disable External Interrupt INTX*/
    Interrupt_INTX_Disable(Copy_stINTX);
    /*Clear Flag */
    Interrupt_INTX_ClearFlag(Copy_stINTX);
    /*Configuration Edge */
    Interrupt_INTX_EdgeUnit(Copy_stINTX);
    /*Enable Global Interrupt*/
    Interrupt_GLOP_InterruptEnable();
    /*Configuration Priority*/
#if INTERRUPT_PRIORITY_level == INTERRUPT_FEATURE_ENABLE
    Interrupt_INTX_PriorityLevel(Copy_stINTX);
#endif
    /*Configuration Pin*/
    Interrupt_INTX_PinUnit(Copy_stINTX);
    /*call back function*/
    Interrupt_INTX_SetInterruptHandeler(Copy_stINTX);
    /*Enable External Interrupt INTX*/
    Interrupt_INTX_Enable(Copy_stINTX);
}

void Interrupt_INTX_UnInit(Interrupt_INTX_T *Copy_stINTX) {
    Interrupt_INTX_Disable(Copy_stINTX);
}

static void Interrupt_INTX_Enable(Interrupt_INTX_T *Copy_stINTX) {
    switch (Copy_stINTX->source) {
        case INTERRUPT_ExternalInterrupt_INT0:
            INTERRUPT_INT0_InterruptEnable();
            break;
        case INTERRUPT_ExternalInterrupt_INT1:
            INTERRUPT_INT1_InterruptEnable();
            break;
        case INTERRUPT_ExternalInterrupt_INT2:
            INTERRUPT_INT2_InterruptEnable();
            break;
        default:
            /*nothing*/
            break;
    }
}

static void Interrupt_INTX_Disable(Interrupt_INTX_T *Copy_stINTX) {
    switch (Copy_stINTX->source) {
        case INTERRUPT_ExternalInterrupt_INT0:
            INTERRUPT_INT0_InterruptDisable();
            break;
        case INTERRUPT_ExternalInterrupt_INT1:
            INTERRUPT_INT1_InterruptDisable();
            break;
        case INTERRUPT_ExternalInterrupt_INT2:
            INTERRUPT_INT2_InterruptDisable();
            break;
        default:
            /*nothing*/
            break;
    }
}
#if INTERRUPT_PRIORITY_level == INTERRUPT_FEATURE_ENABLE

static void Interrupt_INTX_PriorityLevel(Interrupt_INTX_T *Copy_stINTX) {
    switch (Copy_stINTX->priority) {
        case INTERRUPT_Interrupt_LowPriority:
            switch (Copy_stINTX->source) {
                case INTERRUPT_ExternalInterrupt_INT1:
                    INTERRUPT_INT1_LowPriority();
                    break;
                case INTERRUPT_ExternalInterrupt_INT2:
                    INTERRUPT_INT2_LowPriority();
                    break;
            }
            break;
        case INTERRUPT_Interrupt_HighPriority:
            switch (Copy_stINTX->source) {

                case INTERRUPT_ExternalInterrupt_INT1:
                    INTERRUPT_INT1_HighPriority();
                    break;
                case INTERRUPT_ExternalInterrupt_INT2:
                    INTERRUPT_INT2_HighPriority();
                    break;
            }
            break;
    }
}
#endif

static void Interrupt_INTX_EdgeUnit(Interrupt_INTX_T *Copy_stINTX) {
    switch (Copy_stINTX->edge) {
        case INTERRUPT_ExternalInterrupt_Falling:
            switch (Copy_stINTX->source) {
                case INTERRUPT_ExternalInterrupt_INT0:
                    INTERRUPT_INT0_FallingEdge();
                    break;
                case INTERRUPT_ExternalInterrupt_INT1:
                    INTERRUPT_INT1_FallingEdge();
                    break;
                case INTERRUPT_ExternalInterrupt_INT2:
                    INTERRUPT_INT2_FallingEdge();
                    break;
            }
            break;
        case INTERRUPT_ExternalInterrupt_Rising:
            switch (Copy_stINTX->source) {
                case INTERRUPT_ExternalInterrupt_INT0:
                    INTERRUPT_INT0_RisingEdge();
                    break;
                case INTERRUPT_ExternalInterrupt_INT1:
                    INTERRUPT_INT1_RisingEdge();
                    break;
                case INTERRUPT_ExternalInterrupt_INT2:
                    INTERRUPT_INT2_RisingEdge();
                    break;
            }
            break;
    }
}

void INT0_ISR(void) {
    /*clear the flag */
    INTERRUPT_INT0_ClearFlag();
    /*callback function*/
    if (INT0_InterruptHandeler) {
        INT0_InterruptHandeler();
    }
}

void INT1_ISR(void) {
    /*clear the flag */
    INTERRUPT_INT1_ClearFlag();
    /*callback function*/
    if (INT1_InterruptHandeler) {
        INT1_InterruptHandeler();
    }
}

void INT2_ISR(void) {
    /*clear the flag */
    INTERRUPT_INT2_ClearFlag();
    /*callback function*/
    if (INT2_InterruptHandeler) {
        INT2_InterruptHandeler();
    }
}

static void Interrupt_INT0_SetInterruptHandeler(void (*InterruptHandeler)(void)) {
    if (NULL != InterruptHandeler) {
        INT0_InterruptHandeler = InterruptHandeler;
    }
}

static void Interrupt_INT1_SetInterruptHandeler(void (*InterruptHandeler)(void)) {
    if (NULL != InterruptHandeler) {
        INT1_InterruptHandeler = InterruptHandeler;
    }
}

static void Interrupt_INT2_SetInterruptHandeler(void (*InterruptHandeler)(void)) {
    if (NULL != InterruptHandeler) {
        INT2_InterruptHandeler = InterruptHandeler;
    }
}

static void Interrupt_INTX_SetInterruptHandeler(Interrupt_INTX_T *Copy_stINTX) {
    switch (Copy_stINTX->source) {
        case INTERRUPT_ExternalInterrupt_INT0:
            Interrupt_INT0_SetInterruptHandeler(Copy_stINTX->EXT_InterruptHandler);
            break;
        case INTERRUPT_ExternalInterrupt_INT1:
            Interrupt_INT1_SetInterruptHandeler(Copy_stINTX->EXT_InterruptHandler);
            break;
        case INTERRUPT_ExternalInterrupt_INT2:
            Interrupt_INT2_SetInterruptHandeler(Copy_stINTX->EXT_InterruptHandler);
            break;
        default:
            /*nothing*/
            break;
    }
}

static void Interrupt_INTX_ClearFlag(Interrupt_INTX_T *Copy_stINTX) {
    switch (Copy_stINTX->source) {
        case INTERRUPT_ExternalInterrupt_INT0:
            INTERRUPT_INT0_ClearFlag();
            break;
        case INTERRUPT_ExternalInterrupt_INT1:
            INTERRUPT_INT1_ClearFlag();
            break;
        case INTERRUPT_ExternalInterrupt_INT2:
            INTERRUPT_INT2_ClearFlag();
            break;
        default:
            /*nothing*/
            break;
    }
}

static void Interrupt_INTX_PinUnit(Interrupt_INTX_T *Copy_stINTX) {
    GPIO_VoidSetPinDirection(Copy_stINTX->pin.Port, Copy_stINTX->pin.Pin, Copy_stINTX->pin.Direction);
}

void Interrupt_RBX_Init(Interrupt_RBX_T *Copy_stRBX) {
    /*Disable External Interrupt RBX*/
    Interrupt_RBX_Disable(Copy_stRBX);
    /*Clear Flag */
    Interrupt_RBX_ClearFlag(Copy_stRBX);
    /*Enable Global Interrupt*/
    Interrupt_GLOP_InterruptEnable();
#if INTERRUPT_PRIORITY_level == INTERRUPT_FEATURE_ENABLE
    Interrupt_RBXX_PriorityLevel(Copy_stRBX);
#endif
    /*Configuration Pin*/
    Interrupt_RBX_PinUnit(Copy_stRBX);
    /*call back function*/
    Interrupt_RBX_SetInterruptHandeler(Copy_stRBX);
    /*Enable External Interrupt RBX*/
    Interrupt_RBX_Enable(Copy_stRBX);
}

void Interrupt_RBX_UnInit(Interrupt_RBX_T *Copy_stRBX) {
    Interrupt_RBX_Disable(Copy_stRBX);
}
#endif
#if INTERRUPT_EXTERNAL_INTERRUPT_RBX==INTERRUPT_FEATURE_ENABLE

void RB4_ISR(u8 Copy_u8State) {
    /*clear the flag */
    INTERRUPT_RBX_ClearFlag();
    /*callback function*/
    if (Copy_u8State == 1) {

        if (RB4_InterruptHandeler_High) {
            RB4_InterruptHandeler_High();
        }
    } else if (Copy_u8State == 0) {

        if (RB4_InterruptHandeler_Low) {
            RB4_InterruptHandeler_Low();
        }
    }
}

void RB5_ISR(u8 Copy_u8State) {
    /*clear the flag */
    INTERRUPT_RBX_ClearFlag();
    /*callback function*/
    if (Copy_u8State == 1) {

        if (RB5_InterruptHandeler_High) {
            RB5_InterruptHandeler_High();
        }
    } else if (Copy_u8State == 0) {

        if (RB5_InterruptHandeler_Low) {
            RB5_InterruptHandeler_Low();
        }
    }
}

void RB6_ISR(u8 Copy_u8State) {
    /*clear the flag */
    INTERRUPT_RBX_ClearFlag();
    /*callback function*/
    if (Copy_u8State == 1) {

        if (RB6_InterruptHandeler_High) {
            RB6_InterruptHandeler_High();
        }
    } else if (Copy_u8State == 0) {

        if (RB6_InterruptHandeler_Low) {
            RB6_InterruptHandeler_Low();
        }
    }
}

void RB7_ISR(u8 Copy_u8State) {
    /*clear the flag */
    INTERRUPT_RBX_ClearFlag();
    /*callback function*/
    if (Copy_u8State == 1) {

        if (RB7_InterruptHandeler_High) {
            RB7_InterruptHandeler_High();
        }
    } else if (Copy_u8State == 0) {

        if (RB7_InterruptHandeler_Low) {
            RB7_InterruptHandeler_Low();
        }
    }
}

static void Interrupt_RBX_Enable(Interrupt_RBX_T *Copy_stRBX) {
    INTERRUPT_RBX_InterruptEnable();
}

static void Interrupt_RBX_Disable(Interrupt_RBX_T *Copy_stRBX) {
    INTERRUPT_RBX_InterruptDisable();
}
#if INTERRUPT_PRIORITY_level == INTERRUPT_FEATURE_ENABLE

static void Interrupt_RBXX_PriorityLevel(Interrupt_RBX_T *Copy_stRBX) {
    switch (Copy_stRBX->priority) {
        case INTERRUPT_Interrupt_HighPriority:
            INTERRUPT_RBX_HighPriority();
            break;
        case INTERRUPT_Interrupt_LowPriority:
            INTERRUPT_RBX_LowPriority();
            break;
    }
}
#endif

static void Interrupt_RBX_PinUnit(Interrupt_RBX_T *Copy_stRBX) {
    GPIO_VoidSetPinDirection(Copy_stRBX->pin.Port, Copy_stRBX->pin.Pin, Copy_stRBX->pin.Direction);
}

static void Interrupt_RBX_ClearFlag(Interrupt_RBX_T *Copy_stRBX) {
    INTERRUPT_RBX_ClearFlag();
}

static void Interrupt_RBX_SetInterruptHandeler(Interrupt_RBX_T *Copy_stRBX) {
    switch (Copy_stRBX->pin.Pin) {
        case PIN4:
            RB4_InterruptHandeler_High = Copy_stRBX->EXT_InterruptHandler_HIGH;
            RB4_InterruptHandeler_Low = Copy_stRBX->EXT_InterruptHandler_LOW;
            break;
        case PIN5:
            RB5_InterruptHandeler_High = Copy_stRBX->EXT_InterruptHandler_HIGH;
            RB5_InterruptHandeler_Low = Copy_stRBX->EXT_InterruptHandler_LOW;
            break;
        case PIN6:
            RB6_InterruptHandeler_High = Copy_stRBX->EXT_InterruptHandler_HIGH;
            RB6_InterruptHandeler_Low = Copy_stRBX->EXT_InterruptHandler_LOW;
            break;
        case PIN7:
            RB7_InterruptHandeler_High = Copy_stRBX->EXT_InterruptHandler_HIGH;
            RB7_InterruptHandeler_Low = Copy_stRBX->EXT_InterruptHandler_LOW;
            break;

        default:
            break;
    }
}
#endif
#endif
