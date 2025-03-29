#include<Servo.h>

Servo servo[3];
int Servopin[3]={2,3,4};
void setup() {
  

servo[0].attach(Servopin[0]);
servo[1].attach(Servopin[1]);
servo[2].attach(Servopin[2]);
}

void loop() {

servo[0].write(45);
delay(1000);
servo[0].write(135);
delay(1000);
servo[1].write(45);
delay(1000);
servo[1].write(135);
delay(1000);
servo[2].write(45);
delay(1000);
servo[2].write(135);
delay(1000);
}
