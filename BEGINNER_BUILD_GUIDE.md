# Arduino Traffic Light - Complete Tutorial

## About This Guide

This is a comprehensive step-by-step tutorial for building an Arduino traffic light system. You'll start with a single blinking LED and progress to a complete UK-standard traffic light with pedestrian crossing.

**Prerequisites:** None. This guide assumes no prior Arduino or electronics experience.

**Time required:** Can be completed in stages:
- Level 1 (first LED): 10-15 minutes
- Level 2 (traffic light): 45 minutes
- Level 3 (full system): 2-3 hours total

**What you'll build:** Three progressive projects, each working independently:
1. Single blinking LED
2. Three-LED traffic light
3. Complete system with pedestrian button

---

## UK Qualification Suitability

This project meets requirements for:
- GCSE Computer Science and Design & Technology
- BTEC Level 2/3 Engineering (Units 1,2,3,4,5,6,8,17)
- A-Level Computer Science (FSM theory and NEA coursework)
- T-Level Digital Production and Engineering

Teachers: See `UK_CURRICULUM_MAPPING.md` for assessment evidence guidance.

---

## Part 1: What You Need (Shopping List)

### Hardware Components:
- [ ] 1× Arduino Uno R3 (the brain)
- [ ] 1× Breadboard (the building platform)
- [ ] 5× LEDs in these colors:
  - 1× Red LED (traffic light)
  - 1× Yellow/Amber LED (traffic light)
  - 1× Green LED (traffic light)
  - 1× Red LED (pedestrian signal)
  - 1× Green/White LED (pedestrian signal)
- [ ] 5× 220Ω or 330Ω resistors (to protect the LEDs)
- [ ] 1× Push button (for pedestrian crossing)
- [ ] Jumper wires (about 15 wires, male-to-male)
- [ ] USB cable (to connect Arduino to computer)

### Software:
- [ ] Arduino IDE (free download from arduino.cc)
- [ ] OR use Tinkercad Circuits (free online simulator - no hardware needed!)

**Cost:** About $20-30 for all components if buying new

---

## Part 2: Understanding the Basics

### What is an LED?

LED = Light Emitting Diode. It's a tiny light that:
- Has a **long leg** (positive side, called anode)
- Has a **short leg** (negative side, called cathode)
- Needs a **resistor** to avoid burning out

### What is a Resistor?

A resistor limits electrical current. Think of it like a water tap - it controls how much electricity flows through the LED.

**How to read resistor colors:**
- 220Ω: Red-Red-Brown-Gold stripes
- 330Ω: Orange-Orange-Brown-Gold stripes

Both work fine for our project!

### What is a Breadboard?

A breadboard is like a socket board with holes. Rows are connected inside horizontally, and the side rails run vertically. No soldering needed!

---

## Part 3: Project Progression (Three Levels)

We'll build this project in **three stages**:

1. **Level 1 - Single Blink:** Make one LED blink (5 minutes)
2. **Level 2 - Basic Traffic Light:** Make 3 LEDs work like a traffic light (30 minutes)
3. **Level 3 - Full System:** Add pedestrian crossing button (1-2 hours)

You can stop at any level! Each one works on its own.

---

## Level 1: Make One LED Blink

**Goal:** Light up a single LED and make it blink

### Step 1: Connect Your Arduino
1. Plug USB cable into Arduino
2. Connect other end to your computer
3. Arduino should light up (small LED on board)

### Step 2: Build the Circuit

**Physical Setup:**
```
Arduino Pin 13 → Long leg of RED LED → Resistor → Arduino GND
```

**Detailed steps:**
1. Put RED LED into breadboard
   - Long leg in row 10 column E
   - Short leg in row 11 column E
2. Put resistor in breadboard
   - One end in row 10 column F
   - Other end in row 15 column F
3. Wire from Arduino Pin 13 to row 15 (where resistor is)
4. Wire from Arduino GND to row 11 (LED short leg)

### Step 3: Upload the Code

