/**
 * SPI0 Generated Driver API Header File
 *
 * @file spi0.h
 *
 * defgroup spi0 SPI0
 *
 * @brief This header file provides APIs for the SPI0 driver.
 *
 * @version SPI0 Driver Version 2.0.1
*/
/*
© [2022] Microchip Technology Inc. and its subsidiaries.

    Subject to your compliance with these terms, you may use Microchip 
    software and any derivatives exclusively with Microchip products. 
    You are responsible for complying with 3rd party license terms  
    applicable to your use of 3rd party software (including open source  
    software) that may accompany Microchip software. SOFTWARE IS ?AS IS.? 
    NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS 
    SOFTWARE, INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT,  
    MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT 
    WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY 
    KIND WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF 
    MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE 
    FORESEEABLE. TO THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP?S 
    TOTAL LIABILITY ON ALL CLAIMS RELATED TO THE SOFTWARE WILL NOT 
    EXCEED AMOUNT OF FEES, IF ANY, YOU PAID DIRECTLY TO MICROCHIP FOR 
    THIS SOFTWARE.
*/

#ifndef SPI0_BASIC_H_INCLUDED
#define SPI0_BASIC_H_INCLUDED

#include "../system/utils/compiler.h"
#include <stdbool.h>
#include "spi_interface.h"

#ifdef __cplusplus
extern "C" {
#endif
             
extern const struct SPI_INTERFACE SPI0_s;

/**
 * @ingroup spi0
 * @typedef void *spi0_TRANSFER_DONE_CB
 * @brief Function pointer to callback function called by SPI IRQ. NULL=default value: No callback function is to be used.
 */ 
typedef void (*spi0_TRANSFER_DONE_CB)(void);

/**
 * @ingroup spi0
 * @typedef struct SPI0_configuration_t
 * @brief hardware stuff that controls SPI mode and baud rate
 */
typedef struct 
{
    // hardware stuff that controls SPI mode
    // hardware stuff that controls SPI baud rate
    uint8_t CTRLAvalue;
    uint8_t CTRLBvalue;
} SPI0_configuration_t; 

/**
 * @ingroup spi0
 * @typedef enum spi0_transfer_type_t
 * @brief Specify whether the SPI transfer is to be uni- or bidirectional. A bidirectional transfer (=SPI_EXCHANGE) causes the received data to overwrite the buffer with the data to transmit.
 */
typedef enum spi0_transfer_type 
{
    SPI0_EXCHANGE, ///< SPI transfer is bidirectional
    SPI0_READ,     ///< SPI transfer reads, writes only 0s
    SPI0_WRITE     ///< SPI transfer writes, discards read data
} spi0_transfer_type_t;

/**
 * @ingroup spi0
 * @typedef enum spi0_transfer_status_t
 * @brief Status of the SPI hardware and SPI bus.
 */
typedef enum spi0_transfer_status 
{
    SPI0_FREE, ///< SPI hardware is not open, bus is free.
    SPI0_IDLE, ///< SPI hardware has been opened, no transfer ongoing.
    SPI0_BUSY, ///< SPI hardware has been opened, transfer ongoing.
    SPI0_DONE  ///< SPI hardware has been opened, transfer complete.
} spi0_transfer_status_t;

/**
 * @ingroup spi0
 * @typedef enum SPI0_configuration_name_t
 * @brief Enumeration of the different configurations supported by the driver for SPI interface.
 *
 *  NOTE: A user may specify a configuration, e.g. CLIENT_A, used when communication over SPI with CLIENT_A, and another configuration, CLIENT_B, 
 *        used when communication with CLIENT_B. The configurations may use different SPI configuration such as polarity or SCK frequency.
 */
typedef enum 
{
    SPI0_DEFAULT
} SPI0_configuration_name_t;

 /**
 * @ingroup spi0
 * @brief Initialize SPI interface.
 * @param none
 * @return none
 */
void SPI0_Initialize(void);

/**
 * @ingroup spi0
 * @brief Enables the SPI module and enables the clock to the SPI by control register.
 * @param none
 * @return none
 */ 
void SPI0_Enable(void);

/**
 * @ingroup spi0
 * @brief Disables the SPI module and disables the clock to the SPI by control register.
 * @param none
 * @return none
 */ 
void SPI0_Disable(void);

/**
 * @ingroup spi0
 * @brief Sets the index of Configuration to use in the transfer.
 * @param uint8_t spiConfigIndex - The configuration index
 * @retval true  - The SPI open was successful
 * @retval false - The SPI open was not successful
 */
bool SPI0_Open(uint8_t spiConfigIndex);

/**
 * @ingroup spi0
 * @brief Close the SPI for communication.
 * @param none
 * @return none
 */
void SPI0_Close(void);

/**
 * @ingroup spi0
 * @brief Exchange one byte over SPI. Blocks until done.
 * @param uint8_t byteData - The byte to transfer
 * @return uint8_t - Received data byte.
 */
uint8_t SPI0_ByteExchange(uint8_t byteData);

/**
 * @ingroup spi0
 * @brief Exchange a buffer over SPI. Blocks if using polled driver.
 * @param[inout] void * bufferData The buffer to transfer. Received data is returned here
 * @param[in] size_t bufferSize The size of buffer to transfer
 * @return none
 */
void SPI0_BufferExchange(void * bufferData, size_t bufferSize);

/**
 * @ingroup spi0
 * @brief Write a buffer over SPI. Blocks if using polled driver.
 * @param[in] void * bufferData The buffer to transfer
 * @param[in] size_t bufferSize The size of buffer to transfer
 * @return none
 */
void SPI0_BufferWrite(void * bufferData, size_t bufferSize);

/**
 * @ingroup spi0
 * @brief Read a buffer over SPI. Blocks if using polled driver.
 * @param[out] void * bufferData Received data is written here.
 * @param[in] size_t bufferSize The size of buffer to transfer
 * @return none
 */
void SPI0_BufferRead(void * bufferData, size_t bufferSize);

/**
 * @ingroup spi0
 * @brief Write data byte to SPI.
 * @param uint8_t byteData The byte to transfer.
 * @return none
 */
void SPI0_ByteWrite(uint8_t byteData);

/**
 * @ingroup spi0
 * @brief Get received data byte from SPI.
 * @param none
 * @return uint8_t - The received data
 */
uint8_t SPI0_ByteRead(void);

/**
 * @ingroup spi0
 * @brief Check if SPI CLIENT is selected, i.e. its SS has been asserted.
 * @param none
 * @retval true - SPI is selected
 * @retval false - SPI is not selected
 */
bool SPI0_Selected(void);

/**
 * @ingroup spi0
 * @brief Wait until SPI has recaived a data byte
 * @param none
 * @return none
 */
void SPI0_WaitDataready(void);

uint8_t __attribute__((deprecated)) SPI0_ExchangeByte(uint8_t data);
void __attribute__((deprecated)) SPI0_ExchangeBlock(void *block, size_t blockSize);
void __attribute__((deprecated)) SPI0_WriteBlock(void *block, size_t blockSize);
void __attribute__((deprecated)) SPI0_ReadBlock(void *block, size_t blockSize);
void __attribute__((deprecated)) SPI0_WriteByte(uint8_t byte);
uint8_t __attribute__((deprecated)) SPI0_ReadByte(void);

#ifdef __cplusplus
}
#endif

#endif /* SPI0_BASIC_H_INCLUDED */
