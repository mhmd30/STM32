/* 
 * File:   hal_spi.c
 * Author: Mohammed_Elnefary
 *
 * Created on October 25, 2023, 7:46 AM
 */

#include "hal_spi.h"

#if MSSP_SPI_INTERRUPT_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE
    static void (*SPI_InterruptHandler)(void) = NULL;
#endif

/**
 * @brief   Configures GPIO pins for SPI operation in Master mode.
 * @param   _spi: Pointer to the spi_t structure containing SPI configuration.
 * @return  Std_ReturnType: Indicates the success or failure of the operation.
 */
static Std_ReturnType SPI_Master_Gpio_Cfg(const spi_t *_spi);

/**
 * @brief   Configures GPIO pins for SPI operation in Slave mode.
 * @param   _spi: Pointer to the spi_t structure containing SPI configuration.
 * @return  Std_ReturnType: Indicates the success or failure of the operation.
 */
static Std_ReturnType SPI_Slave_Gpio_Cfg(const spi_t *_spi);

/**
 * @brief   Configures the SPI interrupt handler.
 * @param   _spi: Pointer to the spi_t structure containing SPI configuration.
 * @return  Std_ReturnType: Indicates the success or failure of the operation.
 */
static Std_ReturnType SPI_InterruptHandler_function(const spi_t *_spi);

/**
 * @brief   Initializes the SPI module with the provided configuration.
 * @param   _spi: Pointer to the spi_t structure containing SPI configuration.
 * @return  Std_ReturnType: Indicates the success or failure of the operation.
 */
Std_ReturnType SPI_Init(const spi_t *_spi){
    Std_ReturnType ret = E_OK;
    if(NULL == _spi){
        ret = E_NOT_OK;
    }
    else{
        /*disable SPI Module*/
        Spi_Enable(SPI_Disables_Serial_And_Pins);
        /*Master/Slave mode select*/
        Spi_Mode_Select(_spi->SPI_Selected_Mode);
        if((_spi->SPI_Selected_Mode ==SPI_Master_Mode_FOSC_DIV_BY_4) || 
            (_spi->SPI_Selected_Mode ==  SPI_Master_Mode_FOSC_DIV_BY_16)|| 
            (_spi->SPI_Selected_Mode ==  SPI_Master_Mode_FOSC_DIV_BY_64) || 
            (_spi->SPI_Selected_Mode ==  SPI_Master_Mode_TMR2_DIV_BY_2))
        {   
            SPI_Master_Gpio_Cfg(_spi);
        }
        else{
            SPI_Slave_Gpio_Cfg(_spi);
            SSPSTATbits.SMP = 0;               //Sample bit must be cleared when SPI is used in Slave mode
        }
        /*SPI Clock Select bit --> transition cases*/
        Spi_Transition_Clock_State(_spi->Transition_Clock_State);
        /*= Input data sampled data output time*/
        Spi_Sampled_Data_time(_spi->SPI_Sampled_Data_time1);
        /*Clock Polarity Select bit for Idle state*/
        Spi_Clock_Polarity(_spi->Clock_Polarity);
        /*Enable SPI Module*/
        Spi_Enable(SPI_Enables_Serial_And_Pins);
        /* Configure the interrupt */
        SPI_InterruptHandler_function(_spi);

    }
    return ret;

}

/**
 * @brief   Deinitializes the SPI module.
 * @param   _spi: Pointer to the spi_t structure containing SPI configuration.
 * @return  Std_ReturnType: Indicates the success or failure of the operation.
 */
Std_ReturnType SPI_DeInit(const spi_t *_spi){
    Std_ReturnType ret = E_OK;
    if(NULL == _spi){
        ret = E_NOT_OK;
    }
    else{
        /*disable SPI Module*/
        Spi_Enable(SPI_Disables_Serial_And_Pins);
    }
    return ret;
}

/**
 * @brief   Reads a byte from the SPI bus in a blocking manner.
 * @param   _data: Pointer to the variable where the received data will be stored.
 * @return  Std_ReturnType: Indicates the success or failure of the operation.
 */
Std_ReturnType SPI_ReadByteBlocking(uint8 *_data){
    Std_ReturnType ret = E_OK;
    if(NULL == _data){
        ret = E_NOT_OK;
    }
    else{
        while(!(SSPSTATbits.BF));
        *_data = SSPBUF;
    }
    return ret;
}

/**
 * @brief   Reads a byte from the SPI bus in a non-blocking manner.
 * @param   _data: Pointer to the variable where the received data will be stored.
 * @return  Std_ReturnType: Indicates the success or failure of the operation.
 */
Std_ReturnType SPI_ReadByteNonBlocking(uint8 *_data){
    Std_ReturnType ret = E_OK;
    if(1 == SSPSTATbits.BF){
        *_data = RCREG;
    }
    else{
        ret = E_NOT_OK;
    }
    return ret;
}

/**
 * @brief   Writes a byte to the SPI bus in a blocking manner.
 * @param   _data: The data byte to be transmitted.
 * @return  Std_ReturnType: Indicates the success or failure of the operation.
 */
Std_ReturnType SPI_WriteByteBlocking(uint8 _data){
    Std_ReturnType ret = E_OK;
    SSPBUF = _data; 
    while(!PIR1bits.SSPIF);
    PIR1bits.SSPIF = 0;
    if(SSPCON1bits.WCOL == 1){
        SSPCON1bits.WCOL = 0;             // Collision Detect bit
        ret = E_NOT_OK;
    }
    else{/*Nothing*/ }
    return ret;
}