Open Arduino IDE and paste this code:

```cpp
// My First LED Program!

void setup() {
  pinMode(13, OUTPUT);  // Pin 13 controls the LED
}

void loop() {
  digitalWrite(13, HIGH);  // Turn LED ON
  delay(1000);             // Wait 1 second
  digitalWrite(13, LOW);   // Turn LED OFF
  delay(1000);             // Wait 1 second
}
```

**What this code does:**
- `pinMode(13, OUTPUT)` → "Pin 13 will control something"
- `digitalWrite(13, HIGH)` → "Turn pin 13 ON"
- `delay(1000)` → "Wait 1000 milliseconds (1 second)"
- `loop()` → This section repeats forever

### Step 4: Upload and Test

1. Click **Tools** → **Board** → **Arduino Uno**
2. Click **Tools** → **Port** → Select your Arduino port
3. Click the **Upload** button (right arrow icon)
4. Watch your LED blink!

**Success Check:**
✅ LED blinks on and off every second

**Troubleshooting:**
- LED doesn't light? Check LED is right way around (long leg to resistor)
- Still nothing? Check wire connections are firm
- Upload error? Check correct board and port selected

---

## Level 2: Basic Traffic Light (3 LEDs)

**Goal:** Create a proper traffic light sequence: Red → Red+Amber → Green → Amber → Red

### Step 1: Understand UK Traffic Lights

UK traffic lights work like this:

```
RED (Stop!)           → 5 seconds
RED + AMBER (Get ready) → 2 seconds
GREEN (Go!)           → 6 seconds
AMBER (Slow down!)    → 3 seconds
(back to RED)
```

### Step 2: Build the Circuit

Now we'll add 2 more LEDs!

**Pin assignments:**
- Pin 12 → Red LED
- Pin 11 → Amber/Yellow LED
- Pin 10 → Green LED

**Building instructions:**

1. **Red LED (already done from Level 1, but move it):**
   - Long leg → row 5
   - Resistor → row 5 to row 8
   - Wire: Pin 12 to row 8
   - Wire: LED short leg (row 6) to GND rail

2. **Amber LED:**
   - Long leg → row 10
   - Resistor → row 10 to row 13
   - Wire: Pin 11 to row 13
   - Wire: LED short leg (row 11) to GND rail

3. **Green LED:**
   - Long leg → row 15
   - Resistor → row 15 to row 18
   - Wire: Pin 10 to row 18
   - Wire: LED short leg (row 16) to GND rail

**Visual layout:**
```
Arduino Uno R3          Breadboard

Pin 12 ----[220Ω]----(Red LED)----+
Pin 11 ----[220Ω]----(Amber LED)--+---- GND
Pin 10 ----[220Ω]----(Green LED)--+

GND -------------------------------+
```

### Step 3: The Code

```cpp
// UK Traffic Light Controller - Basic Version
// Red -> Red+Amber -> Green -> Amber -> repeat

// Pin definitions (where each LED is connected)
#define RED_LED    12
#define AMBER_LED  11
#define GREEN_LED  10

void setup() {
  // Tell Arduino these pins control LEDs
  pinMode(RED_LED, OUTPUT);
  pinMode(AMBER_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);

  // Turn all LEDs off to start
  digitalWrite(RED_LED, LOW);
  digitalWrite(AMBER_LED, LOW);
  digitalWrite(GREEN_LED, LOW);
}

void loop() {
  // PHASE 1: RED light (stop)
  digitalWrite(RED_LED, HIGH);      // Red ON
  digitalWrite(AMBER_LED, LOW);     // Amber OFF
  digitalWrite(GREEN_LED, LOW);     // Green OFF
  delay(5000);                      // Wait 5 seconds

  // PHASE 2: RED + AMBER (get ready)
  digitalWrite(RED_LED, HIGH);      // Red stays ON
  digitalWrite(AMBER_LED, HIGH);    // Amber ON
  digitalWrite(GREEN_LED, LOW);     // Green OFF
  delay(2000);                      // Wait 2 seconds

  // PHASE 3: GREEN light (go)
  digitalWrite(RED_LED, LOW);       // Red OFF
  digitalWrite(AMBER_LED, LOW);     // Amber OFF
  digitalWrite(GREEN_LED, HIGH);    // Green ON
  delay(6000);                      // Wait 6 seconds

  // PHASE 4: AMBER light (slow down)
  digitalWrite(RED_LED, LOW);       // Red OFF
  digitalWrite(AMBER_LED, HIGH);    // Amber ON
  digitalWrite(GREEN_LED, LOW);     // Green OFF
  delay(3000);                      // Wait 3 seconds

  // Loop back to RED automatically
}
```

