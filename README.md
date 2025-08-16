# ITI Summer Training Project – Industrial Production Line

## Overview
This project is an industrial production line simulation that sorts objects based on their color. The user can configure which color is assigned to each servo motor using a keypad or UART, and the system displays live counts for each sorted color on UART.

**Note:** The color sensor requires a suitable light environment to work accurately.

## Features
- Conveyor belt powered by 12V DC motor
- 3 IR sensors for detecting objects
- 1 color sensor for identifying object color *(needs proper lighting for best accuracy)*
- 2 servo motors for sorting into baskets
- Keypad and UART for user input
- Built with AVR ATmega32 MCU

## Hardware Components
- ATmega32 microcontroller
- 12V DC motor 
- 2 Servo motors
- 3 IR sensors
- TSC3200 Color sensor
- Keypad
- Power supply

## Software & Tools
- AVR-GCC for compiling C code
- AVRDUDE for uploading firmware

## How It Works
1. User assgins colors withc keypad for each servo.
2. Objects move on the conveyor belt driven by the DC motor.
3. IR sensors detect object presence.
4. The color sensor identifies the object's color (under proper lighting conditions).
5. The MCU checks the user-configured color-to-servo mapping.
6. The corresponding servo motor pushes the object into the correct basket.
7. UART updates the count for each color.
