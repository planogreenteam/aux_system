/*#include <LiquidCrystal.h> //for LCD
   LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
   int LedVoltage = 8;
*/
const int ButtonHazard = 1;  //Inputs
const int BrakePedal = 2;
const int ButtonRight = 3;
const int ButtonLeft = 4;
const int ButtonHorn = 10;
unsigned long CurrentMillis = 0;
unsigned long IntervalStart = 0;  // unsigned Long to increase amount of memory
const int Interval = 750;         // interval at which to blink (milliseconds)


const int LedBrake = 5;               // Pin connected to LEDs
const int LedRight = 6;
const int LedLeft = 7;
const int Horn = 9;

int HornState = 0;
int BrakeState = 0;                // Variables to decrease digitalRead() calls
int HazardState = 0;               //prev_variables for edge detection
int RightState = 0;
int LeftState = 0;

int blueButton = 13;  //Turn Button LEDs
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
  /*
     lcd.begin(16, 2);
     // initialize serial communication at 9600 bits per second:
     Serial.begin(9600);
      pinMode(8, OUTPUT);
  */
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
  HornState = digitalRead(ButtonHorn);
  if (HornState == HIGH) {
    digitalWrite(Horn, HIGH);
  }
  else {
    digitalWrite(Horn, LOW);
  }
  //light start
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
      return;
    }
    else {
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
      }
      else {
        allOff();
      }
    }
  }//end light code

}

/* Arudino LCD exsisting code
   void loop() {
  // read the input on analog pin 0:
  int sensorValue = analogRead(A0);
  int sensorValue2 = analogRead(A1);
  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 12v)
  float voltage = sensorValue * (12.0 / 1023.0);
  // Convert the voltage to current
  float voltage2 = sensorValue2 * (12.0 / 1023.0);
  float current2 = (voltage2 / 220) * 1000;
  // print out the value you read:
  // Print a message to the LCD.
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Voltage: ");
  lcd.print(voltage);
  lcd.print("V");
  if(voltage <= 11.90){
   digitalWrite(led, HIGH);
  }
  else{
    digitalWrite(led, LOW);
  }
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);
  lcd.print("Current: ");
  lcd.print(current2);
  lcd.print("mA");
  delay(1500);
  }
*/
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
