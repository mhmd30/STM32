/* 
 * File:   hal_eeprom.h
 * Author: Mohammed_Elnefary
 *
 * Created on May 24, 2023, 11:20 AM
 */

#ifndef HAL_EEPROM_H
#define	HAL_EEPROM_H


/******************************************************************************/
/*                            Includes Section                                */
/******************************************************************************/
#include "pic18f4620.h"
#include "../mcal_std_types.h"
#include "../Interrupt/mcal_internal_interrupt.h"

/******************************************************************************/
/*                       Macros Declaration Section                           */
/******************************************************************************/

/* Flash Program or Data EEPROM Memory Select  */
#define ACCESS_FLASH_PROGRAM_MEMORY       1
#define ACCESS_EEPROM_PROGRAM_MEMORY      0
/* Flash Program/Data EEPROM or Configuration Select */
#define ACCESS_CONFIG_REGISTERS           1
#define ACCESS_FLASH_EEPROM_MEMORY        0
/* Flash Program/Data EEPROM Write Enable */
#define ALLOW_WRITE_CYCLES_FLASH_EEPROM   1
#define INHIBTS_WRITE_CYCLES_FLASH_EEPROM 0
/* Write Control */
#define INITIATE_DATA_EEPROM_WRITE_ERASE  1
#define DATA_EEPROM_WRITE_ERASE_COMPLETED 0
/* Read Control */
#define INITIATE_DATA_EEPROM_READ         1


/******************************************************************************/
/*                  Macro Functions Declaration Section                       */
/******************************************************************************/


/******************************************************************************/
/*                   Data_Types Declaration Section                           */
/******************************************************************************/


/******************************************************************************/
/*                    functions declaration Section                           */
/******************************************************************************/
Std_ReturnType Data_EEPROM_WriteByte(uint16 bAdd, uint8 bData);
Std_ReturnType Data_EEPROM_ReadByte(uint16 bAdd, uint8 *bData);

#endif	/* HAL_EEPROM_H */

