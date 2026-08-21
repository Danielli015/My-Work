# LED direction control ⬅️💡➡️
Small Arduino project made by me.

## Description
This project goal is to use 2 buttons to control the direction the LED will move, going left or right. For an example, if the user press the left button, the LED on will move to left until the button is released.

# How it works
In the loop function, every execution checks if one of the buttons is pressed. If yes, it calls the "leds_changing" function, responsible for moving the LED and activating the buzzer. Inside this function, it checks if it is the right or left LED being pressed and either makes the "current_led" variable higher (right) or lower (left). Back in the loop function, it turns off the other LEDs that aren't the current one.

## Components
- Arduino UNO
- Jumper wires
- 6 LEDs (you can add as many as you wish)
- Resistors (one for each LED)
- 2 buttons
- Active or passive buzzer