const int hazardButton = 1;
const int brakePedal = 2;
const int rightTurnSignal = 3;
const int leftTurnSignal = 4;
unsigned long currentMillis = 0;
unsigned long previousMillis = 0;  // unsigned Long to increase amount of memory
const long interval = 750;         // interval at which to blink (milliseconds)


const int brake = 5;               // Pin connected to LEDs
const int turnRight = 6;
const int turnLeft = 7;

int brakeState = 0;                // Variables to decrease digitalRead() calls
int hazardState = 0;               //prev_variables for edge detection
int prev_hazard = 0;
int rightState = 0;
int prev_right = 0;
int leftState = 0;
int prev_left = 0;
int blueButton = 13;
int yellowButton = 12;
int greenButton = 11;

int rightLight = LOW;             //Variables used so that we can compare the LED states below
int leftLight = LOW;

void setup() {
  pinMode(turnRight, OUTPUT);     // Set LED pins as output
  pinMode(turnLeft, OUTPUT);
  pinMode(brake, OUTPUT);

  pinMode(brakePedal, INPUT);       // Set break as input
  pinMode(hazardButton, INPUT);     // Set hazard button as input
  pinMode(rightTurnSignal, INPUT);  // Set right signal as input
  pinMode(leftTurnSignal, INPUT);   // Set left signal as input

  pinMode(blueButton, OUTPUT);
  pinMode(yellowButton, OUTPUT);
  pinMode(greenButton, OUTPUT);
}

void loop() {
  brakeState = digitalRead(brakePedal);
  hazardState = digitalRead(hazardButton);

  if (brakeState == HIGH) {
    digitalWrite(brake, HIGH);
  }
  else {
    digitalWrite(brake, LOW);
  }
  if (hazardState != prev_hazard) {

    if (hazardState == HIGH) {

      previousMillis = currentMillis; //Restarts the Interval
      allLedOn();
      continue;
    }

    else {

      allLedOff()
    }
  }
  else {

    if (hazardState == HIGH) {

      /*Check to change the state of the button.
        using the millis() function, we can see how
        many milliseconds passed since the interval start
        (previousMillis). If this is greater than our interval
        we toggle the LED State*/

      if (currentMillis - previousMillis >= interval) { //if the interval has passed
        //restart the interval
        previousMillis = currentMillis;

        // if the LED is off turn it on and vice-versa:
        if (ledState == LOW) {
          ledState = HIGH;
        }
        else {
          ledState = LOW;
        }
      }
    }
  }

}
void allLEDOn() {
  rightLight = HIGH;
}
