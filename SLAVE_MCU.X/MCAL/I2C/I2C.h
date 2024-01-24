#ifndef I2C_H
#define I2C_H
/***********************Includes*****************/
#include "../../LIB/pic18f4620.h"
#include "../../LIB/STDTYPES.h"
#include "../../LIB/BITMATH.h"
#include "../../LIB/device_config.h"

#include "../GPIO/GPIO_Interface.h"
#include "../Interrupt/Interrupt_interface.h"
/*******************MACRO DECLERATIONS***************/
#define I2C_MASTER 1
#define I2C_SLAVE 0
#define HIGH_PRIORITY 1
#define LOW_PRIORITY 0
#define I2C_SLAVE_10BIT_ADSRESS_SS_ENABLE 0x0FU
#define I2C_SLAVE_7BIT_ADSRESS_SS_ENABLE 0x0EU
#define I2C_MASTER_FIRMWARE_CONTROLLED 0x0BU
#define I2C_MASTER_DEFIENED_CLOCK 0x08U
#define I2C_SLAVE_10BIT_ADSRESS 0x07U
#define I2C_SLAVE_7BIT_ADSRESS 0x06U

#define SMBUS_EBABLE 1
#define SMBUS_DISABLE 0
#define SLEW_RATE_ENABLE 0
#define SLEW_RATE_DISABLE 1
#define GENERAL_CALL_ENABLE 1
#define GENERAL_CALL_DISABLE 0

#define I2C_MASTER_SEND_ACK 0
#define I2C_MASTER_SEND_NOT_ACK 1

/*******************MACRO FUNCTIONS******************/
/*enable i2c */
#define I2C_MODULE_ENABLE() (SSPCON1bits.SSPEN = 1)
/*disable i2c */
#define I2C_MODULE_DISABLE() (SSPCON1bits.SSPEN = 0)
/*CONFIG I2C MODE*/
#define I2C_MODE_CFG(config) (SSPCON1bits.SSPM = config)
/*Function to Slew Rate Control bit*/
#define SLEW_RATE_ENABLE_CFG() (SSPSTATbits.SMP = 0)
#define SLEW_RATE_DISABLE_CFG() (SSPSTATbits.SMP = 1)
/*Functions to Read/Write Information bit */
#define SLAVE_READ_MODE() (SSPSTATbits.RW = 1)
#define SLAVE_WRITE_MODE() (SSPSTATbits.RW = 0)
/*disable sm bus */
#define SMBUS_ENABLE_CFG() (SSPSTATbits.CKE = 1)
/*enable sm bus */
#define SMBUS_DISABLE_CFG() (SSPSTATbits.CKE = 0)
/*enable general call function*/
#define GENERAL_CALL_ENABLE_CFG() (SSPCON2bits.GCEN = 1)
/*disable general call function*/
#define GENERAL_CALL_DISABLE_CFG() (SSPCON2bits.GCEN = 0)
/*enable master receive mode function */
#define MASTER_RECEIVE_MODE_ENABLE() (SSPCON2bits.RCEN = 1)
/*disable master receive mode function */
#define MASTER_RECEIVE_MODE_DISABLE() (SSPCON2bits.RCEN = 0)
/*  I2C CLEAR INTERRUPT FLAG*/
#define I2C_CLEAR_FLAG() (PIR1bits.SSPIF = 0)
/*ENABLE I2C INTERRUPT*/
#define I2C_INTERRUPT_ENABLE() (PIE1bits.SSPIE = 1)
/*DISABLE I2C INTERRUPT*/
#define I2C_INTERRUPT_DISABLE() (PIE1bits.SSPIE = 0)
/*SET HIGH PRIORITY I2C INTERRUPT*/
#define I2C_HIGH_PRIORITY() (IPR1bits.SSPIP = 1)
/*SET LOW PRIORITY I2C INTERRUPT*/
#define I2C_LOW_PRIORITY() (IPR1bits.SSPIP = 0)
#define I2C_BUS_COLLOISION_INTERRUPT_ENABLE_CFG() (PIE2bits.BCLIE = 1)
#define I2C_BUS_COLLOISION_INTERRUPT_DISABLE_CFG() (PIE2bits.BCLIE = 0)
#define I2C_BUS_COLLOISION_CLEAR_FLAG() (PIR2bits.BCLIF = 0)
#define I2C_BUS_COLLOISION_HIGH_PRIORITY() (IPR2bits.BCLIP = 1)
#define I2C_BUS_COLLOISION_LOW_PRIORITY() (IPR2bits.BCLIP = 0)
#define I2C_CLOCK_STRETCH_ENABLE()          (SSPCON1bits.CKP = 0)
#define I2C_CLOCK_STRETCH_DISABLE()         (SSPCON1bits.CKP = 1)

/* ----------------- Data Type Declarations -----------------*/
typedef struct {
    u8 i2c_mode_cfg;
    u8 i2c_slave_add;
    u8 i2c_mode : 1;
    u8 i2c_slew_rate : 1;
    u8 i2c_smBUS : 1;
    u8 i2c_general_call : 1;

} I2C_CFG_t;

typedef struct {
    u32 master_clk;
#if I2C_INTERRUPT_ENABLE_CFG == INTERRUPT_FEATURE_ENABLE
    void (*I2C_InterruptHandeler)(void);
    void (*I2C_BusColloisionInterruptHandeler)(void);
#if INTERRUPT_PRIORITY_level == INTERRUPT_FEATURE_ENABLE
    u8 i2c_priority : 1;
    u8 i2c_BusColloison_priority : 1;
#endif
#endif
    I2C_CFG_t i2c_cfg;

} I2C_t;
void I2C_voidI2CInit(const I2C_t *Copy_stI2C);
void I2C_voidI2CDeinit(const I2C_t *Copy_stI2C);
void I2C_voidSendStartCond(const I2C_t *Copy_stI2C);
void I2C_voidSendRebeatStartCond(const I2C_t *Copy_stI2C);
void I2C_voidSendStopCond(const I2C_t *Copy_stI2C);
u8 I2C_u8WriteByteBlocking(const I2C_t *Copy_stI2C, u8 Copy_u8Data);
u8 I2C_u8ReadRegByte(const I2C_t *Copy_stI2C, u8 Copy_u8I2C_Address, u8 Copy_u8Byte_Address);
u8 I2C_u8WriteByteRegBlocking(const I2C_t *Copy_stI2C, u8 Copy_u8I2C_Address, u8 Copy_u8Byte_Address, u8 Copy_u8Data);
u8 I2C_u8ReadByte(const I2C_t *Copy_stI2C, u8 Copy_u8Ack);
u8 I2C_Read(void);
u8 I2C_u8ReadByteBlocking(const I2C_t *Copy_stI2C, u8 Copy_u8Ack);

#endif /* I2C_H */
