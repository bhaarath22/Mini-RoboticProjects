#include<Servo.h>
Servo ServoMaster[3];
Servo ServoSlaveFL[3];
Servo ServoSlaveBR[3];
Servo ServoSlaveBL[3];

int ServoMasterpins[3] ={2, 3, 4};
int ServoSlaveFLpins[3]={5, 6, 7};
int ServoSlaveBRpins[3]={8,9,10};
int ServoSlaveBLpins[3]={11,12,13};

int MasterAngles[3] = {90, 90, 90};

void setServoAngles(Servo servo, int angle) {
  servo.write(angle);
}

void setMasterAngles(int angles[]) {
  for (int i = 0; i < 3; i++) {
    setServoAngles(ServoMaster[i], angles[i]);
  }
}

void setSlaveFLAngles(int angles[]) {
  for (int i = 0; i < 3; i++) {
    setServoAngles(ServoSlaveFL[i], angles[i]);
  }
}
void setSlaveBRAngles(int angles[]){
  for(int i=0;i<3;i++){
    setServoAngles(ServoSlaveBR[i],angles[i]);
  }
}
void setSlaveBLAngles(int angles[]){
  for(int i=0;i<3;i++){
    setServoAngles(ServoSlaveBL[i],angles[i]);
  }}

void setup() {
  for (int i = 0; i < 3; i++) {
    ServoMaster[i].attach(ServoMasterpins[i]);
    ServoSlaveFL[i].attach(ServoSlaveFLpins[i]);
    ServoSlaveBR[i].attach(ServoSlaveBRpins[i]);
    ServoSlaveBL[i].attach(ServoSlaveBLpins[i]);
  }
  
  int MasterAngles[3]={90,90,90};
  setMasterAngles(MasterAngles);
  setSlaveFLAngles(MasterAngles);
  setSlaveBRAngles(MasterAngles);
  setSlaveBLAngles(MasterAngles);
  delay(1000);
}

void MoveForward() {
  int forwardAnglesM[3] = {140, 80,90};
  int forwardAnglesFL[3] = {40, 100,90};
  int forwardAnglesBR[3] = {140, 100,90};
  int forwardAnglesBL[3] = {40, 80,90};
  // int forwardAngles2[3] ={140,85,90};
  setMasterAngles(forwardAnglesM);
  
  setSlaveFLAngles(forwardAnglesFL);
  delay(1000);
  setMasterAngles(MasterAngles);
  setSlaveFLAngles(MasterAngles);
  setSlaveBRAngles(forwardAnglesBR);
  setSlaveBLAngles(forwardAnglesBL);
  delay(1000);
  setSlaveBRAngles(MasterAngles);
  setSlaveBLAngles(MasterAngles);
  //delay(10); 
}

void MoveBackward() {
  int backwardAngles[3] = {70, 87, 90};
  setMasterAngles(backwardAngles);
  setSlaveFLAngles(backwardAngles);
  setSlaveBRAngles(backwardAngles);
  setSlaveBLAngles(backwardAngles);
  delay(10); 
  setMasterAngles(MasterAngles);
  setSlaveFLAngles(MasterAngles);
  setSlaveBRAngles(MasterAngles);
  setSlaveBLAngles(MasterAngles);
  delay(10); 
}

void TurnRight() {
  int rightAngles[3] = {120, 87, 90};
  setMasterAngles(rightAngles);
  setSlaveFLAngles(rightAngles);
   setSlaveBRAngles(rightAngles);
  setSlaveBLAngles(rightAngles);
  delay(10); 
  setMasterAngles(MasterAngles);
  setSlaveFLAngles(MasterAngles);
  setSlaveBRAngles(MasterAngles);
  setSlaveBLAngles(MasterAngles);
  delay(10); 
}

void TurnLeft() {
  int leftAngles[3] = {80, 87, 90};
  setMasterAngles(leftAngles);
  setSlaveFLAngles(leftAngles);
  setSlaveBRAngles(leftAngles);
  setSlaveBLAngles(leftAngles);
  delay(10); 
  setMasterAngles(MasterAngles);
  setSlaveFLAngles(MasterAngles);
  setSlaveBRAngles(MasterAngles);
  setSlaveBLAngles(MasterAngles);
  delay(10); 
}


void loop() {
  // Your loop code here
   MoveForward();
   
    // MoveBackward();
    // delay(100);
  // TurnRight();
  // delay(1000);
  // TurnLeft();
  // // delay(1000);
  // int Moment[3] ={180 ,0,180};
  // setMasterAngles(Moment);
}
