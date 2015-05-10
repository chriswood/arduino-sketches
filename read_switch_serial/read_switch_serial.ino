/*

 */
int powerpin = 8;
int analogreadpin = 0;
int val = 0;
String op = "val is ";
void setup()  
{
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  //pinMode(readpin, INPUT);
  pinMode(powerpin, OUTPUT); 
}
//if on is sent to serial, write pin high
void loop() // run over and over
{
  digitalWrite(powerpin, HIGH);
  //int sensorValue = digitalRead(readpin);
  val = analogRead(analogreadpin);
  if (val > 920){
      Serial.println("Turning off voltage.");
      digitalWrite(powerpin, LOW); 
  }
  Serial.println(op + val);
  delay(1000);
}

