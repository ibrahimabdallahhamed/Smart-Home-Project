#include "../../LIB/BITMATH.h"
#include "../../LIB/STDTYPES.h"
#include "../../LIB/device_config.h"
#include "../../MCAL/GPIO/GPIO_Interface.h"
#include "LCD_interface.h"
#include <string.h>
#include <stdio.h>

/*declarations of static Helper functions */
static void LCD_voidSend4bit(LCD_4_BIT_T *Copy_stLCD8Bit, u8 Copy_u8Command_Data);
static void LCD_voidSendEnable_4Bit(LCD_4_BIT_T *Copy_stLCD4Bit);
static void LCD_voidSendEnable_8Bit(LCD_8_BIT_T *Copy_stLCD8Bit);

/*function to init 4bit LCD*/
void LCD4Bit_voidLCD_Init(LCD_4_BIT_T *Copy_stLCD4Bit) {
    /*SET pin of lcd as OUTPUT*/
    GPIO_VoidSetPinDirection(Copy_stLCD4Bit->LCD_RW.Port, Copy_stLCD4Bit->LCD_RW.Pin, OUTPUT);
    GPIO_VoidSetPinDirection(Copy_stLCD4Bit->LCD_RS.Port, Copy_stLCD4Bit->LCD_RS.Pin, OUTPUT);
    GPIO_VoidSetPinDirection(Copy_stLCD4Bit->LCD_EN.Port, Copy_stLCD4Bit->LCD_EN.Pin, OUTPUT);

    GPIO_VoidSetPinDirection(Copy_stLCD4Bit->DataPin[0].Port, Copy_stLCD4Bit->DataPin[0].Pin, OUTPUT);
    GPIO_VoidSetPinDirection(Copy_stLCD4Bit->DataPin[1].Port, Copy_stLCD4Bit->DataPin[1].Pin, OUTPUT);
    GPIO_VoidSetPinDirection(Copy_stLCD4Bit->DataPin[2].Port, Copy_stLCD4Bit->DataPin[2].Pin, OUTPUT);
    GPIO_VoidSetPinDirection(Copy_stLCD4Bit->DataPin[3].Port, Copy_stLCD4Bit->DataPin[3].Pin, OUTPUT);

    /*Init 4bit interface*/
    __delay_ms(20);
    LCD4Bit_voidSendCommand(Copy_stLCD4Bit, LCD_8BIT_MODE_2_LINE);
    __delay_ms(10);
    LCD4Bit_voidSendCommand(Copy_stLCD4Bit, LCD_8BIT_MODE_2_LINE);
    __delay_us(150);
    LCD4Bit_voidSendCommand(Copy_stLCD4Bit, LCD_8BIT_MODE_2_LINE);
    LCD4Bit_voidSendCommand(Copy_stLCD4Bit, LCD_CLEAR);
    LCD4Bit_voidSendCommand(Copy_stLCD4Bit, LCD_RETURN_HOME);
    LCD4Bit_voidSendCommand(Copy_stLCD4Bit, LCD_INC_SHIFT_OFF);
    LCD4Bit_voidSendCommand(Copy_stLCD4Bit, LCD_DisplayON_UnderCursorOFF_BlinkCursorOFF);
    LCD4Bit_voidSendCommand(Copy_stLCD4Bit, LCD_4BIT_MODE_2_LINE);
    LCD4Bit_voidSendCommand(Copy_stLCD4Bit, 0x80);
}

/*Function to send command for 4 bit lcd */
void LCD4Bit_voidSendCommand(LCD_4_BIT_T *Copy_stLCD4Bit, u8 Copy_u8Command) {
    GPIO_VoidSetPinMode(Copy_stLCD4Bit->LCD_RS.Port, Copy_stLCD4Bit->LCD_RS.Pin, LOW);
    LCD_voidSend4bit(Copy_stLCD4Bit, Copy_u8Command >> 4);
    LCD_voidSendEnable_4Bit(Copy_stLCD4Bit);
    LCD_voidSend4bit(Copy_stLCD4Bit, Copy_u8Command);
    LCD_voidSendEnable_4Bit(Copy_stLCD4Bit);
}

/*Function to send charcter  for 4 bit lcd */
void LCD4Bit_voidSendChar(LCD_4_BIT_T *Copy_stLCD4Bit, u8 Copy_u8Char) {
    GPIO_VoidSetPinMode(Copy_stLCD4Bit->LCD_RS.Port, Copy_stLCD4Bit->LCD_RS.Pin, HIGH);
    LCD_voidSend4bit(Copy_stLCD4Bit, Copy_u8Char >> 4);
    LCD_voidSendEnable_4Bit(Copy_stLCD4Bit);
    LCD_voidSend4bit(Copy_stLCD4Bit, Copy_u8Char);
    LCD_voidSendEnable_4Bit(Copy_stLCD4Bit);
}

