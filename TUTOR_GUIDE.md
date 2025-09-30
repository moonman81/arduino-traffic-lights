# Guide for Tutors and Teachers

## About this student

Your student has ADHD and dyslexia.

They have built this project themselves using the guides in this repository.

They understand it through doing it, not through reading theory first.

---

## What they built

A working traffic light system with pedestrian crossing.

**It includes:**
- 3 traffic LEDs (red, yellow, green)
- 2 pedestrian LEDs (red, green)
- 1 button for pedestrian crossing
- Code that makes it all work

**It follows UK traffic light standards:**
- Red → Red+Yellow → Green → Yellow → Red
- Button activates pedestrian crossing
- Pedestrian gets green, traffic gets red (safe)
- Minimum 3 seconds green before interruption

---

## The code they should explain

### For GCSE/BTEC Level 2:
**File:** `arduino-code/examples/L3-7b_full_features.ino`

This is the complete working system. All features, well-commented.

**Key concepts they learned:**
- Variables and data types
- If statements
- Functions
- Input/output control
- Timing without blocking

---

## Questions to ask (that won't overwhelm them)

### Easy questions:
1. "Show me the code running - press the button"
2. "What happens when you press the button?"
3. "Which pin is the red light connected to?"
4. "Show me the line of code that turns the red light on"

### Medium questions:
5. "What does `digitalWrite(RED_LED, HIGH)` do?"
6. "Why do we need to check `timeInState >= GREEN_MIN_TIME`?"
7. "What's the difference between `delay()` and `millis()`?"

### Harder questions (only if they're confident):
8. "How does the code remember that a pedestrian pressed the button?"
9. "What stops the pedestrian light and traffic light both being green?"
10. "Could you add a second button? How would you do it?"

---

## What to look for

### They understand it if they can:
- ✅ Point to the code that controls each LED
- ✅ Explain what HIGH and LOW mean
- ✅ Explain why there's a minimum green time
- ✅ Show you the button reading code
- ✅ Describe what a state is (RED, GREEN, etc)

### They really understand it if they can:
- ✅ Explain why millis() is better than delay()
- ✅ Describe the boolean flag (`pedestrianRequested`)
- ✅ Trace through a state change step-by-step
- ✅ Suggest a modification and explain how to code it

---

## Qualification mapping

### GCSE Computer Science (9-1)
**Covered:**
- 2.1: Algorithms (sequencing, state machines)
- 2.3: Programming techniques (variables, loops, boolean logic)
- 2.6: Data types (integers, boolean)

### BTEC Level 2 Engineering (Unit 4)
**Covered:**
- Microcontroller systems
- Input/output devices
- Program design
- Testing and debugging

### BTEC Level 3 IT (Unit 6)
**Covered:**
- Microcontroller architecture
- C programming
- Input/output interfacing
- Timing and interrupts

### A-Level Computer Science
**Covered:**
- State machines (FSM/FSA)
- Boolean logic
- Problem solving
- NEA project evidence

**See `UK_CURRICULUM_MAPPING.md` for detailed unit-by-unit breakdown.**

---

## Assessment evidence

### Portfolio evidence this provides:

**Design:**
- Circuit diagrams (see `documentation/WIRING_INSTRUCTIONS.md`)
- State diagrams (see `documentation/TRAFFIC_LIGHT_FSA_ANALYSIS.md`)

**Implementation:**
- Working code with comments
- Testing evidence (can demonstrate live)
- Video/photo evidence of working system

**Evaluation:**
- Code comparison between levels (shows progression)
- Understanding of safety requirements
- Extension work (side quests completed)

---

## Common misconceptions to check

### ❌ They might think:
"delay() is the only way to wait"

### ✅ Correct understanding:
"delay() blocks everything. millis() lets the button work while timing."

---

### ❌ They might think:
"The code runs top to bottom once"

### ✅ Correct understanding:
"setup() runs once, then loop() repeats forever"

---

### ❌ They might think:
"HIGH and LOW are just words"

### ✅ Correct understanding:
"HIGH = 5 volts (LED on), LOW = 0 volts (LED off)"

---

## If they struggle to explain

This is normal with ADHD/dyslexia.

**Instead of:**
"Explain how your code works"

**Try:**
"Show me what this line does" (point to specific line)

**Or:**
"Change this number - what happens?"

**Or:**
"Show me the code working, then show me which line controls that"

Demonstration of understanding is as valid as verbal explanation.

---

## Adaptations for neurodivergent students

### This project is accessible because:
- ✅ Short, focused tasks (not one huge project)
- ✅ Immediate visual feedback (LED lights up = success)
- ✅ Multiple entry points (can start at any level)
- ✅ Clear success criteria (LED blinks = you did it)
- ✅ Troubleshooting guide for when stuck
- ✅ No shame in using examples (encouraged)

### The documentation includes:
- Short paragraphs
- Visual breaks between sections
- Step-by-step numbered instructions
- Pictures and diagrams where needed
- Confidence-building language
- Multiple routes to same goal

---

## Extensions and challenges

If they want to go further:

### Easy extensions:
- Change the timing (longer green time)
- Add a third pedestrian button
- Add a buzzer sound for pedestrian crossing
- Make LEDs flash during certain states

### Medium extensions:
- Add night mode (flashing yellow)
- Add traffic counter using Serial Monitor
- Make pedestrian light countdown
- Add emergency vehicle override button

### Hard extensions:
- Two-way crossing (traffic both directions)
- Synchronize multiple traffic lights
- Add interrupt-based button (ADV-2)
- Implement full state machine formal notation (ADV-1)

**See individual quest files for specific "side quests"**

---

## Suggested grading approach

### Pass standard:
- Working system (all LEDs, button works)
- Can point to code sections
- Can explain what input/output means
- Circuit correctly wired

### Merit standard:
- Can explain boolean logic
- Understands state concept
- Can describe timing strategy
- Completed at least one extension

### Distinction standard:
- Can explain millis() vs delay()
- Understands safety requirements
- Can propose modifications
- Completed multiple extensions or advanced work

---

## Further resources in this repo

- **BEGINNER_BUILD_GUIDE.md** - Full tutorial they followed
- **QUEST_LEVEL_3.md** - The main project guide
- **TROUBLESHOOTING.md** - Problems they solved
- **UK_CURRICULUM_MAPPING.md** - Detailed qualification mapping
- **CODE_EXAMPLES_INDEX.md** - All 27 code examples

---

## Questions?

This project covers substantial ground from basic Arduino through to formal verification and safety-critical systems.

Your student has built the working system. The deep theory is available if needed (QUEST_ADVANCED.md, QUEST_EXPERT.md) but is not required for GCSE/BTEC assessment.

The important thing: **they built something real that works**.