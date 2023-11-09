/* 
 * File:   application.c
 * Author: Mohammed_Elnefary
 * Created on May 17, 2023, 7:34 AM
 */


#include "application.h"

#include "MCAL_Layer/Timer0/hal_timr0.h"

led_t led1 = {.port_name = PORTC_INDEX, .pin = GPIO_PIN0, .led_status = GPIO_LOW};
led_t led2 = {.port_name = PORTC_INDEX, .pin = GPIO_PIN1, .led_status = GPIO_LOW};

volatile uint8 timer0_250ms = 0, timer0_500ms = 0;

void Timer0_DefaultInterruptHandler(void){
    timer0_250ms = 1;
    timer0_500ms++;
}

timer0_t timer0_timer_obj = {
    .TMR0_InterruptHandler = Timer0_DefaultInterruptHandler,
    .timer0_mode = TIMER0_TIMER_MODE,
    .timer0_register_size = TIMER0_16BIT_REGISTER_MODE,
    .prescaler_enable = TIMER0_PRESCALER_ENABLE_CFG,
    .prescaler_value = TIMER0_PRESCALER_DIV_BY_4,
    .timer0_preload_value = 3036
};

int main() { 
    Std_ReturnType ret = E_NOT_OK;
    
    application_intialize();
    
    ret = Timer0_Init(&timer0_timer_obj);
    ret = led_initialize(&led1);
    ret = led_initialize(&led2);
    
    while(1){
        if(timer0_250ms == 1){
            timer0_250ms = 0;
            led_turn_toggle(&led1);
        }
        else {/* Nothing */}
        
        if(timer0_500ms == 2){
            led_turn_toggle(&led2);
            timer0_500ms = 0;
        }
        else {/* Nothing */}
    }
    return (EXIT_SUCCESS);
}

void application_intialize(void){
    Std_ReturnType ret = E_NOT_OK;
    ecu_layer_intialize();
}


