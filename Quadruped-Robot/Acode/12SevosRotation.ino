#include<Servo.h>
 Servo servos[3];
 int servopins[3]={5,6,7};
 void setup(){
for(int i=0; i<3;i++) {
  servos[i].attach(servopins[i]);

}
 }
 void loop(){
//   for(int i=0;i<12;i++){
//     servos[i].write(90);
//     delay(1000);
//   }
  
//   for(int i = 0;i<12;i++){
//     servos[i].write(0);
//     delay(1000);
//   }
//  for(int i=0;i<12;i++){
//     servos[i].write(180);
//     delay(1000);
//   }
     servos[5].write(90);
     delay(1000);
     servos[5].write(0);
     delay(1000);
     servos[5].write(180);
     delay(1000);
     servos[6].write(90);
     delay(1000);
     servos[6].write(0);
     delay(1000);
     servos[6].write(180);
     delay(1000);
     servos[7].write(90);
     delay(1000);
     servos[7].write(0);
     delay(1000);
     servos[7].write(180);
     delay(1000);
    
    
  }
 

