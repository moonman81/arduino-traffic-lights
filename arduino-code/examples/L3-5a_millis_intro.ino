// L3-5a: Introduction to millis() - Stepping Stone Task
// Difficulty: ⭐⭐⭐☆☆ (3 stars)
// Time: 20 minutes
// Prerequisites: L2.6 (timing verification)
// Prepares for: L3.5 (millis timing in traffic light)

// This task introduces millis() timing without the complexity
// of a full traffic light system. You'll learn the core pattern
// before integrating it.

#define LED_PIN 13

unsigned long previousTime = 0;
unsigned long interval = 1000;  // 1 second
bool ledState = false;

void setup() {
  pinMode(LED_PIN, OUTPUT);

  Serial.begin(9600);
  Serial.println("=== millis() Timing Introduction ===");
  Serial.println("LED blinks every 1 second using millis()");
  Serial.println("Type 'f' for fast (500ms) or 's' for slow (2000ms)");
  Serial.println();
}

void loop() {
  // CORE PATTERN: Check if enough time has passed
  unsigned long currentTime = millis();

  if (currentTime - previousTime >= interval) {
    // Time to toggle LED
    previousTime = currentTime;

    // Toggle LED state
    ledState = !ledState;
    digitalWrite(LED_PIN, ledState);

    // Debug output
    Serial.print("[TIME] ");
    Serial.print(currentTime);
    Serial.print("ms - LED ");
    Serial.println(ledState ? "ON" : "OFF");
  }

  // Check for user input (demonstrates non-blocking)
  if (Serial.available() > 0) {
    char input = Serial.read();

    if (input == 'f' || input == 'F') {
      interval = 500;  // Fast
      Serial.println("[COMMAND] Interval set to 500ms (fast)");
    } else if (input == 's' || input == 'S') {
      interval = 2000;  // Slow
      Serial.println("[COMMAND] Interval set to 2000ms (slow)");
    }
  }
}

// LEARNING OBJECTIVES:
// 1. Understand millis() returns milliseconds since Arduino started
// 2. Pattern: currentTime - previousTime >= interval
// 3. Update previousTime when action taken
// 4. Non-blocking: loop continues while timing

// WHY NOT delay()?
// delay() blocks everything - nothing else can happen
// millis() allows checking time while doing other things
// Essential for button responsiveness in traffic light

// COMMON MISCONCEPTIONS:
// ❌ WRONG: if (millis() >= 1000)  // This only works once!
// ✅ RIGHT: if (currentTime - previousTime >= interval)

// MILLIS() ROLLOVER:
// millis() resets to 0 after ~49 days
// Our subtraction method handles this automatically!
// Example: previousTime = 4294967290, currentTime = 5
// Subtraction: 5 - 4294967290 = (wraps correctly due to unsigned math)

// TEST PROCEDURE:
// 1. Upload code, open Serial Monitor at 9600 baud
// 2. Watch LED blink every 1 second
// 3. Type 'f' and press Enter - blinks faster (500ms)
// 4. Type 's' and press Enter - blinks slower (2000ms)
// 5. Notice: Serial commands work WHILE blinking (non-blocking!)

// EXPERIMENT:
// Try adding a second LED on pin 12 with different interval
// Both LEDs can blink at different rates simultaneously!

// NEXT STEPS:
// - L3.5: Apply this pattern to traffic light timing
// - L3.6: Track time spent in each traffic light state
// - L3.7: Combine with button for pedestrian crossing