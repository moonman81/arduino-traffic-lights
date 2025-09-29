/*
 * Task L3.6: Button Counter with Serial
 * ======================================
 *
 * Practice combining button input with Serial debugging
 * Counts how many times button is pressed
 *
 * HARDWARE:
 * Pin 13 → Button → GND
 *
 * WHAT IT DOES:
 * - Counts button presses
 * - Displays count on Serial Monitor
 * - Teaches: input + output + state tracking
 */

#define BUTTON_PIN 13

int pressCount = 0;
bool lastButtonState = HIGH;

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);

  Serial.begin(9600);
  Serial.println("=== Button Counter ===");
  Serial.println("Press button to count!");
  Serial.println("Press count: 0");
}

void loop() {
  bool currentButtonState = digitalRead(BUTTON_PIN);

  // Detect button press (HIGH → LOW)
  if (lastButtonState == HIGH && currentButtonState == LOW) {
    pressCount++;  // Increment counter

    Serial.print("Press count: ");
    Serial.println(pressCount);

    // Extra info every 5 presses
    if (pressCount % 5 == 0) {
      Serial.println("  --> 5 more presses!");
    }

    delay(200);  // Debounce
  }

  lastButtonState = currentButtonState;
}

/*
 * WHAT YOU'RE LEARNING:
 *
 * 1. STATE PERSISTENCE:
 *    int pressCount - remembers across loop() calls
 *
 * 2. SERIAL OUTPUT:
 *    Serial.print() - no newline
 *    Serial.println() - with newline
 *
 * 3. MATH OPERATORS:
 *    ++ increment
 *    % modulo (remainder)
 *
 * 4. DEBUGGING:
 *    Print variables to understand program state
 *
 * CHALLENGE:
 * Make it reset to 0 after 10 presses:
 * if (pressCount >= 10) {
 *   pressCount = 0;
 *   Serial.println("Reset!");
 * }
 */