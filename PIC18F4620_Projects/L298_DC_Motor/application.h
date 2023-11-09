/* 
 * File:   application.h
 * Author: Mohammed_Elnefary
 * Created on April 10, 2023, 12:47 AM
 */

#ifndef APPLICATION_H
#define	APPLICATION_H

/******************************************************************************/
/*                            Includes Section                                */
/******************************************************************************/
#include "ECU_Layer/LED/ecu_led.h"
#include "ECU_Layer/7_Segment/ecu_seven_segment.h"
#include "MCAL_Layer/ADC/hal_adc.h"
#include "ECU_Layer/Rleay/ecu_relay.h"
#include "ECU_Layer/DC_Motor/ecu_dc_motor.h"

/******************************************************************************/
/*                       Macros Declaration Section                           */
/******************************************************************************/



/******************************************************************************/
/*                  Macro Functions Declaration Section                       */
/******************************************************************************/


/******************************************************************************/
/*                   Data_Types Declaration Section                           */
/******************************************************************************/


/******************************************************************************/
/*                    functions declaration Section                           */
/******************************************************************************/
void application_intialize(void);


#endif	/* APPLICATION_H */

