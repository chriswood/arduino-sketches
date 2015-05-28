/*
  Drives the 2 digit 7 segment display
 */

const int ANODE1 = A0;
const int ANODE2 = A1;
//bitRead reads right to left
byte numArr[10] = {63, 6, 91, 79, 102, 109, 125, 7, 127, 103};


// the setup routine runs once when you press reset:
void setup() {
  // initialize the digital pin as an output.
    Serial.begin(9600);
    initPins();
}

// the loop routine runs over and over again forever:
void loop() {
    digitalWrite(ANODE1, HIGH);
    digitalWrite(ANODE2, HIGH);
    for(byte l=7;l<100;l++) {
        display(l);
        delay(2000);
    }
}

void display(byte r) {
    if (countDigits(r) > 1) {
        display2(getDigit(r, 1));
        display1(getDigit(r, 2));

    } else {
        display2(r);
        blank(1);
    }  
}

void display1(int n) {
  digitalWrite(ANODE1, HIGH);
    for(int j=0; j<7; j++) {
        digitalWrite(j+2, bitRead(numArr[n], j) ? LOW : HIGH);
    }
}

void display2(int n) {
    int pins[7] = {9,10,11,12,13,A5,A4};
    for(int k=0; k<7; k++) {
        digitalWrite(pins[k], bitRead(numArr[n], k) ? LOW : HIGH);
    }
}

byte countDigits(byte num){
    byte count=0;
    while(num) {
        num=num/10;
        count++;
    }
    return count;
}

byte getDigit(byte num, byte digit) {
    for (byte i=0; i<digit-1; i++) {
      num /= 10;
    }
    return num % 10;
}

void blank(byte spot) {
    if(spot == 1) {
        Serial.println("writing anode 1 low");
        digitalWrite(ANODE1, LOW);
    } else {
      Serial.println("writing anode 2 low");
        digitalWrite(ANODE2, LOW);
    }
}

void initPins() {
    pinMode(ANODE1, OUTPUT);
    pinMode(ANODE2, OUTPUT);

    for(int i=2;i<14;i++) {
        pinMode(i, OUTPUT);
    }
    pinMode(A4, OUTPUT);
    pinMode(A5, OUTPUT);
    blank(1);
    blank(2);
}
