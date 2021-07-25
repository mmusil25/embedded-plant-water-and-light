#include <TimeLib.h>
  // put your setup code here, to run once:
int pumpControl = 2;
#define secondsInADay 86400
#define secondsInThreeHours 3600*3

int thisMoment = 0;
int lightControl = 3;
int CapacitiveMoistureSensor = A0;
float myDryness = 0;


void setup() {
Serial.begin(9600);
pinMode(pumpControl, OUTPUT);
pinMode(lightControl, OUTPUT);
pinMode(CapacitiveMoistureSensor, INPUT);
digitalWrite(pumpControl, HIGH);
digitalWrite(lightControl, LOW);
delay(500);


}

void loop() {
  // put your main code here, to run repeatedly:
Serial.print("The current second is: ");
thisMoment = now();
Serial.print(thisMoment);
Serial.println();

if ((thisMoment % secondsInADay) < secondsInThreeHours){
  //turn on the light
  Serial.print("Time for light! \n");
  digitalWrite(lightControl, LOW);
  }
else {
  Serial.print("Lights out! \n");
  digitalWrite(lightControl, HIGH);
}

Serial.print("Capacitive sensor reading:");
myDryness = analogRead(CapacitiveMoistureSensor);
Serial.println(myDryness);

  if(myDryness>650) {
    Serial.print("Your plant is dry, activating pump.");
    digitalWrite(pumpControl, LOW);}
  else {
    Serial.print("Your plant is watered, pump will stay inactivated.");
    digitalWrite(pumpControl, HIGH);}

Serial.println();
delay(1000);
}
