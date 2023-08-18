/*
    (c) 2023 Microchip Technology Inc. and its subsidiaries.

    Subject to your compliance with these terms, you may use Microchip software and any
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party
    license terms applicable to your use of third party software (including open source software) that
    may accompany Microchip software.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS
    FOR A PARTICULAR PURPOSE.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS
    SOFTWARE.
*/

#include "mcc_generated_files/system/system.h"

#include <util/delay.h>

#include <string.h>

#define NUMBER_OF_LEDS    ( 16 )
#define RGB_COUNT         ( 3 )
#define LED_MIN_BRIGHT    ( 0 )
#define RX_MAX_BUFFER     ( 255 )

typedef struct COLOR
{
    uint8_t redChannel;
    uint8_t greenChannel;
    uint8_t blueChannel;
} color_t;


static volatile uint8_t receiveBuffer[RX_MAX_BUFFER + 1];
static volatile bool receiveFlag;


static void ReceiveHandler(void)
{
    static uint8_t rxIndex = 0;
    uint8_t rxData = USART0_Read();
    USART0_Write(rxData);
    if (receiveFlag == true) 
    {
        // Ignore all data if parsing is still in progress
        return;
    }

    if (rxIndex < RX_MAX_BUFFER)
    {
        receiveBuffer[rxIndex++] = rxData;
        if ((rxData == '\n') || (rxData == '\r'))
        {
            rxIndex = 0;
            receiveFlag = true;
        }
    }
    else
    {
        rxIndex = 0;
        receiveFlag = true;
    }
}

static void ParseString(uint8_t * const rxBuffer, color_t * const neopixels)
{
    char * currentColorComponent = (char *) rxBuffer;

    uint8_t tripletIdx = 0;
    uint8_t currentColor = 0; 
    for (uint8_t colorComponentIdx = 0; colorComponentIdx < (NUMBER_OF_LEDS * RGB_COUNT); ++colorComponentIdx)
    {
        currentColorComponent = strtok(currentColorComponent, ",");
        if (currentColorComponent != NULL)
        {
            switch (tripletIdx)
            {
                case 0: 
                    neopixels[currentColor].redChannel = (uint8_t) atoi(currentColorComponent); 
                    break;
                case 1: 
                    neopixels[currentColor].greenChannel = (uint8_t) atoi(currentColorComponent); 
                    break;
                case 2: 
                    neopixels[currentColor].blueChannel = (uint8_t) atoi(currentColorComponent); 
                    ++currentColor; 
                    break;
            }
            currentColorComponent = NULL;
        }
        else
        {
            break;
        }
        
        tripletIdx = (tripletIdx + 1) % RGB_COUNT;
    }
}

static void WriteNeopixel(color_t const color)
{
    TCA0_Start();
    
    SPI0_ByteExchange(color.greenChannel);    
    SPI0_ByteExchange(color.redChannel);    
    SPI0_ByteExchange(color.blueChannel);
    
    TCA0_Stop();
}

static void WriteLEDsString(color_t const * const frame) 
{
    for (uint8_t idx = 0; idx < NUMBER_OF_LEDS; ++idx)
    {
        WriteNeopixel(frame[idx]);
    }
}

static void DumpLEDsString(color_t const * const frame) 
{
    for (uint8_t idx = 0; idx < NUMBER_OF_LEDS; ++idx)
    {
        printf("\n\rLED no. %2d: (", idx);
        printf("%3d,", frame[idx].redChannel);
        printf("%3d,", frame[idx].greenChannel);
        printf("%3d)", frame[idx].blueChannel);
    }
    printf("\n\r");
}

static void ClearLEDsString(void)
{
    static color_t off = { LED_MIN_BRIGHT, LED_MIN_BRIGHT, LED_MIN_BRIGHT };
     
    for (uint8_t idx = 0; idx < NUMBER_OF_LEDS; ++idx)
    {
        WriteNeopixel(off);
    }
} 

