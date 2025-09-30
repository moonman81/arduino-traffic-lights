# Level 3: Add Pedestrian Button

## What you'll build

Complete traffic light with pedestrian crossing.

**Press button → Pedestrian gets green light → Cars stop**

**Time:** 2-3 hours (take breaks!)

**You need:**
- Did Level 2? You're ready.
- Never did Level 2? Do that first, it's easier.

---

## What you need

**Check you have:**

□ Everything from Level 2 (3 traffic LEDs)
□ 2 more LEDs (for pedestrian lights)
□ 2 more resistors
□ 1 button
□ More wires

**Total: 5 LEDs + 1 button**

---

## The idea

**Normal traffic lights:**
- Red → Red+Yellow → Green → Yellow → repeat

**With button pressed:**
- Normal cycle continues
- THEN when it gets to Yellow
- Goes to Pedestrian Green instead of Red
- Pedestrian gets 8 seconds to cross
- Then back to Red for traffic

**Important:** Pedestrian has to wait for safe time. Can't interrupt immediately.

---

## Which code to use

**Use this file:** `L3-7b_full_features.ino`

Find it in: `arduino-code/examples/`

**Why this one?** It has everything and is well explained.

---

## The steps

### Step 1: Add the 2 pedestrian LEDs

Same as Level 2, but 2 more LEDs:

**Pedestrian LEDs:**
- Red pedestrian → Pin 9
- Green pedestrian → Pin 8

Same wiring: Long leg → resistor → pin, Short leg → GND

**Check:** Now you have 5 LEDs total, none lit yet.

---

### Step 2: Add the button

**Button wiring:**
- One side → Pin 2
- Other side → GND

**That's it.** Buttons are simple.

