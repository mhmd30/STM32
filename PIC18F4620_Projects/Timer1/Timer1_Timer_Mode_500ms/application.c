/* 
 * File:   application.c
 * Author: Mohammed_Elnefary
 * Created on May 20, 2023, 7:59 PM
 */

#include "application.h"
#include "MCAL_Layer/Timer1/hal_timr1.h"

volatile uint16 timer_counter_val;

led_t led1 = {.port_name = PORTC_INDEX, .pin = GPIO_PIN0, .led_status = GPIO_LOW};
timer1_t counter_obj;
uint16 Timer1_Counter_Value = 0;

void Timer1_DefaultInterruptHandler(void){
    led_turn_toggle(&led1);
}

void timer1_timer_init(void){
    Std_ReturnType ret = E_NOT_OK;
    timer1_t timer_obj;
    timer_obj.TMR1_InterruptHandler = Timer1_DefaultInterruptHandler;
    timer_obj.priority = INTERRUPT_LOW_PRIORITY;
    timer_obj.timer1_mode = TIMER1_TIMER_MODE;
    timer_obj.timer1_prescaler_value = TIMER1_PRESCALER_DIV_BY_8;
    timer_obj.timer1_preload_value = 3036;
    timer_obj.timer1_reg_wr_mode = TIMER1_RW_REG_16Bit_MODE;
    ret = Timer1_Init(&timer_obj);
}

void timer1_counter_init(void){
    Std_ReturnType ret = E_NOT_OK;
    counter_obj.TMR1_InterruptHandler = NULL;
    counter_obj.priority = INTERRUPT_LOW_PRIORITY;
    counter_obj.timer1_mode = TIMER1_COUNTER_MODE;
    counter_obj.timer1_prescaler_value = TIMER1_PRESCALER_DIV_BY_1;
    counter_obj.timer1_preload_value = 0;
    counter_obj.timer1_reg_wr_mode = TIMER1_RW_REG_16Bit_MODE;
    counter_obj.timer1_counter_mode = TIMER1_SYNC_COUNTER_MODE;
    ret = Timer1_Init(&counter_obj);
}

void timer1_timer_generate_500KHz(void){
    Std_ReturnType ret = E_NOT_OK;
    timer1_t timer_obj;
    timer_obj.TMR1_InterruptHandler = Timer1_DefaultInterruptHandler;
    timer_obj.priority = INTERRUPT_LOW_PRIORITY;
    timer_obj.timer1_mode = TIMER1_TIMER_MODE;
    timer_obj.timer1_prescaler_value = TIMER1_PRESCALER_DIV_BY_1;
    timer_obj.timer1_preload_value = 64536;
    timer_obj.timer1_reg_wr_mode = TIMER1_RW_REG_16Bit_MODE;
    ret = Timer1_Init(&timer_obj);
}

int main() { 
    Std_ReturnType ret = E_NOT_OK;
    
    application_intialize();
    
    led_initialize(&led1);
    timer1_timer_generate_500KHz();

    while(1){
        //ret = Timer1_Read_Value(&counter_obj, &Timer1_Counter_Value);
    }
    return (EXIT_SUCCESS);
}

void application_intialize(void){
    Std_ReturnType ret = E_NOT_OK;
    ecu_layer_intialize();
}
