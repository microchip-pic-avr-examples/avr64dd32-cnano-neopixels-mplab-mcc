/**
 *
 * @file evsys.c
 *
 * @ingroup evsys_driver
 *
 * @brief This file contains the implementation for EVSYS driver
 *
 * @version EVSYS Driver Version 1.1.0
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

#include "../evsys.h"

int8_t EVSYS_Initialize()
{
    //CHANNEL0 SPI0_SCK; 
    EVSYS.CHANNEL0 = 0x68;
    //CHANNEL1 OFF; 
    EVSYS.CHANNEL1 = 0x0;
    //CHANNEL2 OFF; 
    EVSYS.CHANNEL2 = 0x0;
    //CHANNEL3 OFF; 
    EVSYS.CHANNEL3 = 0x0;
    //CHANNEL4 OFF; 
    EVSYS.CHANNEL4 = 0x0;
    //CHANNEL5 OFF; 
    EVSYS.CHANNEL5 = 0x0;
    //USER OFF; 
    EVSYS.USERADC0START = 0x0;
    //USER OFF; 
    EVSYS.USERCCLLUT0A = 0x0;
    //USER OFF; 
    EVSYS.USERCCLLUT0B = 0x0;
    //USER OFF; 
    EVSYS.USERCCLLUT1A = 0x0;
    //USER OFF; 
    EVSYS.USERCCLLUT1B = 0x0;
    //USER OFF; 
    EVSYS.USERCCLLUT2A = 0x0;
    //USER OFF; 
    EVSYS.USERCCLLUT2B = 0x0;
    //USER OFF; 
    EVSYS.USERCCLLUT3A = 0x0;
    //USER OFF; 
    EVSYS.USERCCLLUT3B = 0x0;
    //USER OFF; 
    EVSYS.USEREVSYSEVOUTA = 0x0;
    //USER OFF; 
    EVSYS.USERTCA0CNTA = 0x0;
    //USER CHANNEL0; 
    EVSYS.USERTCA0CNTB = 0x1;
    //USER OFF; 
    EVSYS.USERTCB0CAPT = 0x0;
    //USER OFF; 
    EVSYS.USERTCB0COUNT = 0x0;
    //USER OFF; 
    EVSYS.USERTCB1CAPT = 0x0;
    //USER OFF; 
    EVSYS.USERTCB1COUNT = 0x0;
    //USER OFF; 
    EVSYS.USERUSART0IRDA = 0x0;
    //USER OFF; 
    EVSYS.USERUSART1IRDA = 0x0;
    //USER OFF; 
    EVSYS.USEREVSYSEVOUTC = 0x0;
    //USER OFF; 
    EVSYS.USEREVSYSEVOUTD = 0x0;
    //USER OFF; 
    EVSYS.USEREVSYSEVOUTF = 0x0;
    //USER OFF; 
    EVSYS.USERTCB2CAPT = 0x0;
    //USER OFF; 
    EVSYS.USERTCB2COUNT = 0x0;
    //USER OFF; 
    EVSYS.USERTCD0INPUTA = 0x0;
    //USER OFF; 
    EVSYS.USERTCD0INPUTB = 0x0;
    
    return 0;
}

void EVSYS_SoftwareEventASet(uint8_t channel){
    EVSYS.SWEVENTA = channel;
} 

void EVSYS_SoftwareEventBSet(uint8_t channel){
    EVSYS.SWEVENTB = channel;
}
