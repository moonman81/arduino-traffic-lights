# Code Version Guide

## Purpose

This project includes multiple code files, each serving different learning goals and skill levels. This guide helps you choose which file to use.

**Quick answer for most students:** Use `traffic-light-level3-pedestrian-simple.ino` - it has all features and is designed for learning.

**For detailed comparison**, see tables below.

---

## 📊 Quick Comparison Table

| File | Lines | Difficulty | Features | Best For |
|------|-------|------------|----------|----------|
| `traffic-light-level1-single-led.ino` | 30 | 🟢 Easiest | 1 blinking LED | First-time Arduino users |
| `traffic-light-level2-basic.ino` | 60 | 🟢 Easy | 3-LED traffic light | Learning sequences |
| `traffic-light-level3-pedestrian-simple.ino` | 200 | 🟡 Medium | Full system, simplified | Most students |
| `traffic-lights-arduino-clean.c` | 460 | 🔴 Advanced | Professional, verified | Advanced learners |
| `traffic-lights-arduino-optimized-final.c` | 600+ | 🔴 Expert | All features + docs | Academic study |

---

## 🎯 Detailed Breakdown

### Level 1: Single LED (`traffic-light-level1-single-led.ino`)

**What it does:** Makes one LED blink on and off

**Code complexity:** Minimal - perfect first program

**Concepts taught:**
- `pinMode()` - setting up pins
- `digitalWrite()` - turning things on/off
- `delay()` - waiting

**Use this if:**
- You've never programmed Arduino before
- You want to verify your setup works
- You're teaching absolute beginners

**Example:**
```cpp
void loop() {
  digitalWrite(13, HIGH);  // LED on
  delay(1000);             // Wait 1 second
  digitalWrite(13, LOW);   // LED off
  delay(1000);             // Wait 1 second
}
```

---

### Level 2: Basic Traffic Light (`traffic-light-level2-basic.ino`)

**What it does:** Complete UK traffic light sequence with 3 LEDs

**Code complexity:** Simple but complete

**Concepts taught:**
- Controlling multiple outputs
- Creating sequences
- UK traffic light patterns
- `#define` for readable code

**Use this if:**
- You've done basic Arduino tutorials
- You want a working traffic light quickly
- You don't need pedestrian crossing yet

**Sequence:**
```
RED (5s) → RED+AMBER (2s) → GREEN (6s) → AMBER (3s) → repeat
```

---

### Level 3: Pedestrian Crossing - Simple (`traffic-light-level3-pedestrian-simple.ino`)

**What it does:** Complete traffic system with pedestrian button

**Code complexity:** Moderate - well-commented

**Concepts taught:**
- Reading button input
- Timing with `millis()`
- Boolean flags
- State management
- Serial debugging
- Safety considerations (minimum green time)

**Use this if:**
- You want the full project
- You want to understand how it works
- You're a student learning embedded systems
- You prefer readable code over theoretical perfection

**Features:**
- ✅ UK traffic light sequence
- ✅ Pedestrian button
- ✅ Pedestrian lights
- ✅ Fair timing (3s minimum green)
- ✅ Serial debugging messages
- ✅ Extensive comments
- ✅ Challenge ideas included

**This is the recommended version for most students!**

---

### Advanced: Clean Professional (`traffic-lights-arduino-clean.c`)

**What it does:** Same as Level 3 but with professional structure

**Code complexity:** Advanced - industry-style

**Concepts taught:**
- Function decomposition
- Safety invariants
- Verification functions
- Professional documentation
- Defensive programming

**Use this if:**
- You're comfortable with C programming
- You want to see professional embedded code
- You're interested in safety-critical systems
- You want to study formal verification concepts

**Additional features over Level 3:**
- ✅ Safety verification functions
- ✅ Mutual exclusion checking
- ✅ Progressive warning verification
- ✅ Minimum time guarantee checking
- ✅ Error handling and recovery
- ✅ Structured state machine
- ✅ Extensive philosophical documentation

**Warning:** More complex to understand - read Level 3 first!

---

### Expert: Full Featured (`traffic-lights-arduino-optimized-final.c`)

**What it does:** Everything plus academic documentation

**Code complexity:** Expert - for study and research

**Concepts taught:**
- Formal verification
- Ontological analysis
- Requirements engineering
- Safety proofs

**Use this if:**
- You're doing academic research
- You want to study formal methods
- You're interested in philosophy of technology
- You're comparing different safety approaches

**Additional features:**
- ✅ Complete ontological annotations
- ✅ Formal safety proofs in comments
- ✅ Philosophical foundations
- ✅ Requirements traceability
- ✅ Temporal logic properties
- ✅ Complete academic documentation

**This is overkill for learning Arduino!** Use for reference only.

---

### Old Versions (Historical Interest)

These are kept for reference but not recommended for learning:

- `traffic-lights-arduino-uno-r3.c` - Original simple version
- `traffic-lights-arduino-uno-r3-uk.c` - Early UK implementation
- `traffic-lights-arduino-uno-r3-optimized.c` - Development version

---

## 🛣️ Recommended Learning Path

