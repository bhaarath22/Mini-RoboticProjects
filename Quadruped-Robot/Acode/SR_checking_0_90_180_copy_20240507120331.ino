#include <Servo.h>

// Define the number of servos as a constant
const int NUM_SERVOS = 3;

// Define the servo pins as an array
int servoPins[NUM_SERVOS] = {5, 6, 7};

// Create an array of Servo objects
Servo servos[NUM_SERVOS];

void setup() {
  // Attach the servos to their respective pins
  for (int i = 0; i < NUM_SERVOS; i++) {
    servos[i].attach(servoPins[i]);
  }
}

void loop() {
  // Define the angles to move the servos
  int angles[] = {0, 90, 180};

  // Move each servo through the angles
  for (int i = 0; i < NUM_SERVOS; i++) {
    for (int j = 0; j < sizeof(angles) / sizeof(angles[0]); j++) {
      servos[i].write(angles[j]);
      delay(1000);
    }
  }
}
