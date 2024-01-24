#include "ADC.h"
#if ADC_INTERRUPT_ENABLE ==INTERRUPT_FEATURE_ENABLE
void (*ADC_InterruptHandeler)(void) = NULL;
#endif
static void ADC_ChannelConfig(ADC_Channel_Select_t channel);
static void ADC_ConversionResultConfig(ADC_congig_t *Copy_stADC);
static void ADC_VoltageRefConfig(ADC_congig_t *Copy_stADC);
static void ADC_InterruptConfig(ADC_congig_t *Copy_stADC);

void ADC_voidADCInit(ADC_congig_t *Copy_stADC) {
    /*Disable ADC */
    ADC_Disable();
    /*configration acquistion time */
    ADCON2bits.ACQT = Copy_stADC->AcquisitionTime;
    /*configration Clock*/
    ADCON2bits.ADCS = Copy_stADC->clock;
    /*configration Channel */
    ADCON0bits.CHS = Copy_stADC->channel;
    ADC_ChannelConfig(Copy_stADC->channel);
    /*configration conversion result*/
    ADC_ConversionResultConfig(Copy_stADC);
    /*configration voltage referance */
    ADC_VoltageRefConfig(Copy_stADC);
    /*Enable Interrupt*/ 
#if ADC_INTERRUPT_ENABLE ==INTERRUPT_FEATURE_ENABLE
    ADC_InterruptHandeler = Copy_stADC->ADC_InterruPtHandeler;
    ADC_ClearFlag();
    ADC_InterruptConfig(Copy_stADC);
    Interrupt_GLOP_InterruptEnable();

    ADC_EnableInterrupt();
#endif
    /*enable adc*/
    ADC_Enable();

}

void ADC_voidADCDeinit(ADC_congig_t *Copy_stADC) {
    ADC_Disable();
#if ADC_INTERRUPT_ENABLE ==INTERRUPT_FEATURE_ENABLE
    ADC_DisableInterrupt();
#endif

}

void ADC_voidSelectChannel(ADC_congig_t *Copy_stADC, u8 Copy_u8Channel) {
    ADC_ChannelConfig(Copy_u8Channel);
    ADC_voidStatrtConversion(Copy_stADC);
}

void ADC_voidStatrtConversion(ADC_congig_t *Copy_stADC) {
    ADC_StatrtConversion();
}

u8 ADC_u8IsConversionDone(ADC_congig_t *Copy_stADC) {
    return ADC_ConversionStatusBit();
}

u16 ADC_u16GetConversionResult(ADC_congig_t *Copy_stADC) {
    if (ADC_RightJustified == Copy_stADC->ResultFormat) {
        return ( (ADRESH << 8) + ADRESL);

    } else {
        return ( ADRESH << 2);

    }
}

u16 ADC_u16GetConversion(ADC_congig_t *Copy_stADC, u8 channel) {
    u16 result = 0;
    ADC_ChannelConfig(channel);
    ADC_voidStatrtConversion(Copy_stADC);
    while (ADCON0bits.GO_nDONE);
    result = ADC_u16GetConversionResult(Copy_stADC);
    return result;
}

static void ADC_ChannelConfig(ADC_Channel_Select_t channel) {
    ADCON0bits.CHS = channel;
    switch (channel) {
        case ADC_CHANNEL_AN0:
            GPIO_VoidSetPinDirection(PORTA, PIN_0, INPUT);
            break;
        case ADC_CHANNEL_AN1:
            GPIO_VoidSetPinDirection(PORTA, PIN_1, INPUT);
            break;
        case ADC_CHANNEL_AN2:
            GPIO_VoidSetPinDirection(PORTA, PIN_2, INPUT);
            break;
        case ADC_CHANNEL_AN3:
            GPIO_VoidSetPinDirection(PORTA, PIN_3, INPUT);
            break;
        case ADC_CHANNEL_AN4:
            GPIO_VoidSetPinDirection(PORTA, PIN_5, INPUT);
        case ADC_CHANNEL_AN5:
            GPIO_VoidSetPinDirection(PORTE, PIN_0, INPUT);
            break;
        case ADC_CHANNEL_AN6:
            GPIO_VoidSetPinDirection(PORTE, PIN_1, INPUT);
            break;
        case ADC_CHANNEL_AN7:
            GPIO_VoidSetPinDirection(PORTE, PIN_2, INPUT);
            break;
        case ADC_CHANNEL_AN8:
            GPIO_VoidSetPinDirection(PORTB, PIN_2, INPUT);
            break;
        case ADC_CHANNEL_AN9:
            GPIO_VoidSetPinDirection(PORTB, PIN_3, INPUT);
            break;
        case ADC_CHANNEL_AN10:
            GPIO_VoidSetPinDirection(PORTB, PIN_1, INPUT);
            break;
        case ADC_CHANNEL_AN11:
            GPIO_VoidSetPinDirection(PORTB, PIN_4, INPUT);
            break;
        case ADC_CHANNEL_AN12:
            GPIO_VoidSetPinDirection(PORTB, PIN_0, INPUT);
            break;
    }
}

static void ADC_ConversionResultConfig(ADC_congig_t *Copy_stADC) {
    if (ADC_RightJustified == Copy_stADC->ResultFormat) {
        ADC_ConversionResult_RightJustified();
    } else {
        ADC_ConversionResult_LeftJustified();
    }
}

static void ADC_VoltageRefConfig(ADC_congig_t *Copy_stADC) {
    if (ADC_Enable_VoltageRef == Copy_stADC->VoltageRef) {
        ADC_EnableVoltageRef();
    } else {
        ADC_DisableVoltageRef();
    }

}
#if ADC_INTERRUPT_ENABLE ==INTERRUPT_FEATURE_ENABLE

void ADC_ISR(void) {
    ADC_ClearFlag();

    if (ADC_InterruptHandeler) {
        ADC_InterruptHandeler();
    }
}

static void ADC_InterruptConfig(ADC_congig_t *Copy_stADC) {
#if   INTERRUPT_PRIORITY_level ==INTERRUPT_FEATURE_ENABLE

    switch (Copy_stADC->priority) {
        case INTERRUPT_Interrupt_LowPriority:
            ADC_LowPriority();
            break;
        case INTERRUPT_Interrupt_HighPriority:
            ADC_HighPriority();

            break;
    }
#endif

}
#endif
