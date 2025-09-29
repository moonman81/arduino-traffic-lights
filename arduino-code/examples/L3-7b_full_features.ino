// L3-7b: Complete Pedestrian System with Full Features
// Difficulty: ⭐⭐⭐⭐☆ (4 stars)
// Time: 30 minutes
// Prerequisites: L3-7a (basic integration)
// This is the FINAL Level 3 task!

// This is the complete system with all features:
// - Traffic lights (3 LEDs)
// - Pedestrian lights (2 LEDs)
// - Button-activated pedestrian crossing
// - Full 5-state state machine
// - Safety: traffic RED during pedestrian GREEN
// - Request queuing and minimum time guarantees

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

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(RED_TRAFFIC, OUTPUT);
  pinMode(YELLOW_TRAFFIC, OUTPUT);
  pinMode(GREEN_TRAFFIC, OUTPUT);
  pinMode(RED_PED, OUTPUT);
  pinMode(GREEN_PED, OUTPUT);

  Serial.begin(9600);
  Serial.println("=== Complete Pedestrian Crossing System ===");
  Serial.println("Press button to request pedestrian crossing");
  Serial.println();

  stateStartTime = millis();
}

void loop() {
  unsigned long currentTime = millis();
  unsigned long timeInState = currentTime - stateStartTime;

  // Check button
  checkButton();

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
// CONGRATULATIONS! YOU'VE BUILT A COMPLETE EMBEDDED SYSTEM!
// ============================================================

// WHAT YOU'VE ACCOMPLISHED:
// ✅ 5-state finite state machine
// ✅ Non-blocking timing with millis()
// ✅ Button input with edge detection
// ✅ Request queuing across states
// ✅ Minimum time guarantee (safety feature)
// ✅ Pedestrian crossing integration
// ✅ Serial debugging
// ✅ Helper functions for code organization
// ✅ UK traffic light standards compliance

// REAL-WORLD APPLICATIONS:
// This exact pattern is used in:
// - Actual traffic light controllers
// - Industrial automation systems
// - IoT devices
// - Robotics control systems
// - Any embedded system requiring state-based control

// TESTING CHECKLIST:
// [ ] Normal cycle works without button press
// [ ] Button during GREEN (early) - waits for minimum time
// [ ] Button during GREEN (late) - immediate transition
// [ ] Button during RED/YELLOW - request queued for later
// [ ] Pedestrian crossing gives full 8 seconds
// [ ] Traffic stays RED during pedestrian GREEN (safety!)
// [ ] Serial monitor shows all state changes
// [ ] Multiple button presses don't cause issues

// COMMON ISSUES AND FIXES:
// - Button does nothing: Check INPUT_PULLUP mode
// - Pedestrian never gets crossing: Check minimum time logic
// - Traffic and ped both green: Check STATE_PED_CROSS LEDs
// - Random behavior: Check breadboard connections

// NEXT STEPS - WHERE TO GO FROM HERE:
//
// Option 1: ADVANCED LEVEL (Theory & Professional Code)
// - Learn about formal state machines (FSM/FSA)
// - Implement advanced safety verification
// - Professional code structure with enums
// - → See QUEST_ADVANCED.md
//
// Option 2: EXTEND THIS PROJECT
// - Add countdown timer display
// - Add audio beeps for pedestrian
// - Add night mode (flashing yellow)
// - Multiple crossings (two buttons)
//
// Option 3: DIFFERENT PROJECT
// - Now you understand: states, timing, buttons, LEDs
// - Apply to: burglar alarm, game controller, weather station
// - The patterns you learned here work everywhere!

// THIS CODE IS YOURS - MODIFY IT, BREAK IT, FIX IT!
// The best way to learn is to experiment.

// ============================================================
// LEVEL 3 COMPLETE! 🎉
// ============================================================