/**
 ******************************************************************************
 * @file           : CortexM4_Core_NVIC.c
 * @author         : Mohammed_Elnefary
 * @brief          : contains the static code to control NVIC
 ******************************************************************************
*/

#include "CortexM4_Core_NVIC.h"


/**
 * @brief Enables a specific interrupt in the NVIC peripheral.
 * @param IRQn: Interrupt number to be enabled (IRQn_Type).
 * @note: IRQn must not be negative
 * @return None.
 */
void NVIC_EnableIRQ(IRQn_Type IRQn){

	if((uint32)IRQn >= 0){
		NVIC->ISER[((uint32)IRQn)>>5] = (1UL <<(((uint32)IRQn) & 0x1F));
		/* ((uint32)IRQn)>>5          ==> to get the register index
		   (((uint32)IRQn) & 0x1F)    ==> to get the bit position   */
	}
}

/**
 * @brief Disables a specific interrupt in the NVIC peripheral.
 * @param IRQn: Interrupt number to be disabled (IRQn_Type).
 * @note: IRQn must not be negative
 * @return None.
 */
void NVIC_DisableIRQ(IRQn_Type IRQn){

	if((uint32)IRQn >= 0){
			NVIC->ICER[((uint32)IRQn)>>5] = (1UL <<(((uint32)IRQn) & 0x1F));
			/* ((uint32)IRQn)>>5          ==> to get the register index
			   (((uint32)IRQn) & 0x1F)    ==> to get the bit position   */
		}
}

/**
 * @brief Sets a specific interrupt as pending in the NVIC peripheral.
 * @param IRQn: Interrupt number to be set as pending (IRQn_Type).
 * @return None.
 */
void NVIC_SetPendingIRQ(IRQn_Type IRQn){

	if((uint32)IRQn >= 0){
			NVIC->ISPR[((uint32)IRQn)>>5] = (1UL <<(((uint32)IRQn) & 0x1F));
			/* ((uint32)IRQn)>>5          ==> to get the register index
			   (((uint32)IRQn) & 0x1F)    ==> to get the bit position   */
		}
}

/**
 * @brief Clears the pending status of a specific interrupt in the NVIC peripheral.
 * @param IRQn: Interrupt number for which the pending status needs to be cleared (IRQn_Type).
 * @return None.
 */
void NVIC_ClearPendingIRQ(IRQn_Type IRQn){

	if((uint32)IRQn >= 0){
			NVIC->ICPR[((uint32)IRQn)>>5] = (1UL <<(((uint32)IRQn) & 0x1F));
			/* ((uint32)IRQn)>>5          ==> to get the register index
			   (((uint32)IRQn) & 0x1F)    ==> to get the bit position   */
		}
}

/**
 * @brief : Checks if a specific interrupt is active or being serviced by the CPU.
 * @param IRQn: Interrupt number to check for activity (IRQn_Type).
 * @return 0 if the interrupt is not active, 1 if the interrupt is active.
 */
uint8 NVIC_GetActive(IRQn_Type IRQn){
	if((uint32)IRQn >= 0){
	return ((NVIC->IABR[((uint32)IRQn)>>5] & (1UL <<(((uint32)IRQn) & 0x1F)) != ((uint32)0) ? 1UL : 0UL));
	}
	else{
		return 0;
	}
}


/**
	\ brief Set Interrupt Priority
	\ details Sets the priority of a device specific interrupt or a processor exception.
	  The interrupt number can be positive to specify a device specific interrupt,
	  or negative to specify a processor exception.
	\ param [in] IRQn Interrupt number.
	\ param [in] priority Priority to set.
	\ note The priority cannot be set for every processor exception.
*/
void NVIC_SetPriority(IRQn_Type IRQn, uint32 priority){

	if((uint32)IRQn >= 0){
		NVIC->IP[(uint32)IRQn] = (uint8)((priority << (8 - NVIC_PRIO_BITS)) & (uint32)0xFF);
	}
	else{
		/*nothing*/
	}

}

/**
	\ brief Get Interrupt Priority
	\ details Reads the priority of a device specific interrupt or a processor exception.
	  The interrupt number can be positive to specify a device specific interrupt,
	  or negative to specify a processor exception.
	\ param [in] IRQn Interrupt number.
	\ return Interrupt Priority.
	  Value is aligned automatically to the implemented priority bits of the microcontroller.
*/
uint32 NVIC_GetPriority(IRQn_Type IRQn){

	if((uint32)IRQn >= 0){
			return ((NVIC->IP[(uint32)IRQ]) >> (8U - NVIC_PRIO_BITS));
		}
	return 0;
}




