// L4-1: Safety Verification Layer
// Difficulty: ⭐⭐⭐⭐⭐ (5 stars)
// Time: 45 minutes
// Prerequisites: L3-7b (complete system)
// This is Level 4: Adding safety checks!

// This builds on Level 3 by adding:
// - Safety verification functions
// - Continuous safety monitoring
// - Separation of concerns (safety layer above state machine)
// - Demonstrates dependency inversion principle

#define BUTTON_PIN 13
#define RED_TRAFFIC    12
#define YELLOW_TRAFFIC 11
#define GREEN_TRAFFIC  10
#define RED_PED         9
#define GREEN_PED       8

// States (full 5-state machine)
#define STATE_RED         0
#define STATE_RED_YELLOW  1
#define STATE_GREEN       2
#define STATE_YELLOW      3
#define STATE_PED_CROSS   4

// Timing
#define RED_TIME        5000
#define RED_YELLOW_TIME 2000
#define GREEN_TIME      6000
#define GREEN_MIN_TIME  3000  // Minimum before pedestrian interrupt
#define YELLOW_TIME     3000
#define PED_CROSS_TIME  8000

// Variables
int currentState = STATE_RED;
unsigned long stateStartTime = 0;
bool pedestrianRequested = false;
bool lastButtonState = HIGH;

// Safety monitoring
int safetyViolationCount = 0;

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(RED_TRAFFIC, OUTPUT);
  pinMode(YELLOW_TRAFFIC, OUTPUT);
  pinMode(GREEN_TRAFFIC, OUTPUT);
  pinMode(RED_PED, OUTPUT);
  pinMode(GREEN_PED, OUTPUT);

  Serial.begin(9600);
  Serial.println("=== Level 4: Safe Traffic Light with Verification ===");
  Serial.println("Safety checks are now running continuously");
  Serial.println();

  stateStartTime = millis();
}

void loop() {
  unsigned long currentTime = millis();
  unsigned long timeInState = currentTime - stateStartTime;

  // Check button
  checkButton();

  // === SAFETY VERIFICATION LAYER ===
  // This runs ABOVE the state machine
  // It watches everything and checks for safety violations
  if (!verifySafety()) {
    safetyViolationCount++;
    // In a real system, this would go to emergency safe state
    // For learning, we just log it
  }

  // State machine
  switch (currentState) {

    case STATE_RED:
      setTrafficLights(HIGH, LOW, LOW);
      setPedestrianLights(HIGH, LOW);

      if (timeInState >= RED_TIME) {
        changeState(STATE_RED_YELLOW);
      }
      break;

    case STATE_RED_YELLOW:
      setTrafficLights(HIGH, HIGH, LOW);
      setPedestrianLights(HIGH, LOW);

      if (timeInState >= RED_YELLOW_TIME) {
        changeState(STATE_GREEN);
      }
      break;

    case STATE_GREEN:
      setTrafficLights(LOW, LOW, HIGH);
      setPedestrianLights(HIGH, LOW);

      // Pedestrian interrupt (if requested AND minimum time passed)
      if (pedestrianRequested && timeInState >= GREEN_MIN_TIME) {
        Serial.println("  -> Pedestrian interrupt!");
        changeState(STATE_YELLOW);
      }
      // Normal timeout
      else if (timeInState >= GREEN_TIME) {
        changeState(STATE_YELLOW);
      }
      break;

    case STATE_YELLOW:
      setTrafficLights(LOW, HIGH, LOW);
      setPedestrianLights(HIGH, LOW);

      if (timeInState >= YELLOW_TIME) {
        // Check if pedestrian is waiting
        if (pedestrianRequested) {
          changeState(STATE_PED_CROSS);
          pedestrianRequested = false;  // Clear request
        } else {
          changeState(STATE_RED);
        }
      }
      break;

    case STATE_PED_CROSS:
      setTrafficLights(HIGH, LOW, LOW);    // Traffic RED (safe!)
      setPedestrianLights(LOW, HIGH);      // Pedestrian GREEN

      if (timeInState >= PED_CROSS_TIME) {
        changeState(STATE_RED);
      }
      break;
  }
}

// ================================================================
// SAFETY VERIFICATION FUNCTIONS
// ================================================================
// These are the NEW parts added in Level 4
// They check that the system is operating safely

/*
 * Main safety verification function
 * Returns: true if all safety checks pass, false if violation detected
 * This is called continuously in loop() - it watches everything
 */
