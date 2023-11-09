/* 
 * File:   application.c
 * Author: Mohammed_Elnefary
 * Created on June 5, 2023, 9:29 PM
 */


#include "application.h"

#include "MCAL_Layer/CCP/hal_ccp.h"
#include "MCAL_Layer/Timer2/hal_timr2.h"

timer2_t timer2_obj;
ccp_t ccp1_obj;
ccp_t ccp2_obj;

uint8 CCP1_PWM1_Duty = 0;

int main() { 
    Std_ReturnType ret = E_NOT_OK;
    
    application_intialize();
    
    ccp1_obj.ccp_inst = CCP1_INST;
    ccp1_obj.CCP1_InterruptHandler = NULL;
    ccp1_obj.ccp_mode = CCP_PWM_MODE_SELECTED;
    ccp1_obj.PWM_Frequency = 20000;
    ccp1_obj.ccp_pin.port = PORTC_INDEX;
    ccp1_obj.ccp_pin.pin = GPIO_PIN2;
    ccp1_obj.ccp_pin.direction = GPIO_DIRECTION_OUTPUT;
    ccp1_obj.timer2_prescaler_value = CCP_TIMER2_PRESCALER_DIV_BY_1;
    ccp1_obj.timer2_postscaler_value = CCP_TIMER2_POSTSCALER_DIV_BY_1;
    ret = CCP_Init(&ccp1_obj);
    
    ccp2_obj.ccp_inst = CCP2_INST;
    ccp2_obj.CCP1_InterruptHandler = NULL;
    ccp2_obj.ccp_mode = CCP_PWM_MODE_SELECTED;
    ccp2_obj.PWM_Frequency = 20000;
    ccp2_obj.ccp_pin.port = PORTC_INDEX;
    ccp2_obj.ccp_pin.pin = GPIO_PIN1;
    ccp2_obj.ccp_pin.direction = GPIO_DIRECTION_OUTPUT;
    ccp2_obj.timer2_prescaler_value = CCP_TIMER2_PRESCALER_DIV_BY_1;
    ccp2_obj.timer2_postscaler_value = CCP_TIMER2_POSTSCALER_DIV_BY_1;
    ret = CCP_Init(&ccp2_obj);
    
    timer2_obj.TMR2_InterruptHandler = NULL;
    timer2_obj.timer2_prescaler_value = TIMER2_PRESCALER_DIV_BY_1;
    timer2_obj.timer2_postscaler_value = TIMER2_POSTSCALER_DIV_BY_1;
    timer2_obj.timer2_preload_value = 0;
    ret = Timer2_Init(&timer2_obj);
    
    ret = CCP_PWM_Set_Duty(&ccp1_obj, 50);
    ret = CCP_PWM_Set_Duty(&ccp2_obj, 75);
    
    ret = CCP_PWM_Start(&ccp1_obj);
    ret = CCP_PWM_Start(&ccp2_obj);

    while(1){
        /*
        for(CCP1_PWM1_Duty=0; CCP1_PWM1_Duty<100; CCP1_PWM1_Duty+=5){
            __delay_ms(5);
            ret = CCP_PWM_Set_Duty(&ccp1_obj, CCP1_PWM1_Duty);
        }*/
    }
    return (EXIT_SUCCESS);
}

void application_intialize(void){
    Std_ReturnType ret = E_NOT_OK;
    ecu_layer_intialize();
}
