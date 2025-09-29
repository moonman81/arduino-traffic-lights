# Level 2: Traffic Light

## Overview

**Difficulty:** Intermediate
**Time:** 45 minutes - 1 hour
**Prerequisites:** Level 1 complete, or basic Arduino experience

**Goal:** Build a three-LED traffic light following UK standards

**What you'll learn:**
- Controlling multiple LEDs
- Creating timed sequences
- Using #define for clean code
- UK traffic light regulations (RED+AMBER phase)

**UK Traffic Light Sequence:**
1. RED (5 seconds) - stop
2. RED + AMBER together (2 seconds) - prepare to proceed
3. GREEN (6 seconds) - go
4. AMBER (3 seconds) - prepare to stop
5. Repeat

The RED+AMBER phase is unique to UK standards and provides better driver preparation than systems without it.

---

## 🎒 Required Inventory

### Hardware Checklist:
- [ ] Arduino Uno R3
- [ ] 1× Red LED
- [ ] 1× Yellow/Amber LED
- [ ] 1× Green LED
- [ ] 3× Resistors (220Ω or 330Ω)
- [ ] Breadboard
- [ ] 8-10 jumper wires
- [ ] USB cable

### Software:
- [ ] Arduino IDE installed and working
- [ ] Confidence from completing Level 1 ✅

**Don't have 3 LEDs yet?** You can practice with what you have and buy more later!

---

## 🗺️ Quest Map

```
START
  ↓
Build Circuit (3 LEDs)
  ↓
Write Code (UK sequence)
  ↓
Upload and Test
  ↓
Verify Timing
  ↓
VICTORY! 🏆
```

---

## 📝 Step 1: Understand The Sequence

Before building, understand what you're creating:

### UK Traffic Light Sequence:

```
PHASE 1: RED only          [●  ○  ○]  5 seconds  - STOP
PHASE 2: RED + AMBER       [●  ●  ○]  2 seconds  - GET READY
PHASE 3: GREEN only        [○  ○  ●]  6 seconds  - GO
PHASE 4: AMBER only        [○  ●  ○]  3 seconds  - SLOW DOWN
         (back to PHASE 1)
```

**Total cycle time:** 5 + 2 + 6 + 3 = **16 seconds**

**Checkpoint:** Do you understand the sequence? Can you draw it on paper?

---

## 🔧 Step 2: Build The Circuit

### Pin Assignments:
```
Pin 12 → Red LED
Pin 11 → Amber LED
Pin 10 → Green LED
GND → All LED cathodes (short legs)
```

### Building Instructions:

#### Part A: Setup Power Rails
1. Connect Arduino GND to breadboard negative rail (blue/black stripe)
2. Use a black wire for this

#### Part B: Red LED (Pin 12)
1. Insert RED LED into breadboard
   - Long leg in hole E5
   - Short leg in hole E6
2. Add resistor
   - One end in hole F5 (same row as long leg)
   - Other end in hole F8
3. Wire from Pin 12 to hole J8
4. Wire from hole J6 to GND rail

#### Part C: Amber LED (Pin 11)
1. Insert AMBER/YELLOW LED
   - Long leg in hole E10
   - Short leg in hole E11
2. Add resistor
   - One end in hole F10
   - Other end in hole F13
3. Wire from Pin 11 to hole J13
4. Wire from hole J11 to GND rail

#### Part D: Green LED (Pin 10)
1. Insert GREEN LED
   - Long leg in hole E15
   - Short leg in hole E16
2. Add resistor
   - One end in hole F15
   - Other end in hole F18
3. Wire from Pin 10 to hole J18
4. Wire from hole J16 to GND rail

### Circuit Diagram (ASCII Art):
```
Arduino Uno                    Breadboard

Pin 12 ────────[220Ω]────[Red LED]────┐
Pin 11 ────────[220Ω]────[Amber LED]──┼──→ GND Rail → Arduino GND
Pin 10 ────────[220Ω]────[Green LED]──┘
```

**Checkpoint:** All three LEDs in breadboard, resistors connected, wires from Arduino to each LED? ✅

---

## ⌨️ Step 3: Write The Code

**Action:** Create a new Arduino sketch and type this:

