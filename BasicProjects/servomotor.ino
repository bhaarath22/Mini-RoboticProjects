#include<Servo.h>
Servo myservo;
int angle=0;

void setup()
{
  myservo.attach(5);
}


void loop()
{
  for (angle=0;angle<=180;angle++)
  {
    myservo.write(angle);
    delay(30);

  }
  for (angle=180;angle>=0;angle--)
  {
    myservo.write(angle);
    delay(30);

  }
}