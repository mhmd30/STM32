/* 
 * File:   ecu_layer_init.h
 * Author: Mohammed_Elnefary
 *
 * Created on April 26, 2023, 6:10 PM
 */

#ifndef ECU_LAYER_INIT_H
#define	ECU_LAYER_INIT_H


/******************************************************************************/
/*                            Includes Section                                */
/******************************************************************************/

#include "../ECU_Layer/LED/ecu_led.h"
#include "../ECU_Layer/button/ecu_button.h"
#include "../ECU_Layer/relay/ecu_relay.h"
#include "../ECU_Layer/DC_Motor/ecu_dc_motor.h"
#include "../ECU_Layer/7_segment/ecu_seven_segment.h"
#include "../ECU_Layer/Keypad/ecu_keypad.h"
#include "../ECU_Layer/CHR_LCD/ecu_chr_lcd.h"

/******************************************************************************/
/*                       Macros Declaration Section                           */
/******************************************************************************/



/******************************************************************************/
/*                  Macro Functions Declaration Section                       */
/******************************************************************************/


/******************************************************************************/
/*                   Data_Types Declaration Section                           */
/******************************************************************************/

extern pin_config_t _pin_config;
extern led_t led1;
extern led_t led2;
extern led_t led3;
extern led_t led4;
extern button_t btn1;
extern relay_t _relay;
extern dc_motor_t dc_motor_1;
extern segment_t seg1;
extern keypad_t keypad1;
extern chr_lcd_4bit_t lcd_1;
extern chr_lcd_8bit_t lcd_2;

/******************************************************************************/
/*                    functions declaration Section                           */
/******************************************************************************/
void ecu_layer_intialize(void);


#endif	/* ECU_LAYER_INIT_H */

