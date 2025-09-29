/*
 * LEVEL 1: Single Blinking LED
 * ============================
 *
 * This is your first Arduino program!
 * It makes one LED blink on and off every second.
 *
 * WHAT YOU'LL LEARN:
 * - How to control an LED
 * - What pinMode() does
 * - What digitalWrite() does
 * - How delay() works
 *
 * HARDWARE NEEDED:
 * - Arduino Uno
 * - 1 Red LED
 * - 1 resistor (220Ω or 330Ω)
 * - 2 jumper wires
 *
 * WIRING:
 * Arduino Pin 13 → Resistor → LED long leg → LED short leg → GND
 */

// This runs once when Arduino starts
void setup() {
  pinMode(13, OUTPUT);  // Pin 13 will control the LED
}

// This runs over and over forever
void loop() {
  digitalWrite(13, HIGH);  // Turn LED ON (HIGH = 5 volts)
  delay(1000);             // Wait 1000 milliseconds (1 second)

  digitalWrite(13, LOW);   // Turn LED OFF (LOW = 0 volts)
  delay(1000);             // Wait 1 second

  // Now loop() starts again automatically!
}

/*
 * CHALLENGES TO TRY:
 * 1. Make it blink faster (change delay to 500)
 * 2. Make it blink slower (change delay to 2000)
 * 3. Make it stay on longer than off (different delays)
 * 4. Make an SOS pattern: dot-dot-dot-dash-dash-dash-dot-dot-dot
 */