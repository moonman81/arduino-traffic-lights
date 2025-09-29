# UK Curriculum Mapping

## Purpose

This document provides explicit mapping between this Arduino project and UK qualification requirements. It helps teachers and students understand:
- Which qualification units are covered
- What assessment evidence can be generated
- Which code version suits which qualification level
- Learning outcomes aligned to specifications

Teachers can use this to justify the project for coursework or portfolio assessment.

---

## 🎓 Qualification Suitability Overview

| Qualification | Level | Suitable Project Version | Assessment Opportunities |
|---------------|-------|-------------------------|-------------------------|
| **GCSE Computer Science** | KS4 | Levels 1-2 | Programming, algorithms, hardware |
| **GCSE Design & Technology** | KS4 | Levels 1-3 | Electronics, prototyping, testing |
| **BTEC Level 2 Engineering** | KS4 | Levels 1-3 | Electronic circuits, practical skills |
| **BTEC Level 3 Engineering** | Post-16 | Level 3 + Clean version | Systems design, testing, documentation |
| **A-Level Computer Science** | Post-16 | Level 3 + Advanced versions | Algorithms, state machines, verification |
| **T-Level Digital Production** | Post-16 | All levels | Project delivery, documentation, testing |
| **T-Level Engineering** | Post-16 | All levels | Electronics, embedded systems, safety |

---

## 📚 GCSE Computer Science (AQA, OCR, Edexcel)

### Curriculum Coverage:

**Programming Skills:**
- ✅ Variables and data types (`bool`, `int`, `unsigned long`)
- ✅ Selection (`if`, `switch` statements)
- ✅ Iteration (`while` loops)
- ✅ Functions and procedures
- ✅ Boolean logic
- ✅ Input/output operations

**Algorithms:**
- ✅ Sequence (step-by-step execution)
- ✅ Selection (decision making)
- ✅ Iteration (repetition/loops)
- ✅ Timing algorithms (millis() timing)

**Hardware & Software:**
- ✅ Input devices (button)
- ✅ Output devices (LEDs)
- ✅ Sensors and control systems
- ✅ Embedded systems concepts

### Recommended Project Version:
**Level 2** (Basic Traffic Light) or **Level 3 Simple** (with button)

### Assessment Evidence:
- Working Arduino program
- Annotated code with comments
- Testing documentation
- Flowcharts or pseudocode planning
- Problem-solving log

### Example GCSE Questions Answered:
1. **"Write an algorithm for a traffic light sequence"** → Use Level 2 code
2. **"Explain how a button input is processed"** → Use Level 3 code
3. **"Describe how timing is controlled in embedded systems"** → `millis()` explanation

---

## 🔧 GCSE Design & Technology: Electronics (All Exam Boards)

### Curriculum Coverage:

**Electronics:**
- ✅ LED circuits with current-limiting resistors
- ✅ Input circuits (buttons with pull-up resistors)
- ✅ Power supply (5V from Arduino/USB)
- ✅ Circuit diagrams and breadboard layouts
- ✅ Component selection and specifications

**Design Process:**
- ✅ Design requirements (traffic light system)
- ✅ Prototyping (breadboard construction)
- ✅ Testing and evaluation
- ✅ User interface design (pedestrian button)
- ✅ Safety considerations

**Practical Skills:**
- ✅ Breadboard wiring
- ✅ Component identification
- ✅ Multimeter use (checking voltages/currents)
- ✅ Troubleshooting circuits
- ✅ Documentation

### Recommended Project Version:
**Level 2** or **Level 3 Simple** - hardware focus

### Assessment Evidence:
- Circuit diagrams (provided in `WIRING_INSTRUCTIONS.md`)
- Breadboard photographs
- Component list with specifications
- Testing log (does each LED work?)
- Evaluation against design criteria

### GCSE D&T Success Criteria Met:
- ✅ Design specification clearly defined
- ✅ Prototype built and tested
- ✅ Technical drawings provided
- ✅ Evaluation of performance
- ✅ Health and safety considered

