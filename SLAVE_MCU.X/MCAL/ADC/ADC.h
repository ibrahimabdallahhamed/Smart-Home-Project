/* 
 * File:   ADC.h
 * Author: dell
 *
 * Created on October 27, 2023, 8:21 PM
 */

#ifndef ADC_H
#define	ADC_H

/****************Include *******************/
#include "ADC_config.h"
/***************Macro declarations ******************/
#define ADC_AN0_FUNCTIONALITY     0x0E
#define ADC_AN1_FUNCTIONALITY     0x0D
#define ADC_AN2_FUNCTIONALITY     0x0C
#define ADC_AN3_FUNCTIONALITY     0x0B
#define ADC_AN4_FUNCTIONALITY     0x0A
#define ADC_AN5_FUNCTIONALITY     0x09
#define ADC_AN6_FUNCTIONALITY     0x08
#define ADC_AN7_FUNCTIONALITY     0x07
#define ADC_AN8_FUNCTIONALITY     0x06
#define ADC_AN9_FUNCTIONALITY     0x05
#define ADC_AN10_FUNCTIONALITY    0x04
#define ADC_AN11_FUNCTIONALITY    0x03
#define ADC_AN12_FUNCTIONALITY    0x02
#define ADC_ALL_ANALOG_FUNCTIONALITY  0x00
#define ADC_ALL_DIGITAL_FUNCTIONALITY  0x0F
#define ADC_RightJustified  0x01
#define ADC_LeftJustified  0x00
#define ADC_Disable_VoltageRef  0x00
#define ADC_Enable_VoltageRef  0x01
/**********macro function *************/
#define ADC_ConversionStatusBit()  (ADCON0bits.GO_nDONE)
#define ADC_StatrtConversion()      (ADCON0bits.GO_nDONE=1)
#define ADC_Enable()              (ADCON0bits.ADON=1)
#define ADC_Disable()             (ADCON0bits.ADON=0)
#define ADC_EnableVoltageRef()    do{ADCON1bits.VCFG1=1;\
                                     ADCON1bits.VCFG0=1;\
                                    }while(0)
#define ADC_DisableVoltageRef()    do{ADCON1bits.VCFG1=0;\
                                     ADCON1bits.VCFG0=0;\
                                    }while(0)
#define ADC_ConversionResult_RightJustified() (ADCON2bits.ADFM=1)
#define ADC_ConversionResult_LeftJustified() (ADCON2bits.ADFM=0)
#define ADC_AnalogPortConfig(config)          (ADCON1bits.PCFG=config)
/*ADC Interrupt*/
#if ADC_INTERRUPT_ENABLE ==INTERRUPT_FEATURE_ENABLE
#define ADC_EnableInterrupt()                  (PIE1bits.ADIE=1)
#define ADC_DisableInterrupt()                 (PIE1bits.ADIE=0)
#define ADC_ClearFlag()                        (PIR1bits.ADIF=0)
#if   INTERRUPT_PRIORITY_level ==INTERRUPT_FEATURE_ENABLE
#define ADC_HighPriority()                      (IPR1bits.ADIP=1)
#define ADC_LowPriority()                       (IPR1bits.ADIP=0)
#endif
#endif

/***************Data type declaration****** */
typedef enum {
    ADC_CHANNEL_AN0 = 0,
    ADC_CHANNEL_AN1,
    ADC_CHANNEL_AN2,
    ADC_CHANNEL_AN3,
    ADC_CHANNEL_AN4,
    ADC_CHANNEL_AN5,
    ADC_CHANNEL_AN6,
    ADC_CHANNEL_AN7,
    ADC_CHANNEL_AN8,
    ADC_CHANNEL_AN9,
    ADC_CHANNEL_AN10,
    ADC_CHANNEL_AN11,
    ADC_CHANNEL_AN12,
} ADC_Channel_Select_t;

typedef enum {
    ADC_AcquisitionTime_0_TAD = 0,
    ADC_AcquisitionTime_2_TAD,
    ADC_AcquisitionTime_4_TAD,
    ADC_AcquisitionTime_8_TAD,
    ADC_AcquisitionTime_12_TAD,
    ADC_AcquisitionTime_16_TAD,
    ADC_AcquisitionTime_20_TAD,
} ADC_AcquisitionTime_t;

typedef enum {
    ADC_converionClock_2 = 0,
    ADC_converionClock_8,
    ADC_converionClock_32,
    ADC_converionClock_FRC,
    ADC_converionClock_4,
    ADC_converionClock_16,
    ADC_converionClock_64,
} ADC_conversionClock_t;

typedef struct {
#if ADC_INTERRUPT_ENABLE ==INTERRUPT_FEATURE_ENABLE
    void (*ADC_InterruPtHandeler)(void);
#if   INTERRUPT_PRIORITY_level ==INTERRUPT_FEATURE_ENABLE
    InterruptPriority_T priority;
#endif
#endif
    ADC_conversionClock_t clock;
    ADC_AcquisitionTime_t AcquisitionTime;
    ADC_Channel_Select_t channel;
    u8 VoltageRef : 1;
    u8 ResultFormat : 1;
    u8 Reserved : 6;

} ADC_congig_t;


void ADC_voidADCInit(ADC_congig_t *Copy_stADC);
void ADC_voidADCDeinit(ADC_congig_t *Copy_stADC);
void ADC_voidSelectChannel(ADC_congig_t *Copy_stADC, u8 Copy_u8Channel);
void ADC_voidStatrtConversion(ADC_congig_t *Copy_stADC);
u8 ADC_u8IsConversionDone(ADC_congig_t *Copy_stADC);
u16 ADC_u16GetConversionResult(ADC_congig_t *Copy_stADC);
u16 ADC_u16GetConversion(ADC_congig_t *Copy_stADC, u8 channel);
#endif	/* ADC_H */

