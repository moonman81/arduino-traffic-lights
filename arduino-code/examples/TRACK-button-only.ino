/*
 * BUTTON LEARNING TRACK: Button Mastery
 * ======================================
 *
 * Want to learn JUST buttons? This is your track!
 * NO traffic light needed - just button + LED
 *
 * HARDWARE:
 * Pin 13 → Button → GND
 * Pin 10 → LED → Resistor → GND
 *
 * PROGRESSION:
 * Stage 1: Button turns LED on/off (while held)
 * Stage 2: Button toggles LED (press to toggle)
 * Stage 3: Button with debouncing
 * Stage 4: Button counter
 */

#define BUTTON_PIN 13
#define LED_PIN    10

// Uncomment ONE section at a time to try different stages

// ============================================================
// STAGE 1: Basic Button (Uncomment to try)
// ============================================================
/*
void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  if (digitalRead(BUTTON_PIN) == LOW) {
    digitalWrite(LED_PIN, HIGH);  // Button pressed
  } else {
    digitalWrite(LED_PIN, LOW);   // Button released
  }
}
*/

// ============================================================
// STAGE 2: Toggle (Uncomment to try)
// ============================================================
/*
bool ledState = false;
bool lastButton = HIGH;

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  bool currentButton = digitalRead(BUTTON_PIN);

  if (lastButton == HIGH && currentButton == LOW) {
    ledState = !ledState;
    digitalWrite(LED_PIN, ledState);
    delay(200);  // Debounce
  }

  lastButton = currentButton;
}
*/

// ============================================================
// STAGE 3: With Proper Debouncing (Uncomment to try)
// ============================================================
/*
bool ledState = false;
bool lastButton = HIGH;
unsigned long lastDebounceTime = 0;
const unsigned long DEBOUNCE_DELAY = 50;

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  bool currentButton = digitalRead(BUTTON_PIN);

  if (currentButton != lastButton) {
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > DEBOUNCE_DELAY) {
    if (lastButton == HIGH && currentButton == LOW) {
      ledState = !ledState;
      digitalWrite(LED_PIN, ledState);
    }
  }

  lastButton = currentButton;
}
*/

// ============================================================
// STAGE 4: Button Counter (Active by default)
// ============================================================
int counter = 0;
bool lastButton = HIGH;

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
  Serial.println("Button Counter - Press to count!");
}

void loop() {
  bool currentButton = digitalRead(BUTTON_PIN);

  if (lastButton == HIGH && currentButton == LOW) {
    counter++;
    Serial.print("Count: ");
    Serial.println(counter);

    // Flash LED
    digitalWrite(LED_PIN, HIGH);
    delay(100);
    digitalWrite(LED_PIN, LOW);
    delay(100);
  }

  lastButton = currentButton;
}

/*
 * BUTTON MASTERY COMPLETE!
 *
 * You now understand:
 * - INPUT_PULLUP
 * - Edge detection (HIGH to LOW)
 * - Toggle logic
 * - Debouncing (why and how)
 * - State tracking
 * - Event counting
 *
 * NEXT: Combine with traffic light!
 * See L3-7_complete_pedestrian.ino
 */