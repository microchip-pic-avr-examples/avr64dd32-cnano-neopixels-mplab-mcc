/**
 * TCA0 Generated Driver API Header File
 *
 * @file tca0.h
 *
 * @defgroup tca0_normal TCA0 in Normal Mode
 *
 * @brief This file contains the API prototypes for the TCA0 driver in Normal (16-bit) mode.
 *
 * @version TCA0 Driver Version 2.1.1
*/
/*
© [2023] Microchip Technology Inc. and its subsidiaries.

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
 * @ingroup tca0_normal
 * @typedef void TCA0_cb_t
 * @brief Function pointer to the callback function called by TCA when operating in Normal mode. The default value is set to NULL which means that no callback function will be used.
 */  
typedef void (*TCA0_cb_t)(void);

extern const struct TMR_INTERFACE TCA0_Interface;

/**
 * @ingroup tca0_normal
 * @brief Initializes the TCA.
 * @param None.
 * @return None.
 */ 
void TCA0_Initialize(void);
/**
 * @ingroup tca0_normal
 * @brief Starts the 16-bit timer/counter for the TCA.
 * @param None.
 * @return None.
 */
void TCA0_Start(void);
/**
 * @ingroup tca0_normal
 * @brief Stops the 16-bit timer/counter for the TCA.
 * @param None.
 * @return None.
 */
void TCA0_Stop(void);
/**
 * @ingroup tca0_normal
 * @brief Interrupt Service Routine (ISR) callback function register to be called if the Overflow Interrupt flag is set.
 * @param TCA0_cb_t cb - Callback function for Overflow event.
 * @return None.
 */ 
void TCA0_OverflowCallbackRegister(TCA0_cb_t cb);
/**
 * @ingroup tca0_normal
 * @brief ISR callback function to be called if the Compare 0 Match Interrupt flag is set.
 * @param TCA0_cb_t cb - Callback function for Compare 0 match event.
 * @return None.
 */ 
void TCA0_Compare0CallbackRegister(TCA0_cb_t cb);
/**
 * @ingroup tca0_normal
 * @brief ISR callback function to be called if the Compare 1 Match Interrupt flag is set.
 * @param TCA0_cb_t cb - Callback function for Compare 1 match event.
 * @return None.
 */ 
void TCA0_Compare1CallbackRegister(TCA0_cb_t cb);
/**
 * @ingroup tca0_normal
 * @brief ISR callback function to be called if the Compare 2 Match Interrupt flag is set.
 * @param TCA0_cb_t cb - Callback function for Compare 2 match event.
 * @return None.
 */ 
void TCA0_Compare2CallbackRegister(TCA0_cb_t cb);
/**
 * @ingroup tca0_normal
 * @brief Enables the 16-bit timer/counter interrupt for the TCA.
 * @param None.
 * @return None.
 */
void TCA0_EnableInterrupt(void);
/**
 * @ingroup tca0_normal
 * @brief Disables the 16-bit timer/counter interrupt for the TCA.
 * @param None.
 * @return None.
 */
void TCA0_DisableInterrupt(void);
/**
 * @ingroup tca0_normal
 * @brief Reads the 16-bit timer/counter value for the TCA.
 * @param None.
 * @return uint16_t - timer/counter value returns from the TCA0.
 */
uint16_t TCA0_Read(void);
/**
 * @ingroup tca0_normal
 * @brief Writes the timer value to load to the TCA.
 * @param uint16_t timerVal - Loading the timer value for the TCA.
 * @return None.
 */
void TCA0_Write(uint16_t timerVal);
/**
 * @ingroup tca0_normal
 * @brief Clears the Overflow Interrupt flag after the Overflow flag set.
 * @param None.
 * @return None.
 */
void TCA0_ClearOverflowInterruptFlag(void);
/**
 * @ingroup tca0_normal
 * @brief Checks the Overflow Interrupt flag status for the TCA.
 * @param None.
 * @retval True  - Overflow Interrupt flag is set.
 * @retval False - Overflow Interrupt flag is not set.
 */
bool TCA0_IsOverflowInterruptFlagSet(void);
/**
 * @ingroup tca0_normal
 * @brief Clears the Compare 0 Interrupt flag after the Compare 0 flag is set.
 * @param None.
 * @return None.
 */
void TCA0_ClearCMP0InterruptFlag(void);
/**
 * @ingroup tca0_normal
 * @brief Checks the Compare 0 Interrupt flag status for the TCA.
 * @param None.
 * @retval True  - Compare 0 Interrupt flag is set.
 * @retval False - Compare 0 Interrupt flag is not set.
 */
bool TCA0_IsCMP0InterruptFlagSet(void);
/**
 * @ingroup tca0_normal
 * @brief Clears the Compare 1 Interrupt flag after the Compare 1 flag is set.
 * @param None.
 * @return None.
 */
void TCA0_ClearCMP1InterruptFlag(void);
/**
 * @ingroup tca0_normal
 * @brief Checks the Compare 1 Interrupt flag status for the TCA.
 * @param None.
 * @retval True  - Compare 1 Interrupt flag is set.
 * @retval False - Compare 1 Interrupt flag is not set.
 */
bool TCA0_IsCMP1InterruptFlagSet(void);
/**
 * @ingroup tca0_normal
 * @brief Clears the Compare 2 Interrupt flag after the Compare 2 flag is set.
 * @param None.
 * @return None.
 */
void TCA0_ClearCMP2InterruptFlag(void);

/**
 * @ingroup tca0_normal
 * @brief Checks the Compare 2 Interrupt flag status for the TCA.
 * @param None.
 * @retval True  - Compare 2 Interrupt flag is set.
 * @retval False - Compare 2 Interrupt flag is not set.
 */
bool TCA0_IsCMP2InterruptFlagSet(void);

#ifdef __cplusplus
}
#endif

#endif /* TCA0_H_INCLUDED */