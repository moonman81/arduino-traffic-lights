/*
 * Task ADV.2: Code Organization with Functions
 * =============================================
 *
 * Learn to organize code with functions
 * Refactoring: making code better WITHOUT changing behavior
 *
 * BEFORE: All code in loop() - hard to read
 * AFTER: Organized into logical functions - easy to understand
 */

#define RED_LED    12
#define YELLOW_LED 11
#define GREEN_LED  10

void setup() {
  pinMode(RED_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);

  Serial.begin(9600);
  Serial.println("Function Organization Example");
}

void loop() {
  // Look how clean and readable this is!
  redPhase();
  redYellowPhase();
  greenPhase();
  yellowPhase();
}

// Each phase gets its own function
void redPhase() {
  Serial.println("RED");
  setLights(HIGH, LOW, LOW);
  delay(5000);
}

void redYellowPhase() {
  Serial.println("RED + YELLOW");
  setLights(HIGH, HIGH, LOW);
  delay(2000);
}

void greenPhase() {
  Serial.println("GREEN");
  setLights(LOW, LOW, HIGH);
  delay(6000);
}

void yellowPhase() {
  Serial.println("YELLOW");
  setLights(LOW, HIGH, LOW);
  delay(3000);
}

// Helper function to set all lights at once
void setLights(bool red, bool yellow, bool green) {
  digitalWrite(RED_LED, red);
  digitalWrite(YELLOW_LED, yellow);
  digitalWrite(GREEN_LED, green);
}

/*
 * WHY FUNCTIONS?
 *
 * BEFORE (without functions):
 * loop() {
 *   Serial.println("RED");
 *   digitalWrite(12, HIGH);
 *   digitalWrite(11, LOW);
 *   digitalWrite(10, LOW);
 *   delay(5000);
 *   Serial.println("YELLOW");
 *   digitalWrite(12, LOW);
 *   digitalWrite(11, HIGH);
 *   digitalWrite(10, LOW);
 *   delay(2000);
 *   // ... 50 more lines ...
 * }
 * HARD TO READ!
 *
 * AFTER (with functions):
 * loop() {
 *   redPhase();
 *   yellowPhase();
 *   greenPhase();
 * }
 * EASY TO READ!
 *
 * BENEFITS:
 * 1. Easier to understand
 * 2. Easier to modify (change one function)
 * 3. Reusable (call same function multiple times)
 * 4. Easier to test
 * 5. Professional code structure
 *
 * WHEN TO MAKE A FUNCTION:
 * - Code is repeated
 * - Logical group of actions
 * - More than ~5 lines doing one thing
 * - Want to reuse code
 *
 * FUNCTION STRUCTURE:
 * returnType functionName(parameters) {
 *   // code here
 *   return value;  // if returnType is not void
 * }
 */