---

## 🏗️ BTEC Level 2 Engineering (First Award/Diploma)

### Unit Mapping:

**Unit 1: The Engineered World**
- ✅ Electronic systems and components
- ✅ Function of control systems
- ✅ Impact of engineering (traffic safety)

**Unit 2: Investigating an Engineering Product**
- ✅ Component identification (LEDs, resistors, microcontroller)
- ✅ Function of components
- ✅ Testing and quality control

**Unit 3: Producing an Engineered Product** ⭐ **PRIMARY UNIT**
- ✅ Interpret engineering drawings (circuit diagrams provided)
- ✅ Select appropriate tools and equipment
- ✅ Produce engineered product (build traffic light)
- ✅ Check and test product
- ✅ Review engineered product performance

**Unit 5: Electronics for a Purpose**
- ✅ Electronic components and symbols
- ✅ Circuit construction
- ✅ Input/output devices
- ✅ Testing electronic circuits

### Recommended Project Version:
**Level 2** (building skills) then **Level 3 Simple** (full project)

### BTEC Assessment Evidence:
- **Pass criteria:** Build working traffic light, test basic functions
- **Merit criteria:** Test systematically, suggest improvements
- **Distinction criteria:** Evaluate performance against specification, justify design choices

### BTEC Evidence Portfolio:
1. Project brief (provided in `BEGINNER_BUILD_GUIDE.md`)
2. Circuit diagram (provided in `WIRING_INSTRUCTIONS.md`)
3. Component list with specifications
4. Build log with photographs
5. Testing evidence (does it meet timing requirements?)
6. Evaluation and improvements

---

## 🔬 BTEC Level 3 Engineering (Extended Diploma/Diploma)

### Unit Mapping:

