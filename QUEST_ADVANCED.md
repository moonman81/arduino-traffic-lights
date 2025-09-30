# Advanced Topics

## Overview

This section covers advanced embedded systems concepts including professional code structure, state machine theory, and safety verification.

**Prerequisites:** Level 3 complete, or equivalent embedded systems experience

**What you'll learn:**
- Formal state machines (FSM)
- Professional code organization
- Safety verification techniques
- Runtime checking
- Requirements engineering

---

## Available Topics

### 1. State Machine Theory

**File:** `documentation/TRAFFIC_LIGHT_FSA_ANALYSIS.md`

Learn about:
- Finite State Automata (FSA) formal definition
- State transition diagrams
- Deterministic vs non-deterministic systems
- Temporal logic properties
- Formal verification

**Code example:** `arduino-code/examples/TRACK-theory-first.ino` demonstrates FSM concepts with mathematical notation.

---

### 2. Professional Code Structure

**File:** `arduino-code/examples/ADV-1_state_machine.ino`

Covers:
- Using enum for states (not #define)
- State transition functions
- Separation of concerns
- Error handling
- Logging and debugging

**Comparison:** Compare this with `traffic-light-level3-pedestrian-simple.ino` to see the difference between learning code and production code.

---

### 3. Code Organization

**File:** `arduino-code/examples/ADV-2_with_functions.ino`

Learn:
- When to create functions
- Code reuse
- Maintainability
- Refactoring techniques
- Professional practices

**Exercise:** Take Level 2 code and refactor it using these principles.

---

### 4. Safety Verification

**File:** `arduino-code/examples/ADV-3_safety_checks.ino`

Demonstrates:
- Runtime verification
- Safety invariant checking
- Emergency safe states
- Violation logging
- Defensive programming

**Theory:** `arduino-code/traffic-lights-arduino-clean.c` includes formal safety proofs in comments.

---

### 5. Requirements Engineering

**File:** `documentation/ONTOLOGICAL_ANALYSIS_TRAFFIC_SYSTEM.md`

Explores:
- Requirements specification
- Traceability
- Verification vs validation
- Safety requirements
- Functional requirements

---

## Learning Paths

### Path 1: Theory First
1. Read FSA Analysis
2. Study TRACK-theory-first.ino
3. Implement your own FSM
4. Compare with provided solutions

### Path 2: Code First
1. Study ADV-1 through ADV-3 examples
2. Understand the techniques
3. Read theory to understand why
4. Apply to your own projects

### Path 3: Professional Development
1. Review your Level 3 code
2. Refactor using ADV-2 principles
3. Add safety checks from ADV-3
4. Restructure as FSM from ADV-1
5. Document with theory from FSA Analysis

---

## Code Examples

All advanced examples are in `arduino-code/examples/`:
- `ADV-1_state_machine.ino` - Professional FSM structure
- `ADV-2_with_functions.ino` - Code organization
- `ADV-3_safety_checks.ino` - Runtime verification
- `TRACK-theory-first.ino` - Theory with implementation

Plus the main production code:
- `traffic-lights-arduino-clean.c` - Industry-standard implementation

---

## Recommended Reading Order

1. **Start:** ADV-2 (functions) - immediately applicable
2. **Then:** ADV-1 (state machines) - better structure
3. **Next:** FSA Analysis document - understand theory
4. **Finally:** ADV-3 (safety) - critical systems thinking

---

## For A-Level Computer Science

This section is particularly relevant for A-Level CS students:

**NEA (Coursework) suitability:**
- Complete project with real hardware
- State machine theory covered
- Professional code structure demonstrated
- Safety considerations documented

**Exam topics covered:**
- Finite State Machines (major topic)
- Algorithm design
- Problem-solving
- Testing and verification

See `UK_CURRICULUM_MAPPING.md` for detailed alignment.

---

## Next Steps

**→ [Study Formal Verification](documentation/ONTOLOGICAL_ANALYSIS_TRAFFIC_SYSTEM.md)** - Deep dive into proofs

**→ [Return to Quest Hub](START_HERE.md)** - Choose another path

**→ [View All Examples](arduino-code/CODE_EXAMPLES_INDEX.md)** - Find specific code