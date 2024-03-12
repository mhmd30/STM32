/**
 ******************************************************************************
 * @file           : CortexM4_Core_NVIC.h
 * @author         : Mohammed_Elnefary
 * @brief          : contains the static code to control NVIC
 ******************************************************************************
*/

#ifndef CORTEXM4_CORE_NVIC_H_
#define CORTEXM4_CORE_NVIC_H_

/******************************************************************************/
/*                            Includes Section                                */
/******************************************************************************/
#include "Std_Types.h"


/******************************************************************************/
/*                       Macros Declaration Section                           */
/******************************************************************************/

#define NVIC_BASE		(0xE000E100UL)
#define NVIC            ((NVIC_Type*)NVIC_BASE)

#define NVIC_PRIO_BITS  4U                           /*STM32FXX uses 4 Bits for the priority levels*/


/******************************************************************************/
/*                  Macro Functions Declaration Section                       */
/******************************************************************************/


/******************************************************************************/
/*                   Data_Types Declaration Section                           */
/******************************************************************************/

typedef enum
{
    /***** Cortex-M4 Processor Exceptions Numbers *****/
    NonMaskableInt_IRQn          = -14,    /*!< 2 Non Maskable Interrupt */
    MemoryManagement_IRQn        = -12,    /*!< 4 Cortex-M4 Memory Management Interrupt */
    BusFault_IRQn                = -11,    /*!< 5 Cortex-M4 Bus Fault Interrupt */
    UsageFault_IRQn              = -10,    /*!< 6 Cortex-M4 Usage Fault Interrupt */
    SVCall_IRQn                  = -5,     /*!< 11 Cortex-M4 SV Call Interrupt */
    DebugMonitor_IRQn            = -4,     /*!< 12 Cortex-M4 Debug Monitor Interrupt */
    PendSV_IRQn                  = -2,     /*!< 14 Cortex-M4 Pend SV Interrupt */
    SysTick_IRQn                 = -1,     /*!< 15 Cortex-M4 System Tick Interrupt */


	/***** STM32 specific Interrupt Numbers *****/
	WWDTG_IRQn                   =0,       /* Window Watchdog interrupt*/
	PVD_IRQn                     =1,       /* PVD through EXTI line detection interrupt*/
	TAMP_STAMP_IRQn              =2,	   /* Tamper and TimeStamp interrupts through the EXTI line*/
	RTC_WKUP_IRQn                =3,       /* RTC Wakeup interrupt through the EXTI line*/
	FLASH_IRGn                   =3,       /* Flash global interrupt*/
	RCC_IRGn                     =5,       /* RCC global interrupt*/
	EXTI0_IRGn                   =6,       /* EXTI Line0 interrupt*/
	EXTI1_IRQn                   =7,       /* EXTI Line1 Interrupt */
	EXTI2_IRQn                   =8,       /* EXTI Line2 Interrupt */
	EXTI3_IRQn                   =9,       /* EXTI Line3 Interrupt */
	EXTI4_IRQn                   =10,      /* EXTI Line4 Interrupt */
	DMA1_Stream0_IRQn            =11,      /* DMA1 Stream 0 global Interrupt */
	DMA1_Stream1_IRQn            =12,      /* DMA1 Stream 1 global Interrupt */
	DMA1_Stream2_IRQn            =13,      /* DMA1 Stream 2 global Interrupt */
	DMA1_Stream3_IRQn            =14,      /* DMA1 Stream 3 global interrupt */
	DMA1_Stream4_IRQn            =15,      /* DMA1 Stream 4 global interrupt */
	DMA1_Stream5_IRQn            =16,      /* DMA1 Stream 5 global interrupt */
	DMA1_Stream6_IRQn            =17,      /* DMA1 Stream 6 global interrupt */
	ADC_IRQn                     =18,      /* ADC1, ADC2 and ADC3 global interrupts */
	CANl_TX_IRQn                 =19,      /* CAN1 TX interrupts */
	CANl_RX0_IRQn                =20,      /* CAN1 RX0 interrupts */
	CANl_RXl_IRQn                =21,      /* CAN1 RX1 interrupt */
	CANl_SCE_IRQn                =22,      /* CAN1 SCE interrupt */
	EXTl9_5_IRGn                 =23,      /* EXTI Line[9:5] interrupts */
	TIMl_BRK_TIM9_IRGn           =24,      /* TIM1 Break interrupt and TIM9 global interrupt */
	TIMl_UP_TIM10_IRGn           =25,      /* TIM1 Update interrupt and TIM10 global interrupt*/
	TIM_TRG_COM_TIMll_IRGn       =26,      /*TIM1 Trigger and Commutation interrupts and TIM11 global interrupt*/
	TIM1_CC_IRQn                 =27,      /* TIM1 Capture Compare Interrupt */
	TIM2_IRQn                    =28,      /* TIM2 global Interrupt */
	TIM3_IRQn                    =29,      /* TIM3 global Interrupt */
	TIM4_IRQn                    =30,      /* TIM4 global Interrupt */
	I2C1_EV_IRQn                 =31,      /* I2C1 Event Interrupt */
	I2C1_ER_IRQn                 =32,      /* I2C1 Error Interrupt */
	I2C2_EV_IRQn                 =33,      /* I2C2 Event Interrupt */
	I2C2_ER_IRQn                 =34,      /* I2C2 Error Interrupt */
	SPI1_IRQn                    =35,      /* SPI1 global Interrupt */
	SPI12_IRqn                   =36,      /**/
	USART1_IRqn                 =37,      /**/
	USART2_IRqn                 =38,      /**/
	USART3_IRqn                 =39,      /**/
	EXTI15_10_IRqn               =40,      /**/
	RTC_Alarm_IRQn               =41,      /**/
	OTG_FS_WKUP_IRQn             =42,      /**/
	TIM8_BRK_TIM12_IRQn          =43,      /**/
	TIM8_UP_TIM13_IRQn           =44,      /**/
	TIM8_TRG_COM_TIM14_IRQn      =45,      /**/
	TIM8_CC_IRQn                 =46,      /**/
	DMA1_Stream7_IRQn            =47,      /**/
	FSMC_IRQn                    =48,      /**/
	SDIO_IRQn                    =49,      /**/
	TIM5_IRQn                    =50,      /**/
	SPI3_IRQn                    =51,      /**/
	UART4_IRQn                   =52,      /**/
	UART5_IRQn                   =53,      /**/
	TIM6_DAC_IRQn                =54,      /**/
	TIM7_IRQn                    =55,      /**/
	DMA2_Stream0_IRqn            =56,      /**/
	DMA2_Stream1_IRqn            =57,      /**/
	DMA2_Stream2_IRqn            =58,      /**/
	DMA2_Stream3_IRqn            =59,      /**/
	DMA2_Stream4_IRqn            =60,      /**/
	ETH_IRqn                     =61,      /**/
	ETH_WKUP_IRQn                =62,      /**/
	CAN2_TX_IRQn                 =63,      /**/
	CAN2_RX0_IRQn                =64,      /**/
	CAN2_RX1_IRQn                =65,      /**/
	CAN2_SCE_IRQn                =66,      /**/
	OTG_FS_IRQn                  =67,      /**/
	DMA2_Stream5_IRQn            =68,      /**/
	DMA2_Stream6_IRQn            =69,      /**/
	DMA2_Stream7_IRQn            =70,      /**/
	USART6_IRQn                  =71,      /**/
	I2C3_EV_IRQn                 =72,      /**/
	I2C3_ER_IRQn                 =73,      /**/
	OTG_HS_EP1_OUT_IRQn          =74,      /**/
	OTG_HS_EP1_IN_IRqn           =75,      /**/
	OTG_HS_WKUP_IRqn             =76,      /**/
	OTG_HS_IRqn                  =77,      /**/
	DCMI_IRqn                    =78,      /**/
	DCMI_IRQn                    =78,      /*!< DCMI global interrupt */
	RNG_IRQn                     =80,      /*!< RNG global Interrupt */
	FPU_IRQn                     =81       /*!< FPU global interrupt */

} IRQn_Type;


