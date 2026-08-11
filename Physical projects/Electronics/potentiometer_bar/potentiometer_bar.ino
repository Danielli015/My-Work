// potentiometer
const int potPin = A0;
int pot_value = 0;

// LEDs
const int led1Pin = 8;
const int led2Pin = 9;
const int led3Pin = 10;
const int led4Pin = 11;
const int led5Pin = 12;
const int led6Pin = 13;
const int leds_count = 6; // amount of leds. change if add or remove LEDs
const int leds_pins[] = {led1Pin, led2Pin, led3Pin, led4Pin, led5Pin, led6Pin};


void setup() {
  // potentiometer setup
  pinMode(potPin, INPUT);
  // LEDs setup
  for(int i = 0; i <= leds_count-1; i++){
    pinMode(leds_pins[i], OUTPUT);
  }


  // serial monitos
  Serial.begin(9600);
}

void loop() {
  pot_value = analogRead(potPin);


  for(int i = 1; i <= leds_count; i++){
    if (pot_value < (1023/leds_count)*i){
      digitalWrite(leds_pins[i-1], HIGH);
    }
    else{
      digitalWrite(leds_pins[i-1], LOW);
    }
  }

}



