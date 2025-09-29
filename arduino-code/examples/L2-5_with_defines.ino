/*
 * Task L2.5: Using #define for Clean Code
 * ========================================
 *
 * Learn to write more readable code with #define
 * This is the SAME as L2.4 but shows WHY #define helps
 *
 * COMPARE THIS:
 * digitalWrite(12, HIGH);  // What's 12? You have to remember!
 *
 * TO THIS:
 * digitalWrite(RED_LED, HIGH);  // Obviously the red LED!
 */

// Pin definitions at the top - easy to change!
#define RED_LED    12
#define YELLOW_LED 11
#define GREEN_LED  10

// Timing definitions - easy to adjust all at once!
#define RED_TIME         5000
#define RED_YELLOW_TIME  2000
#define GREEN_TIME       6000
#define YELLOW_TIME      3000

void setup() {
  pinMode(RED_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
}

void loop() {
  // Now the code is MUCH more readable!

  // RED phase
  digitalWrite(RED_LED, HIGH);
  digitalWrite(YELLOW_LED, LOW);
  digitalWrite(GREEN_LED, LOW);
  delay(RED_TIME);

  // RED + YELLOW phase
  digitalWrite(RED_LED, HIGH);
  digitalWrite(YELLOW_LED, HIGH);
  digitalWrite(GREEN_LED, LOW);
  delay(RED_YELLOW_TIME);

  // GREEN phase
  digitalWrite(RED_LED, LOW);
  digitalWrite(YELLOW_LED, LOW);
  digitalWrite(GREEN_LED, HIGH);
  delay(GREEN_TIME);

  // YELLOW phase
  digitalWrite(RED_LED, LOW);
  digitalWrite(YELLOW_LED, HIGH);
  digitalWrite(GREEN_LED, LOW);
  delay(YELLOW_TIME);
}

/*
 * BENEFITS OF #DEFINE:
 * 1. Code is easier to read (RED_LED vs 12)
 * 2. Easy to change pins (change once at top)
 * 3. Easy to adjust timing (change once at top)
 * 4. Fewer mistakes (can't typo a number)
 *
 * PROFESSIONAL TIP: Always use #define for pins and constants!
 */