// pins variables
int potentiometer_pin = A0;
int speaker_pin = 2;


void setup() {
  // setups
  pinMode(potentiometer_pin, INPUT);
  pinMode(speaker_pin, OUTPUT);

}

void loop() {
  // sets speaker tone as potentiometer value *2
  tone(speaker_pin, analogRead(potentiometer_pin)*2);
  delay(500);

}
