// Variables for the components in the project.
// if you change the amount of components or their pins you must change these variables

// LEDs pins
const int led1_pin = 8;
const int led2_pin = 9;
const int led3_pin = 10;
const int led4_pin = 11;
const int led5_pin = 12;
const int led6_pin = 13;
int current_led = 8;

// amount of LEDs in the project (start from 0). Modify if add or remove LEDs
const int leds_count = 5;
int leds_pins[] = {led1_pin, led2_pin, led3_pin, led4_pin, led5_pin, led6_pin};

// buttons
const int buttonLeft_pin = 7;
const int buttonRight_pin = 6;
// buzzer
const int buzzer_pin = 2;


// --- MAIN CODE ---

void leds_changing(int button){
//
  if(button == buttonLeft_pin){
// beep
    digitalWrite(buzzer_pin, HIGH);
    delay(100);
    digitalWrite(buzzer_pin, LOW);
    delay(300);

    current_led--;
    if (current_led < leds_pins[0]){
      current_led = leds_pins[leds_count];
    }
  }
  else if(button == buttonRight_pin){
// beep
    digitalWrite(buzzer_pin, HIGH);
    delay(100);
    digitalWrite(buzzer_pin, LOW);
    delay(300);
    current_led++;
    if (current_led > leds_pins[leds_count]){
      current_led = leds_pins[0];
    }
    }
}




void setup() {
  // LEDs setup
  for(int i = 0; i <= leds_count; i++){
    pinMode(leds_pins[i], OUTPUT);
  }
  
  // buttons setup
  pinMode(buttonLeft_pin, INPUT_PULLUP);
  pinMode(buttonRight_pin, INPUT_PULLUP);

  pinMode(buzzer_pin, OUTPUT);
}

void loop() {
// turns current led on
  digitalWrite(current_led, HIGH);

// calls function to change leds when a button is pressed
  if(digitalRead(buttonLeft_pin) == LOW){
    leds_changing(buttonLeft_pin);
  }
  else if (digitalRead(buttonRight_pin) == LOW){
    leds_changing(buttonRight_pin);
  }

// turns leds off
  for(int i = 0; i <= leds_count; i++){
    digitalWrite(leds_pins[i], LOW);
  }

}






