// L3-4a: Button Basics - Stepping Stone Task
// Difficulty: ⭐⭐☆☆☆ (2 stars)
// Time: 15 minutes
// Prerequisites: L3.2 (button reading)
// Prepares for: L3.4 (pedestrian request)

// This intermediate task bridges the gap between reading a button
// and integrating it into the traffic light system.
// You'll learn to queue button presses properly before adding complexity.

#define BUTTON_PIN 2
#define LED_PIN 13  // Using built-in LED for simplicity

bool requestQueued = false;
bool requestProcessed = false;

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(LED_PIN, OUTPUT);

  Serial.begin(9600);
  Serial.println("=== Button Request Queuing Test ===");
  Serial.println("Press button to queue request.");
  Serial.println("LED will blink when request processed.");
  Serial.println();
}

void loop() {
  // STEP 1: Check button and queue request
  checkButton();

  // STEP 2: Process queued request after delay
  processRequest();

  // Small delay for stability
  delay(50);
}

void checkButton() {
  // Read button (INPUT_PULLUP means pressed = LOW)
  int buttonState = digitalRead(BUTTON_PIN);

  if (buttonState == LOW) {
    // Button is pressed
    if (!requestQueued) {
      requestQueued = true;
      requestProcessed = false;
      Serial.println("[BUTTON] Request queued!");
    }
  }
}

void processRequest() {
  // If we have a queued request that hasn't been processed
  if (requestQueued && !requestProcessed) {
    Serial.println("[SYSTEM] Processing request...");

    // Simulate processing delay (like waiting for green phase)
    for (int i = 0; i < 5; i++) {
      digitalWrite(LED_PIN, HIGH);
      delay(200);
      digitalWrite(LED_PIN, LOW);
      delay(200);
    }

    // Mark as processed
    requestProcessed = true;
    requestQueued = false;

    Serial.println("[SYSTEM] Request complete!");
    Serial.println();
  }
}

// LEARNING OBJECTIVES:
// 1. Understand request queuing (flag stays true until processed)
// 2. Prevent duplicate processing (requestProcessed flag)
// 3. Serial debugging for state visibility
// 4. Separation of concerns (check vs process)

// TEST PROCEDURE:
// 1. Press button once - should see "Request queued!"
// 2. LED blinks 5 times (simulated processing)
// 3. Press button again - new request queued
// 4. Try pressing multiple times quickly - only one request queued

// COMMON ISSUES:
// - Button seems to do nothing: Check INPUT_PULLUP mode
// - Multiple requests from one press: Need debouncing (covered in L3.4)
// - Serial not showing: Check baud rate is 9600

// NEXT STEPS:
// - L3.4: Integrate this pattern into traffic light system
// - L3.5: Add timing with millis() instead of delay()
// - L3.6: Add pedestrian LED indication