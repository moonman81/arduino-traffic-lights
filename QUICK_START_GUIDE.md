# Quick Start Guide

## Purpose

This guide helps you quickly find the right starting point based on your experience and available time.

**If you're unsure where to start**, use the decision tree at the bottom of this page.

**If you know your level**, jump directly to the appropriate section below.

---

## Three Main Levels

Each level is a complete working project. You can start at any level based on your experience.

---

## 🟢 **Level 1: Beginner** - Never used Arduino before

**Time:** 5-10 minutes
**What you build:** One blinking LED

**Start here:**
1. Read `BEGINNER_BUILD_GUIDE.md` - Part 1 & 2
2. Upload `arduino-code/traffic-light-level1-single-led.ino`
3. Watch your LED blink!

**Hardware needed:**
- Arduino Uno
- 1 LED
- 1 resistor
- 2 wires

---

## 🟡 **Level 2: Intermediate** - Used Arduino once or twice

**Time:** 30-45 minutes
**What you build:** Complete 3-LED traffic light

**Start here:**
1. Read `BEGINNER_BUILD_GUIDE.md` - Level 2 section
2. Build circuit with 3 LEDs
3. Upload `arduino-code/traffic-light-level2-basic.ino`
4. Watch UK traffic light sequence!

**Hardware needed:**
- Arduino Uno
- 3 LEDs (red, amber, green)
- 3 resistors
- Breadboard and wires

---

## 🔴 **Level 3: Advanced** - Comfortable with Arduino

**Time:** 1-2 hours
**What you build:** Full traffic system with pedestrian crossing

**Two options:**

### Option A: Simple but complete
1. Read `BEGINNER_BUILD_GUIDE.md` - Level 3 section
2. Build complete circuit (5 LEDs + button)
3. Upload `arduino-code/traffic-light-level3-pedestrian-simple.ino`

### Option B: Professional with safety verification
1. Same hardware as Option A
2. Upload `arduino-code/traffic-lights-arduino-clean.c`
3. Read `documentation/TRAFFIC_LIGHT_FSA_ANALYSIS.md` to understand theory

**Hardware needed:**
- Arduino Uno
- 5 LEDs (3 traffic + 2 pedestrian)
- 5 resistors
- 1 push button
- Breadboard and wires

---

## 📚 Complete Documentation

| Document | Purpose | Difficulty |
|----------|---------|------------|
| `BEGINNER_BUILD_GUIDE.md` | Step-by-step for beginners | 🟢 Easy |
| `WIRING_INSTRUCTIONS.md` | Circuit diagrams and wiring | 🟡 Medium |
| `TRAFFIC_LIGHT_FSA_ANALYSIS.md` | State machine theory | 🔴 Advanced |
| `ONTOLOGICAL_ANALYSIS_TRAFFIC_SYSTEM.md` | Philosophy and formal verification | 🔴 Academic |

---

## 🎯 Learning Path

### Complete Beginner Path:
```
Level 1 (1 LED)
    ↓
Level 2 (3 LEDs)
    ↓
Level 3 Option A (Simple complete system)
    ↓
Level 3 Option B (Professional system)
```

### Experienced Path:
```
Start at Level 2 → Level 3 Option B → Read theory docs
```

### Academic Study Path:
```
Level 3 Option B → FSA Analysis → Ontological Analysis → Explore formal proofs
```

---

## 💡 Quick Tips

**Starting out?**
- Use Tinkercad Circuits first (free online simulator)
- No hardware needed to test!
- Safe to make mistakes

**Building physical circuit?**
- Double-check LED polarity (long leg = positive)
- Use 220Ω or 330Ω resistors
- Connect firmly into breadboard

**Code not uploading?**
- Check correct board selected (Tools → Board → Arduino Uno)
- Check correct port selected (Tools → Port)
- Try unplugging and replugging USB

**Want debugging info?**
- Open Serial Monitor (Tools → Serial Monitor)
- Set baud rate to 9600
- Watch messages appear as system runs

---

## 🆘 Need Help?

1. **Check troubleshooting** in `BEGINNER_BUILD_GUIDE.md` Part 6
2. **Compare your circuit** to the wiring diagrams
3. **Test with Level 1** first to verify basics work
4. **Read error messages** carefully - they usually explain the problem

---

## 🎓 What You'll Learn

By completing all three levels, you'll understand:

- ✅ Digital input/output
- ✅ LED circuits and current limiting
- ✅ Timing and delays
- ✅ State machines
- ✅ Button debouncing
- ✅ Safety-critical system design

**These skills apply to:**
- Robotics
- Home automation
- Industrial control
- Game development
- Embedded systems

---

## Next Steps After Completing

1. **Modify the code** - make it your own!
2. **Add features** - buzzers, LCD display, sensors
3. **Build two intersections** - coordinate two traffic lights
4. **Study the theory** - FSA analysis and formal verification
5. **Share your project** - help others learn!

---

Ready to start? Open `BEGINNER_BUILD_GUIDE.md` and begin with Level 1!