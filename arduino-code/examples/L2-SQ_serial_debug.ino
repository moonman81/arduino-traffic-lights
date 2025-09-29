/*
 * Side Quest: Add Serial Debugging
 * =================================
 *
 * Learn to use Serial Monitor to see what your code is doing!
 * This is ESSENTIAL for debugging.
 *
 * HARDWARE: Same as L2.4
 *
 * HOW TO USE:
 * 1. Upload this code
 * 2. Open Tools → Serial Monitor
 * 3. Set baud rate to 9600 (bottom right)
 * 4. Watch messages appear as traffic light changes!
 */

#define RED_LED    12
#define YELLOW_LED 11
#define GREEN_LED  10

void setup() {
  // Start Serial communication
  Serial.begin(9600);
  Serial.println("=== Traffic Light Started ===");
  Serial.println("Open Serial Monitor to see phases");
  Serial.println();

  pinMode(RED_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
}

void loop() {
  // RED phase
  Serial.println("PHASE: RED (Stop!)");
  digitalWrite(RED_LED, HIGH);
  digitalWrite(YELLOW_LED, LOW);
  digitalWrite(GREEN_LED, LOW);
  delay(5000);

  // RED + YELLOW phase
  Serial.println("PHASE: RED + YELLOW (Get ready!)");
  digitalWrite(RED_LED, HIGH);
  digitalWrite(YELLOW_LED, HIGH);
  digitalWrite(GREEN_LED, LOW);
  delay(2000);

  // GREEN phase
  Serial.println("PHASE: GREEN (Go!)");
  digitalWrite(RED_LED, LOW);
  digitalWrite(YELLOW_LED, LOW);
  digitalWrite(GREEN_LED, HIGH);
  delay(6000);

  // YELLOW phase
  Serial.println("PHASE: YELLOW (Slow down!)");
  digitalWrite(RED_LED, LOW);
  digitalWrite(YELLOW_LED, HIGH);
  digitalWrite(GREEN_LED, LOW);
  delay(3000);

  Serial.println("--- Cycle complete, repeating ---");
  Serial.println();
}

/*
 * SERIAL MONITOR COMMANDS:
 * Serial.begin(9600);     - Start serial (put in setup)
 * Serial.println("text"); - Print line of text
 * Serial.print("text");   - Print without newline
 *
 * WHY USE SERIAL?
 * - See what your code is doing
 * - Debug problems
 * - Display sensor values
 * - Log events
 *
 * ESSENTIAL SKILL for all Arduino projects!
 */