# Quick Reference Card

## For when you need to remember something fast

---

## LED wiring

**Every LED needs:**
1. Long leg → resistor → Arduino pin
2. Short leg → GND

**Can't tell which leg?** Flat edge on LED = short leg (GND)

---

## Pin numbers

**Level 1 (1 LED):**
- Pin 13 → LED

**Level 2 (3 LEDs):**
- Pin 12 → Red
- Pin 11 → Yellow
- Pin 10 → Green

**Level 3 (5 LEDs + button):**
- Pin 12 → Red traffic
- Pin 11 → Yellow traffic
- Pin 10 → Green traffic
- Pin 9 → Red pedestrian
- Pin 8 → Green pedestrian
- Pin 13 → Button

---

## Upload code

1. **Tools** → **Board** → **Arduino Uno**
2. **Tools** → **Port** → Pick your Arduino
3. Click **→** (Upload button)
4. Wait for "Done uploading"

---

## Basic code structure

```cpp
void setup() {
  // Runs ONCE when Arduino starts
  pinMode(13, OUTPUT);
}

void loop() {
  // Runs FOREVER, repeats
  digitalWrite(13, HIGH);  // ON
  delay(1000);             // Wait 1 second
  digitalWrite(13, LOW);   // OFF
  delay(1000);             // Wait 1 second
}
```

---

## Common values

**Timing:**
- 1000 = 1 second
- 500 = half second
- 5000 = 5 seconds

**LED states:**
- HIGH = ON (5 volts)
- LOW = OFF (0 volts)

**Button reading:**
- HIGH = not pressed (with INPUT_PULLUP)
- LOW = pressed (with INPUT_PULLUP)

---

## Troubleshooting

### LED not working:
1. Check long leg goes to pin side
2. Check short leg goes to GND
3. Check wires pushed in firmly
4. Try a different LED

### Upload error:
1. Check USB cable (must be data cable)
2. Check port selected
3. Try different USB port

### Wrong pattern:
1. Check code matches example exactly
2. Count semicolons (;)
3. Upload again

---

## UK traffic light sequence

1. RED (5 sec)
2. RED + YELLOW (2 sec)
3. GREEN (6 sec)
4. YELLOW (3 sec)
5. Back to 1

**Total:** 16 seconds per cycle

---

## Files to use

**Just starting:**
- README.md (start here)
- START_HERE.md (pick your level)

**Building it:**
- QUEST_LEVEL_1.md (one LED)
- QUEST_LEVEL_2.md (traffic lights)
- QUEST_LEVEL_3.md (full system)

**Something broken:**
- TROUBLESHOOTING.md

**Code examples:**
- arduino-code/examples/L1-4_single_led_blink.ino
- arduino-code/examples/L2-4_uk_traffic_light.ino
- arduino-code/examples/L3-7b_full_features.ino

**For your tutor:**
- TUTOR_GUIDE.md
- UK_CURRICULUM_MAPPING.md

---

## Important: pinMode modes

```cpp
pinMode(13, OUTPUT);      // For LEDs
pinMode(2, INPUT_PULLUP); // For buttons
```

**Don't mix these up!**

---

## Print to serial monitor

```cpp
void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println("Hello");
  delay(1000);
}
```

Then: **Tools** → **Serial Monitor**
Check baud rate is **9600**

---

## #define (makes code readable)

Instead of:
```cpp
digitalWrite(12, HIGH);
```

Do this:
```cpp
#define RED 12
digitalWrite(RED, HIGH);
```

Easier to understand what RED means!

---

## Need more help?

**Start here:** [README.md](README.md)

**Troubleshooting:** [TROUBLESHOOTING.md](TROUBLESHOOTING.md)

**For tutors:** [TUTOR_GUIDE.md](TUTOR_GUIDE.md)

---

**Save this file or print it out to keep nearby while building!**