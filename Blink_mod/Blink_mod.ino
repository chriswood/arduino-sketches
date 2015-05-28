/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.
 */
 
// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
const int ANODE = A0;
const int a1 = 2;
const int b1 = 3;
char segments[7] = {'a', 'b', 'c', 'd', 'e', 'f', 'g'};
String pin;
// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
    Serial.begin(9600);
    pinMode(ANODE, OUTPUT);
    for(int i=0;i<7;i++) {
        pin = String(segments[i]) + 1;
        Serial.println(pin);
        //pinMode(pin, OUTPUT);
        
    }
    //pinMode(b1, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
    //digitalWrite(ANODE, HIGH);
    //digitalWrite(a1, LOW);
    //digitalWrite(b1, LOW);
}
