# Level 3: Complete Pedestrian Crossing

## Overview

**Difficulty:** Advanced
**Time:** 2-3 hours
**Prerequisites:** Level 2 complete, or comfortable with Arduino basics

**Goal:** Build a complete UK-standard traffic light with button-activated pedestrian crossing

**What you'll learn:**
- Button input processing
- Non-blocking timing with millis()
- State machine implementation
- Request queuing
- Safety considerations (minimum green time)
- Serial debugging

This is a complete embedded system with multiple inputs, outputs, timing requirements, and safety rules.

---

## Hardware Requirements

### Complete Component List:
- [ ] Arduino Uno R3
- [ ] 5× LEDs:
  - 1× Red (traffic)
  - 1× Yellow/Amber (traffic)
  - 1× Green (traffic)
  - 1× Red (pedestrian)
  - 1× Green (pedestrian)
- [ ] 5× 330Ω resistors
- [ ] 1× Push button (momentary)
- [ ] Breadboard
- [ ] Jumper wires (15-20)
- [ ] USB cable

**Don't have all components yet?** You can practice with fewer LEDs using the earlier level examples.

---

## Recommended Code

**Primary recommendation:** Use `arduino-code/traffic-light-level3-pedestrian-simple.ino`

This version includes:
- Full functionality
- Extensive comments
- Serial debugging
- All safety features
- Designed specifically for learning

**Alternative:** See `arduino-code/examples/L3-7_complete_pedestrian.ino` for a similar implementation

**Advanced:** After completing this, explore `arduino-code/traffic-lights-arduino-clean.c` for professional structure

---

## What You'll Build

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