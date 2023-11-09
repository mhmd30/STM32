/* 
 * File:   ecu_relay.h
 * Author: Mohammed_Elnefary
 *
 * Created on April 12, 2023, 8:02 AM
 */

#ifndef ECU_RELAY_H
#define	ECU_RELAY_H


/******************************************************************************/
/*                            Includes Section                                */
/******************************************************************************/
#include "../../MCAL_Layer/GPIO/hal_gpio.h"
#include "../ecu_relay_cfg.h"

/******************************************************************************/
/*                       Macros Declaration Section                           */
/******************************************************************************/
#define RELAY_ON_STATUS    0x01U
#define RELAY_OFF_STATUS   0x00U


/******************************************************************************/
/*                  Macro Functions Declaration Section                       */
/******************************************************************************/


/******************************************************************************/
/*                   Data_Types Declaration Section                           */
/******************************************************************************/
typedef struct{
    uint8 relay_port     :4;
    uint8 relay_pin      :3;
    uint8  relay_status  :1;
}relay_t;

/******************************************************************************/
/*                    functions declaration Section                           */
/******************************************************************************/
Std_ReturnType relay_initialize(const relay_t *_relay);
Std_ReturnType relay_turn_on(const relay_t *_relay);
Std_ReturnType relay_turn_off(const relay_t *_relay);
Std_ReturnType relay_toggle(relay_t *_relay);

#endif	/* ECU_RELAY_H */

