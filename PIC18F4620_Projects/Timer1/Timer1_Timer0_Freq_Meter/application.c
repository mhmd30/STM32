/* 
 * File:   application.c
 * Author: Mohammed_Elnefary
 * Created on May 20, 2023, 7:59 PM
 */

#include "application.h"
#include "MCAL_Layer/Timer0/hal_timr0.h"
#include "MCAL_Layer/Timer1/hal_timr1.h"

void Timer0_DefaultInterruptHandler(void);
void Timer1_DefaultInterruptHandler(void);

volatile uint16 Freq = 0;

timer1_t timer1_counter_obj = {
    .TMR1_InterruptHandler = Timer1_DefaultInterruptHandler,
    .priority = INTERRUPT_LOW_PRIORITY,
    .timer1_mode = TIMER1_COUNTER_MODE,
    .timer1_prescaler_value = TIMER1_PRESCALER_DIV_BY_1,
    .timer1_preload_value = 0,
    .timer1_reg_wr_mode = TIMER1_RW_REG_16Bit_MODE,
    .timer1_counter_mode = TIMER1_SYNC_COUNTER_MODE
};

timer0_t timer0_timer_obj = {
    .TMR0_InterruptHandler = Timer0_DefaultInterruptHandler,
    .timer0_mode = TIMER0_TIMER_MODE,
    .timer0_register_size = TIMER0_16BIT_REGISTER_MODE,
    .prescaler_enable = TIMER0_PRESCALER_ENABLE_CFG,
    .prescaler_value = TIMER0_PRESCALER_DIV_BY_16,
    .timer0_preload_value = 3036
    
};

int main() { 
    Std_ReturnType ret = E_NOT_OK;
    
    application_intialize();
    
    ret = Timer0_Init(&timer0_timer_obj);
    ret = Timer1_Init(&timer1_counter_obj);

    while(1){
        
    }
    return (EXIT_SUCCESS);
}

void application_intialize(void){
    Std_ReturnType ret = E_NOT_OK;
    ecu_layer_intialize();
}

void Timer0_DefaultInterruptHandler(void){
    Std_ReturnType ret = E_NOT_OK;
    ret = Timer1_Read_Value(&timer1_counter_obj, &Freq);
    ret = Timer1_Write_Value(&timer1_counter_obj, 0x00);
}

void Timer1_DefaultInterruptHandler(void){
    
}