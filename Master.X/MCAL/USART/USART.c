/***********************Includes*****************/
#include "USART.h"
/*******************MACRO DECLERATIONS***************/
/*******************MACRO FUNCTIONS******************/
/* ----------------- Data Type Declarations -----------------*/
#if USART_TX_INTERRUPT_ENABLE_CFG == INTERRUPT_FEATURE_ENABLE
void (*UsartTx_InterruptHandeler)(void) = NULL;
#endif
#if USART_RX_INTERRUPT_ENABLE_CFG == INTERRUPT_FEATURE_ENABLE
void (*UsartRx_InterruptHandeler)(void) = NULL;
void (*UsartFramingError_InterruptHandeler)(void) = NULL;
void (*UsartOverRunError_InterruptHandeler)(void) = NULL;
#endif
/*-------------------Static Software Interface---------------*/
static void BaudRateConfig(const usart_t *Copy_stUsart);
static void Tx_config(const usart_t *Copy_stUsart);
#if USART_TX_INTERRUPT_ENABLE_CFG == INTERRUPT_FEATURE_ENABLE
static void Tx_Interruptconfig(const usart_t *Copy_stUsart);
#endif
static void rx_config(const usart_t *Copy_stUsart);
#if USART_RX_INTERRUPT_ENABLE_CFG == INTERRUPT_FEATURE_ENABLE
static void rx_Interruptconfig(const usart_t *Copy_stUsart);
#endif

/*-------------------Software Interface---------------*/
void USART_voidAsynchUsartInit(const usart_t *Copy_stUsart) {
    if (NULL != Copy_stUsart) {
        TRISCbits.RC6 = 1;
        TRISCbits.RC7 = 1;
        SERIAL_PORT_DISABLE();
        BaudRateConfig(Copy_stUsart);
        if (USART_ASYNCHRONOUS_TX_ENABLE == Copy_stUsart->transmit.usart_tx_enable) {
            Tx_config(Copy_stUsart);
        }
        if (USART_ASYNCHRONOUS_RX_ENABLE == Copy_stUsart->receive.usart_rx_enable) {
            rx_config(Copy_stUsart);
        }

        SERIAL_PORT_ENABLE();
    }
}

void USART_voidAsynchUsartDeinit(const usart_t *Copy_stUsart) {
    if (NULL != Copy_stUsart) {
    }
}

u8 USART_u8AsynchReadDataBlocking(void) {
    u8 Local_u8RetunData = 0;

    while (!(PIR1bits.RCIF))
        ;
    if (1 == RCSTAbits.OERR) {
        // EUSART error - restart

        RCSTAbits.CREN = 0;
        RCSTAbits.CREN = 1;
    }

    Local_u8RetunData = RCREG;

    return Local_u8RetunData;
}

u8 USART_u8AsynchReadDataNonBlocking(void) {
    u8 Local_u8RetunData = 0;

    if (PIR1bits.RCIF == 1) {

        Local_u8RetunData = RCREG;
    } else { /*nothing*/
    }

    return Local_u8RetunData;
}

void USART_voidAsynchWriteData(u8 Copy_u8Data) {
    while (0 == PIR1bits.TXIF)
        ;

    TXREG = Copy_u8Data;
    __delay_ms(10);
#if USART_TX_INTERRUPT_ENABLE_CFG == INTERRUPT_FEATURE_ENABLE
    USART_TX_INTERRUPT_ENABLE();
#endif
}

void USART_voidAsynchWriteString(u8 *Copy_Pu8Data, u8 Copy_u8Len) {
    u8 Local_u8Counter = 0;
    for (Local_u8Counter = 0; Local_u8Counter < Copy_u8Len; Local_u8Counter++) {
        USART_voidAsynchWriteData(Copy_Pu8Data[Local_u8Counter]);
    }
}

/*---------Static Function Definition------*/
static void BaudRateConfig(const usart_t *Copy_stUsart) {
    f32 Local_f32BaudRateTemp = 0.0;
    if (NULL != Copy_stUsart) {
        switch (Copy_stUsart->BaudRate_CFG) {
            case USART_ASYNCHRONOUS_8BIT_LOW_SPEED:
                USART_ASYNCH_MODE();
                BAUD_RATE_8BIT();
                ASYNCHRONOUS_LOW_SPEED();
                Local_f32BaudRateTemp = (((f32) _XTAL_FREQ / Copy_stUsart->BaudRate) / 64) - 1;
                break;

            case USART_ASYNCHRONOUS_8BIT_HIGH_SPEED:
                USART_ASYNCH_MODE();
                BAUD_RATE_8BIT();
                ASYNCHRONOUS_HIGH_SPEED();
                Local_f32BaudRateTemp = (((f32) _XTAL_FREQ / Copy_stUsart->BaudRate) / 16) - 1;
                break;

            case USART_ASYNCHRONOUS_16BIT_LOW_SPEED:
                USART_ASYNCH_MODE();
                BAUD_RATE_16BIT();
                ASYNCHRONOUS_LOW_SPEED();
                Local_f32BaudRateTemp = (((f32) _XTAL_FREQ / Copy_stUsart->BaudRate) / 16) - 1;

                break;

            case USART_ASYNCHRONOUS_16BIT_HIGH_SPEED:
                USART_ASYNCH_MODE();
                BAUD_RATE_16BIT();
                ASYNCHRONOUS_HIGH_SPEED();
                Local_f32BaudRateTemp = (((f32) _XTAL_FREQ / Copy_stUsart->BaudRate) / 4) - 1;

                break;

            case USART_SYNCHRONOUS_8BIT:
                USART_SYNCH_MODE();
                BAUD_RATE_8BIT();
                Local_f32BaudRateTemp = (((f32) _XTAL_FREQ / Copy_stUsart->BaudRate) / 4) - 1;

                break;
            case USART_SYNCHRONOUS_16BIT:
                USART_SYNCH_MODE();
                BAUD_RATE_16BIT();
                Local_f32BaudRateTemp = (((f32) _XTAL_FREQ / Copy_stUsart->BaudRate) / 4) - 1;

                break;
        }
        SPBRG = (u8) ((u32) Local_f32BaudRateTemp);
        SPBRGH = (u8) (((u32) Local_f32BaudRateTemp) >> 8);
    }
}

