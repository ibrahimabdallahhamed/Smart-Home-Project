#include "I2C.h"

/*-----------------static function decleration -----------*/
static void I2C_MasterMode_CFG(const I2C_t *Copy_stI2C);
static void I2C_SlaveMode_CFG(const I2C_t *Copy_stI2C);
#if I2C_INTERRUPT_ENABLE_CFG == INTERRUPT_FEATURE_ENABLE
static void I2C_Interrupt_CFG(const I2C_t *Copy_stI2C);
void (*i2c_interrupt_handeler)(void) = NULL;
void (*i2c_bus_colloision_interrupt_handeler)(void) = NULL;

#endif

void I2C_voidI2CInit(const I2C_t *Copy_stI2C)
{
    if (NULL != Copy_stI2C)
    {
        /*disable i2c module */
        I2C_MODULE_DISABLE();
        /*configration I2C mode */
        if (I2C_MASTER == Copy_stI2C->i2c_cfg.i2c_mode)
        {
            I2C_MasterMode_CFG(Copy_stI2C);
        }
        else if (I2C_SLAVE == Copy_stI2C->i2c_cfg.i2c_mode)
        {
            /*release clock*/
            SSPCON1bits.CKP = 1;
            /*NO OVERFLOW*/
            SSPCON1bits.SSPOV = 0;
            /* No collision*/
            SSPCON1bits.WCOL = 0;
            I2C_SlaveMode_CFG(Copy_stI2C);
            /*configration GENERAL CALL*/
            switch (Copy_stI2C->i2c_cfg.i2c_general_call)
            {
            case GENERAL_CALL_DISABLE:
                GENERAL_CALL_DISABLE_CFG();
                break;
            case GENERAL_CALL_ENABLE:
                GENERAL_CALL_ENABLE_CFG();
                break;
            default:
                break;
            }
            SSPADD = Copy_stI2C->i2c_cfg.i2c_slave_add;
        }

        /*configration I2C pins*/
        TRISCbits.TRISC3 = 1; /* Serial clock (SCL) is Input */
        TRISCbits.TRISC4 = 1; /* Serial data (SDA) is Input */
        /*configration I2C SMBUS*/
        switch (Copy_stI2C->i2c_cfg.i2c_smBUS)
        {
        case SMBUS_DISABLE:
            SMBUS_DISABLE_CFG();
            break;
        case SMBUS_EBABLE:
            SMBUS_ENABLE_CFG();
            break;
        default:
            break;
        }
        /*configration slew rate*/
        switch (Copy_stI2C->i2c_cfg.i2c_slew_rate)
        {
        case SLEW_RATE_DISABLE:
            SLEW_RATE_DISABLE_CFG();
            break;
        case SLEW_RATE_ENABLE:
            SLEW_RATE_ENABLE_CFG();
            break;
        default:
            break;
        }
#if I2C_INTERRUPT_ENABLE_CFG == INTERRUPT_FEATURE_ENABLE
        I2C_Interrupt_CFG(Copy_stI2C);
#endif
        /*enable i2c module */
        I2C_MODULE_ENABLE();
    }
}

void I2C_voidI2CDeinit(const I2C_t *Copy_stI2C)
{
    if (NULL != Copy_stI2C)
    {
    }
}

void I2C_voidSendStartCond(const I2C_t *Copy_stI2C)
{

    if (NULL != Copy_stI2C)
    {
        SSPCON2bits.SEN = 1;
        while (SSPCON2bits.SEN)
            ;
        I2C_CLEAR_FLAG();
    }
}

void I2C_voidSendRebeatStartCond(const I2C_t *Copy_stI2C)
{
    if (NULL != Copy_stI2C)
    {
        SSPCON2bits.RSEN = 1;
        while (SSPCON2bits.RSEN)
            ;
        PIR1bits.SSPIF = 0;
    }
}

void I2C_voidSendStopCond(const I2C_t *Copy_stI2C)
{

    if (NULL != Copy_stI2C)
    {
        SSPCON2bits.PEN = 1;
        while (SSPCON2bits.PEN == 1)
            ;
        PIR1bits.SSPIF = 0;
    }
}

u8 I2C_u8WriteByteBlocking(const I2C_t *Copy_stI2C, u8 Copy_u8Data)
{
    if (SSPCON1bits.WCOL == 1)
    {
        SSPCON1bits.WCOL = 0;
    }
    u8 Local_u8Return = 0;
    if (NULL != Copy_stI2C)
    {
        SSPBUF = Copy_u8Data;
        while (!PIR1bits.SSPIF)
            ;
        I2C_CLEAR_FLAG();
        Local_u8Return = SSPCON2bits.ACKSTAT;
    }
    if (SSPCON1bits.WCOL == 1)
    {
        SSPCON1bits.WCOL = 0;
    }
    return Local_u8Return;
}

