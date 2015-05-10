/*

 */
int powerpin = 8;
int readpin = 2;
void setup()  
{
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  Serial.println("Goodnight moon!");
  pinMode(readpin, INPUT);
  pinMode(powerpin, OUTPUT); 
}

void loop() // run over and over
{
  digitalWrite(powerpin, HIGH);
  int sensorValue = digitalRead(readpin);
  Serial.println(sensorValue);
  delay(1000);
}

