#include <SoftwareSerial.h>

// set the serial pin
const int TxPin = 8;

#include <SoftwareSerial.h>

// I am not sure how the 255 interprets to rxpin = txpin...
SoftwareSerial SerialLCD = SoftwareSerial(255, TxPin);

void setup() {
    pinMode(TxPin, OUTPUT);
    SerialLCD.begin(9600);
    digitalWrite(TxPin, HIGH);
    delay(100); //Always have to do this
    SerialLCD.write(12);                 // Clear             
    SerialLCD.write(17);                 // Turn backlight on
    delay(5);                           // Required delay
    SerialLCD.print("Hi Grandmama!");  // First line
    SerialLCD.write(13);                 // Form feed
    SerialLCD.print("I Love You!!!!");   // Second line
    SerialLCD.write(212);                // Quarter note
    SerialLCD.write(220);                // A tone
    delay(3000);                        // Wait 3 seconds
    SerialLCD.write(18);                 // Turn backlight off
}

void loop() {
    // set the cursor to column 0, line 1
//    int tones;
//    mySerial.write(212);
//    for (tones = 220; tones < 233; tones++) {
//        mySerial.write(tones);
//        delay(.2);
//    }
  
}
