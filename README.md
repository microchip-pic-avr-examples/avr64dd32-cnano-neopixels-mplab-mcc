<!-- Please do not change this logo with link -->

<a href="https://www.microchip.com" rel="nofollow"><img src="images/microchip.png" alt="MCHP" width="300"/></a>

# Getting Started with Neopixels using the AVR64DD32 Microcontroller using MCC Melody

This repository provides an MPLAB® X project with an MPLAB® Code Configurator (MCC) generated code example for interfacing the CCL and SPI peripherals with Neopixel (WS2812) LEDs.

Furthermore, there is a web interface called **Creator UI** used to choose the color for each Neopixel. This interface can be used to define the size of an LEDs matrix. Such LEDs are connected sequentially but are mounted in the shape of a matrix (or other shape), therefore it is important to know the order in which they are connected.

## Related Documentation

More details and code examples on the AVR64DD32 can be found at the following links:

- [AVR64DD32 Product Page](https://www.microchip.com/wwwproducts/en/AVR64DD32)
- [AVR64DD32 Code Examples on GitHub](https://github.com/microchip-pic-avr-examples?q=AVR64DD32)
- [AVR64DD32 Project Examples in START](https://start.atmel.com/#examples/AVR64DD32CuriosityNano)
- [WS2812 Data Sheet](https://cdn-shop.adafruit.com/datasheets/WS2812.pdf)


## Software Used
- [MPLAB® X IDE](http://www.microchip.com/mplab/mplab-x-ide) v6.00 or newer
- [MPLAB® XC8](http://www.microchip.com/mplab/compilers) v2.36 or newer
- [AVR-Dx Series Device Pack](https://packs.download.microchip.com/) v2.1.152 or newer
- [MPLAB® Code Configurator Melody](https://www.microchip.com/en-us/tools-resources/configure/mplab-code-configurator/melody) v2.1.13 or newer
- AVR Devices Library v4.4.0 or newer
- Content Manager v2.3.7 or newer
- Node.js 16.13.2 or newer


## Hardware Used

- The AVR64DD32 Curiosity Nano Development Board is used as a test platform
    <br><img src="images/AVR64DD32.PNG" width="640">

 - Curiosity Nano Adapter
    <br><img src="images/Curiosity-Nano-Adapter.jpg" height="400">

- MikroElektronika 4x4 RGB LED Matrix Display mikroBus Click Board
    <br><img src="images/4x4_RGB_LED_Matrix.jpg" height="400">
## Operation

To program the Curiosity Nano board with this MPLAB® X project, follow the steps provided in the [How to Program the Curiosity Nano Board](#how-to-program-the-curiosity-nano-board) chapter.<br><br>

## Creator UI

### Prerequisites

- install Node.js 16.12.2 or newer
- from the *creator-ui* directory, open cmd and run the following commands:

> -  npm install -g yarn  
> 	- npm install react-scripts --save    
> 	- yarn start

    

![MCHP](./images/creator-ui.PNG)

### LED Numbering

Creator UI supports three numbering strategies: *row*, *column* and *manual*. *Row* and *column* numbering are described in the image below.

![MCHP](./images/numbering.PNG)

When *manual* numbering is selected, initially no numbers are assigned to the LEDs. Numbers are assigned by the user by clicking each LED in the order in which they are connected: First LED clicked first, second one clicked next, and so on. This way, complex numbering strategies can be achieved. In the image below, the LEDs are numbered in the shape of a spiral.

![MCHP](./images/spiral-numbering.PNG)

### Setting the LEDs Color

Once a numbered LED is clicked, its color can be set using a color picker that appears on the page. The Creator UI image above is descriptive for the Creator UI's functionality.

### Use the Generated Code

When all LEDs are configured, the last step is to click the **Code** button. This is used to create a string that can be used to configure the LEDs on board. After clicking this button, the code can be send through UART interface and the LEDs will be set to the configuration generated by this web interface.

[Back to Top](#getting-started-with-neopixels-using-the-avr64dd32-microcontroller-using-mcc-melody)<br>

## Setup

The board is connected as presented in the following diagram: 

<br><img src="images/Neopixels_setup.jpg" width="640">

Note: The yellow wire is used to connect the output of LUT1 (PC3) to the input of RGB LED Matrix. The connection is: CS3 - RST1.

The following configurations must be made for this project:


- Clock frequency set to 24 MHz
- SPI0:
  - Mode: Master
  - SPI Mode: Mode 1
  - Clock frequency: 750 kHz
- CCL :
  - LUT1 is used
  - IN0: TCA0-WO0
  - IN1: SPI-CLK
  - IN2: TCA0-WO2
  - TRUTH table: 0xE0
  - Clock source: CLKPER
  - LUT1CTRLA: 0x41
  - LUT1CTRLB: 0x9A
  - LUT1CTRLC:  0xA
- TCA0:
  - Single-Slope PWM mode
  - EVCTRL Register:
      - EVCTRL set to 0x96 to set all of the following:
      - EVACTB RESTART_POSEDGE
      - CNTBEI enabled
      - EVACTA UPDOWN
      - CNTAEI disabled)      
  - Channel 0: enabled
  - Channel 2: enabled
  - Channel 0 waveform duty cycle: 0.4
  - Channel 2 waveform duty cycle: 0.7
  - Period: 100 us
- EVSYS:
  - Event Generators:
    - SPI0_CLK: CHANNEL0
  - Event Users:
    - CHANNEL 0: TCA0CNTA, TCA0CNTB


|Pin               | Configuration      |
| :--------------: | :----------------: |
|PC3 (LUT1_OUT)    | Digital Output     |
|PC0 (TCA0-WO0)    | Digital Output     |
|PC1 (TCA0-WO1)    | Digital Output     |
|PC2 (TCA0-WO2)    | Digital Output     |
|PA4 (SPI0-MOSI)   | Digital Output     |
|PA6 (SPI0-CLK)    | Digital Output     |

<br>**Note:** Only PC3(LUT1_OUT) will be used to transmit data to the LED Matrix. The rest of the pins are routed outside for visualization of intermediary signals.

[Back to Top](#getting-started-with-neopixels-using-the-avr64dd32-microcontroller-using-mcc-melody)<br>

## Demo

- The configuration of the Creator UI is presented in the following picture:
  <br><img src="images/Creator-UI_Configuration.PNG">

- When all the LEDs are configured, the **Code** button can be used to generate the string that contains the LEDs configuration as presented below:
  <br><img src="images/creatorUI-generated-code.PNG">


 - There is a message that will appear in the terminal. After that, the string that was generated by CreatorUI can be send to device via UART interface. 
  <br><img src="images/serial-interface.PNG">

*Note*: The string needs to be followed by **Enter**.

- The result of this configuration is presented in the following picture:
  <br><img src="images/Neopixel Setup_result.jpg" width="640">

[Back to Top](#getting-started-with-neopixels-using-the-avr64dd32-microcontroller-using-mcc-melody)<br>

## Summary

Using the peripherals on the AVR DD efficiently, Neopixels can be very easily controlled in software. Moreover, the Creator UI provides an easy way to generate a configuration of the LEDs colors.

[Back to Top](#getting-started-with-neopixels-using-the-avr64dd32-microcontroller-using-mcc-melody)<br>


## How to Program the Curiosity Nano Board

This chapter shows how to use the MPLAB® X IDE to program an AVR® device with an Example_Project.X. This can be applied to any other projects.

- Connect the board to the PC

- Open the Example_Project.X project in MPLAB® X IDE

- Set the Example_Project.X project as main project

  - Right click the project in the **Projects** tab and click **Set as Main Project**
    <br><img src="images/Program_Set_as_Main_Project.PNG" width="600">

- Clean and build the Example_Project.X project

  - Right click the **Example_Project.X** project and select **Clean and Build**
    <br><img src="images/Program_Clean_and_Build.PNG" width="600">

- Select **AVRxxxxx Curiosity Nano** in the Connected Hardware Tool section of the project settings:

  - Right click the project and click **Properties**
  - Click the arrow under the Connected Hardware Tool
  - Select the **AVRxxxxx Curiosity Nano** (click the **SN**), click **Apply** and then **OK**:
    <br><img src="images/Program_Tool_Selection.PNG" width="600">

- Program the project to the board
  - Right click the project and then **Make and Program Device**
    <br><img src="images/Program_Make_and_Program_Device.PNG" width="600">

<br>

- [Back to Creator-UI](#creator-ui) 
- [Back to Setup](#setup) 
- [Back to Demo](#demo) 
- [Back to Summary](#summary) 
- [Back to Top](#getting-started-with-neopixels-using-the-avr64dd32-microcontroller-using-mcc-melody)<br>
