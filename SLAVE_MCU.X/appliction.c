#include "Application.h"

void Application_Init(void)
{
    /*SET ALL PIN AS A DIGITAL I/O PINS */
    ADC_AnalogPortConfig(ADC_ALL_DIGITAL_FUNCTIONALITY);
    GPIO_VoidSetPinDirection(PORT_A, PIN_0, OUTPUT);
    GPIO_VoidSetPinDirection(PORT_A, PIN_1, OUTPUT);
    GPIO_VoidSetPortDirection(PORT_D, OUTPUT);
    LED_voidLedInt(&TV_LED);
    LED_voidLedInt(&LED_ROOM_1);
    LED_voidLedInt(&LED_ROOM_2);
    LED_voidLedInt(&LED_ROOM_3);
    LED_voidLedInt(&LED_ROOM_4);
    LED_voidLedInt(&LED_ROOM_5);
    LED_voidLedInt(&LED_ROOM_6);
    LED_voidLedInt(&LED_ROOM_7);
    LED_voidLedInt(&LED_ROOM_8);
    Interrupt_GLOP_InterruptEnable();
    SERVO_voidServoInit();
    LCD4Bit_voidLCD_Init(&LCD_1);
    USART_voidAsynchUsartInit(&rc_uart);
    I2C_voidI2CInit(&I2C_OBJ);
}

void I2C_ReceiveStuct(Data_t *MyData)
{
    u8 SizeOfStruct = 0;
    SizeOfStruct = sizeof(*MyData);
    for (u8 i = 0; i <= SizeOfStruct; i++)
    {
        *((u8 *)MyData + i) = I2C_Read();
    }
}

void App_CheckTemp(Data_t *MyData)
{
    LCD_voidSetCursorPos_4Bit(&LCD_1, 4, 1);
    LCD4Bit_voidSendString_Pos(&LCD_1, 4, 1, "FAN:");
    LCD_voidSetCursorPos_4Bit(&LCD_1, 4, 5);
    if (MyData->sensor_TEMP > MyData->Set_TEMP)
    {
        GPIO_VoidSetPinMode(PORT_A, PIN_0, HIGH);
        GPIO_VoidSetPinMode(PORT_A, PIN_1, LOW);
        LCD4Bit_voidSendString_Pos(&LCD_1, 4, 5, "    ");
        LCD4Bit_voidSendString_Pos(&LCD_1, 4, 5, "ON");
    }
    else
    {
        GPIO_VoidSetPinMode(PORT_A, PIN_0, LOW);
        GPIO_VoidSetPinMode(PORT_A, PIN_1, LOW);
        LCD4Bit_voidSendString_Pos(&LCD_1, 4, 5, "OFF");
    }
}

void App_CheckDoor(Data_t *MyData)
{
    if (MyData->Door == 1)
    {
        SERVO_voidSetAngle(100);
    }
    else if (MyData->Door == 2)
    {
        SERVO_voidSetAngle(0);
    }
}

void App_CheckTV(Data_t *MyData)
{
    if (MyData->TV == 1)
    {
        LED_voidLedOn(&TV_LED);
    }
    else if (MyData->TV == 2)
    {
        LED_voidLedOff(&TV_LED);
    }
}

