#include "MotorDriver.h"
#include <SoftwareSerial.h>
#include <ParallaxLCD.h>

const int pingPin = 7;
const int LCDPin = 2;

// pin, rows, columns
ParallaxLCD lcd(LCDPin, 2, 16);

void setup() {                
    Serial.begin(9600);
    
    // ********* lcd *************
    lcd.setup();
    lcd.cursorBlock();
    delay(1000);
    
    // ********* motor ***********
    motordriver.init();
    motordriver.setSpeed(255,MOTORA);
    motordriver.setSpeed(255,MOTORB);
}

void loop()
{

  
    // establish variables for duration of the ping, 
    // and the distance result in centimeters:
    long duration, cm;

    // The PING))) is triggered by a HIGH pulse of 2 or more microseconds.
    // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
    pinMode(pingPin, OUTPUT);
    digitalWrite(pingPin, LOW);
    delayMicroseconds(2);
    digitalWrite(pingPin, HIGH);
    delayMicroseconds(5);
    digitalWrite(pingPin, LOW);

    // The same pin is used to read the signal from the PING))): a HIGH
    // pulse whose duration is the time (in microseconds) from the sending
    // of the ping to the reception of its echo off of an object.
    pinMode(pingPin, INPUT);
    duration = pulseIn(pingPin, HIGH);

    // convert the time into a distance
    cm = microsecondsToCentimeters(duration);
  
    delay(500); // prevent rapid firing
    if(cm > 50) {
//    // turn around 
//      motordriver.forward();
//      delay(170);
//  } else {
//      motordriver.stop();
//      delay(250);
//      motordriver.rotateLeft();
//      delay(5000);
//  }
  
    Serial.print(cm);
    Serial.print("cm");
    Serial.println();
  
}



long microsecondsToCentimeters(long m){
    // m = microseconds
    // The speed of sound is 340 m/s or 29 microseconds per centimeter.
    // The ping travels out and back, so to find the distance of the
    // object we take half of the distance travelled.
    return (m / 29 / 2);
}
