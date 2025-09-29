/*
 * LEVEL 3: Traffic Light with Pedestrian Crossing
 * ================================================
 *
 * Complete traffic light system with pedestrian button!
 * This is a simplified version that's easier to understand.
 *
 * FEATURES:
 * - UK traffic light sequence
 * - Pedestrian button
 * - Pedestrian red/green lights
 * - Fair timing (3 second minimum green for traffic)
 * - Serial debugging messages
 *
 * HARDWARE NEEDED:
 * - Arduino Uno
 * - 3 LEDs for traffic (Red, Amber, Green)
 * - 2 LEDs for pedestrian (Red, Green)
 * - 5 resistors (220Ω or 330Ω)
 * - 1 push button
 * - Jumper wires and breadboard
 *
 * WIRING:
 * Pin 13 → Button → GND (no resistor needed!)
 * Pin 12 → [Resistor] → Red Traffic LED → GND
 * Pin 11 → [Resistor] → Amber Traffic LED → GND
 * Pin 10 → [Resistor] → Green Traffic LED → GND
 * Pin 9  → [Resistor] → Red Pedestrian LED → GND
 * Pin 8  → [Resistor] → Green Pedestrian LED → GND
 */

// ============================================
// Pin Definitions
// ============================================
#define PEDESTRIAN_BUTTON    13
#define RED_TRAFFIC_LED      12
#define AMBER_TRAFFIC_LED    11
#define GREEN_TRAFFIC_LED    10
#define PEDESTRIAN_RED_LED    9
#define PEDESTRIAN_GREEN_LED  8

// ============================================
// Timing Constants (in milliseconds)
// ============================================
#define RED_TIME              5000  // 5 seconds
#define RED_AMBER_TIME        2000  // 2 seconds
#define GREEN_TIME            6000  // 6 seconds
#define GREEN_MINIMUM_TIME    3000  // 3 seconds (fair play!)
#define AMBER_TIME            3000  // 3 seconds
#define PEDESTRIAN_TIME       8000  // 8 seconds to cross

// ============================================
// Variables
// ============================================
bool pedestrianWaiting = false;     // Is someone waiting to cross?
unsigned long phaseStartTime = 0;    // When did current phase start?

// ============================================
// Setup - runs once at start
// ============================================
void setup() {
  // Setup all the pins
  pinMode(RED_TRAFFIC_LED, OUTPUT);
  pinMode(AMBER_TRAFFIC_LED, OUTPUT);
  pinMode(GREEN_TRAFFIC_LED, OUTPUT);
  pinMode(PEDESTRIAN_RED_LED, OUTPUT);
  pinMode(PEDESTRIAN_GREEN_LED, OUTPUT);
  pinMode(PEDESTRIAN_BUTTON, INPUT_PULLUP);  // Internal pull-up resistor

  // Start Serial for debugging messages
  Serial.begin(9600);
  Serial.println("=================================");
  Serial.println("Traffic Light System Started!");
  Serial.println("Press button to cross road");
  Serial.println("=================================");

  // Remember when we started
  phaseStartTime = millis();
}

// ============================================
// Main Loop - runs forever
// ============================================
void loop() {
  // Check if button is pressed
  // (LOW because INPUT_PULLUP makes it HIGH normally)
  if (digitalRead(PEDESTRIAN_BUTTON) == LOW) {
    if (!pedestrianWaiting) {  // Only log first press
      pedestrianWaiting = true;
      Serial.println(">>> Button pressed! Pedestrian waiting...");
    }
    delay(200);  // Debounce - ignore repeated presses for 200ms
  }

  // Run the traffic light sequence
  runTrafficLightCycle();
}

