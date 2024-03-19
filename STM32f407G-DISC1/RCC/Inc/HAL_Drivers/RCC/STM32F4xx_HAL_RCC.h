 /**
 ******************************************************************************
 * @file           : STM32F4xx_HAL_RCC.h
 * @author         : Mohammed_Elnefary
 * @brief          : contains the static code to control
 ******************************************************************************
*/

#ifndef HAL_DRIVERS_RCC_STM32F4XX_HAL_RCC_H_
#define HAL_DRIVERS_RCC_STM32F4XX_HAL_RCC_H_


/******************************************************************************/
/*                            Includes Section                                */
/******************************************************************************/

#include "HAL_Drivers/STM32F4xx_Reg_Def.h"

/******************************************************************************/
/*                       Macros Declaration Section                           */
/******************************************************************************/

/*@defgroup RCC_AHB_CLOCK_SOURCES AHB Clock Sources*/
#define RCC_SYSCLK_DIV1       RCC_CFGR_HPRE_DIV1
#define RCC_SYSCLK_DIV2       RCC_CFGR_HPRE_DIV2
#define RCC_SYSCLK_DIV4       RCC_CFGR_HPRE_DIV4
#define RCC_SYSCLK_DIV8       RCC_CFGR_HPRE_DIV8
#define RCC_SYSCLK_DIV16      RCC_CFGR_HPRE_DIV16
#define RCC_SYSCLK_DIV64      RCC_CFGR_HPRE_DIV64
#define RCC_SYSCLK_DIV128     RCC_CFGR_HPRE_DIV128
#define RCC_SYSCLK_DIV256     RCC_CFGR_HPRE_DIV256
#define RCC_SYSCLK_DIV512     RCC_CFGR_HPRE_DIV512

/*@defgroup RCC_APB1_APB2_CLOCK_SOURCES APB/APB2 Clock Sources*/
#define RCC_HCLK_APB1_DIV1         RCC_CFGR_PPRE1_DIV1
#define RCC_HCLK_APB1_DIV2         RCC_CFGR_PPRE1_DIV2
#define RCC_HCLK_APB1_DIV4         RCC_CFGR_PPRE1_DIV4
#define RCC_HCLK_APB1_DIV8         RCC_CFGR_PPRE1_DIV8
#define RCC_HCLK_APB1_DIV16        RCC_CFGR_PPRE1_DIV16

#define RCC_HCLK_APB2_DIV1         RCC_CFGR_PPRE2_DIV1
#define RCC_HCLK_APB2_DIV2         RCC_CFGR_PPRE2_DIV2
#define RCC_HCLK_APB2_DIV4         RCC_CFGR_PPRE2_DIV4
#define RCC_HCLK_APB2_DIV8         RCC_CFGR_PPRE2_DIV8
#define RCC_HCLK_APB2_DIV16        RCC_CFGR_PPRE2_DIV16

/******************************************************************************/
/*                  Macro Functions Declaration Section                       */
/******************************************************************************/



#define HAL_RCC_GPIOA_CLK_ENABLE()      (SET_BIT(RCC->AHB1ENR , RCC_AHB1ENR_GPIOAEN_MASK))
#define HAL_RCC_GPIOB_CLK_ENABLE()      (SET_BIT(RCC->AHB1ENR , RCC_AHB1ENR_GPIOBEN_MASK))
#define HAL_RCC_GPIOC_CLK_ENABLE()      (SET_BIT(RCC->AHB1ENR , RCC_AHB1ENR_GPIOCEN_MASK))
#define HAL_RCC_GPIOD_CLK_ENABLE()      (SET_BIT(RCC->AHB1ENR , RCC_AHB1ENR_GPIODEN_MASK))
#define HAL_RCC_GPIOE_CLK_ENABLE()      (SET_BIT(RCC->AHB1ENR , RCC_AHB1ENR_GPIOEEN_MASK))
#define HAL_RCC_GPIOF_CLK_ENABLE()      (SET_BIT(RCC->AHB1ENR , RCC_AHB1ENR_GPIOFEN_MASK))
#define HAL_RCC_GPIOG_CLK_ENABLE()      (SET_BIT(RCC->AHB1ENR , RCC_AHB1ENR_GPIOGEN_MASK))
#define HAL_RCC_GPIOH_CLK_ENABLE()      (SET_BIT(RCC->AHB1ENR , RCC_AHB1ENR_GPIOHEN_MASK))
#define HAL_RCC_GPIOI_CLK_ENABLE()      (SET_BIT(RCC->AHB1ENR , RCC_AHB1ENR_GPIOIEN_MASK))



