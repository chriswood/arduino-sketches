
const int monitorPin = A0;
int level = 0;

void setup() {
    // Open serial communications and wait for port to open:
    Serial.begin(9600);
}
//if on is sent to serial, write pin high
void loop() {
    if(Serial.available()) {
        level = analogRead(monitorPin);
        Serial.println("monitor pin is at...");
        Serial.println(level);
    } 
    delay(250);
}
