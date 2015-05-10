#include "MotorDriver.h"
#include <SoftwareSerial.h>
#include <ParallaxLCD.h>

const bool MOBILE = true;
const int pingPin = 7;
const int LCDPin = 2;
const int PING_LIMIT = 100;
const int MAX_PULSE = 25000;
const int OBJ_THRESHOLD = 40; //centimeters
long duration, dist;

// pin, rows, columns
ParallaxLCD lcd(LCDPin, 2, 16);

void setup() {                
    Serial.begin(9600);
    
    /************ lcd ************/
    lcd.setup();
    lcd.cursorBlock();
    delay(1000);
    lcd.backLightOn();
    
    /*********** motor *********/
    if(MOBILE) {
        motordriver.init();
        motordriver.setSpeed(255,MOTORA);
        motordriver.setSpeed(255,MOTORB);
    }
}

void loop() {
    delay(500);
    dist = measure_dist();
    //Serial.println(dist);
    if(dist && dist < OBJ_THRESHOLD) {
        log_distance(dist);
        play_noise();
      
        if(MOBILE) {
            motordriver.stop();
            delay(250);
            motordriver.rotateLeft();
            delay(1000);
        }
    }
    else if(MOBILE) {
        motordriver.forward();
    } 
}

void log_distance(long dist) {
    lcd.empty();
    lcd.print("Obj spotted at:");
    lcd.at(1, 0, dist);
    //for i = 1 TO 120 step 2
    //freqout spkr,10,(sin(i + 40) * 50)
}

long measure_dist() {
    // Send initial low pulse
    int count = 0;

    while(count < PING_LIMIT) {
        delay(1);
        pinMode(pingPin, OUTPUT);
        digitalWrite(pingPin, LOW);
        delayMicroseconds(2);
        digitalWrite(pingPin, HIGH);
        delayMicroseconds(5);
        digitalWrite(pingPin, LOW);
            
        // measure high pulse from object
        pinMode(pingPin, INPUT);
        duration = pulseIn(pingPin, HIGH);
      
        if(duration < MAX_PULSE) {
            // convert the time into a distance
            return(microsecondsToCentimeters(duration));
            break;
        }
        count++;
    }
    return 0;
}

void play_noise() {
    randomSeed(analogRead(0));
    int n = random(220, 232);
    int s = random(215, 220);
    lcd.playTone(210, s, n);
    for(int i=0; i< 10; i++) {
        int n = random(220, 232);
        int s = random(215, 220);
        //duration, scale, note
        lcd.playTone(208, s, n);
    }
}

long microsecondsToCentimeters(long m){
    // m = microseconds
    return (m / 29 / 2);
}


