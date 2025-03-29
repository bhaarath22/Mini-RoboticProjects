
  const int motor1A = 2;
const int motor1B = 3;
const int motor2A = 4;
const int motor2B = 5;

int joystickXcar;
int joystickYcar;

void setup() {
  pinMode(motor1A, OUTPUT);
  pinMode(motor1B, OUTPUT);
  pinMode(motor2A, OUTPUT);
  pinMode(motor2B, OUTPUT);
}

void loop() {
  joystickXcar = analogRead(A1);
  joystickYcar = analogRead(A3);

  int motorSpeed = map(joystickXcar, 0, 1023, -255, 255);
  int direction = map(joystickYcar, 0, 1023, -1, 1);
  motorSpeed = motorSpeed * direction;

  if (joystickXcar < 400) {
    moveLeft(motorSpeed);
  } else if (joystickXcar > 600) {
    moveRight(motorSpeed);
  } else if (joystickYcar < 400) {
    moveForward(motorSpeed);
  } else if (joystickYcar > 600) {
    moveBackward(motorSpeed);
  } else {
    stopRover();
  }

  delay(15);
}

void moveLeft(int motorSpeed) {
  digitalWrite(motor1A, LOW);
  digitalWrite(motor1B, HIGH);
  digitalWrite(motor2A, HIGH);
  digitalWrite(motor2B, LOW);
  analogWrite(motor1A, motorSpeed);
  analogWrite(motor2A, motorSpeed);
}

void moveRight(int motorSpeed) {
  digitalWrite(motor1A, HIGH);
  digitalWrite(motor1B, LOW);
  digitalWrite(motor2A, LOW);
  digitalWrite(motor2B, HIGH);
  analogWrite(motor1A, motorSpeed);
  analogWrite(motor2A, motorSpeed);
}

void moveForward(int motorSpeed) {
  digitalWrite(motor1A, HIGH);
  digitalWrite(motor1B, LOW);
  digitalWrite(motor2A, HIGH);
  digitalWrite(motor2B, LOW);
  analogWrite(motor1A, motorSpeed);
  analogWrite(motor2A, motorSpeed);
}

void moveBackward(int motorSpeed) {
  digitalWrite(motor1A, LOW);
  digitalWrite(motor1B, HIGH);
  digitalWrite(motor2A, LOW);
  digitalWrite(motor2B, HIGH);
  analogWrite(motor1A, motorSpeed);
  analogWrite(motor2A, motorSpeed);
}

void stopRover() {
  digitalWrite(motor1A, LOW);
  digitalWrite(motor1B, LOW);
  digitalWrite(motor2A, LOW);
  digitalWrite(motor2B, LOW);
}