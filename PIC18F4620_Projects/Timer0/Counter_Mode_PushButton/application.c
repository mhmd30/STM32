/* 
 * File:   application.c
 * Author: Mohammed_Elnefary
 * Created on May 17, 2023, 7:34 AM
 */

#include "application.h"

#include "MCAL_Layer/Timer0/hal_timr0.h"

led_t led1 = {.port_name = PORTC_INDEX, .pin = GPIO_PIN0, .led_status = GPIO_LOW};

volatile uint16 PushButtonCounter = 0;

void Timer0_DefaultInterruptHandler(void){
    
}

timer0_t timer0_counter_obj = {
    .TMR0_InterruptHandler = Timer0_DefaultInterruptHandler,
    .timer0_mode = TIMER0_COUNTER_MODE,
    .timer0_counter_edge = TIMER0_COUNTER_FALLING_EDGE_CFG,
    .timer0_register_size = TIMER0_16BIT_REGISTER_MODE,
    .prescaler_enable = TIMER0_PRESCALER_DISABLE_CFG,
    .timer0_preload_value = 0
};

int main() { 
    Std_ReturnType ret = E_NOT_OK;
    
    application_intialize();
    
    ret = Timer0_Init(&timer0_counter_obj);
    ret = led_initialize(&led1);
    
    while(1){
        ret = Timer0_Read_Value(&timer0_counter_obj, &PushButtonCounter);
        if(PushButtonCounter == 5){
            led_turn_on(&led1);
        }
        else{
            led_turn_off(&led1);
        }
    }
    return (EXIT_SUCCESS);
}

void application_intialize(void){
    Std_ReturnType ret = E_NOT_OK;
    ecu_layer_intialize();
}
