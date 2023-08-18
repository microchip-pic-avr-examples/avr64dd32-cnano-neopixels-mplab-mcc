
### General Information

| Test Engineer         | Iustinian Bujor |
|:----------------:     | :--------:|
| **Jira Issue**        |[MCU8APPS-38348](https://jira.microchip.com/browse/MCU8APPS-38348)|
|**Git/Bitbucket tag**  | 1.0.0-rc1 |

### Overall Result: **FAIL**

### Software Tools used:
- MPLAB® X IDE 5.40
- MPLAB® XC8 2.31
- AVR-Dx_DFP 1.6.88


### Hardware Tools:
- AVR128DA48 Curiosity Nano (test on AVR64DD32 required when the device is launched)
- Neopixel LED band and other required peripherals
- Neopixel LED click 4x4 matrix



## Scenario: **avr64dd32-cnano-neopixels-mplab-mcc**

| Step | Action | Expected behavior | Result |Status |
|:-----|:------ |:-------------------|:-------------------|:-------------------|
|1| Connect the Curiosity Nano board to the PC using a micro USB cable| The board is detected by Windows |Board detected|-|
|2| Open the avr64dd32-cnano-neopixels-mplab-mcc.X project and flash the program to the board<br> The device needs to be set according to the board being used for the test (even if the name is for a DD device, the initial test will be run on DA) | The program will build without errors and it will be flashed to the target| Board successfully programmed.|-|
|3| Open the web UI provided in the repository (the UI should be intuitive; if there are any problems encountered contact Alex Niculae for more explanations) | The UI should load correctly <br> No glitches should be detected while using the color picker UI; any problems should be noted down |UI started.|-|
|4| Connect the Neopixel band to the board and set all LEDs different colors in the UI: black (brightness 0 on all channels) <br> - white (full brightness on all channels) <br> - red (full brightness on R channel) <br> - green (full brightness on G channel) <br> - blue (full brightness on B channel) <br> a random color that has a value different than 0 on all channels (ex. 0x3C -R, 0xC4 - G, 0x5E - B) <br> - for each example generate the .h file and replace it in the project | The LEDs should light with the color being sent to them without errors |Colors selected in the UI are the same as the color of the LEDs (Tried more configurations)|**PASS**|
|5| Set the first LED to blue (full brightness on B channel), the second LED green (full brightness on G channel) and the third LED red (full brightness on R channel) | The LEDs should light up correctly |LEDs have the correct color as described in the requirement.|**PASS**|
|6| Repeat steps 4 and 5 with the LED click Matrix | The steps should produce the same results as before| The RGB channels do not correspond with the order from the UI. This leads to different colors showed by the LEDs. In the UI the order is RGB, while the LEDs from the 4x4 matrix work on GBR order.|**FAIL**|