```cpp
/*
 * Level 2: The Traffic Light Challenge
 * UK-Standard Traffic Light Sequence
 */

// Pin definitions (makes code easier to read)
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
  // PHASE 1: RED light (STOP!)
  digitalWrite(RED_LED, HIGH);      // Red ON
  digitalWrite(AMBER_LED, LOW);     // Amber OFF
  digitalWrite(GREEN_LED, LOW);     // Green OFF
  delay(5000);                      // Wait 5 seconds

  // PHASE 2: RED + AMBER (Get ready!)
  digitalWrite(RED_LED, HIGH);      // Red stays ON
  digitalWrite(AMBER_LED, HIGH);    // Amber ON
  digitalWrite(GREEN_LED, LOW);     // Green OFF
  delay(2000);                      // Wait 2 seconds

  // PHASE 3: GREEN light (GO!)
  digitalWrite(RED_LED, LOW);       // Red OFF
  digitalWrite(AMBER_LED, LOW);     // Amber OFF
  digitalWrite(GREEN_LED, HIGH);    // Green ON
  delay(6000);                      // Wait 6 seconds

  // PHASE 4: AMBER light (Slow down!)
  digitalWrite(RED_LED, LOW);       // Red OFF
  digitalWrite(AMBER_LED, HIGH);    // Amber ON
  digitalWrite(GREEN_LED, LOW);     // Green OFF
  delay(3000);                      // Wait 3 seconds

  // Loop automatically repeats - back to RED
}
```

### Code Explanation (Level Up Your Knowledge):

**`#define RED_LED 12`** - Creates a nickname. Now you can say "RED_LED" instead of "12". Much easier to read!

**Four phases** - Each phase:
1. Sets the right LEDs on/off
2. Waits the right amount of time
3. Automatically moves to next phase

**The magic:** When `loop()` finishes, it automatically starts again at the top. RED → RED+AMBER → GREEN → AMBER → RED forever!

---

## 📤 Step 4: Upload The Code

1. **File** → **Save** (give it a name like "TrafficLight")
2. **Tools** → **Board** → **Arduino Uno** (should already be set)
3. **Tools** → **Port** → Select your Arduino
4. Click **Upload** button (→)
5. Wait for "Done uploading"

---

## ✨ Step 5: Witness The Traffic Light!

**What Should Happen:**

```
[5 seconds]  RED only             [●  ○  ○]
[2 seconds]  RED + AMBER together [●  ●  ○]
[6 seconds]  GREEN only           [○  ○  ●]
[3 seconds]  AMBER only           [○  ●  ○]
(repeats)
```

**Use a timer** (phone stopwatch) to verify the timing is correct!

---

## ✅ Victory Conditions

### Quest Complete When:
- [x] All three LEDs work
- [x] RED shows for 5 seconds
- [x] RED + AMBER show together for 2 seconds
- [x] GREEN shows for 6 seconds
- [x] AMBER shows for 3 seconds
- [x] Pattern repeats automatically
- [x] Only correct LEDs are on at each phase

**Full Victory:** All checks pass! 🏆

---

## 🐛 Debugging (If Something's Wrong)

### Problem: LEDs flash in wrong order
**Solution:** Check your code phases match the circuit wiring

### Problem: Wrong LED colors at wrong times
**Solution:**
- Verify pin assignments (is RED on pin 12?)
- Check wires go to correct pins

### Problem: Multiple LEDs on when shouldn't be
**Solution:**
- Check all cathodes (short legs) go to GND
- Verify no wires touching that shouldn't

### Problem: Timing feels wrong
**Solution:**
- Use phone stopwatch to measure
- Remember: 1000 milliseconds = 1 second
- 5000ms = 5 seconds, etc.

### Problem: One LED doesn't work
**Solution:**
- Check that LED polarity (long leg to resistor?)
- Try swapping with a different LED (might be broken)
- Check resistor is connected

---

## 🏆 Achievements Unlocked!

- 🚦 **Traffic Master** - "You built a working traffic light"
- 🔄 **Sequence Specialist** - "You created a timed sequence"
- 🎨 **Multi-Output Manager** - "You controlled 3 LEDs simultaneously"
- 🇬🇧 **UK Standard Bearer** - "You implemented UK traffic regulations"
- ⏱️ **Timing Apprentice** - "You mastered delay() timing"

---

## 🎓 What You Learned (Experience Gained)

**New Skills:**
- ✅ Controlling multiple LEDs
- ✅ Creating sequences
- ✅ Using `#define` for readable code
- ✅ Coordinating multiple outputs
- ✅ Building more complex circuits

**New Concepts:**
- ✅ State sequences (Phase 1 → Phase 2 → Phase 3...)
- ✅ UK traffic light standards
- ✅ Code organization with defines
- ✅ Planning before building

---

## 🎮 Side Quests (Bonus Challenges)

### Side Quest 1: Speed It Up ⚡
**Challenge:** Make the whole cycle complete in 8 seconds (half time)
**Hint:** Divide all delays by 2
**Reward:** Understanding of timing scaling

