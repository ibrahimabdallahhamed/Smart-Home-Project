#include "Interrupt_manger.h"
static volatile u8 RB4_flag = 1, RB5_flag = 1, RB6_flag = 1, RB7_flag = 1;
#if INTERRUPT_PRIORITY_level == INTERRUPT_FEATURE_ENABLE

void __interrupt() InterruptMangerHigh(void) {
#if INTERRUPT_EXTERNAL_INTERRUPT_INTX == INTERRUPT_FEATURE_ENABLE

    if ((INTERRUPT_ENABLE == (INTCONbits.INT0IE)) && (INTERRUPT_OCCUR == (INTCONbits.INT0IF))) {
        INT0_ISR();
    }
    if ((INTERRUPT_ENABLE == (INTCON3bits.INT2IE)) && (INTERRUPT_OCCUR == (INTCON3bits.INT2IF))) {
        INT2_ISR();
    }
#endif
#if ADC_INTERRUPT_ENABLE == INTERRUPT_FEATURE_ENABLE

    if ((INTERRUPT_ENABLE == (PIE1bits.ADIE)) && (INTERRUPT_OCCUR == (PIR1bits.ADIF))) {
        ADC_ISR();
    }
#endif
#if TIMER0_INTERRUPT_ENABLE == INTERRUPT_FEATURE_ENABLE

    if ((INTERRUPT_ENABLE == (INTCONbits.TMR0IE)) && (INTERRUPT_OCCUR == (INTCONbits.TMR0IF))) {
        TIMER0_ISR();
    }
#endif
#if TIMER1_INTERRUPT_ENABLE == INTERRUPT_FEATURE_ENABLE

    if ((INTERRUPT_ENABLE == (PIE1bits.TMR1IE)) && (INTERRUPT_OCCUR == (PIR1bits.TMR1IF))) {
        TIMER1_ISR();
    }
#endif
#if TIMER2_INTERRUPT_ENABLE == INTERRUPT_FEATURE_ENABLE

    if ((INTERRUPT_ENABLE == (PIE1bits.TMR2IE)) && (INTERRUPT_OCCUR == (PIR1bits.TMR2IF))) {
        TIMER2_ISR();
    }
#endif
#if TIMER3_INTERRUPT_ENABLE == INTERRUPT_FEATURE_ENABLE

    if ((INTERRUPT_ENABLE == (PIE2bits.TMR3IE)) && (INTERRUPT_OCCUR == (PIR2bits.TMR3IF))) {
        TIMER3_ISR();
    }
#endif
#if CCP1_INTERRUPT_ENABLE == INTERRUPT_FEATURE_ENABLE

    if ((INTERRUPT_ENABLE == (PIE1bits.CCP1IE)) && (INTERRUPT_OCCUR == (PIR1bits.CCP1IF))) {
        CCP1_ISR();
    }
#endif
#if CCP2_INTERRUPT_ENABLE == INTERRUPT_FEATURE_ENABLE

    if ((INTERRUPT_ENABLE == (PIE2bits.CCP2IE)) && (INTERRUPT_OCCUR == (PIR2bits.CCP2IF))) {
        CCP2_ISR();
    }
#endif
#if USART_TX_INTERRUPT_ENABLE_CFG == INTERRUPT_FEATURE_ENABLE
    if ((INTERRUPT_ENABLE == (PIE1bits.TXIE)) && (INTERRUPT_OCCUR == (PIR1bits.TXIF))) {
        USART_TX_ISR();
    }
#endif
#if USART_RX_INTERRUPT_ENABLE_CFG == INTERRUPT_FEATURE_ENABLE
    if ((INTERRUPT_ENABLE == (PIE1bits.RCIE)) && (INTERRUPT_OCCUR == (PIR1bits.RCIF))) {
        USART_RX_ISR();
    }
#endif
#if SPI_INTERRUPT_ENABLE_CFG == INTERRUPT_FEATURE_ENABLE
    if ((INTERRUPT_ENABLE == (PIE1bits.SSPIE)) && (INTERRUPT_OCCUR == (PIR1bits.SSPIF))) {
        SPI_ISR();
    }
#endif
#if I2C_INTERRUPT_ENABLE_CFG == INTERRUPT_FEATURE_ENABLE
    if ((INTERRUPT_ENABLE == (PIE1bits.SSPIE)) && (INTERRUPT_OCCUR == (PIR1bits.SSPIF))) {
        I2C_ISR();
    }
    if ((INTERRUPT_ENABLE == (PIE2bits.BCLIE)) && (INTERRUPT_OCCUR == (PIR2bits.BCLIF))) {
        I2C_BUSColloision_ISR();
    }
#endif
}

void __interrupt(low_priority) InterruptMangerLow(void) {
#if INTERRUPT_EXTERNAL_INTERRUPT_INTX == INTERRUPT_FEATURE_ENABLE

    if ((INTERRUPT_ENABLE == (INTCON3bits.INT1IE)) && (INTERRUPT_OCCUR == (INTCON3bits.INT1IF))) {
        INT1_ISR();
    }
#endif
}

