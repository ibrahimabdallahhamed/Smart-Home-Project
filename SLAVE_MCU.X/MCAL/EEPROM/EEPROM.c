#include "EEPROM.h"

void EEPROM_voidWrite(u16 Copy_u16Address, u8 Copy_u8Data) {
    u8 Local_u8GlobalInterruptStatus = 0;
    /*read status of global interrupt pin*/
    Local_u8GlobalInterruptStatus = INTCONbits.GIE;
    /*Update the address regester */
    EEADRH = (u8) ((Copy_u16Address >> 8)&0x03);
    EEADR = (u8) ((Copy_u16Address & 0xFF));
    /*Update the data*/
    EEDATA = Copy_u8Data;
    /*Flash Program or Data EEPROM Memory Select bit*/
    Access_Data_EEPROM_Memory();
    /*Flash Program/Data EEPROM or Configuration Select bit*/
    Access_Flash_program_or_data_EEPROM_memory();
    /* Flash Program/Data EEPROM Write Enable bit*/
    Allows_write_cycles_to_Flash_program_data_EEPROM();
    INTERRUPT_GlobalInterruptDisable();
    EECON2 = 0x55;
    EECON2 = 0xAA;
    /*Write Control bit*/
    Initiates_data_EEPROM_erase_write_cycle();
    while (EECON1bits.WR);
    /* Flash Program/Data EEPROM Write Enable bit*/
    Inhibits_write_cycles_to_Flash_program_data_EEPROM();
    INTCONbits.GIE = Local_u8GlobalInterruptStatus;

}

u8 EEPROM_u8Read(u16 Copy_u16Address) {
    /*Update the address regester */
    EEADRH = (u8) ((Copy_u16Address >> 8)&0x03);
    EEADR = (u8) ((Copy_u16Address & 0xFF));
    /*Flash Program or Data EEPROM Memory Select bit*/
    Access_Data_EEPROM_Memory();
    /*Flash Program/Data EEPROM or Configuration Select bit*/
    Access_Flash_program_or_data_EEPROM_memory();
    /* Flash Program/Data EEPROM Write Enable bit*/
    Allows_write_cycles_to_Flash_program_data_EEPROM();
    /*Read Control bit*/
    initiates_an_EEPROM_read();
    NOP();
    NOP();
    /*Return value*/
    return EEDATA;

}