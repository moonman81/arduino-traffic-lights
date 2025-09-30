# Arduino Traffic Light

## You will build a working traffic light

Press button → Pedestrian gets green light → Cars stop

Just like real UK traffic lights.

**No experience needed.**

---

## Start here

**→ [START_HERE.md](START_HERE.md)** ← Click this

Pick Level 1, 2, or 3. That's it.

---

## For your tutor

**→ [TUTOR_GUIDE.md](TUTOR_GUIDE.md)** - Give them this. Explains everything.

**→ [UK_CURRICULUM_MAPPING.md](UK_CURRICULUM_MAPPING.md)** - Shows GCSE/BTEC/A-Level coverage

---

## What you can build

### 🟢 Level 1: One blinking LED (10 minutes)
Just one light turning on and off. Easy first step.

**Start:** [QUEST_LEVEL_1.md](QUEST_LEVEL_1.md)

---

### 🟡 Level 2: Traffic light (45 minutes)
Red, yellow, green lights in the right pattern.

**Start:** [QUEST_LEVEL_2.md](QUEST_LEVEL_2.md)

---

### 🔴 Level 3: Full system with button (2 hours)
The complete project. Press button, pedestrian gets green light.

**Start:** [QUEST_LEVEL_3.md](QUEST_LEVEL_3.md)

---

**Never used Arduino before?** → Start at Level 1

**Just want to see working code?** → [Code Examples](arduino-code/CODE_EXAMPLES_INDEX.md)

---

## Files to read

### If you're building it:
- **[BEGINNER_BUILD_GUIDE.md](BEGINNER_BUILD_GUIDE.md)** - Follow this step by step
- **[CODE_COMPARISON.md](CODE_COMPARISON.md)** - Which code should I use?
- **[TROUBLESHOOTING.md](TROUBLESHOOTING.md)** - Something not working? Look here

### If your tutor asks about qualifications:
- **[UK_CURRICULUM_MAPPING.md](UK_CURRICULUM_MAPPING.md)** - Shows GCSE, BTEC, A-Level coverage

### If you want to understand the theory:
- **[QUEST_ADVANCED.md](QUEST_ADVANCED.md)** - How state machines work
- **[QUEST_EXPERT.md](QUEST_EXPERT.md)** - Academic/university level stuff

---

## What this project includes

### Code files (pick the right one for your level):

**Beginners:**
- `L1-4_single_led_blink.ino` - Just one LED (easy start)
- `L2-4_uk_traffic_light.ino` - Three lights working
- `L3-7b_full_features.ino` - Complete system ⭐ **Use this one for coursework**

**Advanced:**
- `ADV-1-practical_state_machine.ino` - Professional code structure
- `traffic-lights-arduino-clean.c` - University level with safety proofs

**All 27 code examples:** See [CODE_EXAMPLES_INDEX.md](arduino-code/CODE_EXAMPLES_INDEX.md)

---

## What makes this good

### It follows real UK traffic light rules:
- ✅ Red + Yellow before green (like real traffic lights)
- ✅ Button for pedestrians works properly
- ✅ Pedestrian gets green light, cars get red (safe!)
- ✅ Works on Tinkercad (online) or real Arduino

### It's good for education:
- ✅ Suitable for GCSE, BTEC, A-Level coursework
- ✅ All code explained with comments
- ✅ Has troubleshooting help
- ✅ Step-by-step building guide

---

## 🏗️ Repository Structure

```
arduino-traffic-lights/
├── BEGINNER_BUILD_GUIDE.md         # ⭐ START HERE - Complete beginner tutorial
├── QUICK_START_GUIDE.md            # Quick level selection guide
├── CODE_COMPARISON.md              # Which code version to use
├── README.md                        # This file
│
├── arduino-code/                    # Code files (progressive difficulty)
│   ├── traffic-light-level1-single-led.ino           # Level 1: One LED
│   ├── traffic-light-level2-basic.ino                # Level 2: Traffic light
│   ├── traffic-light-level3-pedestrian-simple.ino    # Level 3: Full system ⭐
│   ├── traffic-lights-arduino-clean.c                # Advanced: Professional
│   ├── traffic-lights-arduino-optimized-final.c      # Expert: All features
│   └── [older versions for reference]
│
├── documentation/                   # Hardware and theory docs
│   ├── WIRING_INSTRUCTIONS.md      # Circuit diagrams
│   ├── TRAFFIC_LIGHT_FSA_ANALYSIS.md       # State machine theory
│   └── ONTOLOGICAL_ANALYSIS_TRAFFIC_SYSTEM.md  # Formal verification
│
└── ontological-analysis/            # Advanced: Formal proofs (N3 format)
    ├── base-ontology.n3            # Philosophical foundations
    ├── formal-safety-proof.n3      # Mathematical safety verification
    └── [additional analysis files]
```

