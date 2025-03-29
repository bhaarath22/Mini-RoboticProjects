#include <Servo.h>


const int MASTER_SERVO_ANGLE = 90;
const int SERVO_COUNT = 4;

Servo servos[SERVO_COUNT];

int servoPins[SERVO_COUNT][3] = {
  {2, 5, 8},  // Master
  {3, 6, 9},  // Slave FL
  {4, 7, 10}, // Slave BR
  {11, 12, 13} // Slave BL
};

void setServoAngle(Servo servo, int angle) {
  servo.write(angle);
}

void setServoAngles(Servo servo, int angles[]) {
  for (int i = 0; i < 3; i++) {
    setServoAngle(servo, angles[i]);
  }
}

void setup() {
  for (int i = 0; i < SERVO_COUNT; i++) {
    servos[i].attach(servoPins[i][0]);
  }
  int masterAngles[3] = {MASTER_SERVO_ANGLE, MASTER_SERVO_ANGLE, MASTER_SERVO_ANGLE};
  setServoAngles(servos[0], masterAngles);
  setServoAngles(servos[1], masterAngles);
  setServoAngles(servos[2], masterAngles);
  setServoAngles(servos[3], masterAngles);
  delay(10);
}

void moveForward() {
  int forwardAngles[3] = {140, 85, 90};
  setServoAngles(servos[0], forwardAngles);
  setServoAngles(servos[1], forwardAngles);
  setServoAngles(servos[2], forwardAngles);
  setServoAngles(servos[3], forwardAngles);
  delay(100);
  int masterAngles[3] = {MASTER_SERVO_ANGLE, MASTER_SERVO_ANGLE, MASTER_SERVO_ANGLE};
  setServoAngles(servos[0], masterAngles);
  setServoAngles(servos[1], masterAngles);
  setServoAngles(servos[2], masterAngles);
  setServoAngles(servos[3], masterAngles);
  delay(10);
}

void loop() {
  moveForward();
  
}
