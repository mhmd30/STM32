 /**
 ******************************************************************************
 * @file           : Bit_Math.h
 * @author         : Mohammed_Elnefary
 * @brief          : contains the Bit Manipulation Macros
 ******************************************************************************
*/
#ifndef COMMON_BIT_MATH_H_
#define COMMON_BIT_MATH_H_


/******************************************************************************/
/*                            Includes Section                                */
/******************************************************************************/



/******************************************************************************/
/*                       Macros Declaration Section                           */
/******************************************************************************/

#define SET_BIT(REG,BITN)       ((REG) |= (1<<BITN))       // Sets a bit (bitN) in a register (reg)
#define CLEAR_BIT(REG,BITN)     ((REG) &= ~(1<<BITN))      // Clears a bit (bitN) in a register (reg)
#define TOGGlE_BIT(REG,BITN)    ((REG) ^= (1<<BITN))       // Toggles a bit (bitN) in a register (reg)
#define GET_BIT(REG,BITN)       (1 & ((REG)>>BITN))        // Returns value of bit (bitN) in a register (reg)

#define READ_REG(REG)           (REG)
#define WRITE_REG(REG , VAL)    (REG = VAL)
#define MODIFY_REG(REG, CLEARMASK , SETMASK)       (WRITE_REG((REG) , (((READ_REG(REG)) & (~(CLEARMASK))) | (SETMASK))))



#endif /* COMMON_BIT_MATH_H_ */
