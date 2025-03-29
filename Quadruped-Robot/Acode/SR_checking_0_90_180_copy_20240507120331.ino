#include <Servo.h>


const int NUM_SERVOS = 3;


int servoPins[NUM_SERVOS] = {5, 6, 7};


Servo servos[NUM_SERVOS];

void setup() {
  
  for (int i = 0; i < NUM_SERVOS; i++) {
    servos[i].attach(servoPins[i]);
  }
}

void loop() {
 
  int angles[] = {0, 90, 180};

  for (int i = 0; i < NUM_SERVOS; i++) {
    for (int j = 0; j < sizeof(angles) / sizeof(angles[0]); j++) {
      servos[i].write(angles[j]);
      delay(1000);
    }
  }
}
