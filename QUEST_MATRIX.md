# Quest Matrix - Learning Paths

## Purpose

This document maps all possible learning routes through the project. Use it to:
- Plan a custom learning path
- Find prerequisites for specific tasks
- Understand task dependencies
- Skip around based on your interests
- Backtrack when you need to fill knowledge gaps

**You don't need to follow a linear path.** Tasks are designed to be independent where possible, allowing you to learn in the order that makes sense for you.

---

## 🎯 The Complete Quest Matrix

```
                            [QUEST START]
                                 |
        ┌────────────────────────┼────────────────────────┐
        |                        |                        |
   [NO HARDWARE]            [HARDWARE]              [THEORY FIRST]
        |                        |                        |
   Tinkercad Path          Physical Path            Academic Path
        |                        |                        |
        └────────────────────────┼────────────────────────┘
                                 |
              ┌──────────────────┼──────────────────┐
              |                  |                  |
         [LEVEL 1]          [LEVEL 2]          [LEVEL 3]
         Single LED       Traffic Light    Pedestrian System
         ⭐☆☆☆☆            ⭐⭐☆☆☆           ⭐⭐⭐☆☆
              |                  |                  |
              |    ┌─────────────┼─────────────┐    |
              |    |             |             |    |
        [Side Quests]      [Side Quests] [Side Quests]
        Speed Control      Serial Debug   State Analysis
        Morse Code         US Standard    Button Debounce
        Different Pin      Night Mode     Multiple Buttons
              |                  |                  |
              └──────────────────┼──────────────────┘
                                 |
                    ┌────────────┼────────────┐
                    |            |            |
              [ADVANCED]     [EXPERT]    [MASTERY]
              Clean Code    Ontology    Your Own Project
              ⭐⭐⭐⭐☆       ⭐⭐⭐⭐⭐    ∞
                    |            |            |
                    └────────────┴────────────┘
                                 |
                           [QUEST COMPLETE]
```

---

## 📊 Task Decomposition Matrix

Every quest level is broken into **independent tasks**. You can complete tasks in ANY order or combine tasks from different levels.

### Level 1 Tasks (Foundational)

| Task ID | Task Name | Skills Required | Unlocks | Can Start From |
|---------|-----------|----------------|---------|----------------|
| **L1.1** | Connect Arduino to Computer | None | L1.2 | Anywhere |
| **L1.2** | Upload Test Code | L1.1 | L1.3 | Anywhere |
| **L1.3** | Build Single LED Circuit | None | L1.4 | Anywhere |
| **L1.4** | Make LED Blink | L1.2, L1.3 | L2.1, L3.1 | Anywhere |
| **L1.5** | Change Blink Speed | L1.4 | L2.2 | L1.4 |
| **L1.6** | Understand digitalWrite | L1.4 | All levels | L1.4 |

### Level 2 Tasks (Building Up)

| Task ID | Task Name | Skills Required | Unlocks | Can Start From |
|---------|-----------|----------------|---------|----------------|
| **L2.1** | Add Second LED | L1.4 | L2.2 | L1.4 |
| **L2.2** | Add Third LED | L2.1 | L2.3 | L1.4 |
| **L2.3** | Create Sequence | L2.2 | L2.4 | L1.5 |
| **L2.4** | Implement UK Standard | L2.3 | L3.1, ADV.1 | L2.3 |
| **L2.5** | Use #define | L1.4 | ADV.2 | L1.4 |
| **L2.6** | Verify Timing | L2.4 | ADV.3 | L2.3 |

### Level 3 Tasks (Integration)

