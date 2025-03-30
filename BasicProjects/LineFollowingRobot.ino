int leftSensor = 2;
int middleSensor = 3;
int rightSensor = 4;

//// PINS FOR INPUTS&OUTPUTS

void setup() {
  //// IR SENSOR PINS INPUTS
  pinMode(leftSensor, INPUT);
  pinMode(middleSensor, INPUT);
  pinMode(rightSensor, INPUT);

  //// PINS FOR MOTORS OUTPUTS
  pinMode(5, OUTPUT);  
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
}

void loop() {
  int leftValue = digitalRead(leftSensor);
  int middleValue = digitalRead(middleSensor);
  int rightValue = digitalRead(rightSensor);

  // IF ALL SENSORS SENSORS DETECT BLACK MOVE, FORWARD
  if (leftValue == LOW && middleValue == LOW && rightValue == LOW) {
    moveForward();
  }
  // If left and middle sensors detect black, turn left 
  else if (leftValue == LOW && middleValue == LOW) {
    turnLeft();
  }
  // If right and middle sensors detect black, turn right
  else if (rightValue == LOW && middleValue == LOW) {
    turnRight();
  }
  // If only middle sensor detects black, move forward
  else if (middleValue == LOW) {
    moveForward();
  }
  // If only left sensor detects black, turn left
  else if (leftValue == LOW) {
    turnLeft();
  }
  // If only right sensor detects black, turn right
  else if (rightValue == LOW) {
    turnRight();
  }
  // If no sensors detect black, stop
  else {
    stopMoving();
  }
}

void moveForward() {
  digitalWrite(5, HIGH);
  digitalWrite(9, LOW);
  digitalWrite(10, HIGH);
  digitalWrite(11, LOW);
}

void moveBackward() {
  digitalWrite(5, LOW);
  digitalWrite(9, HIGH);
  digitalWrite(10, LOW);
  digitalWrite(11, HIGH);
}

void turnLeft() {
  digitalWrite(5, LOW);
  digitalWrite(9, HIGH);
  digitalWrite(10, HIGH);
  digitalWrite(11, LOW);
}

void turnRight() {
  digitalWrite(5, HIGH);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, HIGH);
}

void stopMoving() {
  digitalWrite(5, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
}