u8 I2C_u8ReadByteBlocking(const I2C_t *Copy_stI2C, u8 Copy_u8Ack)
{
    u8 Local_u8Return = 0;

    if (NULL != Copy_stI2C)
    {
        MASTER_RECEIVE_MODE_ENABLE();
        while (!SSPSTATbits.BF)
            ;
        Local_u8Return = SSPBUF;
        if (Copy_u8Ack == I2C_MASTER_SEND_ACK)
        {
            SSPCON2bits.ACKDT = I2C_MASTER_SEND_ACK;
            /* Initiates Acknowledge sequence on SDA and SCL pins and transmit ACKDT data bit. */
            /* Automatically cleared by hardware */
        }
        else if (Copy_u8Ack == I2C_MASTER_SEND_NOT_ACK)
        {
            SSPCON2bits.ACKDT = I2C_MASTER_SEND_NOT_ACK;
            /* Initiates Acknowledge sequence on SDA and SCL pins and transmit ACKDT data bit. */
            SSPCON2bits.ACKEN = 1;
            /* Automatically cleared by hardware */
        }
        return Local_u8Return;
    }
}

static void I2C_MasterMode_CFG(const I2C_t *Copy_stI2C)
{
    I2C_MODE_CFG(Copy_stI2C->i2c_cfg.i2c_mode_cfg);

    switch (Copy_stI2C->i2c_cfg.i2c_mode_cfg)
    {
    case I2C_MASTER_FIRMWARE_CONTROLLED:
        break;
    case I2C_MASTER_DEFIENED_CLOCK:
        SSPADD = (u8)(((_XTAL_FREQ / 4.0) / Copy_stI2C->master_clk) - 1);

        break;
    default:
        break;
    }
}

static void I2C_SlaveMode_CFG(const I2C_t *Copy_stI2C)
{
    I2C_MODE_CFG(Copy_stI2C->i2c_cfg.i2c_mode_cfg);
}
#if I2C_INTERRUPT_ENABLE_CFG == INTERRUPT_FEATURE_ENABLE

static void I2C_Interrupt_CFG(const I2C_t *Copy_stI2C)
{
    if (NULL != Copy_stI2C)
    {
        I2C_CLEAR_FLAG();
        I2C_BUS_COLLOISION_CLEAR_FLAG();

        i2c_interrupt_handeler = Copy_stI2C->I2C_InterruptHandeler;
        i2c_bus_colloision_interrupt_handeler = Copy_stI2C->I2C_BusColloisionInterruptHandeler;
        Interrupt_GLOP_InterruptEnable();
        I2C_BUS_COLLOISION_INTERRUPT_ENABLE_CFG();
        I2C_INTERRUPT_ENABLE();

#if INTERRUPT_PRIORITY_level == INTERRUPT_FEATURE_ENABLE
        switch (Copy_stI2C->i2c_priority)
        {
        case HIGH_PRIORITY:
            I2C_HIGH_PRIORITY();
            break;
        case LOW_PRIORITY:
            I2C_LOW_PRIORITY();
            break;
        }
        switch (Copy_stI2C->i2c_BusColloison_priority)
        {
        case HIGH_PRIORITY:
            I2C_BUS_COLLOISION_HIGH_PRIORITY();
            break;
        case LOW_PRIORITY:
            I2C_BUS_COLLOISION_LOW_PRIORITY();
            break;
        }
#endif
    }
}

void I2C_ISR(void)
{
    I2C_CLEAR_FLAG();
    if (i2c_interrupt_handeler)
    {
        i2c_interrupt_handeler();
    }
}

void I2C_BUSColloision_ISR(void)
{
    I2C_BUS_COLLOISION_CLEAR_FLAG();
    if (i2c_bus_colloision_interrupt_handeler)
    {
        i2c_bus_colloision_interrupt_handeler();
    }
}
#endif

u8 I2C_u8WriteByteRegBlocking(const I2C_t *Copy_stI2C, u8 Copy_u8I2C_Address, u8 Copy_u8Byte_Address, u8 Copy_u8Data)
{
    if (NULL != Copy_stI2C)
    {
        I2C_voidSendStartCond(Copy_stI2C);
        I2C_u8WriteByteBlocking(Copy_stI2C, Copy_u8I2C_Address);
        I2C_u8WriteByteBlocking(Copy_stI2C, Copy_u8Byte_Address);
        I2C_u8WriteByteBlocking(Copy_stI2C, Copy_u8Data);
        I2C_voidSendStopCond(Copy_stI2C);
    }
    return 0;
}

u8 I2C_u8ReadRegByte(const I2C_t *Copy_stI2C, u8 Copy_u8I2C_Address, u8 Copy_u8Byte_Address)
{
    u8 returnedData = 0;
    if (NULL != Copy_stI2C)
    {
        I2C_voidSendStartCond(Copy_stI2C);
        I2C_u8WriteByteBlocking(Copy_stI2C, Copy_u8I2C_Address);
        I2C_u8WriteByteBlocking(Copy_stI2C, Copy_u8Byte_Address);
        I2C_voidSendRebeatStartCond(Copy_stI2C);
        I2C_u8WriteByteBlocking(Copy_stI2C, Copy_u8I2C_Address + 1);
        returnedData = I2C_u8ReadByteBlocking(Copy_stI2C, I2C_MASTER_SEND_ACK);
        I2C_voidSendStopCond(Copy_stI2C);
    }
    return returnedData;
}
