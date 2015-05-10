
int rin = A0;

// the setup routine runs once when you press reset:
void setup() {                
    Serial.begin(9600);
    Serial.println("Serial Engaged Chris.");
    pinMode(rin, INPUT);
}

// the loop routine runs over and over again forever:
void loop() {
    int sensorValue = analogRead(rin);
    float voltage = sensorValue * (5.0 / 1023.0);
    Serial.println(voltage);
    delay(500);
}