### Side Quest 2: US Traffic Light 🇺🇸
**Challenge:** Convert to US standard (no RED+AMBER phase)
**Hint:** Remove Phase 2, go straight from RED to GREEN
**Reward:** Understanding different standards

### Side Quest 3: Night Mode 🌙
**Challenge:** Make amber flash on/off continuously (night mode)
**Hint:** Just amber blinking, ON 500ms, OFF 500ms
**Reward:** Emergency mode thinking

### Side Quest 4: Serial Monitor 📊
**Challenge:** Add Serial.println() to show which phase is active
**Hint:** Add `Serial.begin(9600)` in setup, `Serial.println("RED")` in each phase
**Reward:** Debugging skills unlocked!

**Code for Side Quest 4:**
```cpp
void setup() {
  Serial.begin(9600);  // Add this
  pinMode(RED_LED, OUTPUT);
  // ... rest of setup
}

void loop() {
  Serial.println("PHASE 1: RED");  // Add to each phase
  digitalWrite(RED_LED, HIGH);
  // ... rest of phase
}
```

---

## 📊 Skills Assessment

**Ready for Level 3?** Answer these:

1. **Can you add a 4th LED on a different pin?**
   - [ ] Yes → +1 point
   - [ ] Not sure → Review code

2. **Do you understand what `#define` does?**
   - [ ] Yes → +1 point
   - [ ] No → It creates nicknames for numbers

3. **Could you change the timing without help?**
   - [ ] Yes → +1 point
   - [ ] No → Try Side Quest 1

4. **Do you understand why we use resistors?**
   - [ ] Yes → +1 point
   - [ ] No → They protect LEDs from too much current

**Score:**
- **4 points:** Ready for Level 3! 🚀
- **2-3 points:** Almost there! Try side quests
- **0-1 points:** Practice more at Level 2, that's okay!

---

## 🗺️ Choose Your Next Adventure

### Option A: Level Up! 🚀
Ready for the ultimate challenge?
**→ [Proceed to Level 3: Pedestrian Crossing Quest](QUEST_LEVEL_3.md)**
- Add a button
- Add 2 more LEDs
- Make it interactive!

### Option B: Jump to Advanced! ⏭️
Skip the button, go straight to theory:
**→ [Advanced: State Machines](QUEST_ADVANCED.md)**
- Your traffic light IS a state machine!
- Learn the theory behind what you built
- Come back to add buttons later

### Option C: Backtrack to Fill Gaps 🔄
Need more practice with basics?
**→ [Return to Level 1](QUEST_LEVEL_1.md)** - Reinforce fundamentals
- Try the side quests you skipped
- Build confidence with simpler circuits

### Option D: Master This Level 🏋️
Stay here and become an expert:
- Complete all side quests
- Try different timing combinations
- Add more LEDs
- Experiment with patterns

### Option E: Learn The Theory 📚
Understand the "why" behind it:
- Read about state machines
- Learn about timing systems
- Study UK traffic regulations
**→ [Read: BEGINNER_BUILD_GUIDE.md Level 2](BEGINNER_BUILD_GUIDE.md#level-2-basic-traffic-light-3-leds)**

### Option F: Custom Path 🗺️
Want to pick specific skills to learn?
**→ [View Quest Matrix](QUEST_MATRIX.md)** - Mix and match tasks!

### Option G: Take a Victory Lap 🎉
You've earned it!
- Take photos of your working traffic light
- Show someone what you built
- Come back tomorrow for Level 3

---

## 💬 NPC Dialogue

> **Town Council Member:** "Excellent work! The traffic light is functioning perfectly. But... we have one more request. The pedestrians need a crossing. Think you can handle it?"

> **LED Shopkeeper:** "You're getting good at this! Next you'll be building robots. Here, you'll need these for the next challenge..." *hands you 2 more LEDs and a button*

> **Arduino Wizard:** "Your skills grow stronger. But true mastery requires more than output. You must learn to listen... to input. The button awaits."

---

## 🎯 Level 2 Complete!

**Outstanding work!** You've built a real traffic light that follows international standards. This is no toy - it's real engineering!

**What you've accomplished:**
- Built a multi-LED circuit
- Written sequential control code
- Implemented real-world standards
- Created timed automation

**You're now ready for the biggest challenge: adding user input!**

---

## 🚀 Ready to Continue?

**Next up:** Add a pedestrian button, 2 more LEDs, and make your traffic light respond to users!

**→ [Continue to Level 3: The Pedestrian Crossing Quest](QUEST_LEVEL_3.md)**

Or return to **[Quest Hub](QUEST_START.md)** to choose a different path.

---

*Quest Progress: ■■□□□ Level 2 Complete!*

**Achievements:** 8 unlocked | **Skills:** +5 | **Confidence:** +100