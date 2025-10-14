#include <Servo.h> // Include Servo library

Servo headlightServo; // Servo for headlight direction

void setup() {
  // Input pins
  pinMode(A0, INPUT);   // LDR (light sensor)
  pinMode(8, INPUT);    // Ultrasonic Echo
  pinMode(7, INPUT);    // Switch to detect vehicle stop/start
  pinMode(A2, INPUT);   // Speed sensor
  pinMode(2, INPUT);    // Rain sensor
  
  // Output pins
  pinMode(3, OUTPUT); // HIGH intensity LED
  pinMode(4, OUTPUT); // MEDIUM intensity LED
  pinMode(5, OUTPUT); // LOW intensity LED
  pinMode(9, OUTPUT); // Ultrasonic trigger
  pinMode(2, OUTPUT); // Rain sensor (if active-high)
  
  Serial.begin(9600); // Initialize serial communication

  headlightServo.attach(6); // Attach servo to pin 6
  headlightServo.write(90); // Initialize servo to center position
}

void loop() {
  int light = analogRead(A0); // Read LDR value
  int rain = digitalRead(2);   // Read rain sensor
  int swit = digitalRead(7);   // Read vehicle stop/start switch

  // Trigger ultrasonic sensor
  digitalWrite(9, HIGH);
  delay(10);
  digitalWrite(9, LOW);

  // Measure pulse duration from ultrasonic sensor
  float time = pulseIn(8, HIGH);
  float distance = 0.033 * time / 2;      // distance in cm
  distance = (distance - 500) / 10;       // calibration (adjust if needed)
  distance = abs(distance);               // make positive

  // Correct speed calculation
  int speedRaw = analogRead(A2);         // Read speed sensor analog value
  float speed = (speedRaw * 5.0 / 1023) * 100; // Map voltage to speed (0-100 km/h approx.)

  if (swit == 0) {
    Serial.println("Vehicle is stopped");
    headlightServo.write(90); // Keep headlights straight
  } else {
    Serial.print("Distance: ");
    Serial.println(distance);
    
    // Automatic headlight direction based on distance
    if (distance < 35) {
      headlightServo.write(70); // Tilt down to avoid blinding oncoming vehicles
    } else {
      headlightServo.write(90); // Normal forward position
    }

    // Evening light condition
    if (light >= 300 && light <= 600) {
      Serial.println("Evening");
      if (rain == 0) {
        Serial.println("Weather clear");
      } else {
        Serial.println("It's raining now");
      }
    }
    // Night light condition
    else if (light < 300) {
      Serial.println("Night");
      if (rain == 0) {
        Serial.println("Weather clear");
      } else {
        Serial.println("It's raining now");
      }
    } 
    // Day light condition
    else {
      Serial.println("Day");
    }

    // LED intensity based on speed and distance
    if (distance > 35) { // Path clear
      if (speed <= 30) {
        Serial.println("Vehicle moving at normal speed - LOW Intensity");
        digitalWrite(5, HIGH);
        digitalWrite(4, LOW);
        digitalWrite(3, LOW);
      } 
      else if (speed > 30 && speed < 60) {
        Serial.println("Vehicle moving at average speed - MEDIUM Intensity");
        digitalWrite(4, HIGH);
        digitalWrite(5, LOW);
        digitalWrite(3, LOW);
      } 
      else {
        Serial.println("Vehicle moving at high speed - HIGH Intensity");
        digitalWrite(3, HIGH);
        digitalWrite(4, LOW);
        digitalWrite(5, LOW);
      }
    } 
    else { // Vehicle coming / obstacle detected
      if (speed <= 30) {
        Serial.println("Vehicle moving at normal speed - MEDIUM Intensity");
        digitalWrite(4, HIGH);
        digitalWrite(3, LOW);
        digitalWrite(5, LOW);
      } 
      else if (speed > 30 && speed < 60) {
        Serial.println("Vehicle moving at average speed - LOW Intensity");
        digitalWrite(5, HIGH);
        digitalWrite(3, LOW);
        digitalWrite(4, LOW);
      } 
      else {
        Serial.println("Vehicle moving at high speed - MEDIUM Intensity");
        digitalWrite(4, HIGH);
        digitalWrite(3, LOW);
        digitalWrite(5, LOW);
      }
    }
  }

  delay(1000); // 1-second delay between loops
}
