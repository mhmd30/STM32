/* 
 * File:   application.h
 * Author: Mohammed_Elnefary 
 *
 * Created on April 2, 2023, 5:56 PM
 */

#ifndef APPLICATION_H
#define	APPLICATION_H


/******************************************************************************/
/*                            Includes Section                                */
/******************************************************************************/

#include "ECU_Layer/ecu_layer_init.h"
#include "MCAL_Layer/Interrupt/mcal_external_interrupt.h"
#include "MCAL_Layer/EEPROM/hal_eeprom.h"
#include "MCAL_Layer/ADC/hal_adc.h"
#include "MCAL_Layer/Timer0/hal_timer0.h"
#include "MCAL_Layer/Timer1/hal_timer1.h"
#include "MCAL_Layer/Timer2/hal_timer2.h"
#include "MCAL_Layer/Timer3/hal_timer3.h"
#include "MCAL_Layer/CCP/hal_ccp.h"
#include "MCAL_Layer/USART/hal_usart.h"
#include "MCAL_Layer/SPI/hal_spi.h"
#include "MCAL_Layer/I2C/hal_i2c.h"

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

