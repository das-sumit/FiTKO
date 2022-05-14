// Author: Sumit Das (sumit.das.f@gmail.com)
// Date Created: 5/9/2022
// Microcontroller: Arduino Nano Every

int forceSensorPin = A0;
int green = 3;
int blue = 5;
int red = 6;

int forceSensorValue = 0;
unsigned long startTime = 0;

void setup() {
  pinMode(forceSensorPin, INPUT);
  pinMode(green, OUTPUT);   // middle pin of the N power mosfet
  pinMode(blue, OUTPUT);
  pinMode(red, OUTPUT);
  Serial.begin(9600);
  Serial.println("Starting...");
}

void loop() {
  startTime = millis();       // records the time currently in miliseconds (0.001 seconds) since powered on
  forceSensorValue = analogRead(forceSensorPin);    // analogRead values go from 0 to 1023
  
  analogWrite(red, 255);      // analogWrite values from 0 to 255
  analogWrite(green, 255);    // white = RGB(255,255,255)
  analogWrite(blue, 255);

  while(1)
  {
    forceSensorValue = analogRead(forceSensorPin);    // analogRead values go from 0 to 1023
    if(forceSensorValue > 100)   // If hit, turn green
    {
      analogWrite(red, 0);
      analogWrite(green, 255);
      analogWrite(blue, 0);
      break;
    }
    else if (millis() - startTime > 3000)   // If no hit, turn red
    {
      analogWrite(red, 255);
      analogWrite(green, 0);
      analogWrite(blue, 0);
      break;
    }
  }
  delay(1000);
  Serial.println(forceSensorValue);
}