/*Function to send charcter  for 4 bit lcd at position */
void LCD4Bit_voidSendChar_Pos(LCD_4_BIT_T *Copy_stLCD4Bit, u8 Copy_u8Row, u8 Copy_u8Column, u8 Copy_u8Char) {
    LCD_voidSetCursorPos_4Bit(Copy_stLCD4Bit, Copy_u8Row, Copy_u8Column);
    LCD4Bit_voidSendChar(Copy_stLCD4Bit, Copy_u8Char);
}

/*Function to send string for 4 bit lcd */
void LCD4Bit_voidSendString(LCD_4_BIT_T *Copy_stLCD4Bit, u8 *Copy_Pu8Str) {
    while (NULL != *(Copy_Pu8Str)) {
        LCD4Bit_voidSendChar(Copy_stLCD4Bit, *(Copy_Pu8Str));
        Copy_Pu8Str++;
    }
}

/*Function to send string for 4 bit lcd at position*/
void LCD4Bit_voidSendString_Pos(LCD_4_BIT_T *Copy_stLCD4Bit, u8 Copy_u8Row, u8 Copy_u8Column, u8 *Copy_Pu8Str) {
    LCD_voidSetCursorPos_4Bit(Copy_stLCD4Bit, Copy_u8Row, Copy_u8Column);
    LCD4Bit_voidSendString(Copy_stLCD4Bit, Copy_Pu8Str);
}

/*Function to init 8bit LCD*/
void LCD8Bit_voidLCD_Init(LCD_8_BIT_T *Copy_stLCD8Bit) {
    /*set pin of LCD as OUTPUT*/
    GPIO_VoidSetPinDirection(Copy_stLCD8Bit->LCD_RW.Port, Copy_stLCD8Bit->LCD_RW.Pin, OUTPUT);
    GPIO_VoidSetPinDirection(Copy_stLCD8Bit->LCD_RS.Port, Copy_stLCD8Bit->LCD_RS.Pin, OUTPUT);
    GPIO_VoidSetPinDirection(Copy_stLCD8Bit->LCD_EN.Port, Copy_stLCD8Bit->LCD_EN.Pin, OUTPUT);
    for (u8 i = 0; i < 8; i++) {
        GPIO_VoidSetPinDirection(Copy_stLCD8Bit->DataPin[i].Port, Copy_stLCD8Bit->DataPin[i].Pin, OUTPUT);
    }
    /*Init 8bit interface*/
    __delay_ms(15);
    LCD8Bit_voidSendCommand(Copy_stLCD8Bit, LCD_8BIT_MODE_2_LINE);
    __delay_ms(10);
    LCD8Bit_voidSendCommand(Copy_stLCD8Bit, LCD_8BIT_MODE_2_LINE);
    __delay_us(150);
    LCD8Bit_voidSendCommand(Copy_stLCD8Bit, LCD_8BIT_MODE_2_LINE);
    LCD8Bit_voidSendCommand(Copy_stLCD8Bit, LCD_DisplayOFF);
    LCD8Bit_voidSendCommand(Copy_stLCD8Bit, LCD_CLEAR);
    LCD8Bit_voidSendCommand(Copy_stLCD8Bit, LCD_RETURN_HOME);
    LCD8Bit_voidSendCommand(Copy_stLCD8Bit, LCD_INC_SHIFT_OFF);
    LCD8Bit_voidSendCommand(Copy_stLCD8Bit, LCD_DisplayON_UnderCursorOFF_BlinkCursorON);
    LCD8Bit_voidSendCommand(Copy_stLCD8Bit, LCD_8BIT_MODE_2_LINE);
}

/*function to send command to 8bit LCD*/
void LCD8Bit_voidSendCommand(LCD_8_BIT_T *Copy_stLCD8Bit, u8 Copy_u8Command) {
    GPIO_VoidSetPinMode(Copy_stLCD8Bit->LCD_RS.Port, Copy_stLCD8Bit->LCD_RS.Pin, LOW);
    for (u8 i = 0; i < 8; i++) {
        GPIO_VoidSetPinMode(Copy_stLCD8Bit->DataPin[i].Port, Copy_stLCD8Bit->DataPin[i].Pin, (Copy_u8Command >> i) & 0x01);
    }
    LCD_voidSendEnable_8Bit(Copy_stLCD8Bit);
}

