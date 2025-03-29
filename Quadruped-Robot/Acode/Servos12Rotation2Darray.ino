#include<Servo.h>
Servo servos[4][3];
int servoPins[4][3]={{2,3,4},{5,6,7},{8,9,10},{11,12,13}};

void setup() {
  for(int i=0;i<4;i++){
    for(int j=0;j<3;j++){
      servos[i][j].attach(servoPins[i][j]);
    }
  }
}

void loop() {
  for(int i=0;i<4;i++){
    for(int j=0;j<3;j++){
      servos[i][j].write(140);
      delay(10000);
      servos[i][j].write(70);
      delay(10000);

    }
  }


  
}
