/*
 * Task L2.4: UK Traffic Light Standard
 * =====================================
 *
 * Complete UK-standard traffic light!
 * Notice RED+YELLOW together before GREEN
 *
 * HARDWARE: Same as L2.2
 */

// Use #define to make code more readable
#define RED_LED    12
#define YELLOW_LED 11
#define GREEN_LED  10

void setup() {
  pinMode(RED_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
}

void loop() {
  // PHASE 1: RED (STOP!)
  digitalWrite(RED_LED, HIGH);
  digitalWrite(YELLOW_LED, LOW);
  digitalWrite(GREEN_LED, LOW);
  delay(5000);  // 5 seconds

  // PHASE 2: RED + YELLOW (Get ready!)
  digitalWrite(RED_LED, HIGH);
  digitalWrite(YELLOW_LED, HIGH);  // Both on!
  digitalWrite(GREEN_LED, LOW);
  delay(2000);  // 2 seconds

  // PHASE 3: GREEN (GO!)
  digitalWrite(RED_LED, LOW);
  digitalWrite(YELLOW_LED, LOW);
  digitalWrite(GREEN_LED, HIGH);
  delay(6000);  // 6 seconds

  // PHASE 4: YELLOW (Slow down!)
  digitalWrite(RED_LED, LOW);
  digitalWrite(YELLOW_LED, HIGH);
  digitalWrite(GREEN_LED, LOW);
  delay(3000);  // 3 seconds

  // Back to RED automatically
}

/*
 * UK STANDARD:
 * RED → RED+YELLOW → GREEN → YELLOW → repeat
 *
 * WHY RED+YELLOW?
 * Gives drivers warning to prepare to go!
 *
 * Total cycle: 5 + 2 + 6 + 3 = 16 seconds
 */