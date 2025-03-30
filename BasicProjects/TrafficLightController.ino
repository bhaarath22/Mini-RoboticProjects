int redled =10;
int yellowled=11;
int greenled=12;
void setup() {
  // put your setup code here, to run once:
pinMode(redled,OUTPUT);
pinMode(yellowled,OUTPUT);
pinMode(greenled,OUTPUT);

digitalWrite(redled,LOW);
digitalWrite(yellowled,LOW);
digitalWrite(greenled,LOW);

Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
 // yellow ON
digitalWrite(redled,LOW);
digitalWrite(yellowled,HIGH);
digitalWrite(greenled,LOW);
Serial.println("Yeild mode:ON");
delay(1000);
//GO mode
digitalWrite(redled,LOW);
digitalWrite(yellowled,LOW);
digitalWrite(greenled,HIGH);
Serial.println("GO mode:ON");
delay(2000);
//Stop mode
digitalWrite(redled,HIGH);
digitalWrite(yellowled,LOW);
digitalWrite(greenled,LOW);
Serial.println("Stop mode:ON");
delay(3000);
}
