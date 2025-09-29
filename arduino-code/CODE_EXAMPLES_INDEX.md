# Code Examples Index

## 📁 Complete Code Example Library

Every quest task and learning track has corresponding code examples. **Each file is independent** - copy and use any example without affecting others!

---

## 🗺️ Quest Task Examples

### Level 1: Foundation Tasks

| File | Task ID | Description | Hardware Needed | Difficulty |
|------|---------|-------------|-----------------|------------|
| `L1-1_arduino_test.ino` | L1.1, L1.2 | Test Arduino connection | Arduino only | ⭐☆☆☆☆ |
| `L1-4_single_led_blink.ino` | L1.4 | First external LED | 1 LED, 1 resistor | ⭐☆☆☆☆ |
| `L1-5_speed_control.ino` | L1.5 | Change blink speed | Same as L1.4 | ⭐☆☆☆☆ |
| `L1-SQ_morse_code.ino` | Side Quest | Morse code SOS | Same as L1.4 | ⭐⭐☆☆☆ |

### Level 2: Building Tasks

| File | Task ID | Description | Hardware Needed | Difficulty |
|------|---------|-------------|-----------------|------------|
| `L2-1_two_leds.ino` | L2.1 | Control 2 LEDs | 2 LEDs, 2 resistors | ⭐⭐☆☆☆ |
| `L2-2_three_leds.ino` | L2.2 | Control 3 LEDs | 3 LEDs, 3 resistors | ⭐⭐☆☆☆ |
| `L2-3_simple_sequence.ino` | L2.3 | Create sequence | Same as L2.2 | ⭐⭐☆☆☆ |
| `L2-4_uk_traffic_light.ino` | L2.4 | UK standard | Same as L2.2 | ⭐⭐☆☆☆ |
| `L2-5_with_defines.ino` | L2.5 | Clean code | Same as L2.2 | ⭐⭐☆☆☆ |
| `L2-SQ_serial_debug.ino` | Side Quest | Serial Monitor | Same as L2.2 | ⭐⭐☆☆☆ |

### Level 3: Integration Tasks

| File | Task ID | Description | Hardware Needed | Difficulty |
|------|---------|-------------|-----------------|------------|
| `L3-1_button_test.ino` | L3.1 | Button basics | Button, 1 LED | ⭐⭐☆☆☆ |
| `L3-2_button_toggle.ino` | L3.2 | Toggle logic | Same as L3.1 | ⭐⭐⭐☆☆ |
| `L3-3_five_leds.ino` | L3.3 | Add ped LEDs | 5 LEDs | ⭐⭐⭐☆☆ |
| `L3-5_millis_timing.ino` | L3.5 | Non-blocking | 3 LEDs | ⭐⭐⭐☆☆ |
| `L3-6_button_counter.ino` | L3.6 | Serial + button | Button only | ⭐⭐⭐☆☆ |
| `L3-7_complete_pedestrian.ino` | L3.7 | Full system | 5 LEDs + button | ⭐⭐⭐☆☆ |

### Advanced Tasks

| File | Task ID | Description | Hardware Needed | Difficulty |
|------|---------|-------------|-----------------|------------|
| `ADV-1_state_machine.ino` | ADV.1 | Professional FSM | 5 LEDs + button | ⭐⭐⭐⭐☆ |
| `ADV-2_with_functions.ino` | ADV.2 | Code organization | 3 LEDs | ⭐⭐⭐⭐☆ |
| `ADV-3_safety_checks.ino` | ADV.3 | Runtime verification | 5 LEDs | ⭐⭐⭐⭐☆ |

---

## 🎯 Learning Track Examples

### Speedrun Track
- **Goal:** Working traffic light in <5 minutes
- **File:** `TRACK-speedrun.ino`
- **Hardware:** 3 LEDs minimum
- **Lines:** 30 (minimal!)

### Button Mastery Track
- **Goal:** Learn buttons deeply, no traffic light needed
- **File:** `TRACK-button-only.ino`
- **Hardware:** 1 button + 1 LED
- **Includes:** 4 progressive stages in one file

### Theory-First Track
- **Goal:** Understand FSM theory before building
- **File:** `TRACK-theory-first.ino`
- **Hardware:** 3 LEDs (to see theory in action)
- **Includes:** Formal definitions and proofs

---

## 📊 Quick Reference Matrix

### By Hardware Requirements

**Have only Arduino:**
- `L1-1_arduino_test.ino` ✅

**Have 1 LED:**
- `L1-4_single_led_blink.ino`
- `L1-5_speed_control.ino`
- `L1-SQ_morse_code.ino`

**Have 2 LEDs:**
- `L2-1_two_leds.ino`

**Have 3 LEDs:**
- `L2-2_three_leds.ino`
- `L2-3_simple_sequence.ino`
- `L2-4_uk_traffic_light.ino`
- `L2-5_with_defines.ino`
- `L2-SQ_serial_debug.ino`
- `L3-5_millis_timing.ino`
- `ADV-2_with_functions.ino`
- `TRACK-speedrun.ino`
- `TRACK-theory-first.ino`

**Have 5 LEDs:**
- `L3-3_five_leds.ino`
- `ADV-3_safety_checks.ino`

**Have button + 1 LED:**
- `L3-1_button_test.ino`
- `L3-2_button_toggle.ino`
- `L3-6_button_counter.ino`
- `TRACK-button-only.ino`

**Have 5 LEDs + button (full system):**
- `L3-7_complete_pedestrian.ino`
- `ADV-1_state_machine.ino`

---

## 📚 By Concept Taught

### Basic I/O
- `L1-1_arduino_test.ino` - OUTPUT basics
- `L1-4_single_led_blink.ino` - digitalWrite
- `L3-1_button_test.ino` - digitalRead

