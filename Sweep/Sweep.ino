// Sweep
// by BARRAGAN <http://barraganstudio.com> 
// This example code is in the public domain.


#include <Servo.h> 
 
Servo myservo;
int servoPin = 9;
int pos = 0;    // variable to store the servo position 
 
void setup() 
{ 
    Serial.begin(9600);

    myservo.attach(servoPin, 600, 2100);  // attaches the servo on pin 9 to the servo object 
    myservo.write(0); //reset
    delay(1500);
    Serial.println(myservo.read());
} 
 
 
void loop() 
{ 
    
    
    for(pos = 0; pos < 180; pos += 1)  // goes from 0 degrees to 180 degrees 
    {                                  // in steps of 1 degree 
        myservo.write(pos);              // tell servo to go to position in variable 'pos' 
        delay(50);                       // waits 15ms for the servo to reach the position 
    } 
  for(pos = 180; pos>=1; pos-=1)     // goes from 180 degrees to 0 degrees 
  {                                
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(50);                       // waits 15ms for the servo to reach the position 
  } 
 
} 
