/*
 * Task L3.5: Using millis() for Non-Blocking Timing
 * ==================================================
 *
 * PROBLEM WITH delay():
 * - Program freezes during delay
 * - Can't check button during delay
 * - Can't do multiple things at once
 *
 * SOLUTION: millis()
 * - Returns time since Arduino started (in milliseconds)
 * - Program keeps running
 * - Can check button anytime!
 *
 * This example: Simple traffic light using millis()
 *
 * HARDWARE: 3 LEDs (traffic light)
 */

#define RED_LED    12
#define YELLOW_LED 11
#define GREEN_LED  10

// States
#define STATE_RED         0
#define STATE_RED_YELLOW  1
#define STATE_GREEN       2
#define STATE_YELLOW      3

// Timing (in milliseconds)
#define RED_TIME         5000
#define RED_YELLOW_TIME  2000
#define GREEN_TIME       6000
#define YELLOW_TIME      3000

// Variables
int currentState = STATE_RED;
unsigned long stateStartTime = 0;

void setup() {
  pinMode(RED_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);

  Serial.begin(9600);
  Serial.println("millis() Timing Example");

  stateStartTime = millis();  // Remember when we started
}

void loop() {
  unsigned long currentTime = millis();
  unsigned long timeInState = currentTime - stateStartTime;

  // Check if it's time to change state
  switch (currentState) {

    case STATE_RED:
      digitalWrite(RED_LED, HIGH);
      digitalWrite(YELLOW_LED, LOW);
      digitalWrite(GREEN_LED, LOW);

      if (timeInState >= RED_TIME) {
        currentState = STATE_RED_YELLOW;
        stateStartTime = currentTime;
        Serial.println("Changing to RED+YELLOW");
      }
      break;

    case STATE_RED_YELLOW:
      digitalWrite(RED_LED, HIGH);
      digitalWrite(YELLOW_LED, HIGH);
      digitalWrite(GREEN_LED, LOW);

      if (timeInState >= RED_YELLOW_TIME) {
        currentState = STATE_GREEN;
        stateStartTime = currentTime;
        Serial.println("Changing to GREEN");
      }
      break;

    case STATE_GREEN:
      digitalWrite(RED_LED, LOW);
      digitalWrite(YELLOW_LED, LOW);
      digitalWrite(GREEN_LED, HIGH);

      if (timeInState >= GREEN_TIME) {
        currentState = STATE_YELLOW;
        stateStartTime = currentTime;
        Serial.println("Changing to YELLOW");
      }
      break;

    case STATE_YELLOW:
      digitalWrite(RED_LED, LOW);
      digitalWrite(YELLOW_LED, HIGH);
      digitalWrite(GREEN_LED, LOW);

      if (timeInState >= YELLOW_TIME) {
        currentState = STATE_RED;
        stateStartTime = currentTime;
        Serial.println("Changing to RED");
      }
      break;
  }

  // No delay()! Loop runs continuously!
  // This means we can check buttons, read sensors, etc.
}

/*
 * HOW millis() WORKS:
 *
 * millis() returns time since Arduino started:
 * - At 0 seconds: millis() = 0
 * - At 1 second:  millis() = 1000
 * - At 1 minute:  millis() = 60000
 *
 * TECHNIQUE:
 * 1. Remember when state started (stateStartTime)
 * 2. Calculate how long we've been in state (currentTime - stateStartTime)
 * 3. When enough time passed, change state
 *
 * ADVANTAGES:
 * - No blocking!
 * - Can do other things in loop()
 * - Essential for responsive programs
 *
 * This is PROFESSIONAL Arduino programming!
 */