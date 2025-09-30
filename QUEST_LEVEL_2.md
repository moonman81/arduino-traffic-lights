# Level 2: Traffic Lights

## What you're making

3 LEDs that work like real UK traffic lights.

Red → Red+Yellow → Green → Yellow → repeat

**Time:** 1 hour

---

## What you need

□ Arduino
□ 3 LEDs (red, yellow, green)
□ 3 Resistors
□ Wires
□ Breadboard

---

## Step 1: Wire the LEDs

**Do each LED the same way:**

1. Long leg → Resistor → Arduino pin
2. Short leg → GND

**Which pins:**
- Red LED → Pin 12
- Yellow LED → Pin 11
- Green LED → Pin 10

All short legs → Arduino GND

**Check:** 3 LEDs in breadboard. None lit. That's right.

---

## Step 2: Get the code

Open Arduino IDE.

**File** → **New**.

Click in this box. Press Ctrl+A (or Cmd+A on Mac). Press Ctrl+C (or Cmd+C):

```cpp
#define RED    12
#define YELLOW 11
#define GREEN  10

void setup() {
  pinMode(RED, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(GREEN, OUTPUT);
}

void loop() {
  digitalWrite(RED, HIGH);
  digitalWrite(YELLOW, LOW);
  digitalWrite(GREEN, LOW);
  delay(5000);

  digitalWrite(RED, HIGH);
  digitalWrite(YELLOW, HIGH);
  digitalWrite(GREEN, LOW);
  delay(2000);

  digitalWrite(RED, LOW);
  digitalWrite(YELLOW, LOW);
  digitalWrite(GREEN, HIGH);
  delay(6000);

  digitalWrite(RED, LOW);
  digitalWrite(YELLOW, HIGH);
  digitalWrite(GREEN, LOW);
  delay(3000);
}
```

Paste into Arduino IDE (Ctrl+V or Cmd+V).

---

## Step 3: Upload

**□** **Tools** → **Board** → **Arduino Uno**

**□** **Tools** → **Port** → Pick one with "Arduino" or "COM" or "USB"

**□** Click → arrow (Upload button)

**□** Wait for "Done uploading"

---

## Step 4: Watch

**What happens:**

1. RED (5 seconds)
2. RED + YELLOW (2 seconds)
3. GREEN (6 seconds)
4. YELLOW (3 seconds)
5. Repeats

Use your phone timer to check.

---

## ✓ Success

Working? You did it.

---

## Not working?

### Only 1 LED works:

**□ Try 1:** Check each LED long leg goes to its pin (12, 11, or 10)

**□ Try 2:** Check all short legs go to GND

**□ Try 3:** Push all wires firmly

**□ Try 4:** Upload code again

### Wrong pattern:

**□ Try 1:** Delete all code. Paste from Step 2 again. Upload.

**□ Try 2:** Check every line ends with semicolon (;)

### Timing wrong:

In the code:
- 5000 = 5 seconds
- 2000 = 2 seconds
- 6000 = 6 seconds
- 3000 = 3 seconds

Count them. Make sure they're right.

---

## What next

**Ready for button?**

**→ [Level 3](QUEST_LEVEL_3.md)** - Add pedestrian crossing

**Want more practice?**

Change the 5000 to 10000. Makes red last 10 seconds instead of 5.

Upload and test.

---

## You're doing great

You just controlled 3 things at once with timing.

Same as real traffic lights.