### Path 1: Complete Beginner
```
Level 1 (single LED)
    ↓
Level 2 (basic traffic)
    ↓
Level 3 Simple (pedestrian)
    ↓
Done! ✓
```

### Path 2: Some Experience
```
Level 2 (basic traffic)
    ↓
Level 3 Simple (pedestrian)
    ↓
Read the Clean version
    ↓
Done! ✓
```

### Path 3: Advanced Study
```
Level 3 Simple (pedestrian)
    ↓
Clean version (professional)
    ↓
Read FSA Analysis
    ↓
Study Ontological Analysis
    ↓
Compare with Full Featured version
```

---

## 📝 Feature Comparison

| Feature | Level 1 | Level 2 | Level 3 Simple | Clean | Full Featured |
|---------|---------|---------|----------------|-------|---------------|
| Blinking LED | ✅ | | | | |
| Traffic lights | | ✅ | ✅ | ✅ | ✅ |
| UK standard | | ✅ | ✅ | ✅ | ✅ |
| Pedestrian button | | | ✅ | ✅ | ✅ |
| Pedestrian lights | | | ✅ | ✅ | ✅ |
| Serial debug | | | ✅ | ✅ | ✅ |
| Safety checks | | | Basic | ✅ | ✅ |
| Formal verification | | | | ✅ | ✅ |
| Ontological docs | | | | | ✅ |
| Beginner-friendly | ✅ | ✅ | ✅ | | |
| Professional structure | | | | ✅ | ✅ |
| Academic research | | | | | ✅ |

---

## 🎓 Code Complexity Metrics

### Level 1: Single LED
- **Lines of code:** ~30
- **Functions:** 2 (setup, loop)
- **Variables:** 0
- **Concepts:** 3
- **Reading time:** 2 minutes

### Level 2: Basic Traffic
- **Lines of code:** ~60
- **Functions:** 2 (setup, loop)
- **Variables:** 0
- **Concepts:** 5
- **Reading time:** 5 minutes

### Level 3: Simple Pedestrian
- **Lines of code:** ~200
- **Functions:** 5
- **Variables:** 2
- **Concepts:** 10
- **Reading time:** 15 minutes

### Clean Professional
- **Lines of code:** ~460
- **Functions:** 10+
- **Variables:** 5
- **Concepts:** 20+
- **Reading time:** 45 minutes

### Full Featured
- **Lines of code:** 600+
- **Functions:** 15+
- **Variables:** 8+
- **Concepts:** 30+
- **Reading time:** 2+ hours

---

## 💡 Which Should You Use?

### "I've never used Arduino"
→ **Level 1**, then **Level 2**

### "I want a working traffic light quickly"
→ **Level 2**

### "I want the full project for a class assignment"
→ **Level 3 Simple** (most student-friendly!)

### "I want to understand professional embedded code"
→ **Clean version** (after doing Level 3)

### "I'm doing academic research on formal methods"
→ **Full Featured** (for reference and comparison)

### "I'm teaching a class"
→ Start with **Level 1**, progress through all three levels

---

## 🔄 Upgrading Between Versions

You can progress through versions on the **same hardware**:

1. Build circuit for Level 1 (1 LED)
2. Upload Level 1 code → test
3. Add 2 more LEDs
4. Upload Level 2 code → test
5. Add 2 pedestrian LEDs + button
6. Upload Level 3 Simple → test
7. Upload Clean version → compare behavior
8. Study the differences in code structure

Same hardware, increasingly sophisticated code!

---

## 🎯 Pedagogical Purpose

Each version serves a specific teaching goal:

- **Level 1:** Confidence building - "I can make it work!"
- **Level 2:** Pattern learning - "I understand sequences!"
- **Level 3 Simple:** Integration - "I can combine inputs and outputs!"
- **Clean:** Professionalization - "I can write quality code!"
- **Full Featured:** Specialization - "I can study advanced topics!"

---

## 📚 Supporting Documents

Each code version is supported by documentation:

| Code Version | Read This Document |
|--------------|-------------------|
| Levels 1-3 | `BEGINNER_BUILD_GUIDE.md` |
| All versions | `WIRING_INSTRUCTIONS.md` |
| Clean & Full | `TRAFFIC_LIGHT_FSA_ANALYSIS.md` |
| Full Featured | `ONTOLOGICAL_ANALYSIS_TRAFFIC_SYSTEM.md` |

---

## ✅ Quick Decision Tree

```
Are you brand new to Arduino?
    YES → Level 1
    NO ↓

Do you just want a basic traffic light?
    YES → Level 2
    NO ↓

Do you want pedestrian crossing?
    YES ↓

    Do you prioritize understanding the code?
        YES → Level 3 Simple ← MOST STUDENTS CHOOSE THIS
        NO → Clean version

Are you doing academic research?
    YES → Full Featured
    NO → You probably want Level 3 Simple!
```

---

**Bottom line:** Most students should use **Level 3 Simple** (`traffic-light-level3-pedestrian-simple.ino`). It has all the features, is well-commented, and designed specifically for learning.

The other versions exist for progression (Levels 1-2) and advanced study (Clean, Full Featured).