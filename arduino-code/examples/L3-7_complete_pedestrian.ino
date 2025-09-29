/*
 * Task L3.7: Complete Pedestrian Crossing System
 * ===============================================
 *
 * FULL SYSTEM! Button-activated pedestrian crossing
 * Using millis() for non-blocking timing
 *
 * HARDWARE:
 * Pin 13 → Button → GND
 * Pin 12 → Red Traffic LED
 * Pin 11 → Yellow Traffic LED
 * Pin 10 → Green Traffic LED
 * Pin 9  → Red Pedestrian LED
 * Pin 8  → Green Pedestrian LED
 *
 * FEATURES:
 * - Normal traffic light cycle
 * - Button press requests pedestrian crossing
 * - Respects minimum green time (3 seconds)
 * - Safe: traffic red during pedestrian green
 */

#define BUTTON_PIN 13
#define RED_TRAFFIC    12
#define YELLOW_TRAFFIC 11
#define GREEN_TRAFFIC  10
#define RED_PED         9
#define GREEN_PED       8

// States
#define STATE_RED         0
#define STATE_RED_YELLOW  1
#define STATE_GREEN       2
#define STATE_YELLOW      3
#define STATE_PED_CROSS   4

// Timing
#define RED_TIME        5000
#define RED_YELLOW_TIME 2000
#define GREEN_TIME      6000
#define GREEN_MIN_TIME  3000  // Minimum before pedestrian can interrupt
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
  Serial.println("=== Complete Pedestrian Crossing ===");
  Serial.println("Press button to cross");

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

      // Check if pedestrian requested AND minimum time elapsed
      if (pedestrianRequested && timeInState >= GREEN_MIN_TIME) {
        Serial.println("  -> Pedestrian interrupt!");
        changeState(STATE_YELLOW);
      }
      // Or normal timeout
      else if (timeInState >= GREEN_TIME) {
        changeState(STATE_YELLOW);
      }
      break;

    case STATE_YELLOW:
      setTrafficLights(LOW, HIGH, LOW);
      setPedestrianLights(HIGH, LOW);

      if (timeInState >= YELLOW_TIME) {
        // If pedestrian waiting, go to pedestrian crossing
        if (pedestrianRequested) {
          changeState(STATE_PED_CROSS);
          pedestrianRequested = false;  // Clear request
        } else {
          changeState(STATE_RED);
        }
      }
      break;

    case STATE_PED_CROSS:
      setTrafficLights(HIGH, LOW, LOW);    // Traffic RED
      setPedestrianLights(LOW, HIGH);      // Pedestrian GREEN

      if (timeInState >= PED_CROSS_TIME) {
        changeState(STATE_RED);
      }
      break;
  }
}

void checkButton() {
  bool currentButtonState = digitalRead(BUTTON_PIN);

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

  // Print state name
  Serial.print("State: ");
  switch (newState) {
    case STATE_RED:         Serial.println("RED"); break;
    case STATE_RED_YELLOW:  Serial.println("RED+YELLOW"); break;
    case STATE_GREEN:       Serial.println("GREEN"); break;
    case STATE_YELLOW:      Serial.println("YELLOW"); break;
    case STATE_PED_CROSS:   Serial.println("PEDESTRIAN CROSSING"); break;
  }
}

/*
 * WHAT YOU'VE BUILT:
 * - 5-state state machine
 * - Non-blocking timing with millis()
 * - Button input processing
 * - Minimum time guarantee (safety)
 * - Request queuing
 * - Functions for organization
 * - Serial debugging
 *
 * This is a REAL embedded system!
 *
 * CONGRATULATIONS! You've completed Level 3!
 */