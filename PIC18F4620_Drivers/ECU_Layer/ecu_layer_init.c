/* 
 * File:   ecu_layer_init.c
 * Author: Mohammed_Elnefary
 *
 * Created on April 26, 2023, 6:10 PM
 */

#include "ecu_layer_init.h"

pin_config_t _pin_config = {
    .port = PORTD_INDEX,
    .pin = GPIO_PIN2,
    .logic = GPIO_LOW,
    .direction = GPIO_DIRECTION_INPUT
};



led_t led1 = {.port_name = PORTB_INDEX, .pin = GPIO_PIN0, .led_status = GPIO_LOW};
led_t led2 = {.port_name = PORTC_INDEX, .pin = GPIO_PIN1, .led_status = GPIO_LOW};
led_t led3 = {.port_name = PORTC_INDEX, .pin = GPIO_PIN2, .led_status = GPIO_LOW};
led_t led4 = {.port_name = PORTC_INDEX, .pin = GPIO_PIN3, .led_status = GPIO_LOW};

relay_t _relay = {
    .relay_port = PORTC_INDEX,
    .relay_pin = GPIO_PIN0,
    .relay_status = RELAY_OFF_STATUS
};

dc_motor_t dc_motor_1 = {
    .dc_motor_pin[0].port = PORTD_INDEX,
    .dc_motor_pin[0].pin = GPIO_PIN0,
    .dc_motor_pin[0].logic = DC_MOTOR_OFF_STATUS,
    .dc_motor_pin[0].direction = GPIO_DIRECTION_OUTPUT,
    .dc_motor_pin[1].port = PORTD_INDEX,
    .dc_motor_pin[1].pin = GPIO_PIN1,
    .dc_motor_pin[1].logic = DC_MOTOR_OFF_STATUS,
    .dc_motor_pin[1].direction = GPIO_DIRECTION_OUTPUT
};
        
        
        
segment_t seg1 = {
    .segment_pins[SEGEMENT_PIN0].port = PORTC_INDEX,
    .segment_pins[SEGEMENT_PIN0].pin = GPIO_PIN0,
    .segment_pins[SEGEMENT_PIN0].logic = GPIO_HIGH,
    .segment_pins[SEGEMENT_PIN0].direction = GPIO_DIRECTION_OUTPUT,
    .segment_pins[SEGEMENT_PIN1].port = PORTC_INDEX,
    .segment_pins[SEGEMENT_PIN1].pin = GPIO_PIN1,
    .segment_pins[SEGEMENT_PIN1].logic = GPIO_HIGH,
    .segment_pins[SEGEMENT_PIN1].direction = GPIO_DIRECTION_OUTPUT,
    .segment_pins[SEGEMENT_PIN2].port = PORTC_INDEX,
    .segment_pins[SEGEMENT_PIN2].pin = GPIO_PIN2,
    .segment_pins[SEGEMENT_PIN2].logic = GPIO_HIGH,
    .segment_pins[SEGEMENT_PIN2].direction = GPIO_DIRECTION_OUTPUT,
    .segment_pins[SEGEMENT_PIN3].port = PORTC_INDEX,
    .segment_pins[SEGEMENT_PIN3].pin = GPIO_PIN3,
    .segment_pins[SEGEMENT_PIN3].logic = GPIO_HIGH,
    .segment_pins[SEGEMENT_PIN3].direction = GPIO_DIRECTION_OUTPUT,
    .segment_type = SEGMENT_COMMON_CATHODE
};

button_t btn1={
    .button_pin.port = PORTD_INDEX,
    .button_pin.pin = GPIO_PIN2,
    .button_pin.logic = GPIO_LOW,
    .button_pin.direction = GPIO_DIRECTION_INPUT,
    .button_connection = BUTTON_ACTIVE_HIGH,
    .button_state = BUTTON_RELEASED
};


keypad_t keypad1 = {
    .keypad_row_pins[0].port = PORTB_INDEX,
    .keypad_row_pins[0].pin = GPIO_PIN0,
    .keypad_row_pins[0].direction = GPIO_DIRECTION_OUTPUT,
    .keypad_row_pins[0].logic = GPIO_LOW,
    .keypad_row_pins[1].port = PORTB_INDEX,
    .keypad_row_pins[1].pin = GPIO_PIN1,
    .keypad_row_pins[1].direction = GPIO_DIRECTION_OUTPUT,
    .keypad_row_pins[1].logic = GPIO_LOW,
    .keypad_row_pins[2].port = PORTB_INDEX,
    .keypad_row_pins[2].pin = GPIO_PIN2,
    .keypad_row_pins[2].direction = GPIO_DIRECTION_OUTPUT,
    .keypad_row_pins[2].logic = GPIO_LOW,
    .keypad_row_pins[3].port = PORTB_INDEX,
    .keypad_row_pins[3].pin = GPIO_PIN3,
    .keypad_row_pins[3].direction = GPIO_DIRECTION_OUTPUT,
    .keypad_row_pins[3].logic = GPIO_LOW,
    .keypad_columns_pins[0].port = PORTB_INDEX,
    .keypad_columns_pins[0].pin = GPIO_PIN4,
    .keypad_columns_pins[0].direction = GPIO_DIRECTION_INPUT,
    .keypad_columns_pins[0].logic = GPIO_LOW,
    .keypad_columns_pins[1].port = PORTB_INDEX,
    .keypad_columns_pins[1].pin = GPIO_PIN5,
    .keypad_columns_pins[1].direction = GPIO_DIRECTION_INPUT,
    .keypad_columns_pins[1].logic = GPIO_LOW,
    .keypad_columns_pins[2].port = PORTB_INDEX,
    .keypad_columns_pins[2].pin = GPIO_PIN6,
    .keypad_columns_pins[2].direction = GPIO_DIRECTION_INPUT,
    .keypad_columns_pins[2].logic = GPIO_LOW,
    .keypad_columns_pins[3].port = PORTB_INDEX,
    .keypad_columns_pins[3].pin = GPIO_PIN7,
    .keypad_columns_pins[3].direction = GPIO_DIRECTION_INPUT,
    .keypad_columns_pins[3].logic = GPIO_LOW,
};

