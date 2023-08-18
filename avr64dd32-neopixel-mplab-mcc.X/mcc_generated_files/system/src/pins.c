/**
 * Generated Driver File
 * 
 * @file pins.c
 * 
 * @ingroup  pinsdriver
 * 
 * @brief This is generated driver implementation for pins. 
 *        This file provides implementations for pin APIs for all pins selected in the GUI.
 *
 * @version Driver Version 1.1.0
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

#include "../pins.h"

static void (*USART0_RX_InterruptHandler)(void);
static void (*USART0_TX_InterruptHandler)(void);
static void (*LUT1_OUT_InterruptHandler)(void);
static void (*TCA0_WO0_InterruptHandler)(void);
static void (*TCA0_WO2_InterruptHandler)(void);
static void (*SPI0_MISO_InterruptHandler)(void);
static void (*SPI0_MOSI_InterruptHandler)(void);
static void (*SPI0_SCK_InterruptHandler)(void);
static void (*SPI0_SS_InterruptHandler)(void);

void PIN_MANAGER_Initialize()
{
  /* DIR Registers Initialization */
    PORTA.DIR = 0xD0;
    PORTC.DIR = 0xD;
    PORTD.DIR = 0x10;
    PORTF.DIR = 0x0;

  /* OUT Registers Initialization */
    PORTA.OUT = 0x0;
    PORTC.OUT = 0x0;
    PORTD.OUT = 0x10;
    PORTF.OUT = 0x0;

  /* PINxCTRL registers Initialization */
    PORTA.PIN0CTRL = 0x0;
    PORTA.PIN1CTRL = 0x0;
    PORTA.PIN2CTRL = 0x0;
    PORTA.PIN3CTRL = 0x0;
    PORTA.PIN4CTRL = 0x0;
    PORTA.PIN5CTRL = 0x0;
    PORTA.PIN6CTRL = 0x0;
    PORTA.PIN7CTRL = 0x0;
    PORTC.PIN0CTRL = 0x0;
    PORTC.PIN1CTRL = 0x0;
    PORTC.PIN2CTRL = 0x0;
    PORTC.PIN3CTRL = 0x0;
    PORTC.PIN4CTRL = 0x0;
    PORTC.PIN5CTRL = 0x0;
    PORTC.PIN6CTRL = 0x0;
    PORTC.PIN7CTRL = 0x0;
    PORTD.PIN0CTRL = 0x0;
    PORTD.PIN1CTRL = 0x0;
    PORTD.PIN2CTRL = 0x0;
    PORTD.PIN3CTRL = 0x0;
    PORTD.PIN4CTRL = 0x0;
    PORTD.PIN5CTRL = 0x0;
    PORTD.PIN6CTRL = 0x0;
    PORTD.PIN7CTRL = 0x0;
    PORTF.PIN0CTRL = 0x0;
    PORTF.PIN1CTRL = 0x0;
    PORTF.PIN2CTRL = 0x0;
    PORTF.PIN3CTRL = 0x0;
    PORTF.PIN4CTRL = 0x0;
    PORTF.PIN5CTRL = 0x0;
    PORTF.PIN6CTRL = 0x0;
    PORTF.PIN7CTRL = 0x0;

  /* PORTMUX Initialization */
    PORTMUX.CCLROUTEA = 0x0;
    PORTMUX.EVSYSROUTEA = 0x0;
    PORTMUX.SPIROUTEA = 0x0;
    PORTMUX.TCAROUTEA = 0x2;
    PORTMUX.TCBROUTEA = 0x0;
    PORTMUX.TCDROUTEA = 0x0;
    PORTMUX.TWIROUTEA = 0x0;
    PORTMUX.USARTROUTEA = 0x3;

  // register default ISC callback functions at runtime; use these methods to register a custom function
    USART0_RX_SetInterruptHandler(USART0_RX_DefaultInterruptHandler);
    USART0_TX_SetInterruptHandler(USART0_TX_DefaultInterruptHandler);
    LUT1_OUT_SetInterruptHandler(LUT1_OUT_DefaultInterruptHandler);
    TCA0_WO0_SetInterruptHandler(TCA0_WO0_DefaultInterruptHandler);
    TCA0_WO2_SetInterruptHandler(TCA0_WO2_DefaultInterruptHandler);
    SPI0_MISO_SetInterruptHandler(SPI0_MISO_DefaultInterruptHandler);
    SPI0_MOSI_SetInterruptHandler(SPI0_MOSI_DefaultInterruptHandler);
    SPI0_SCK_SetInterruptHandler(SPI0_SCK_DefaultInterruptHandler);
    SPI0_SS_SetInterruptHandler(SPI0_SS_DefaultInterruptHandler);
}

