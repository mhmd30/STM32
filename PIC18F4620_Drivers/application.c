/* 
 * File:   application.c
 * Author: Mohammed_Elnefary 
 * Created on April 2, 2023, 5:25 PM
 */
#include "application.h"

/* porta pin0 --> led1*/



int main() { 
    Std_ReturnType ret = E_NOT_OK;
    application_intialize();

    while(1){
        
    }
    return (EXIT_SUCCESS);
}

void application_intialize(void){
    Std_ReturnType ret = E_NOT_OK;
    ecu_layer_intialize();
}
