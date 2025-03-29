#include<Servo.h> // this is a library for servos

Servo servoBase1;
Servo servoBase2;
Servo servoBase3;
Servo servoBase4;
Servo servoThaigh1;
Servo servoThaigh2;
Servo servoThaigh3;
Servo servoThaigh4;
Servo servoFoot1;
Servo servoFoot2;
Servo servoFoot3;
Servo servoFoot4;

void setup(){
  // we can initalize servo to the pins here . using the method attach();
  servoBase1.attach(0);
  servoBase2.attach(1);
  servoBase3.attach(2);
  servoBase4.attach(3);
  servoThaigh1.attach(4);
  servoThaigh2.attach(5);
  servoThaigh3.attach(6);
  servoThaigh4.attach(7);
  servoFoot1.attach(8);
  servoFoot2.attach(9);
  servoFoot3.attach(10);
  servoFoot4.attach(11);
}
void loop(){
  // now i want to set all my servos to 90 so that they can move in bot directions equally, utilizing the method write();
servoBase1.write(90);
  servoBase2.write(90);
  servoBase3.write(90);
  servoBase4.write(90);
  servoThaigh1.write(90);
  servoThaigh2.write(90);
  servoThaigh3.write(90);
  servoThaigh4.write(90);
  servoFoot1.write(90);
  servoFoot2.write(90);
  servoFoot3.write(90);
  servoFoot4.write(90);
  

}


