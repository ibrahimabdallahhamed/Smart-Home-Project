/*
 * File:   Application.h
 * Author: dell
 *
 * Created on December 8, 2023, 1:51 PM
 */

#ifndef APPLICATION_H
#define APPLICATION_H
/***********************Includes*****************/
#include "LIB/pic18f4620.h"
#include "LIB/device_config.h"
#include "LIB/STDTYPES.h"
#include "LIB/BITMATH.h"
#include "MCAL/GPIO/GPIO_Interface.h"
#include "HAL/KeyPad/KEYPAD_interface.h"
#include "HAL/LCD/LCD_interface.h"
#include "MCAL/USART/USART.h"
#include "MCAL/EEPROM/EEPROM.h"
#include "HAL/LED/LED_interface.h"
#include "MCAL/I2C/I2C.h"
#include "MCAL/ADC/ADC.h"
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/
/*******************MACRO DECLERATIONS***************/
#define OK 1
#define N_OK 0

#define ID 0
#define PASSWORD 0
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/
/******************Macro functions**********************/
#define WATCHDOG_CONFEIG_FREQUANCY() (OSCCONbits.IRCF = 0)
#define WATCHDOG_ENABLE() {(WDTCONbits.SWDTEN = 1); \
                            CLRWDT();\
                           WATCHDOG_CONFEIG_FREQUANCY();}
#define WATCHDOG_DISABLE() (WDTCONbits.SWDTEN = 0)
/* ----------------- Data Type Declarations -----------------*/
/**
 * creat object from LCD_4_BIT
 */

LCD_4_BIT_T LCD_1 = {
    .LCD_RS.Port = PORT_D,
    .LCD_RS.Pin = PIN_0,
    .LCD_RW.Port = PORT_D,
    .LCD_RW.Pin = PIN_1,
    .LCD_EN.Port = PORT_D,
    .LCD_EN.Pin = PIN_2,
    .DataPin[0].Port = PORT_D,
    .DataPin[0].Pin = PIN_4,
    .DataPin[1].Port = PORT_D,
    .DataPin[1].Pin = PIN_5,
    .DataPin[2].Port = PORT_D,
    .DataPin[2].Pin = PIN_6,
    .DataPin[3].Port = PORT_D,
    .DataPin[3].Pin = PIN_7

};
/**
 * creat object from KeyPad_T
 */
KeyPad_T KeyPad_1 = {
    .RowPinConfig[0].Port = PORT_B,
    .RowPinConfig[0].Pin = PIN_0,
    .RowPinConfig[1].Port = PORT_B,
    .RowPinConfig[1].Pin = PIN_1,
    .RowPinConfig[2].Port = PORT_B,
    .RowPinConfig[2].Pin = PIN_2,
    .RowPinConfig[3].Port = PORT_B,
    .RowPinConfig[3].Pin = PIN_3,
    .CoulmPinConfig[0].Port = PORT_B,
    .CoulmPinConfig[0].Pin = PIN_4,
    .CoulmPinConfig[1].Port = PORT_B,
    .CoulmPinConfig[1].Pin = PIN_5,
    .CoulmPinConfig[2].Port = PORT_B,
    .CoulmPinConfig[2].Pin = PIN_6,
    .CoulmPinConfig[3].Port = PORT_B,
    .CoulmPinConfig[3].Pin = PIN_7};
/**
 * initilization USART
 */
usart_t uart_TX = {
    .BaudRate = 9600,
    .BaudRate_CFG = USART_ASYNCHRONOUS_BAUD_RATE_LOW_SPEED,
    .transmit.usart_tx_9bit_enable = USART_ASYNCHRONOUS_TX_9BIT_DISABLE,
    .transmit.usart_tx_enable = USART_ASYNCHRONOUS_TX_ENABLE,
    .receive.usart_rx_9bit_enable = USART_ASYNCHRONOUS_RX_9BIT_DISABLE,
    .receive.usart_rx_enable = USART_ASYNCHRONOUS_RX_ENABLE};

/**
 *creat object from LED_T
 */
LED_T LED_LOCK = {
    .Port = PORT_C,
    .Pin = PIN_0,
    .Stauts = CommonAnode

};
/**
 * Create struct that used to store of smart home project
 */
typedef struct
{
    volatile u8 sensor_TEMP;
    u8 Set_TEMP;
    u8 Door : 2;
    u8 TV : 2;
    u8 Light_Status : 2;
    u8 Light;
} Data_t;
I2C_t i2c_obj =
    {
        .master_clk = 100000,
        .i2c_cfg.i2c_mode = I2C_MASTER,
        .i2c_cfg.i2c_general_call = GENERAL_CALL_DISABLE,
        .i2c_cfg.i2c_mode_cfg = I2C_MASTER_DEFIENED_CLOCK,
        .i2c_cfg.i2c_slew_rate = SLEW_RATE_DISABLE,
        .i2c_cfg.i2c_smBUS = SMBUS_DISABLE};
ADC_congig_t ADC = {
    .AcquisitionTime = ADC_AcquisitionTime_12_TAD,
    .channel = ADC_CHANNEL_AN0,
    .clock = ADC_converionClock_8,
    .ResultFormat = ADC_RightJustified,
    .VoltageRef = ADC_Disable_VoltageRef};
/*-----------------------Function Decleration----------------*/
void Application_Init(void);
u16 APP_Get_Number(u8 x, u8 y);
void I2C_SendStuct(Data_t *MyData);
u8 App_SetTemperature(void);
u8 LCD_ChoisePrint(void);
void IdleI2C(void);
void APP_CheckLights(Data_t *MyData);
#endif /* APPLICATION_H */