**Code explanation:**
- `#define` creates a nickname so we can say "RED_LED" instead of "12"
- Each phase: Turn on the right lights, wait the right time
- When loop() finishes, it automatically starts again

### Step 4: Test It!

Upload the code and watch your traffic light!

**Success Check:**
✅ Red for 5 seconds
✅ Red + Amber together for 2 seconds
✅ Green for 6 seconds
✅ Amber for 3 seconds
✅ Pattern repeats

**Troubleshooting:**
- Wrong LED lighting? Check pin numbers match in code and wiring
- Multiple LEDs on at wrong time? Check each short leg goes to GND
- Timing feels wrong? That's normal - hard to judge seconds. Trust it!

---

## Level 3: Full Traffic Light with Pedestrian Crossing

**Goal:** Add a button so pedestrians can request to cross the road

### Step 1: Add Pedestrian LEDs and Button

Now we add:
- 2 more LEDs (red and green for pedestrians)
- 1 button (to request crossing)

**New pin assignments:**
- Pin 13 → Pedestrian Button (input)
- Pin 9 → Pedestrian Red LED
- Pin 8 → Pedestrian Green LED

**Building instructions:**

1. **Pedestrian Red LED:**
   - Long leg → row 20
   - Resistor → row 20 to row 23
   - Wire: Pin 9 to row 23
   - Wire: LED short leg (row 21) to GND rail

2. **Pedestrian Green LED:**
   - Long leg → row 25
   - Resistor → row 25 to row 28
   - Wire: Pin 8 to row 28
   - Wire: LED short leg (row 26) to GND rail

3. **Pedestrian Button:**
   - Place button across the center gap of breadboard
   - One side → Pin 13 (with wire)
   - Other side → GND rail (with wire)
   - No resistor needed! (Arduino has internal pull-up)

**Complete circuit:**
```
Pin 13 ---- Button ---- GND

Pin 12 ----[220Ω]---- Red Traffic LED ----+
Pin 11 ----[220Ω]---- Amber Traffic LED --+
Pin 10 ----[220Ω]---- Green Traffic LED --+---- GND
Pin 9  ----[220Ω]---- Ped Red LED --------+
Pin 8  ----[220Ω]---- Ped Green LED ------+
```

### Step 2: Understanding the Button Logic

When you press the button:
- During GREEN traffic light → After 3 seconds minimum, traffic goes amber then red
- During RED/AMBER/AMBER → Request is remembered for later
- Then pedestrian gets GREEN light for 8 seconds to cross safely

**Safety rule:** Traffic gets at least 3 seconds of green before interruption. This is fair!

### Step 3: The Code (Simplified Version)

This is a simplified but complete version. For the advanced version with all safety checks, see `traffic-lights-arduino-clean.c`.

