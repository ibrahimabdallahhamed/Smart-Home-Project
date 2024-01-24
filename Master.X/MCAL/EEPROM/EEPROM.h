/* 
 * File:   EEPROM.h
 * Author: dell
 *
 * Created on October 26, 2023, 2:20 AM
 */

#ifndef EEPROM_H
#define	EEPROM_H

/*--------------Includes--------------*/
#include"pic18f4620.h"
#include"../../LIB/BITMATH.h"
#include"../../LIB/STDTYPES.h"
#include"../Interrupt/Interrupt_interface.h"

/*-----------------------------Macro Function----------------------------------------- */
/*Flash Program or Data EEPROM Memory Select bit*/
#define Access_Flash_program_memory()                   (EECON1bits.EEPGD=1)
#define Access_Data_EEPROM_Memory()                     (EECON1bits.EEPGD=0)
/*Flash Program/Data EEPROM or Configuration Select bit*/
#define Access_Configuration_registers()                (EECON1bits.CFGS=1)
#define Access_Flash_program_or_data_EEPROM_memory()    (EECON1bits.CFGS=0)
/* Flash Program/Data EEPROM Write Enable bit*/
#define Allows_write_cycles_to_Flash_program_data_EEPROM()(EECON1bits.WREN=1)
#define Inhibits_write_cycles_to_Flash_program_data_EEPROM()(EECON1bits.WREN=0)
/*Write Control bit*/
#define  Initiates_data_EEPROM_erase_write_cycle()        (EECON1bits.WR=1) 
/*Read Control bit*/
#define initiates_an_EEPROM_read()                        (EECON1bits.RD=1)
#define  Does_not_initiates_an_EEPROM_read()              (EECON1bits.RD=0)
/***********Functions Deceralations**********/
void EEPROM_voidWrite(u16 Copy_u16Address, u8 Copy_u8Data);
u8 EEPROM_u8Read(u16 Copy_u16Address);
#endif	/* EEPROM_H */