static void Tx_config(const usart_t *Copy_stUsart) {
    if (NULL != Copy_stUsart) {
#if USART_TX_INTERRUPT_ENABLE_CFG == INTERRUPT_FEATURE_ENABLE
        Tx_Interruptconfig(Copy_stUsart);
#endif
        switch (Copy_stUsart->transmit.usart_tx_9bit_enable) {
            case USART_ASYNCHRONOUS_TX_9BIT_ENABLE:
                ENABLE_9BIT_TRANSMIT();
                break;
            case USART_ASYNCHRONOUS_TX_9BIT_DISABLE:
                DISABLE_9BIT_TRANSMIT();
                break;
        }
        TRANSMIT_ENABLE();
    }
}
#if USART_TX_INTERRUPT_ENABLE_CFG == INTERRUPT_FEATURE_ENABLE

static void Tx_Interruptconfig(const usart_t *Copy_stUsart) {
    if (NULL != Copy_stUsart) {
        switch (Copy_stUsart->transmit.usart_tx_interrupt_enable) {
            case USART_ASYNCHRONOUS_TX_INTERRUPT_ENABLE:
                USART_TX_CLEAR_FLAG();
#if INTERRUPT_PRIORITY_level == INTERRUPT_FEATURE_ENABLE
                switch (Copy_stUsart->transmit.usart_tx_interrupt_priority) {
                    case INTERRUPT_HIGH_PRIORITY:
                        USART_TX_HIGH_PRIORITY();
                        break;
                    case INTERRUPT_LOW_PRIORITY:
                        USART_TX_LOW_PRIORITY();
                        break;
                }
#endif
                UsartTx_InterruptHandeler = Copy_stUsart->USART_TxDefualtInterruptHandeler;
                USART_TX_INTERRUPT_ENABLE();
                break;
            case USART_ASYNCHRONOUS_TX_INTERRUPT_DISABLE:
                USART_TX_INTERRUPT_DISABLE();
                break;
        }
        Interrupt_GLOP_InterruptEnable();
    }
}
#endif
#if USART_RX_INTERRUPT_ENABLE_CFG == INTERRUPT_FEATURE_ENABLE

static void rx_Interruptconfig(const usart_t *Copy_stUsart) {
    if (NULL != Copy_stUsart) {
        switch (Copy_stUsart->receive.usart_rx_interrupt_enable) {
            case USART_ASYNCHRONOUS_RX_INTERRUPT_ENABLE:
                USART_RX_CLEAR_FLAG();
#if INTERRUPT_PRIORITY_level == INTERRUPT_FEATURE_ENABLE

                switch (Copy_stUsart->receive.usart_rx_interrupt_priority) {
                    case INTERRUPT_HIGH_PRIORITY:
                        USART_RX_HIGH_PRIORITY();
                        break;
                    case INTERRUPT_LOW_PRIORITY:
                        USART_RX_LOW_PRIORITY();
                        break;
                }
#endif
                UsartRx_InterruptHandeler = Copy_stUsart->USART_RxDefualtInterruptHandeler;
                UsartFramingError_InterruptHandeler = Copy_stUsart->USART_FramingErrorInterruptHandeler;
                UsartOverRunError_InterruptHandeler = Copy_stUsart->USART_OverRunErrorInterruptHandeler;

                USART_RX_INTERRUPT_ENABLE();
                break;
            case USART_ASYNCHRONOUS_RX_INTERRUPT_DISABLE:
                USART_RX_INTERRUPT_DISABLE();
                break;
        }
        Interrupt_GLOP_InterruptEnable();
    }
}
#endif

static void rx_config(const usart_t *Copy_stUsart) {
    if (NULL != Copy_stUsart) {
#if USART_RX_INTERRUPT_ENABLE_CFG == INTERRUPT_FEATURE_ENABLE
        rx_Interruptconfig(Copy_stUsart);
#endif
        switch (Copy_stUsart->receive.usart_rx_9bit_enable) {
            case USART_ASYNCHRONOUS_RX_9BIT_ENABLE:
                ENABLE_9BIT_RECEIVE();
                break;
            case USART_ASYNCHRONOUS_RX_9BIT_DISABLE:
                DISABLE_9BIT_RECEIVE();
                break;
        }
        USART_RX_ENABLE();
    }
}
#if USART_TX_INTERRUPT_ENABLE_CFG == INTERRUPT_FEATURE_ENABLE

void USART_TX_ISR(void) {
    USART_TX_INTERRUPT_DISABLE();
    if (UsartTx_InterruptHandeler) {
        UsartTx_InterruptHandeler();
    }
}
#endif
#if USART_RX_INTERRUPT_ENABLE_CFG == INTERRUPT_FEATURE_ENABLE

void USART_RX_ISR(void) {
    if (UsartRx_InterruptHandeler) {
        UsartRx_InterruptHandeler();
    }
}
#endif