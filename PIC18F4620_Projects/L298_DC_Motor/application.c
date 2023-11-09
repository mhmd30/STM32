/* 
 * File:   application.c
 * Author: Mohammed_Elnefary
 * Created on April 10, 2023, 12:47 AM
 */

#include "application.h"

dc_motor_t dc_motor_1 = {
    .dc_motor_pin[0].port = PORTC_INDEX,
    .dc_motor_pin[0].pin = GPIO_PIN0,
    .dc_motor_pin[0].logic = DC_MOTOR_OFF_STATUS,
    .dc_motor_pin[0].direction = GPIO_DIRECTION_OUTPUT,
    .dc_motor_pin[1].port = PORTC_INDEX,
    .dc_motor_pin[1].pin = GPIO_PIN1,
    .dc_motor_pin[1].logic = DC_MOTOR_OFF_STATUS,
    .dc_motor_pin[1].direction = GPIO_DIRECTION_OUTPUT
};

dc_motor_t dc_motor_2 = {
    .dc_motor_pin[0].port = PORTC_INDEX,
    .dc_motor_pin[0].pin = GPIO_PIN2,
    .dc_motor_pin[0].logic = DC_MOTOR_OFF_STATUS,
    .dc_motor_pin[0].direction = GPIO_DIRECTION_OUTPUT,
    .dc_motor_pin[1].port = PORTC_INDEX,
    .dc_motor_pin[1].pin = GPIO_PIN3,
    .dc_motor_pin[1].logic = DC_MOTOR_OFF_STATUS,
    .dc_motor_pin[1].direction = GPIO_DIRECTION_OUTPUT
};


int main() { 
    Std_ReturnType ret = E_NOT_OK;
    application_intialize();
    while(1){
        ret = dc_motor_move_right(&dc_motor_1);
        ret = dc_motor_move_right(&dc_motor_2);
        __delay_ms(3000);
        ret = dc_motor_move_left(&dc_motor_1);
        ret = dc_motor_move_left(&dc_motor_2);
        __delay_ms(3000);
        ret = dc_motor_stop(&dc_motor_1);
        ret = dc_motor_stop(&dc_motor_2);
        __delay_ms(3000);
        ret = dc_motor_move_right(&dc_motor_1);
        ret = dc_motor_move_left(&dc_motor_2);
        __delay_ms(3000);
        ret = dc_motor_stop(&dc_motor_1);
        ret = dc_motor_stop(&dc_motor_2);
        __delay_ms(3000);
        ret = dc_motor_move_right(&dc_motor_2);
        ret = dc_motor_move_left(&dc_motor_1);
        __delay_ms(3000);
    }
    return (EXIT_SUCCESS);
}

void application_intialize(void){
    Std_ReturnType ret = E_NOT_OK;
    ret = dc_motor_initialize(&dc_motor_1);
    ret = dc_motor_initialize(&dc_motor_2);
}