```cpp
// UK Traffic Light with Pedestrian Crossing - Beginner Version
// This version is simplified but fully functional!

// ============================================
// Pin Definitions
// ============================================
#define PEDESTRIAN_BUTTON    13
#define RED_TRAFFIC_LED      12
#define AMBER_TRAFFIC_LED    11
#define GREEN_TRAFFIC_LED    10
#define PEDESTRIAN_RED_LED    9
#define PEDESTRIAN_GREEN_LED  8

// ============================================
// Timing Constants (in milliseconds)
// ============================================
#define RED_TIME              5000  // 5 seconds
#define RED_AMBER_TIME        2000  // 2 seconds
#define GREEN_TIME            6000  // 6 seconds
#define GREEN_MINIMUM_TIME    3000  // 3 seconds minimum
#define AMBER_TIME            3000  // 3 seconds
#define PEDESTRIAN_TIME       8000  // 8 seconds

// ============================================
// Variables
// ============================================
bool pedestrianWaiting = false;  // Is someone waiting to cross?
unsigned long phaseStartTime = 0; // When did current phase start?

void setup() {
  // Setup pins
  pinMode(RED_TRAFFIC_LED, OUTPUT);
  pinMode(AMBER_TRAFFIC_LED, OUTPUT);
  pinMode(GREEN_TRAFFIC_LED, OUTPUT);
  pinMode(PEDESTRIAN_RED_LED, OUTPUT);
  pinMode(PEDESTRIAN_GREEN_LED, OUTPUT);
  pinMode(PEDESTRIAN_BUTTON, INPUT_PULLUP);

  // Start with debugging messages
  Serial.begin(9600);
  Serial.println("Traffic Light System Ready!");

  // Remember when we started
  phaseStartTime = millis();
}

void loop() {
  // Check if button is pressed (LOW because INPUT_PULLUP)
  if (digitalRead(PEDESTRIAN_BUTTON) == LOW) {
    pedestrianWaiting = true;  // Remember someone wants to cross
    Serial.println("Button pressed! Pedestrian waiting...");
    delay(200);  // Debounce - ignore repeated presses
  }

  // Run the traffic light sequence
  runTrafficLightCycle();
}

void runTrafficLightCycle() {
  unsigned long currentTime = millis();

  // ============================================
  // PHASE 1: RED (5 seconds)
  // ============================================
  setTrafficLights(HIGH, LOW, LOW);  // Red on
  setPedestrianLights(HIGH, LOW);    // Ped red on
  Serial.println("TRAFFIC: RED");

  // Wait for red duration
  phaseStartTime = currentTime;
  while (millis() - phaseStartTime < RED_TIME) {
    checkButton();  // Keep checking button while waiting
  }

  // ============================================
  // PHASE 2: RED + AMBER (2 seconds)
  // ============================================
  setTrafficLights(HIGH, HIGH, LOW);  // Red + Amber on
  setPedestrianLights(HIGH, LOW);     // Ped red on
  Serial.println("TRAFFIC: RED + AMBER (Get ready!)");

  phaseStartTime = millis();
  while (millis() - phaseStartTime < RED_AMBER_TIME) {
    checkButton();
  }

  // ============================================
  // PHASE 3: GREEN (6 seconds, or until pedestrian)
  // ============================================
  setTrafficLights(LOW, LOW, HIGH);  // Green on
  setPedestrianLights(HIGH, LOW);    // Ped red on
  Serial.println("TRAFFIC: GREEN");

  phaseStartTime = millis();
  bool greenInterrupted = false;

  // Stay green for minimum 3 seconds
  while (millis() - phaseStartTime < GREEN_MINIMUM_TIME) {
    checkButton();
  }

  // After minimum time, check if pedestrian waiting
  if (pedestrianWaiting) {
    greenInterrupted = true;
    Serial.println("Pedestrian requested - cutting green short!");
  } else {
    // Continue for full green time
    while (millis() - phaseStartTime < GREEN_TIME) {
      checkButton();
      if (pedestrianWaiting) {
        greenInterrupted = true;
        break;
      }
    }
  }

  // ============================================
  // PHASE 4: AMBER (3 seconds)
  // ============================================
  setTrafficLights(LOW, HIGH, LOW);  // Amber on
  setPedestrianLights(HIGH, LOW);    // Ped red on
  Serial.println("TRAFFIC: AMBER (Slow down!)");

  phaseStartTime = millis();
  while (millis() - phaseStartTime < AMBER_TIME) {
    checkButton();
  }

  // ============================================
  // PHASE 5: PEDESTRIAN CROSSING (if requested)
  // ============================================
  if (pedestrianWaiting) {
    setTrafficLights(HIGH, LOW, LOW);  // Red on (traffic stopped)
    setPedestrianLights(LOW, HIGH);    // Ped GREEN on
    Serial.println("PEDESTRIAN: GREEN (Cross now!)");

    phaseStartTime = millis();
    while (millis() - phaseStartTime < PEDESTRIAN_TIME) {
      // Pedestrians crossing - don't check button
    }

    pedestrianWaiting = false;  // Request completed
    Serial.println("Pedestrian crossing complete");
  }

  // Loop continues back to RED phase
}

// ============================================
// Helper Functions
// ============================================

void setTrafficLights(bool red, bool amber, bool green) {
  digitalWrite(RED_TRAFFIC_LED, red);
  digitalWrite(AMBER_TRAFFIC_LED, amber);
  digitalWrite(GREEN_TRAFFIC_LED, green);
}

void setPedestrianLights(bool red, bool green) {
  digitalWrite(PEDESTRIAN_RED_LED, red);
  digitalWrite(PEDESTRIAN_GREEN_LED, green);
}

void checkButton() {
  if (digitalRead(PEDESTRIAN_BUTTON) == LOW && !pedestrianWaiting) {
    pedestrianWaiting = true;
    Serial.println("Button pressed!");
    delay(200);  // Debounce
  }
}
```

