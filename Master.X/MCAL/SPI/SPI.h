#ifndef SPI_H
#define SPI_H
/***********************Includes*****************/
#include "../../LIB/pic18f4620.h"
#include "../../LIB/STDTYPES.h"
#include "../../LIB/BITMATH.h"
#include "../GPIO/GPIO_Interface.h"
#include "../Interrupt/Interrupt_interface.h"
/*******************MACRO DECLERATIONS***************/
#define SPI_MASTER_CLK_DIV_4          0
#define SPI_MASTER_CLK_DIV_16         1
#define SPI_MASTER_CLK_DIV_64         2
#define SPI_MASTER_CLK_DIV_TMR2_DIV_2 3
#define SPI_SLAVE_SS_ENABLE           4
#define SPI_SLAVE_SS_DISABLE          5

#define SAMPLED_AT_END                1
#define SAMPLED_AT_MIDDLE             0

#define IDLE_TO_ACTIVE                0
#define ACTIVE_TO_IDLE                1

#define HIGH_LEVEL                    1
#define LOW_LEVEL                     0
#define HIGH_PRIORITY                 1
#define LOW_PRIORITY                  0
/*******************MACRO FUNCTIONS******************/
/*Functions for sample bit*/
#define SPI_SAMPLE_AT_END() (SSPSTATbits.SMP = 1)
#define SPI_SAMPLE_AT_MIDDLE() (SSPSTATbits.SMP = 0)
/*SPI Clock Select bit*/
#define SPI_CLK_ACTIVE_TO_IDLE() (SSPSTATbits.CKE = 1)
#define SPI_CLK_IDLE_TO_ACTIVE() (SSPSTATbits.CKE = 0)
/*Function to enable SPI Mode*/
#define SPI_MODE_ENABLE() (SSPCON1bits.SSPEN = 1)
#define SPI_MODE_DISABLE() (SSPCON1bits.SSPEN = 0)
/*: Clock Polarity Select bit*/
#define SPI_IDLE_HIGH() (SSPCON1bits.CKP = 1)
#define SPI_IDLE_LOW() (SSPCON1bits.CKP = 0)
/*Function to select SPI MODE*/
#define SPI_MODE_SELECT(config) (SSPCON1bits.SSPM = config)
/********SPI Interrupt Functions*******/
#define SPI_INTERRUPT_ENABLE() (PIE1bits.SSPIE=1)
#define SPI_INTERRUPT_DISABLE() (PIE1bits.SSPIE=0)
#define SPI_CLEAR_FLAG() (PIR1bits.SSPIF=0)
#define SPI_HIGH_PRIORITY() (IPR1bits.SSPIP=1)
#define SPI_LOW_PRIORITY() (IPR1bits.SSPIP=0)

/* ----------------- Data Type Declarations -----------------*/

typedef struct {
    u8 spi_mode : 4;
    u8 sample_time : 1;
    u8 spi_clk : 1;
    u8 spi_clk_priority : 1;
#if SPI_INTERRUPT_ENABLE_CFG == INTERRUPT_FEATURE_ENABLE
#if INTERRUPT_PRIORITY_level == INTERRUPT_FEATURE_ENABLE
    u8 priority : 1;
#endif
    void(*SPI_InterruptHandeler)(void);
#endif

} spi_t;

void SPI_voidSPI_Init(spi_t *Copy_stSPI);
void SPI_voidSPI_Deinit(spi_t *Copy_stSPI);
void SPI_voidWriteData(spi_t *Copy_stSPI, u8 Copy_u8Data);
u8 SPI_u8ReadData(spi_t *Copy_stSPI);
u8 SPI_u8ReadDataNON_Blocking(spi_t *Copy_stSPI);
#endif /* SPI_H */
