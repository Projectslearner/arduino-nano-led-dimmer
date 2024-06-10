/*
    Project name : LED Dimmer
    Modified Date: 10-06-2024
    Code by : Projectslearner
    Website : https://projectslearner.com/learn/arduino-nano-led-dimmer
*/

const int ledPin = 9;  // Pin connected to the LED
int brightness = 0;    // Initial brightness of the LED
int fadeAmount = 5;    // Amount by which to increase/decrease the brightness

void setup() {
  pinMode(ledPin, OUTPUT); // Set the LED pin as an output
  Serial.begin(9600); // Initialize serial communication for debugging
}

void loop() {
  analogWrite(ledPin, brightness); // Set the brightness of the LED
  Serial.print("LED Brightness: ");
  Serial.println(brightness);

  // Change the brightness for the next time through the loop
  brightness = brightness + fadeAmount;

  // Reverse the direction of the fading at the ends of the fade
  if (brightness <= 0 || brightness >= 255) {
    fadeAmount = -fadeAmount; // Reverse the direction
  }

  delay(30); // Wait for 30 milliseconds to see the dimming effect
}
