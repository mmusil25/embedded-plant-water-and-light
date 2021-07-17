
  // put your setup code here, to run once:
int pumpControl = 2;
int CapacitiveMoistureSensor = A0;
float myDryness = 0;

void setup() {
Serial.begin(9600);
pinMode(pumpControl, OUTPUT);
pinMode(CapacitiveMoistureSensor, INPUT);
digitalWrite(pumpControl, HIGH);
delay(500);
}

void loop() {
  // put your main code here, to run repeatedly:

Serial.print("Capacitive sensor reading:");
myDryness = analogRead(CapacitiveMoistureSensor);
Serial.println(myDryness);

  if(myDryness>500) {
    Serial.print("Your plant is dry, activating pump.");
    digitalWrite(pumpControl, LOW);}
  else {
    Serial.print("Your plant is watered, pump will stay inactivated.");
    digitalWrite(pumpControl, HIGH);}

Serial.println();
delay(1000);
}