**Check:** Button is wired, you can press it (does nothing yet, that's right).

---

### Step 3: Copy the code

Open file: `arduino-code/examples/L3-7b_full_features.ino`

Copy ALL of it into Arduino IDE.

**Don't type it.** Copy and paste. It's long (200 lines).

**Check:** Code is in Arduino IDE.

---

### Step 4: Upload it

1. **Tools** → **Board** → **Arduino Uno**
2. **Tools** → **Port** → Pick your Arduino
3. Click **Upload** (→ arrow)
4. Wait for "Done uploading"

---

### Step 5: Open Serial Monitor

**Tools** → **Serial Monitor**

Check bottom right says **9600 baud**

You should see messages like:
```
State: RED
State: RED+YELLOW
State: GREEN
```

This shows what's happening.

---

### Step 6: Test the button

**Watch the Serial Monitor.**

1. Wait for "State: GREEN"
2. Press the button
3. You should see ">>> Button pressed! Pedestrian waiting..."
4. Wait - it won't happen immediately
5. After traffic goes to Yellow
6. Then "State: PEDESTRIAN CROSSING"
7. Pedestrian green LED lights up!

**Check:** Button works, pedestrian gets green light.

---

## ✅ Success!

**It's working?** You built a complete embedded system!

**This is coursework-level work.** GCSE, BTEC, A-Level suitable.

---

## Something wrong?

### Button does nothing:
- Check button wired to Pin 2 and GND
- Check Serial Monitor shows button press
- Try a different button

### Pedestrian never gets green:
- Did you wait for the traffic cycle to finish?
- Check Serial Monitor messages
- Pedestrian has to wait for safe time (3 seconds minimum green)

### Serial Monitor shows gibberish:
- Check baud rate is 9600 (bottom right)

### LEDs in wrong pattern:
- Check pin numbers in wiring match code
- Pin 12=Red traffic, 11=Yellow, 10=Green, 9=Red ped, 8=Green ped

---

## What you learned

You now know:
- How to read a button
- How `millis()` works (timing without blocking)
- What a state machine is (RED, GREEN, PED_CROSSING states)
- How to queue a request (button press remembered)
- Safety timing (minimum green before interruption)

**This is professional embedded systems work.**

---

## What next?

### Show your tutor:
Read [TUTOR_GUIDE.md](TUTOR_GUIDE.md) first - it tells them what to look for.

### Want to understand it deeper?
**→ [Advanced Guide](QUEST_ADVANCED.md)** - Theory and state machines

### Want to improve it?
**Try these:**
- Add a countdown timer
- Add a buzzer for pedestrian crossing
- Make pedestrian light flash at end
- Add a second button

---

## You should feel proud

**You just:**
- Built a complete traffic control system
- Wrote 200+ lines of working code
- Handled multiple inputs and outputs
- Implemented safety rules
- Created a real embedded system

This is the same type of system that controls actual traffic lights.

**Many people never get this far. You did it.**

### System Features:
1. **Normal traffic cycle:**
   - RED (5s) → RED+AMBER (2s) → GREEN (6s) → AMBER (3s) → repeat

2. **Pedestrian crossing:**
   - Button press during green triggers crossing
   - Respects minimum 3-second green time for traffic
   - Provides 8 seconds for pedestrians to cross
   - Queues requests if button pressed during other phases

3. **Safety features:**
   - Traffic green and pedestrian green never on together
   - Always transitions through amber before red
   - Minimum time guarantees

---

## Step-by-Step Instructions

Complete wiring and setup instructions are in:
- **[BEGINNER_BUILD_GUIDE.md Level 3](BEGINNER_BUILD_GUIDE.md#level-3-pedestrian-crossing-full-system)**
- **[WIRING_INSTRUCTIONS.md](documentation/WIRING_INSTRUCTIONS.md)**

**Quick summary:**
1. Build traffic light circuit (3 LEDs, pins 12-10)
2. Add pedestrian LEDs (2 LEDs, pins 9-8)
3. Add button (pin 13 to GND)
4. Upload code
5. Test with Serial Monitor

---

## Testing Your System

### Test Checklist:

**Normal operation (no button):**
- [ ] RED for 5 seconds
- [ ] RED+AMBER for 2 seconds
- [ ] GREEN for 6 seconds
- [ ] AMBER for 3 seconds
- [ ] Cycle repeats

**Button during green (after 3 seconds):**
- [ ] Button press recognized
- [ ] Green cuts short, goes to amber
- [ ] Then red traffic + green pedestrian
- [ ] Pedestrian phase lasts 8 seconds
- [ ] Returns to normal cycle

**Button during other phases:**
- [ ] Request is queued
- [ ] Activates after next amber
- [ ] Pedestrian gets crossing phase

**Serial Monitor:**
- [ ] State changes displayed
- [ ] Button presses logged
- [ ] Timing information visible

---

## Common Issues

### Button doesn't work
- Check wiring: one side to pin 13, other to GND
- Check code uses INPUT_PULLUP
- Try printing button state to Serial

### Lights don't follow sequence
- Check pin assignments match code
- Verify all cathodes (short legs) go to GND
- Check for loose wires

### Timing seems wrong
- Use phone stopwatch to measure
- Remember: 1000ms = 1 second
- Check code delay/timing values

### Pedestrian never gets green
- Check pedestrianRequested flag is being set
- Check minimum green time has elapsed
- Verify state machine logic

---

## Understanding the Code

### Key Concepts:

**millis() instead of delay():**
```cpp
unsigned long stateStartTime = millis();
// Later...
if (millis() - stateStartTime >= DURATION) {
  // Change state
}
```
This allows the program to keep checking the button while timing.

**State machine:**
Different states (RED, GREEN, etc.) with transitions between them.

**Request queuing:**
Button press sets a flag; system handles it at the appropriate time.

**Safety checks:**
Code ensures traffic and pedestrian greens never on together.

---

## Next Steps

### Option A: Understand the Theory
**→ [Read FSA Analysis](documentation/TRAFFIC_LIGHT_FSA_ANALYSIS.md)**
- Formal state machine description
- Mathematical verification
- Temporal logic properties

### Option B: Professional Code Structure
**→ [Study Advanced Code](arduino-code/traffic-lights-arduino-clean.c)**
- Functions for organization
- Safety verification functions
- Professional documentation

### Option C: Deep Dive
**→ [Complete Ontological Analysis](documentation/ONTOLOGICAL_ANALYSIS_TRAFFIC_SYSTEM.md)**
- Philosophical foundations
- Formal proofs
- Requirements engineering

### Option D: Custom Learning Path
**→ [View Quest Matrix](QUEST_MATRIX.md)**
- Mix and match tasks
- Fill specific knowledge gaps
- Create your own route

---

## You've Completed the Main Quest!

You've built a complete embedded system with:
- Multiple inputs and outputs
- Complex timing requirements
- State machine implementation
- Safety considerations
- Real-world applicability

**Skills gained:**
- Hardware interfacing
- Non-blocking programming
- State management
- Input processing
- Debugging techniques

This is the foundation for any embedded systems work - robots, home automation, industrial control, automotive systems, and more.

---

**→ [Return to Quest Hub](QUEST_START.md)**

**→ [View All Code Examples](arduino-code/CODE_EXAMPLES_INDEX.md)**

**→ [Explore Advanced Topics](QUEST_MATRIX.md)**