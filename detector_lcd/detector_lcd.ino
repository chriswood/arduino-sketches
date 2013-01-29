#include <SoftwareSerial.h>

const byte RUNSPEED = 150;
const byte MAX_ARRAY_SIZE = 100;
const byte TxPin = 8;
byte index = 0;
byte photocellPin = 0; 
int photocellVal;
int count = 0;
int lightVals[MAX_ARRAY_SIZE];
long sum = 0;
int avg = 0;
int lastVal = 0;
boolean sendMessage1 = true;
boolean sendMessage2 = true;

// I am not sure how the 255 interprets to rxpin = txpin...
SoftwareSerial SerialLCD = SoftwareSerial(255, TxPin);

void setup() { 
    // Get lcd ready
    SerialLCD.begin(9600);
    pinMode(TxPin, OUTPUT);
    digitalWrite(TxPin, HIGH);
    delay(100); //required delay
    //Set up debug serial logging via usb
    Serial.begin(9600);
}

void loop() {
    //check for difference (intruder! :) )
    photocellVal = analogRead(photocellPin);
    if(detect(photocellVal)) {
        setAlarm(); 
        delay(800);
    }
    
    //Now we have a value from 0-1023 that represents the brightness
    //Find the running average
    //If count of vals < 100 send not ready message continue
    if(count < 100) {
        if(sendMessage1) {
            writeLCD("Checking light levels");
            sendMessage1 = false;
        }
        addToArray(index, photocellVal);
        index++;
        count++;
    }
    else {
        if(sendMessage2) {
            SerialLCD.write(13);
            writeLCD("Alarm Ready.");
            sendMessage2 = false;
        }
        //calculate average of current values
        avg = getAvg(); 
        //rotate all values
        lastVal = shiftArray();
        //subtract old value
        sum -= lastVal;
        addToArray(MAX_ARRAY_SIZE - 1, photocellVal);
    }
    //add new value to sum
    sum += photocellVal;
    delay(RUNSPEED);
}

void setAlarm() {
    SerialLCD.write(12);                 // Clear             
    SerialLCD.write(17);                 // Turn backlight on
    delay(5);                           // Required delay
    SerialLCD.write(13);                 // Form feed
    SerialLCD.print("I SEE YOU!!!!");   // Second line
    SerialLCD.write(212);                // Quarter note
    SerialLCD.write(220);                // A tone
    delay(3000);                        // Wait 3 seconds
    SerialLCD.write(18);                 // Turn backlight off
}

int shiftArray() {
    //Return 0th value, and shift all others down
    int oldval = lightVals[0];
    for(int i = 1; i < MAX_ARRAY_SIZE; i++) {
        lightVals[i - 1] = lightVals[i];
    }
    return oldval;
}

void addToArray(byte p, int val) {
    if(p < 100) {
        lightVals[p] = val;
    }
}

int getAvg() {
    if (sum == 0) return 0;
    return sum/MAX_ARRAY_SIZE;
}

boolean detect(int reading) {
    return ((avg > reading) && ((avg - reading) > (0.1 * avg)));
}

void writeLCD(String phrase) {
    SerialLCD.write(12);           // Clear             
    SerialLCD.write(17);           // Turn backlight on
    delay(5);                      // Required delay
    SerialLCD.print(phrase);
}


