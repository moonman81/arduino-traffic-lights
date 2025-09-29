/*
 * Task L1.1 & L1.2: Arduino Connection Test
 * ==========================================
 *
 * This is the simplest possible Arduino program.
 * Use this to test that your Arduino is connected and working.
 *
 * WHAT IT DOES:
 * - Flashes the built-in LED on the Arduino board (pin 13)
 * - No external components needed!
 *
 * EXPECTED RESULT:
 * - Small LED on Arduino board blinks once per second
 *
 * SUCCESS = Your Arduino works! Move to L1.3
 */

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);  // LED_BUILTIN = pin 13 on most Arduinos
}

void loop() {
  digitalWrite(LED_BUILTIN, HIGH);  // Turn on
  delay(1000);                      // Wait 1 second
  digitalWrite(LED_BUILTIN, LOW);   // Turn off
  delay(1000);                      // Wait 1 second
}

/*
 * TROUBLESHOOTING:
 * - Nothing happens? Check USB cable is connected
 * - Upload error? Check Tools → Board → Arduino Uno
 * - Wrong port? Check Tools → Port → Select your Arduino
 */