bool verifySafety() {
  bool safe = true;

  // Safety Check 1: Mutual Exclusion
  // Traffic green and pedestrian green must NEVER be on together
  if (!verifyMutualExclusion()) {
    Serial.println("!!! SAFETY VIOLATION: Mutual exclusion failed !!!");
    Serial.println("    Traffic green and pedestrian green both ON!");
    safe = false;
  }

  // Safety Check 2: Progressive Warning
  // Green must go through yellow before red (no direct GREEN->RED)
  // This is checked during state transitions (see changeState function)

  // Safety Check 3: Minimum Green Time
  // If pedestrian interrupt happens, it should respect minimum time
  if (!verifyMinimumGreenTime()) {
    Serial.println("!!! SAFETY VIOLATION: Minimum green time violated !!!");
    Serial.println("    Pedestrian interrupted green too early!");
    safe = false;
  }

  return safe;
}

/*
 * Verify that traffic and pedestrian greens are never on together
 * This is called "mutual exclusion" - two things can't happen at once
 */
bool verifyMutualExclusion() {
  bool trafficGreen = digitalRead(GREEN_TRAFFIC);
  bool pedGreen = digitalRead(GREEN_PED);

  // If BOTH are on, that's dangerous!
  if (trafficGreen && pedGreen) {
    return false;  // Safety violation!
  }

  return true;  // Safe
}

/*
 * Verify minimum green time is respected
 * Traffic should get at least GREEN_MIN_TIME before pedestrian interrupt
 */
bool verifyMinimumGreenTime() {
  if (currentState != STATE_GREEN) {
    return true;  // Not applicable in other states
  }

  unsigned long elapsedTime = millis() - stateStartTime;

  // If pedestrian requested and we're transitioning early
  if (pedestrianRequested && elapsedTime < GREEN_MIN_TIME) {
    return false;  // Violation: interrupted too early
  }

  return true;  // Safe
}

// ================================================================
// ORIGINAL FUNCTIONS (from Level 3)
// ================================================================

void checkButton() {
  bool currentButtonState = digitalRead(BUTTON_PIN);

  // Detect button press (edge detection)
  if (lastButtonState == HIGH && currentButtonState == LOW) {
    if (!pedestrianRequested) {
      pedestrianRequested = true;
      Serial.println(">>> Button pressed! Pedestrian waiting...");
    }
    delay(200);  // Debounce
  }

  lastButtonState = currentButtonState;
}

void setTrafficLights(bool red, bool yellow, bool green) {
  digitalWrite(RED_TRAFFIC, red);
  digitalWrite(YELLOW_TRAFFIC, yellow);
  digitalWrite(GREEN_TRAFFIC, green);
}

void setPedestrianLights(bool red, bool green) {
  digitalWrite(RED_PED, red);
  digitalWrite(GREEN_PED, green);
}

void changeState(int newState) {
  // Progressive warning check (Safety Check 2)
  if (currentState == STATE_GREEN && newState == STATE_RED) {
    Serial.println("!!! SAFETY VIOLATION: Progressive warning failed !!!");
    Serial.println("    Cannot go directly from GREEN to RED!");
    // In real system, would prevent this transition
  }

  currentState = newState;
  stateStartTime = millis();

  // Debug output
  Serial.print("State: ");
  switch (newState) {
    case STATE_RED:        Serial.println("RED"); break;
    case STATE_RED_YELLOW: Serial.println("RED+YELLOW"); break;
    case STATE_GREEN:      Serial.println("GREEN"); break;
    case STATE_YELLOW:     Serial.println("YELLOW"); break;
    case STATE_PED_CROSS:  Serial.println("PEDESTRIAN CROSSING"); break;
  }
}

// ============================================================
// LEVEL 4 COMPLETE! YOU ADDED SAFETY VERIFICATION!
// ============================================================

// WHAT YOU'VE ACCOMPLISHED:
// ✅ Added safety verification layer ABOVE state machine
// ✅ Implemented mutual exclusion checking
// ✅ Implemented minimum time verification
// ✅ Implemented progressive warning checking
// ✅ Demonstrated separation of concerns
// ✅ Showed dependency inversion (safety checks state machine)

// KEY CONCEPT: LAYERS
// Your code now has TWO layers:
//
// [SAFETY LAYER] ← Watches and verifies
//        ↓
// [STATE MACHINE] ← Does the work
//
// The safety layer doesn't change the lights
// The state machine doesn't know safety layer exists
// This is called "dependency inversion"

// REAL-WORLD IMPORTANCE:
// - Medical devices use this pattern
// - Aviation software uses this pattern
// - Nuclear power systems use this pattern
// - Any safety-critical system uses this pattern

// TRY THIS: Break it on purpose!
// Change line 125 to: setTrafficLights(LOW, LOW, HIGH);
// Upload and watch Serial Monitor - safety will catch it!

// THIS IS PROFESSIONAL-LEVEL EMBEDDED SYSTEMS ARCHITECTURE
// You've now built something that matches industry standards

// ============================================================
// LEVEL 4 COMPLETE! 🎉🔒
// ============================================================