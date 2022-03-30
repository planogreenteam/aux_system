const int ButtonHazard = 1;  //Inputs
const int BrakePedal = 2;
const int ButtonRight = 3;
const int ButtonLeft = 4;
unsigned long CurrentMillis = 0;
unsigned long IntervalStart = 0;  // unsigned Long to increase amount of memory
const int Interval = 750;         // interval at which to blink (milliseconds)


const int LedBrake = 5;               // Pin connected to LEDs
const int LedRight = 6;
const int LedLeft = 7;

int BrakeState = 0;                // Variables to decrease digitalRead() calls
int HazardState = 0;               //prev_variables for edge detection
int RightState = 0;
int LeftState = 0;

int blueButton = 13;  //Turn Signal LEDs
int yellowButton = 12;
int greenButton = 11;


void setup() {
  pinMode(LedBrake, OUTPUT);     // Set LED pins as output
  pinMode(LedRight, OUTPUT);
  pinMode(LedLeft, OUTPUT);

  pinMode(ButtonHazard, INPUT);       // Set break as input
  pinMode(BrakePedal, INPUT);     // Set hazard button as input
  pinMode(ButtonRight, INPUT);  // Set right signal as input
  pinMode(ButtonLeft, INPUT);   // Set left signal as input

  pinMode(blueButton, OUTPUT);
  pinMode(yellowButton, OUTPUT);
  pinMode(greenButton, OUTPUT);
}

void loop() {
  CurrentMillis = millis();
  BrakeState = digitalRead(BrakePedal);
  if (BrakeState == HIGH) {
    digitalWrite(LedBrake, HIGH);
  }
  else {
    digitalWrite(LedBrake, LOW);
  }
  HazardState = digitalRead(ButtonHazard);
  if (HazardState == HIGH) {
    if (CurrentMillis - IntervalStart >= Interval) {
      IntervalStart = CurrentMillis;
      if (digitalRead(LedRight) == HIGH || digitalRead(LedLeft) == HIGH) {
        allOff();
      }
      else {
        allOn();
      }
    }
    return;
  }
  else {
    RightState = digitalRead(ButtonRight);
    if (RightState == HIGH) {
      leftOff();
      if (CurrentMillis - IntervalStart >= Interval) {
        IntervalStart = CurrentMillis;
        if (digitalRead(LedRight) == HIGH) {
          rightOff();
        }
        else {
          rightOn();
        }
      }
    }
    LeftState = digitalRead(ButtonLeft);
    if (LeftState == HIGH) {
      rightOff();
      if (CurrentMillis - IntervalStart >= Interval) {
        IntervalStart = CurrentMillis;
        if (digitalRead(LedLeft) == HIGH) {
          leftOff();
        }
        else {
          leftOn();
        }
      }
      return;
    }
    allOff();
  }
}

void allOn() {
  digitalWrite(LedRight, HIGH);
  digitalWrite(LedLeft, HIGH);
}

void allOff() {
  digitalWrite(LedRight, LOW);
  digitalWrite(LedLeft, LOW);
}

void rightOn() {
  digitalWrite(LedRight, HIGH);
  digitalWrite(LedLeft, LOW);
}

void rightOff() {
  digitalWrite(LedRight, LOW);
}

void leftOn() {
  digitalWrite(LedLeft, HIGH);
  digitalWrite(LedRight, LOW);
}

void leftOff() {
  digitalWrite(LedLeft, LOW);
}
