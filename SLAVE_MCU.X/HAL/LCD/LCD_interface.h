/* 
 * File:   LCD_interface.h
 * Author: dell
 *
 * Created on October 12, 2023, 7:53 PM
 */

#ifndef LCD_INTERFACE_H
#define	LCD_INTERFACE_H
/**********Include files*************/
#include "../../LIB/BITMATH.h"
#include "../../LIB/STDTYPES.h"
#include "../../MCAL/GPIO/GPIO_Interface.h"
/*d********define MACROS**************/
#define ROW1  1
#define ROW2  2
#define ROW3  3
#define ROW4  4
#define LCD_CLEAR           0x01
#define LCD_RETURN_HOME     0x02
#define LCD_INC_SHIFT_OFF   0x06
#define LCD_DEC_SHIFT_OFF   0x04
#define LCD_DisplayON_UnderCursorON_BlinkCursorON 0x0F   
#define LCD_DisplayON_UnderCursorOFF_BlinkCursorON 0x0D  
#define LCD_DisplayON_UnderCursorON_BlinkCursorOFF 0x0E  
#define LCD_DisplayON_UnderCursorOFF_BlinkCursorOFF 0x0C 
#define LCD_8BIT_MODE_2_LINE 0x38
#define LCD_4BIT_MODE_2_LINE 0x28
#define LCD_DisplayOFF 0x08
#define LCD_StartAddressCGRAM 0x40

/***Incert struct to init pin configuration for 8bit and 4bit LCD*/

typedef struct
{
    PinConfig_T LCD_RS;
    PinConfig_T LCD_RW;
    PinConfig_T LCD_EN;
    PinConfig_T DataPin[4];

}LCD_4_BIT_T;
typedef struct
{
    PinConfig_T LCD_RS;
    PinConfig_T LCD_RW;
    PinConfig_T LCD_EN;
    PinConfig_T DataPin[8];

}LCD_8_BIT_T;
/*Declarations of functions for 4bit lcd  */
void LCD4Bit_voidLCD_Init(LCD_4_BIT_T * Copy_stLCD4Bit);
void LCD4Bit_voidSendCommand(LCD_4_BIT_T * Copy_stLCD4Bit,u8 Copy_u8Command);
void LCD4Bit_voidSendChar(LCD_4_BIT_T * Copy_stLCD4Bit,u8 Copy_u8Char);
void LCD4Bit_voidSendChar_Pos(LCD_4_BIT_T * Copy_stLCD4Bit, u8 Copy_u8Row, u8 Copy_u8Column,u8 Copy_u8Char);
void LCD4Bit_voidSendString(LCD_4_BIT_T * Copy_stLCD4Bit,u8 *Copy_Pu8Str);
void LCD4Bit_voidSendString_Pos(LCD_4_BIT_T * Copy_stLCD4Bit, u8 Copy_u8Row, u8 Copy_u8Column,u8 *Copy_Pu8Str);
void LCD4Bit_voidSendNumber(LCD_4_BIT_T *Copy_stLCD4Bit, u16 Copy_u16Number, u8 Copy_u8Row, u8 Copy_u8Column);
void LCD4Bit_voidSendCustomChar(LCD_4_BIT_T * Copy_stLCD4Bit,u8 Copy_u8Row,u8 Copy_u8Coulmn,u8 Copy_Au8Characters [],u8 Copy_u8MemPos);



/*Declarations of functions for 8bit lcd  */
void LCD8Bit_voidLCD_Init(LCD_8_BIT_T * Copy_stLCD8Bit);
void LCD8Bit_voidSendCommand(LCD_8_BIT_T * Copy_stLCD8Bit,u8 Copy_u8Command);
void LCD8Bit_voidSendChar(LCD_8_BIT_T * Copy_stLCD8Bit,u8 Copy_u8Char);
void LCD8Bit_voidSendChar_Pos(LCD_8_BIT_T * Copy_stLCD8Bit, u8 Copy_u8Row, u8 Copy_u8Column,u8 Copy_u8Char);
void LCD8Bit_voidSendString(LCD_8_BIT_T * Copy_stLCD8Bit,u8 *Copy_Pu8Str);
void LCD8Bit_voidSendString_Pos(LCD_4_BIT_T * Copy_stLCD8Bit, u8 Copy_u8Row, u8 Copy_u8Column,u8 *Copy_Pu8Str);
void LCD8Bit_voidSendNumber(LCD_8_BIT_T * Copy_stLCD8Bit,u16 Copy_u16Number);
void LCD8Bit_voidSendCustomChar(LCD_8_BIT_T * Copy_stLCD8Bit,u8 Copy_u8Row,u8 Copy_u8Coulmn,u8 Copy_Au8Characters [],u8 Copy_u8MemPos);


 void LCD_voidSetCursorPos_8Bit(LCD_8_BIT_T *Copy_stLCD8Bit, u8 Copy_u8Row, u8 Copy_u8Column);
 void LCD_voidSetCursorPos_4Bit(LCD_4_BIT_T *Copy_stLCD4Bit, u8 Copy_u8Row, u8 Copy_u8Column);

#endif	/* LCD_INTERFACE_H */

