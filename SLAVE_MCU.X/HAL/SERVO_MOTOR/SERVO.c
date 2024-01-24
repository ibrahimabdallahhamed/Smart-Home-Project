#include "SERVO.h"
volatile u8 ccp_flag = 0;
volatile u16 Compare_Duty = 1800;

void APP(void);
CCP_t ccp1 = {
    .CPP_Variant = COMPARE_CCP_LOW,
    .mode = Compare_Mode,
    .timer3_timer1_ccp = TIMER3_CCP,
    .CCP1_InterruptHandeler = Servo_ISR,
    .ccp_select = CCP1


};
TIMER3_t T3 = {
    .RW_Mode = RW_16_BIT,
    .mode = TIMER_MODE,
    .preload = 0,
    .prescaler = TIMER3_PRESCALER_DIV_BY_1,
    .ext_clk_synch = N_SYNCH_CLK

};

void SERVO_voidServoInit(void) {
    CCP_voidInit(&ccp1);
    TIMER3_voidInit(&T3);
}

void SERVO_voidSetAngle(u8 Copy_u8Angle) {


    Compare_Duty = map(Copy_u8Angle, 0.0, 180.0, 1850.0, 4000.0);


}

void Servo_ISR(void) {

    ccp_flag++;
    TIMER3_voidWriteReg(&T3, 0);
    if (1 == ccp_flag) {
        CCP_voidCompareSetValue(&ccp1, Compare_Duty);
        CCP1_MODE_SELECT(COMPARE_CCP_HIGH);
    } else if (2 == ccp_flag) {
        CCP_voidCompareSetValue(&ccp1, 40000.0 - Compare_Duty);
        CCP1_MODE_SELECT(COMPARE_CCP_LOW);
        ccp_flag = 0;

    }

}

f32 map(f32 number, f32 start_1, f32 finish_1, f32 start_2, f32 finish_2) {
    f32 result;
    result = -((((finish_1 - number) * (finish_2 - start_2)) / (finish_1 - start_1)) - finish_2);
    return result;
}