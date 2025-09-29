// L3-7a: Basic Pedestrian Integration
// Difficulty: ⭐⭐⭐☆☆ (3 stars)
// Time: 20 minutes
// Prerequisites: L3-4a (button queuing), L3-5a (millis intro)
// Prepares for: L3-7b (full features)

// This simplified version integrates button with traffic light
// using millis() but WITHOUT pedestrian LEDs or complex safety.
// Get the core integration working first!

#define BUTTON_PIN 13
#define RED_TRAFFIC    12
#define YELLOW_TRAFFIC 11
#define GREEN_TRAFFIC  10

// States (simplified - 4 states only)
#define STATE_RED         0
#define STATE_RED_YELLOW  1
#define STATE_GREEN       2
#define STATE_YELLOW      3

// Timing
#define RED_TIME        5000
#define RED_YELLOW_TIME 2000
#define GREEN_TIME      6000
#define YELLOW_TIME     3000

// Variables
int currentState = STATE_RED;
unsigned long stateStartTime = 0;
bool pedestrianRequested = false;

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(RED_TRAFFIC, OUTPUT);
  pinMode(YELLOW_TRAFFIC, OUTPUT);
  pinMode(GREEN_TRAFFIC, OUTPUT);

  Serial.begin(9600);
  Serial.println("=== Basic Pedestrian Integration ===");
  Serial.println("Press button to shorten green phase");
  Serial.println();

  stateStartTime = millis();
}

void loop() {
  unsigned long currentTime = millis();
  unsigned long timeInState = currentTime - stateStartTime;

  // Check button
  checkButton();

  // State machine (simplified)
  switch (currentState) {

    case STATE_RED:
      digitalWrite(RED_TRAFFIC, HIGH);
      digitalWrite(YELLOW_TRAFFIC, LOW);
      digitalWrite(GREEN_TRAFFIC, LOW);

      if (timeInState >= RED_TIME) {
        changeState(STATE_RED_YELLOW);
      }
      break;

    case STATE_RED_YELLOW:
      digitalWrite(RED_TRAFFIC, HIGH);
      digitalWrite(YELLOW_TRAFFIC, HIGH);
      digitalWrite(GREEN_TRAFFIC, LOW);

      if (timeInState >= RED_YELLOW_TIME) {
        changeState(STATE_GREEN);
      }
      break;

    case STATE_GREEN:
      digitalWrite(RED_TRAFFIC, LOW);
      digitalWrite(YELLOW_TRAFFIC, LOW);
      digitalWrite(GREEN_TRAFFIC, HIGH);

      // KEY FEATURE: Button shortens green phase
      if (pedestrianRequested && timeInState >= 3000) {
        Serial.println("  -> Pedestrian shortened green!");
        changeState(STATE_YELLOW);
        pedestrianRequested = false;  // Clear request
      }
      // Normal timeout
      else if (timeInState >= GREEN_TIME) {
        changeState(STATE_YELLOW);
      }
      break;

    case STATE_YELLOW:
      digitalWrite(RED_TRAFFIC, LOW);
      digitalWrite(YELLOW_TRAFFIC, HIGH);
      digitalWrite(GREEN_TRAFFIC, LOW);

      if (timeInState >= YELLOW_TIME) {
        changeState(STATE_RED);
      }
      break;
  }
}

void checkButton() {
  static bool lastButtonState = HIGH;
  bool currentButtonState = digitalRead(BUTTON_PIN);

  // Detect button press (HIGH to LOW transition)
  if (lastButtonState == HIGH && currentButtonState == LOW) {
    if (!pedestrianRequested) {
      pedestrianRequested = true;
      Serial.println(">>> Button pressed! Request queued.");
    }
    delay(200);  // Simple debounce
  }

  lastButtonState = currentButtonState;
}

void changeState(int newState) {
  currentState = newState;
  stateStartTime = millis();

  // Debug output
  Serial.print("State: ");
  switch (newState) {
    case STATE_RED:        Serial.println("RED"); break;
    case STATE_RED_YELLOW: Serial.println("RED+YELLOW"); break;
    case STATE_GREEN:      Serial.println("GREEN"); break;
    case STATE_YELLOW:     Serial.println("YELLOW"); break;
  }
}

// LEARNING OBJECTIVES:
// 1. Integrate button with state machine
// 2. Queue requests across state transitions
// 3. Implement minimum safe time (3 seconds)
// 4. Clear request after processing

// TEST PROCEDURE:
// 1. Watch normal cycle: RED → RED+YELLOW → GREEN → YELLOW → RED
// 2. During GREEN: Press button EARLY (before 3 seconds)
//    - Should see "Request queued" but green continues to 3 seconds
// 3. During GREEN: Press button LATE (after 3 seconds)
//    - Should immediately transition to YELLOW
// 4. Press button during RED or YELLOW
//    - Request queued but no immediate effect (correct!)

// WHAT'S SIMPLIFIED vs L3-7b:
// - No pedestrian LEDs (only traffic lights)
// - No pedestrian crossing state (just shortens green)
// - Simpler state machine (4 states vs 5)
// - No advanced safety checks

// WHY THIS STEP MATTERS:
// Monte Carlo analysis showed L3.7 had 60% success rate
// Breaking into L3-7a (basic) and L3-7b (full) improves learning
// Get button integration working before adding complexity

// NEXT STEP:
// L3-7b: Add pedestrian LEDs and full crossing phase