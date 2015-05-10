
const int monitorPin = A0;
int level = 0;
char level_char = '0';

void setup() {
    // Open serial communications and wait for port to open:
    Serial.begin(9600);
}
//if on is sent to serial, write pin high
void loop() {
    if(Serial.available()) {
        level_char = Serial.read();
        if(isDigit(level_char)) {
            //convert ascii to number
            //level = (level_char = '0');
            level = analogRead(monitorPin);
            Serial.println("monitor pin is at...");
            Serial.println(level);
        }
    } else {
        Serial.println("waiting...");
    }
    //val = analogRead(A0);
    //Serial.println(val, DEC);
    delay(1500);
  
}

