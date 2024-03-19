/**
 ******************************************************************************
 * @file           : STM32F4xx_Reg_Def.h
 * @author         : Mohammed_Elnefary
 * @brief          : contains the Data Structure and the address mapping for all peripherals
 ******************************************************************************
*/


#ifndef HAL_DRIVERS_STM32F4XX_REG_DEF_H_
#define HAL_DRIVERS_STM32F4XX_REG_DEF_H_



/******************************************************************************/
/*                            Includes Section                                */
/******************************************************************************/
#include <Common/Std_Types.h>
#include <Common/Bit_Math.h>
/******************************************************************************/
/*                       Macros Declaration Section                           */
/******************************************************************************/

/*peripheral memory map*/
#define PERIPH_BASE      0x40000000UL     /* Peripheral base address in the alias region */
#define AHB1PERIPH_BASE  (PERIPH_BASE + 0x00020000UL)
#define RCC_BASE         (AHB1PERIPH_BASE + 0x3800UL)
#define RCC              ((RCC_t *)RCC_BASE)



/***************** Bit definition for RCC_AHB1ENR Register *****************/
#define RCC_AHB1ENR_GPIOAEN_POS        (0U)
#define RCC_AHB1ENR_GPIOAEN_MASK       (0x1UL << RCC_AHB1ENR_GPIOAEN_POS)

#define RCC_AHB1ENR_GPIOBEN_POS        (1U)
#define RCC_AHB1ENR_GPIOBEN_MASK       (0x1UL << RCC_AHB1ENR_GPIOBEN_POS)

#define RCC_AHB1ENR_GPIOCEN_POS        (2U)
#define RCC_AHB1ENR_GPIOCEN_MASK       (0x1UL << RCC_AHB1ENR_GPIOCEN_POS)

#define RCC_AHB1ENR_GPIODEN_POS        (3U)
#define RCC_AHB1ENR_GPIODEN_MASK       (0x1UL << RCC_AHB1ENR_GPIODEN_POS)

#define RCC_AHB1ENR_GPIOEEN_POS        (4U)
#define RCC_AHB1ENR_GPIOEEN_MASK       (0x1UL << RCC_AHB1ENR_GPIOEEN_POS)

#define RCC_AHB1ENR_GPIOFEN_POS        (5U)
#define RCC_AHB1ENR_GPIOFEN_MASK       (0x1UL << RCC_AHB1ENR_GPIOFEN_POS)

#define RCC_AHB1ENR_GPIOGEN_POS        (6U)
#define RCC_AHB1ENR_GPIOGEN_MASK       (0x1UL << RCC_AHB1ENR_GPIOGEN_POS)

#define RCC_AHB1ENR_GPIOHEN_POS        (7U)
#define RCC_AHB1ENR_GPIOHEN_MASK       (0x1UL << RCC_AHB1ENR_GPIOHEN_POS)

#define RCC_AHB1ENR_GPIOIEN_POS        (8U)
#define RCC_AHB1ENR_GPIOIEN_MASK       (0x1UL << RCC_AHB1ENR_GPIOIEN_POS)



/*bit definition for RCC_CR register*/
#define RCC_CR_HSEON_POS                (16U)
#define RCC_CR_HSEON_MASK               (0x1UL << RCC_CR_HSEON_POS)

/*@defgroup RCC_HSE_CONFIG HSE CONFIG*/
#define RCC_HSE_OFF                     ((uint8) 0x00)
#define RCC_HSE_ON                      ((uint8) 0x01)

/*@defgroup RCC_LSE_CONFIG LSE CONFIG*/
#define RCC_LSE_OFF                     ((uint8) 0x00)
#define RCC_LSE_ON                      ((uint8) 0x01)

/*@defgroup RCC_HSI_CONFIG HSI CONFIG*/
#define RCC_HSI_OFF                     ((uint8) 0x00)
#define RCC_HSI_ON                      ((uint8) 0x01)

/*@defgroup RCC_LSI_CONFIG LSI CONFIG*/
#define RCC_LSI_OFF                     ((uint8) 0x00)
#define RCC_LSI_ON                      ((uint8) 0x01)


/* HPRE configuration */
#define RCC_CFGR_HPRE_POS     (4U)
#define RCC_CFGR_HPRE_MASK    (0xFUL << RCC_CFGR_HPRE_POS)    /*0x000000F0*/

#define RCC_CFGR_HPRE_DIV1    0x00000000U   /* SYSCLK not divided */
#define RCC_CFGR_HPRE_DIV2    0x00000080U   /* SYSCLK divided by 2 */
#define RCC_CFGR_HPRE_DIV4    0x00000090U   /* SYSCLK divided by 4 */
#define RCC_CFGR_HPRE_DIV8    0x000000A0U   /* SYSCLK divided by 8 */
#define RCC_CFGR_HPRE_DIV16   0x000000B0U   /* SYSCLK divided by 16 */
#define RCC_CFGR_HPRE_DIV64   0x000000C0U   /* SYSCLK divided by 64 */
#define RCC_CFGR_HPRE_DIV128  0x000000D0U   /* SYSCLK divided by 128 */
#define RCC_CFGR_HPRE_DIV256  0x000000E0U   /* SYSCLK divided by 256 */
#define RCC_CFGR_HPRE_DIV512  0x80000F00U   /* SYSCLK divided by 512 */