## 🔧 Hardware Setup

### **Pin Configuration (UK Standard)**
| Pin | Component | Description |
|-----|-----------|-------------|
| 13  | Pedestrian Button | INPUT_PULLUP - Democratic participation interface |
| 12  | Red Traffic LED | OUTPUT - Universal prohibition signifier |
| 11  | Amber Traffic LED | OUTPUT - Temporal transition warning |
| 10  | Green Traffic LED | OUTPUT - Movement permission authorization |
| 9   | Pedestrian Red LED | OUTPUT - Pedestrian constraint signal |
| 8   | Pedestrian Green LED | OUTPUT - Pedestrian empowerment signal |

### **Component Requirements**
- Arduino Uno R3
- 5× LEDs (Red, Amber/Yellow, Green, Red for pedestrian, Green/White for pedestrian)
- 5× 330Ω resistors (optimized for current efficiency)
- 1× Momentary push button
- Breadboard and jumper wires

### **Current Specifications**
- **Per LED**: 6-9mA (with 330Ω resistors)
- **Total System**: ~75mA (efficient operation)
- **Safety Margin**: Well within 40mA per pin / 200mA total limits

---

## 🚀 Quick Start (First Time Users)

### **Option 1: No Hardware? Try Tinkercad (Free Online Simulator)**
1. Open [Tinkercad Circuits](https://www.tinkercad.com/circuits) (no account needed for testing)
2. Add Arduino Uno R3 and components
3. Copy code from `arduino-code/traffic-light-level2-basic.ino` (easiest start)
4. Click "Start Simulation" and watch it work!
5. **Then:** Try Level 3 with button: `traffic-light-level3-pedestrian-simple.ino`

### **Option 2: Have Arduino Hardware?**
1. **Read:** `BEGINNER_BUILD_GUIDE.md` - complete step-by-step instructions
2. **Build:** Start with Level 1 (one LED) to verify everything works
3. **Progress:** Move through Level 2 → Level 3 at your own pace
4. **Stuck?** See troubleshooting sections in the guide

### **Option 3: Experienced Users**
1. Wire components per `documentation/WIRING_INSTRUCTIONS.md`
2. Upload `arduino-code/traffic-light-level3-pedestrian-simple.ino`
3. Open Serial Monitor (9600 baud) to see debugging output
4. Press button during green light to trigger pedestrian crossing

## 📊 System Behavior

### **Normal Traffic Cycle**
1. **RED** (5 seconds) - Traffic stopped
2. **RED+AMBER** (2 seconds) - Prepare to proceed
3. **GREEN** (6 seconds) - Traffic flows
4. **AMBER** (3 seconds) - Prepare to stop
5. Return to RED

### **Pedestrian Crossing Cycle**
- Button press during GREEN with >3 seconds elapsed → Immediate amber transition
- Button press during GREEN with <3 seconds elapsed → Queued until minimum time
- Button press during other states → Queued for next green cycle
- Pedestrian crossing phase: 8 seconds of safe crossing time

### **Safety Features**
- **Real-time Safety Verification**: Continuous monitoring of safety invariants
- **Emergency Response**: Automatic safe state on safety violation
- **Button Debouncing**: 200ms filter prevents false triggers
- **Non-blocking Architecture**: Responsive to all inputs

## 🧠 Ontological Analysis

This project includes a comprehensive ontological analysis using Notation3 (N3) format, exploring:

- **Philosophical Foundations**: Heidegger, Bergson, Deleuze, Whitehead, Harman perspectives
- **Requirements Engineering**: 19 formally specified requirements across 5 categories
- **Safety Verification**: Mathematical proofs with step-by-step verification
- **Simulation Theory**: Baudrillard's simulation orders applied to Tinkercad
- **Temporal Analysis**: Multiple theories of time and temporal coordination
- **Democratic Infrastructure**: Pedestrian button as citizen participation interface

## 🔬 Formal Verification

The system has been formally verified using:

- **State Transition System**: Complete mathematical model
- **Temporal Logic**: CTL and LTL property verification
- **Inductive Proofs**: Step-by-step safety invariant verification
- **Complexity Analysis**: O(1) finite state space complexity
- **Requirements Traceability**: End-to-end verification coverage

## 🎓 Educational Value

Perfect for learning:
- **Embedded Systems Programming**: Professional Arduino C development
- **Safety-Critical Systems**: Formal verification techniques
- **Requirements Engineering**: Comprehensive specification development
- **Philosophy of Technology**: Ontological analysis of technical systems
- **Electronics**: Circuit design and current optimization
- **State Machines**: Finite state automaton implementation

---

## 📚 Code Versions - Which One to Use?

See `CODE_COMPARISON.md` for detailed comparison. Here's the quick guide:

### **For Students (Recommended):**

- **`traffic-light-level1-single-led.ino`** - First Arduino program ever
- **`traffic-light-level2-basic.ino`** - Learning traffic light sequences
- **`traffic-light-level3-pedestrian-simple.ino`** ⭐ **BEST FOR MOST STUDENTS**
  - Complete system with all features
  - Heavily commented and explained
  - Serial debugging built in
  - Designed specifically for learning

### **For Advanced Study:**

- **`traffic-lights-arduino-clean.c`** - Professional embedded code structure
- **`traffic-lights-arduino-optimized-final.c`** - Academic research and formal verification

**Confused?** Read `CODE_COMPARISON.md` or just start with Level 3 Simple!


## 🔍 Safety Verification Results

```
PROVEN PROPERTIES:
✓ Mutual Exclusion Safety Invariant
✓ Progressive Warning Safety Invariant
✓ Minimum Time Safety Invariant
✓ Deadlock Freedom Safety Invariant
✓ Pedestrian Eventual Service Liveness Property
✓ Traffic Progress Liveness Property
✓ System Progress Liveness Property
✓ All CTL and LTL Temporal Logic Properties

CONCLUSION: THE TRAFFIC LIGHT SYSTEM IS FORMALLY PROVEN SAFE
```

---

## 🎓 Learning Outcomes

By completing this project, students will learn:

**Hardware Skills:**
- LED circuits and current limiting with resistors
- Button input with pull-up resistors
- Breadboard construction
- Arduino pin configuration

**Programming Concepts:**
- Digital I/O (pinMode, digitalWrite, digitalRead)
- Timing (delay, millis)
- Boolean logic and state variables
- Functions and code organization
- Serial communication for debugging

**Engineering Principles:**
- State machines and finite automata
- Safety-critical system design
- Timing requirements and fairness
- Button debouncing
- Requirements specification

**Advanced Topics (Optional):**
- Formal verification
- Safety invariants
- Temporal logic
- Ontological analysis
- Requirements engineering

---

## 🤝 For Educators & Teachers

This repository provides a **complete teaching progression** suitable for **UK curriculum requirements**:

1. **Level 1** builds confidence with immediate success
2. **Level 2** teaches sequences and multiple outputs
3. **Level 3** integrates inputs and outputs with logic
4. **Advanced versions** introduce professional practices

**Suggested class structure:**
- **Week 1:** Level 1 (get everyone working)
- **Week 2:** Level 2 (traffic light basics)
- **Week 3-4:** Level 3 (full project)
- **Week 5+:** Theory and optimization (FSA analysis)

### ✅ **UK Qualification Suitability:**

| Qualification | Suitable | Best Version | See Details |
|---------------|----------|--------------|-------------|
| **GCSE Computer Science** | ✅ Yes | Level 2-3 Simple | `UK_CURRICULUM_MAPPING.md` |
| **GCSE D&T Electronics** | ✅ Yes | Level 2-3 Simple | Hardware focus |
| **BTEC Level 2 Engineering** | ✅ Yes | Level 2-3 Simple | Units 1,2,3,5 |
| **BTEC Level 3 Engineering** | ✅ Yes | Clean + FSA | Units 1,4,6,8,17 |
| **A-Level Computer Science** | ✅ Yes | Clean + FSA | **Perfect for FSM topic + NEA** |
| **T-Level Digital Production** | ✅ Yes | All levels | Full portfolio |
| **T-Level Engineering** | ✅ Yes | All levels | Practical + theory |

**For full curriculum mapping, assessment evidence guidance, and learning outcomes,** see **`UK_CURRICULUM_MAPPING.md`**

All documentation is designed to be **accessible** while maintaining technical rigor and **meeting qualification requirements**.

---

## 📝 License

Educational and research use. Free to use for learning and teaching.

---

## 🙏 Acknowledgments

This project demonstrates how complex engineering concepts can be made accessible through progressive teaching. It bridges the gap between "hello world" and professional embedded systems development.

**From a single blinking LED to formal safety verification - learning at your own pace.**