**Unit 1: Engineering Principles** ⭐ **STRONG FIT**
- ✅ Electrical principles (Ohm's law for resistor calculations)
- ✅ Component characteristics (LED forward voltage, current)
- ✅ Circuit analysis
- ✅ Mechanical principles (button mechanism)

**Unit 4: Applied Electrical/Electronic Engineering** ⭐ **PRIMARY UNIT**
- ✅ Circuit theory and analysis
- ✅ Digital electronics (HIGH/LOW logic)
- ✅ Input/output devices
- ✅ Microcontroller applications
- ✅ Testing and measurement

**Unit 6: Microcontroller Systems for Engineers** ⭐ **EXCELLENT FIT**
- ✅ Microcontroller architecture (Arduino/ATmega328)
- ✅ Programming in C/C++
- ✅ Input/output interfacing
- ✅ Timing and interrupts
- ✅ System design and implementation

**Unit 8: Programmable Logic Controllers (optional link)**
- ✅ Sequential control systems
- ✅ State machines and ladder logic concepts
- ✅ Safety interlocks (mutual exclusion)

**Unit 17: Computer Aided Design in Engineering**
- ✅ Circuit design and simulation (Tinkercad)
- ✅ Documentation and technical drawings

### Recommended Project Version:
**Level 3 Simple** (practical) + **Clean version** (professional) + **FSA Analysis** (theory)

### BTEC Level 3 Assessment Evidence:

**For Pass:**
- Working traffic light system with pedestrian crossing
- Circuit calculations (resistor values using Ohm's law)
- Program with basic comments
- Test results showing it works

**For Merit:**
- Systematic testing with recorded results
- Analysis of timing requirements
- Comparison of design alternatives
- Detailed technical documentation

**For Distinction:**
- Comprehensive evaluation against specification
- State machine analysis (use `TRAFFIC_LIGHT_FSA_ANALYSIS.md`)
- Safety analysis (mutual exclusion, timing guarantees)
- Professional documentation standard
- Optimization and improvements justified

### BTEC Level 3 Evidence Portfolio:
1. Project specification (requirements analysis)
2. Circuit design with calculations (current, power, voltage drops)
3. Program listing with detailed comments
4. State machine diagram (FSA provided)
5. Test plan and results
6. Safety analysis (safety invariants documented)
7. User manual
8. Professional evaluation report

---

## 📐 A-Level Computer Science (AQA, OCR, Edexcel)

### Curriculum Coverage:

**Programming (Paper 1):**
- ✅ Data types (primitives, constants)
- ✅ Programming constructs (sequence, selection, iteration)
- ✅ Procedures and functions
- ✅ Boolean logic
- ✅ File handling (Serial output as logging)
- ✅ Error handling

**Algorithms (Paper 1):**
- ✅ Algorithm design and analysis
- ✅ Computational thinking
- ✅ Problem-solving strategies
- ✅ State transition systems
- ✅ Finite state automata ⭐

**Computer Systems (Paper 1):**
- ✅ Hardware and software
- ✅ Input/output devices
- ✅ Embedded systems
- ✅ Real-time systems

**Theory of Computation (Paper 2):**
- ✅ **Finite State Machines** ⭐⭐⭐ (Major topic!)
- ✅ Regular languages
- ✅ State transition diagrams
- ✅ Deterministic systems

**Non-Exam Assessment (NEA/Coursework):**
- ✅ Analysis of problem
- ✅ Design of solution
- ✅ Implementation
- ✅ Testing and evaluation
- ✅ Technical solution with real hardware

### Recommended Project Version:
**Level 3 Simple** + **Clean version** + **FSA Analysis Document** ⭐⭐⭐

### Why This Project is PERFECT for A-Level:

**1. Finite State Machines (Key A-Level Topic):**
The traffic light is a **textbook example** of an FSM:
- States: RED, RED+AMBER, GREEN, AMBER, PEDESTRIAN_CROSSING
- Transitions: Time-based and event-based (button press)
- Deterministic behavior
- State transition diagram provided in `TRAFFIC_LIGHT_FSA_ANALYSIS.md`

**2. Computational Thinking:**
- Abstraction (states represent complex light patterns)
- Decomposition (functions for LED control, button processing)
- Pattern recognition (repeating cycle)
- Algorithm design (state machine implementation)

**3. Non-Exam Assessment Suitability:**
This project provides:
- ✅ Real-world problem with stakeholders (road safety)
- ✅ Clear requirements (timing, safety, UK standards)
- ✅ Hardware interface (not just screen-based)
- ✅ Opportunity for extension (multiple intersections)
- ✅ Safety-critical aspects (formal verification possible)

### A-Level Assessment Evidence:

**Analysis:**
- Problem definition (traffic safety, pedestrian crossing needs)
- Stakeholder requirements
- Research into UK traffic light standards
- Computational thinking breakdown

**Design:**
- State transition diagram (FSA)
- Data structure design (state variables)
- Algorithm design (pseudocode/flowcharts)
- Hardware interface design (pin assignments)

**Implementation:**
- Well-structured code (use Clean version)
- Comments and documentation
- Version control possible (Git repository provided)

**Testing:**
- Test plan (state transitions)
- Normal operation testing
- Edge cases (button during different states)
- Safety property verification (mutual exclusion)

**Evaluation:**
- Performance against requirements
- Limitations and improvements
- User feedback potential

### A-Level Exam Questions This Addresses:

**Example 1: "Draw a state transition diagram for a traffic light system"**
→ Directly answered in `TRAFFIC_LIGHT_FSA_ANALYSIS.md`

**Example 2: "Explain how a finite state machine could be implemented in code"**
→ Use `switch` statement in Level 3 code as example

**Example 3: "Describe a real-world application of embedded systems"**
→ This entire project!

---

## ⚙️ T-Level Digital Production, Design and Development

### Core Component Mapping:

**Digital Production:**
- ✅ Digital systems design and implementation
- ✅ Testing and quality assurance
- ✅ Documentation standards
- ✅ Version control (Git repository)
- ✅ Problem-solving

**Occupational Specialism (Digital Support Services):**
- ✅ System testing and evaluation
- ✅ Technical documentation
- ✅ User support documentation (Beginner's Guide)
- ✅ Troubleshooting procedures

**Occupational Specialism (Software Development):**
- ✅ Programming in C/C++
- ✅ Algorithm implementation
- ✅ State machine design
- ✅ Code documentation
- ✅ Version control practices

### Recommended Project Version:
**All levels** (demonstrates progression) + **Professional documentation**

### T-Level Industry Placement Relevance:
- Embedded systems programming skills
- Hardware/software integration
- Professional documentation practices
- Safety-critical system awareness
- Version control with Git

### T-Level Assessment Evidence:

**Core Knowledge:**
- Technical understanding of digital systems
- Problem analysis and solution design
- Testing methodologies

**Practical Skills:**
- Building and testing circuits
- Programming microcontrollers
- Creating technical documentation
- Version control (Git)

**Industry Practices:**
- Professional code standards (see Clean version)
- Comprehensive documentation (multiple markdown files)
- Testing logs and evaluation
- Safety considerations

---

## ⚙️ T-Level Design, Surveying and Planning for Construction (Engineering Route)

### Core Component Mapping:

**Engineering Design:**
- ✅ Design principles and processes
- ✅ Electronic system design
- ✅ Technical drawings and schematics
- ✅ Component selection
- ✅ Testing and validation

**Health, Safety and Environment:**
- ✅ Electrical safety (current limits, resistor selection)
- ✅ Risk assessment (LED current ratings)
- ✅ Safe working practices

**Digital Engineering:**
- ✅ CAD/simulation (Tinkercad)
- ✅ Digital prototyping
- ✅ Documentation

**Occupational Specialism (Engineering):**
- ✅ Electronic circuits and systems
- ✅ Control systems (embedded)
- ✅ Testing and commissioning
- ✅ Maintenance documentation

### Recommended Project Version:
**Level 2-3** (practical focus) + **Full documentation set**

### T-Level Engineering Assessment Evidence:

**Design Portfolio:**
- Requirements specification
- Circuit design with calculations
- Component datasheets and selection rationale
- Risk assessment (electrical safety)
- Testing and commissioning plan

**Practical Implementation:**
- Built and tested prototype
- Photographic evidence of build process
- Testing results documented
- Commissioning records

**Professional Practice:**
- User documentation (guides provided)
- Maintenance procedures
- Safety considerations
- Quality standards met

---

## 🎯 Quick Reference: Which Version for Which Qualification?

| Qualification | Start With | Progress To | Use For Assessment |
|--------------|-----------|-------------|-------------------|
| **GCSE Computer Science** | Level 1-2 | Level 3 Simple | Code + flowchart |
| **GCSE D&T Electronics** | Level 1-2 | Level 3 Simple | Build + circuit + test |
| **BTEC L2 Engineering** | Level 2 | Level 3 Simple | Build + test + evaluate |
| **BTEC L3 Engineering** | Level 3 Simple | Clean + FSA | Full portfolio |
| **A-Level Computer Science** | Level 3 Simple | Clean + FSA | NEA project |
| **T-Level Digital** | All levels | Professional docs | Full portfolio |
| **T-Level Engineering** | Level 2-3 | Full docs | Practical + theory |

---

## 📋 Assessment Evidence Checklist

### For All Qualifications:

**Documentation Provided:**
- ✅ Requirements specification (in guides)
- ✅ Circuit diagrams (`WIRING_INSTRUCTIONS.md`)
- ✅ Component specifications (in guides)
- ✅ Program listings (5 versions, different complexity)
- ✅ State machine analysis (`TRAFFIC_LIGHT_FSA_ANALYSIS.md`)
- ✅ Testing guidance (in `BEGINNER_BUILD_GUIDE.md`)
- ✅ User manual (the beginner's guide itself)
- ✅ Safety analysis (in Clean version comments)

**Student Needs to Provide:**
- □ Photographs of build process
- □ Personal testing log (what they tried)
- □ Modifications or improvements they made
- □ Evaluation of their work
- □ Personal problem-solving log

---

## 💡 Teacher Guidance: Using This Project for Assessment

### For GCSE/BTEC Level 2:
- **Focus on:** Practical skills, basic understanding, working product
- **Evidence needed:** Build photos, basic testing, simple evaluation
- **Use:** Levels 1-3 Simple only

### For BTEC Level 3:
- **Focus on:** Professional documentation, calculations, systematic testing
- **Evidence needed:** Comprehensive portfolio with calculations
- **Use:** Level 3 Simple + Clean version + FSA document

### For A-Level NEA:
- **Focus on:** FSM theory, algorithm design, formal documentation
- **Evidence needed:** Full analysis/design/implementation/testing/evaluation
- **Use:** All documents, emphasize FSA analysis

### For T-Levels:
- **Focus on:** Industry practices, professional standards, real-world skills
- **Evidence needed:** Industry-standard portfolio
- **Use:** All materials, emphasize documentation quality

---

## 🎓 Skills Matrix by Qualification

| Skill Area | GCSE CS | GCSE D&T | BTEC L2 | BTEC L3 | A-Level | T-Level |
|------------|---------|----------|---------|---------|---------|---------|
| Programming | ✅✅✅ | ✅ | ✅✅ | ✅✅✅ | ✅✅✅ | ✅✅✅ |
| Electronics | ✅ | ✅✅✅ | ✅✅✅ | ✅✅✅ | ✅ | ✅✅✅ |
| Circuit Building | ✅ | ✅✅✅ | ✅✅✅ | ✅✅ | ✅ | ✅✅ |
| State Machines | ✅ | - | ✅ | ✅✅ | ✅✅✅ | ✅✅ |
| Documentation | ✅ | ✅✅ | ✅✅ | ✅✅✅ | ✅✅ | ✅✅✅ |
| Testing | ✅✅ | ✅✅ | ✅✅ | ✅✅✅ | ✅✅✅ | ✅✅✅ |
| Safety Analysis | - | ✅ | ✅ | ✅✅ | ✅✅ | ✅✅✅ |
| Professional Practice | - | ✅ | ✅ | ✅✅ | ✅ | ✅✅✅ |

---

## ✅ Curriculum Compliance Confirmation

This project is **confirmed suitable** for:

✅ **GCSE Computer Science** (All exam boards: AQA, OCR, Edexcel)
- Meets programming requirements
- Covers algorithm design
- Demonstrates computational thinking

✅ **GCSE Design & Technology: Electronics** (All exam boards)
- Complete electronics project
- Circuit design and build
- Testing and evaluation

✅ **BTEC Level 2 Engineering** (Units 1, 2, 3, 5)
- Practical engineering skills
- Product creation and testing
- Electronic systems

✅ **BTEC Level 3 Engineering** (Units 1, 4, 6, 8, 17)
- Advanced electronics and microcontrollers
- Professional documentation
- System design and analysis

✅ **A-Level Computer Science** (All exam boards)
- Finite State Machines (key theory topic)
- Suitable for NEA (coursework project)
- Real hardware implementation

✅ **T-Level Digital Production** (Digital Support/Software Dev)
- Industry-standard practices
- Professional documentation
- Version control ready

✅ **T-Level Engineering** (Construction/Manufacturing routes)
- Electronic system design
- Control systems
- Safety and testing

---

## 📞 For Teachers: Assessment Support

This repository includes **everything needed** for assessment:

1. **Differentiated by difficulty** (Levels 1-3 + advanced)
2. **Complete documentation** (guides, diagrams, theory)
3. **Explicit curriculum mapping** (this document)
4. **Evidence opportunities** clearly identified
5. **Scalable complexity** (same hardware, different code)

**Students can succeed at their level while being stretched appropriately.**

---

*This project meets UK curriculum requirements across multiple qualifications at different levels.*