static void Print_Menu(void)
{
    printf("\n\r");
    printf("********************************************************************************************************\n\r");
    printf("*                          Neopixels application for AVR64DD32 Curiosity Nano                          *\n\r");
    printf("********************************************************************************************************\n\r");
    printf("*        MMMMMMMMMNddhysyyyysyyhdmMMNNNMMMMM                                                           *\r\n");
    printf("*        MMMMMMmhssssssssssssssssshMNmmMMMMM                                                           *\r\n");
    printf("*        MMMMdyssssssssssssssssssssyNMMMMMMM                                                           *\r\n");
    printf("*        MMmyssssso-`.ossssssso-.-osymMMMMMM                                                           *\r\n");
    printf("*        Mdssssss/`   `/sssss:    `+ssdMMMMM       __  __ _                     _     _                *\r\n");
    printf("*        mssssss/       -sss-       /ssyNMMM      |  \\/  (_)                   | |   (_)               *\r\n");
    printf("*        yssssoso-       .oso.       -ssymMM      | \\  / |_  ___ _ __ ___   ___| |__  _ _ __           *\r\n");
    printf("*        ysso- -ss/`      `/ss-       .ossdM      | |\\/| | |/ __| '__/ _ \\ / __| '_ \\| | '_ \\          *\r\n");
    printf("*        ys+`   .os+`       :ss/`      `/ssh      | |  | | | (__| | | (_) | (__| | | | | |_) |         *\r\n");
    printf("*        y:      `+so-       .os+`       :sh      |_|  |_|_|\\___|_|  \\___/ \\___|_| |_|_| .__/          *\r\n");
    printf("*        m`      -osss/       -sso-       /M                                           | |             *\r\n");
    printf("*        Mh`   `/ssssss+`    :sssss/     -NM                                           |_|             *\r\n");
    printf("*        MMm: -osssssssso-`.+sssssss+`  +NMM                                                           *\r\n");
    printf("*        MMMMhysssssssssssssssssssssso+mMMMM                                                           *\r\n");
    printf("*        MMMMMMNdysssssssssssssssssydNMMMMMM                                                           *\r\n");
    printf("*        MMMMMMMMMNmdhyyysssyyhhdmMMMMMMMMMM                                                           *\r\n");
    printf("********************************************************************************************************\n\r");
}

void main(void)
{
    color_t neopixelsBuffer[NUMBER_OF_LEDS] = {
        { 64, 64, 64 }, { 64, 64,  0 }, {  0, 64, 64 }, {  0, 64,  0 },
        { 64,  0, 64 }, { 64,  0,  0 }, {  0,  0, 64 }, {  0,  0,  0 },
        { 96, 96, 96 }, { 48, 48, 48 }, { 24, 24, 24 }, { 12, 12, 12 },
        {  6,  6,  6 }, {  3,  3,  3 }, {  1,  1,  1 }, {  0,  0,  0 } 
    };
    
    SYSTEM_Initialize();

    // Initialize serial reception
    memset((void *) receiveBuffer, 0, sizeof(receiveBuffer));
    receiveFlag = false;
    USART0_RxCompleteCallbackRegister(ReceiveHandler);
    
    // Initialize Neopixel LEDs
    ClearLEDsString();
    _delay_ms(1000);
    Print_Menu();

    DumpLEDsString(neopixelsBuffer);
    WriteLEDsString(neopixelsBuffer);
    printf("\n\rPlease enter the new configuration for LEDs:\n\r");
   
    while (true)
    {
        if (receiveFlag == true)
        {
            printf("\n\rGot new input string\n\r");
            printf("%s", (char *) receiveBuffer);
            ParseString((uint8_t *) receiveBuffer, neopixelsBuffer);
            DumpLEDsString(neopixelsBuffer);

            // Update LEDs string
            ClearLEDsString();
            _delay_ms(10);
            WriteLEDsString(neopixelsBuffer);
            
            // Prepare the reception for a new session
            memset((void *) receiveBuffer, 0, sizeof(receiveBuffer));
            receiveFlag = false;
            printf("\n\rPlease enter the new configuration for LEDs:\n\r");
        }
    }   
}
