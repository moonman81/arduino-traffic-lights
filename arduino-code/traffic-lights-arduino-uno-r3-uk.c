// UK Traffic Light Controller for Arduino Uno R3
// Implements proper UK traffic light sequence with pedestrian crossing
//
// Quick Reference - UK Traffic Light System:
// Pin 13 -> Pedestrian Button (other side to GND)
// Pin 12 -> Red LED (through 220Ω resistor)
// Pin 11 -> Amber LED (through 220Ω resistor)
// Pin 10 -> Green LED (through 220Ω resistor)
// Pin 9  -> Pedestrian Red LED (through 220Ω resistor)
// Pin 8  -> Pedestrian Green LED (through 220Ω resistor)
// All LED cathodes (-) -> GND

// Pin definitions - UK Traffic Light System
#define PEDESTRIAN_BUTTON 13
#define RED_LED 12
#define AMBER_LED 11           // UK uses "amber" not "orange"
#define GREEN_LED 10
#define PEDESTRIAN_RED 9
#define PEDESTRIAN_GREEN 8

// Timing constants (in milliseconds) - UK standard timings
#define RED_DURATION 5000
#define RED_AMBER_DURATION 2000
#define GREEN_DURATION 6000
#define AMBER_DURATION 3000
#define PEDESTRIAN_CROSSING_TIME 8000
#define DEBOUNCE_DELAY 50

// State variables
bool pedestrianRequested = false;
unsigned long lastButtonPress = 0;
unsigned long stateStartTime = 0;
int currentState = 0;

// Traffic light states
enum TrafficStates {
  STATE_RED,
  STATE_RED_AMBER,
  STATE_GREEN,
  STATE_AMBER,
  STATE_PEDESTRIAN_CROSSING
};

void setup() {
  // Initialize LED pins as outputs
  pinMode(RED_LED, OUTPUT);
  pinMode(AMBER_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(PEDESTRIAN_RED, OUTPUT);
  pinMode(PEDESTRIAN_GREEN, OUTPUT);

  // Initialize button pin as input with pull-up resistor
  pinMode(PEDESTRIAN_BUTTON, INPUT_PULLUP);

  // Initialize serial communication for debugging
  Serial.begin(9600);

  // Start with red light and pedestrian red
  currentState = STATE_RED;
  stateStartTime = millis();
  setTrafficLights(HIGH, LOW, LOW);
  setPedestrianLights(HIGH, LOW);

  Serial.println("UK Traffic Light Controller Started");
}

void loop() {
  unsigned long currentTime = millis();

  // Check for pedestrian button press with debouncing
  checkPedestrianButton(currentTime);

  // Handle traffic light state machine
  switch (currentState) {
    case STATE_RED:
      if (currentTime - stateStartTime >= RED_DURATION) {
        changeState(STATE_RED_AMBER, currentTime);
        setTrafficLights(HIGH, HIGH, LOW);
        Serial.println("State: Red + Amber");
      }
      break;

    case STATE_RED_AMBER:
      if (currentTime - stateStartTime >= RED_AMBER_DURATION) {
        changeState(STATE_GREEN, currentTime);
        setTrafficLights(LOW, LOW, HIGH);
        setPedestrianLights(HIGH, LOW);  // Pedestrian red when traffic green
        Serial.println("State: Green");
      }
      break;

    case STATE_GREEN:
      // Check if pedestrian crossing requested or normal green time elapsed
      if (pedestrianRequested || (currentTime - stateStartTime >= GREEN_DURATION)) {
        changeState(STATE_AMBER, currentTime);
        setTrafficLights(LOW, HIGH, LOW);
        Serial.println("State: Amber");
      }
      break;

    case STATE_AMBER:
      if (currentTime - stateStartTime >= AMBER_DURATION) {
        if (pedestrianRequested) {
          changeState(STATE_PEDESTRIAN_CROSSING, currentTime);
          setTrafficLights(HIGH, LOW, LOW);
          setPedestrianLights(LOW, HIGH);  // Pedestrian green when traffic red
          pedestrianRequested = false;
          Serial.println("State: Pedestrian Crossing");
        } else {
          changeState(STATE_RED, currentTime);
          setTrafficLights(HIGH, LOW, LOW);
          setPedestrianLights(HIGH, LOW);  // Pedestrian red
          Serial.println("State: Red");
        }
      }
      break;

    case STATE_PEDESTRIAN_CROSSING:
      if (currentTime - stateStartTime >= PEDESTRIAN_CROSSING_TIME) {
        changeState(STATE_RED, currentTime);
        setPedestrianLights(HIGH, LOW);  // Back to pedestrian red
        Serial.println("State: Red (after pedestrian crossing)");
      }
      break;
  }
}

void setTrafficLights(int redState, int amberState, int greenState) {
  digitalWrite(RED_LED, redState);
  digitalWrite(AMBER_LED, amberState);
  digitalWrite(GREEN_LED, greenState);
}

void setPedestrianLights(int redState, int greenState) {
  digitalWrite(PEDESTRIAN_RED, redState);
  digitalWrite(PEDESTRIAN_GREEN, greenState);
}

void changeState(int newState, unsigned long currentTime) {
  currentState = newState;
  stateStartTime = currentTime;
}

void checkPedestrianButton(unsigned long currentTime) {
  // Read button state (LOW when pressed due to INPUT_PULLUP)
  if (digitalRead(PEDESTRIAN_BUTTON) == LOW) {
    // Debounce button press
    if (currentTime - lastButtonPress > DEBOUNCE_DELAY) {
      if (!pedestrianRequested && currentState == STATE_GREEN) {
        pedestrianRequested = true;
        Serial.println("Pedestrian crossing requested");
      }
      lastButtonPress = currentTime;
    }
  }
}