| Task ID | Task Name | Skills Required | Unlocks | Can Start From | Code Example |
|---------|-----------|----------------|---------|----------------|--------------|
| **L3.1** | Add Button Circuit | L1.3 | L3.2 | L1.3 | L3-1_button_test.ino |
| **L3.2** | Read Button Input | L3.1, L1.6 | L3.4a | L3.1 | L3-2_button_read.ino |
| **L3.3** | Add Pedestrian LEDs | L2.2 | L3.4 | L2.1 | L3-3_pedestrian_leds.ino |
| **L3.4a** | Button Request Queuing ⭐ NEW | L3.2 | L3.4 | L3.2 | L3-4a_button_basics.ino |
| **L3.4** | Implement Button Logic | L3.4a, L2.4 | L3.5a | L3.4a | L3-4_button_integration.ino |
| **L3.5a** | Introduction to millis() ⭐ NEW | L2.6 | L3.5 | L2.3 | L3-5a_millis_intro.ino |
| **L3.5** | Use millis() for Timing | L3.5a | L3.7a | L3.5a | L3-5_millis_timing.ino |
| **L3.6** | Add Serial Debug | L1.2 | ADV.4 | L1.2 | L3-6_serial_debug.ino |
| **L3.7a** | Basic Pedestrian Integration ⭐ NEW | L3.4a, L3.5a | L3.7b | L3.5a | L3-7a_basic_integration.ino |
| **L3.7b** | Complete Pedestrian System ⭐ NEW | L3.7a, L3.3 | ADV.1 | L3.7a | L3-7b_full_features.ino |
| **L3.7** | Full System (Original) | L3.4, L3.5 | ADV.5 | L3.4 | L3-7_complete_pedestrian.ino |

### Advanced Tasks (Professional)

| Task ID | Task Name | Skills Required | Unlocks | Can Start From | Code Example |
|---------|-----------|----------------|---------|----------------|--------------|
| **ADV.1** | State Machines (Theory) | L3.7b | ADV.2 | L2.4 | ADV-1_state_machine.ino |
| **ADV.1-P** | State Machines (Practical) ⭐ NEW | L3.7b | ADV.2 | L2.4 | ADV-1-practical_state_machine.ino |
| **ADV.2** | Refactor with Functions | L2.5 | ADV.3 | L2.3 | ADV-2_interrupts.ino |
| **ADV.3** | Implement Safety Checks | L3.7b | ADV.4 | L3.4 | ADV-3_safety_verification.ino |
| **ADV.4** | Add Verification Functions | L3.6, ADV.3 | EXP.1 | L3.6 | (See QUEST_ADVANCED.md) |
| **ADV.5** | Professional Documentation | ADV.2 | EXP.2 | L3.6 | (See QUEST_ADVANCED.md) |

### Expert Tasks (Mastery)

| Task ID | Task Name | Skills Required | Unlocks | Can Start From |
|---------|-----------|----------------|---------|----------------|
| **EXP.1** | Study FSA Theory | ADV.1 | EXP.3 | Anywhere |
| **EXP.2** | Ontological Analysis | ADV.5 | EXP.4 | Anywhere |
| **EXP.3** | Formal Verification | EXP.1, ADV.4 | MASTER | EXP.1 |
| **EXP.4** | Philosophical Foundations | EXP.2 | MASTER | Anywhere |

---

## 🛤️ Example Learning Paths

### Path A: Complete Beginner → Advanced (RECOMMENDED)
**"I've never done this before but want to master it"**

```
L1.1 → L1.2 → L1.3 → L1.4 → L1.5 → L1.6
  ↓
L2.1 → L2.2 → L2.3 → L2.4 → L2.5 → L2.6
  ↓
L3.1 → L3.2 → L3.4a → L3.5a → L3.3 → L3.7a → L3.7b
  ↓
ADV.1-P → ADV.2 → ADV.3 → ADV.4 → ADV.5
  ↓
EXP.1 → EXP.2 → EXP.3 → EXP.4
```
**Estimated Time:** 10-15 hours total
**Path Structure:** Introduces intermediate stepping stones at challenging transitions
**Achievement:** Complete Mastery 🏆

**Why This Path:** Intermediate tasks (L3.4a, L3.5a) ease the learning curve for button integration and millis() timing. Splitting L3.7 into basic (L3.7a) and full (L3.7b) versions allows building confidence before tackling the complete system.

---

### Path B: Jump to Level 3, Fill Gaps
**"I want the full project but need help with specifics"**