// ============================================
// Traffic Light Cycle Function
// ============================================
void runTrafficLightCycle() {
  unsigned long currentTime = millis();

  // ==========================================
  // PHASE 1: RED (5 seconds)
  // ==========================================
  setTrafficLights(HIGH, LOW, LOW);  // Red on
  setPedestrianLights(HIGH, LOW);     // Pedestrian red on
  Serial.println("\n[TRAFFIC: RED - 5 seconds]");

  phaseStartTime = currentTime;
  while (millis() - phaseStartTime < RED_TIME) {
    checkButton();  // Keep checking button
  }

  // ==========================================
  // PHASE 2: RED + AMBER (2 seconds)
  // ==========================================
  setTrafficLights(HIGH, HIGH, LOW);  // Red + Amber on
  setPedestrianLights(HIGH, LOW);     // Pedestrian red on
  Serial.println("[TRAFFIC: RED + AMBER - Get ready!]");

  phaseStartTime = millis();
  while (millis() - phaseStartTime < RED_AMBER_TIME) {
    checkButton();
  }

  // ==========================================
  // PHASE 3: GREEN (6 seconds, or interrupted)
  // ==========================================
  setTrafficLights(LOW, LOW, HIGH);   // Green on
  setPedestrianLights(HIGH, LOW);     // Pedestrian red on
  Serial.println("[TRAFFIC: GREEN - 6 seconds]");

  phaseStartTime = millis();

  // Stay green for minimum 3 seconds (fair to traffic!)
  while (millis() - phaseStartTime < GREEN_MINIMUM_TIME) {
    checkButton();
  }

  // After minimum time, check if pedestrian is waiting
  if (pedestrianWaiting) {
    Serial.println("  -> Pedestrian waiting! Cutting green short...");
  } else {
    // Continue for full green time
    while (millis() - phaseStartTime < GREEN_TIME) {
      checkButton();
      if (pedestrianWaiting) {
        Serial.println("  -> Pedestrian pressed button!");
        break;  // Exit green early
      }
    }
  }

  // ==========================================
  // PHASE 4: AMBER (3 seconds)
  // ==========================================
  setTrafficLights(LOW, HIGH, LOW);   // Amber on
  setPedestrianLights(HIGH, LOW);     // Pedestrian red on
  Serial.println("[TRAFFIC: AMBER - Prepare to stop!]");

  phaseStartTime = millis();
  while (millis() - phaseStartTime < AMBER_TIME) {
    checkButton();
  }

  // ==========================================
  // PHASE 5: PEDESTRIAN CROSSING (if requested)
  // ==========================================
  if (pedestrianWaiting) {
    setTrafficLights(HIGH, LOW, LOW);   // Traffic RED (stopped)
    setPedestrianLights(LOW, HIGH);     // Pedestrian GREEN (cross now!)
    Serial.println("[PEDESTRIAN: GREEN - CROSS NOW! - 8 seconds]");

    phaseStartTime = millis();
    while (millis() - phaseStartTime < PEDESTRIAN_TIME) {
      // Wait for pedestrians to cross
      // Don't check button during crossing
    }

    pedestrianWaiting = false;  // Request completed
    Serial.println("  -> Crossing complete!");
  }

  // Loop continues automatically back to RED phase
}

// ============================================
// Helper Functions
// ============================================

// Set traffic light LEDs
void setTrafficLights(bool red, bool amber, bool green) {
  digitalWrite(RED_TRAFFIC_LED, red);
  digitalWrite(AMBER_TRAFFIC_LED, amber);
  digitalWrite(GREEN_TRAFFIC_LED, green);
}

// Set pedestrian LEDs
void setPedestrianLights(bool red, bool green) {
  digitalWrite(PEDESTRIAN_RED_LED, red);
  digitalWrite(PEDESTRIAN_GREEN_LED, green);
}

// Check button and update waiting flag
void checkButton() {
  if (digitalRead(PEDESTRIAN_BUTTON) == LOW && !pedestrianWaiting) {
    pedestrianWaiting = true;
    Serial.println("  >>> Button pressed!");
    delay(200);  // Debounce
  }
}

/*
 * ============================================
 * HOW THIS WORKS:
 * ============================================
 *
 * NORMAL CYCLE (no button press):
 * RED → RED+AMBER → GREEN → AMBER → back to RED
 *
 * WITH BUTTON PRESS:
 * 1. If pressed during GREEN (after 3 seconds): cuts to AMBER early
 * 2. If pressed during RED/AMBER/AMBER: remembered for after next AMBER
 * 3. Pedestrian gets 8 seconds of green light to cross safely
 * 4. Traffic red during pedestrian crossing (safe!)
 *
 * SAFETY FEATURES:
 * - Traffic always gets minimum 3 seconds of green (fair!)
 * - Traffic and pedestrian never both green (mutual exclusion)
 * - Pedestrian gets full 8 seconds to cross
 * - Button debouncing prevents false triggers
 *
 * DEBUGGING:
 * - Open Serial Monitor (Tools → Serial Monitor)
 * - Set baud rate to 9600
 * - Watch messages show what's happening
 *
 * ============================================
 * CHALLENGES TO TRY:
 * ============================================
 *
 * 1. Add flashing amber for last 3 seconds of pedestrian crossing
 * 2. Add a countdown display (3... 2... 1...)
 * 3. Make pedestrian green flash for last 2 seconds (warning)
 * 4. Add a buzzer that beeps during pedestrian crossing
 * 5. Count how many pedestrians cross per hour
 *
 * ============================================
 * WHAT YOU'VE LEARNED:
 * ============================================
 *
 * ✓ Digital input (button reading)
 * ✓ Digital output (LED control)
 * ✓ Timing with millis()
 * ✓ State machines (different phases)
 * ✓ Boolean variables (true/false flags)
 * ✓ Serial debugging
 * ✓ Functions for organization
 * ✓ Safety in embedded systems
 *
 * These are real engineering skills!
 * ============================================
 */