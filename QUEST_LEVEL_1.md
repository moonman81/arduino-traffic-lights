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

## The steps

Follow these in order. Don't skip any.

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

## Step 3: Get the code

Open Arduino IDE.

Click **File** → **New**.

Now select ALL this code (click it, press Ctrl+A or Cmd+A):

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

Copy it (Ctrl+C or Cmd+C).

Paste it into Arduino IDE (Ctrl+V or Cmd+V).

**That's it.** Don't type it. Just copy and paste.

---

## Step 4: Upload to Arduino

**Do exactly this:**

**□ Step 4a:** Click **Tools** at the top

**□ Step 4b:** Click **Board** → **Arduino Uno**

**□ Step 4c:** Click **Tools** again

**□ Step 4d:** Click **Port** → Pick the one that says "Arduino" or "USB" or "COM"

**□ Step 4e:** Look for the → arrow button (top left)

**□ Step 4f:** Click the → arrow button

**□ Step 4g:** Watch the bottom. Wait until it says "Done uploading"

---

### If it says "Port not found":

Do these in order until it works:

**□ Try 1:** Unplug USB cable. Plug it back in. Try upload again.

**□ Try 2:** Use a different USB cable.

**□ Try 3:** Plug into different USB port on computer.

**□ Try 4:** Close Arduino IDE completely. Unplug Arduino. Plug Arduino back in. Open Arduino IDE. Try again.

One of these WILL work.

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

## If LED not working

**Try these in order. Stop when it works:**

### Try 1: Check the legs
- Long LED leg goes to Pin 13 side? ✓
- Short LED leg goes to GND side? ✓
- Fix it if wrong. Upload code again (press → arrow).

### Try 2: Push wires
- Push every wire firmly into Arduino
- Push every wire firmly into breadboard
- Upload code again (press → arrow).

### Try 3: Reset button
- Find the small button on Arduino board
- Press it once
- LED should start blinking

### Try 4: Different LED
- Take out the LED
- Put in a different LED (any colour)
- Upload code again (press → arrow).

### Try 5: Check code
- Look at your code
- Does every line have a semicolon (;) at the end?
- Delete everything and paste the code again (from Step 3)
- Upload (press → arrow).

**One of these fixes it. Guaranteed.**

---

### LED very dim?
That's fine. It's working. Some resistors make LEDs dimmer. No problem.

---

## Done

LED blinking? You did it.

**What next:**
- **[Level 2](QUEST_LEVEL_2.md)** - Traffic lights
- **[Level 3](QUEST_LEVEL_3.md)** - Full system with button

---

## Still not working?

**If you tried all 5 fixes and LED still doesn't work:**

Your hardware might be faulty. This happens sometimes.

**Options:**
- Ask someone who knows Arduino for help
- Try a different Arduino board
- Try a different LED and resistor

Not your fault. Sometimes components are broken.

---