void App_CheckRoom(Data_t *MyData)
{
    for (u8 i = 0; i < 8; i++)
    {
        if (0 == GPIO_u8ReadPin(PORT_D, i))
        {
            GLOP_u16NumberOfLights++;
        }
    }
    if (1 == MyData->Light_status)
    {
        Glopal_Flag = 1;
        switch (MyData->Light)
        {
        case 0:
            LED_voidLedOff(&LED_ROOM_1);
            LED_voidLedOff(&LED_ROOM_2);
            LED_voidLedOff(&LED_ROOM_3);
            LED_voidLedOff(&LED_ROOM_4);
            LED_voidLedOff(&LED_ROOM_5);
            LED_voidLedOff(&LED_ROOM_6);
            LED_voidLedOff(&LED_ROOM_7);
            LED_voidLedOff(&LED_ROOM_8);
            break;
        case 1:
            LED_voidLedOn(&LED_ROOM_1);
            LED_voidLedOff(&LED_ROOM_2);
            LED_voidLedOff(&LED_ROOM_3);
            LED_voidLedOff(&LED_ROOM_4);
            LED_voidLedOff(&LED_ROOM_5);
            LED_voidLedOff(&LED_ROOM_6);
            LED_voidLedOff(&LED_ROOM_7);
            LED_voidLedOff(&LED_ROOM_8);
            break;
        case 2:
            LED_voidLedOn(&LED_ROOM_1);
            LED_voidLedOn(&LED_ROOM_2);
            LED_voidLedOff(&LED_ROOM_3);
            LED_voidLedOff(&LED_ROOM_4);
            LED_voidLedOff(&LED_ROOM_5);
            LED_voidLedOff(&LED_ROOM_6);
            LED_voidLedOff(&LED_ROOM_7);
            LED_voidLedOff(&LED_ROOM_8);
            break;
        case 3:
            LED_voidLedOn(&LED_ROOM_1);
            LED_voidLedOn(&LED_ROOM_2);
            LED_voidLedOn(&LED_ROOM_3);
            LED_voidLedOff(&LED_ROOM_4);
            LED_voidLedOff(&LED_ROOM_5);
            LED_voidLedOff(&LED_ROOM_6);
            LED_voidLedOff(&LED_ROOM_7);
            LED_voidLedOff(&LED_ROOM_8);
            break;
        case 4:
            LED_voidLedOn(&LED_ROOM_1);
            LED_voidLedOn(&LED_ROOM_2);
            LED_voidLedOn(&LED_ROOM_3);
            LED_voidLedOn(&LED_ROOM_4);
            LED_voidLedOff(&LED_ROOM_5);
            LED_voidLedOff(&LED_ROOM_6);
            LED_voidLedOff(&LED_ROOM_7);
            LED_voidLedOff(&LED_ROOM_8);
            break;
        case 5:
            LED_voidLedOn(&LED_ROOM_1);
            LED_voidLedOn(&LED_ROOM_2);
            LED_voidLedOn(&LED_ROOM_3);
            LED_voidLedOn(&LED_ROOM_4);
            LED_voidLedOn(&LED_ROOM_5);
            LED_voidLedOff(&LED_ROOM_6);
            LED_voidLedOff(&LED_ROOM_7);
            LED_voidLedOff(&LED_ROOM_8);
            break;
        case 6:
            LED_voidLedOn(&LED_ROOM_1);
            LED_voidLedOn(&LED_ROOM_2);
            LED_voidLedOn(&LED_ROOM_3);
            LED_voidLedOn(&LED_ROOM_4);
            LED_voidLedOn(&LED_ROOM_5);
            LED_voidLedOn(&LED_ROOM_6);
            LED_voidLedOff(&LED_ROOM_7);
            LED_voidLedOff(&LED_ROOM_8);
            break;
        case 7:
            LED_voidLedOn(&LED_ROOM_1);
            LED_voidLedOn(&LED_ROOM_2);
            LED_voidLedOn(&LED_ROOM_3);
            LED_voidLedOn(&LED_ROOM_4);
            LED_voidLedOn(&LED_ROOM_5);
            LED_voidLedOn(&LED_ROOM_6);
            LED_voidLedOn(&LED_ROOM_7);
            LED_voidLedOff(&LED_ROOM_8);
            break;
        case 8:
            LED_voidLedOn(&LED_ROOM_1);
            LED_voidLedOn(&LED_ROOM_2);
            LED_voidLedOn(&LED_ROOM_3);
            LED_voidLedOn(&LED_ROOM_4);
            LED_voidLedOn(&LED_ROOM_5);
            LED_voidLedOn(&LED_ROOM_6);
            LED_voidLedOn(&LED_ROOM_8);
            LED_voidLedOn(&LED_ROOM_7);
            break;
        }
    }
    else if (2 == MyData->Light_status)
    {
        Glopal_Flag = 2;
    }
}

