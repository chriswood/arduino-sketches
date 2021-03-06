/*************************************************************************
* File Name          : TestUltrasonicSensor.ino
* Author             : Steve
* Updated            : Steve
* Version            : V1.0.0
* Date               : 2/22/2013
* Description        : Test for Makeblock Electronic modules of Me - 
                       Ultrasonic Sensor. The module can ONLY be connected 
                       to the PORT_3, PORT_4, PORT_5, PORT_6, PORT_7, 
                       PORT_8 of Me - Base Shield. 
* License            : CC-BY-SA 3.0
* Copyright (C) 2013 Maker Works Technology Co., Ltd. All right reserved.
* http://www.makeblock.cc/
**************************************************************************/
#include <Makeblock.h>
#include <Arduino.h>
#include <SoftwareSerial.h>
#include <Wire.h>

MeUltrasonicSensor ultraSensor(PORT_3); //Ultrasonic module can ONLY be connected to port 3, 4, 6, 7, 8 of base shield.
MeDCMotor motor1(M1);
MeDCMotor motor2(M2);
uint8_t speed1 = 180;

void setup()
{
	Serial.begin(9600);

}

void loop()
{
        motor1.run(speed1);
        motor2.run(speed1);
        delay(1000);
        motor1.stop();
        motor2.stop();
	Serial.print("Distance : ");
	Serial.print(ultraSensor.distanceCm());
	Serial.println(" cm cwr");
	delay(200);// the minimal measure interval is 100 milliseconds
}

