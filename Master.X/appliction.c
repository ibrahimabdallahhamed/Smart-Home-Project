#include "Application.h"

void Application_Init(void)
{
    /**
     * initilization LCD
     */
    LCD4Bit_voidLCD_Init(&LCD_1);
    /**
     * initilization KeyPad
     */
    KEYPAD_voidKeyPadInt(&KeyPad_1);
    /**
     * initilization USART
     */
    USART_voidAsynchUsartInit(&uart_TX);
    /**
     * initilization Lock Led
     */
    LED_voidLedInt(&LED_LOCK);
    /*I2C initilization*/
    I2C_voidI2CInit(&i2c_obj);
    /*Analog to digital initilization*/
    ADC_voidADCInit(&ADC);
    /*Disable Watchdog timer*/
    WATCHDOG_DISABLE();
}

/**
 * function that return number from 4 digit from keypad
 * and print each digit on LCD
 */
u16 APP_Get_Number(u8 x, u8 y)
{
    u8 counter_KEY = 0;
    u8 pressed = 0;
    u16 number = 0;
    while (1)
    {

        pressed = KEYPAD_u8KeyPadPressed(&KeyPad_1);
        if (pressed != 0xff)
        {
            if (pressed != 'c' && counter_KEY < 4)
            {
                __delay_ms(200);
                number *= 10;
                number += pressed;
                counter_KEY++;
                LCD4Bit_voidSendNumber(&LCD_1, number, x, y);
            }
            if ('c' == pressed)
            {
                break;
            }
        }
    }
    return number;
}
u8 uart_flag = 0;

/**
 * Function that to send struct of data
 * it work by send  one byte and then the slave answer with flag
 * the master will block until the flag be ok and then send the second byte
 */
u8 ACK_STATUS = I2C_NON_ACK;

void I2C_SendStuct(Data_t *MyData)
{

    u8 SizeOfStruct = 0;
    u8 *ptr = (u8 *)MyData;
    SizeOfStruct = sizeof(*MyData);
    IdleI2C();
    I2C_voidSendStartCond(&i2c_obj);
    IdleI2C();
    ACK_STATUS = I2C_u8WriteByteBlocking(&i2c_obj, 0x30);
    __delay_ms(100);
    for (u8 i = 0; i < SizeOfStruct; i++)
    {
        IdleI2C();
        ACK_STATUS = I2C_u8WriteByteBlocking(&i2c_obj, *(ptr + i));
        __delay_ms(10);
        IdleI2C();
        __delay_ms(20);
    }
    IdleI2C();
    I2C_voidSendStopCond(&i2c_obj);
    IdleI2C();
}

/**
 * this function to set temperature sensor
 */
u8 App_SetTemperature(void)
{
    __delay_ms(200);

    u8 RequiredTemp = 0;
    LCD4Bit_voidSendCommand(&LCD_1, LCD_CLEAR);
    LCD_voidSetCursorPos_4Bit(&LCD_1, 1, 1);
    LCD4Bit_voidSendString_Pos(&LCD_1, 1, 1, "Set Temperature");
    LCD4Bit_voidSendChar_Pos(&LCD_1, 2, 8, 'C');
    RequiredTemp = APP_Get_Number(2, 1);
    LCD4Bit_voidSendCommand(&LCD_1, LCD_CLEAR);
    LCD_voidSetCursorPos_4Bit(&LCD_1, 1, 2);

    LCD4Bit_voidSendString_Pos(&LCD_1, 1, 2, "Loading");
    __delay_ms(500);
    LCD4Bit_voidSendCommand(&LCD_1, LCD_CLEAR);
    LCD_voidSetCursorPos_4Bit(&LCD_1, 1, 3);

    LCD4Bit_voidSendString_Pos(&LCD_1, 1, 2, "Done");
    __delay_ms(500);
    LCD4Bit_voidSendCommand(&LCD_1, LCD_CLEAR);
    return RequiredTemp;
}

/**
 * this function to print the choises at LCD
 */

u8 LCD_ChoisePrint(void)
{
    u8 User_choise = 0;
    LCD4Bit_voidSendCommand(&LCD_1, LCD_CLEAR);
    LCD_voidSetCursorPos_4Bit(&LCD_1, 1, 3);
    LCD4Bit_voidSendString_Pos(&LCD_1, 1, 3, "Choose option ");
    LCD4Bit_voidSendString_Pos(&LCD_1, 2, 1, "1-Temp");
    LCD4Bit_voidSendString_Pos(&LCD_1, 2, 8, "2-Door");
    LCD4Bit_voidSendString_Pos(&LCD_1, 2, 16, "3-TV");
    LCD4Bit_voidSendString_Pos(&LCD_1, 3, 1, "4-Lights");
    User_choise = APP_Get_Number(4, 1);
    LCD4Bit_voidSendNumber(&LCD_1, User_choise, 4, 1);
    return User_choise;
}



void IdleI2C(void)
{
    // Wait until the I2C module is idle
    while (SSPCON2bits.RSEN || SSPCON2bits.PEN || SSPCON2bits.RCEN || SSPCON2bits.ACKEN || SSPSTATbits.BF || SSPSTATbits.R_W)
        ;
}
/*Function to read value from LDR Sensor and convert its values to number of on leds */
void APP_CheckLights(Data_t *MyData)
{
    u16 Adc_result = ADC_u16GetConversion(&ADC, ADC_CHANNEL_AN0);
    if (Adc_result >= 0 && Adc_result < 124)
    {
        MyData->Light = 8;
    }
    else if (Adc_result >= 124 && Adc_result < 248)
    {
        MyData->Light = 7;
    }
    else if (Adc_result >= 248 && Adc_result < 372)
    {
        MyData->Light = 6;
    }
    else if (Adc_result >= 372 && Adc_result < 496)
    {
        MyData->Light = 5;
    }
    else if (Adc_result >= 496 && Adc_result < 620)
    {
        MyData->Light = 4;
    }
    else if (Adc_result >= 620 && Adc_result < 744)
    {
        MyData->Light = 3;
    }
    else if (Adc_result >= 744 && Adc_result < 868)
    {
        MyData->Light = 2;
    }
    else if (Adc_result >= 868 && Adc_result < 992)
    {
        MyData->Light = 1;
    }
    else if (Adc_result >= 992)
    {
        MyData->Light = 0;
    }
}
