/*
 * Task L1.5: Change Blink Speed (Side Quest)
 * ===========================================
 *
 * Learn about timing by experimenting with different speeds
 *
 * HARDWARE: Same as L1.4
 * Pin 13 → Resistor → LED → GND
 */

void setup() {
  pinMode(13, OUTPUT);
}

void loop() {
  // Fast blink (half second)
  digitalWrite(13, HIGH);
  delay(500);  // 500ms = 0.5 seconds
  digitalWrite(13, LOW);
  delay(500);

  // Try these variations:
  // delay(100);   // Very fast
  // delay(2000);  // Slow
  // delay(50);    // Super fast (like flashing)
}

/*
 * EXPERIMENT:
 * Try making it pulse like a heartbeat:
 * Quick ON, quick OFF, quick ON, quick OFF, long pause
 *
 * Code:
 * digitalWrite(13, HIGH); delay(200); digitalWrite(13, LOW); delay(200);
 * digitalWrite(13, HIGH); delay(200); digitalWrite(13, LOW); delay(800);
 */