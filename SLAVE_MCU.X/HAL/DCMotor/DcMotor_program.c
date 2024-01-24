#include "../../LIB/BITMATH.h"
#include "../../LIB/STDTYPES.h"
#include "../../MCAL/GPIO/GPIO_Interface.h"
#include "DCMotor_interface.h"
#include "../../MCAL/TIMER2/TIMER2.h"
#if CCP_1_SELECT_MODE == CCP_PWM_MODE ||  CCP__SELECT_MODE == CCP_PWM_MODE

CCP_t DC_MotorCCP = {
    .PWM_FREQ = 20000,
    .mode = PWM_Mode,
    .Postscaler = CCP_POSTSCALER_DIV_BY_1,
    .Prescaler = CCP_PRESCALER_DIV_BY_1,
    .ccp_select = CCP1

};
#endif
timer2_t t2 = {
    .postscaler = TIMER2_POSTSCALER_DIV_BY_1,
    .prescaler = TIMER2_PRESCALER_DIV_BY_1,
    .preload = 0
};

void DCMOTOR_voidDcMotorInt(DcMotor_T *Copy_stDcMotor) {
    GPIO_VoidSetPinDirection(Copy_stDcMotor->Port, Copy_stDcMotor->Pin[0], OUTPUT);
    GPIO_VoidSetPinDirection(Copy_stDcMotor->Port, Copy_stDcMotor->Pin[1], OUTPUT);
#if CCP_1_SELECT_MODE == CCP_PWM_MODE ||  CCP__SELECT_MODE == CCP_PWM_MODE

    switch (Copy_stDcMotor->EN_PIN) {
        case CCP1:
            DC_MotorCCP.ccp_select = CCP1;
            CCP1_MODE_SELECT(PWM_MODE);

            break;
        case CCP2:
            CCP2_MODE_SELECT(PWM_MODE);
            DC_MotorCCP.ccp_select = CCP2;

            break;
    }
#endif
    TIMER2_voidTmerInit(&t2);
#if CCP_1_SELECT_MODE == CCP_PWM_MODE ||  CCP__SELECT_MODE == CCP_PWM_MODE

    CCP_voidInit(&DC_MotorCCP);
    CCP_voidPWM_Start(&DC_MotorCCP);
#endif
    GPIO_VoidSetPinMode(Copy_stDcMotor->Port, Copy_stDcMotor->Pin[0], LOW);
    GPIO_VoidSetPinMode(Copy_stDcMotor->Port, Copy_stDcMotor->Pin[1], LOW);
}

void DCMOTOR_voidDcMotoroTurnOff(DcMotor_T *Copy_stDcMotor) {

    GPIO_VoidSetPinMode(Copy_stDcMotor->Port, Copy_stDcMotor->Pin[0], LOW);
    GPIO_VoidSetPinMode(Copy_stDcMotor->Port, Copy_stDcMotor->Pin[1], LOW);
}

void DCMOTOR_voidDcMotoroTurnForward(DcMotor_T *Copy_stDcMotor, u8 Copy_u8Speed) {
    GPIO_VoidSetPinMode(Copy_stDcMotor->Port, Copy_stDcMotor->Pin[0], HIGH);
    GPIO_VoidSetPinMode(Copy_stDcMotor->Port, Copy_stDcMotor->Pin[1], LOW);
#if CCP_1_SELECT_MODE == CCP_PWM_MODE ||  CCP__SELECT_MODE == CCP_PWM_MODE

    CCP_voidSetDuty(&DC_MotorCCP, Copy_u8Speed);
#endif
}

void DCMOTOR_voidDcMotoroTurnReverse(DcMotor_T *Copy_stDcMotor, u8 Copy_u8Speed) {
    GPIO_VoidSetPinMode(Copy_stDcMotor->Port, Copy_stDcMotor->Pin[1], HIGH);
    GPIO_VoidSetPinMode(Copy_stDcMotor->Port, Copy_stDcMotor->Pin[0], LOW);
#if CCP_1_SELECT_MODE == CCP_PWM_MODE ||  CCP__SELECT_MODE == CCP_PWM_MODE

    CCP_voidSetDuty(&DC_MotorCCP, Copy_u8Speed);
#endif
}