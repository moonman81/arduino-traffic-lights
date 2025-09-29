/*
 * Task L3.3: Add Pedestrian LEDs
 * ===============================
 *
 * Now we have 5 LEDs total:
 * - 3 for traffic (red, yellow, green)
 * - 2 for pedestrians (red, green)
 *
 * HARDWARE:
 * Pin 12 → Red Traffic LED
 * Pin 11 → Yellow Traffic LED
 * Pin 10 → Green Traffic LED
 * Pin 9  → Red Pedestrian LED
 * Pin 8  → Green Pedestrian LED
 *
 * WHAT IT DOES:
 * Traffic light cycles normally
 * Pedestrian red stays on (no crossing yet)
 */

#define RED_TRAFFIC    12
#define YELLOW_TRAFFIC 11
#define GREEN_TRAFFIC  10
#define RED_PED         9
#define GREEN_PED       8

void setup() {
  pinMode(RED_TRAFFIC, OUTPUT);
  pinMode(YELLOW_TRAFFIC, OUTPUT);
  pinMode(GREEN_TRAFFIC, OUTPUT);
  pinMode(RED_PED, OUTPUT);
  pinMode(GREEN_PED, OUTPUT);

  Serial.begin(9600);
  Serial.println("5 LED Test - Traffic + Pedestrian");
}

void loop() {
  // During traffic RED, pedestrians COULD cross (but we won't allow it yet)
  Serial.println("Traffic: RED");
  digitalWrite(RED_TRAFFIC, HIGH);
  digitalWrite(YELLOW_TRAFFIC, LOW);
  digitalWrite(GREEN_TRAFFIC, LOW);
  digitalWrite(RED_PED, HIGH);    // Pedestrians wait
  digitalWrite(GREEN_PED, LOW);
  delay(5000);

  // Traffic RED + YELLOW
  Serial.println("Traffic: RED + YELLOW");
  digitalWrite(RED_TRAFFIC, HIGH);
  digitalWrite(YELLOW_TRAFFIC, HIGH);
  digitalWrite(GREEN_TRAFFIC, LOW);
  digitalWrite(RED_PED, HIGH);    // Still waiting
  digitalWrite(GREEN_PED, LOW);
  delay(2000);

  // Traffic GREEN - cars can go, pedestrians must wait
  Serial.println("Traffic: GREEN");
  digitalWrite(RED_TRAFFIC, LOW);
  digitalWrite(YELLOW_TRAFFIC, LOW);
  digitalWrite(GREEN_TRAFFIC, HIGH);
  digitalWrite(RED_PED, HIGH);    // Still waiting
  digitalWrite(GREEN_PED, LOW);
  delay(6000);

  // Traffic YELLOW
  Serial.println("Traffic: YELLOW");
  digitalWrite(RED_TRAFFIC, LOW);
  digitalWrite(YELLOW_TRAFFIC, HIGH);
  digitalWrite(GREEN_TRAFFIC, LOW);
  digitalWrite(RED_PED, HIGH);    // Still waiting
  digitalWrite(GREEN_PED, LOW);
  delay(3000);
}

/*
 * NOTICE:
 * - Pedestrian red is ALWAYS on in this version
 * - We're not using the pedestrian green yet
 * - Next: Add button to trigger pedestrian crossing!
 *
 * SAFETY RULE:
 * Traffic green and pedestrian green should NEVER be on together!
 * That would be dangerous!
 */