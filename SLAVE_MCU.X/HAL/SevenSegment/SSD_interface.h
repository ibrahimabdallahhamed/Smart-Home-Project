/*
 * File:   SSD_interface.h
 * Author: dell
 *
 * Created on October 10, 2023, 12:26 AM
 */

#ifndef SSD_INTERFACE_H
#define SSD_INTERFACE_H
#include "../../LIB/BITMATH.h"
#include "../../LIB/STDTYPES.h"
#include "SSD_config.h"
#if TYPE_CONNECTION == WITHOUT_BCD

typedef struct
{
    u8 Port : 4;
    u8 Status : 4;
} SSD_T;

#define ZERO 0b1111110
#define ONE 0b0110000
#define TWO 0b1101101
#define THREE 0b1111001
#define FOUR 0b0110011
#define FIVE 0b1011011
#define SIX 0b1011111
#define SEVEN 0b1110000
#define EIGHT 0b1111111
#define NINE 0b1111011

u8 SSD_Au8Numbers[10] = {ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE};
void SSD_voidSSDInt(SSD_T *Copy_stSSD);
void SSD_voidSSDWriteNumber(SSD_T *Copy_stSSD, u8 Copy_u8SSDNumber);
#endif
#if TYPE_CONNECTION == WITH_BCD
typedef struct
{
    u8 Port;
    u8 Pin ; 
}Pin_Config;

typedef struct
{
   Pin_Config PinConfig[4];
} SSD_T;

void SSD_voidSSD_BCDInt(SSD_T *Copy_stSSD);
void SSD_voidSSD_BCDWriteNumber(SSD_T *Copy_stSSD, u8 Copy_u8SSDNumber);

#endif
#define CommonAnode 2
#define CommonCathode 3
#endif /* SSD_INTERFACE_H */
