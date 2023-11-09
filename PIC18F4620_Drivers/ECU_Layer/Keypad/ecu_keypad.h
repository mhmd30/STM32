/* 
 * File:   ecu_keypad.h
 * Author: Mohammed_Elnefary
 *
 * Created on April 25, 2023, 5:47 PM
 */

#ifndef ECU_KEYPAD_H
#define	ECU_KEYPAD_H


/******************************************************************************/
/*                            Includes Section                                */
/******************************************************************************/

#include "ecu_keypad_cfg.h"
#include "../../MCAL_Layer/GPIO/hal_gpio.h"
/******************************************************************************/
/*                       Macros Declaration Section                           */
/******************************************************************************/

#define ECU_KEYPAD_ROWS    4
#define ECU_KEYPAD_COLUMNS 4 

/******************************************************************************/
/*                  Macro Functions Declaration Section                       */
/******************************************************************************/


/******************************************************************************/
/*                   Data_Types Declaration Section                           */
/******************************************************************************/

typedef struct{
    pin_config_t keypad_row_pins[ECU_KEYPAD_ROWS];
    pin_config_t keypad_columns_pins[ECU_KEYPAD_COLUMNS];
}keypad_t;

/******************************************************************************/
/*                    functions declaration Section                           */
/******************************************************************************/

Std_ReturnType keypad_initialize(const keypad_t *_keypad_obj);
Std_ReturnType keypad_get_value(const keypad_t *_keypad_obj, uint8 *value);

#endif	/* ECU_KEYPAD_H */

