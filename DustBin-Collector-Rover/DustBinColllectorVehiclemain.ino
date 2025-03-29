#include <Servo.h>

// Servo motorObjects
Servo servoBase;
Servo servoUpLeft;
Servo servoUpRight;

int joystickX, joystickY;
int joystickXcar, joystickYcar;

// Servo positionVariables
int servoBasePosition;
int servoUpLeftPosition;
int servoUpRightPosition;

const int motor1A = 2;
const int motor1B = 3;
const int motor2A = 4;
const int motor2B = 5;

void setup() {
  Serial.begin(9600);

  servoBase.attach(9);
  servoUpLeft.attach(10);
  servoUpRight.attach(11);

  pinMode(motor1A, OUTPUT);
  pinMode(motor1B, OUTPUT);
  pinMode(motor2A, OUTPUT);
  pinMode(motor2B, OUTPUT);
}

void loop() {

  joystickX = analogRead(A0);
  joystickY = analogRead(A1);

  // Maping joystick values to servo positions (0 to 180 degrees)
  servoBasePosition = map(joystickX, 0, 1023, 0, 180);
  servoUpLeftPosition = map(joystickY, 0, 1023, 0, 180);
  servoUpRightPosition = map(joystickY, 0, 1023, 0, 180);
// servoAngle= (((joystick value-0)*(180-0))/(1203-0))+0

// Joystick Value	Mapped Servo Angle (°)
// 0	0°	Joystick pushed to extreme left
// 512	90°	Joystick in center position
// 1023	180°	Joystick pushed to extreme right

// The joystick center (512) corresponds to 90° on the servo.
// Left (<512) moves the servo below 90° (towards 0°).
// Right (>512) moves the servo above 90° (towards 180°).

  servoBase.write(servoBasePosition);
  servoUpLeft.write(servoUpLeftPosition);
  servoUpRight.write(servoUpRightPosition);
  
  delay(15);

  joystickXcar = analogRead(A2);
  joystickYcar = analogRead(A3);

  int motorSpeed = map(abs(joystickXcar - 512), 0, 512, 0, 255);
  int direction = joystickYcar - 512;

// motorSpeed is calculated by mapping joystickXcar (0-1023) → motor speed (-255 to 255).
// direction is calculated by mapping joystickYcar (0-1023) → direction (-1 to 1).
// Multiplying motorSpeed * direction ensures correct speed and movement.

  //  small dead zone to prevent unwanted movement
  if (abs(joystickXcar - 512) < 50 && abs(joystickYcar - 512) < 50) {
    stopRover();
  } 
  else if (joystickYcar < 450) {
    moveForward(motorSpeed);
  } 
  else if (joystickYcar > 570) {
    moveBackward(motorSpeed);
  } 
  else if (joystickXcar < 450) {
    moveLeft(motorSpeed);
  } 
  else if (joystickXcar > 570) {
    moveRight(motorSpeed);
  }

  delay(15);
}

// move rover left
void moveLeft(int motorSpeed) {
  analogWrite(motor1A, 0);
  analogWrite(motor1B, motorSpeed);
  analogWrite(motor2A, motorSpeed);
  analogWrite(motor2B, 0);
}

//  move rover right
void moveRight(int motorSpeed) {
  analogWrite(motor1A, motorSpeed);
  analogWrite(motor1B, 0);
  analogWrite(motor2A, 0);
  analogWrite(motor2B, motorSpeed);
}

//  move rover forward
void moveForward(int motorSpeed) {
  analogWrite(motor1A, motorSpeed);
  analogWrite(motor1B, 0);
  analogWrite(motor2A, motorSpeed);
  analogWrite(motor2B, 0);
}

// move rover backward
void moveBackward(int motorSpeed) {
  analogWrite(motor1A, 0);
  analogWrite(motor1B, motorSpeed);
  analogWrite(motor2A, 0);
  analogWrite(motor2B, motorSpeed);
}

// stop the rover
void stopRover() {
  analogWrite(motor1A, 0);
  analogWrite(motor1B, 0);
  analogWrite(motor2A, 0);
  analogWrite(motor2B, 0);
}
// If joystick is moved left, call moveLeft(motorSpeed).
// If joystick is moved right, call moveRight(motorSpeed).
// If joystick is moved forward, call moveForward(motorSpeed).
// If joystick is moved backward, call moveBackward(motorSpeed).
//If joystick is centered (between 400–600), call stopRover().