void App_printData(Data_t *MyData, LCD_4_BIT_T *LCD)
{
    LCD_voidSetCursorPos_4Bit(LCD, 1, 1);
    LCD4Bit_voidSendString_Pos(LCD, 1, 1, "Temp:");
    LCD_voidSetCursorPos_4Bit(LCD, 1, 6);
    LCD4Bit_voidSendNumber(LCD, MyData->sensor_TEMP, 1, 6);
    LCD_voidSetCursorPos_4Bit(LCD, 1, 12);
    LCD4Bit_voidSendString_Pos(LCD, 1, 12, "TV:");
    if (MyData->TV == 1)
    {
        LCD_voidSetCursorPos_4Bit(LCD, 1, 15);
        LCD4Bit_voidSendString_Pos(LCD, 1, 15, "    ");
        LCD4Bit_voidSendString_Pos(LCD, 1, 15, "ON");
    }
    else if (MyData->TV == 2)
    {
        LCD_voidSetCursorPos_4Bit(LCD, 1, 15);
        LCD4Bit_voidSendString_Pos(LCD, 1, 15, "OFF");
    }

    LCD_voidSetCursorPos_4Bit(LCD, 2, 1);
    LCD4Bit_voidSendString_Pos(LCD, 2, 1, "Door:");
    LCD_voidSetCursorPos_4Bit(LCD, 2, 6);
    if (MyData->Door == 1)
    {
        LCD4Bit_voidSendString_Pos(LCD, 2, 6, "    ");
        LCD4Bit_voidSendString_Pos(LCD, 2, 6, "ON");
    }
    else
    {
        LCD_voidSetCursorPos_4Bit(LCD, 2, 6);
        LCD4Bit_voidSendString_Pos(LCD, 2, 6, "OFF");
    }

    LCD_voidSetCursorPos_4Bit(&LCD_1, 4, 1);
    LCD4Bit_voidSendString_Pos(&LCD_1, 4, 1, "FAN:");
    LCD_voidSetCursorPos_4Bit(&LCD_1, 4, 5);
    if (MyData->sensor_TEMP > MyData->Set_TEMP)
    {

        LCD4Bit_voidSendString_Pos(&LCD_1, 4, 5, "   ");
        LCD4Bit_voidSendString_Pos(&LCD_1, 4, 5, "ON");
    }
    else
    {

        LCD4Bit_voidSendString_Pos(&LCD_1, 4, 5, "OFF");
    }
    LCD_voidSetCursorPos_4Bit(&LCD_1, 3, 1);
    LCD4Bit_voidSendString_Pos(&LCD_1, 3, 1, "Lights on : ");
    LCD_voidSetCursorPos_4Bit(&LCD_1, 3, 1);
    LCD4Bit_voidSendNumber(&LCD_1, GLOP_u16NumberOfLights, 3, 14);
    GLOP_u16NumberOfLights=0;
}
void APP_u8_Bluetooth_Receive(void)
{
    u8 returned_bluetooth = 0;
    returned_bluetooth = USART_u8AsynchReadDataNonBlocking();
    if (Glopal_Flag == 2)
    {
        if (returned_bluetooth == 'a')
        {
            LED_voidLedOn(&LED_ROOM_1);
        }
        else if (returned_bluetooth == 'A')
        {
            LED_voidLedOff(&LED_ROOM_1);
        }
        if (returned_bluetooth == 'b')
        {
            LED_voidLedOn(&LED_ROOM_2);
        }
        else if (returned_bluetooth == 'B')
        {
            LED_voidLedOff(&LED_ROOM_2);
        }
        if (returned_bluetooth == 'c')
        {
            LED_voidLedOn(&LED_ROOM_3);
        }
        else if (returned_bluetooth == 'C')
        {
            LED_voidLedOff(&LED_ROOM_3);
        }
        if (returned_bluetooth == 'd')
        {
            LED_voidLedOn(&LED_ROOM_4);
        }
        else if (returned_bluetooth == 'D')
        {
            LED_voidLedOff(&LED_ROOM_4);
        }
        if (returned_bluetooth == 'e')
        {
            LED_voidLedOn(&LED_ROOM_5);
        }
        else if (returned_bluetooth == 'E')
        {
            LED_voidLedOff(&LED_ROOM_5);
        }
        if (returned_bluetooth == 'f')
        {
            LED_voidLedOn(&LED_ROOM_6);
        }
        else if (returned_bluetooth == 'F')
        {
            LED_voidLedOff(&LED_ROOM_6);
        }
        if (returned_bluetooth == 'g')
        {
            LED_voidLedOn(&LED_ROOM_7);
        }
        else if (returned_bluetooth == 'G')
        {
            LED_voidLedOff(&LED_ROOM_7);
        }
        if (returned_bluetooth == 'h')
        {
            LED_voidLedOn(&LED_ROOM_8);
        }
        else if (returned_bluetooth == 'H')
        {
            LED_voidLedOff(&LED_ROOM_8);
        }
    }
}
