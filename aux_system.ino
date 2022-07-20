
const int ButtonHazard = 5;  //Inputs
const int BrakePedal = 2;
const int ButtonRight = 3;
const int ButtonLeft = 4;
const int ButtonHorn = 10; 
const int Interval = 750;         // interval at which to blink (milliseconds)


const int LedBrake = 6;               // Pin connected to LEDs
const int LedRight = 7;
const int LedLeft = 8;

int BrakeState = 0;
      
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LedBrake, OUTPUT);     // Set LED pins as output
  pinMode(LedRight, OUTPUT);
  pinMode(LedLeft, OUTPUT);

  pinMode(ButtonHazard, INPUT_PULLUP);       // Set break as input
  pinMode(BrakePedal, INPUT_PULLUP);     // Set hazard button as input
  pinMode(ButtonRight, INPUT_PULLUP);  // Set right signal as input
  pinMode(ButtonLeft, INPUT_PULLUP);   // Set left signal as input


  // initialize serial communication at 9600 bits per second:
 
  pinMode(A3, INPUT );
  pinMode(10, OUTPUT);

void loop() {
  // put your main code here, to run repeatedly:

float lowvoltagevalue = 316;//@15v, set to 279 - low voltage alarm equation is (((1/11)*wanted voltage)/5)*1023
   float voltage = analogRead(A3);
  float readout = voltage;
  Serial.println(readout);
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
