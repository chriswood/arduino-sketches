#include <MotorDriver.h>
#include <IRremote.h>

int RECV_PIN = 7;
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup() {                
    Serial.begin(9600);
    
    irrecv.enableIRIn();
    
    // ********* motor ***********
    motordriver.init();
    motordriver.setSpeed(255, MOTORA);
    motordriver.setSpeed(255, MOTORB);
}

void loop()
{
    if(irrecv.decode(&results)){
        switch(results.value) {
            case 752:
                motordriver.forward();
                delay(2000);
                break;
            case 2800:
                motordriver.backward();
                delay(2000);
                break;
            case 720:
                motordriver.rotateLeft();
                delay(2000);
                break;
            case 3280:
                motordriver.rotateRight();
                delay(2000);
                break;
            default:
                //do last verb
                motordriver.stop();
        }
      //  Serial.println(results.value);
        
        irrecv.resume(); //get next value 
    }
  
    //Serial.println("boo");
    
    //motordriver.forward();
    //delay(2000); // prevent rapid firing
}
