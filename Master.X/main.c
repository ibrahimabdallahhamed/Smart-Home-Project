/*
 * File:   main.c
 * Author: dell
 *
 * Created on December 8, 2023, 1:50 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "Application.h"

/*
 *
 */

u8 Counter_Try = 0;
u8 ID_STATUS = 0;
u16 KeyPadNumber = 0;
u8 PASSWORD_STATUS = 0;
u8 User = 0;
u8 flag_1 = 0;
Data_t Data = {
    .sensor_TEMP = 0,
    .Set_TEMP = 90,
    .Door = 0,
    .TV = 0
};
u16 Set_Password = 0;

int main(void) {
    /*Initilization Function*/
    Application_Init();
    /*welcome  to smart home LCD*/
    LCD4Bit_voidSendCommand(&LCD_1, LCD_CLEAR);
    LCD_voidSetCursorPos_4Bit(&LCD_1, 1, 3);
    LCD4Bit_voidSendString_Pos(&LCD_1, 1, 3, "Welcome to Smart");
    LCD_voidSetCursorPos_4Bit(&LCD_1, 2, 3);
    LCD4Bit_voidSendString_Pos(&LCD_1, 2, 3, "Home System");
    __delay_ms(1000);
    LCD4Bit_voidSendCommand(&LCD_1, LCD_CLEAR);
    /**
     * check if written in eeprom or not
     * -if not, ask the user to confirm  password
     * --And then ask the user to enter the password
     * ---if password correct ,the user can use the smart home
     * ----if user enter password 3 times wrong the system will lock for 20 sec and then return
     * -if written at eeprom, ask user to enter the password
     * --if password correct ,the user can use the smart home
     * ---if user enter password 3 times wrong the system will lock for 20 sec and then return
     * >>>>>>  i store flag indicate that the eeprom is written before or not at address 0x100
     * >>>>>>if not written before tha value will be 0xff(defualt value)
     * >>>>>>if written before  the value will be 0x00    */

    if (EEPROM_u8Read(0x0100) == 0XFF) // check if written at eeprom or not
    {
        /*ask the user to set the password and then store it in eeprom at adress 0x0200 and 0x0201*/
        LCD_voidSetCursorPos_4Bit(&LCD_1, 1, 1);
        LCD4Bit_voidSendString_Pos(&LCD_1, 1, 1, "Login for first time");
        __delay_ms(1000);
        LCD4Bit_voidSendCommand(&LCD_1, LCD_CLEAR);
        LCD_voidSetCursorPos_4Bit(&LCD_1, 1, 1);
        LCD4Bit_voidSendString_Pos(&LCD_1, 1, 1, "Set password");
        // WATCHDOG_ENABLE();
        KeyPadNumber = APP_Get_Number(2, 1); // Get pasword Nunber form keypad
        //  WATCHDOG_DISABLE();
        Set_Password = KeyPadNumber; // store password in value
        EEPROM_voidWrite(0x0200, Set_Password >> 8); // store the High Byte Password in 0x0200
        EEPROM_voidWrite(0x0201, (u8) Set_Password); // store the Low Byte Pasword in 0x0201
        EEPROM_voidWrite(0x0100, 0x00); // store value 0x00 in the flag which indicate that i written in eeprom
        __delay_ms(1000);
        LCD4Bit_voidSendCommand(&LCD_1, LCD_CLEAR);
    } else if (EEPROM_u8Read(0x0100) == 0X00) {
        Set_Password = EEPROM_u8Read(0x0200) * 256;
        Set_Password += EEPROM_u8Read(0x0201);
    }
    while (1) {
        Counter_Try = 0;
        do {
            LCD_voidSetCursorPos_4Bit(&LCD_1, 1, 1);
            LCD4Bit_voidSendString_Pos(&LCD_1, 1, 1, "Enter password : ");
            KeyPadNumber = APP_Get_Number(2, 1); // Get pasword Nunber form keypad
            if (Set_Password == KeyPadNumber) // check if the password correct or not
            {
                PASSWORD_STATUS = 1;
                LCD_voidSetCursorPos_4Bit(&LCD_1, 3, 1);
                LCD4Bit_voidSendString_Pos(&LCD_1, 3, 1, "Correct password");
                __delay_ms(1000);
                LCD4Bit_voidSendCommand(&LCD_1, LCD_CLEAR);
                break;
            } else {
                LCD_voidSetCursorPos_4Bit(&LCD_1, 3, 1);
                LCD4Bit_voidSendString_Pos(&LCD_1, 3, 1, "Wrong password ");
                LCD4Bit_voidSendString_Pos(&LCD_1, 4, 1, "Try again ");
                Counter_Try++;
                __delay_ms(1000);
                LCD4Bit_voidSendCommand(&LCD_1, LCD_CLEAR);
            }
            if (Counter_Try > 0x02) {
                /***
                 *if enter password 3 times wrong the program will lock for 5 sec
                 *and the lock led turn on for 5 sec
                 */
                LCD4Bit_voidSendCommand(&LCD_1, LCD_CLEAR);
                LCD_voidSetCursorPos_4Bit(&LCD_1, 1, 1);
                LCD4Bit_voidSendString_Pos(&LCD_1, 1, 1, "3 wrong attempts");
                LCD4Bit_voidSendString_Pos(&LCD_1, 2, 1, "Block for 5 sec ");
                LED_voidLedOn(&LED_LOCK);
                __delay_ms(5000);
                LED_voidLedOff(&LED_LOCK);
                LCD4Bit_voidSendCommand(&LCD_1, LCD_CLEAR);
                break;
            }
        } while (Counter_Try <= 2);
        if (OK == PASSWORD_STATUS) {
            break;
        }
    }
    if (OK == PASSWORD_STATUS) {
        /*Enable Watchdog timer*/
        WATCHDOG_ENABLE();
        while (1) {
            WATCHDOG_ENABLE();

            /*Read temperture sensor data and then send the struct data*/
            Data.sensor_TEMP = I2C_u8ReadRegByte(&i2c_obj, 0x9E, 0x00);
            APP_CheckLights(&Data);
            I2C_SendStuct(&Data);
            __delay_ms(200);
            /*print the main screen at LCD to choose the program  */
            User = LCD_ChoisePrint();
            /**
             * if user choose 1 to temperatue option
             * first ask the user to confirm Set Temperature
             * --that if temerature of sensor greater than Set Temoeratue the fan will work
             */
            if (User == 1) {
                WATCHDOG_DISABLE();

                Data.Set_TEMP = App_SetTemperature();
                LCD4Bit_voidSendCommand(&LCD_1, LCD_CLEAR);
                LCD_voidSetCursorPos_4Bit(&LCD_1, 1, 1);
                LCD4Bit_voidSendString_Pos(&LCD_1, 1, 1, "Temp : ");
                LCD4Bit_voidSendString_Pos(&LCD_1, 4, 3, "9_Ret");

                while (1) {

                    Data.sensor_TEMP = I2C_u8ReadRegByte(&i2c_obj, 0x9E, 0x00);

                    APP_CheckLights(&Data);
                    I2C_SendStuct(&Data);
                    LCD4Bit_voidSendString_Pos(&LCD_1, 1, 6, "    ");
                    LCD4Bit_voidSendNumber(&LCD_1, Data.sensor_TEMP, 1, 6);
                    flag_1 = KEYPAD_u8KeyPadPressed(&KeyPad_1);
                    if (flag_1 == 9) {
                        LCD4Bit_voidSendCommand(&LCD_1, LCD_CLEAR);
                        break;
                    }
                }
            }                /**
             * if user choose 2 to Door option
             * that the user has two choise
             * first  : 1-open door
             * Second : 2-close door
             */
            else if (User == 2) {
                WATCHDOG_DISABLE();

                Data.sensor_TEMP = I2C_u8ReadRegByte(&i2c_obj, 0x9E, 0x00);
                APP_CheckLights(&Data);
                I2C_SendStuct(&Data);
                __delay_ms(200);
                LCD4Bit_voidSendCommand(&LCD_1, LCD_CLEAR);
                LCD_voidSetCursorPos_4Bit(&LCD_1, 1, 1);
                LCD4Bit_voidSendString_Pos(&LCD_1, 1, 1, "1-Open Door");
                LCD4Bit_voidSendString_Pos(&LCD_1, 2, 1, "2-Close Door");
                LCD4Bit_voidSendString_Pos(&LCD_1, 3, 1, "9_Ret");
                while (1) {
                    flag_1 = KEYPAD_u8KeyPadPressed(&KeyPad_1);
                    LCD_voidSetCursorPos_4Bit(&LCD_1, 1, 1);
                    Data.sensor_TEMP = I2C_u8ReadRegByte(&i2c_obj, 0x9E, 0x00);
                    APP_CheckLights(&Data);
                    I2C_SendStuct(&Data);

                    if (flag_1 == 1 || flag_1 == 2 || flag_1 == 9) {
                        LCD_voidSetCursorPos_4Bit(&LCD_1, 4, 1);
                        LCD4Bit_voidSendNumber(&LCD_1, flag_1, 4, 1);
                        __delay_ms(200);
                        LCD4Bit_voidSendString_Pos(&LCD_1, 4, 1, "  ");
                        if (flag_1 == 9) {
                            break;
                        } else {
                            Data.Door = flag_1;
                            Data.sensor_TEMP = I2C_u8ReadRegByte(&i2c_obj, 0x9E, 0x00);
                            APP_CheckLights(&Data);
                            I2C_SendStuct(&Data);
                        }
                    }
                }
            }                /**
             * if user choose 3 to TV option
             * that the user has two choise
             * first  : 1-open TV
             * Second : 2-close TV
             */
            else if (User == 3) {
                WATCHDOG_DISABLE();

                Data.sensor_TEMP = I2C_u8ReadRegByte(&i2c_obj, 0x9E, 0x00);
                APP_CheckLights(&Data);

                I2C_SendStuct(&Data);
                __delay_ms(200);
                LCD4Bit_voidSendCommand(&LCD_1, LCD_CLEAR);
                LCD_voidSetCursorPos_4Bit(&LCD_1, 1, 1);
                LCD4Bit_voidSendString_Pos(&LCD_1, 1, 1, "1-Open TV");
                LCD4Bit_voidSendString_Pos(&LCD_1, 2, 1, "2-Close TV");
                LCD4Bit_voidSendString_Pos(&LCD_1, 3, 1, "9_Ret");
                while (1) {
                    Data.sensor_TEMP = I2C_u8ReadRegByte(&i2c_obj, 0x9E, 0x00);

                    I2C_SendStuct(&Data);
                    flag_1 = KEYPAD_u8KeyPadPressed(&KeyPad_1);
                    LCD_voidSetCursorPos_4Bit(&LCD_1, 1, 1);

                    if (flag_1 == 1 || flag_1 == 2 || flag_1 == 9) {
                        LCD_voidSetCursorPos_4Bit(&LCD_1, 4, 1);
                        LCD4Bit_voidSendNumber(&LCD_1, flag_1, 4, 1);
                        __delay_ms(200);
                        LCD4Bit_voidSendString_Pos(&LCD_1, 4, 1, "  ");
                        if (flag_1 == 9) {
                            break;
                        } else {
                            Data.TV = flag_1;
                            Data.sensor_TEMP = I2C_u8ReadRegByte(&i2c_obj, 0x9E, 0x00);
                            APP_CheckLights(&Data);

                            I2C_SendStuct(&Data);
                        }
                    }
                }
            }                /**
             * if user choose 4 to LIGHTS option
             * that the user has 2 option automatic by ldr sensor or manual
             * if enter valid number
             */
            else if (User == 4) {
                WATCHDOG_DISABLE();

                while (1) {
                    Data.sensor_TEMP = I2C_u8ReadRegByte(&i2c_obj, 0x9E, 0x00);

                    I2C_SendStuct(&Data);
                    __delay_ms(200);
                    LCD4Bit_voidSendCommand(&LCD_1, LCD_CLEAR);
                    LCD_voidSetCursorPos_4Bit(&LCD_1, 1, 1);
                    LCD4Bit_voidSendString_Pos(&LCD_1, 1, 1, "Choose operation");
                    LCD_voidSetCursorPos_4Bit(&LCD_1, 1, 1);
                    LCD4Bit_voidSendString_Pos(&LCD_1, 2, 1, "1-Automatic");
                    LCD4Bit_voidSendString_Pos(&LCD_1, 3, 1, "2-Manual");
                    LCD4Bit_voidSendString_Pos(&LCD_1, 4, 15, "9-Ret");
                    Data.sensor_TEMP = I2C_u8ReadRegByte(&i2c_obj, 0x9E, 0x00);
                    I2C_SendStuct(&Data);
                    flag_1 = KEYPAD_u8KeyPadPressed(&KeyPad_1);
                    if (0xff != flag_1) {
                        if (1 == flag_1) {
                            LCD4Bit_voidSendCommand(&LCD_1, LCD_CLEAR);
                            LCD_voidSetCursorPos_4Bit(&LCD_1, 1, 1);
                            LCD4Bit_voidSendString_Pos(&LCD_1, 2, 1, "Looding");
                            __delay_ms(500);

                            Data.Light_Status = 1;
                            APP_CheckLights(&Data);
                        } else if (2 == flag_1) {
                            LCD4Bit_voidSendCommand(&LCD_1, LCD_CLEAR);
                            LCD_voidSetCursorPos_4Bit(&LCD_1, 1, 1);
                            LCD4Bit_voidSendString_Pos(&LCD_1, 2, 1, "Looding");
                            __delay_ms(500);
                            Data.Light_Status = 2;
                            Data.Light = 15;
                        } else if (9 == flag_1) {
                            break;
                        } else {
                            LCD4Bit_voidSendCommand(&LCD_1, LCD_CLEAR);
                            LCD_voidSetCursorPos_4Bit(&LCD_1, 1, 1);
                            LCD4Bit_voidSendString_Pos(&LCD_1, 2, 1, "Invalid Number");
                            __delay_ms(1000);
                        }
                    }
                    APP_CheckLights(&Data);

                    LCD_voidSetCursorPos_4Bit(&LCD_1, 1, 1);
                }
            } else {
                LCD_voidSetCursorPos_4Bit(&LCD_1, 4, 1);
                LCD4Bit_voidSendString_Pos(&LCD_1, 4, 1, "Wrong Id");
                __delay_ms(500);
                LCD4Bit_voidSendCommand(&LCD_1, LCD_CLEAR);
                WATCHDOG_DISABLE();

            }
        }
        WATCHDOG_DISABLE();
    }

    return (EXIT_SUCCESS);
}
