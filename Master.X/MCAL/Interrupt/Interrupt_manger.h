/*
 * File:   Interrupt_manger.h
 * Author: dell
 *
 * Created on October 21, 2023, 10:43 AM
 */

#ifndef INTERRUPT_MANGER_H
#define INTERRUPT_MANGER_H
#include "Interrupt_config.h"
#if INTERRUPT_EXTERNAL_INTERRUPT == INTERRUPT_FEATURE_ENABLE
#if INTERRUPT_EXTERNAL_INTERRUPT_INTX == INTERRUPT_FEATURE_ENABLE
void INT0_ISR(void);
void INT1_ISR(void);
void INT2_ISR(void);
#endif
#if INTERRUPT_EXTERNAL_INTERRUPT_RBX == INTERRUPT_FEATURE_ENABLE

void RB4_ISR(u8 Copy_u8State);
void RB5_ISR(u8 Copy_u8State);
void RB6_ISR(u8 Copy_u8State);
void RB7_ISR(u8 Copy_u8State);
#endif
#endif
void ADC_ISR(void);
void TIMER0_ISR(void);
void TIMER1_ISR(void);
void TIMER2_ISR(void);
void TIMER3_ISR(void);
void CCP1_ISR(void);
void CCP2_ISR(void);
#if USART_TX_INTERRUPT_ENABLE_CFG == INTERRUPT_FEATURE_ENABLE
void USART_TX_ISR(void);
#endif
#if USART_RX_INTERRUPT_ENABLE_CFG == INTERRUPT_FEATURE_ENABLE
void USART_RX_ISR(void);
#endif
#if SPI_INTERRUPT_ENABLE_CFG == INTERRUPT_FEATURE_ENABLE
void SPI_ISR(void);
#endif
#if I2C_INTERRUPT_ENABLE_CFG == INTERRUPT_FEATURE_ENABLE
void I2C_ISR(void);
void I2C_BUSColloision_ISR(void);
#endif


#endif /* INTERRUPT_MANGER_H */
