/* 
 * File:   Interrupt_interface.h
 * Author: dell
 *
 * Created on October 19, 2023, 8:30 PM
 */

#ifndef EXT_INTERRUPT_INTERFACE_H
#define	EXT_INTERRUPT_INTERFACE_H

/*--------------Includes--------------*/
#include "Interrupt_config.h"
/*--------------Macro Declerations--------------*/
/*----------Macro Function-------------- */
#if INTERRUPT_EXTERNAL_INTERRUPT==INTERRUPT_FEATURE_ENABLE
#if INTERRUPT_EXTERNAL_INTERRUPT_INTX==INTERRUPT_FEATURE_ENABLE

/*Functions to enable and disable interrupt (INT0) */
#define INTERRUPT_INT0_InterruptEnable()        (INTCONbits.INT0IE = 1)
#define INTERRUPT_INT0_InterruptDisable()       (INTCONbits.INT0IE = 0) 
/*Function to clear the interrupt Flag*/
#define INTERRUPT_INT0_ClearFlag()              (INTCONbits.INT0IF = 0)
/*Function to enable Interrupt (INT0) With Rising Edge*/
#define INTERRUPT_INT0_RisingEdge()             (INTCON2bits.INTEDG0=1)
/*Function to enable Interrupt (INT0) With Falling Edge*/
#define INTERRUPT_INT0_FallingEdge()            (INTCON2bits.INTEDG0=0)

/*Functions to enable and disable interrupt (INT1) */
#define INTERRUPT_INT1_InterruptEnable()         (INTCON3bits.INT1IE=1)
#define INTERRUPT_INT1_InterruptDisable()        (INTCON3bits.INT1IE=0)
/*Function to clear the interrupt Flag (INT1)*/
#define INTERRUPT_INT1_ClearFlag()               (INTCON3bits.INT1IF=0)
/*Function to enable Interrupt (INT1) With Rising Edge*/
#define INTERRUPT_INT1_RisingEdge()              (INTCON2bits.INTEDG1=1)
/*Function to enable Interrupt (INT1) With Falling Edge*/
#define INTERRUPT_INT1_FallingEdge()             (INTCON2bits.INTEDG1=0)


/*Functions to enable and disable interrupt (INT2) */
#define INTERRUPT_INT2_InterruptEnable()         (INTCON3bits.INT2IE=1)
#define INTERRUPT_INT2_InterruptDisable()        (INTCON3bits.INT2IE=0)
/*Function to clear the interrupt Flag (INT2)*/
#define INTERRUPT_INT2_ClearFlag()               (INTCON3bits.INT2IF=0)
/*Function to enable Interrupt (INT2) With Rising Edge*/
#define INTERRUPT_INT2_RisingEdge()              (INTCON2bits.INTEDG2=1)
/*Function to enable Interrupt (INT2) With Falling Edge*/
#define INTERRUPT_INT2_FallingEdge()             (INTCON2bits.INTEDG2=0)

#if INTERRUPT_PRIORITY_level==INTERRUPT_FEATURE_ENABLE
/*Function to Select interrupt High priority level (INT1)*/
#define INTERRUPT_INT1_HighPriority()             (INTCON3bits.INT1IP=1)
/*Function to Select interrupt Low priority level (INT1)*/
#define INTERRUPT_INT1_LowPriority()              (INTCON3bits.INT1IP=0)
/*Function to Select interrupt High priority level (INT2)*/
#define INTERRUPT_INT2_HighPriority()             (INTCON3bits.INT2IP=1)
/*Function to Select interrupt Low priority level (INT2)*/
#define INTERRUPT_INT2_LowPriority()              (INTCON3bits.INT2IP=0)
#endif
#endif
#if INTERRUPT_EXTERNAL_INTERRUPT_RBX==INTERRUPT_FEATURE_ENABLE
/*function to enable onchange external interrupt (RBX)*/
#define INTERRUPT_RBX_InterruptEnable()           (INTCONbits.RBIE=1)
/*function to disable onchange external interrupt (RBX)*/
#define INTERRUPT_RBX_InterruptDisable()          (INTCONbits.RBIE=0)
/*function to Clear flag onchange external interrupt (RBX) */
#define INTERRUPT_RBX_ClearFlag()                 (INTCONbits.RBIF = 0)
#if INTERRUPT_PRIORITY_level == INTERRUPT_FEATURE_ENABLE
/*Function to select high priority interrupt*/
#define INTERRUPT_RBX_HighPriority()              (INTCON2bits.RBIP=1)
/*Function to select low priority interrupt*/
#define INTERRUPT_RBX_LowPriority()               (INTCON2bits.RBIP=0)
#endif
#endif
#endif



typedef enum {
    INTERRUPT_ExternalInterrupt_INT0 = 0,
    INTERRUPT_ExternalInterrupt_INT1,
    INTERRUPT_ExternalInterrupt_INT2
} InterruptSource_INTX_T;

typedef enum {
    INTERRUPT_ExternalInterrupt_Falling = 0,
    INTERRUPT_ExternalInterrupt_Rising
} InterruptEdge_INTX_T;

typedef enum {
    INTERRUPT_Interrupt_LowPriority = 0,
    INTERRUPT_Interrupt_HighPriority
} InterruptPriority_T;

typedef struct {
    void (*EXT_InterruptHandler)(void);
    PinConfig_T pin;
    InterruptSource_INTX_T source;
    InterruptEdge_INTX_T edge;
    InterruptPriority_T priority;
} Interrupt_INTX_T;

typedef struct {
    void (*EXT_InterruptHandler_HIGH)(void);
    void (*EXT_InterruptHandler_LOW)(void);
    PinConfig_T pin;
    InterruptPriority_T priority;
} Interrupt_RBX_T;

void Interrupt_INTX_Init(Interrupt_INTX_T *Copy_stINTX);
void Interrupt_INTX_UnInit(Interrupt_INTX_T *Copy_stINTX);
void Interrupt_RBX_Init(Interrupt_RBX_T *Copy_stRBX);
void Interrupt_RBX_UnInit(Interrupt_RBX_T *Copy_stRBX);
void Interrupt_GLOP_InterruptEnable(void);
void Interrupt_GLOP_InterruptDisable(void);

#endif	/* INTERRUPT_INTERFACE_H */

