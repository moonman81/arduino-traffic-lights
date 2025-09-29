/*
 * THEORY-FIRST TRACK: Understanding Before Building
 * ==================================================
 *
 * This code demonstrates state machine theory with
 * extensive comments explaining WHY, not just HOW
 *
 * READ THIS CODE, understand it, THEN build hardware
 *
 * THEORY CONCEPTS DEMONSTRATED:
 * - Finite State Machines (FSM)
 * - State transitions
 * - Temporal logic
 * - Safety invariants
 */

// ============================================================
// CONCEPT 1: States
// ============================================================
// A state machine has discrete states. At any moment,
// the system is in EXACTLY ONE state.
//
// Our traffic light has 4 states:
enum State {
  RED,         // State 0: Traffic must stop
  RED_YELLOW,  // State 1: Prepare to proceed
  GREEN,       // State 2: Traffic may proceed
  YELLOW       // State 3: Prepare to stop
};

// Current state - the system's "memory"
State currentState = RED;

// ============================================================
// CONCEPT 2: Time
// ============================================================
// Transitions happen based on time (temporal logic)
// We track "how long in current state?"
unsigned long stateStartTime = 0;

// Duration for each state (in milliseconds)
const unsigned long RED_DURATION = 5000;
const unsigned long RED_YELLOW_DURATION = 2000;
const unsigned long GREEN_DURATION = 6000;
const unsigned long YELLOW_DURATION = 3000;

// ============================================================
// CONCEPT 3: Outputs
// ============================================================
// Each state has associated outputs (lights)
// Outputs are a FUNCTION of state
#define RED_LED    12
#define YELLOW_LED 11
#define GREEN_LED  10

void setup() {
  pinMode(RED_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);

  Serial.begin(9600);
  Serial.println("=== State Machine Theory Demo ===");

  stateStartTime = millis();
  printStateInfo();
}

void loop() {
  // ============================================================
  // CONCEPT 4: State Updates
  // ============================================================
  // Each loop iteration:
  // 1. Check if transition condition met
  // 2. If yes, transition to next state
  // 3. Update outputs based on current state

  unsigned long elapsed = millis() - stateStartTime;

  // ============================================================
  // CONCEPT 5: Deterministic Transitions
  // ============================================================
  // Transitions are DETERMINISTIC: given current state and
  // elapsed time, next state is always the same

  switch (currentState) {
    case RED:
      // Output function for RED state
      setLights(HIGH, LOW, LOW);

      // Transition condition: time >= duration
      if (elapsed >= RED_DURATION) {
        transition(RED_YELLOW);  // Deterministic next state
      }
      break;

    case RED_YELLOW:
      setLights(HIGH, HIGH, LOW);

      if (elapsed >= RED_YELLOW_DURATION) {
        transition(GREEN);
      }
      break;

    case GREEN:
      setLights(LOW, LOW, HIGH);

      if (elapsed >= GREEN_DURATION) {
        transition(YELLOW);
      }
      break;

    case YELLOW:
      setLights(LOW, HIGH, LOW);

      if (elapsed >= YELLOW_DURATION) {
        transition(RED);  // Cycle complete
      }
      break;
  }
}

// ============================================================
// CONCEPT 6: State Transitions
// ============================================================
// Transitions are atomic: instantaneous change from one
// state to another. System is never "between states"
void transition(State newState) {
  Serial.print("TRANSITION: ");
  printStateName(currentState);
  Serial.print(" -> ");
  printStateName(newState);
  Serial.println();

  // Update state variable
  currentState = newState;

  // Reset time counter for new state
  stateStartTime = millis();

  printStateInfo();
}

// ============================================================
// CONCEPT 7: Output Function
// ============================================================
// Outputs are determined by current state
// This is the "Moore Machine" model: outputs depend only
// on current state, not on inputs
void setLights(bool red, bool yellow, bool green) {
  digitalWrite(RED_LED, red);
  digitalWrite(YELLOW_LED, yellow);
  digitalWrite(GREEN_LED, green);
}

// ============================================================
// HELPER FUNCTIONS
// ============================================================
void printStateName(State s) {
  switch (s) {
    case RED:        Serial.print("RED"); break;
    case RED_YELLOW: Serial.print("RED_YELLOW"); break;
    case GREEN:      Serial.print("GREEN"); break;
    case YELLOW:     Serial.print("YELLOW"); break;
  }
}

void printStateInfo() {
  Serial.print("  State: ");
  printStateName(currentState);
  Serial.print(" (Duration: ");

  switch (currentState) {
    case RED:        Serial.print(RED_DURATION); break;
    case RED_YELLOW: Serial.print(RED_YELLOW_DURATION); break;
    case GREEN:      Serial.print(GREEN_DURATION); break;
    case YELLOW:     Serial.print(YELLOW_DURATION); break;
  }

  Serial.println("ms)");
}

/*
 * ============================================================
 * FORMAL STATE MACHINE DEFINITION
 * ============================================================
 *
 * M = (S, I, O, δ, λ, s₀)
 *
 * Where:
 * S = {RED, RED_YELLOW, GREEN, YELLOW}         // States
 * I = {timeout}                                // Inputs
 * O = {red_on, yellow_on, green_on}            // Outputs
 * δ = state transition function                // See transition()
 * λ = output function                          // See setLights()
 * s₀ = RED                                     // Initial state
 *
 * TRANSITION FUNCTION δ:
 * δ(RED, timeout) = RED_YELLOW
 * δ(RED_YELLOW, timeout) = GREEN
 * δ(GREEN, timeout) = YELLOW
 * δ(YELLOW, timeout) = RED
 *
 * OUTPUT FUNCTION λ:
 * λ(RED) = (1, 0, 0)
 * λ(RED_YELLOW) = (1, 1, 0)
 * λ(GREEN) = (0, 0, 1)
 * λ(YELLOW) = (0, 1, 0)
 *
 * ============================================================
 * SAFETY INVARIANT
 * ============================================================
 *
 * ∀t: ¬(green(t) ∧ red(t))
 * "At all times, green and red are never both on"
 *
 * This is PROVEN by inspection of λ: no state outputs (1,*,1)
 *
 * ============================================================
 * LIVENESS PROPERTY
 * ============================================================
 *
 * ∀s ∈ S: ◇(state = s)
 * "Eventually, every state is reached"
 *
 * This is guaranteed by deterministic cycle:
 * RED → RED_YELLOW → GREEN → YELLOW → RED → ...
 *
 * ============================================================
 * NOW BUILD IT!
 * ============================================================
 *
 * You understand the theory. Now build the hardware
 * and see the theory become reality!
 */