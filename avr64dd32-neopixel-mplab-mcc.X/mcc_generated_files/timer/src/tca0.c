/**
  * TCA0 Generated Driver File
  *
  * @file tca0.c
  *
  * @ingroup tca0_normal
  *
  * @brief This file contains the API implementations for TCA0 module driver in Normal (16-bit) mode.
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


#include "../tca0.h"

const struct TMR_INTERFACE TCA0_Interface = {
    .Initialize = TCA0_Initialize,
    .Start = TCA0_Start,
    .Stop = TCA0_Stop,
    .PeriodCountSet = TCA0_Write,
    .TimeoutCallbackRegister = TCA0_OverflowCallbackRegister,
    .Tasks = NULL
};

void TCA0_DefaultCompare0CallbackRegister(void);
void (*TCA0_CMP0_isr_cb)(void) = &TCA0_DefaultCompare0CallbackRegister;
void TCA0_DefaultCompare1CallbackRegister(void);
void (*TCA0_CMP1_isr_cb)(void) = &TCA0_DefaultCompare1CallbackRegister;
void TCA0_DefaultCompare2CallbackRegister(void);
void (*TCA0_CMP2_isr_cb)(void) = &TCA0_DefaultCompare2CallbackRegister;
void TCA0_DefaultOverflowCallbackRegister(void);
void (*TCA0_OVF_isr_cb)(void) = &TCA0_DefaultOverflowCallbackRegister;

void TCA0_DefaultCompare0CallbackRegister(void)
{
    //Add your ISR code here
}

void TCA0_DefaultCompare1CallbackRegister(void)
{
    //Add your ISR code here
}

void TCA0_DefaultCompare2CallbackRegister(void)
{
    //Add your ISR code here
}

void TCA0_DefaultOverflowCallbackRegister(void)
{
    //Add your ISR code here
}

void TCA0_OverflowCallbackRegister(TCA0_cb_t cb)
{
    TCA0_OVF_isr_cb = cb;
}

void TCA0_Compare0CallbackRegister(TCA0_cb_t cb)
{
    TCA0_CMP0_isr_cb = cb;
}

void TCA0_Compare1CallbackRegister(TCA0_cb_t cb)
{
    TCA0_CMP1_isr_cb = cb;
}

void TCA0_Compare2CallbackRegister(TCA0_cb_t cb)
{
    TCA0_CMP2_isr_cb = cb;
}

ISR(TCA0_CMP0_vect)
{
    if (TCA0_CMP0_isr_cb != NULL)
        (*TCA0_CMP0_isr_cb)();
    
    TCA0.SINGLE.INTFLAGS = TCA_SINGLE_CMP0_bm;
}

ISR(TCA0_CMP1_vect)
{
    if (TCA0_CMP1_isr_cb != NULL)
        (*TCA0_CMP1_isr_cb)();
    
    TCA0.SINGLE.INTFLAGS = TCA_SINGLE_CMP1_bm;
}

ISR(TCA0_CMP2_vect)
{
    if (TCA0_CMP2_isr_cb != NULL)
        (*TCA0_CMP2_isr_cb)();
    
    TCA0.SINGLE.INTFLAGS = TCA_SINGLE_CMP2_bm;
}

ISR(TCA0_OVF_vect)
{
    if (TCA0_OVF_isr_cb != NULL)
        (*TCA0_OVF_isr_cb)();
    
    TCA0.SINGLE.INTFLAGS = TCA_SINGLE_OVF_bm;
}


void TCA0_Initialize(void) {
    // Compare 0
    TCA0.SINGLE.CMP0 = 0xA;
        
    // Compare 1
    TCA0.SINGLE.CMP1 = 0x0;
    
    // Compare 2
    TCA0.SINGLE.CMP2 = 0x11;
        
    // Count
    TCA0.SINGLE.CNT = 0x0;
    
    // ALUPD disabled; CMP0EN enabled; CMP1EN disabled; CMP2EN enabled; WGMODE SINGLESLOPE; 
    TCA0.SINGLE.CTRLB = 0x53;
    
    // CMP0OV disabled; CMP1OV disabled; CMP2OV disabled; 
    TCA0.SINGLE.CTRLC = 0x0;
    
    // SPLITM disabled; 
    TCA0.SINGLE.CTRLD = 0x0;
    
    // CMD NONE; DIR disabled; LUPD disabled; 
    TCA0.SINGLE.CTRLECLR = 0x0;
    
    // CMD NONE; DIR UP; LUPD disabled; 
    TCA0.SINGLE.CTRLESET = 0x0;
    
    // CMP0BV disabled; CMP1BV disabled; CMP2BV disabled; PERBV disabled; 
    TCA0.SINGLE.CTRLFCLR = 0x0;
    
    // CMP0BV disabled; CMP1BV disabled; CMP2BV disabled; PERBV disabled; 
    TCA0.SINGLE.CTRLFSET = 0x0;
    
    // DBGRUN disabled; 
    TCA0.SINGLE.DBGCTRL = 0x0;
    
    // CNTAEI disabled; CNTBEI enabled; EVACTA CNT_POSEDGE; EVACTB RESTART_POSEDGE; 
    TCA0.SINGLE.EVCTRL = 0x90;
    
    // CMP0 disabled; CMP1 disabled; CMP2 disabled; OVF disabled; 
    TCA0.SINGLE.INTCTRL = 0x0;
    
    // CMP0 disabled; CMP1 disabled; CMP2 disabled; OVF disabled; 
    TCA0.SINGLE.INTFLAGS = 0x0;
    
    // Period
    TCA0.SINGLE.PER = 0x95F;
    
    // Temporary data for 16-bit Access
    TCA0.SINGLE.TEMP = 0x0;
    
    // CLKSEL DIV1; ENABLE enabled; RUNSTDBY disabled; 
    TCA0.SINGLE.CTRLA = 0x1;
    
}

void TCA0_Start(void)
{
    TCA0.SINGLE.CTRLA|= TCA_SINGLE_ENABLE_bm;
}

void TCA0_Stop(void)
{
    TCA0.SINGLE.CTRLA&= ~TCA_SINGLE_ENABLE_bm;
}

void TCA0_Write(uint16_t timerVal)
{
    TCA0.SINGLE.PER=timerVal;
}

uint16_t TCA0_Read(void)
{
    uint16_t readVal;

    readVal = TCA0.SINGLE.CNT;

    return readVal;
}

void TCA0_EnableInterrupt(void)
{
        TCA0.SINGLE.INTCTRL = 1 << TCA_SINGLE_CMP0_bp /* Compare 0 Interrupt: enabled */
	 				| 1 << TCA_SINGLE_CMP1_bp /* Compare 1 Interrupt: enabled */
	 				| 1 << TCA_SINGLE_CMP2_bp /* Compare 2 Interrupt: enabled */
	 				| 1 << TCA_SINGLE_OVF_bp; /* Overflow Interrupt: enabled */
}
void TCA0_DisableInterrupt(void)
{
    TCA0.SINGLE.INTCTRL = 0 << TCA_SINGLE_CMP0_bp /* Compare 0 Interrupt: disabled */
	 				| 0 << TCA_SINGLE_CMP1_bp /* Compare 1 Interrupt: disabled */
	 				| 0 << TCA_SINGLE_CMP2_bp /* Compare 2 Interrupt: disabled */
	 				| 0 << TCA_SINGLE_OVF_bp; /* Overflow Interrupt: disabled */
}
void TCA0_ClearOverflowInterruptFlag(void)
{
    TCA0.SINGLE.INTFLAGS = TCA_SINGLE_OVF_bm; /* Clear Overflow Interrupt Flag */
}
bool TCA0_IsOverflowInterruptFlagSet(void)
{
    return ((TCA0.SINGLE.INTFLAGS & TCA_SINGLE_OVF_bm) > 0);
}

void TCA0_ClearCMP0InterruptFlag(void)
{
    TCA0.SINGLE.INTFLAGS = TCA_SINGLE_CMP0_bm; /* Clear Compare Channel-0 Interrupt Flag */
}

bool TCA0_IsCMP0InterruptFlagSet(void)
{
    return ((TCA0.SINGLE.INTFLAGS & TCA_SINGLE_CMP0_bm) > 0);
}

void TCA0_ClearCMP1InterruptFlag(void)
{
    TCA0.SINGLE.INTFLAGS = TCA_SINGLE_CMP1_bm; /* Clear Compare Channel-1 Interrupt Flag */
}

bool TCA0_IsCMP1InterruptFlagSet(void)
{
    return ((TCA0.SINGLE.INTFLAGS & TCA_SINGLE_CMP1_bm) > 0);
}

void TCA0_ClearCMP2InterruptFlag(void)
{
    TCA0.SINGLE.INTFLAGS = TCA_SINGLE_CMP2_bm; /* Clear Compare Channel-2 Interrupt Flag */
}

bool TCA0_IsCMP2InterruptFlagSet(void)
{
    return ((TCA0.SINGLE.INTFLAGS & TCA_SINGLE_CMP2_bm) > 0);
}