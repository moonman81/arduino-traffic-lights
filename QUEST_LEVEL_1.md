# Level 1: Make One LED Blink

## What you'll do

Make one LED turn on and off.

That's it. Just one light blinking.

**Time:** 10-15 minutes

**You need:**
- Arduino
- 1× LED (any colour)
- 1× Resistor
- 2× Wires
- USB cable

---

## Why start here?

This is the easiest Arduino project.

If you can make one LED blink, you can control anything - traffic lights, robots, displays, everything.

Every Arduino project starts here.

---

## The steps

Follow these in order. Don't skip any.

---

## 🎒 Required Inventory

### Minimum (Hardware):
- [ ] 1× Arduino Uno R3
- [ ] 1× LED (any color, but red is traditional)
- [ ] 1× Resistor (220Ω or 330Ω)
- [ ] 2× Jumper wires
- [ ] 1× Breadboard (optional but recommended)
- [ ] 1× USB cable
- [ ] 1× Computer

### Minimum (Software):
- [ ] Arduino IDE installed (free from arduino.cc)

**Don't have hardware?** → Try **Tinkercad Circuits** (tinkercad.com/circuits) instead - free online simulator!

---

## Step 1: Get everything ready

**Do this:**
1. Plug Arduino into computer with USB cable
2. Open Arduino IDE on computer
3. Put components on desk

**Check:** Small LED on Arduino board should light up when plugged in ✅

---

## Step 2: Connect the wires

### First: Which leg is which?

**Look at your LED:**
- LONG leg = Positive ✅
- SHORT leg = Negative (ground) ❌

Can't tell? Look for the flat edge on the LED plastic = that's the negative side.

---

### Now connect it:

**1. Put LED in breadboard**
- Long leg goes in one hole
- Short leg goes in hole next to it

**2. Add the resistor**
- One end connects to LED long leg (same row)
- Other end in a different row

**3. Connect wire from Arduino Pin 13**
- Goes to the resistor

**4. Connect wire from Arduino GND**
- Goes to LED short leg

**Check:** LED not lit yet? That's correct! It will light up after we add code.

---

### Not sure about wiring?

See [BEGINNER_BUILD_GUIDE.md](BEGINNER_BUILD_GUIDE.md) for pictures and detailed wiring.

---

## Step 3: Write the code

Open Arduino IDE and copy this code:

```cpp
void setup() {
  pinMode(13, OUTPUT);
}

void loop() {
  digitalWrite(13, HIGH);
  delay(1000);

  digitalWrite(13, LOW);
  delay(1000);
}
```

**What this does:**
- `pinMode(13, OUTPUT)` = Pin 13 will control the LED
- `digitalWrite(13, HIGH)` = Turn LED ON
- `delay(1000)` = Wait 1 second
- `digitalWrite(13, LOW)` = Turn LED OFF
- Then it repeats forever

**Don't understand it?** That's okay. Just copy it exactly and it will work.

---

## Step 4: Upload to Arduino

**Do this:**

1. Click **Tools** → **Board** → **Arduino Uno**

2. Click **Tools** → **Port** → Pick the one with your Arduino

3. Click the **Upload button** (→ arrow at top)

4. Wait for "Done uploading"

---

### Error: "Port not found"?

**Try these:**
- Check USB cable is plugged in properly
- Try a different USB cable (some only charge, they don't send data)
- Try a different USB port on your computer

---

## Step 5: Watch it work!

**What happens:**
- LED turns ON
- Waits 1 second
- LED turns OFF
- Waits 1 second
- Repeats forever

---

## ✅ Success!

**Your LED is blinking?** You did it!

This is the foundation of everything in Arduino.

---

## Something not working?

### LED doesn't light at all:
1. Check the long leg goes to Pin 13 side
2. Push wires in firmly
3. Press the reset button on Arduino

### LED stays on forever:
1. Check your code matches exactly
2. Look for missing semicolons (;)
3. Upload the code again

### LED is very dim:
That's fine! It still counts as working.

---

## What you learned

You now know:
- How to connect wires to Arduino
- How to upload code
- How `pinMode` and `digitalWrite` work
- How to make something turn on and off

**This is real programming.** You're controlling hardware with code you wrote.

---

## 🎮 Side Quests (Optional Challenges)

Try these modifications to earn bonus experience:

### Side Quest 1: Speed Control ⚡
**Challenge:** Make it blink faster
**Hint:** Change `delay(1000)` to `delay(500)` (half second)
**Reward:** Understanding of timing

### Side Quest 2: Morse Code 📡
**Challenge:** Blink "SOS" in Morse code (···−−−···)
**Hint:** Short blink = 200ms, long blink = 600ms
**Reward:** Pattern recognition skill

### Side Quest 3: Different Pin 🔌
**Challenge:** Make it work on Pin 12 instead of Pin 13
**Hint:** Change all `13` to `12` in code (and move wire!)
**Reward:** Understanding pin flexibility

### Side Quest 4: Heartbeat 💓
**Challenge:** Make it "pulse" like a heartbeat (two quick blinks, pause)
**Hint:** ON-OFF-ON-OFF-long pause
**Reward:** Creative thinking skill

---

## 📊 Progress Report

**Level 1 Status:** COMPLETE ✅

**Skills Acquired:**
- Basic circuit building
- LED control
- Arduino programming fundamentals
- Upload process

**Ready for Next Level?** Check your skills:
- [ ] Can you change the blink speed?
- [ ] Do you understand why the resistor is needed?
- [ ] Could you add a second LED on a different pin?

**If you answered YES to 2 or more → You're ready for Level 2!**

---

## What next?

### Ready for Level 2?
**→ [Level 2: Traffic Light](QUEST_LEVEL_2.md)**

You'll make 3 LEDs work like real traffic lights.

---

### Want to skip to the full project?
**→ [Level 3: Complete System](QUEST_LEVEL_3.md)**

This is the full traffic light with button.

---

### Want a break?
That's fine! You did something real today.

Take a photo of your circuit so you can rebuild it later.

---

## You should feel good about this

**You just:**
- Built a circuit
- Wrote code
- Made hardware respond to your commands

Many people never get this far. You did it.

---

## 🆘 Got Stuck? Respawn Points:

**Problem:** LED doesn't light at all
**→ [Troubleshooting Guide](BEGINNER_BUILD_GUIDE.md#troubleshooting)**

**Problem:** Upload error
**→ Check board and port settings in Tools menu**

**Problem:** LED very dim
**→ That's okay! Still working. Resistor might be higher value.**

**Problem:** Code won't compile
**→ Check for typos, missing semicolons, matching brackets**

**Need more help?**
**→ [Return to Quest Hub](QUEST_START.md)**
**→ [Full Tutorial](BEGINNER_BUILD_GUIDE.md)**

---

## 🎯 Level 1 Complete!

**Congratulations, brave builder!** You've taken your first step into the world of Arduino. The LED blinks because YOU made it happen. That's real magic.

**Ready to level up?**

**→ [Continue to Level 2: The Traffic Light Challenge](QUEST_LEVEL_2.md)**

Or return to **[Quest Hub](QUEST_START.md)** to choose a different path.

---

*Quest Progress: ■□□□□ Level 1 Complete!*