 /**
 ******************************************************************************
 * @file           : CortexM4_Core_SCB.c
 * @author         : Mohammed_Elnefary
 * @brief          : contains the static code to control system block
 ******************************************************************************
*/


#include "CortexM4_Core_SCB.h"

/**
	\brief Set Priority Grouping
	\details Sets the priority grouping field using the required unlock sequence.
	         The parameter PriorityGroup is assigned to the field SCB->AIRCR [10:8] PRIGROUP field.
             Only values from 0..7 are used.
			 In case of a conflict between priority grouping and available
			 grouping and available
	\param [in] PriorityGroup Priority grouping field.
	\Note: The vector key (0x5FA) must be written to the AIRCR to allow write access.
*/
void SCB_SetPriorityGrouping(uint32 PriorityGroup)
{
    uint32 Register_Value = 0;

    uint32 PriorityGroupTemp = ((uint32)PriorityGroup & (uint32)0x07);

    Register_Value = SCB->AIRCR;

    Register_Value &= ~((uint32)SCB_AIRCR_PRIGROUP_MASK | SCB_AIRCR_VECTKEY_MASK);

    Register_Value = (Register_Value | ((uint32)0x5FA << SCB_AIRCR_VECTKEY_Pos) |
                     (PriorityGroupTemp << SCB_AIRCR_PRIGROUP_Pos));

    SCB->AIRCR = Register_Value;
}


/**
 * @ brief   : Get Priority Grouping
 * @ details : Reads the priority grouping field from the NVIC Interrupt Controller
 * @ Return  : Priority grouping field (SCB->AIRCR [10 : 8] PRIGROUP field).
**/
uint32 SCB_GetPriorityGrouping(void){
	return (((uint32)SCB->AIRCR & (uint32)SCB_AIRCR_PRIGROUP_MASK) >> SCB_AIRCR_PRIGROUP_Pos);

}