/* PPRE1 configuration */
#define RCC_CFGR_PPRE1_POS    (10U)
#define RCC_CFGR_PPRE1_MASK   (0x7UL << RCC_CFGR_PPRE1_POS)   /*0x00001C00*/

#define RCC_CFGR_PPRE1_DIV1	  0x00000000U	/* HCLK not divided */
#define RCC_CFGR_PPRE1_DIV2	  0x00001000U	/* HCLK divided by 2 */
#define RCC_CFGR_PPRE1_DIV4	  0x00001400U	/* HCLK divided by 4 */
#define RCC_CFGR_PPRE1_DIV8	  0x00001800U	/* HCLK divided by 8 */
#define RCC_CFGR_PPRE1_DIV16  0x00001C00U	/* HCLK divided by 16 */

/* PPRE2 configuration */
#define RCC_CFGR_PPRE2_POS    (13U)
#define RCC_CFGR_PPRE2_MASK   (0x7UL << RCC_CFGR_PPRE2_POS)   /*0x0000E000*/

#define RCC_CFGR_PPRE2_DIV1	  0x00000000U	/*!< HCLK not divided */
#define RCC_CFGR_PPRE2_DIV2	  0x00008000U	/*!< HCLK divided by 2 */
#define RCC_CFGR_PPRE2_DIV4	  0x0000A000U	/*!< HCLK divided by 4 */
#define RCC_CFGR_PPRE2_DIV8	  0x0000C000U	/*!< HCLK divided by 8 */
#define RCC_CFGR_PPRE2_DIV16  0x0000E000U	/*!< HCLK divided by 16 */

/******************************************************************************/
/*                  Macro Functions Declaration Section                       */
/******************************************************************************/



/******************************************************************************/
/*                   Data_Types Declaration Section                           */
/******************************************************************************/
typedef struct
{
    volatile uint32 CR;            /*!< RCC clock control register,                                     Address offset: 0x00 */
    volatile uint32 PLLCFGR;       /*!< RCC PLL configuration register,                                 Address offset: 0x04 */
    volatile uint32 CFGR;          /*!< RCC clock configuration register,                               Address offset: 0x08 */
    volatile uint32 CIR;           /*!< RCC clock interrupt register,                                   Address offset: 0x0C */
    volatile uint32 AHB1RSTR;      /*!< RCC AHB1 peripheral reset register,                             Address offset: 0x10 */
    volatile uint32 AHB2RSTR;      /*!< RCC AHB2 peripheral reset register,                             Address offset: 0x14 */
    volatile uint32 AHB3RSTR;      /*!< RCC AHB3 peripheral reset register,                             Address offset: 0x18 */
    uint32          RESERVED0;     /*!< Reserved, 0x1C */
    volatile uint32 APB1RSTR;      /*!< RCC APB1 peripheral reset register,                             Address offset: 0x20*/
    volatile uint32 APB2RSTR;      /*!< RCC APB2 peripheral reset register,                             Address offset: 0x24*/
    uint32          RESERVED1[2];  /*!< Reserved, 0x28-0x2C */
    volatile uint32 AHB1ENR;       /*!< RCC AHB1 peripheral clock register,                             Address offset: 0x30 */
    volatile uint32 AHB2ENR;       /*!< RCC AHB2 peripheral clock register,                             Address offset: 0x34 */
    volatile uint32 AHB3ENR;       /*!< RCC AHB3 peripheral clock register,                             Address offset: 0x38 */
    uint32          RESERVED2;     /*!< Reserved, 0x3C */
    volatile uint32 APB1ENR;       /*!< RCC APB1 peripheral clock enable register,                      Address offset: 0x40 */
    volatile uint32 APB2ENR;       /*!< RCC APB2 peripheral clock enable register,                      Address offset: 0x44 */
    uint32          RESERVED3[2];  /*!< Reserved, 0x48-0x4C */
    volatile uint32 AHB1LPENR;     /*!< RCC AHB1 peripheral clock enable in low power mode register,    Address offset: 0x50 */
    volatile uint32 AHB2LPENR;     /*!< RCC AHB2 peripheral clock enable in low power mode register,    Address offset: 0x54 */
    volatile uint32 AHB3LPENR;     /*!< RCC AHB3 peripheral clock enable in low power mode register,    Address offset: 0x58 */
    uint32          RESERVED4;     /*!< Reserved, 0x5C */
    volatile uint32 APB1LPENR;     /*!< RCC APB1 peripheral clock enable in low power mode register,    Address offset: 0x60 */
    volatile uint32 APB2LPENR;     /*!< RCC APB2 peripheral clock enable in low power mode register,    Address offset: 0x64 */
    uint32          RESERVED5[2];  /*!< Reserved, 0x68-0x6C */
    volatile uint32 BDCR;          /*!< RCC Backup domain control register,                             Address offset: 0x70 */
    volatile uint32 CSR;           /*!< RCC clock control & status register,                            Address offset: 0x74 */
    uint32          RESERVED6[2];  /*!< Reserved, 0x78-0x7C */
    volatile uint32 SSCGR;         /*!< RCC spread spectrum clock generation register,                  Address offset: 0x80 */
    volatile uint32 PLLI2SCFGR;    /*!< RCC PLLI2S configuration register,                              Address offset: 0x84 */
} RCC_t;



/******************************************************************************/
/*                    functions declaration Section                           */
/******************************************************************************/


#endif /* HAL_DRIVERS_STM32F4XX_REG_DEF_H_ */
