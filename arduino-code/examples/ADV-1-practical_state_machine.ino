// ADV-1-practical: State Machine (Practical Focus)
// Difficulty: ⭐⭐⭐⭐☆ (4 stars)
// Time: 45 minutes
// Prerequisites: L3-7b (complete system)

// This is the practical-focused variant of ADV-1 state machine.
// Instead of heavy theory, this focuses on:
// - DOING: Refactoring working code to use enum
// - SEEING: How professional structure improves debugging
// - BUILDING: Safety checks through code, not math

// DIFFERENCE from ADV-1 (theory):
// - Less mathematical notation
// - More code examples and experiments
// - Focus on debugging and extension
// - Practical safety checks vs formal verification

#define BUTTON_PIN 13
#define RED_TRAFFIC    12
#define YELLOW_TRAFFIC 11
#define GREEN_TRAFFIC  10
#define RED_PED         9
#define GREEN_PED       8

// PROFESSIONAL PATTERN: Use enum instead of #define
// Why? Compiler catches errors, better debugging, clearer intent
enum TrafficState {
  RED,
  RED_YELLOW,
  GREEN,
  YELLOW,
  PED_CROSSING
};

// State names for debugging (array maps enum to string)
const char* stateNames[] = {
  "RED",
  "RED_YELLOW",
  "GREEN",
  "YELLOW",
  "PED_CROSSING"
};

// Timing constants
const unsigned long RED_TIME = 5000;
const unsigned long RED_YELLOW_TIME = 2000;
const unsigned long GREEN_TIME = 6000;
const unsigned long GREEN_MIN_TIME = 3000;
const unsigned long YELLOW_TIME = 3000;
const unsigned long PED_CROSS_TIME = 8000;

// State variables
TrafficState currentState = RED;
unsigned long stateStartTime = 0;
bool pedestrianRequested = false;
bool lastButtonState = HIGH;

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(RED_TRAFFIC, OUTPUT);
  pinMode(YELLOW_TRAFFIC, OUTPUT);
  pinMode(GREEN_TRAFFIC, OUTPUT);
  pinMode(RED_PED, OUTPUT);
  pinMode(GREEN_PED, OUTPUT);

  Serial.begin(9600);
  Serial.println("=== State Machine (Practical) ===");
  Serial.println("Professional code structure demo");
  Serial.println();

  stateStartTime = millis();
}

void loop() {
  unsigned long currentTime = millis();
  unsigned long timeInState = currentTime - stateStartTime;

  checkButton();

  // State machine with enum (cleaner switch)
  switch (currentState) {

    case RED:
      setTrafficLights(HIGH, LOW, LOW);
      setPedestrianLights(HIGH, LOW);

      if (timeInState >= RED_TIME) {
        transitionTo(RED_YELLOW);
      }
      break;

    case RED_YELLOW:
      setTrafficLights(HIGH, HIGH, LOW);
      setPedestrianLights(HIGH, LOW);

      if (timeInState >= RED_YELLOW_TIME) {
        transitionTo(GREEN);
      }
      break;

    case GREEN:
      setTrafficLights(LOW, LOW, HIGH);
      setPedestrianLights(HIGH, LOW);

      if (pedestrianRequested && timeInState >= GREEN_MIN_TIME) {
        Serial.println("  -> Pedestrian interrupt");
        transitionTo(YELLOW);
      }
      else if (timeInState >= GREEN_TIME) {
        transitionTo(YELLOW);
      }
      break;

    case YELLOW:
      setTrafficLights(LOW, HIGH, LOW);
      setPedestrianLights(HIGH, LOW);

      if (timeInState >= YELLOW_TIME) {
        if (pedestrianRequested) {
          transitionTo(PED_CROSSING);
          pedestrianRequested = false;
        } else {
          transitionTo(RED);
        }
      }
      break;

    case PED_CROSSING:
      setTrafficLights(HIGH, LOW, LOW);
      setPedestrianLights(LOW, HIGH);

      if (timeInState >= PED_CROSS_TIME) {
        transitionTo(RED);
      }
      break;
  }

  // PRACTICAL SAFETY: Check continuously
  verifySafety();
}

