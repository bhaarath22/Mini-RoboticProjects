int i;
void setup() {
 pinMode(3,OUTPUT);
 pinMode(2,INPUT);
 Serial.begin(9600);
}

void loop() {
 i = digitalRead(2);
 Serial.print(i);
 if(i==0)
 {
  digitalWrite(3,HIGH);
  delay(250);
 }
 else if(i==1)
 {
  digitalWrite(3,LOW);
  delay(250);
 }
}