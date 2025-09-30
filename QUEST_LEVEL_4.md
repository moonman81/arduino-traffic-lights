# Level 4: Make It Safe

## What you'll do

Take your working traffic light and add safety checks.

Make it detect when something goes wrong.

**Time:** 45 minutes

**You need:**
- Completed Level 3 (working traffic light)

---

## Why this matters

Your Level 3 traffic light works.

But working ≠ safe.

Real traffic lights check for errors constantly. Like:
- Are both pedestrian green AND traffic green on? (Dangerous!)
- Did green go straight to red without yellow? (Breaking rules!)

You'll add these checks.

---

## The steps

### Step 1: Copy your code

Open: `arduino-code/examples/L3-7b_full_features.ino`

**File** → **Save As** → Name it: `my_safe_traffic_light.ino`

**Check:** New file open in Arduino IDE.

---

### Step 2: Add first safety check

Find this line in your code:
```cpp
void loop() {
```

Right AFTER the `checkButton();` line, add this:

```cpp
  // Safety check 1: Mutual exclusion
  bool trafficGreen = digitalRead(GREEN_TRAFFIC);
  bool pedGreen = digitalRead(GREEN_PED);

  if (trafficGreen && pedGreen) {
    Serial.println("!!! DANGER: Both greens on at same time !!!");
  }
```

Copy and paste it. Don't type.

**Check:** Code compiles (click ✓ button). No errors.

---

### Step 3: Upload and test

Upload to Arduino.

Open Serial Monitor.

Watch it run. You should NOT see the danger message.

**Why?** Because your code is safe. The check proves it.

---

### Step 4: Break it on purpose

Find this line:
```cpp
    case STATE_PED_CROSS:
      setTrafficLights(HIGH, LOW, LOW);    // Traffic RED (safe!)
      setPedestrianLights(LOW, HIGH);      // Pedestrian GREEN
```

Change the first line to:
```cpp
      setTrafficLights(LOW, LOW, HIGH);    // Traffic GREEN (DANGER!)
```

Upload again.

**Watch Serial Monitor:** You should see "!!! DANGER: Both greens on at same time !!!"

**Check:** Safety system caught the bug!

---

### Step 5: Fix it back

Change that line back to:
```cpp
      setTrafficLights(HIGH, LOW, LOW);    // Traffic RED (safe!)
```

Upload. Danger message should disappear.

**Check:** Back to safe operation.

---

### Step 6: Add it as a function

At the bottom of your code (before the final `}`), add:

```cpp
bool verifySafety() {
  // Check 1: Traffic green and pedestrian green never together
  bool trafficGreen = digitalRead(GREEN_TRAFFIC);
  bool pedGreen = digitalRead(GREEN_PED);

  if (trafficGreen && pedGreen) {
    Serial.println("!!! SAFETY VIOLATION: Mutual exclusion failed !!!");
    return false;
  }

  return true;  // All checks passed
}
```

Now in `loop()`, replace your safety check code with:

```cpp
  // Run safety checks
  if (!verifySafety()) {
    // Safety failed - could go to emergency safe state here
  }
```

Upload and test.

**Check:** Works the same, but now organized as a function.

---

## What you built

You added a **safety verification layer**.

This is different from your state machine code.

**State machine:** Makes lights change
**Safety layer:** Checks if changes are safe

The safety layer sits ABOVE the state machine. It watches everything.

This is called **separation of concerns**.

---

## Done

You now have:
- Working traffic light (Level 3)
- Safety checks watching it (Level 4)

This is how real critical systems work.

**What next:**
- Show your tutor the safety function
- Explain what "mutual exclusion" means (two things can't be on together)

---

## Still not working?

**Safety check never triggers:**
- That's good! It means your code is safe.
- Try breaking it on purpose (Step 4) to test the check works.

**Code won't compile:**
- Check you pasted the safety function BEFORE the final `}`
- Count your curly braces { } - must be balanced

**Can't find where to add code:**
- Look for `void loop() {` - add after `checkButton();`
- Look for the very end of file - add function before last `}`