```
START: L3.4 (try it)
  ↓
STUCK: Need button help
  ↓
BACKTRACK: L3.1 → L3.2 (button basics)
  ↓
CONTINUE: L3.4 ✓
  ↓
STUCK: Timing issues
  ↓
BACKTRACK: L2.6 → L3.5 (millis timing)
  ↓
CONTINUE: L3.7 → COMPLETE!
```
**Estimated Time:** 3-5 hours
**Achievement:** Problem Solver 🎯

---

### Path C: Theory First, Then Build
**"I want to understand before I build"**

```
EXP.1 (FSA theory) → ADV.1 (state machines)
  ↓
Read all documentation
  ↓
L2.4 (implement what you learned)
  ↓
L3.4 → L3.7 (apply theory)
  ↓
ADV.3 → ADV.4 (verify it works)
```
**Estimated Time:** 5-8 hours
**Achievement:** Theoretical Master 📚

---

### Path D: Build Minimum, Then Enhance
**"I want it working ASAP, then improve"**

```
L1.4 (prove Arduino works)
  ↓
L2.1 → L2.2 (add LEDs fast)
  ↓
L2.3 → L2.4 (basic sequence)
  ↓
[WORKING TRAFFIC LIGHT!]
  ↓
Then add as desired:
- L3.1 → L3.4 (button)
- L2.5 (cleaner code)
- L3.6 (debugging)
- ADV.2 (functions)
```
**Estimated Time:** 1-2 hours to working, +more for enhancements
**Achievement:** Rapid Prototyper ⚡

---

### Path E: Start Advanced, Backfill Skills
**"I want to jump in deep and learn by struggle"**

```
START: ADV.1 (read about state machines)
  ↓
TRY: Copy Clean code version
  ↓
CONFUSED: What's digitalWrite?
  ↓
BACKTRACK: L1.6 (learn digitalWrite)
  ↓
CONFUSED: What's millis()?
  ↓
BACKTRACK: L3.5 (learn timing)
  ↓
CONFUSED: How do buttons work?
  ↓
BACKTRACK: L3.1 → L3.2 (button basics)
  ↓
NOW UNDERSTAND: Re-read Clean code
  ↓
CONTINUE: ADV.2 → ADV.3 → ADV.4
```
**Estimated Time:** Variable, higher struggle but deeper learning
**Achievement:** Determined Explorer 🗡️

---

## 🔄 Cross-Level Task Dependencies

This diagram shows which tasks from different levels work together:

```
        [Hardware Skills]           [Software Skills]         [Theory Skills]
              |                            |                         |
    L1.3 ─────┼──────> L2.1 ────> L3.1    |                         |
    Single LED       Add LEDs    Button    |                         |
              |                            |                         |
    L1.4 ─────┼──────> L2.3 ────> L3.4 ───┼────> ADV.1 ──> EXP.1
    Blink        Sequence   Button Logic   |   State Machine   FSA Theory
              |                            |                         |
    L1.5 ─────┼──────> L2.6 ────> L3.5 ───┘                         |
    Timing         Verify      millis()                              |
                                                                      |
    L2.5 (#define) ────────────────────────────> ADV.2 ──> EXP.2
                                            Functions   Ontology
```

---

## 🎯 Skill-Based Navigation

**Want to learn a specific skill? Start with these tasks:**

### I Want to Learn: Button Input
```
Recommended Path:
L1.3 (circuits) → L1.4 (basics) → L3.1 (button circuit) → L3.2 (read input) → L3.4 (use it)

Can Skip:
L2.1, L2.2 (extra LEDs not needed for button learning)
```

### I Want to Learn: Timing
```
Recommended Path:
L1.5 (delay) → L2.3 (sequences) → L2.6 (verify) → L3.5 (millis)

Can Skip:
L3.1-L3.3 (button stuff not needed for timing)
```

### I Want to Learn: State Machines
```
Recommended Path:
EXP.1 (theory first) → L2.4 (see it in code) → ADV.1 (understand deeply) → ADV.3 (apply)

Prerequisites:
L1.4 (basic Arduino) helps but not required
```

### I Want to Learn: Professional Coding
```
Recommended Path:
L2.5 (#define) → L3.6 (debugging) → ADV.2 (functions) → ADV.5 (documentation)

Prerequisites:
L2.4 (working code to refactor)
```