/*function to send Character to 8bit LCD*/
void LCD8Bit_voidSendChar(LCD_8_BIT_T *Copy_stLCD8Bit, u8 Copy_u8Char) {

    GPIO_VoidSetPinMode(Copy_stLCD8Bit->LCD_RS.Port, Copy_stLCD8Bit->LCD_RS.Pin, HIGH);
    for (u8 i = 0; i < 8; i++) {
        GPIO_VoidSetPinMode(Copy_stLCD8Bit->DataPin[i].Port, Copy_stLCD8Bit->DataPin[i].Pin, (Copy_u8Char >> i) & 0x01);
    }
    LCD_voidSendEnable_8Bit(Copy_stLCD8Bit);
}

/*function to send Character to 8bit LCD at position */
void LCD8Bit_voidSendChar_Pos(LCD_8_BIT_T *Copy_stLCD8Bit, u8 Copy_u8Row, u8 Copy_u8Column, u8 Copy_u8Char) {
    LCD_voidSetCursorPos_8Bit(Copy_stLCD8Bit, Copy_u8Row, Copy_u8Column);
    LCD8Bit_voidSendChar(Copy_stLCD8Bit, Copy_u8Char);
}

/*function to send string to 8bit LCD*/
void LCD8Bit_voidSendString(LCD_8_BIT_T *Copy_stLCD8Bit, u8 *Copy_Pu8Str) {
    while (NULL != *(Copy_Pu8Str)) {
        LCD8Bit_voidSendChar(Copy_stLCD8Bit, *(Copy_Pu8Str));
        Copy_Pu8Str++;
    }
}

/*function to send string to 8bit LCD at position*/
void LCD8Bit_voidSendString_Pos(LCD_4_BIT_T *Copy_stLCD8Bit, u8 Copy_u8Row, u8 Copy_u8Column, u8 *Copy_Pu8Str) {
    LCD_voidSetCursorPos_8Bit(Copy_stLCD8Bit, Copy_u8Row, Copy_u8Column);
    LCD8Bit_voidSendString(Copy_stLCD8Bit, Copy_Pu8Str);
}

static void LCD_voidSend4bit(LCD_4_BIT_T *Copy_stLCD4Bit, u8 Copy_u8Command_Data) {
    GPIO_VoidSetPinMode(Copy_stLCD4Bit->DataPin[0].Port, Copy_stLCD4Bit->DataPin[0].Pin, (Copy_u8Command_Data >> 0) & (u8) 0x01);
    GPIO_VoidSetPinMode(Copy_stLCD4Bit->DataPin[1].Port, Copy_stLCD4Bit->DataPin[1].Pin, (Copy_u8Command_Data >> 1) & (u8) 0x01);
    GPIO_VoidSetPinMode(Copy_stLCD4Bit->DataPin[2].Port, Copy_stLCD4Bit->DataPin[2].Pin, (Copy_u8Command_Data >> 2) & (u8) 0x01);
    GPIO_VoidSetPinMode(Copy_stLCD4Bit->DataPin[3].Port, Copy_stLCD4Bit->DataPin[3].Pin, (Copy_u8Command_Data >> 3) & (u8) 0x01);
}

static void LCD_voidSendEnable_4Bit(LCD_4_BIT_T *Copy_stLCD4Bit) {
    GPIO_VoidSetPinMode(Copy_stLCD4Bit->LCD_EN.Port, Copy_stLCD4Bit->LCD_EN.Pin, HIGH);
    __delay_us(10);
    GPIO_VoidSetPinMode(Copy_stLCD4Bit->LCD_EN.Port, Copy_stLCD4Bit->LCD_EN.Pin, LOW);
    __delay_us(10);
}

static void LCD_voidSendEnable_8Bit(LCD_8_BIT_T *Copy_stLCD8Bit) {
    GPIO_VoidSetPinMode(Copy_stLCD8Bit->LCD_EN.Port, Copy_stLCD8Bit->LCD_EN.Pin, HIGH);
    __delay_us(10);
    GPIO_VoidSetPinMode(Copy_stLCD8Bit->LCD_EN.Port, Copy_stLCD8Bit->LCD_EN.Pin, LOW);
}

void LCD_voidSetCursorPos_8Bit(LCD_8_BIT_T *Copy_stLCD8Bit, u8 Copy_u8Row, u8 Copy_u8Column) {
    Copy_u8Column--;
    switch (Copy_u8Row) {
        case ROW1:
            LCD8Bit_voidSendCommand(Copy_stLCD8Bit, (0x80 + Copy_u8Column));
            break;
        case ROW2:
            LCD8Bit_voidSendCommand(Copy_stLCD8Bit, (0xc0 + Copy_u8Column));
            break;
        case ROW3:
            LCD8Bit_voidSendCommand(Copy_stLCD8Bit, (0x94 + Copy_u8Column));
            break;
        case ROW4:
            LCD8Bit_voidSendCommand(Copy_stLCD8Bit, (0xd4 + Copy_u8Column));
            break;

        default:
            break;
    }
}

