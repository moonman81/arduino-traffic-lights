/*
 * Task L3.1: Button Circuit Test
 * ===============================
 *
 * Learn to read button input - your first sensor!
 *
 * HARDWARE:
 * Pin 13 → Button → GND
 * (No resistor needed - we use INPUT_PULLUP)
 *
 * Also connect an LED to see button state:
 * Pin 10 → Resistor → LED → GND
 *
 * WHAT IT DOES:
 * - LED is off normally
 * - LED turns on when you press button
 * - LED turns off when you release button
 */

#define BUTTON_PIN 13
#define LED_PIN    10

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);  // Button with internal pull-up
  pinMode(LED_PIN, OUTPUT);

  // Serial for debugging
  Serial.begin(9600);
  Serial.println("Button Test - Press the button!");
}

void loop() {
  // Read button state
  int buttonState = digitalRead(BUTTON_PIN);

  // INPUT_PULLUP means:
  // - Normally HIGH (not pressed)
  // - LOW when pressed (button connects to GND)

  if (buttonState == LOW) {
    // Button is pressed
    digitalWrite(LED_PIN, HIGH);
    Serial.println("Button PRESSED!");
    delay(100);  // Small delay to avoid spam
  } else {
    // Button is not pressed
    digitalWrite(LED_PIN, LOW);
  }
}

/*
 * WHAT IS INPUT_PULLUP?
 * - Normal: Pin floats (undefined state)
 * - INPUT_PULLUP: Pin pulled to HIGH (5V) internally
 * - When button pressed: Pin connects to GND = LOW
 *
 * WHY USE IT?
 * - Don't need external resistor!
 * - Cleaner circuit
 * - Standard Arduino practice
 *
 * BUTTON LOGIC (with INPUT_PULLUP):
 * - Not pressed = HIGH
 * - Pressed = LOW
 * (Seems backwards, but that's how it works!)
 */