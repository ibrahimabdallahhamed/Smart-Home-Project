/***********************Includes*****************/
#include "SPI.h"
/*******************static FUNCTIONS******************/
static void SPI_ModeConfig(spi_t *Copy_stSPI);
static void SPI_SampleConfig(spi_t *Copy_stSPI);
static void SPI_ClockConfig(spi_t *Copy_stSPI);
static void SPI_Interruptconfig(spi_t *Copy_stSPI);

/* ----------------- Data Type Declarations -----------------*/
void (*SPI_INTERRUPT_HANDELER)(void) = NULL;
/*-------------------Functions definitions----------------*/
void SPI_voidSPI_Init(spi_t *Copy_stSPI)
{
    if (NULL != Copy_stSPI)
    {
        /*Disable SPI Module*/
        SPI_MODE_DISABLE();
        /*Configure SPI Mode*/
        SPI_ModeConfig(Copy_stSPI);
/*Configure Spi interrupt */
#if SPI_INTERRUPT_ENABLE_CFG == INTERRUPT_FEATURE_ENABLE
        SPI_Interruptconfig(Copy_stSPI);
#endif
        /*Configure SPI SAMPLE*/
        SPI_SampleConfig(Copy_stSPI);
        /*Configure SPI Clock*/
        SPI_ClockConfig(Copy_stSPI);
        /*ENABLE SPI Module*/
        SPI_MODE_ENABLE();
    }
}
void SPI_voidSPI_Deinit(spi_t *Copy_stSPI)
{
    if (NULL != Copy_stSPI)
    {
        /*Disable SPI Module*/
        SPI_MODE_DISABLE();
    }
}
void SPI_voidWriteData(spi_t *Copy_stSPI, u8 Copy_u8Data)
{
    if (NULL != Copy_stSPI)
    {
        SSPBUF = Copy_u8Data;
        while (!(PIR1bits.SSPIF))
            ; /* Waiting to transmit */
        PIR1bits.SSPIF = 0;
    }
}
u8 SPI_u8ReadData(spi_t *Copy_stSPI)
{
    u8 Local_u8returned = 0;
    if (NULL != Copy_stSPI)
    {
        while (SSPSTATbits.BF == 0)
            ;
        Local_u8returned = SSPBUF;
    }
    return Local_u8returned;
}

u8 SPI_u8ReadDataNON_Blocking(spi_t *Copy_stSPI)
{

    u8 Local_u8returned = 0;
    if (NULL != Copy_stSPI)
    {
        if (SSPSTATbits.BF == 1)
        {

            Local_u8returned = SSPBUF;
        }
    }
    return Local_u8returned;
}

/*********************definition static functions***********/
static void SPI_ModeConfig(spi_t *Copy_stSPI)
{
    if (NULL != Copy_stSPI)
    {
        SPI_MODE_SELECT(Copy_stSPI->spi_mode);
        if ((SPI_MASTER_CLK_DIV_4 == Copy_stSPI->spi_mode) ||
            (SPI_MASTER_CLK_DIV_16 == Copy_stSPI->spi_mode) ||
            (SPI_MASTER_CLK_DIV_64 == Copy_stSPI->spi_mode) ||
            (SPI_MASTER_CLK_DIV_TMR2_DIV_2 == Copy_stSPI->spi_mode))
        {
            GPIO_VoidSetPinDirection(PORT_C, PIN_5, OUTPUT);
            GPIO_VoidSetPinDirection(PORT_C, PIN_4, INPUT);
            GPIO_VoidSetPinDirection(PORT_C, PIN_3, OUTPUT);
        }
        else if (SPI_SLAVE_SS_DISABLE == Copy_stSPI->spi_mode)
        {
            GPIO_VoidSetPinDirection(PORT_C, PIN_5, OUTPUT);
            GPIO_VoidSetPinDirection(PORT_C, PIN_4, INPUT);
            GPIO_VoidSetPinDirection(PORT_C, PIN_3, INPUT);
        }
        else if (SPI_SLAVE_SS_ENABLE == Copy_stSPI->spi_mode)
        {
            GPIO_VoidSetPinDirection(PORT_C, PIN_5, OUTPUT);
            GPIO_VoidSetPinDirection(PORT_C, PIN_4, INPUT);
            GPIO_VoidSetPinDirection(PORT_C, PIN_3, INPUT);
            GPIO_VoidSetPinDirection(PORT_A, PIN_5, INPUT);
        }
    }
}
static void SPI_SampleConfig(spi_t *Copy_stSPI)
{
    if (NULL != Copy_stSPI)
    {
        switch (Copy_stSPI->sample_time)
        {
        case SAMPLED_AT_END:
            SPI_SAMPLE_AT_END();
            break;
        case SAMPLED_AT_MIDDLE:
            SPI_SAMPLE_AT_MIDDLE();
            break;
        }
    }
}

static void SPI_ClockConfig(spi_t *Copy_stSPI)
{
    if (NULL != Copy_stSPI)
    {
        switch (Copy_stSPI->spi_clk)
        {
        case IDLE_TO_ACTIVE:
            SPI_CLK_IDLE_TO_ACTIVE();
            break;
        case ACTIVE_TO_IDLE:
            SPI_CLK_ACTIVE_TO_IDLE();
            break;
        default:
            break;
        }
        switch (Copy_stSPI->spi_clk_priority)
        {
        case HIGH_LEVEL:
            SPI_IDLE_HIGH();
            break;
        case LOW_LEVEL:
            SPI_IDLE_LOW();
            break;

        default:
            break;
        }
    }
}
#if SPI_INTERRUPT_ENABLE_CFG == INTERRUPT_FEATURE_ENABLE
static void SPI_Interruptconfig(spi_t *Copy_stSPI)
{
    if (Copy_stSPI)
    {
        SPI_INTERRUPT_DISABLE();
        SPI_INTERRUPT_HANDELER = Copy_stSPI->SPI_InterruptHandeler;
#if INTERRUPT_PRIORITY_level == INTERRUPT_FEATURE_ENABLE
        switch (Copy_stSPI->priority)
        {
        case HIGH_PRIORITY:
            SPI_HIGH_PRIORITY();
            break;
        case LOW_PRIORITY:
            SPI_LOW_PRIORITY();
            break;
        }
#endif
        SPI_INTERRUPT_ENABLE();
        Interrupt_GLOP_InterruptEnable();
    }
}
#endif
#if SPI_INTERRUPT_ENABLE_CFG == INTERRUPT_FEATURE_ENABLE
void SPI_ISR(void)
{
    SPI_CLEAR_FLAG();
    if (SPI_INTERRUPT_HANDELER)
    {
        SPI_INTERRUPT_HANDELER();
    }
}
#endif
