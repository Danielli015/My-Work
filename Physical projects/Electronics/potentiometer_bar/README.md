# Potentiometer bar

## Description
This project simulates a charging bar using LEDs and a potentiometer to control the amount of leds that are going to be lighted up

# How it works
In the loop function, a loop checks each LED to see if the potentiometer's max value divided by its number is lower than the necessary for it to turn on (max value/number of LEDs).
## Example
Let's say the potentiometer's value is currently 700.
- LED 1: (1023/6*)1 = 170 < 700 TURN ON
- LED 2: (1023/6*)*2 = 340 < 700 TURN ON
- LED 3: (1023/6*)*3 = 510 < 700 TURN ON
- LED 4: (1023/6*)*4 = 680 < 700 TURN ON
- LED 5: (1023/6*)*5 = 850 > 700 DO NOT TURN ON
- LED 6: (1023/6*)*6 = 1020 > 700 DO NOT TURN ON

## Components
- Arduino UNO
- Potentiometer
- LEDs (this project uses 6)
- Resistors
- Jumper wires

If you change the amount of LEDs you need to modify the leds_count variable right under the LEDs pins variables