# Level 1: Single LED Blink

## Overview

**Difficulty:** Beginner
**Time:** 10-15 minutes
**Prerequisites:** None

**Goal:** Make a single LED blink on and off every second

**What you'll learn:**
- How to connect an LED to Arduino
- Basic Arduino programming (pinMode, digitalWrite, delay)
- The concept of HIGH/LOW voltage states

This is the foundation for all Arduino projects. Every complex system starts with controlling a single output.

---

## 🎒 Required Inventory

### Minimum (Hardware):
- [ ] 1× Arduino Uno R3
- [ ] 1× LED (any color, but red is traditional)
- [ ] 1× Resistor (220Ω or 330Ω)
- [ ] 2× Jumper wires
- [ ] 1× Breadboard (optional but recommended)
- [ ] 1× USB cable
- [ ] 1× Computer

### Minimum (Software):
- [ ] Arduino IDE installed (free from arduino.cc)

**Don't have hardware?** → Try **Tinkercad Circuits** (tinkercad.com/circuits) instead - free online simulator!

---

## 🗺️ Quest Steps

### Step 1: Set Up Your Workspace ⚙️

**Action:** Prepare your area
- Clear space on desk
- Have Arduino, breadboard, and components ready
- USB cable connected from Arduino to computer
- Arduino IDE open on computer

**Check:** Small LED on Arduino board lights up when plugged in → ✅

---

### Step 2: Build The Circuit 🔧

**The Spell (Circuit):**
```
Arduino Pin 13 → Resistor → LED (long leg) → LED (short leg) → Arduino GND
```

**Detailed Instructions:**

1. **Identify LED legs:**
   - LONG leg = Positive (anode) ✅
   - SHORT leg = Negative (cathode) ❌
   - If you can't tell, look for flat edge on LED plastic = negative side

2. **Place LED in breadboard:**
   - Long leg in hole E10
   - Short leg in hole E11

3. **Add resistor:**
   - One end in hole F10 (same row as LED long leg)
   - Other end in hole F15 (different row)

4. **Wire to Arduino Pin 13:**
   - Jumper wire from Arduino Pin 13 to hole J15 (where resistor is)

5. **Wire to Arduino GND:**
   - Jumper wire from Arduino GND to hole J11 (where LED short leg is)

**Visual Check:**
```
Arduino         Breadboard
Pin 13 -------- Row 15 [Resistor] Row 10 [LED long leg]
                                  Row 11 [LED short leg] -------- GND
```

