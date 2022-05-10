// Author: Sumit Das (sumit.das.f@gmail.com)
// Date Created: 5/9/2022

int forceSensorPin = A0;
int forceSensorValue = 0;

void setup() {
  pinMode(forceSensorPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  forceSensorValue = analogRead(forceSensorPin);
  Serial.println(forceSensorValue);
  delay(300); // This delay prevents overwhelming the serial monitor
}
