/*
    (c) 2022 Microchip Technology Inc. and its subsidiaries. 
    
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

#define RX_MAX_BUFFER      255
#define NUMBER_OF_LEDS      16
#define LED_MIN_BRIGHT       0
#define LEDS_INIT_COLORS  {  64,64,64,  64,64, 0,   0,64,64,   0,64, 0,\
                             64, 0,64,  64, 0, 0,   0, 0,64,   0, 0, 0,\
                             96,96,96,  48,48,48,  24,24,24,  12,12,12,\
                              6, 6, 6,   3, 3, 3,   1, 1, 1,   0, 0, 0 } 


typedef struct
{
    uint8_t redChannel;
    uint8_t greenChannel;
    uint8_t blueChannel;
} color_t;


volatile static uint8_t receive_buffer[256];
volatile static bool    receive_flag;

static void ReceiveHandler(void)
{
    static uint8_t rx_index = 0;
    uint8_t rx_data = USART0_Read();
    USART0_Write(rx_data);
    if(receive_flag == true) // ignore all data if parsing is still in progress
        return;

    if(rx_index < RX_MAX_BUFFER)
    {
        receive_buffer[rx_index++] = rx_data;
        if((rx_data == '\n') || (rx_data == '\r'))
        {
            rx_index = 0;
            receive_flag = true;
        }
    }
    else
    {
        rx_index = 0;
        receive_flag = true;
    }
}

static void ParseString(const uint8_t *rx_buffer, color_t *neopixels)
{
    uint8_t i, j, k;
    char *pStr;

    pStr = (char *)rx_buffer;
    j = 0; k = 0;
    for(i = 0; i < (NUMBER_OF_LEDS * 3); i++)
    {
        pStr = strtok(pStr, ",");
        if(pStr != NULL)
        {
            switch(k)
            {
                case 0: neopixels[j].redChannel = (uint8_t)atoi(pStr); break;
                case 1: neopixels[j].greenChannel = (uint8_t)atoi(pStr); break;
                case 2: neopixels[j].blueChannel = (uint8_t)atoi(pStr); j++; break;
            }
            pStr = NULL;
        }
        else
            break;
        k++; if(k == 3) k = 0;
    }
}

static void WriteNeopixel(color_t color)
{
    TCA0_Start();    
    SPI0_ByteExchange(color.greenChannel);    
    SPI0_ByteExchange(color.redChannel);    
    SPI0_ByteExchange(color.blueChannel);
    TCA0_Stop();
}

static void WriteLEDsString(const color_t *frame) 
{
    uint8_t i;
    for(i = 0; i < NUMBER_OF_LEDS; i++)
    {
        WriteNeopixel(frame[i]);
    }
}

static void DumpLEDsString(const color_t *frame) 
{
    uint8_t i;
    for(i = 0; i < NUMBER_OF_LEDS; i++)
    {
        printf("\n\rLED no. %2d:  ", i);
        printf("%3d,", frame[i].redChannel);
        printf("%3d,", frame[i].greenChannel);
        printf("%3d",  frame[i].blueChannel);
    }
    printf("\n\r");
}

static void ClearLEDsString(void)
{
    uint8_t i;
    color_t off = {LED_MIN_BRIGHT, LED_MIN_BRIGHT, LED_MIN_BRIGHT};
     
    for(i = 0; i < NUMBER_OF_LEDS; i++)
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
    color_t neopixels_buffer[NUMBER_OF_LEDS] = LEDS_INIT_COLORS;
    
    /* Initializes MCU, drivers and middleware */
    SYSTEM_Initialize();

    /* initialize serial reception */
    memset((void *)receive_buffer, 0, sizeof(receive_buffer));
    receive_flag = false;
    USART0_RxCompleteCallbackRegister(ReceiveHandler);
    
    /* initialize Neopixel LEDs */
    ClearLEDsString();
    _delay_ms(1000);
    Print_Menu();

    DumpLEDsString(neopixels_buffer);
    WriteLEDsString(neopixels_buffer);
    printf("\n\rPlease enter the new configuration for LEDs:\n\r");
   
    while (1)
    {
        if(receive_flag == true)
        {
            printf("\n\rGot new input string\n\r");
            printf("%s", (char*)receive_buffer);
            ParseString((uint8_t *)receive_buffer, neopixels_buffer);
            DumpLEDsString(neopixels_buffer);

            /* update LEDs string */
            ClearLEDsString();
            _delay_ms(10);
            WriteLEDsString(neopixels_buffer);
            
            /* prepare the reception for a new session */
            memset((void *)receive_buffer, 0, sizeof(receive_buffer));
            receive_flag = false;
            printf("\n\rPlease enter the new configuration for LEDs:\n\r");
        }
    }   
}
