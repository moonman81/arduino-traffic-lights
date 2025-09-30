# Level 3: Add Pedestrian Button

## What you'll build

Complete traffic light with pedestrian crossing.

**Press button → Pedestrian gets green light → Cars stop**

**Time:** 2-3 hours (take breaks!)

**You need:**
- Did Level 2? You're ready.
- Never did Level 2? Do that first, it's easier.

---

## What you need

**Check you have:**

□ Everything from Level 2 (3 traffic LEDs)
□ 2 more LEDs (for pedestrian lights)
□ 2 more resistors
□ 1 button
□ More wires

**Total: 5 LEDs + 1 button**

---

## The idea

**Normal traffic lights:**
- Red → Red+Yellow → Green → Yellow → repeat

**With button pressed:**
- Normal cycle continues
- THEN when it gets to Yellow
- Goes to Pedestrian Green instead of Red
- Pedestrian gets 8 seconds to cross
- Then back to Red for traffic

**Important:** Pedestrian has to wait for safe time. Can't interrupt immediately.

---

## Which code to use

**Use this file:** `L3-7b_full_features.ino`

Find it in: `arduino-code/examples/`

**Why this one?** It has everything and is well explained.

---

## The steps

### Step 1: Add the 2 pedestrian LEDs

Same as Level 2, but 2 more LEDs:

**Pedestrian LEDs:**
- Red pedestrian → Pin 9
- Green pedestrian → Pin 8

Same wiring: Long leg → resistor → pin, Short leg → GND

**Check:** Now you have 5 LEDs total, none lit yet.

---

### Step 2: Add the button

**Button wiring:**
- One side → Pin 13
- Other side → GND

**That's it.** Buttons are simple.

**Check:** Button is wired, you can press it (does nothing yet, that's right).

---

### Step 3: Copy the code

Open file: `arduino-code/examples/L3-7b_full_features.ino`

Copy ALL of it into Arduino IDE.

**Don't type it.** Copy and paste. It's long (200 lines).

**Check:** Code is in Arduino IDE.

---

### Step 4: Upload it

1. **Tools** → **Board** → **Arduino Uno**
2. **Tools** → **Port** → Pick your Arduino
3. Click **Upload** (→ arrow)
4. Wait for "Done uploading"

---

### Step 5: Open Serial Monitor

**Tools** → **Serial Monitor**

Check bottom right says **9600 baud**

You should see messages like:
```
State: RED
State: RED+YELLOW
State: GREEN
```

This shows what's happening.

---

### Step 6: Test the button

**Watch the Serial Monitor.**

1. Wait for "State: GREEN"
2. Press the button
3. You should see ">>> Button pressed! Pedestrian waiting..."
4. Wait - it won't happen immediately
5. After traffic goes to Yellow
6. Then "State: PEDESTRIAN CROSSING"
7. Pedestrian green LED lights up!

**Check:** Button works, pedestrian gets green light.

---

## ✅ Success!

**It's working?** You built a complete embedded system!

**This is coursework-level work.** GCSE, BTEC, A-Level suitable.

---

## Something wrong?

### Button does nothing:
- Check button wired to Pin 13 and GND
- Check Serial Monitor shows button press
- Try a different button

### Pedestrian never gets green:
- Did you wait for the traffic cycle to finish?
- Check Serial Monitor messages
- Pedestrian has to wait for safe time (3 seconds minimum green)

### Serial Monitor shows gibberish:
- Check baud rate is 9600 (bottom right)

### LEDs in wrong pattern:
- Check pin numbers in wiring match code
- Pin 12=Red traffic, 11=Yellow, 10=Green, 9=Red ped, 8=Green ped

### Still not working?

**If you tried everything and it still doesn't work:**

Your hardware might be faulty.

**Options:**
- Ask someone who knows Arduino for help
- Try different components
- Check the code file is correct version

Not your fault. Sometimes things break.

---

## You did it

You built a complete traffic light system with button.

This is real embedded systems work.

**Many people never get this far. You did it.**

**What next:**
- Show your tutor (read [TUTOR_GUIDE.md](TUTOR_GUIDE.md) first)
- **[Level 4](QUEST_LEVEL_4.md)** - Add safety checks (advanced)