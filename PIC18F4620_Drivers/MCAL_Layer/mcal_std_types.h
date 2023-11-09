/* 
 * File:   mcal_std_types.h
 * Author: Mohammed_Elnefary
 *
 * Created on April 2, 2023, 5:45 PM
 */

#ifndef MCAL_STD_TYPES_H
#define	MCAL_STD_TYPES_H


/******************************************************************************/
/*                            Includes Section                                */
/******************************************************************************/
#include "std_libraries.h"
#include "compiler.h"



/******************************************************************************/
/*                  Macro Functions Declaration Section                       */
/******************************************************************************/



/******************************************************************************/
/*                   Data_Types Declaration Section                           */
/******************************************************************************/
#if (CPU_TYPE == CPU_TYPE_64)
typedef unsigned char        boolean;
typedef unsigned char        uint8;
typedef unsigned short       uint16;
typedef unsigned int         uint32;
typedef unsigned long long   uint64;
typedef signed char          sint8;
typedef signed short         sint16;
typedef signed int           sint32;
typedef signed long long     sint64;
typedef float                float32;
typedef double               float64;
/*******************************************************/
#elif (CPU_TYPE == CPU_TYPE_32)
typedef unsigned char        boolean;
typedef unsigned char        uint8;
typedef unsigned short       uint16;
typedef unsigned long        uint32;
typedef unsigned long long   uint64;
typedef signed char          sint8;
typedef signed short         sint16;
typedef signed long          sint32;
typedef signed long long     sint64;
typedef float                float32;
typedef double               float64;
/*******************************************************/
#elif (CPU_TYPE == CPU_TYPE_16)
typedef unsigned char        boolean;
typedef unsigned char        uint8;
typedef unsigned short       uint16;
typedef unsigned long        uint32;
typedef unsigned long long   uint64;
typedef signed char          sint8;
typedef signed short         sint16;
typedef signed long          sint32;
typedef signed long long     sint64;
typedef float                float32;
typedef double               float64;
/*******************************************************/
#endif


typedef uint8 Std_ReturnType;


/******************************************************************************/
/*                       Macros Declaration Section                           */
/******************************************************************************/
#define CPU_TYPE_16 16
#define CPU_TYPE_32 32
#define CPU_TYPE_64 64

#define CPU_TYPE (CPU_TYPE_64)  /*based on your configuratoin */


#define STD_HIGH        0x01
#define STD_LOW         0x00

#define STD_ON          0x01
#define STD_OFF         0x00

#define STD_ACTIVE      0x01
#define STD_IDLE        0x00

#define E_OK            (Std_ReturnType)0x01
#define E_NOT_OK        (Std_ReturnType)0x00

#define ZERO_INIT       0



/******************************************************************************/
/*                    functions declaration Section                           */
/******************************************************************************/





#endif	/* MCAL_STD_TYPES_H */

