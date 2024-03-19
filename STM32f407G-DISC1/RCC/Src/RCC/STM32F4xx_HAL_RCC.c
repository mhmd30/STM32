 /**
 ******************************************************************************
 * @file           : STM32F4xx_HAL_RCC.c
 * @author         : Mohammed_Elnefary
 * @brief          : contains the static code to control
 ******************************************************************************
*/

#include "HAL_Drivers/RCC/STM32F4xx_HAL_RCC.h"

Std_ReturnType HAL_RCC_OscConfig(RCC_OscInitType *RCC_OscInitStruct){
	Std_ReturnType Ret_Status = E_OK;
	if(NULL == RCC_OscInitStruct){
		Ret_Status = E_NOT_OK;
	}
	else{
		/************************ HSE Configuration *******************************/
		if(RCC_OSCILLATOR_HSE == RCC_OscInitStruct->RCC_OscType){
			if(RCC_HSE_ON == RCC_OscInitStruct->HSEState){
				SET_BIT(RCC->CR , RCC_CR_HSEON_MASK);
			}
			else{
				CLEAR_BIT(RCC->CR , RCC_CR_HSEON_MASK);
			}
		}
		/************************ HSI Configuration *******************************/
		else if(RCC_OSCILLATOR_HSI == RCC_OscInitStruct->RCC_OscType){
			if(RCC_HSI_ON == RCC_OscInitStruct->HSIState){

			}
			else{

			}

		}
		/************************ LSE Configuration *******************************/
		else if(RCC_OSCILLATOR_LSE == RCC_OscInitStruct->RCC_OscType){
			if(RCC_LSE_ON == RCC_OscInitStruct->LSEState){

			}
			else{

			}

		}
		/************************ LSI Configuration *******************************/
		else if(RCC_OSCILLATOR_LSI == RCC_OscInitStruct->RCC_OscType){
			if(RCC_LSI_ON == RCC_OscInitStruct->LSIState){

			}
			else{

			}

		}
		else{
			/*no thing*/
		}
	}

	return Ret_Status ;
}


Std_ReturnType HAL_RCC_ClockConfig(RCC_CLKInit_t *RCC_CLKInitStruct){
	Std_ReturnType Ret_Status = E_OK;
	if(NULL == RCC_CLKInitStruct){
			Ret_Status = E_NOT_OK;
	}
	else{

		MODIFY_REG(RCC->CFGR , RCC_CFGR_HPRE_MASK , RCC_CLKInitStruct->AHBCLKDivider);
		MODIFY_REG(RCC->CFGR , RCC_CFGR_PPRE1_MASK , RCC_CLKInitStruct->APB1CLKDivider);
		MODIFY_REG(RCC->CFGR , RCC_CFGR_PPRE2_MASK , RCC_CLKInitStruct->APB2CLKDivider);
	}

	return Ret_Status ;
}






