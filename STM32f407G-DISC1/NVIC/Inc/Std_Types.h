/**
 ******************************************************************************
 * @file           : CortexM4_Core_NVIC.h
 * @author         : Mohammed_Elnefary
 * @brief          : contains the standard types
 ******************************************************************************
*/

#ifndef STD_TYPES_H_
#define STD_TYPES_H_
/******************************************************************************/
/*                            Includes Section                                */
/******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
/******************************************************************************/
/*                       Macros Declaration Section                           */
/******************************************************************************/



/******************************************************************************/
/*                  Macro Functions Declaration Section                       */
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
/*                   Data_Types Declaration Section                           */
/******************************************************************************/

typedef unsigned char  Std_ReturnType;

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



/******************************************************************************/
/*                    functions declaration Section                           */
/******************************************************************************/


#endif /* STD_TYPES_H_ */
