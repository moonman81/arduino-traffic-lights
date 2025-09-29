/*
 * Task L2.2: Add Third LED
 * =========================
 *
 * Now controlling three LEDs - ready for traffic light!
 *
 * HARDWARE:
 * Pin 12 → Resistor → Red LED → GND
 * Pin 11 → Resistor → Yellow LED → GND
 * Pin 10 → Resistor → Green LED → GND
 */

void setup() {
  pinMode(12, OUTPUT);  // Red
  pinMode(11, OUTPUT);  // Yellow
  pinMode(10, OUTPUT);  // Green
}

void loop() {
  // Light them up one at a time

  // Red only
  digitalWrite(12, HIGH);
  digitalWrite(11, LOW);
  digitalWrite(10, LOW);
  delay(1000);

  // Yellow only
  digitalWrite(12, LOW);
  digitalWrite(11, HIGH);
  digitalWrite(10, LOW);
  delay(1000);

  // Green only
  digitalWrite(12, LOW);
  digitalWrite(11, LOW);
  digitalWrite(10, HIGH);
  delay(1000);

  // All off
  digitalWrite(12, LOW);
  digitalWrite(11, LOW);
  digitalWrite(10, LOW);
  delay(1000);
}

/*
 * Notice the pattern?
 * Each LED needs two commands:
 * 1. Turn it on or off
 * 2. Turn the others off (if you want only one lit)
 *
 * CHALLENGE: Make all three flash together!
 */