/**
\brief Structure type to access the Nested Vectored Interrupt Controller (NVIC).
*/
typedef struct
{
    volatile uint32 ISER[8U];     /*!< Offset: 0x000 (R/W)  Interrupt Set Enable Register */
    uint32 RESERVED0[24U];
    volatile uint32 ICER[8U];     /*!< Offset: 0x080 (R/W)  Interrupt Clear Enable Register */
    uint32 RESERVED1[24U];
    volatile uint32 ISPR[8U];     /*!< Offset: 0x100 (R/W)  Interrupt Set Pending Register */
    uint32 RESERVED2[24U];
    volatile uint32 ICPR[8U];     /*!< Offset: 0x180 (R/W)  Interrupt Clear Pending Register */
    uint32 RESERVED3[24U];
    volatile uint32 IABR[8U];     /*!< Offset: 0x200 (R/W)  Interrupt Active bit Register */
    uint32 RESERVED4[56U];
    volatile uint8 IP[240U];      /*!< Offset: 0x300 (R/W)  Interrupt Priority Register (8Bit wide) */
    uint32 RESERVED5[644U];
	volatile uint32 STIR;	        /*!< Offset:	0xE00	(W) Software Trigger	Interrupt	Register */
} NVIC_Type;

/******************************************************************************/
/*                    functions declaration Section                           */
/******************************************************************************/

