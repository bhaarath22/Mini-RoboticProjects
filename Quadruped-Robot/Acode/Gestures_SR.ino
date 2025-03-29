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
  // Home position
  int MasterAngles[3]={90,90,90};
  setMasterAngles(MasterAngles);
  setSlaveFLAngles(MasterAngles);
  setSlaveBRAngles(MasterAngles);
  setSlaveBLAngles(MasterAngles);
  delay(1000);
}

void Gestures() {
  int G1_M[3] = {90, 90,180};
  int G1_FL[3] = {90, 90,0};
  int G1_BR[3] = {90, 90,0};
  int G1_BL[3] = {90, 90,180};
  setMasterAngles(G1_M);
  setSlaveFLAngles(G1_FL);
  setSlaveBRAngles(G1_BR);
  setSlaveBLAngles(G1_BL);
  delay(2000);
  int G2_M[3] = {180, 90,180};
  int G2_FL[3] = {-30, 90,0};
  int G2_BR[3] = {0, 90,0};
  int G2_BL[3] = {180, 90,180};
  setMasterAngles(G2_M);
  setSlaveFLAngles(G2_FL);
  setSlaveBRAngles(G2_BR);
  setSlaveBLAngles(G2_BL);
  delay(2000);
  int G3_M[3] = {90, 0,0};
  int G3_FL[3] = {90, 180,180};
  int G3_BR[3] = {90, 180,180};
  int G3_BL[3] = {90, 0,0};
  setMasterAngles(G3_M);
  setSlaveFLAngles(G3_FL);
  setSlaveBRAngles(G3_BR);
  setSlaveBLAngles(G3_BL);
  delay(2000);

   
}
void HandShake(){
  int G1_HS[3] = {40, 175,0};
  int G2_HS[3] = {90, 175,40};
  setSlaveFLAngles(G1_HS);
  delay(1000);
  setSlaveFLAngles(G2_HS);
}
void Opposite_legMoments(){
  int MBL1[3]={170,90,150};
  int FLBR1[3]={40,90,40};
  setMasterAngles(MBL1);
  delay(1000);
  setSlaveBLAngles(MBL1);
  delay(1000);
  setMasterAngles(MasterAngles);
  setSlaveBLAngles(MasterAngles);
  delay(1000);
  setSlaveFLAngles(FLBR1);
  delay(1000);
  setSlaveBRAngles(FLBR1);
  delay(1000);
  setSlaveFLAngles(MasterAngles);
  setSlaveBRAngles(MasterAngles);

}
void loop() {
  Gestures();
  delay(1000);
  HandShake(); 
  delay(1000);
  Opposite_legMoments();
  delay(1000);

}