/*
 * Task L2.1: Add Second LED
 * ==========================
 *
 * Control two LEDs independently
 *
 * HARDWARE:
 * Pin 13 → Resistor → Red LED → GND
 * Pin 12 → Resistor → Yellow LED → GND
 *
 * WHAT YOU LEARN:
 * - Multiple outputs
 * - Independent control
 * - Alternating patterns
 */

void setup() {
  pinMode(13, OUTPUT);  // Red LED
  pinMode(12, OUTPUT);  // Yellow LED
}

void loop() {
  // Red on, Yellow off
  digitalWrite(13, HIGH);
  digitalWrite(12, LOW);
  delay(1000);

  // Red off, Yellow on
  digitalWrite(13, LOW);
  digitalWrite(12, HIGH);
  delay(1000);

  // Try this: Both on together!
  // digitalWrite(13, HIGH);
  // digitalWrite(12, HIGH);
  // delay(1000);

  // Both off
  // digitalWrite(13, LOW);
  // digitalWrite(12, LOW);
  // delay(1000);
}

/*
 * EXPERIMENT:
 * Make them flash in different patterns:
 * - Police lights (alternate fast)
 * - Both flash together
 * - One stays on, other blinks
 */