chr_lcd_4bit_t lcd_1 = {
    .lcd_rs.port = PORTC_INDEX,
    .lcd_rs.pin = GPIO_PIN0,
    .lcd_rs.direction = GPIO_DIRECTION_OUTPUT,
    .lcd_rs.logic = GPIO_LOW,
    .lcd_en.port = PORTC_INDEX,
    .lcd_en.pin = GPIO_PIN1,
    .lcd_en.direction = GPIO_DIRECTION_OUTPUT,
    .lcd_en.logic = GPIO_LOW,
    .lcd_data[0].port = PORTC_INDEX,
    .lcd_data[0].pin = GPIO_PIN2,
    .lcd_data[0].direction = GPIO_DIRECTION_OUTPUT,
    .lcd_data[0].logic = GPIO_LOW,
    .lcd_data[1].port = PORTC_INDEX,
    .lcd_data[1].pin = GPIO_PIN3,
    .lcd_data[1].direction = GPIO_DIRECTION_OUTPUT,
    .lcd_data[1].logic = GPIO_LOW,
    .lcd_data[2].port = PORTC_INDEX,
    .lcd_data[2].pin = GPIO_PIN4,
    .lcd_data[2].direction = GPIO_DIRECTION_OUTPUT,
    .lcd_data[2].logic = GPIO_LOW,
    .lcd_data[3].port = PORTC_INDEX,
    .lcd_data[3].pin = GPIO_PIN5,
    .lcd_data[3].direction = GPIO_DIRECTION_OUTPUT,
    .lcd_data[3].logic = GPIO_LOW
};

chr_lcd_8bit_t lcd_2 = {
    .lcd_rs.port = PORTC_INDEX,
    .lcd_rs.pin = GPIO_PIN6,
    .lcd_rs.direction = GPIO_DIRECTION_OUTPUT,
    .lcd_rs.logic = GPIO_LOW,
    .lcd_en.port = PORTC_INDEX,
    .lcd_en.pin = GPIO_PIN7,
    .lcd_en.direction = GPIO_DIRECTION_OUTPUT,
    .lcd_en.logic = GPIO_LOW,
    .lcd_data[0].port = PORTD_INDEX,
    .lcd_data[0].pin = GPIO_PIN0,
    .lcd_data[0].direction = GPIO_DIRECTION_OUTPUT,
    .lcd_data[0].logic = GPIO_LOW,
    .lcd_data[1].port = PORTD_INDEX,
    .lcd_data[1].pin = GPIO_PIN1,
    .lcd_data[1].direction = GPIO_DIRECTION_OUTPUT,
    .lcd_data[1].logic = GPIO_LOW,
    .lcd_data[2].port = PORTD_INDEX,
    .lcd_data[2].pin = GPIO_PIN2,
    .lcd_data[2].direction = GPIO_DIRECTION_OUTPUT,
    .lcd_data[2].logic = GPIO_LOW,
    .lcd_data[3].port = PORTD_INDEX,
    .lcd_data[3].pin = GPIO_PIN3,
    .lcd_data[3].direction = GPIO_DIRECTION_OUTPUT,
    .lcd_data[3].logic = GPIO_LOW,
    .lcd_data[4].port = PORTD_INDEX,
    .lcd_data[4].pin = GPIO_PIN4,
    .lcd_data[4].direction = GPIO_DIRECTION_OUTPUT,
    .lcd_data[4].logic = GPIO_LOW,
    .lcd_data[5].port = PORTD_INDEX,
    .lcd_data[5].pin = GPIO_PIN5,
    .lcd_data[5].direction = GPIO_DIRECTION_OUTPUT,
    .lcd_data[5].logic = GPIO_LOW,
    .lcd_data[6].port = PORTD_INDEX,
    .lcd_data[6].pin = GPIO_PIN6,
    .lcd_data[6].direction = GPIO_DIRECTION_OUTPUT,
    .lcd_data[6].logic = GPIO_LOW,
    .lcd_data[7].port = PORTD_INDEX,
    .lcd_data[7].pin = GPIO_PIN7,
    .lcd_data[7].direction = GPIO_DIRECTION_OUTPUT,
    .lcd_data[7].logic = GPIO_LOW
};

void ecu_layer_intialize(void){
    Std_ReturnType ret = E_NOT_OK;
    /*ret = led_initialize(&led1);
    ret = led_initialize(&led2);
    ret = led_initialize(&led3);
    ret = led_initialize(&led4);
    ret = lcd_4bit_intialize(&lcd_1);*/
    //ret = led_initialize(&led1);
    //seven_segment_intialize(&seg1);
    

}
