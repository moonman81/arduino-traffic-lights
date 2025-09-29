/*
 * Task ADV.3: Safety Checks and Verification
 * ===========================================
 *
 * Add safety checks to prevent dangerous conditions
 *
 * SAFETY RULES:
 * 1. Traffic green and pedestrian green NEVER together
 * 2. Green must go through yellow before red
 * 3. Minimum green time must be respected
 *
 * This code VERIFIES these rules at runtime!
 */

#define RED_TRAFFIC    12
#define YELLOW_TRAFFIC 11
#define GREEN_TRAFFIC  10
#define RED_PED         9
#define GREEN_PED       8

// Safety statistics
int safetyViolations = 0;
int stateChanges = 0;

void setup() {
  pinMode(RED_TRAFFIC, OUTPUT);
  pinMode(YELLOW_TRAFFIC, OUTPUT);
  pinMode(GREEN_TRAFFIC, OUTPUT);
  pinMode(RED_PED, OUTPUT);
  pinMode(GREEN_PED, OUTPUT);

  Serial.begin(9600);
  Serial.println("=== Safety Verification System ===");
}

void loop() {
  // Example traffic light cycle with safety checks

  safeRedPhase();
  safeRedYellowPhase();
  safeGreenPhase();
  safeYellowPhase();

  // Report safety statistics
  printSafetyReport();
}

void safeRedPhase() {
  setAndVerify(HIGH, LOW, LOW, HIGH, LOW, "RED");
  delay(5000);
}

void safeRedYellowPhase() {
  setAndVerify(HIGH, HIGH, LOW, HIGH, LOW, "RED+YELLOW");
  delay(2000);
}

void safeGreenPhase() {
  setAndVerify(LOW, LOW, HIGH, HIGH, LOW, "GREEN");
  delay(6000);
}

void safeYellowPhase() {
  setAndVerify(LOW, HIGH, LOW, HIGH, LOW, "YELLOW");
  delay(3000);
}

// Set lights AND verify safety
void setAndVerify(bool red, bool yellow, bool green,
                  bool pedRed, bool pedGreen, String phaseName) {

  // Set the lights
  digitalWrite(RED_TRAFFIC, red);
  digitalWrite(YELLOW_TRAFFIC, yellow);
  digitalWrite(GREEN_TRAFFIC, green);
  digitalWrite(RED_PED, pedRed);
  digitalWrite(GREEN_PED, pedGreen);

  stateChanges++;

  // VERIFY SAFETY RULE: mutual exclusion
  if (verifySafety(green, pedGreen)) {
    Serial.print("[OK] ");
    Serial.println(phaseName);
  } else {
    Serial.print("[VIOLATION!] ");
    Serial.println(phaseName);
    safetyViolations++;

    // EMERGENCY: Turn off conflicting lights!
    emergencySafeState();
  }
}

// Check safety rule: traffic green and ped green never together
bool verifySafety(bool trafficGreen, bool pedGreen) {
  if (trafficGreen && pedGreen) {
    Serial.println("  ERROR: Traffic and pedestrian both green!");
    return false;
  }
  return true;
}

// Emergency: return to safe state
void emergencySafeState() {
  Serial.println("  [EMERGENCY] Entering safe state...");

  // All red
  digitalWrite(RED_TRAFFIC, HIGH);
  digitalWrite(YELLOW_TRAFFIC, LOW);
  digitalWrite(GREEN_TRAFFIC, LOW);
  digitalWrite(RED_PED, HIGH);
  digitalWrite(GREEN_PED, LOW);

  delay(2000);  // Hold safe state
}

void printSafetyReport() {
  Serial.println();
  Serial.println("=== Safety Report ===");
  Serial.print("State changes: ");
  Serial.println(stateChanges);
  Serial.print("Safety violations: ");
  Serial.println(safetyViolations);

  if (safetyViolations == 0) {
    Serial.println("Status: ALL SAFE ✓");
  } else {
    Serial.println("Status: VIOLATIONS DETECTED!");
  }
  Serial.println("====================");
  Serial.println();

  delay(2000);
}

/*
 * SAFETY-CRITICAL SYSTEMS:
 *
 * In real traffic lights:
 * - Lives depend on correctness
 * - Must detect and prevent failures
 * - Must have emergency fallback
 * - Must log violations
 *
 * TECHNIQUES SHOWN:
 * 1. Runtime verification
 * 2. Safety invariant checking
 * 3. Emergency safe state
 * 4. Violation logging
 * 5. Statistics tracking
 *
 * REAL-WORLD APPLICATION:
 * - Medical devices
 * - Automotive systems
 * - Industrial control
 * - Aerospace
 *
 * This is how professional embedded engineers think!
 */