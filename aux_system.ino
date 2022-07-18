

const int ButtonHazard = 5;  //Inputs
const int BrakePedal = 2;
const int ButtonRight = 3;
const int ButtonLeft = 4;
const int ButtonHorn = 10;
unsigned long CurrentMillis = 0;
unsigned long IntervalStart = 0;  // unsigned Long to increase amount of memory
const int Interval = 750;         // interval at which to blink (milliseconds)


const int LedBrake = 6;               // Pin connected to LEDs
const int LedRight = 7;
const int LedLeft = 8;

int HornState = 0;
int BrakeState = 0;                // Variables to decrease digitalRead() calls
int HazardState = 0;               //prev_variables for edge detection
int RightState = 0;
int LeftState = 0;

int blueButton = 13;  //Turn Button LEDs
int yellowButton = 12;
int greenButton = 11;


void setup() { 
  Serial.begin(9600);
  pinMode(LedBrake, OUTPUT);     // Set LED pins as output
  pinMode(LedRight, OUTPUT);
  pinMode(LedLeft, OUTPUT);

  pinMode(ButtonHazard, INPUT_PULLUP);       // Set break as input
  pinMode(BrakePedal, INPUT_PULLUP);     // Set hazard button as input
  pinMode(ButtonRight, INPUT_PULLUP);  // Set right signal as input
  pinMode(ButtonLeft, INPUT_PULLUP);   // Set left signal as input

  pinMode(blueButton, OUTPUT);
  pinMode(yellowButton, OUTPUT);
  pinMode(greenButton, OUTPUT);

  // initialize serial communication at 9600 bits per second:
 
  pinMode(A3, INPUT );
}

void loop() {



  //battery voltage of 17.3
  float lowvoltagevalue = 279;//@15v, set to 279 - low voltage alarm equation is (((1/11)*wanted voltage)/5)*1023
   float voltage = analogRead(A3);
  float readout = voltage;
  if (readout < lowvoltagevalue){
    tone(10,440);
  }
  else{
    noTone(10);
    }
  BrakeState = digitalRead(BrakePedal);//Brake lights//Brown&White Wires
  if (BrakeState == LOW) {
    digitalWrite(LedBrake, HIGH);
  }
  else {
    digitalWrite(LedBrake, LOW);
  }

if(digitalRead(ButtonHazard) == LOW){//hazard lights//input 5      //green input wires

digitalWrite(LedLeft, HIGH);
digitalWrite(LedRight, HIGH);
delay(Interval);
digitalWrite(LedLeft, LOW);
digitalWrite(LedRight, LOW);
delay(Interval);
}
else{
  digitalWrite(LedLeft, LOW);
  digitalWrite(LedRight, LOW);
  }

if(digitalRead(ButtonLeft) == LOW){//Left lights//Blue&White Wires//input pin 4

digitalWrite(LedLeft, HIGH);
delay(Interval);
digitalWrite(LedLeft, LOW);
delay(Interval);
}
  else{

digitalWrite(LedLeft, LOW);
    }
if(digitalRead(ButtonRight) == LOW){//Right lights//Green&White Wires//input pin 3

 digitalWrite(LedRight, HIGH);
 delay(750);
 digitalWrite(LedRight, LOW);
 delay(750);
}
 else{

digitalWrite(LedRight, LOW);
  }

}
/*
  }

  if (CurrentMillis - LCDIntervalStart >= LCDInterval) {
    ADCValue = analogRead(Divider1);
    ADCValue2 = analogRead(Divider2);
    // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 12v)
    voltage = ADCValue * (12.0 / 1023.0);
    // Convert the voltage to current
    voltage2 = ADCValue2 * (12.0 / 1023.0);
    current = (voltage2 / 220) * 1000;
    // print out the value you read:
    // Print a message to the LCD.
    //lcd.clear();
    //lcd.setCursor(0, 0);
    //lcd.print("Voltage: ");
    //lcd.print(voltage);
    //lcd.print("V");
    if (voltage <= 11.90) {
      digitalWrite(LedVoltage, HIGH);
    }
    else {
      digitalWrite(LedVoltage, LOW);
    }
    // set the cursor to column 0, line 1
    // (note: line 1 is the second row, since counting begins with 0):
    //lcd.setCursor(0, 1);
    //lcd.print("Current: ");
    //lcd.print(current);
    //lcd.print("mA");
  }
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