void LCD_voidSetCursorPos_4Bit(LCD_4_BIT_T *Copy_stLCD4Bit, u8 Copy_u8Row, u8 Copy_u8Column) {
    Copy_u8Column--;
    switch (Copy_u8Row) {
        case ROW1:
            LCD4Bit_voidSendCommand(Copy_stLCD4Bit, (0x80 + Copy_u8Column));
            break;
        case ROW2:
            LCD4Bit_voidSendCommand(Copy_stLCD4Bit, (0xc0 + Copy_u8Column));
            break;
        case ROW3:
            LCD4Bit_voidSendCommand(Copy_stLCD4Bit, (0x94 + Copy_u8Column));
            break;
        case ROW4:
            LCD4Bit_voidSendCommand(Copy_stLCD4Bit, (0xd4 + Copy_u8Column));
            break;

        default:
            break;
    }
}

void LCD4Bit_voidSendNumber(LCD_4_BIT_T *Copy_stLCD4Bit, u16 Copy_u16Number, u8 Copy_u8Row, u8 Copy_u8Column) {
    u8 Number[6] = {'\0'};
    u8 Number2[6] = {'\0'};
    u8 i = 0;
    memset((s8 *) Number, ' ', 5);
    Number[5] = '\0';
    sprintf((s8 *) Number2, "%i", Copy_u16Number);
    while (Number2[i] != '\0') {
        Number[i] = Number2[i];
        i++;
    }
    LCD4Bit_voidSendString_Pos(Copy_stLCD4Bit, Copy_u8Row, Copy_u8Column, Number);
    /*
u8 i = 0;
if (Copy_u16Number == 0) {
    LCD4Bit_voidSendChar(Copy_stLCD4Bit, '0');
} else {
    while (0 != Copy_u16Number) {
        Number[i] = Copy_u16Number % 10;
        Copy_u16Number /= 10;
        i++;
    }
    for (s8 j = i - 1; j >= 0; j--) {
        LCD4Bit_voidSendChar(Copy_stLCD4Bit, Number[j] + '0');
    }
}*/
}

void LCD8Bit_voidSendNumber(LCD_8_BIT_T *Copy_stLCD8Bit, u16 Copy_u16Number) {
    u8 Number[10] = {0};
    u8 i = 0;
    if (Copy_u16Number == 0) {
        LCD8Bit_voidSendChar(Copy_stLCD8Bit, '0');
    } else {

        while (0 != Copy_u16Number) {
            Number[i] = Copy_u16Number % 10;
            Copy_u16Number /= 10;
            i++;
        }
        for (s8 j = i - 1; j >= 0; j--) {
            LCD8Bit_voidSendChar(Copy_stLCD8Bit, Number[j] + '0');
        }
    }
}

void LCD8Bit_voidSendCustomChar(LCD_8_BIT_T *Copy_stLCD8Bit, u8 Copy_u8Row, u8 Copy_u8Coulmn, u8 Copy_Au8Characters[], u8 Copy_u8MemPos) {
    LCD8Bit_voidSendCommand(Copy_stLCD8Bit, (LCD_StartAddressCGRAM + (Copy_u8MemPos)*40));
    for (u8 i = 0; i <= 7; i++) {
        LCD8Bit_voidSendChar(Copy_stLCD8Bit, Copy_Au8Characters[i]);
    }
    LCD8Bit_voidSendChar_Pos(Copy_stLCD8Bit, Copy_u8Row, Copy_u8Coulmn, Copy_u8MemPos);
}

void LCD4Bit_voidSendCustomChar(LCD_4_BIT_T *Copy_stLCD4Bit, u8 Copy_u8Row, u8 Copy_u8Coulmn, u8 Copy_Au8Characters[], u8 Copy_u8MemPos) {
    LCD4Bit_voidSendCommand(Copy_stLCD4Bit, (LCD_StartAddressCGRAM + (Copy_u8MemPos)*40));
    for (u8 i = 0; i <= 7; i++) {
        LCD4Bit_voidSendChar(Copy_stLCD4Bit, Copy_Au8Characters[i]);
    }
    LCD4Bit_voidSendChar_Pos(Copy_stLCD4Bit, Copy_u8Row, Copy_u8Coulmn, Copy_u8MemPos);
}
