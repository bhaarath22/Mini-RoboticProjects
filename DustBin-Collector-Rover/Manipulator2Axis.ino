#include<Servo.h>
Servo servoBase;
Servo servoUpLeft;
Servo servoUpRight;
//variables to store the values of joystick
int joystickX;
int joystickY;
//variables to store position of servos
int servoBasePosition;
int servoUpLeftPosition;
int servoUpRightPosition;



void setup() {

  servoBase.attach(9);
  servoUpLeft.attach(10);
  servoUpRight.attach(11);
  Serial.begin(9600);

}

void loop() {
  joystickX=analogRead(A0);
joystickY=analogRead(A1);

  servoBasePosition=map(joystickX,0,1023,0,180);
servoUpLeftPosition=map(joystickY,0,1023,0,180);
servoUpRightPosition=map(joystickY,0,1023,0,180);


servoBase.write(servoBasePosition);
servoUpLeft.write(servoUpLeftPosition);
servoUpRight.write(servoUpRightPosition);
delay(15);

}