#include <Servo.h>
#include "HX711.h"

// Pin definitions
const int irSensorPin = 2;
const int trigPin = 5;
const int echoPin = 6;
const int servoPin = 7;
const int hxDtPin = 9;
const int hxSckPin = 10;

// Objects
Servo myServo;
HX711 scale;

// Variables
long duration;
float distance;
float weight;

void setup() {
  Serial.begin(9600);

  pinMode(irSensorPin, INPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  myServo.attach(servoPin);
  myServo.write(0); // Closed position

  scale.begin(hxDtPin, hxSckPin);
  Serial.println("System ready. Waiting for hand detection...");
}

void loop() {
  // Read IR sensor
  int irState = digitalRead(irSensorPin);

  // Read ultrasonic sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  // Read weight
  if (scale.is_ready()) {
    weight = scale.get_units();
  } else {
    weight = 0;
  }

  // Print sensor values
  Serial.print("IR: ");
  Serial.print(irState);
  Serial.print(" | Distance: ");
  Serial.print(distance);
  Serial.print(" cm | Weight: ");
  Serial.println(weight);

  // Trigger servo if hand is detected
  if (irState == LOW || distance < 15) {
    Serial.println("Hand detected - Dispensing sanitizer");

    myServo.write(90); // Dispense
    delay(1000);
    myServo.write(0);  // Return to start
    delay(1000);
  }

  delay(500);
}