---

## 🗺️ Task Relationship Map

```
FOUNDATIONAL TASKS (Do These First):
┌─────────────────────────────────────┐
│ L1.1  L1.2  L1.3  L1.4              │
│ [These unlock everything else]      │
└─────────────────────────────────────┘
              ↓
BUILDING TASKS (Choose Your Focus):
┌──────────────┬──────────────┬──────────────┐
│   Hardware   │   Software   │    Theory    │
├──────────────┼──────────────┼──────────────┤
│ L2.1 → L2.2  │ L2.3 → L2.5  │ EXP.1 → ADV.1│
│ L3.1 → L3.3  │ L3.6         │ EXP.2 → EXP.4│
└──────────────┴──────────────┴──────────────┘
              ↓
INTEGRATION TASKS (Combine Skills):
┌─────────────────────────────────────┐
│ L2.4  L3.4  L3.5  L3.7              │
│ [Requires multiple skill areas]     │
└─────────────────────────────────────┘
              ↓
MASTERY TASKS (Polish & Depth):
┌─────────────────────────────────────┐
│ ADV.2  ADV.3  ADV.4  ADV.5          │
│ EXP.3  [Optional: EXP.4]            │
└─────────────────────────────────────┘
```

---

## 📋 Personal Quest Planner

**Use this to plan YOUR unique path:**

### My Starting Point:
- [ ] Never used Arduino → Start L1.1
- [ ] Used Arduino before → Start L2.1 or L3.1
- [ ] Want theory first → Start EXP.1
- [ ] Have working code, want to improve → Start ADV.2

### My Goals (check all that apply):
- [ ] Just make something blink → L1.4 is enough!
- [ ] Build traffic light → Need L2.4
- [ ] Add button → Need L3.4
- [ ] School project (GCSE/BTEC) → Need L3.7
- [ ] A-Level coursework → Need ADV.1 + EXP.1
- [ ] Professional code → Need ADV.2 → ADV.5
- [ ] Deep understanding → Need EXP.1 → EXP.4

### My Current Skills:
**Hardware:**
- [ ] Can wire an LED → L1.3 ✓
- [ ] Can wire multiple LEDs → L2.2 ✓
- [ ] Can wire buttons → L3.1 ✓
- [ ] Understand breadboards well → All hardware ✓

**Software:**
- [ ] Know digitalWrite → L1.6 ✓
- [ ] Know delay() → L1.5 ✓
- [ ] Know millis() → L3.5 ✓
- [ ] Know functions → ADV.2 ✓
- [ ] Know state machines → ADV.1 ✓

**Theory:**
- [ ] Understand sequences → L2.3 ✓
- [ ] Understand FSM → EXP.1 ✓
- [ ] Know formal verification → EXP.3 ✓

### My Personalized Path:
```
Week 1: ___________________ (tasks: ________)
Week 2: ___________________ (tasks: ________)
Week 3: ___________________ (tasks: ________)
Week 4: ___________________ (tasks: ________)
```

---

## 🔓 Unlocking Advanced Tasks Early

**Can I do advanced tasks without completing earlier ones?**

**YES! Here's how:**

### To Do ADV.1 (State Machines) Early:
**Minimum Requirements:**
- Need to understand: What's a traffic light sequence? (can read, don't need to build)
- Can complete: Just read EXP.1 first
- **Path:** EXP.1 (theory) → ADV.1 (practice) → THEN build L2.4 to see it work

### To Do ADV.2 (Functions) Early:
**Minimum Requirements:**
- Need: Working code to refactor (any level)
- Can complete: After L1.4 or L2.3
- **Path:** L1.4 → ADV.2 (refactor blinking code) → L2.3 → ADV.2 (refactor again better)

### To Do ADV.3 (Safety Checks) Early:
**Minimum Requirements:**
- Need: Understand what can go wrong
- Can complete: Read theory first, then implement
- **Path:** EXP.1 → ADV.1 → ADV.3 → THEN build L3.4 with safety from start

