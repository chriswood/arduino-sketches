

int val;

void setup()
{
Serial.begin(9600); // sets the serial port to 9600
}

void loop()
{

val = analogRead(A1); // read analog input pin 0

Serial.println(val);

delay(200); // wait 10ms for next reading

} 
