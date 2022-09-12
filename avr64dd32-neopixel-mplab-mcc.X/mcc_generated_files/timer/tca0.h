/**
 * TCA0 Generated Driver API Header File
 *
 * @file tca0.h
 *
 * @defgroup tca0 TCA0
 *
 * @brief This header file provides APIs for the TCA0 driver.
 *
 * @version TCA0 Driver Version 2.1.1
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


#ifndef TCA0_H_INCLUDED
#define TCA0_H_INCLUDED

#include <stdint.h>
#include <stdbool.h>
#include "../system/system.h"
#include "timer_interface.h"
#include "../system/utils/compiler.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @ingroup tca0
 * @typedef void TCA0_cb_t
 * @brief Function pointer to callback function called by TCA. NULL=default value: No callback function is to be used.
 */  
typedef void (*TCA0_cb_t)(void);    

extern const struct TMR_INTERFACE TCA0_Interface;

/**
 * @ingroup tca0
 * @brief Initialize TCA interface.
 * @param none
 * @return none
 */ 
void TCA0_Initialize(void);
/**
 * @ingroup tca0
 * @brief API to start the 16-bit timer/counter for TCA interface.
 * @param none
 * @return none
 */
void TCA0_Start(void);
/**
 * @ingroup tca0
 * @brief API to stop the 16-bit timer/counter for TCA interface
 * @param none
 * @return none
 */
void TCA0_Stop(void);
/**
 * @ingroup tca0
 * @brief ISR callback function register to be called if overflow interrupt flag is set.
 * @param TCA0_cb_t cb - call back value for overflow.
 * @return none
 */ 
void TCA0_OverflowCallbackRegister(TCA0_cb_t cb);
/**
 * @ingroup tca0
 * @brief ISR callback function to be called if Compare 0 match interrupt flag is set.
 * @param TCA0_cb_t cb - call back value for compare 0.
 * @return none
 */ 
void TCA0_Compare0CallbackRegister(TCA0_cb_t cb);
/**
 * @ingroup tca0
 * @brief ISR callback function to be called if Compare 1 match interrupt flag is set.
 * @param TCA0_cb_t cb - call back value for compare 1.
 * @return none
 */ 
void TCA0_Compare1CallbackRegister(TCA0_cb_t cb);
/**
 * @ingroup tca0
 * @brief ISR callback function to be called if Compare 2 match interrupt flag is set.
 * @param TCA0_cb_t cb - call back value for compare 2.
 * @return none
 */ 
void TCA0_Compare2CallbackRegister(TCA0_cb_t cb);
/**
 * @ingroup tca0
 * @brief Enable the 16-bit Timer/Counter interrupt for TCA interface.
 * @param none
 * @return none
 */
void TCA0_EnableInterrupt(void);
/**
 * @ingroup tca0
 * @brief Disable the 16-bit Timer/Counter interrupt for TCA interface.
 * @param none
 * @return none
 */
void TCA0_DisableInterrupt(void);
/**
 * @ingroup tca0
 * @brief API to read the 16-bit timer/counter value for TCA interface.
 * @param none
 * @return uint16_t - timer/counter value returns from the TCA0 interface.
 */
uint16_t TCA0_Read(void);
/**
 * @ingroup tca0
 * @brief API to write the timer value to load for TCA.
 * @param uint16_t timerVal - Loading the timer value for TCA.
 * @return none
 */
void TCA0_Write(uint16_t timerVal);
/**
 * @ingroup tca0
 * @brief Clearing the Overflow interrupt flag after the overflow flag set.
 * @param none
 * @return none
 */
void TCA0_ClearOverflowInterruptFlag(void);
/**
 * @ingroup tca0
 * @brief To verify the Overflow interrupt flag status for TCA interface.
 * @param none
 * @retval true  - Overflow interrupt flag was set.
 * @retval false - Overflow interrupt flag was not set.
 */
bool TCA0_IsOverflowInterruptFlagSet(void);
/**
 * @ingroup tca0
 * @brief Clearing the Compare 0 interrupt flag after the compare 0 flag set.
 * @param none
 * @return none
 */
void TCA0_ClearCMP0InterruptFlag(void);
/**
 * @ingroup tca0
 * @brief To verify the compare 0 interrupt flag status for TCA interface.
 * @param none
 * @retval true  - compare 0 interrupt flag was set.
 * @retval false - compare 0 interrupt flag was not set.
 */
bool TCA0_IsCMP0InterruptFlagSet(void);
/**
 * @ingroup tca0
 * @brief Clearing the Compare 1 interrupt flag after the compare 0 flag set.
 * @param none
 * @return none
 */
void TCA0_ClearCMP1InterruptFlag(void);
/**
 * @ingroup tca0
 * @brief To verify the compare 1 interrupt flag status for TCA interface.
 * @param none
 * @retval true  - compare 1 interrupt flag was set.
 * @retval false - compare 1 interrupt flag was not set.
 */
bool TCA0_IsCMP1InterruptFlagSet(void);
/**
 * @ingroup tca0
 * @brief Clearing the Compare 2 interrupt flag after the compare 2 flag set.
 * @param none
 * @return none
 */
void TCA0_ClearCMP2InterruptFlag(void);
/**
 * @ingroup tca0
 * @brief To verify the compare 2 interrupt flag status for TCA interface.
 * @param none
 * @retval true  - compare 2 interrupt flag was set.
 * @retval false - compare 2 interrupt flag was not set.
 */
bool TCA0_IsCMP2InterruptFlagSet(void);

#ifdef __cplusplus
}
#endif

#endif /* TCA0_H_INCLUDED */