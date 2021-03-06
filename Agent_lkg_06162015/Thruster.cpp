#include "Thruster.h"
#include <Servo.h>

Servo motor1;
Servo motor2;
Servo motor3;
Servo motor4;



int Thruster_Init()
{
  //Serial.println("Initialize Thrusters ...");
  motor1.attach(MOTOR1_PIN);
  motor2.attach(MOTOR2_PIN);
  motor3.attach(MOTOR3_PIN);
  motor4.attach(MOTOR4_PIN);
  
  motor1.writeMicroseconds(IDLE);
  motor2.writeMicroseconds(IDLE);
  motor3.writeMicroseconds(IDLE);
  motor4.writeMicroseconds(IDLE);
  //delay(10000);
  return 1;
}

void Thruster_Speed(int *TH)
{
  motor1.writeMicroseconds(TH[0]);
//  Serial.println("1");
  motor2.writeMicroseconds(TH[1]);
//  Serial.println("2");
  motor3.writeMicroseconds(TH[2]);
//  Serial.println("3");
  motor4.writeMicroseconds(TH[3]);
//  Serial.println("4");
  //delay(TH[4]*1000);
  
}

void Thruster_Stop()
{
  motor1.writeMicroseconds(IDLE);
  motor2.writeMicroseconds(IDLE);
  motor3.writeMicroseconds(IDLE);
  motor4.writeMicroseconds(IDLE);   

}
