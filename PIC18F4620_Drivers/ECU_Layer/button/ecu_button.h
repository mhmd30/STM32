/* 
 * File:   ecu_button.h
 * Author: Mohammed_Elnefary
 *
 * Created on April 10, 2023, 12:45 AM
 */

#ifndef ECU_BUTTON_H
#define	ECU_BUTTON_H


/******************************************************************************/
/*                            Includes Section                                */
/******************************************************************************/
#include "../ecu_button_cfg.h"
#include "../../MCAL_Layer/GPIO/hal_gpio.h"

/******************************************************************************/
/*                       Macros Declaration Section                           */
/******************************************************************************/



/******************************************************************************/
/*                  Macro Functions Declaration Section                       */
/******************************************************************************/


/******************************************************************************/
/*                   Data_Types Declaration Section                           */
/******************************************************************************/
typedef enum{
    BUTTON_PRESSED = 0,
    BUTTON_RELEASED
}button_state_t;

typedef enum{
    BUTTON_ACTIVE_HIGH,
    BUTTON_ACTIVE_LOW
}button_active_t;

typedef struct{
    pin_config_t button_pin;
    button_state_t button_state;
    button_active_t button_connection;
}button_t;

/******************************************************************************/
/*                    functions declaration Section                           */
/******************************************************************************/

/**
 * @brief Initialize the assigned pin to be Input.
 * @param btn pointer to the button configurations
 * @return  Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue while performing this action
 */
Std_ReturnType button_initialize(const button_t *btn);

/**
 * @brief Read the state of the button
 * @param btn pointer to the button configurations
 * @param btn_state button state @ref button_state_t
 * @return  Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue while performing this action
 */
Std_ReturnType button_read_state(const button_t *btn, button_state_t *btn_state);



#endif	/* ECU_BUTTON_H */