/**
  Allows selecting an interrupt handler for USART0_RX at application runtime
*/
void USART0_RX_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    USART0_RX_InterruptHandler = interruptHandler;
}

void USART0_RX_DefaultInterruptHandler(void)
{
    // add your USART0_RX interrupt custom code
    // or set custom function using USART0_RX_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for USART0_TX at application runtime
*/
void USART0_TX_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    USART0_TX_InterruptHandler = interruptHandler;
}

void USART0_TX_DefaultInterruptHandler(void)
{
    // add your USART0_TX interrupt custom code
    // or set custom function using USART0_TX_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for LUT1_OUT at application runtime
*/
void LUT1_OUT_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    LUT1_OUT_InterruptHandler = interruptHandler;
}

void LUT1_OUT_DefaultInterruptHandler(void)
{
    // add your LUT1_OUT interrupt custom code
    // or set custom function using LUT1_OUT_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for TCA0_WO0 at application runtime
*/
void TCA0_WO0_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    TCA0_WO0_InterruptHandler = interruptHandler;
}

void TCA0_WO0_DefaultInterruptHandler(void)
{
    // add your TCA0_WO0 interrupt custom code
    // or set custom function using TCA0_WO0_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for TCA0_WO2 at application runtime
*/
void TCA0_WO2_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    TCA0_WO2_InterruptHandler = interruptHandler;
}

void TCA0_WO2_DefaultInterruptHandler(void)
{
    // add your TCA0_WO2 interrupt custom code
    // or set custom function using TCA0_WO2_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for SPI0_MISO at application runtime
*/
void SPI0_MISO_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    SPI0_MISO_InterruptHandler = interruptHandler;
}

void SPI0_MISO_DefaultInterruptHandler(void)
{
    // add your SPI0_MISO interrupt custom code
    // or set custom function using SPI0_MISO_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for SPI0_MOSI at application runtime
*/
void SPI0_MOSI_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    SPI0_MOSI_InterruptHandler = interruptHandler;
}

void SPI0_MOSI_DefaultInterruptHandler(void)
{
    // add your SPI0_MOSI interrupt custom code
    // or set custom function using SPI0_MOSI_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for SPI0_SCK at application runtime
*/
void SPI0_SCK_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    SPI0_SCK_InterruptHandler = interruptHandler;
}

void SPI0_SCK_DefaultInterruptHandler(void)
{
    // add your SPI0_SCK interrupt custom code
    // or set custom function using SPI0_SCK_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for SPI0_SS at application runtime
*/
void SPI0_SS_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    SPI0_SS_InterruptHandler = interruptHandler;
}

void SPI0_SS_DefaultInterruptHandler(void)
{
    // add your SPI0_SS interrupt custom code
    // or set custom function using SPI0_SS_SetInterruptHandler()
}
ISR(PORTA_PORT_vect)
{ 
    // Call the interrupt handler for the callback registered at runtime
    if(VPORTA.INTFLAGS & PORT_INT5_bm)
    {
       SPI0_MISO_InterruptHandler(); 
    }
    if(VPORTA.INTFLAGS & PORT_INT4_bm)
    {
       SPI0_MOSI_InterruptHandler(); 
    }
    if(VPORTA.INTFLAGS & PORT_INT6_bm)
    {
       SPI0_SCK_InterruptHandler(); 
    }
    if(VPORTA.INTFLAGS & PORT_INT7_bm)
    {
       SPI0_SS_InterruptHandler(); 
    }
    /* Clear interrupt flags */
    VPORTA.INTFLAGS = 0xff;
}

ISR(PORTC_PORT_vect)
{ 
    // Call the interrupt handler for the callback registered at runtime
    if(VPORTC.INTFLAGS & PORT_INT3_bm)
    {
       LUT1_OUT_InterruptHandler(); 
    }
    if(VPORTC.INTFLAGS & PORT_INT0_bm)
    {
       TCA0_WO0_InterruptHandler(); 
    }
    if(VPORTC.INTFLAGS & PORT_INT2_bm)
    {
       TCA0_WO2_InterruptHandler(); 
    }
    /* Clear interrupt flags */
    VPORTC.INTFLAGS = 0xff;
}

ISR(PORTD_PORT_vect)
{ 
    // Call the interrupt handler for the callback registered at runtime
    if(VPORTD.INTFLAGS & PORT_INT5_bm)
    {
       USART0_RX_InterruptHandler(); 
    }
    if(VPORTD.INTFLAGS & PORT_INT4_bm)
    {
       USART0_TX_InterruptHandler(); 
    }
    /* Clear interrupt flags */
    VPORTD.INTFLAGS = 0xff;
}

ISR(PORTF_PORT_vect)
{ 
    /* Clear interrupt flags */
    VPORTF.INTFLAGS = 0xff;
}

/**
 End of File
*/