void checkButton() {
  bool currentButtonState = digitalRead(BUTTON_PIN);

  if (lastButtonState == HIGH && currentButtonState == LOW) {
    if (!pedestrianRequested) {
      pedestrianRequested = true;
      Serial.println(">>> Button: Pedestrian waiting");
    }
    delay(200);
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

void transitionTo(TrafficState newState) {
  // Log transition
  Serial.print("Transition: ");
  Serial.print(stateNames[currentState]);
  Serial.print(" -> ");
  Serial.println(stateNames[newState]);

  currentState = newState;
  stateStartTime = millis();
}

void verifySafety() {
  // PRACTICAL SAFETY CHECK: Never both greens
  bool trafficGreen = digitalRead(GREEN_TRAFFIC);
  bool pedGreen = digitalRead(GREEN_PED);

  if (trafficGreen && pedGreen) {
    // SAFETY VIOLATION!
    Serial.println("!!! SAFETY ERROR: Both greens lit !!!");

    // Emergency safe state: All red
    setTrafficLights(HIGH, LOW, LOW);
    setPedestrianLights(HIGH, LOW);

    // Halt system
    while(true) {
      delay(1000);
      Serial.println("System halted - safety violation");
    }
  }
}

// ============================================================
// WHAT YOU'VE LEARNED (PRACTICAL FOCUS):
// ============================================================

// 1. ENUM vs #DEFINE
//    - Enums are type-safe (compiler catches mistakes)
//    - Can use in switch statements cleanly
//    - Better debugging (shows state names, not numbers)

// 2. NAMED CONSTANTS
//    - const unsigned long RED_TIME vs magic number 5000
//    - Easy to adjust timing in one place
//    - Self-documenting code

// 3. CENTRALIZED STATE TRANSITIONS
//    - transitionTo() function logs all changes
//    - Easy to add validation or safety checks
//    - Single point to modify transition behavior

// 4. RUNTIME SAFETY CHECKS
//    - verifySafety() runs continuously
//    - Catches bugs immediately
//    - Halts system in safe state if error detected

// 5. STATE NAME DEBUGGING
//    - stateNames[] array for readable output
//    - Serial shows "RED -> RED_YELLOW" not "0 -> 1"
//    - Easier to understand logs

// ============================================================
// EXPERIMENTS TO TRY:
// ============================================================

// EXPERIMENT 1: Break the safety
// - Temporarily set both greens HIGH in a state
// - Watch safety system catch it and halt
// - This proves your safety check works!

// EXPERIMENT 2: Add transition validation
// - Create isValidTransition(from, to) function
// - Return false for invalid transitions (like GREEN -> RED)
// - Prevent bugs before they happen

// EXPERIMENT 3: Add state entry/exit actions
// - Create enterState() and exitState() functions
// - Log when entering/leaving each state
// - Track total time spent in each state

// EXPERIMENT 4: Add statistics
// - Count how many times each state visited
// - Track average time in each state
// - Display stats on command (type 's' in serial)

// ============================================================
// COMPARISON: This vs L3-7b
// ============================================================

// L3-7b (working code):
// - #define for states (numbers)
// - Direct state assignment
// - changeState() just updates variables

// ADV-1-practical (professional):
// - enum for states (type-safe)
// - transitionTo() with logging
// - verifySafety() continuous checks
// - Named constants
// - State name array for debugging

// BOTH DO THE SAME THING functionally!
// Difference is maintainability and debugging.

// ============================================================
// NEXT STEPS:
// ============================================================

// Continue Advanced Path:
// → ADV-2: Add interrupt-based button (no debounce delay needed)
// → ADV-3: Implement formal state table with validation

// Or explore theory version:
// → ADV-1 (theory): Learn FSM mathematical formalism
// → See documentation/TRAFFIC_LIGHT_FSA_ANALYSIS.md

// Or extend this project:
// - Add night mode (all flashing yellow)
// - Add emergency vehicle override (all red)
// - Add pedestrian countdown display
// - Log statistics to SD card

// ============================================================
// ADV-1-PRACTICAL COMPLETE!
// ============================================================