### Step 4: Testing Your Full System

**Test checklist:**

1. **Basic cycle (no button press):**
   - ✅ Red → Red+Amber → Green → Amber → Red
   - ✅ Pedestrian red stays on during traffic lights

2. **Button during green (after 3 seconds):**
   - ✅ Press button after green has been on a while
   - ✅ Green should switch to amber quickly
   - ✅ Then red traffic + green pedestrian
   - ✅ Pedestrian green for 8 seconds

3. **Button during red:**
   - ✅ Press button during red light
   - ✅ System remembers and activates pedestrian phase after next amber

4. **Serial Monitor (debugging):**
   - Open Tools → Serial Monitor (set to 9600 baud)
   - Watch messages appear showing what's happening

**Troubleshooting:**

| Problem | Solution |
|---------|----------|
| Button doesn't work | Check one leg to pin 13, other to GND |
| Button triggers multiple times | Normal! The debounce delay helps |
| Pedestrian never gets green | Check `pedestrianWaiting` is being set |
| Lights stay on | Check all LED short legs go to GND |
| Nothing works | Check power: USB connected? LEDs the right way? |

---

## Part 4: Understanding How It Works

### The `millis()` Function

`millis()` returns how many milliseconds since Arduino started. Think of it like a stopwatch that never stops.

**Example:**
```cpp
unsigned long startTime = millis();  // Remember when we started
// ... do stuff ...
unsigned long elapsed = millis() - startTime;  // How long has passed?
```

### Variables Explained

```cpp
bool pedestrianWaiting = false;
```
- `bool` = boolean (true or false)
- This remembers if someone pressed the button

```cpp
unsigned long phaseStartTime = 0;
```
- `unsigned long` = big number (for milliseconds)
- This remembers when the current phase started

### Why INPUT_PULLUP?

When you set a pin to `INPUT_PULLUP`:
- Normally the pin reads HIGH (5V)
- When button pressed and connects to GND, it reads LOW (0V)
- This is opposite of what you might expect!
- That's why we check `if (digitalRead(PEDESTRIAN_BUTTON) == LOW)`

---

## Part 5: Next Steps & Improvements

### Congratulations! You've built a working traffic light system!

### Ideas to improve your project:

1. **Add sounds:**
   - Buzzer on pin 7
   - Beep during pedestrian crossing

