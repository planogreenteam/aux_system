#include <LiquidCrystal.h>
#include <Wire.h>
#include <Adafruit_ADS1X15.h>

LiquidCrystal lcd(32, 30, 28, 26, 24, 22);
int led = 9;
int piezoBuzzer = 10;
Adafruit_ADS1115 ads1115;

int batteryVoltage = 5.0;
int lowBatteryVoltage = 4.9;
int shuntResistor = 220;

void setup() {
  lcd.begin(16, 2);
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(piezoBuzzer, OUTPUT);
 
  lcd.setCursor(0, 0);
  lcd.print("Starting...");

  for (int i = 3; i >= 1; i--) {
  delay(1000);
  lcd.clear();
  lcd.print(i);
  }
  lcd.clear();
 
  ads1115.begin();
}

void loop() {
 
  //Reading and printing the voltage from the batteries
  int sensorValue = analogRead(A4);                                   // read the input on analog pin 0
  float voltage = sensorValue * (batteryVoltage / 1023.0);            // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 48v)

  //Reading and printing the Input Power from the VE Direct
  //Code for the Input Power VE Direct Program
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("IP: ");
  //lcd.print();
  lcd.print("W");

  //Reading the current from the shunt resistor
  int16_t results;
  results = ads1115.readADC_Differential_0_1();
  Serial.println(results);
  Serial.println("unfiltered");
  float translateMicroVoltage = (results * 188);
  Serial.println(translateMicroVoltage);
  Serial.println("uV");
  float translateVoltage = (translateMicroVoltage * 0.000001);
  Serial.println(translateVoltage);
  Serial.println("V");
  float current = (translateVoltage / shuntResistor);                       //0.0005 is the shunt resistor
  Serial.println(current);
  Serial.println("A");

  //Printing the current from the shunt resistor
  lcd.setCursor(0, 1);
  lcd.print("OP: ");
  lcd.print(voltage * current);
  lcd.print("W");
  delay(650);

  //Setting off the voltage alarm  
  if(voltage <= lowBatteryVoltage){                                   // Override message if the voltage is low
  digitalWrite(led, HIGH);
  tone(piezoBuzzer,4000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(" LOW VOLTAGE! ");
  lcd.setCursor(0, 1);
  lcd.print("   ");
  lcd.print(voltage);
  lcd.print("V");
  delay(650);
  }
  else{
  digitalWrite(led, LOW);
  noTone(piezoBuzzer);  
  lcd.clear();
  }
}
