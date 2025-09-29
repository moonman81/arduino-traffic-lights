/*
 * SPEEDRUN TRACK: Minimum Viable Traffic Light
 * =============================================
 *
 * Get a working traffic light in <5 minutes!
 * This is the SIMPLEST possible UK traffic light
 *
 * HARDWARE:
 * Pin 12 → Red LED → Resistor → GND
 * Pin 11 → Yellow LED → Resistor → GND
 * Pin 10 → Green LED → Resistor → GND
 *
 * JUST COPY AND RUN!
 */

void setup() {
  pinMode(12, OUTPUT);  // Red
  pinMode(11, OUTPUT);  // Yellow
  pinMode(10, OUTPUT);  // Green
}

void loop() {
  // RED
  digitalWrite(12, HIGH);
  digitalWrite(11, LOW);
  digitalWrite(10, LOW);
  delay(5000);

  // RED + YELLOW
  digitalWrite(12, HIGH);
  digitalWrite(11, HIGH);
  digitalWrite(10, LOW);
  delay(2000);

  // GREEN
  digitalWrite(12, LOW);
  digitalWrite(11, LOW);
  digitalWrite(10, HIGH);
  delay(6000);

  // YELLOW
  digitalWrite(12, LOW);
  digitalWrite(11, HIGH);
  digitalWrite(10, LOW);
  delay(3000);
}

/*
 * THAT'S IT! You have a working traffic light!
 *
 * NEXT STEPS:
 * - Want it cleaner? See L2-5_with_defines.ino
 * - Want button? See L3-7_complete_pedestrian.ino
 * - Want to understand? Read the other examples!
 */