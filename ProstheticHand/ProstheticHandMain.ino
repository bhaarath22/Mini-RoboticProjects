#include <Servo.h>

#define THRESHOLD 150 //In order to determine the state of the hand
//(Opened/closed)
 #define EMGPIN A3 // Analog pin connected to muscle sensor V3 board
#define  LITTLEPIN 2// digital pin used by little servo
#define  RINGPIN   3 // digital pin used by ring servo
#define  MIDDLEPIN 4 // digital pin used by middle servo
#define  INDEXPIN  5 // digital pin used by index servo
#define   THUMBPIN 6 // digital pin used by thumb servo 


// Constants used to open and close the fingers

#define LITTLE 1
#define  RING   2
#define  MIDDLE 3
#define  INDEX  4
#define  THUMB 5

Servo servoLittleFinger;    // Defineservofingers
Servo servoRingFinger;    // Define servo fingers
Servo servoMiddleFinger;  //Defineservo fingers
Servo servoIndexFinger;  //Define servo fingers
Servo servoThumbFinger;  //Defineservo fingers

int finger;
// Motion routines for hand open and hand close
void openhand(){
for(finger = 1; finger < 6; finger++){openFinger(finger);}}

void closehand(){
for(finger = 1; finger < 6; finger++){closeFinger(finger);}}

//OPEN

void openFinger(int finger){
if(finger== LITTLE)
{servoLittleFinger.write(0);} // Little finger

else if(finger==RING)
{servoRingFinger.write(170);} // ring finger

else if(finger== MIDDLE)
{servoMiddleFinger.write(170);} // middle finger

else if(finger== INDEX)
{servoIndexFinger.write(170);} // INDEX finger

else if(finger== THUMB)
{servoThumbFinger.write(0);} // thumb finger
}

// CLOSE

void closeFinger(int finger){
if(finger == LITTLE)
{servoLittleFinger.write(170);} // little finger

else if(finger == RING)
{servoRingFinger.write(0);} // ring finger

else if(finger == MIDDLE)
{servoMiddleFinger.write(0);} // middle finger

else if(finger == INDEX)
{servoIndexFinger.write(0);} // index finger

else if(finger == THUMB)
{servoThumbFinger.write(170);} // thumb finger
}

void setup(){

Serial.begin(115200); // BAUDRATE 
servoLittleFinger.attach(LITTLEPIN); // Set little finger servo to pin 3
servoRingFinger.attach(RINGPIN); // Set ring finger servo to pin 5
servoMiddleFinger.attach(MIDDLEPIN); // Set MIDDLE finger servo to pin 6
servoIndexFinger.attach(INDEXPIN); // Set lINDEX finger servo to pin 9
servoThumbFinger.attach(THUMBPIN); // Set thumb finger servo to pin 10
}

void loop(){ 
int value = analogRead(EMGPIN);
if(value>THRESHOLD) // THRESHOLD means hand closed
{ closehand();}

else //
{ openhand();}
Serial.println(value); 
}