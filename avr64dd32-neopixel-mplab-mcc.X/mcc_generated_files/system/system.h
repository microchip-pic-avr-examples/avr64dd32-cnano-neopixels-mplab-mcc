/**
 * System Driver Header File
 * 
 * @file system.h
 * 
 * @defgroup systemdriver System Driver
 * 
 * @brief This is the generated header file for the System Driver.
 *
 * @version Driver Version 1.0.1
*/
/*
� [2022] Microchip Technology Inc. and its subsidiaries.

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


#ifndef MCC_H
#define	MCC_H

#ifdef __cplusplus
extern "C" {
#endif

/**
  Section: Included Files
*/
#include "../system/utils/compiler.h"
#include "config_bits.h"
#include "../system/pins.h"
#include "../ccl/ccl.h"
#include "../system/clock.h"
#include "../evsys/evsys.h"
#include "../spi/spi0.h"
#include "../timer/tca0.h"
#include "../uart/usart0.h"
#include "../system/interrupt.h"
/**
 * @ingroup systemdriver
 * @brief This initializes the system module and must be called before any other API is called.
 * This routine should only be called once during system initialization.
 * @param None
 * @return None
*/
void SYSTEM_Initialize(void);

#ifdef __cplusplus
}
#endif
#endif	/* MCC_H */
/**
 End of File
*/