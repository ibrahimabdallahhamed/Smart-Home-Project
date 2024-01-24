#ifndef USART_H
#define USART_H
/***********************Includes*****************/
#include "../../LIB/pic18f4620.h"
#include "../../LIB/STDTYPES.h"
#include "../../LIB/BITMATH.h"
#include "../GPIO/GPIO_Interface.h"
#include "../Interrupt/Interrupt_interface.h"
#include "USART_config.h"
/*******************MACRO DECLERATIONS***************/
/* Define usart transmittion mode*/
#define USART_TX_SYNCHRONOUS_MODE 0
#define USART_TX_ASYNCHRONOUS_MODE 1
/*Define  9-bit Transmit Enable bit*/
#define USART_ASYNCHRONOUS_TX_9BIT_ENABLE 1
#define USART_ASYNCHRONOUS_TX_9BIT_DISABLE 0
/*Define Transmit Enable bit*/
#define USART_ASYNCHRONOUS_TX_ENABLE 1
#define USART_ASYNCHRONOUS_TX_DISABLE 0
/*Define USART Transmit Interrupt*/
#define USART_ASYNCHRONOUS_TX_INTERRUPT_ENABLE 1
#define USART_ASYNCHRONOUS_TX_INTERRUPT_DISABLE 0
/*Define High Baud Rate Select bit*/
#define USART_ASYNCHRONOUS_BAUD_RATE_HIGH_SPEED 1
#define USART_ASYNCHRONOUS_BAUD_RATE_LOW_SPEED 0
/*Define 16-bit Baud Rate Generator bit*/
#define USART_BAUD_RATE_16CONF 1
#define USART_BAUD_RATE_8CONF 0

/*Define Receive Enable bit*/
#define USART_ASYNCHRONOUS_RX_ENABLE 1
#define USART_ASYNCHRONOUS_RX_DISABLE 0
/*Define  9-bit Receive Enable bit*/
#define USART_ASYNCHRONOUS_RX_9BIT_ENABLE 1
#define USART_ASYNCHRONOUS_RX_9BIT_DISABLE 0
/*Define USART Receive Interrupt*/
#define USART_ASYNCHRONOUS_RX_INTERRUPT_ENABLE 1
#define USART_ASYNCHRONOUS_RX_INTERRUPT_DISABLE 0

/*Define BAUD RATE FORMULAS*/
#define USART_ASYNCHRONOUS_8BIT_LOW_SPEED 0
#define USART_ASYNCHRONOUS_8BIT_HIGH_SPEED 1
#define USART_ASYNCHRONOUS_16BIT_LOW_SPEED 2
#define USART_ASYNCHRONOUS_16BIT_HIGH_SPEED 3
#define USART_SYNCHRONOUS_8BIT 4
#define USART_SYNCHRONOUS_16BIT 5
#define INTERRUPT_HIGH_PRIORITY 1
#define INTERRUPT_LOW_PRIORITY 0

/*******************MACRO FUNCTIONS******************/
/*Function to enable  Serial Port */
#define SERIAL_PORT_ENABLE() (RCSTAbits.SPEN = 1)
/*Function to Disable  Serial Port */
#define SERIAL_PORT_DISABLE() (RCSTAbits.SPEN = 0)
/*----functions to 9-bit Transmit Enable bit------*/
/*Function to enable 9-bit Transmit Enable bit*/
#define ENABLE_9BIT_TRANSMIT() (TXSTAbits.TX9 = 1)
/*Function to Disable 9-bit Transmit Enable bit*/
#define DISABLE_9BIT_TRANSMIT() (TXSTAbits.TX9 = 0)
/*function to enable Transmit*/
#define TRANSMIT_ENABLE() (TXSTAbits.TXEN = 1)
/*function to Disable Transmit*/
#define TRANSMIT_DISABLE() (TXSTAbits.TXEN = 0)
/*Function to set USART as Synchronous mode*/
#define USART_SYNCH_MODE() (TXSTAbits.SYNC = 1)
/*Function to set USART as Asynchronous mode*/
#define USART_ASYNCH_MODE() (TXSTAbits.SYNC = 0)
/*Function to High Baud Rate Select bit*/
#define ASYNCHRONOUS_HIGH_SPEED() (TXSTAbits.BRGH = 1)
#define ASYNCHRONOUS_LOW_SPEED() (TXSTAbits.BRGH = 0)
/*Function to 16-bit Baud Rate Generator bit*/
#define BAUD_RATE_16BIT() (BAUDCONbits.BRG16 = 1)
#define BAUD_RATE_8BIT() (BAUDCONbits.BRG16 = 0)
/*Function to enable TX interrupt*/
#define USART_TX_INTERRUPT_ENABLE() (PIE1bits.TXIE = 1)
/*Function to disable TX interrupt*/
#define USART_TX_INTERRUPT_DISABLE() (PIE1bits.TXIE = 0)
/*Function to clear  tx interrupt flag*/
#define USART_TX_CLEAR_FLAG() (PIR1bits.TXIF = 0)
/*Function to high priority tx interrupt*/
#define USART_TX_HIGH_PRIORITY() (IPR1bits.TXIP = 1)
/*Function to low priority tx interrupt*/
#define USART_TX_LOW_PRIORITY() (IPR1bits.TXIP = 0)

