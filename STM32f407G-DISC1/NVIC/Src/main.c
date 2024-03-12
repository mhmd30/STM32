/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Mohammed_Elnefary
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2024 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include <stdint.h>
#include <stdio.h>
#include "CortexM4_Core_NVIC.h"
#include "CortexM4_Core_SCB.h"

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif




uint32 USART3_IRQHandler_Flag = 0 , USART3_IRQHandler_Active_Flag2 = 0;
uint32 EXTI15_10_IRQHandler_Flag =0;


int main(void)
{
	SCB_SetPriorityGrouping(SCB_PRIORITYGROUP_2);
	NVIC_EnableIRQ(USART3_IRqn);
	NVIC_EnableIRQ(EXTI15_10_IRqn);

	NVIC_SetPriority(USART3_IRqn, 4);
	NVIC_SetPriority(EXTI15_10_IRqn, 1);


	NVIC_SetPendingIRQ(USART3_IRqn);

    /* Loop forever */
	while(1){


	}
}



void USART3_IRQHandler(void){
	USART3_IRQHandler_Flag = 1;
	//USART3_IRQHandler_Active_Flag2 = NVIC_GetActive(USART3_IRqn);
	NVIC_SetPendingIRQ(EXTI15_10_IRqn);
	USART3_IRQHandler_Flag = 2;
}

void EXTI15_10_IRQHandler(void){
	EXTI15_10_IRQHandler_Flag = 1;


}

