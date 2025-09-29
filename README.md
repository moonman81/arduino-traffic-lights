# Arduino Traffic Light Controller

## 🚦 Educational Traffic Light System - From Beginner to Expert

This repository contains a complete Arduino-based traffic light control system designed for **students at all levels**. Start with a single blinking LED or dive into formal safety verification and philosophical foundations. **You choose your own path!**

**Perfect for:** Electronics students, Arduino beginners, embedded systems classes, and advanced computer science research.

---

## 🎮 NEW: Quest-Based Learning Mode!

**Learn by doing in an interactive adventure!** Choose your path, complete challenges, earn achievements, and level up your skills.

**→ [START YOUR QUEST HERE](QUEST_START.md)** ⚔️

- 🎯 Choose your difficulty
- 📊 Track your progress
- 🏆 Unlock achievements
- 🗺️ Multiple paths to mastery

---

## 🎯 Quick Start - Choose Your Level

| Level | Time | What You'll Build | Start Here |
|-------|------|-------------------|------------|
| 🟢 **Beginner** | 10 min | One blinking LED | `BEGINNER_BUILD_GUIDE.md` Part 1 |
| 🟡 **Intermediate** | 45 min | 3-LED traffic light | `BEGINNER_BUILD_GUIDE.md` Level 2 |
| 🔴 **Advanced** | 2 hours | Full pedestrian crossing | `BEGINNER_BUILD_GUIDE.md` Level 3 |
| 🎓 **Expert** | Study | Formal verification & theory | See documentation below |

**New to Arduino?** Start with `QUICK_START_GUIDE.md`

**Not sure which code to use?** See `CODE_COMPARISON.md`

**UK Teacher?** See `UK_CURRICULUM_MAPPING.md` for GCSE/BTEC/A-Level/T-Level suitability

---

## 📚 Documentation for Every Level

### For Students & Beginners:
- **`BEGINNER_BUILD_GUIDE.md`** - Step-by-step instructions, no experience needed
- **`QUICK_START_GUIDE.md`** - Quick overview and level selection
- **`CODE_COMPARISON.md`** - Which code version should you use?
- **`WIRING_INSTRUCTIONS.md`** - Hardware setup and circuit diagrams

### For Teachers & Educators:
- **`UK_CURRICULUM_MAPPING.md`** ⭐ **Curriculum compliance for GCSE, BTEC, A-Level, T-Level**
  - Explicit learning outcomes mapped to specifications
  - Assessment evidence guidance
  - Unit-by-unit mapping for all major UK qualifications

### For Advanced Study:
- **`TRAFFIC_LIGHT_FSA_ANALYSIS.md`** - Finite state automaton theory (perfect for A-Level CS)
- **`ONTOLOGICAL_ANALYSIS_TRAFFIC_SYSTEM.md`** - Philosophical foundations
- **Ontological analysis files** - Formal verification and safety proofs

---

## 📦 What's Included

### Arduino Code (Progressive Difficulty):

1. **`traffic-light-level1-single-led.ino`** - One blinking LED (30 lines)
2. **`traffic-light-level2-basic.ino`** - Basic traffic light sequence (60 lines)
3. **`traffic-light-level3-pedestrian-simple.ino`** - Full system, student-friendly (200 lines) ⭐ **RECOMMENDED**
4. **`traffic-lights-arduino-clean.c`** - Professional structure with safety checks (460 lines)
5. **`traffic-lights-arduino-optimized-final.c`** - Complete with academic documentation (600+ lines)

**Most students should start with Level 3 Simple!** It has all features and is designed for learning.

## 📋 Project Overview

### **System Features**
- ✅ **UK Traffic Light Standard**: Proper RED+AMBER preparation phase
- ✅ **Pedestrian Crossing**: Separate red/green pedestrian signals with democratic request processing
- ✅ **Formal Safety Verification**: Mathematically proven safe with 4 safety invariants
- ✅ **Ontological Analysis**: Comprehensive philosophical and requirements engineering
- ✅ **Educational Platform**: Suitable for Tinkercad simulation and electronics learning
- ✅ **Professional Code**: Clean, documented, maintainable implementation

### **Safety Properties (Formally Proven)**
1. **Mutual Exclusion**: Traffic and pedestrian greens never simultaneous
2. **Progressive Warning**: All green→red transitions pass through amber
3. **Minimum Time Guarantee**: 3-second minimum green before interruption
4. **Deadlock Freedom**: System always progresses, never gets stuck

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