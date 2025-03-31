#include <SoftwareSerial.h>

// Define the pins for the Bluetooth module
const int bluetoothTx = 2;  // TX pin of Bluetooth module
const int bluetoothRx = 3;  // RX pin of Bluetooth module

// Create a software serial port for the Bluetooth module
SoftwareSerial bluetooth(bluetoothTx, bluetoothRx);

String voiceCommand = "";

void setup() {
  Serial.begin(9600); // Start serial communication for debugging
  bluetooth.begin(9600); // Start Bluetooth communication

  pinMode(13, OUTPUT); // Set pin 13 as output for the LED
}

void loop() {
  if (bluetooth.available()) {
    char c = bluetooth.read();
    voiceCommand += c;

    if (voiceCommand == "*turn on LED") {
      digitalWrite(13, HIGH); // Turn the LED on
      Serial.println("LED is ON");
      voiceCommand = "";
    } else if (voiceCommand == "*turn off LED") {
      digitalWrite(13, LOW); // Turn the LED off
      Serial.println("LED is OFF");
      voiceCommand = "";
    }
  }

  delay(50); // Small delay to avoid flooding
}
