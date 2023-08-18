/**
 * Generated Pins header File
 * 
 * @file pins.h
 * 
 * @defgroup  pinsdriver Pins Driver
 * 
 * @brief This is generated driver header for pins. 
 *        This header file provides APIs for all pins selected in the GUI.
 *
 * @version Driver Version  1.1.0
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

#ifndef PINS_H_INCLUDED
#define PINS_H_INCLUDED

#include <avr/io.h>
#include "./port.h"

//get/set USART0_RX aliases
#define USART0_RX_SetHigh() do { PORTD_OUTSET = 0x20; } while(0)
#define USART0_RX_SetLow() do { PORTD_OUTCLR = 0x20; } while(0)
#define USART0_RX_Toggle() do { PORTD_OUTTGL = 0x20; } while(0)
#define USART0_RX_GetValue() (VPORTD.IN & (0x1 << 5))
#define USART0_RX_SetDigitalInput() do { PORTD_DIRCLR = 0x20; } while(0)
#define USART0_RX_SetDigitalOutput() do { PORTD_DIRSET = 0x20; } while(0)
#define USART0_RX_SetPullUp() do { PORTD_PIN5CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define USART0_RX_ResetPullUp() do { PORTD_PIN5CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define USART0_RX_SetInverted() do { PORTD_PIN5CTRL  |= PORT_INVEN_bm; } while(0)
#define USART0_RX_ResetInverted() do { PORTD_PIN5CTRL  &= ~PORT_INVEN_bm; } while(0)
#define USART0_RX_DisableInterruptOnChange() do { PORTD.PIN5CTRL = (PORTD.PIN5CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define USART0_RX_EnableInterruptForBothEdges() do { PORTD.PIN5CTRL = (PORTD.PIN5CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define USART0_RX_EnableInterruptForRisingEdge() do { PORTD.PIN5CTRL = (PORTD.PIN5CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define USART0_RX_EnableInterruptForFallingEdge() do { PORTD.PIN5CTRL = (PORTD.PIN5CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define USART0_RX_DisableDigitalInputBuffer() do { PORTD.PIN5CTRL = (PORTD.PIN5CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define USART0_RX_EnableInterruptForLowLevelSensing() do { PORTD.PIN5CTRL = (PORTD.PIN5CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)
#define PD5_SetInterruptHandler USART0_RX_SetInterruptHandler

//get/set USART0_TX aliases
#define USART0_TX_SetHigh() do { PORTD_OUTSET = 0x10; } while(0)
#define USART0_TX_SetLow() do { PORTD_OUTCLR = 0x10; } while(0)
#define USART0_TX_Toggle() do { PORTD_OUTTGL = 0x10; } while(0)
#define USART0_TX_GetValue() (VPORTD.IN & (0x1 << 4))
#define USART0_TX_SetDigitalInput() do { PORTD_DIRCLR = 0x10; } while(0)
#define USART0_TX_SetDigitalOutput() do { PORTD_DIRSET = 0x10; } while(0)
#define USART0_TX_SetPullUp() do { PORTD_PIN4CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define USART0_TX_ResetPullUp() do { PORTD_PIN4CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define USART0_TX_SetInverted() do { PORTD_PIN4CTRL  |= PORT_INVEN_bm; } while(0)
#define USART0_TX_ResetInverted() do { PORTD_PIN4CTRL  &= ~PORT_INVEN_bm; } while(0)
#define USART0_TX_DisableInterruptOnChange() do { PORTD.PIN4CTRL = (PORTD.PIN4CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define USART0_TX_EnableInterruptForBothEdges() do { PORTD.PIN4CTRL = (PORTD.PIN4CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define USART0_TX_EnableInterruptForRisingEdge() do { PORTD.PIN4CTRL = (PORTD.PIN4CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define USART0_TX_EnableInterruptForFallingEdge() do { PORTD.PIN4CTRL = (PORTD.PIN4CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define USART0_TX_DisableDigitalInputBuffer() do { PORTD.PIN4CTRL = (PORTD.PIN4CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define USART0_TX_EnableInterruptForLowLevelSensing() do { PORTD.PIN4CTRL = (PORTD.PIN4CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)
#define PD4_SetInterruptHandler USART0_TX_SetInterruptHandler

//get/set LUT1_OUT aliases
#define LUT1_OUT_SetHigh() do { PORTC_OUTSET = 0x8; } while(0)
#define LUT1_OUT_SetLow() do { PORTC_OUTCLR = 0x8; } while(0)
#define LUT1_OUT_Toggle() do { PORTC_OUTTGL = 0x8; } while(0)
#define LUT1_OUT_GetValue() (VPORTC.IN & (0x1 << 3))
#define LUT1_OUT_SetDigitalInput() do { PORTC_DIRCLR = 0x8; } while(0)
#define LUT1_OUT_SetDigitalOutput() do { PORTC_DIRSET = 0x8; } while(0)
#define LUT1_OUT_SetPullUp() do { PORTC_PIN3CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define LUT1_OUT_ResetPullUp() do { PORTC_PIN3CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define LUT1_OUT_SetInverted() do { PORTC_PIN3CTRL  |= PORT_INVEN_bm; } while(0)
#define LUT1_OUT_ResetInverted() do { PORTC_PIN3CTRL  &= ~PORT_INVEN_bm; } while(0)
#define LUT1_OUT_DisableInterruptOnChange() do { PORTC.PIN3CTRL = (PORTC.PIN3CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define LUT1_OUT_EnableInterruptForBothEdges() do { PORTC.PIN3CTRL = (PORTC.PIN3CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define LUT1_OUT_EnableInterruptForRisingEdge() do { PORTC.PIN3CTRL = (PORTC.PIN3CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define LUT1_OUT_EnableInterruptForFallingEdge() do { PORTC.PIN3CTRL = (PORTC.PIN3CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define LUT1_OUT_DisableDigitalInputBuffer() do { PORTC.PIN3CTRL = (PORTC.PIN3CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define LUT1_OUT_EnableInterruptForLowLevelSensing() do { PORTC.PIN3CTRL = (PORTC.PIN3CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)
#define PC3_SetInterruptHandler LUT1_OUT_SetInterruptHandler

//get/set TCA0_WO0 aliases
#define TCA0_WO0_SetHigh() do { PORTC_OUTSET = 0x1; } while(0)
#define TCA0_WO0_SetLow() do { PORTC_OUTCLR = 0x1; } while(0)
#define TCA0_WO0_Toggle() do { PORTC_OUTTGL = 0x1; } while(0)
#define TCA0_WO0_GetValue() (VPORTC.IN & (0x1 << 0))
#define TCA0_WO0_SetDigitalInput() do { PORTC_DIRCLR = 0x1; } while(0)
#define TCA0_WO0_SetDigitalOutput() do { PORTC_DIRSET = 0x1; } while(0)
#define TCA0_WO0_SetPullUp() do { PORTC_PIN0CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define TCA0_WO0_ResetPullUp() do { PORTC_PIN0CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define TCA0_WO0_SetInverted() do { PORTC_PIN0CTRL  |= PORT_INVEN_bm; } while(0)
#define TCA0_WO0_ResetInverted() do { PORTC_PIN0CTRL  &= ~PORT_INVEN_bm; } while(0)
#define TCA0_WO0_DisableInterruptOnChange() do { PORTC.PIN0CTRL = (PORTC.PIN0CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define TCA0_WO0_EnableInterruptForBothEdges() do { PORTC.PIN0CTRL = (PORTC.PIN0CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define TCA0_WO0_EnableInterruptForRisingEdge() do { PORTC.PIN0CTRL = (PORTC.PIN0CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define TCA0_WO0_EnableInterruptForFallingEdge() do { PORTC.PIN0CTRL = (PORTC.PIN0CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define TCA0_WO0_DisableDigitalInputBuffer() do { PORTC.PIN0CTRL = (PORTC.PIN0CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define TCA0_WO0_EnableInterruptForLowLevelSensing() do { PORTC.PIN0CTRL = (PORTC.PIN0CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)
#define PC0_SetInterruptHandler TCA0_WO0_SetInterruptHandler

//get/set TCA0_WO2 aliases
#define TCA0_WO2_SetHigh() do { PORTC_OUTSET = 0x4; } while(0)
#define TCA0_WO2_SetLow() do { PORTC_OUTCLR = 0x4; } while(0)
#define TCA0_WO2_Toggle() do { PORTC_OUTTGL = 0x4; } while(0)
#define TCA0_WO2_GetValue() (VPORTC.IN & (0x1 << 2))
#define TCA0_WO2_SetDigitalInput() do { PORTC_DIRCLR = 0x4; } while(0)
#define TCA0_WO2_SetDigitalOutput() do { PORTC_DIRSET = 0x4; } while(0)
#define TCA0_WO2_SetPullUp() do { PORTC_PIN2CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define TCA0_WO2_ResetPullUp() do { PORTC_PIN2CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define TCA0_WO2_SetInverted() do { PORTC_PIN2CTRL  |= PORT_INVEN_bm; } while(0)
#define TCA0_WO2_ResetInverted() do { PORTC_PIN2CTRL  &= ~PORT_INVEN_bm; } while(0)
#define TCA0_WO2_DisableInterruptOnChange() do { PORTC.PIN2CTRL = (PORTC.PIN2CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define TCA0_WO2_EnableInterruptForBothEdges() do { PORTC.PIN2CTRL = (PORTC.PIN2CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define TCA0_WO2_EnableInterruptForRisingEdge() do { PORTC.PIN2CTRL = (PORTC.PIN2CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define TCA0_WO2_EnableInterruptForFallingEdge() do { PORTC.PIN2CTRL = (PORTC.PIN2CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define TCA0_WO2_DisableDigitalInputBuffer() do { PORTC.PIN2CTRL = (PORTC.PIN2CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define TCA0_WO2_EnableInterruptForLowLevelSensing() do { PORTC.PIN2CTRL = (PORTC.PIN2CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)
#define PC2_SetInterruptHandler TCA0_WO2_SetInterruptHandler

//get/set SPI0_MISO aliases
#define SPI0_MISO_SetHigh() do { PORTA_OUTSET = 0x20; } while(0)
#define SPI0_MISO_SetLow() do { PORTA_OUTCLR = 0x20; } while(0)
#define SPI0_MISO_Toggle() do { PORTA_OUTTGL = 0x20; } while(0)
#define SPI0_MISO_GetValue() (VPORTA.IN & (0x1 << 5))
#define SPI0_MISO_SetDigitalInput() do { PORTA_DIRCLR = 0x20; } while(0)
#define SPI0_MISO_SetDigitalOutput() do { PORTA_DIRSET = 0x20; } while(0)
#define SPI0_MISO_SetPullUp() do { PORTA_PIN5CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define SPI0_MISO_ResetPullUp() do { PORTA_PIN5CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define SPI0_MISO_SetInverted() do { PORTA_PIN5CTRL  |= PORT_INVEN_bm; } while(0)
#define SPI0_MISO_ResetInverted() do { PORTA_PIN5CTRL  &= ~PORT_INVEN_bm; } while(0)
#define SPI0_MISO_DisableInterruptOnChange() do { PORTA.PIN5CTRL = (PORTA.PIN5CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define SPI0_MISO_EnableInterruptForBothEdges() do { PORTA.PIN5CTRL = (PORTA.PIN5CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define SPI0_MISO_EnableInterruptForRisingEdge() do { PORTA.PIN5CTRL = (PORTA.PIN5CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define SPI0_MISO_EnableInterruptForFallingEdge() do { PORTA.PIN5CTRL = (PORTA.PIN5CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define SPI0_MISO_DisableDigitalInputBuffer() do { PORTA.PIN5CTRL = (PORTA.PIN5CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define SPI0_MISO_EnableInterruptForLowLevelSensing() do { PORTA.PIN5CTRL = (PORTA.PIN5CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)
#define PA5_SetInterruptHandler SPI0_MISO_SetInterruptHandler

//get/set SPI0_MOSI aliases
#define SPI0_MOSI_SetHigh() do { PORTA_OUTSET = 0x10; } while(0)
#define SPI0_MOSI_SetLow() do { PORTA_OUTCLR = 0x10; } while(0)
#define SPI0_MOSI_Toggle() do { PORTA_OUTTGL = 0x10; } while(0)
#define SPI0_MOSI_GetValue() (VPORTA.IN & (0x1 << 4))
#define SPI0_MOSI_SetDigitalInput() do { PORTA_DIRCLR = 0x10; } while(0)
#define SPI0_MOSI_SetDigitalOutput() do { PORTA_DIRSET = 0x10; } while(0)
#define SPI0_MOSI_SetPullUp() do { PORTA_PIN4CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define SPI0_MOSI_ResetPullUp() do { PORTA_PIN4CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define SPI0_MOSI_SetInverted() do { PORTA_PIN4CTRL  |= PORT_INVEN_bm; } while(0)
#define SPI0_MOSI_ResetInverted() do { PORTA_PIN4CTRL  &= ~PORT_INVEN_bm; } while(0)
#define SPI0_MOSI_DisableInterruptOnChange() do { PORTA.PIN4CTRL = (PORTA.PIN4CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define SPI0_MOSI_EnableInterruptForBothEdges() do { PORTA.PIN4CTRL = (PORTA.PIN4CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define SPI0_MOSI_EnableInterruptForRisingEdge() do { PORTA.PIN4CTRL = (PORTA.PIN4CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define SPI0_MOSI_EnableInterruptForFallingEdge() do { PORTA.PIN4CTRL = (PORTA.PIN4CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define SPI0_MOSI_DisableDigitalInputBuffer() do { PORTA.PIN4CTRL = (PORTA.PIN4CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define SPI0_MOSI_EnableInterruptForLowLevelSensing() do { PORTA.PIN4CTRL = (PORTA.PIN4CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)
#define PA4_SetInterruptHandler SPI0_MOSI_SetInterruptHandler

//get/set SPI0_SCK aliases
#define SPI0_SCK_SetHigh() do { PORTA_OUTSET = 0x40; } while(0)
#define SPI0_SCK_SetLow() do { PORTA_OUTCLR = 0x40; } while(0)
#define SPI0_SCK_Toggle() do { PORTA_OUTTGL = 0x40; } while(0)
#define SPI0_SCK_GetValue() (VPORTA.IN & (0x1 << 6))
#define SPI0_SCK_SetDigitalInput() do { PORTA_DIRCLR = 0x40; } while(0)
#define SPI0_SCK_SetDigitalOutput() do { PORTA_DIRSET = 0x40; } while(0)
#define SPI0_SCK_SetPullUp() do { PORTA_PIN6CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define SPI0_SCK_ResetPullUp() do { PORTA_PIN6CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define SPI0_SCK_SetInverted() do { PORTA_PIN6CTRL  |= PORT_INVEN_bm; } while(0)
#define SPI0_SCK_ResetInverted() do { PORTA_PIN6CTRL  &= ~PORT_INVEN_bm; } while(0)
#define SPI0_SCK_DisableInterruptOnChange() do { PORTA.PIN6CTRL = (PORTA.PIN6CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define SPI0_SCK_EnableInterruptForBothEdges() do { PORTA.PIN6CTRL = (PORTA.PIN6CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define SPI0_SCK_EnableInterruptForRisingEdge() do { PORTA.PIN6CTRL = (PORTA.PIN6CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define SPI0_SCK_EnableInterruptForFallingEdge() do { PORTA.PIN6CTRL = (PORTA.PIN6CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define SPI0_SCK_DisableDigitalInputBuffer() do { PORTA.PIN6CTRL = (PORTA.PIN6CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define SPI0_SCK_EnableInterruptForLowLevelSensing() do { PORTA.PIN6CTRL = (PORTA.PIN6CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)
#define PA6_SetInterruptHandler SPI0_SCK_SetInterruptHandler

//get/set SPI0_SS aliases
#define SPI0_SS_SetHigh() do { PORTA_OUTSET = 0x80; } while(0)
#define SPI0_SS_SetLow() do { PORTA_OUTCLR = 0x80; } while(0)
#define SPI0_SS_Toggle() do { PORTA_OUTTGL = 0x80; } while(0)
#define SPI0_SS_GetValue() (VPORTA.IN & (0x1 << 7))
#define SPI0_SS_SetDigitalInput() do { PORTA_DIRCLR = 0x80; } while(0)
#define SPI0_SS_SetDigitalOutput() do { PORTA_DIRSET = 0x80; } while(0)
#define SPI0_SS_SetPullUp() do { PORTA_PIN7CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define SPI0_SS_ResetPullUp() do { PORTA_PIN7CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define SPI0_SS_SetInverted() do { PORTA_PIN7CTRL  |= PORT_INVEN_bm; } while(0)
#define SPI0_SS_ResetInverted() do { PORTA_PIN7CTRL  &= ~PORT_INVEN_bm; } while(0)
#define SPI0_SS_DisableInterruptOnChange() do { PORTA.PIN7CTRL = (PORTA.PIN7CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define SPI0_SS_EnableInterruptForBothEdges() do { PORTA.PIN7CTRL = (PORTA.PIN7CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define SPI0_SS_EnableInterruptForRisingEdge() do { PORTA.PIN7CTRL = (PORTA.PIN7CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define SPI0_SS_EnableInterruptForFallingEdge() do { PORTA.PIN7CTRL = (PORTA.PIN7CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define SPI0_SS_DisableDigitalInputBuffer() do { PORTA.PIN7CTRL = (PORTA.PIN7CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define SPI0_SS_EnableInterruptForLowLevelSensing() do { PORTA.PIN7CTRL = (PORTA.PIN7CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)
#define PA7_SetInterruptHandler SPI0_SS_SetInterruptHandler

/**
 * @ingroup  pinsdriver
 * @brief GPIO and peripheral I/O initialization
 * @param none
 * @return none
 */