/*Function to enable 9-bit RECEIVE Enable bit*/
#define ENABLE_9BIT_RECEIVE() (RCSTAbits.RC9 = 1)
/*Function to Disable 9-bit RECEIVE DISABLE bit*/
#define DISABLE_9BIT_RECEIVE() (RCSTAbits.RC9 = 0)
/*Function to enable usart receiver*/
#define USART_RX_ENABLE() (RCSTAbits.CREN = 1)
/*Function to DISABLE usart receiver*/
#define USART_RX_DISABLE() (RCSTAbits.CREN = 0)
/*FUNCTION to enable usart receiver interrupt*/
#define USART_RX_INTERRUPT_ENABLE() (PIE1bits.RCIE = 1)
/*FUNCTION to disable usart receiver interrupt*/
#define USART_RX_INTERRUPT_DISABLE() (PIE1bits.RCIE = 0)
/*function to clear usart receiver interrupt flag*/
#define USART_RX_CLEAR_FLAG() (PIR1bits.RCIF = 0)
/*Function to set high priority usart receiver interrupt*/
#define USART_RX_HIGH_PRIORITY() (IPR1bits.RCIP = 1)
/*Function to set LOW priority usart receiver interrupt*/
#define USART_RX_LOW_PRIORITY() (IPR1bits.RCIP = 0)

/* ----------------- Data Type Declarations -----------------*/
typedef struct {
    u8 usart_tx_enable : 1;
    u8 usart_tx_9bit_enable : 1;
#if USART_TX_INTERRUPT_ENABLE_CFG == INTERRUPT_FEATURE_ENABLE
    u8 usart_tx_interrupt_enable : 1;
#if INTERRUPT_PRIORITY_level == INTERRUPT_FEATURE_ENABLE
    u8 usart_tx_interrupt_priority : 1;
#endif
#endif
} usart_tx_t;

typedef struct {
    u8 usart_rx_enable : 1;
    u8 usart_rx_9bit_enable : 1;
#if USART_RX_INTERRUPT_ENABLE_CFG == INTERRUPT_FEATURE_ENABLE
    u8 usart_rx_interrupt_enable : 1;
#if INTERRUPT_PRIORITY_level == INTERRUPT_FEATURE_ENABLE
    u8 usart_rx_interrupt_priority : 1;
#endif
#endif

} usart_rx_t;

typedef union {

    struct {
        u8 reserved : 6;
        u8 OV_error : 1;
        u8 F_error : 1;
    };
    u8 status;

} usart_error_t;

typedef struct {
    u32 BaudRate;
    u8 BaudRate_CFG;
    usart_tx_t transmit;
    usart_rx_t receive;
    usart_error_t Error;
#if USART_TX_INTERRUPT_ENABLE_CFG == INTERRUPT_FEATURE_ENABLE
    void (*USART_TxDefualtInterruptHandeler)(void);
#endif
#if USART_RX_INTERRUPT_ENABLE_CFG == INTERRUPT_FEATURE_ENABLE
    void (*USART_RxDefualtInterruptHandeler)(void);
    void (*USART_FramingErrorInterruptHandeler)(void);
    void (*USART_OverRunErrorInterruptHandeler)(void);
#endif

} usart_t;

/*-------------------Software Interface---------------*/
void USART_voidAsynchUsartInit(const usart_t *Copy_stUsart);
void USART_voidAsynchUsartDeinit(const usart_t *Copy_stUsart);
u8 USART_u8AsynchReadDataBlocking(void);
u8 USART_u8AsynchReadDataNonBlocking(void);
void USART_voidAsynchWriteData(u8 Copy_u8Data);
void USART_voidAsynchWriteString(u8 *Copy_Pu8Data, u8 Copy_u8Len);

#endif /* USART_H */