#else

void __interrupt() InterruptManger(void) {
#if INTERRUPT_EXTERNAL_INTERRUPT == INTERRUPT_FEATURE_ENABLE
#if INTERRUPT_EXTERNAL_INTERRUPT_INTX == INTERRUPT_FEATURE_ENABLE
    if ((INTERRUPT_ENABLE == (INTCONbits.INT0IE)) && (INTERRUPT_OCCUR == (INTCONbits.INT0IF))) {
        INT0_ISR();
    }
    if ((INTERRUPT_ENABLE == (INTCON3bits.INT1IE)) && (INTERRUPT_OCCUR == (INTCON3bits.INT1IF))) {
        INT1_ISR();
    }
    if ((INTERRUPT_ENABLE == (INTCON3bits.INT2IE)) && (INTERRUPT_OCCUR == (INTCON3bits.INT2IF))) {
        INT2_ISR();
    }
#endif
#if INTERRUPT_EXTERNAL_INTERRUPT_RBX == INTERRUPT_FEATURE_ENABLE

    if ((INTERRUPT_ENABLE == (INTCONbits.RBIE)) && (INTERRUPT_OCCUR == (INTCONbits.RBIF)) && ((PORTBbits.RB4) == HIGH) && (RB4_flag == 1)) {
        RB4_flag = 0;
        RB4_ISR(1);
    }
    if ((INTERRUPT_ENABLE == (INTCONbits.RBIE)) && (INTERRUPT_OCCUR == (INTCONbits.RBIF)) && ((PORTBbits.RB4) == LOW) && (RB4_flag == 0)) {
        RB4_flag = 1;
        RB4_ISR(0);
    }
    if ((INTERRUPT_ENABLE == (INTCONbits.RBIE)) && (INTERRUPT_OCCUR == (INTCONbits.RBIF)) && ((PORTBbits.RB5) == HIGH) && (RB5_flag == 1)) {
        RB5_flag = 0;
        RB5_ISR(1);
    }
    if ((INTERRUPT_ENABLE == (INTCONbits.RBIE)) && (INTERRUPT_OCCUR == (INTCONbits.RBIF)) && ((PORTBbits.RB5) == LOW) && (RB5_flag == 0)) {
        RB5_flag = 1;
        RB5_ISR(0);
    }
    if ((INTERRUPT_ENABLE == (INTCONbits.RBIE)) && (INTERRUPT_OCCUR == (INTCONbits.RBIF)) && ((PORTBbits.RB6) == HIGH) && (RB6_flag == 1)) {
        RB6_flag = 0;
        RB6_ISR(1);
    }
    if ((INTERRUPT_ENABLE == (INTCONbits.RBIE)) && (INTERRUPT_OCCUR == (INTCONbits.RBIF)) && ((PORTBbits.RB6) == LOW) && (RB6_flag == 0)) {
        RB6_flag = 1;
        RB6_ISR(0);
    }
    if ((INTERRUPT_ENABLE == (INTCONbits.RBIE)) && (INTERRUPT_OCCUR == (INTCONbits.RBIF)) && ((PORTBbits.RB7) == HIGH) && (RB7_flag == 1)) {
        RB7_flag = 0;
        RB7_ISR(1);
    }
    if ((INTERRUPT_ENABLE == (INTCONbits.RBIE)) && (INTERRUPT_OCCUR == (INTCONbits.RBIF)) && ((PORTBbits.RB7) == LOW) && (RB7_flag == 0)) {
        RB7_flag = 1;
        RB7_ISR(0);
    }
#if ADC_INTERRUPT_ENABLE == INTERRUPT_FEATURE_ENABLE

    if ((INTERRUPT_ENABLE == (PIE1bits.ADIE)) && (INTERRUPT_OCCUR == (PIR1bits.ADIF))) {
        ADC_ISR();
    }
#endif


#endif
#endif
#if I2C_INTERRUPT_ENABLE_CFG == INTERRUPT_FEATURE_ENABLE
    if ((INTERRUPT_ENABLE == (PIE1bits.SSPIE)) && (INTERRUPT_OCCUR == PIR1bits.SSPIF)) {
        I2C_ISR();
    }
    if ((INTERRUPT_ENABLE == (PIE2bits.BCLIE)) && (INTERRUPT_OCCUR == (PIR2bits.BCLIF))) {
        I2C_BUSColloision_ISR();
    }
#endif
#if TIMER0_INTERRUPT_ENABLE == INTERRUPT_FEATURE_ENABLE

    if ((INTERRUPT_ENABLE == (INTCONbits.TMR0IE)) && (INTERRUPT_OCCUR == (INTCONbits.TMR0IF))) {
        TIMER0_ISR();
    }
#endif
}

#endif