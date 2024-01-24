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
#include "HAL/SERVO_MOTOR/SERVO.h"
#include "MCAL/USART/USART.h"
#include "MCAL/ADC/ADC.h"
#include "HAL/LED/LED_interface.h"
#include "MCAL/Interrupt/Interrupt_interface.h"
#include "MCAL/I2C/I2C.h"
/*******************MACRO DECLERATIONS***************/
/*******************MACRO FUNCTIONS******************/
#define OK 1
#define N_OK 0
u16 GLOP_u16NumberOfLights=0;
void APP_u8_Bluetooth_Receive(void);
u8 Glopal_Flag = 15;
usart_t rc_uart = {
    .BaudRate = 9600,
    .BaudRate_CFG = USART_ASYNCHRONOUS_BAUD_RATE_LOW_SPEED,
    .transmit.usart_tx_9bit_enable = USART_ASYNCHRONOUS_TX_9BIT_DISABLE,
    .transmit.usart_tx_enable = USART_ASYNCHRONOUS_TX_DISABLE,
    .USART_FramingErrorInterruptHandeler = NULL,
    .USART_OverRunErrorInterruptHandeler = NULL,
    .USART_RxDefualtInterruptHandeler = APP_u8_Bluetooth_Receive,
    .receive.usart_rx_9bit_enable = USART_ASYNCHRONOUS_RX_9BIT_DISABLE,
    .receive.usart_rx_enable = USART_ASYNCHRONOUS_RX_ENABLE,
    .receive.usart_rx_interrupt_enable = USART_ASYNCHRONOUS_RX_INTERRUPT_ENABLE};

typedef struct
{
    u8 sensor_TEMP;
    u8 Set_TEMP;
    u8 Door : 2;
    u8 TV : 2;
    u8 Light_status : 2;
    u8 Light;
} Data_t;
/*-----------------------Function Decleration----------------*/
void Application_Init(void);
void I2C_ReceiveStuct(Data_t *MyData);
void App_CheckTemp(Data_t *MyData);
void App_CheckDoor(Data_t *MyData);
void App_CheckTV(Data_t *MyData);
void App_CheckRoom(Data_t *MyData);
void App_printData(Data_t *MyData, LCD_4_BIT_T *LCD);
void APP_u8_Bluetooth_Receive(void);

/* ----------------- Data Type Declarations -----------------*/
LED_T TV_LED = {
    .Port = PORT_A,
    .Pin = PIN_2,
    .Stauts = CommonAnode

};

LED_T LED_ROOM_1 = {
    .Port = PORT_D,
    .Pin = PIN_0,
    .Stauts = CommonAnode};
LED_T LED_ROOM_2 = {
    .Port = PORT_D,
    .Pin = PIN_1,
    .Stauts = CommonAnode};
LED_T LED_ROOM_3 = {
    .Port = PORT_D,
    .Pin = PIN_2,
    .Stauts = CommonAnode};
LED_T LED_ROOM_4 = {
    .Port = PORT_D,
    .Pin = PIN_3,
    .Stauts = CommonAnode};
LED_T LED_ROOM_5 = {
    .Port = PORT_D,
    .Pin = PIN_4,
    .Stauts = CommonAnode};
LED_T LED_ROOM_6 = {
    .Port = PORT_D,
    .Pin = PIN_5,
    .Stauts = CommonAnode};
LED_T LED_ROOM_7 = {
    .Port = PORT_D,
    .Pin = PIN_6,
    .Stauts = CommonAnode};
LED_T LED_ROOM_8 = {
    .Port = PORT_D,
    .Pin = PIN_7,
    .Stauts = CommonAnode};

LCD_4_BIT_T LCD_1 = {
    .LCD_RS.Port = PORT_B,
    .LCD_RS.Pin = PIN_0,
    .LCD_RW.Port = PORT_B,
    .LCD_RW.Pin = PIN_1,
    .LCD_EN.Port = PORT_B,
    .LCD_EN.Pin = PIN_2,
    .DataPin[0].Port = PORT_B,
    .DataPin[0].Pin = PIN_4,
    .DataPin[1].Port = PORT_B,
    .DataPin[1].Pin = PIN_5,
    .DataPin[2].Port = PORT_B,
    .DataPin[2].Pin = PIN_6,
    .DataPin[3].Port = PORT_B,
    .DataPin[3].Pin = PIN_7,
};
I2C_t I2C_OBJ =
    {
        .i2c_cfg.i2c_general_call = GENERAL_CALL_DISABLE,
        .i2c_cfg.i2c_mode = I2C_SLAVE,
        .i2c_cfg.i2c_mode_cfg = I2C_SLAVE_7BIT_ADSRESS,
        .i2c_cfg.i2c_slave_add = 0x30,
        .i2c_cfg.i2c_slew_rate = SLEW_RATE_DISABLE,
        .i2c_cfg.i2c_smBUS = SMBUS_DISABLE};
#endif /* APPLICATION_H */
