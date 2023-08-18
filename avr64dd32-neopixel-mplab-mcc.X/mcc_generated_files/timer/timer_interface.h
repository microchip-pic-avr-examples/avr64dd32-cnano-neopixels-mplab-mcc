/** 
  @Company
    Microchip Technology Inc.
 
  @File Name
    TMR_interface.h
 
  @Summary
    This is the generated header file for Timer module interfaces.
 
  @Description
    This header file provides interfaces to Timer driver APIs.
    Generation Information :
        Driver Version    :  1.00
    The generated drivers are tested against the following:
        MPLAB             :  MPLAB X v5.40
*/

/*
� [2023] Microchip Technology Inc. and its subsidiaries.

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

#ifndef TMR_INTERFACE_H
#define TMR_INTERFACE_H

/**
 * @brief This file contains API prototypes and other datatypes for Timer-0 module.
 * @defgroup timer_interface Timer Interface
 * @{
 */

#include<stddef.h>
        
/**
 @ingroup timer_interface
 @typedef struct TMR_INTERFACE
 @brief This structure contains the interfaces to Timer module
 */
 
struct TMR_INTERFACE
{
    void (*Initialize)(void);
    void (*Start)(void);
    void (*Stop)(void);
    void (*PeriodCountSet)(size_t count);
    void (*TimeoutCallbackRegister)(void (* CallbackHandler)(void));
    void (*Tasks)(void);
};
/**
 * @}
 */
#endif //TMR_INTERFACE_H