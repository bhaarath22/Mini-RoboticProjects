#include<Servo.h>
Servo ServoMaster[3];
Servo ServoSlaveFL[3];
Servo ServoSlaveBR[3];
Servo ServoSlaveBL[3];

int ServoMasterpins[3]={2,3,4};
int ServoSlaveFLpins[3]={5,6,7};
int ServoSlaveBRpins[3]={8,9,10};
int ServoSlaveBLpins[3]={11,12,13};
int MasterAngles[3] = {90, 90, 90};
void setup(){
  for(int i=0 ; i < 3 ; i++){
    ServoMaster[i].attach(ServoMasterpins[i]);
    ServoSlaveFL[i].attach(ServoSlaveFLpins[i]);
    ServoSlaveBR[i].attach(ServoSlaveBRpins[i]);
    ServoSlaveBL[i].attach(ServoSlaveBLpins[i]);
  }}
  void setServoAngles(Servo servo , int angle){
    servo.write(angle);
  }
void setMasterAngles(int angles[]){
  for(int i=0;i < 3;i++){
    setServoAngles(ServoMaster[i],angles[i]);
  }
}
void setSlaveFLAngles(int angles[]){
  for(int i=0 ;i < 3 ;i++){
    setServoAngles(ServoSlaveFL[i],angles[i]);
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
  }

}

void loop(){
  int MasterAngles[3]={90,90,90};
  setMasterAngles(MasterAngles);
  setSlaveFLAngles(MasterAngles);
  setSlaveBRAngles(MasterAngles);
  setSlaveBLAngles(MasterAngles);
  delay(50);
 int MasterAngles2[3]={150,90, 90};
   setMasterAngles(MasterAngles2);
   setSlaveFLAngles(MasterAngles2);
   setSlaveBRAngles(MasterAngles2);
   setSlaveBLAngles(MasterAngles2);
  delay(10);
}
