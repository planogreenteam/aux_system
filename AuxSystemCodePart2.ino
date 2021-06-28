#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int led = 8;

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  pinMode(8, OUTPUT);
}

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