### To Do EXP.1 (FSA Theory) Early:
**Minimum Requirements:**
- None! Pure theory, can do anytime
- Better with: L2.4 as example to reference
- **Path:** Can do before ANY coding!

---

## 🎮 Quest Combinations (Speedrun Routes)

### Speedrun 1: Minimum Viable Traffic Light
**Goal:** Working traffic light in <1 hour
```
L1.1 → L1.2 → L1.3 → L1.4 (15 mins)
L2.1 → L2.2 (15 mins)
L2.3 → L2.4 (30 mins)
DONE: 60 minutes
```

### Speedrun 2: Theory to Implementation
**Goal:** Understand then build in one session
```
EXP.1 (read 30 mins)
ADV.1 (study 20 mins)
L2.4 (implement 30 mins)
L3.4 (extend 40 mins)
DONE: 2 hours
```

### Speedrun 3: Button Mastery
**Goal:** Learn buttons deeply
```
L1.4 (10 mins - prove Arduino works)
L3.1 (15 mins - button circuit)
L3.2 (20 mins - read button)
L3.4 (30 mins - use button in logic)
L3.7 (30 mins - advanced button features)
DONE: 1hr 45mins
```

---

## 🔄 Circular Dependencies Resolved

**Some tasks seem to need each other. Here's how to break the loop:**

### L3.4 needs L2.4, but you want buttons first?
**Solution:**
1. Do L3.1 → L3.2 (button only, no traffic light)
2. Make button just print to Serial Monitor
3. Then do L2.4 (traffic light only, no button)
4. Finally L3.4 (combine them)

### ADV.2 needs working code, but want functions first?
**Solution:**
1. Read ADV.2 theory
2. Do L1.4 with functions from the start
3. Practice functions on simple code
4. Then apply to complex code later

### Want L3.5 (millis) but don't want full button system?
**Solution:**
1. Do L2.4 (traffic light with delay)
2. Do L3.5 (convert just the traffic light to millis)
3. Skip L3.1-L3.4 if you don't want buttons
4. Come back to buttons later if desired

---

## 🎯 Task Completion Tracking

**Print this or copy to track your progress:**

```
FOUNDATIONAL:
[ ] L1.1 - Connect Arduino
[ ] L1.2 - Upload Code
[ ] L1.3 - Single LED Circuit
[ ] L1.4 - Make LED Blink
[ ] L1.5 - Change Speed
[ ] L1.6 - Understand digitalWrite

BUILDING:
[ ] L2.1 - Add Second LED
[ ] L2.2 - Add Third LED
[ ] L2.3 - Create Sequence
[ ] L2.4 - UK Standard
[ ] L2.5 - Use #define
[ ] L2.6 - Verify Timing

INTEGRATION:
[ ] L3.1 - Button Circuit
[ ] L3.2 - Read Button
[ ] L3.3 - Pedestrian LEDs
[ ] L3.4 - Button Logic
[ ] L3.5 - millis() Timing
[ ] L3.6 - Serial Debug
[ ] L3.7 - Request Queue

ADVANCED:
[ ] ADV.1 - State Machines
[ ] ADV.2 - Functions
[ ] ADV.3 - Safety Checks
[ ] ADV.4 - Verification
[ ] ADV.5 - Documentation

EXPERT:
[ ] EXP.1 - FSA Theory
[ ] EXP.2 - Ontological Analysis
[ ] EXP.3 - Formal Verification
[ ] EXP.4 - Philosophy

Your Completion: _____ / 32 tasks
```

---

## 🗺️ Choose Your Path

Now that you see ALL possible routes, choose your adventure:

**→ [Return to Quest Start](QUEST_START.md)** - Choose a level
**→ [Level 1](QUEST_LEVEL_1.md)** - Start with basics
**→ [Level 2](QUEST_LEVEL_2.md)** - Jump to traffic light
**→ [Level 3](QUEST_LEVEL_3.md)** - Start with full system
**→ [Advanced](QUEST_ADVANCED.md)** - Theory and professional code
**→ [Expert](QUEST_EXPERT.md)** - Philosophy and verification

**Remember:** There is no wrong path. Every expert took a different route. Take YOURS! 🚀