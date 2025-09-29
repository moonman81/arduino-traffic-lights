/*
 * Task L1.4: Single External LED Blink
 * =====================================
 *
 * Your first external circuit!
 *
 * HARDWARE:
 * Pin 13 → Resistor (220Ω) → LED long leg
 * LED short leg → GND
 *
 * WHAT YOU LEARN:
 * - pinMode() - configure pins
 * - digitalWrite() - turn pins ON/OFF
 * - delay() - wait for time
 * - HIGH = ON = 5V
 * - LOW = OFF = 0V
 */

void setup() {
  pinMode(13, OUTPUT);  // Pin 13 will control the LED
}

void loop() {
  digitalWrite(13, HIGH);  // Turn LED ON (5 volts)
  delay(1000);             // Wait 1000 milliseconds (1 second)

  digitalWrite(13, LOW);   // Turn LED OFF (0 volts)
  delay(1000);             // Wait 1 second

  // Loop automatically repeats forever!
}

/*
 * CHALLENGE: Try changing the numbers!
 * - delay(500) = blinks twice as fast
 * - delay(2000) = blinks half as fast
 * - Try different values and see what happens!
 */