void PIN_MANAGER_Initialize();

/**
 * @ingroup  pinsdriver
 * @brief Default Interrupt Handler for USART0_RX pin. 
 *        This is a predefined interrupt handler to be used together with the USART0_RX_SetInterruptHandler() method.
 *        This handler is called every time the USART0_RX ISR is executed. 
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param none
 * @return none
 */
void USART0_RX_DefaultInterruptHandler(void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt Handler Setter for USART0_RX pin input-sense-config functionality.
 *        Allows selecting an interrupt handler for USART0_RX at application runtime
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param InterruptHandler function pointer.
 * @return none
 */
void USART0_RX_SetInterruptHandler(void (* interruptHandler)(void)) ; 

/**
 * @ingroup  pinsdriver
 * @brief Default Interrupt Handler for USART0_TX pin. 
 *        This is a predefined interrupt handler to be used together with the USART0_TX_SetInterruptHandler() method.
 *        This handler is called every time the USART0_TX ISR is executed. 
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param none
 * @return none
 */
void USART0_TX_DefaultInterruptHandler(void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt Handler Setter for USART0_TX pin input-sense-config functionality.
 *        Allows selecting an interrupt handler for USART0_TX at application runtime
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param InterruptHandler function pointer.
 * @return none
 */
void USART0_TX_SetInterruptHandler(void (* interruptHandler)(void)) ; 

/**
 * @ingroup  pinsdriver
 * @brief Default Interrupt Handler for LUT1_OUT pin. 
 *        This is a predefined interrupt handler to be used together with the LUT1_OUT_SetInterruptHandler() method.
 *        This handler is called every time the LUT1_OUT ISR is executed. 
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param none
 * @return none
 */
void LUT1_OUT_DefaultInterruptHandler(void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt Handler Setter for LUT1_OUT pin input-sense-config functionality.
 *        Allows selecting an interrupt handler for LUT1_OUT at application runtime
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param InterruptHandler function pointer.
 * @return none
 */
void LUT1_OUT_SetInterruptHandler(void (* interruptHandler)(void)) ; 

/**
 * @ingroup  pinsdriver
 * @brief Default Interrupt Handler for TCA0_WO0 pin. 
 *        This is a predefined interrupt handler to be used together with the TCA0_WO0_SetInterruptHandler() method.
 *        This handler is called every time the TCA0_WO0 ISR is executed. 
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param none
 * @return none
 */
void TCA0_WO0_DefaultInterruptHandler(void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt Handler Setter for TCA0_WO0 pin input-sense-config functionality.
 *        Allows selecting an interrupt handler for TCA0_WO0 at application runtime
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param InterruptHandler function pointer.
 * @return none
 */
void TCA0_WO0_SetInterruptHandler(void (* interruptHandler)(void)) ; 

/**
 * @ingroup  pinsdriver
 * @brief Default Interrupt Handler for TCA0_WO2 pin. 
 *        This is a predefined interrupt handler to be used together with the TCA0_WO2_SetInterruptHandler() method.
 *        This handler is called every time the TCA0_WO2 ISR is executed. 
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param none
 * @return none
 */
void TCA0_WO2_DefaultInterruptHandler(void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt Handler Setter for TCA0_WO2 pin input-sense-config functionality.
 *        Allows selecting an interrupt handler for TCA0_WO2 at application runtime
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param InterruptHandler function pointer.
 * @return none
 */
void TCA0_WO2_SetInterruptHandler(void (* interruptHandler)(void)) ; 

/**
 * @ingroup  pinsdriver
 * @brief Default Interrupt Handler for SPI0_MISO pin. 
 *        This is a predefined interrupt handler to be used together with the SPI0_MISO_SetInterruptHandler() method.
 *        This handler is called every time the SPI0_MISO ISR is executed. 
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param none
 * @return none
 */
void SPI0_MISO_DefaultInterruptHandler(void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt Handler Setter for SPI0_MISO pin input-sense-config functionality.
 *        Allows selecting an interrupt handler for SPI0_MISO at application runtime
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param InterruptHandler function pointer.
 * @return none
 */
void SPI0_MISO_SetInterruptHandler(void (* interruptHandler)(void)) ; 

/**
 * @ingroup  pinsdriver
 * @brief Default Interrupt Handler for SPI0_MOSI pin. 
 *        This is a predefined interrupt handler to be used together with the SPI0_MOSI_SetInterruptHandler() method.
 *        This handler is called every time the SPI0_MOSI ISR is executed. 
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param none
 * @return none
 */
void SPI0_MOSI_DefaultInterruptHandler(void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt Handler Setter for SPI0_MOSI pin input-sense-config functionality.
 *        Allows selecting an interrupt handler for SPI0_MOSI at application runtime
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param InterruptHandler function pointer.
 * @return none
 */
void SPI0_MOSI_SetInterruptHandler(void (* interruptHandler)(void)) ; 

/**
 * @ingroup  pinsdriver
 * @brief Default Interrupt Handler for SPI0_SCK pin. 
 *        This is a predefined interrupt handler to be used together with the SPI0_SCK_SetInterruptHandler() method.
 *        This handler is called every time the SPI0_SCK ISR is executed. 
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param none
 * @return none
 */
void SPI0_SCK_DefaultInterruptHandler(void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt Handler Setter for SPI0_SCK pin input-sense-config functionality.
 *        Allows selecting an interrupt handler for SPI0_SCK at application runtime
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param InterruptHandler function pointer.
 * @return none
 */
void SPI0_SCK_SetInterruptHandler(void (* interruptHandler)(void)) ; 

/**
 * @ingroup  pinsdriver
 * @brief Default Interrupt Handler for SPI0_SS pin. 
 *        This is a predefined interrupt handler to be used together with the SPI0_SS_SetInterruptHandler() method.
 *        This handler is called every time the SPI0_SS ISR is executed. 
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param none
 * @return none
 */
void SPI0_SS_DefaultInterruptHandler(void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt Handler Setter for SPI0_SS pin input-sense-config functionality.
 *        Allows selecting an interrupt handler for SPI0_SS at application runtime
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param InterruptHandler function pointer.
 * @return none
 */
void SPI0_SS_SetInterruptHandler(void (* interruptHandler)(void)) ; 
#endif /* PINS_H_INCLUDED */