2. **Add flashing amber:**
   - Make amber blink for the last 3 seconds of pedestrian crossing
   - Warning that pedestrian time is ending

3. **Two-way traffic lights:**
   - Build a second set for the cross street
   - Make sure they never both show green!

4. **Night mode:**
   - Add a light sensor
   - Flash amber at night when it's quiet

5. **LCD display:**
   - Show countdown timer
   - Display "WAIT" or "CROSS" messages

### Learn more:

- **Explore the advanced code:** `traffic-lights-arduino-clean.c` has safety checks and better structure
- **Read about state machines:** See `TRAFFIC_LIGHT_FSA_ANALYSIS.md`
- **Understand the theory:** Check out `ONTOLOGICAL_ANALYSIS_TRAFFIC_SYSTEM.md`

---

## Part 6: Troubleshooting Guide

### Common Issues:

**"avrdude: ser_open(): can't open device"**
- Solution: Check correct port selected in Tools → Port
- Solution: Close any other programs using the Arduino

**LED is dim or doesn't light up:**
- Check LED polarity (long leg to resistor side)
- Check resistor value (220Ω or 330Ω, not 10kΩ!)
- Try a different LED (might be broken)

**Button always triggers / never stops:**
- Check button wiring (one side to GND, other to pin 13)
- Check `INPUT_PULLUP` is set in code
- Add longer debounce delay (try 500ms)

**Lights flash weirdly:**
- Check no wires are loose
- Check breadboard connections are firm
- Check no wires are touching that shouldn't be

**Upload fails:**
- Check board type: Tools → Board → Arduino Uno
- Check port selected: Tools → Port → (your Arduino)
- Try unplugging and replugging USB
- Try a different USB cable

---

## Part 7: Safety & Best Practices

### Electrical Safety:

✅ **DO:**
- Use resistors with all LEDs (220Ω or 330Ω)
- Connect Arduino to computer USB (5V only)
- Check connections before powering on
- Unplug while making changes

❌ **DON'T:**
- Connect LEDs without resistors (they'll burn out!)
- Use external power supplies without adult supervision
- Touch components while powered on
- Force components into breadboard

### Code Best Practices:

✅ **DO:**
- Use meaningful names (`RED_LED` not `x`)
- Add comments explaining what code does
- Test one small change at a time
- Save your code often

❌ **DON'T:**
- Copy code you don't understand
- Change lots of things at once
- Forget to save before uploading
- Delete code that works!

---

## Part 8: Getting Help

### Stuck? Try these:

1. **Read the error message carefully** - it often tells you what's wrong
2. **Check the troubleshooting sections** in this guide
3. **Compare your circuit** to the diagrams
4. **Test with Level 1** (single LED) to verify basics work
5. **Search online** - others have likely had the same problem!

### Useful Resources:

- **Arduino Official**: arduino.cc/reference
- **Tinkercad Circuits**: tinkercad.com (practice online for free!)
- **Arduino Forum**: forum.arduino.cc
- **YouTube**: Search "Arduino traffic light tutorial"

---

## Summary

### What you've learned:

✅ How to connect LEDs to an Arduino
✅ How to use digital pins as outputs
✅ How to create timed sequences with delays
✅ How to read button inputs
✅ How to build a complete traffic control system
✅ How to debug and troubleshoot circuits

### Your achievements:

🏆 **Level 1:** Single blinking LED
🏆 **Level 2:** Complete 3-LED traffic light
🏆 **Level 3:** Full pedestrian crossing system

---

## Final Notes

**This project teaches real engineering concepts:**
- State machines (different phases)
- Timing control (milliseconds)
- Input/output (buttons and LEDs)
- Safety considerations (minimum green time)
- Debouncing (handling button presses correctly)

These same concepts are used in:
- Real traffic lights
- Industrial control systems
- Video games (character states)
- Robotics
- Home automation

**You're learning real skills!**

Now go experiment, make changes, and build something awesome!

---

*Made simple so anyone can learn. If you found this helpful, share it with others!*