/**
 * @brief   Writes a byte to the SPI bus in a non-blocking manner.
 * @param   _data: The data byte to be transmitted.
 * @return  Std_ReturnType: Indicates the success or failure of the operation.
 */
Std_ReturnType SPI_WriteByte_NotBlocking( uint8 _data){
    Std_ReturnType ret = E_OK;
        SSPBUF = _data;
    if(PIR1bits.SSPIF == 1){
        PIR1bits.SSPIF = 0;           //the interrupt flag bit
    }
    else{
        ret = E_NOT_OK;
    }
    if(SSPCON1bits.WCOL == 1){
        SSPCON1bits.WCOL = 0;             // Collision Detect bit
        ret = E_NOT_OK;
    }
    else{/*Nothing*/ }
    return ret;
}

/**
 * @brief   Writes a string of bytes to the SPI bus in a blocking manner.
 * @param   _data: Pointer to the data string to be transmitted.
 * @param   str_len: Length of the data string.
 * @return  Std_ReturnType: Indicates the success or failure of the operation.
 */
Std_ReturnType SPI_WriteStringBlocking( uint8 *_data , uint8 str_len){
    Std_ReturnType ret = E_OK;
    if(NULL == _data){
        ret = E_NOT_OK;
    }
    else{
        uint16 char_counter = ZERO_INIT;
        for(char_counter=ZERO_INIT; char_counter < str_len; char_counter++){
            ret = SPI_WriteByteBlocking(_data[char_counter]);
        }
}
    return ret;
}

/**
 * @brief   Writes a string of bytes to the SPI bus in a non-blocking manner.
 * @param   _data: Pointer to the data string to be transmitted.
 * @param   str_len: Length of the data string.
 * @return  Std_ReturnType: Indicates the success or failure of the operation.
 */
Std_ReturnType SPI_WriteStringNotBlocking( uint8 *_data , uint8 str_len){
    Std_ReturnType ret = E_OK;
    if(NULL == _data){
        ret = E_NOT_OK;
    }
    else{
    uint16 char_counter = ZERO_INIT;
    for(char_counter = ZERO_INIT; char_counter < str_len; char_counter++){
        ret = SPI_WriteByte_NotBlocking(_data[char_counter]);
    }
    return ret;
    }
}

static Std_ReturnType SPI_Master_Gpio_Cfg(const spi_t *_spi){
    Std_ReturnType ret = E_NOT_OK;
    if(_spi != NULL){
        pin_config_t SPI_SDO = {.port = PORTC_INDEX, .pin = GPIO_PIN5, .direction = GPIO_DIRECTION_OUTPUT};
        pin_config_t SPI_SDI = {.port = PORTC_INDEX, .pin = GPIO_PIN4, .direction = GPIO_DIRECTION_INPUT};
        pin_config_t SPI_CLK = {.port = PORTC_INDEX, .pin = GPIO_PIN3, .direction = GPIO_DIRECTION_OUTPUT};

        ret = gpio_pin_intialize(&SPI_SDO); 
        ret = gpio_pin_intialize(&SPI_SDI);
        ret = gpio_pin_intialize(&SPI_CLK);
    }
    return ret;
}
static Std_ReturnType SPI_Slave_Gpio_Cfg(const spi_t *_spi){
    Std_ReturnType ret = E_NOT_OK;
    if(_spi != NULL){
        pin_config_t SPI_SDO = {.port = PORTC_INDEX, .pin = GPIO_PIN5, .direction = GPIO_DIRECTION_OUTPUT};
        pin_config_t SPI_SDI = {.port = PORTC_INDEX, .pin = GPIO_PIN4, .direction = GPIO_DIRECTION_INPUT};
        pin_config_t SPI_CLK = {.port = PORTC_INDEX, .pin = GPIO_PIN3, .direction = GPIO_DIRECTION_INPUT};
        pin_config_t SPI_SS =  {.port = PORTA_INDEX, .pin = GPIO_PIN5, .direction = GPIO_DIRECTION_INPUT};

        ret = gpio_pin_intialize(&SPI_SDO); 
        ret = gpio_pin_intialize(&SPI_SDI);
        ret = gpio_pin_intialize(&SPI_CLK); 

        if(_spi->SPI_Selected_Mode == SPI_Slave_mode_SS_Enabled){
            ret = gpio_pin_direction_intialize(&SPI_SS);
        }
    }
    return ret;
}

static Std_ReturnType SPI_InterruptHandler_function(const spi_t *_spi){
#if MSSP_SPI_INTERRUPT_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE
        MSSP_SPI_InterruptEnable();
        MSSP_SPI_InterruptFlagClear();
#if INTERRUPT_PRIORITY_LEVELS_ENABLE==INTERRUPT_FEATURE_ENABLE 
        INTERRUPT_PriorityLevelsEnable();
        if(INTERRUPT_HIGH_PRIORITY == _spi->priority){ 
            INTERRUPT_GlobalInterruptHighEnable();
            MSSP_SPI_HighPrioritySet(); 
        }
        else if(INTERRUPT_LOW_PRIORITY == _adc->priority){ 
            INTERRUPT_GlobalInterruptLowEnable();
            MSSP_SPI_LowPrioritySet(); 
        }
        else{ /* Nothing */ }
#else
        INTERRUPT_GlobalInterruptEnable();
        INTERRUPT_PeripheralInterruptEnable();
#endif
        SPI_InterruptHandler = _spi->SPI_InterruptHandler;
#endif
}

void MSSP_SPI_ISR(void){
    MSSP_SPI_InterruptFlagClear();
    if(SPI_InterruptHandler){
        SPI_InterruptHandler();
    }    
    else { /* Nothing */}
}