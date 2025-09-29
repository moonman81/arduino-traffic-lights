/*
 * Side Quest: Morse Code SOS
 * ===========================
 *
 * Make your LED blink "SOS" in Morse code
 *
 * MORSE CODE:
 * S = · · ·   (three short)
 * O = – – –   (three long)
 * S = · · ·   (three short)
 *
 * SHORT = 200ms
 * LONG = 600ms
 * GAP between letters = 600ms
 *
 * HARDWARE: Same as L1.4
 */

void setup() {
  pinMode(13, OUTPUT);
}

void loop() {
  // S (dot dot dot)
  dot(); dot(); dot();
  delay(600);  // Gap between letters

  // O (dash dash dash)
  dash(); dash(); dash();
  delay(600);  // Gap between letters

  // S (dot dot dot)
  dot(); dot(); dot();
  delay(2000);  // Long pause before repeating
}

// Helper function for a dot
void dot() {
  digitalWrite(13, HIGH);
  delay(200);  // Short flash
  digitalWrite(13, LOW);
  delay(200);  // Short gap
}

// Helper function for a dash
void dash() {
  digitalWrite(13, HIGH);
  delay(600);  // Long flash
  digitalWrite(13, LOW);
  delay(200);  // Short gap
}

/*
 * WHAT YOU LEARNED:
 * - Functions! (dot() and dash())
 * - Code reuse (call functions multiple times)
 * - Patterns and sequences
 *
 * CHALLENGE: Make it spell your initials!
 * Look up Morse code alphabet online
 */