Automatic Hand Sanitizer Dispenser (Arduino)

This project is a contactless automatic hand sanitizer dispenser built using Arduino UNO, multiple sensors, and a servo motor. It detects a hand and dispenses sanitizer automatically without physical contact, making it hygienic and safe.

Components Used
1.Arduino UNO
2.IR Sensor
3.Ultrasonic Sensor (HC-SR04)
4.3kg Load Cell with HX711 Module
5.MG995 Servo Motor
6.Breadboard
7.Jumper Wires
8.External Battery / Power Supply

Pin Connections
| Component       | Arduino Pin |
| --------------- | ----------- |
| IR Sensor OUT   | D2          |
| Ultrasonic Trig | D5          |
| Ultrasonic Echo | D6          |
| Servo Signal    | D7          |
| HX711 DT        | D9          |
| HX711 SCK       | D10         |
| All VCC         | 5V          |
| All GND         | GND         |

Working Principle
-The IR sensor and ultrasonic sensor detect a hand near the dispenser.
-When a hand is detected, the servo motor rotates to press the sanitizer pump.
-The load cell (HX711) measures the sanitizer bottle weight to monitor the level.
-Sensor values and actions are printed on the Serial Monitor.

How to Run
-Connect all components as per the wiring table.
-Open Arduino IDE.
-Upload the code to Arduino UNO.
-Open Serial Monitor at 9600 baud rate.
-Place your hand near the sensors — sanitizer will dispense automatically!

Applications
-Schools & Colleges
-Hospitals & Clinics
-Offices & Public Places
-Homes

Author
Bhoomika.H.B
MPCA Project – Automatic Hand Sanitizer Dispenser
