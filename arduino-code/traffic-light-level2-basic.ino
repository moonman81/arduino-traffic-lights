/*
 * LEVEL 2: Basic Traffic Light (3 LEDs)
 * ======================================
 *
 * This creates a UK-style traffic light sequence
 * RED → RED+AMBER → GREEN → AMBER → repeat
 *
 * WHAT YOU'LL LEARN:
 * - How to control multiple LEDs
 * - How to use #define for pin names
 * - How to create timed sequences
 * - UK traffic light patterns
 *
 * HARDWARE NEEDED:
 * - Arduino Uno
 * - 1 Red LED
 * - 1 Amber/Yellow LED
 * - 1 Green LED
 * - 3 resistors (220Ω or 330Ω)
 * - Jumper wires
 * - Breadboard
 *
 * WIRING:
 * Pin 12 → [Resistor] → Red LED → GND
 * Pin 11 → [Resistor] → Amber LED → GND
 * Pin 10 → [Resistor] → Green LED → GND
 */

// Pin definitions - makes code easier to read!
#define RED_LED    12
#define AMBER_LED  11
#define GREEN_LED  10

void setup() {
  // Tell Arduino these pins control LEDs (outputs)
  pinMode(RED_LED, OUTPUT);
  pinMode(AMBER_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);

  // Turn all LEDs off to start
  digitalWrite(RED_LED, LOW);
  digitalWrite(AMBER_LED, LOW);
  digitalWrite(GREEN_LED, LOW);
}

void loop() {
  // PHASE 1: RED light (STOP!)
  digitalWrite(RED_LED, HIGH);      // Red ON
  digitalWrite(AMBER_LED, LOW);     // Amber OFF
  digitalWrite(GREEN_LED, LOW);     // Green OFF
  delay(5000);                      // Wait 5 seconds

  // PHASE 2: RED + AMBER (Get ready to go)
  digitalWrite(RED_LED, HIGH);      // Red stays ON
  digitalWrite(AMBER_LED, HIGH);    // Amber ON
  digitalWrite(GREEN_LED, LOW);     // Green OFF
  delay(2000);                      // Wait 2 seconds

  // PHASE 3: GREEN light (GO!)
  digitalWrite(RED_LED, LOW);       // Red OFF
  digitalWrite(AMBER_LED, LOW);     // Amber OFF
  digitalWrite(GREEN_LED, HIGH);    // Green ON
  delay(6000);                      // Wait 6 seconds

  // PHASE 4: AMBER light (Prepare to stop)
  digitalWrite(RED_LED, LOW);       // Red OFF
  digitalWrite(AMBER_LED, HIGH);    // Amber ON
  digitalWrite(GREEN_LED, LOW);     // Green OFF
  delay(3000);                      // Wait 3 seconds

  // Now loop() runs again, back to RED
}

/*
 * HOW IT WORKS:
 * - We go through 4 phases in order
 * - Each phase sets the right LEDs on or off
 * - delay() makes each phase last the right amount of time
 * - When we finish, loop() starts again automatically
 *
 * TOTAL CYCLE TIME: 5 + 2 + 6 + 3 = 16 seconds
 *
 * CHALLENGES TO TRY:
 * 1. Make the green phase longer (change 6000 to 10000)
 * 2. Add Serial.println("RED") in each phase to see what's happening
 * 3. Speed up the whole thing (divide all delays by 2)
 * 4. Make it a US traffic light (remove RED+AMBER phase)
 */