/*
 * Task L3.2: Button Toggle
 * =========================
 *
 * Make button press TOGGLE LED (on/off/on/off)
 * This teaches button logic and state tracking
 *
 * HARDWARE: Same as L3.1
 */

#define BUTTON_PIN 13
#define LED_PIN    10

bool ledState = false;  // Track if LED is on or off
bool lastButtonState = HIGH;  // Track previous button state

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(LED_PIN, OUTPUT);

  Serial.begin(9600);
  Serial.println("Toggle Test - Each press toggles LED");
}

void loop() {
  // Read current button state
  bool currentButtonState = digitalRead(BUTTON_PIN);

  // Check if button was just pressed (HIGH → LOW transition)
  if (lastButtonState == HIGH && currentButtonState == LOW) {
    // Button was just pressed!

    // Toggle LED state
    ledState = !ledState;  // Flip true/false

    // Update LED
    digitalWrite(LED_PIN, ledState);

    // Print to serial
    if (ledState) {
      Serial.println("LED turned ON");
    } else {
      Serial.println("LED turned OFF");
    }

    delay(200);  // Debounce delay
  }

  // Remember current state for next loop
  lastButtonState = currentButtonState;
}

/*
 * KEY CONCEPTS:
 *
 * 1. STATE TRACKING:
 *    bool ledState - remembers if LED is on/off
 *
 * 2. EDGE DETECTION:
 *    We detect when button CHANGES from HIGH to LOW
 *    Not just "is it pressed?" but "was it just pressed?"
 *
 * 3. TOGGLE LOGIC:
 *    ledState = !ledState
 *    ! means NOT (flips true/false)
 *
 * 4. DEBOUNCING:
 *    delay(200) prevents multiple triggers from one press
 *    Buttons "bounce" electrically!
 *
 * This is fundamental input processing!
 */