### Timing
- `L1-5_speed_control.ino` - delay()
- `L3-5_millis_timing.ino` - millis()

### Sequences
- `L2-3_simple_sequence.ino` - Basic sequences
- `L2-4_uk_traffic_light.ino` - UK standard

### Code Organization
- `L2-5_with_defines.ino` - #define
- `ADV-2_with_functions.ino` - Functions
- `L1-SQ_morse_code.ino` - Helper functions

### Input Processing
- `L3-1_button_test.ino` - Basic input
- `L3-2_button_toggle.ino` - Edge detection
- `L3-6_button_counter.ino` - State tracking

### State Machines
- `L3-7_complete_pedestrian.ino` - Practical FSM
- `ADV-1_state_machine.ino` - Professional FSM
- `TRACK-theory-first.ino` - FSM theory

### Debugging
- `L2-SQ_serial_debug.ino` - Serial Monitor
- `L3-6_button_counter.ino` - Serial output

### Safety
- `ADV-3_safety_checks.ino` - Runtime verification

---

## 🎓 By Educational Level

### Complete Beginners
1. `L1-1_arduino_test.ino` - Prove it works
2. `L1-4_single_led_blink.ino` - First circuit
3. `L1-5_speed_control.ino` - Experiment
4. `L2-1_two_leds.ino` - Multiple outputs

### Intermediate
1. `L2-4_uk_traffic_light.ino` - Full traffic light
2. `L2-5_with_defines.ino` - Clean code
3. `L3-1_button_test.ino` - Add input
4. `L3-7_complete_pedestrian.ino` - Complete system

### Advanced
1. `L3-5_millis_timing.ino` - Non-blocking
2. `ADV-2_with_functions.ino` - Organization
3. `ADV-1_state_machine.ino` - Professional structure
4. `ADV-3_safety_checks.ino` - Verification

### Theory Students
1. `TRACK-theory-first.ino` - Read this first!
2. `ADV-1_state_machine.ino` - See theory applied
3. Then read `TRAFFIC_LIGHT_FSA_ANALYSIS.md`

---

## 🎯 By Learning Goal

### "I just want it working fast"
→ `TRACK-speedrun.ino` (5 minutes)

### "I want to learn buttons"
→ `TRACK-button-only.ino` (4 stages)

### "I want to understand theory"
→ `TRACK-theory-first.ino` (theory + code)

### "I want professional code"
→ `ADV-1_state_machine.ino` + `ADV-2_with_functions.ino`

### "School project (GCSE/BTEC)"
→ `L3-7_complete_pedestrian.ino` (full featured)

### "A-Level coursework"
→ `ADV-1_state_machine.ino` (FSM focus)

---

## 📝 Usage Notes

### How to Use These Examples

1. **Each file is standalone** - copy entire file to Arduino IDE
2. **Hardware requirements** listed at top of each file
3. **No dependencies** between files - use any order
4. **Comments explain WHY** not just what
5. **Challenges included** in many files

### File Naming Convention

- `L1-X` = Level 1, Task X
- `L2-X` = Level 2, Task X
- `L3-X` = Level 3, Task X
- `ADV-X` = Advanced, Task X
- `SQ` = Side Quest
- `TRACK-` = Special learning track

### Progressive Learning

Files build on each other conceptually, but you can:
- ✅ Jump to any file
- ✅ Skip files
- ✅ Use in any order
- ✅ Mix and match

### Troubleshooting

Each file includes:
- Clear hardware requirements
- Expected behavior
- Common problems
- Debugging hints

---

## 🔄 Version Compatibility

All examples work with:
- ✅ Arduino Uno R3
- ✅ Arduino Uno R4
- ✅ Arduino Mega
- ✅ Most Arduino-compatible boards
- ✅ Tinkercad Circuits simulator

---

## 📦 Complete Example List (Alphabetical)

```
examples/
├── ADV-1_state_machine.ino          Advanced state machine
├── ADV-2_with_functions.ino         Code organization
├── ADV-3_safety_checks.ino          Safety verification
├── L1-1_arduino_test.ino            Connection test
├── L1-4_single_led_blink.ino        First LED
├── L1-5_speed_control.ino           Timing practice
├── L1-SQ_morse_code.ino             Morse code patterns
├── L2-1_two_leds.ino                Two LEDs
├── L2-2_three_leds.ino              Three LEDs
├── L2-3_simple_sequence.ino         Basic sequence
├── L2-4_uk_traffic_light.ino        UK standard
├── L2-5_with_defines.ino            Clean code
├── L2-SQ_serial_debug.ino           Serial Monitor
├── L3-1_button_test.ino             Button basics
├── L3-2_button_toggle.ino           Toggle logic
├── L3-3_five_leds.ino               Pedestrian LEDs
├── L3-5_millis_timing.ino           Non-blocking timing
├── L3-6_button_counter.ino          Input + Serial
├── L3-7_complete_pedestrian.ino     Full system
├── TRACK-button-only.ino            Button mastery
├── TRACK-speedrun.ino               Quick start
└── TRACK-theory-first.ino           Theory to practice
```

**Total: 22 example files covering every learning path!**

---

## 🎯 Quick Decision Tree

```
What do you want?

Fast result → TRACK-speedrun.ino
Button skills → TRACK-button-only.ino
Understand theory → TRACK-theory-first.ino
Complete project → L3-7_complete_pedestrian.ino
Professional code → ADV-1_state_machine.ino
School assignment → L3-7 + ADV-1 + documentation
```

---

**Every quest task has example code. Every learning path is covered. No student left behind!** 🚀