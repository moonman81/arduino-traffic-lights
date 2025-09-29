/*
 * Task ADV.1: Professional State Machine
 * =======================================
 *
 * This is the traffic light rewritten as a CLEAN state machine
 * with proper structure, safety checks, and documentation
 *
 * WHAT'S DIFFERENT:
 * - Enum for states (more professional)
 * - State transition function
 * - Safety checks
 * - Better organization
 */

// Pin definitions
#define BUTTON_PIN     13
#define RED_TRAFFIC    12
#define YELLOW_TRAFFIC 11
#define GREEN_TRAFFIC  10
#define RED_PED         9
#define GREEN_PED       8

// State enumeration (professional way to define states)
enum TrafficState {
  STATE_RED,
  STATE_RED_YELLOW,
  STATE_GREEN,
  STATE_YELLOW,
  STATE_PED_CROSSING
};

// Timing constants
const unsigned long RED_DURATION = 5000;
const unsigned long RED_YELLOW_DURATION = 2000;
const unsigned long GREEN_DURATION = 6000;
const unsigned long GREEN_MIN_DURATION = 3000;
const unsigned long YELLOW_DURATION = 3000;
const unsigned long PED_DURATION = 8000;

// State variables
TrafficState currentState = STATE_RED;
unsigned long stateStartTime = 0;
bool pedestrianRequested = false;
bool lastButtonState = HIGH;

void setup() {
  // Configure pins
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(RED_TRAFFIC, OUTPUT);
  pinMode(YELLOW_TRAFFIC, OUTPUT);
  pinMode(GREEN_TRAFFIC, OUTPUT);
  pinMode(RED_PED, OUTPUT);
  pinMode(GREEN_PED, OUTPUT);

  // Initialize serial
  Serial.begin(9600);
  Serial.println("=== Professional State Machine ===");

  // Initialize state
  stateStartTime = millis();
  enterState(STATE_RED);
}

void loop() {
  unsigned long currentTime = millis();
  unsigned long timeInState = currentTime - stateStartTime;

  // Process inputs
  processButton();

  // Update state machine
  updateStateMachine(timeInState);

  // Small delay for stability
  delay(10);
}

// Button processing
void processButton() {
  bool currentButtonState = digitalRead(BUTTON_PIN);

  if (lastButtonState == HIGH && currentButtonState == LOW) {
    if (!pedestrianRequested) {
      pedestrianRequested = true;
      Serial.println("  [REQUEST] Pedestrian waiting");
    }
    delay(200);
  }

  lastButtonState = currentButtonState;
}

// State machine update
void updateStateMachine(unsigned long timeInState) {
  switch (currentState) {

    case STATE_RED:
      if (timeInState >= RED_DURATION) {
        transitionTo(STATE_RED_YELLOW);
      }
      break;

    case STATE_RED_YELLOW:
      if (timeInState >= RED_YELLOW_DURATION) {
        transitionTo(STATE_GREEN);
      }
      break;

    case STATE_GREEN:
      // Check for pedestrian interrupt
      if (pedestrianRequested && timeInState >= GREEN_MIN_DURATION) {
        transitionTo(STATE_YELLOW);
      }
      // Or normal timeout
      else if (timeInState >= GREEN_DURATION) {
        transitionTo(STATE_YELLOW);
      }
      break;

    case STATE_YELLOW:
      if (timeInState >= YELLOW_DURATION) {
        if (pedestrianRequested) {
          transitionTo(STATE_PED_CROSSING);
          pedestrianRequested = false;
        } else {
          transitionTo(STATE_RED);
        }
      }
      break;

    case STATE_PED_CROSSING:
      if (timeInState >= PED_DURATION) {
        transitionTo(STATE_RED);
      }
      break;
  }
}

// State transition with logging and safety
void transitionTo(TrafficState newState) {
  // Safety check: verify transition is valid
  if (!isValidTransition(currentState, newState)) {
    Serial.println("[ERROR] Invalid state transition!");
    return;
  }

  // Log transition
  Serial.print("TRANSITION: ");
  printStateName(currentState);
  Serial.print(" -> ");
  printStateName(newState);
  Serial.println();

  // Change state
  currentState = newState;
  stateStartTime = millis();

  // Enter new state
  enterState(newState);
}

// Enter state - set outputs
void enterState(TrafficState state) {
  switch (state) {
    case STATE_RED:
      setTrafficLights(HIGH, LOW, LOW);
      setPedestrianLights(HIGH, LOW);
      break;

    case STATE_RED_YELLOW:
      setTrafficLights(HIGH, HIGH, LOW);
      setPedestrianLights(HIGH, LOW);
      break;

    case STATE_GREEN:
      setTrafficLights(LOW, LOW, HIGH);
      setPedestrianLights(HIGH, LOW);
      break;

    case STATE_YELLOW:
      setTrafficLights(LOW, HIGH, LOW);
      setPedestrianLights(HIGH, LOW);
      break;

    case STATE_PED_CROSSING:
      setTrafficLights(HIGH, LOW, LOW);
      setPedestrianLights(LOW, HIGH);
      break;
  }
}

// Safety: check if transition is valid
bool isValidTransition(TrafficState from, TrafficState to) {
  // Can't go from GREEN directly to RED (must go through YELLOW)
  if (from == STATE_GREEN && to == STATE_RED) {
    return false;
  }

  // Add more rules as needed
  return true;
}

// Helper: print state name
void printStateName(TrafficState state) {
  switch (state) {
    case STATE_RED:         Serial.print("RED"); break;
    case STATE_RED_YELLOW:  Serial.print("RED_YELLOW"); break;
    case STATE_GREEN:       Serial.print("GREEN"); break;
    case STATE_YELLOW:      Serial.print("YELLOW"); break;
    case STATE_PED_CROSSING: Serial.print("PED_CROSSING"); break;
  }
}

// Helper: set traffic lights
void setTrafficLights(bool red, bool yellow, bool green) {
  digitalWrite(RED_TRAFFIC, red);
  digitalWrite(YELLOW_TRAFFIC, yellow);
  digitalWrite(GREEN_TRAFFIC, green);
}

// Helper: set pedestrian lights
void setPedestrianLights(bool red, bool green) {
  digitalWrite(RED_PED, red);
  digitalWrite(GREEN_PED, green);
}

/*
 * PROFESSIONAL TECHNIQUES DEMONSTRATED:
 *
 * 1. ENUM for states (not #define numbers)
 * 2. const for timing (not #define)
 * 3. Separate functions for:
 *    - Input processing
 *    - State updates
 *    - State transitions
 *    - Output control
 * 4. Safety validation
 * 5. Clear logging
 * 6. Consistent naming
 * 7. Comments explaining WHY not just WHAT
 *
 * This is industry-standard embedded code structure!
 */