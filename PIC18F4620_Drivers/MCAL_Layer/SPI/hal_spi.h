/* 
 * File:   hal_spi.h
 * Author: Mohammed_Elnefary
 *
 * Created on October 25, 2023, 7:46 AM
 */

#ifndef HAL_SPI_H
#define	HAL_SPI_H


/******************************************************************************/
/*                            Includes Section                                */
/******************************************************************************/
#include "pic18f4620.h"
#include "../mcal_std_types.h"
#include "../../MCAL_Layer/GPIO/hal_gpio.h"
#include "../../MCAL_Layer/Interrupt/mcal_internal_interrupt.h"
#include "hal_spi_cfg.h"

/******************************************************************************/
/*                       Macros Declaration Section                           */
/******************************************************************************/
/* EUSART Transmit Interrupt Enable */
#define SPI_INTERRUPT_ENABLE              1
#define SPI_INTERRUPT_DISABLE             0

/*MSSP module configuration for spi module*/
/* SSPSTAT: MSSP STATUS REGISTER (SPI MODE)*/
/*bit 0 BF: Buffer Full Status bit (Receive mode only)*/
#define SPI_Receive_complete              1   //SSPBUF is full
#define SPI_Receive_not_complete          0   //SSPBUF is empty

/*bit 6 CKE: SPI Clock Select bit(1)*/
#define SPI_Transition_Active_To_Idle     1   
#define SPI_Transition_Idle_To_Active     0

/*bit 7 SMP: Sample bit --> SPI Master mode:*/
#define SPI_Sampled_At_End_Of_Data        1
#define SPI_Sampled_At_Middle_Of_Data     0    //SPI Slave mode : SMP must be cleared when SPI is used in Slave mode

/*SSPCON1: MSSP CONTROL REGISTER 1 (SPI MODE)*/
/*bit 4 CKP: Clock Polarity Select bit for idle state*/
#define SPI_Clock_Polarity_High_Level     1
#define SPI_Clock_Polarity_Low_Level      0

 /*bit 5 SSPEN: Master Synchronous Serial Port Enable bit(*/
#define SPI_Enables_Serial_And_Pins       1
#define SPI_Disables_Serial_And_Pins      0

/*bit 6 SSPOV: Receive Overflow Indicator bit --> SPI Slave mode:*/
#define SPI_Overflow_Exist                1
#define SPI_Overflow_Does_not_Exist       0

/*bit 7 WCOL: Write Collision Detect bit*/
#define SPI_Collision_Detect              1
#define SPI_Collision_Does_not_Exist      0

#define Clear_Collision_Flag              0

/******************************************************************************/
/*                  Macro Functions Declaration Section                       */
/******************************************************************************/
#define Spi_Transition_Clock_State(_Selection)      (SSPSTATbits.CKE = _Selection) //@CKE: SPI Clock Select bit --> transition cases
#define Spi_Sampled_Data_time(_Pos)                 (SSPSTATbits.SMP = _Pos)       //@SMP: Sample bit
#define Spi_Mode_Select(_Mode)                      (SSPCON1bits.SSPM = _Mode)     // @spi_mode_select_t
#define Spi_Enable(_Cfg)                            (SSPCON1bits.SSPEN = _Cfg)   //@SSPEN: Master Synchronous Serial Port Enable bit
#define Spi_Clear_Collision_Flag()                  (SSPCON1bits.WCOL = Clear_Collision_Flag)
#define Spi_Clock_Polarity(_polarity)               (SSPCON1bits.CKP =_polarity ) //bit 4 CKP: Clock Polarity Select bit for Idle state

/******************************************************************************/
/*                   Data_Types Declaration Section                           */
/******************************************************************************/
/*SSPCON1: MSSP CONTROL REGISTER 1 (SPI MODE)*/
/*SSPM3:SSPM0: Master Synchronous Serial Port Mode Select bits(3)*/
typedef enum{
SPI_Master_Mode_FOSC_DIV_BY_4 = 0,
SPI_Master_Mode_FOSC_DIV_BY_16,
SPI_Master_Mode_FOSC_DIV_BY_64,
SPI_Master_Mode_TMR2_DIV_BY_2,
SPI_Slave_mode_SS_Enabled,
SPI_Slave_mode_SS_Disabled
}spi_mode_select_t;


typedef struct{
#if MSSP_SPI_INTERRUPT_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE
    void (* SPI_InterruptHandler)(void);
    interrupt_priority_cfg priority;
#endif
    spi_mode_select_t SPI_Selected_Mode;
    uint8 Transition_Clock_State;
    uint8 SPI_Sampled_Data_time1;
    uint8 Clock_Polarity;
}spi_t;
/******************************************************************************/
/*                    functions declaration Section                           */
/******************************************************************************/

Std_ReturnType SPI_Init(const spi_t *_spi);
Std_ReturnType SPI_DeInit(const spi_t *_spi);

Std_ReturnType SPI_ReadByteBlocking(uint8 *_data);
Std_ReturnType SPI_ReadByteNonBlocking(uint8 *_data);

Std_ReturnType SPI_WriteByteBlocking( uint8 _data);
Std_ReturnType SPI_WriteByte_NotBlocking( uint8 _data);
Std_ReturnType SPI_WriteStringBlocking( uint8 *_data , uint8 str_len);
Std_ReturnType SPI_WriteStringNotBlocking( uint8 *_data , uint8 str_len);

#endif	/* HAL_SPI_H */

