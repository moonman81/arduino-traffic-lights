/*
 * Task L2.3: Create Simple Sequence
 * ==================================
 *
 * Create a repeating pattern - almost a traffic light!
 *
 * HARDWARE: Same as L2.2
 * Pin 12 → Red LED
 * Pin 11 → Yellow LED
 * Pin 10 → Green LED
 *
 * SEQUENCE:
 * Red → Yellow → Green → repeat
 */

void setup() {
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
}

void loop() {
  // Phase 1: RED
  digitalWrite(12, HIGH);   // Red ON
  digitalWrite(11, LOW);    // Yellow OFF
  digitalWrite(10, LOW);    // Green OFF
  delay(2000);              // 2 seconds

  // Phase 2: YELLOW
  digitalWrite(12, LOW);    // Red OFF
  digitalWrite(11, HIGH);   // Yellow ON
  digitalWrite(10, LOW);    // Green OFF
  delay(2000);              // 2 seconds

  // Phase 3: GREEN
  digitalWrite(12, LOW);    // Red OFF
  digitalWrite(11, LOW);    // Yellow OFF
  digitalWrite(10, HIGH);   // Green ON
  delay(2000);              // 2 seconds

  // Loop repeats automatically!
}

/*
 * THIS IS A SEQUENCE!
 * - Step 1: Do something
 * - Step 2: Do something else
 * - Step 3: Do another thing
 * - Repeat
 *
 * Every program is just sequences!
 */