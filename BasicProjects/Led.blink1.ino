// Pin connected to the LED
const int ledPin = 13;

// Time interval for blinking (in milliseconds)
const int blinkInterval = 1000;

void setup() {
  // Initialize the digital pin as an output
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // Turn the LED on
  digitalWrite(ledPin, HIGH);
  
  // Delay for the specified interval
  delay(blinkInterval);
  
  // Turn the LED off
  digitalWrite(ledPin, LOW);
  
  // Delay for the specified interval
  delay(blinkInterval);
}