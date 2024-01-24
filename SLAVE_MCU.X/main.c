
#include <stdio.h>
#include <stdlib.h>
#include "Application.h"

u8 Uart_Data = 0;
Data_t Data = {
    .sensor_TEMP = 0,
    .Set_TEMP = 0,
    .Door = 0,
    .TV = 2,
    .Light = 15,
    .Light_status = 0
};
u8 flag = 0;

int main(void) {
    Application_Init();
    while (1) {
        if (1 == flag) {

            App_printData(&Data, &LCD_1);
        } else {
            LCD4Bit_voidSendString_Pos(&LCD_1, 1, 1, "Not Received ");
            LCD4Bit_voidSendString_Pos(&LCD_1, 2, 1, "Data Yet.... ");
        }
        I2C_ReceiveStuct(&Data);
        if (flag == 0) {
            LCD4Bit_voidSendCommand(&LCD_1, LCD_CLEAR);

        }
        flag = 1;
        App_CheckTemp(&Data);
        App_CheckDoor(&Data);
        App_CheckTV(&Data);
        App_CheckRoom(&Data);
        //  APP_u8_Bluetooth_Receive();
    }
    return (EXIT_SUCCESS);
}
