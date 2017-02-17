# esp8266-blindController

Program for the ESP8266 to remotely control a blind. The real blind is controlled using 2 220v relay (one for each direction).

## How to install

- Install PlatformIO
- Import the project
- Rename 'src/config-sample.h' as 'src/config.h' and set the right values
- Build and upload

## Commands

Format is: 

    http://\<device ip\>?c=[up/down/stop]&t=\<duration in milliseconds\>

## Hardware

- ESP8266 (I use a NodeMCU device)
- 2 220v relays with inputs connected to the pins defined in 'src/config.h'
- the real blind, with up/down wires connected to 'NO' entries on the relays
