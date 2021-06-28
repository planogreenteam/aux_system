const int hazardButton = 1;        // Pin connected to hazard button
const int breakPedal = 2;          // Pin connected to break
const int rightTurnSignal = 3;     // Pin connected to right turn signal
const int leftTurnSignal = 4;      // Pin connected to left turn signal

const int brack = 5;         // Pin connected to LEDs
const int turnRight = 6;
const int turnLeft = 7;

int breakState = 0;                // Give break a value
int hazardState = 0;               // Give hazard button a value
int isHazardStateOn = 0;             // 
int rightState = 0;                // Give right signal a vale
int leftState = 0;                 // Give left signal a value

int blueButton = 13;
int yellowButton = 12;
int greenButton = 11;

void setup() {
  pinMode(turnRight, OUTPUT);     // Set LED pins as output
  pinMode(turnLeft, OUTPUT);
  pinMode(brack, OUTPUT);
    
  pinMode(breakPedal, INPUT);       // Set break as input
  pinMode(hazardButton, INPUT);     // Set hazard button as input
  pinMode(rightTurnSignal, INPUT);  // Set right signal as input
  pinMode(leftTurnSignal, INPUT);   // Set left signal as input
 
  pinMode(blueButton, OUTPUT);
  pinMode(yellowButton, OUTPUT);
  pinMode(greenButton, OUTPUT);
}

void loop() {
   
  isHazardStateOn = digitalRead(hazardButton);
  
  stopSignal();
  hazardSignal();
  
  if (isHazardStateOn != HIGH) {
    rightTurn();
    leftTurn();
    digitalWrite(blueButton, LOW);
  }
  else{
  	digitalWrite(blueButton, HIGH);
  }
}  
  
void stopSignal(){
  breakState = digitalRead(breakPedal);    // Read input from break pedal
  if (breakState == HIGH) {                // If pushbutton is pressed, set as HIGH
    digitalWrite(brack, HIGH);                            // Turn on all LEDs
  }
  else{                                    // Other wise all LED are off
    digitalWrite(brack, LOW);
  }
}

void hazardSignal(){
  hazardState = digitalRead(hazardButton);    // Read input from hazard button
  if (hazardState == HIGH) {                  // If pushbutton is pressed, set as HIGH
    allLedOn();                               // Have all LEDs blink
    delay(500);
    allLedOff();
    delay(500);
    allLedOn();
    delay(500);
    allLedOff();
  }
}

void rightTurn(){
  rightState = digitalRead(rightTurnSignal);    // Read input from right turn signal
  if (rightState == HIGH) {                     // If pushbutton is pressed, set as HIGH
     digitalWrite(greenButton, HIGH);
     digitalWrite(turnRight, HIGH);            // Have right LEDs blink
     delay(500);
     digitalWrite(turnRight, LOW);
     delay(500);
     digitalWrite(turnRight, HIGH);
     delay(500);
     digitalWrite(turnRight, LOW);
  }
  else{
  	digitalWrite(greenButton, LOW);
  }
}

void leftTurn(){
  leftState = digitalRead(leftTurnSignal);    // Read input from left signal
  if (leftState == HIGH) {                    // If pushbutton is pressed, set as HIGH
     digitalWrite(yellowButton, HIGH);
     digitalWrite(turnLeft, HIGH);           // Have left LEDs blink
     delay(500);
     digitalWrite(turnLeft, LOW);
     delay(500);
     digitalWrite(turnLeft, HIGH);
     delay(500);
     digitalWrite(turnLeft, LOW);
  }
  else{
  	digitalWrite(yellowButton, LOW);
  }
}

void allLedOn(){
  digitalWrite(turnRight, HIGH);             // Turn on all LEDs
  digitalWrite(turnLeft, HIGH);
}

void allLedOff(){
  digitalWrite(turnRight, LOW);              // Turn off all LEDs
  digitalWrite(turnLeft, LOW);
}