**Checkpoint:** Circuit is built but LED is not lit yet (that's correct!)

---

### Step 3: Write The Spell (Code) ⌨️

**Action:** Open Arduino IDE and type this EXACTLY:

```cpp
// Level 1: The First Light
// This is your first spell!

void setup() {
  pinMode(13, OUTPUT);  // Pin 13 will control the LED
}

void loop() {
  digitalWrite(13, HIGH);  // Turn LED ON
  delay(1000);             // Wait 1 second (1000 milliseconds)

  digitalWrite(13, LOW);   // Turn LED OFF
  delay(1000);             // Wait 1 second

  // Loop automatically repeats!
}
```

**Spell Translation (What Each Line Means):**
- `void setup()` → Runs once when Arduino starts
- `pinMode(13, OUTPUT)` → "Pin 13 will control something"
- `void loop()` → Runs forever, repeating
- `digitalWrite(13, HIGH)` → "Send power to pin 13" (LED turns on)
- `delay(1000)` → "Wait 1000 milliseconds" (1 second)
- `digitalWrite(13, LOW)` → "Stop power to pin 13" (LED turns off)

---

### Step 4: Upload The Spell 📤

**Action:** Send code to Arduino

1. Click **Tools** → **Board** → **Arduino Uno**
2. Click **Tools** → **Port** → Select the port with your Arduino
   - Usually looks like `/dev/cu.usbserial` (Mac) or `COM3` (Windows)
3. Click the **Upload** button (→ arrow icon at top)
4. Wait for "Done uploading" message

**Common Error:** "Port not found"
- **Fix:** Check USB cable is connected
- **Fix:** Try a different USB cable (some are power-only!)
- **Fix:** Try different USB port on computer

---

### Step 5: Witness The Magic! ✨

**What Should Happen:**
- LED blinks ON
- Waits 1 second
- LED blinks OFF
- Waits 1 second
- Repeats forever!

**Victory Condition:** LED blinks steadily on and off

---

## ✅ Victory Checkpoints

### Victory Achieved When:
- [x] LED turns on
- [x] LED turns off
- [x] Pattern repeats automatically
- [x] Timing is consistent (about 1 second each)

**If LED doesn't light at all:**
1. Check LED polarity (long leg to resistor side?)
2. Check wires are firmly inserted
3. Try pressing Arduino reset button

**If LED stays on all the time:**
1. Check your code matches exactly
2. Look for missing semicolons (;)
3. Re-upload the code

**If LED is very dim:**
1. That might be normal! Still counts as victory
2. Resistor might be higher value than needed (still safe)

---

## 🏆 Achievements Unlocked!

Completing Level 1 unlocks:

- 🔥 **First Light** - "You brought light to the darkness"
- 🎯 **Circuit Apprentice** - "You built your first circuit"
- ⚡ **Code Initiate** - "You wrote your first Arduino program"
- 🔌 **Connection Master** - "Arduino and computer work together"

---

## 🎓 What You Learned (Experience Points)

**Hardware Skills:**
- ✅ LED polarity (long leg = positive)
- ✅ Resistor purpose (protects LED from burning out)
- ✅ Breadboard usage
- ✅ Arduino pin connections

**Software Skills:**
- ✅ `setup()` function (runs once)
- ✅ `loop()` function (runs forever)
- ✅ `pinMode()` - setting pin mode
- ✅ `digitalWrite()` - turning pins ON/OFF
- ✅ `delay()` - waiting/timing

**Concepts:**
- ✅ HIGH = ON = 5 volts
- ✅ LOW = OFF = 0 volts
- ✅ 1000 milliseconds = 1 second
- ✅ Programs run in sequence

---

## 🎮 Side Quests (Optional Challenges)

Try these modifications to earn bonus experience:

### Side Quest 1: Speed Control ⚡
**Challenge:** Make it blink faster
**Hint:** Change `delay(1000)` to `delay(500)` (half second)
**Reward:** Understanding of timing

### Side Quest 2: Morse Code 📡
**Challenge:** Blink "SOS" in Morse code (···−−−···)
**Hint:** Short blink = 200ms, long blink = 600ms
**Reward:** Pattern recognition skill

### Side Quest 3: Different Pin 🔌
**Challenge:** Make it work on Pin 12 instead of Pin 13
**Hint:** Change all `13` to `12` in code (and move wire!)
**Reward:** Understanding pin flexibility

### Side Quest 4: Heartbeat 💓
**Challenge:** Make it "pulse" like a heartbeat (two quick blinks, pause)
**Hint:** ON-OFF-ON-OFF-long pause
**Reward:** Creative thinking skill

---

## 📊 Progress Report

**Level 1 Status:** COMPLETE ✅

**Skills Acquired:**
- Basic circuit building
- LED control
- Arduino programming fundamentals
- Upload process

**Ready for Next Level?** Check your skills:
- [ ] Can you change the blink speed?
- [ ] Do you understand why the resistor is needed?
- [ ] Could you add a second LED on a different pin?

**If you answered YES to 2 or more → You're ready for Level 2!**

---

## 🗺️ Choose Your Next Adventure

### Option A: Level Up! 🚀
You're ready for the next challenge!
**→ [Proceed to Level 2: Traffic Light Challenge](QUEST_LEVEL_2.md)**

### Option B: Jump Ahead! ⏭️
Feel confident? Skip ahead!
- **→ [Jump to Level 3: Pedestrian System](QUEST_LEVEL_3.md)** - Full project
- **→ [Jump to Advanced: Theory](QUEST_ADVANCED.md)** - State machines
- Come back to Level 2 if you need specific skills

### Option C: Consolidate Your Skills 🛠️
Practice more at this level:
- Try all the side quests
- Experiment with different delays
- Try different colored LEDs
- Read the theory: `BEGINNER_BUILD_GUIDE.md` Level 1 section

### Option D: Learn The Theory 📚
Understand WHY it works:
- Read about Ohm's Law (resistor calculations)
- Learn about LED specifications
- Understand Arduino pins in detail
- **→ [Visit The Library](BEGINNER_BUILD_GUIDE.md)**

### Option E: Custom Path 🗺️
Want to mix and match tasks from different levels?
**→ [View Quest Matrix](QUEST_MATRIX.md)** - All possible paths!

### Option F: Take a Break ☕
That's okay! You've achieved something real today.
- Save your circuit (take a photo!)
- Come back tomorrow for Level 2
- Your progress is saved!

---

## 💬 NPC Dialogue (Words of Encouragement)

> **Arduino Wizard:** "Impressive! The light responds to your commands. You have the gift. Are you ready for a greater challenge? The Traffic Light awaits..."

> **LED Shopkeeper:** "You've mastered the basics! Many heroes stop here, but I sense you'll go further. Good luck on your journey!"

> **Debugging Oracle:** "Remember this moment. Every complex project starts with this simple blink. When things get hard later, come back to this. Simplicity is power."

---

## 🆘 Got Stuck? Respawn Points:

**Problem:** LED doesn't light at all
**→ [Troubleshooting Guide](BEGINNER_BUILD_GUIDE.md#troubleshooting)**

**Problem:** Upload error
**→ Check board and port settings in Tools menu**

**Problem:** LED very dim
**→ That's okay! Still working. Resistor might be higher value.**

**Problem:** Code won't compile
**→ Check for typos, missing semicolons, matching brackets**

**Need more help?**
**→ [Return to Quest Hub](QUEST_START.md)**
**→ [Full Tutorial](BEGINNER_BUILD_GUIDE.md)**

---

## 🎯 Level 1 Complete!

**Congratulations, brave builder!** You've taken your first step into the world of Arduino. The LED blinks because YOU made it happen. That's real magic.

**Ready to level up?**

**→ [Continue to Level 2: The Traffic Light Challenge](QUEST_LEVEL_2.md)**

Or return to **[Quest Hub](QUEST_START.md)** to choose a different path.

---

*Quest Progress: ■□□□□ Level 1 Complete!*