int led = 13;
#include "MotorDriver.h"

void setup() {                
    Serial.begin(9600);
    motordriver.init();
    motordriver.setSpeed(255,MOTORA);
}

// the loop routine runs over and over again forever:
void loop() {
    // check if switch is turned right
    if(digitalRead(4) == LOW) {
        motordriver.goForward();
        delay(500);
    } else {
        motordriver.stop();
        delay(500);
    }
    //digitalWrite(3, HIGH); 

}
