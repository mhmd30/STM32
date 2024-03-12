 /**
 ******************************************************************************
 * @file           : CortexM4_Core_SCB.h
 * @author         : Mohammed_Elnefary
 * @brief          : contains the declarations to control system block
 ******************************************************************************
*/


#ifndef CORTEXM4_CORE_SCB_H_
#define CORTEXM4_CORE_SCB_H_

/******************************************************************************/
/*                            Includes Section                                */
/******************************************************************************/

#include "Std_Types.h"

/******************************************************************************/
/*                       Macros Declaration Section                           */
/******************************************************************************/

/*memory mapping of core hardware*/
#define SCB_BASE        (0xE000ED00UL)     /*system control block base address*/
#define SCB             ((SCB_Type *)(0xE000ED00UL))

/**
  * @defgroup CORTEX_Preemption_Priority_Group
  */
#define SCB_PRIORITYGROUP_0            0x00000007U /*!< 0 bits for pre-emption priority
                                                        4 bits for subpriority */
#define SCB_PRIORITYGROUP_1            0x00000006U /*!< 1 bits for pre-emption priority
                                                        3 bits for subpriority */
#define SCB_PRIORITYGROUP_2            0x00000005U /*!< 2 bits for pre-emption priority
                                                        2 bits for subpriority */
#define SCB_PRIORITYGROUP_3            0x00000004U /*!< 3 bits for pre-emption priority
                                                        1 bits for subpriority */
#define SCB_PRIORITYGROUP_4            0x00000003U /*!< 4 bits for pre-emption priority
                                                        0 bits for subpriority */


#define SCB_AIRCR_PRIGROUP_Pos         8U          /*!< SCB AIRCR: PRIGROUP Position */
#define SCB_AIRCR_PRIGROUP_MASK        (7UL << SCB_AIRCR_PRIGROUP_Pos)


#define SCB_AIRCR_VECTKEY_Pos      16U         /*!< SCB AIRCR: VECTKEYSTAT Position */
#define SCB_AIRCR_VECTKEY_MASK     (16UL << SCB_AIRCR_VECTKEY_Pos)

/******************************************************************************/
/*                  Macro Functions Declaration Section                       */
/******************************************************************************/


/******************************************************************************/
/*                   Data_Types Declaration Section                           */
/******************************************************************************/

typedef struct
{
    volatile uint32 CPUID;   /*!< Offset: 0x000 (R/ )  CPUID Base Register */
    volatile uint32 ICSR;    /*!< Offset: 0x004 (R/W)  Interrupt Control and State Register */
    volatile uint32 VTOR;    /*!< Offset: 0x008 (R/W)  Vector Table Offset Register */
    volatile uint32 AIRCR;   /*!< Offset: 0x00C (R/W)  Application Interrupt and Reset Control */
    volatile uint32 SCR;     /*!< Offset: 0x010 (R/W)  System Control Register */
    volatile uint32 CCR;     /*!< Offset: 0x014 (R/W)  Configuration Control Register */
    volatile uint32 SHPR1;   /*!< Offset: 0x018 (R/W)  System Handler Priority Register 1 */
    volatile uint32 SHPR2;   /*!< Offset: 0x01C (R/W)  System Handler Priority Register 2 */
    volatile uint32 SHPR3;   /*!< Offset: 0x020 (R/W)  System Handler Priority Register 3 */
    volatile uint32 SHCSR;   /*!< Offset: 0x024 (R/W)  System Handler Control and State Register */
    volatile uint32 CFSR;    /*!< Offset: 0x028 (R/W)  Configurable Fault Status Register */
} SCB_Type;


/******************************************************************************/
/*                    functions declaration Section                           */
/******************************************************************************/

/**
	\brief Set Priority Grouping
	\details Sets the priority grouping field using the required unlock sequence.
	         The parameter PriorityGroup is assigned to the field SCB->AIRCR [10:8] PRIGROUP field.
             Only values from 0..7 are used.
			 In case of a conflict between priority grouping and available
			 grouping and available
	\param [in] PriorityGroup Priority grouping field.
*/
void SCB_SetPriorityGrouping(uint32 PriorityGroup);


/**
 * @ brief   : Get Priority Grouping
 * @ details : Reads the priority grouping field from the NVIC Interrupt Controller
 * @ Return  : Priority grouping field (SCB->AIRCR [10 : 8] PRIGROUP field).
**/
uint32 SCB_GetPriorityGrouping(void);



#endif /* CORTEXM4_CORE_SCB_H_ */
