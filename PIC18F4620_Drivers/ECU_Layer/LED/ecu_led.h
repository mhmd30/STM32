/* 
 * File:   ecu_led.h
 * Author: Mohammed_Elnefary
 *
 * Created on April 2, 2023, 5:51 PM
 */

#ifndef ECU_LED_H
#define	ECU_LED_H


/******************************************************************************/
/*                            Includes Section                                */
/******************************************************************************/
#include "../../MCAL_Layer/GPIO/hal_gpio.h"
#include "../ecu_led_cfg.h"
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
    LED_OFF,
    LED_ON
}led_status_t;

typedef struct{
    uint8 port_name : 4;  /*one bit reserved*/
    uint8 pin : 3;
    uint8 led_status : 1;
}led_t;

/******************************************************************************/
/*                    functions declaration Section                           */
/******************************************************************************/
Std_ReturnType led_initialize(const led_t *led);
Std_ReturnType led_turn_on(const led_t *led);
Std_ReturnType led_turn_off(const led_t *led);
Std_ReturnType led_turn_toggle(const led_t *led);


#endif	/* ECU_LED_H */

