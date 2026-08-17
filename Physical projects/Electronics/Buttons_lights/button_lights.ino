// LED pins
const int led1Pin = 5;
const int led2Pin = 4;
const int led3Pin = 3;
const int led4Pin = 2;
// button pins
const int button1Pin = 13;
const int button2Pin = 12;
const int button3Pin = 11;
const int button4Pin = 10;


void setup() {
  // LEDs setup
  pinMode(led1Pin, OUTPUT);
  pinMode(led2Pin, OUTPUT);
  pinMode(led3Pin, OUTPUT);
  pinMode(led4Pin, OUTPUT);
  // buttons setup
  pinMode(button1Pin, INPUT_PULLUP);
  pinMode(button2Pin, INPUT_PULLUP);
  pinMode(button3Pin, INPUT_PULLUP);
  pinMode(button4Pin, INPUT_PULLUP);
}

void loop() {
  //check if each button is pressed
  if(digitalRead(button1Pin) == LOW){
    digitalWrite(led1Pin, HIGH);
  }
  if(digitalRead(button2Pin) == LOW){
    digitalWrite(led2Pin, HIGH);
  }
  if(digitalRead(button3Pin) == LOW){
    digitalWrite(led3Pin, HIGH);
  }
  if(digitalRead(button4Pin) == LOW){
    digitalWrite(led4Pin, HIGH);
  }




// turn LEDs off after button pressed
  digitalWrite(led1Pin, LOW);
  digitalWrite(led2Pin, LOW);
  digitalWrite(led3Pin, LOW);
  digitalWrite(led4Pin, LOW);
}






