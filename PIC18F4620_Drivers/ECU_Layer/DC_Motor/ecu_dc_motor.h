/* 
 * File:   ecu_dc_motor.h
 * Author: Mohammed_Elnefary
 *
 * Created on April 14, 2023, 10:20 PM
 */

#ifndef ECU_DC_MOTOR_H
#define	ECU_DC_MOTOR_H


/******************************************************************************/
/*                            Includes Section                                */
/******************************************************************************/
#include "ecu_dc_motor_cfg.h"
#include "../../MCAL_Layer/GPIO/hal_gpio.h"

/******************************************************************************/
/*                       Macros Declaration Section                           */
/******************************************************************************/
#define DC_MOTOR_ON_STATUS    0x01U
#define DC_MOTOR_OFF_STATUS   0x00U

#define DC_MOTOR_PIN1         0x00U
#define DC_MOTOR_PIN2         0x01U

/******************************************************************************/
/*                  Macro Functions Declaration Section                       */
/******************************************************************************/


/******************************************************************************/
/*                   Data_Types Declaration Section                           */
/******************************************************************************/

typedef struct{
    pin_config_t dc_motor_pin[2];
}dc_motor_t;

/******************************************************************************/
/*                    functions declaration Section                           */
/******************************************************************************/

Std_ReturnType dc_motor_initialize(const dc_motor_t *_dc_motor);
Std_ReturnType dc_motor_move_right(const dc_motor_t *_dc_motor);
Std_ReturnType dc_motor_move_left(const dc_motor_t *_dc_motor);
Std_ReturnType dc_motor_stop(const dc_motor_t *_dc_motor);

#endif	/* ECU_DC_MOTOR_H */

