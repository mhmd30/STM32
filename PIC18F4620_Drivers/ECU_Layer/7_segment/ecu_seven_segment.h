/* 
 * File:   ecu_seven_segment.h
 * Author: Mohammed_Elnefary
 *
 * Created on April 24, 2023, 5:58 PM
 */

#ifndef ECU_SEVEN_SEGMENT_H
#define	ECU_SEVEN_SEGMENT_H

/******************************************************************************/
/*                            Includes Section                                */
/******************************************************************************/
#include "ecu_seven_segment_cfg.h"
#include "../../MCAL_Layer/GPIO/hal_gpio.h"

/******************************************************************************/
/*                       Macros Declaration Section                           */
/******************************************************************************/

#define SEGEMENT_PIN0 0
#define SEGEMENT_PIN1 1
#define SEGEMENT_PIN2 2
#define SEGEMENT_PIN3 3

/******************************************************************************/
/*                  Macro Functions Declaration Section                       */
/******************************************************************************/


/******************************************************************************/
/*                   Data_Types Declaration Section                           */
/******************************************************************************/

typedef enum{
    SEGMENT_COMMON_ANODE,
    SEGMENT_COMMON_CATHODE
}segment_type_t;

typedef struct{
    pin_config_t segment_pins[4];
    segment_type_t segment_type;
}segment_t;

/******************************************************************************/
/*                    functions declaration Section                           */
/******************************************************************************/

Std_ReturnType seven_segment_intialize(const segment_t *seg);
Std_ReturnType seven_segment_write_number(const segment_t *seg, uint8 number);



#endif	/* ECU_SEVEN_SEGMENT_H */