#define HAL_RCC_GPIOA_CLK_DISABLE()     (CLEAR_BIT(RCC->AHB1ENR , RCC_AHB1ENR_GPIOAEN_MASK))
#define HAL_RCC_GPIOB_CLK_DISABLE()     (CLEAR_BIT(RCC->AHB1ENR , RCC_AHB1ENR_GPIOBEN_MASK))
#define HAL_RCC_GPIOC_CLK_DISABLE()     (CLEAR_BIT(RCC->AHB1ENR , RCC_AHB1ENR_GPIOCEN_MASK))
#define HAL_RCC_GPIOD_CLK_DISABLE()     (CLEAR_BIT(RCC->AHB1ENR , RCC_AHB1ENR_GPIODEN_MASK))
#define HAL_RCC_GPIOE_CLK_DISABLE()     (CLEAR_BIT(RCC->AHB1ENR , RCC_AHB1ENR_GPIOEEN_MASK))
#define HAL_RCC_GPIOF_CLK_DISABLE()     (CLEAR_BIT(RCC->AHB1ENR , RCC_AHB1ENR_GPIOFEN_MASK))
#define HAL_RCC_GPIOG_CLK_DISABLE()     (CLEAR_BIT(RCC->AHB1ENR , RCC_AHB1ENR_GPIOGEN_MASK))
#define HAL_RCC_GPIOH_CLK_DISABLE()     (CLEAR_BIT(RCC->AHB1ENR , RCC_AHB1ENR_GPIOHEN_MASK))
#define HAL_RCC_GPIOI_CLK_DISABLE()     (CLEAR_BIT(RCC->AHB1ENR , RCC_AHB1ENR_GPIOIEN_MASK))






/******************************************************************************/
/*                   Data_Types Declaration Section                           */
/******************************************************************************/

typedef enum {
	RCC_OSCILLATOR_NONE = 0x00000000U,
	RCC_OSCILLATOR_HSE,
	RCC_OSCILLATOR_HSI,
	RCC_OSCILLATOR_LSE,
	RCC_OSCILLATOR_LSI,
}RCC_OSCILLATOR_Types_t;



typedef struct{
	RCC_OSCILLATOR_Types_t RCC_OscType;        /*@ref : RCC_OSCILLATOR_Types_t*/
	uint32 HSEState;                           /*@ref : @defgroup RCC_HSE_CONFIG HSE CONFIG*/
	uint32 LSEState;                           /*@ref : @defgroup RCC_LSE_CONFIG LSE CONFIG*/
	uint32 HSIState;                           /*@ref : @defgroup RCC_HSI_CONFIG HSI CONFIG*/
	uint32 LSIState;                           /*@ref : @defgroup RCC_LSI_CONFIG LSI CONFIG*/
}RCC_OscInitType;



typedef struct {
	uint32 AHBCLKDivider;       /* the AHB clock (HCLK) divider. this clock is derived from the system clock (SYSCLK)
	                             * @ref : RCC_AHB_CLOCK_Source */
	uint32 APB1CLKDivider;      /* the APB1 clock (PCLK1) divider. this clock is derived from the system clock (SYSCLK)
	                             * @ref : RCC_APB1_CLOCK_Source */
	uint32 APB2CLKDivider;      /* the APB2 clock (PCLK1) divider. this clock is derived from the system clock (SYSCLK)
	                             * @ref : RCC_APB2_CLOCK_Source */
}RCC_CLKInit_t;


/******************************************************************************/
/*                    functions declaration Section                           */
/******************************************************************************/
Std_ReturnType HAL_RCC_OscConfig(RCC_OscInitType *RCC_OscInitStruct);
Std_ReturnType HAL_RCC_ClockConfig(RCC_CLKInit_t *RCC_CLKInitStruct);


#endif /* HAL_DRIVERS_RCC_STM32F4XX_HAL_RCC_H_ */