/**
 * @brief Enables a specific interrupt in the NVIC peripheral.
 * @param IRQn: Interrupt number to be enabled (IRQn_Type).
 * @note: IRQn must not be negative
 * @return None.
 */
void NVIC_EnableIRQ(IRQn_Type IRQn);

/**
 * @brief Disables a specific interrupt in the NVIC peripheral.
 * @param IRQn: Interrupt number to be disabled (IRQn_Type).
 * @note: IRQn must not be negative
 * @return None.
 */
void NVIC_DisableIRQ(IRQn_Type IRQn);

/**
 * @brief Sets a specific interrupt as pending in the NVIC peripheral.
 * @param IRQn: Interrupt number to be set as pending (IRQn_Type).
 * @return None.
 */
void NVIC_SetPendingIRQ(IRQn_Type IRQn);

/**
 * @brief Clears the pending status of a specific interrupt in the NVIC peripheral.
 * @param IRQn: Interrupt number for which the pending status needs to be cleared (IRQn_Type).
 * @return None.
 */
void NVIC_ClearPendingIRQ(IRQn_Type IRQn);

/**
 * @brief Checks if a specific interrupt is active or being serviced by the CPU.
 * @param IRQn: Interrupt number to check for activity (IRQn_Type).
 * @return 0 if the interrupt is not active, 1 if the interrupt is active.
 */
uint8 NVIC_GetActive(IRQn_Type IRQn);


/**
	\ brief Set Interrupt Priority
	\ details Sets the priority of a device specific interrupt or a processor exception.
	  The interrupt number can be positive to specify a device specific interrupt,
	  or negative to specify a processor exception.
	\ param [in] IRQn Interrupt number.
	\ param [in] priority Priority to set.
	\ note The priority cannot be set for every processor exception.
*/
void NVIC_SetPriority(IRQn_Type IRQn, uint32 priority);

/**
	\ brief Get Interrupt Priority
	\ details Reads the priority of a device specific interrupt or a processor exception.
	  The interrupt number can be positive to specify a device specific interrupt,
	  or negative to specify a processor exception.
	\ param [in] IRQn Interrupt number.
	\ return Interrupt Priority.
	  Value is aligned automatically to the implemented priority bits of the microcontroller.
*/
uint32 NVIC_GetPriority(IRQn_Type IRQn);

#endif /* CORTEXM4_CORE_NVIC_H_ */
