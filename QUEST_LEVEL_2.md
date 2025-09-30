# Level 2: Make Traffic Lights Work

## What you'll build

3 LEDs working like real UK traffic lights.

**Time:** 45 minutes to 1 hour

**You need:**
- Did Level 1? You're ready.
- Never did Level 1? That's okay, start here anyway.

---

## UK traffic lights pattern

Real UK traffic lights do this:

1. **RED** (5 seconds) - Stop
2. **RED + YELLOW** together (2 seconds) - Get ready
3. **GREEN** (6 seconds) - Go
4. **YELLOW** (3 seconds) - Stop coming
5. Back to step 1

**The red + yellow together is special to UK.** Other countries don't do this.

Total time for one cycle: 16 seconds

---

## What you need

**Check you have these:**

□ Arduino Uno
□ 3× LEDs (red, yellow, green)
□ 3× Resistors
□ Wires
□ Breadboard
□ USB cable

**Don't have 3 LEDs?** You can use 3 of any colour to practice. The pattern matters more than the colours.

---

## The steps

### Step 1: Connect the wires

You're connecting 3 LEDs this time instead of 1.

**For each LED:**
1. Long leg → resistor → Arduino pin
2. Short leg → Arduino GND

**Which pins:**
- Red LED → Pin 12
- Yellow LED → Pin 11
- Green LED → Pin 10

**Check:** All 3 LEDs in breadboard, all connected, none lit yet (that's right!)

---

### Step 2: Copy this code

```cpp
#define RED    12
#define YELLOW 11
#define GREEN  10

void setup() {
  pinMode(RED, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(GREEN, OUTPUT);
}

void loop() {
  // RED
  digitalWrite(RED, HIGH);
  digitalWrite(YELLOW, LOW);
  digitalWrite(GREEN, LOW);
  delay(5000);

  // RED + YELLOW
  digitalWrite(RED, HIGH);
  digitalWrite(YELLOW, HIGH);
  digitalWrite(GREEN, LOW);
  delay(2000);

  // GREEN
  digitalWrite(RED, LOW);
  digitalWrite(YELLOW, LOW);
  digitalWrite(GREEN, HIGH);
  delay(6000);

  // YELLOW
  digitalWrite(RED, LOW);
  digitalWrite(YELLOW, HIGH);
  digitalWrite(GREEN, LOW);
  delay(3000);
}
```

**What #define does:** Lets you write `RED` instead of `12`. Makes code easier to read.

---

### Step 3: Upload it

1. Click **Tools** → **Board** → **Arduino Uno**
2. Click **Tools** → **Port** → Pick your Arduino
3. Click **Upload** (→ arrow)
4. Wait for "Done uploading"

---

### Step 4: Watch it work

**What should happen:**

1. **RED** lights up (5 seconds)
2. **RED + YELLOW** both on (2 seconds)
3. **GREEN** lights up (6 seconds)
4. **YELLOW** lights up (3 seconds)
5. Back to step 1, repeats forever

**Use a timer** (your phone) to check the timing is right.

---

## ✅ Success!

**Your traffic lights working?** You did it!

**This is the real UK pattern.** Same as actual traffic lights on roads.

---

## Something wrong?

### Only one LED works:
- Check the other LEDs are wired to the right pins
- Check each LED's long leg goes toward the pin
- Check each LED's short leg goes to GND

### Wrong pattern:
- Check your code matches the example exactly
- Count the commas and semicolons
- Upload the code again

### Timing wrong:
- Check the `delay()` numbers
- 5000 = 5 seconds, 2000 = 2 seconds, etc

---

## What you learned

You now know:
- How to control multiple LEDs
- How to make patterns with timing
- What `#define` does (makes code readable)
- UK traffic light sequence

**This is real embedded systems programming.**

---

## What next?

### Ready for the full project?
**→ [Level 3: Add Button](QUEST_LEVEL_3.md)**

This adds the pedestrian crossing button.

---

### Want more practice first?
**Try these:**
- Make the green time longer (change 6000 to 8000)
- Make it cycle faster (half all the numbers)
- Add a 4th LED that blinks during green
- Use different coloured LEDs

---

## You should feel good

**You just:**
- Controlled 3 LEDs at once
- Created a timed sequence
- Made real UK traffic light pattern

This is the same logic that real traffic lights use.

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