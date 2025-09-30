# Troubleshooting Guide

## Common Problems and Solutions

This guide covers the most common issues encountered when building the Arduino traffic light project.

---

## Hardware Problems

### LED Not Lighting

**Symptoms:** LED stays off when it should be on

**Solutions:**
1. **Check polarity** - Long leg (anode) should go to resistor side, short leg to GND
2. **Try different LED** - LED might be broken
3. **Check resistor** - Should be 220-330Ω, not 10kΩ
4. **Check connections** - Wires firmly inserted?
5. **Test LED directly** - Connect to 5V with resistor to test

---

### LED Very Dim

**Symptoms:** LED lights up but barely visible

**Solutions:**
1. **Check resistor value** - Higher resistance = dimmer LED
2. **This is often normal** - Still counts as working!
3. **Try lower resistor** - 220Ω instead of 330Ω (both safe)

---

### Multiple LEDs On When Shouldn't Be

**Symptoms:** More than one LED lit at same time incorrectly

**Solutions:**
1. **Check for wire shorts** - Wires touching that shouldn't be?
2. **Verify cathode connections** - All short legs to GND?
3. **Check pin assignments** - Code pins match physical wiring?
4. **Test one LED at a time** - Disconnect others to isolate

---

### Button Not Working

**Symptoms:** Pressing button does nothing

**Solutions:**
1. **Check wiring** - One side to pin 13, other to GND?
2. **Verify INPUT_PULLUP** - Code should use INPUT_PULLUP mode
3. **Test button** - Use multimeter or swap with known-good button
4. **Check for debounce** - Need delay after button read
5. **Print button state** - Use Serial.println() to see if button read correctly

---

### Erratic Behavior / Random Lights

**Symptoms:** Lights flash randomly, unpredictable behavior

**Solutions:**
1. **Check power** - USB cable fully inserted?
2. **Verify breadboard connections** - Push components in firmly
3. **Check for loose wires** - Jiggle test each wire
4. **Look for shorts** - Adjacent breadboard rows touching?
5. **Try fresh breadboard** - Older breadboards can have worn contacts

---

## Software Problems

### Code Won't Compile

**Symptoms:** Error messages when trying to upload

**Common errors:**

**"expected ';' before ..."**
- Missing semicolon on previous line
- Check every line ends with ;

**"variable not declared"**
- Typo in variable name?
- Did you #define the pin?
- Variable out of scope?

**"multiple definition of loop"**
- Two loop() functions in code
- Commented out old code properly?

---

### Code Won't Upload

**Symptoms:** Upload fails with error

**Solutions:**

**"Port not found" or "Access denied"**
1. Check USB cable is data cable (not power-only)
2. Check correct port selected in Tools → Port
3. Try different USB port on computer
4. Unplug and replug Arduino

**"Programmer not responding"**
1. Check board type: Tools → Board → Arduino Uno
2. Try pressing reset button on Arduino
3. Close other programs using serial port
4. Try different USB cable

**"Upload fails midway"**
1. Let Arduino IDE fully finish previous upload
2. Don't disconnect during upload
3. Check available disk space on computer

---

### Wrong Timing

**Symptoms:** Sequences too fast/slow or wrong duration

**Solutions:**
1. **Use stopwatch** - Time it precisely (phone timer)
2. **Check delay values** - 1000 = 1 second, not 1 millisecond
3. **Verify no missing delays** - Each phase should have timing
4. **Check millis() logic** - If using millis(), check subtraction

---

### Serial Monitor Shows Nothing

**Symptoms:** Serial Monitor blank or gibberish

**Solutions:**
1. **Check baud rate** - Bottom right, should be 9600
2. **Check Serial.begin(9600)** - In setup() function?
3. **Check USB connection** - Serial uses same cable
4. **Try restarting Serial Monitor** - Close and reopen

---

## Logic Problems

### Pedestrian Never Gets Green

**Symptoms:** Button press recognized but no pedestrian crossing

**Debug steps:**
1. **Check button flag** - Is pedestrianRequested being set?
2. **Check minimum time** - Has 3 seconds elapsed in green?
3. **Add Serial prints** - Log state changes
4. **Check state machine** - Does AMBER lead to pedestrian?

---

### Request Not Queuing

**Symptoms:** Button during red/amber doesn't work later

**Debug steps:**
1. **Check flag persistence** - Variable should stay true
2. **Check flag clearing** - Only clear after pedestrian phase
3. **Add debug logging** - Print when flag set/cleared

---

### Safety Violation (If Using Advanced Code)

**Symptoms:** "Safety violation" message in Serial

**Solutions:**
1. **This is intentional** - Code caught an error!
2. **Check your modifications** - Did you change state logic?
3. **Review safety rules** - Traffic and ped green never together
4. **System enters safe state** - All red, by design

---

## Environment Problems

### Arduino IDE Issues

**Symptoms:** IDE crashes, slow, or won't start

**Solutions:**
1. **Update Arduino IDE** - Download latest version
2. **Check Java version** - Arduino IDE requires Java
3. **Clear preferences** - File → Preferences → Clear
4. **Reinstall** - Complete uninstall and fresh install

---

### Tinkercad Simulation Issues

**Symptoms:** Simulation not working correctly

**Solutions:**
1. **Check browser** - Use Chrome or Firefox, not Safari
2. **Disable extensions** - Ad blockers can interfere
3. **Check component connections** - Virtual wires connected?
4. **Try copy-paste code** - Don't type, paste from file
5. **Start fresh simulation** - Create new, don't edit old

---

## Debugging Strategies

### General Approach

1. **Isolate the problem** - Which part doesn't work?
2. **Test smallest unit** - One LED, then two, then all
3. **Use Serial Monitor** - Print everything!
4. **Check one thing at a time** - Change one variable
5. **Compare with working code** - Use provided examples

---

### Serial Debugging Technique

Add these lines to understand what's happening:

```cpp
void loop() {
  Serial.print("Button state: ");
  Serial.println(digitalRead(BUTTON_PIN));

  Serial.print("Current state: ");
  Serial.println(currentState);

  // Your code here
}
```

---

### LED Test Code

Test individual LEDs:

```cpp
void setup() {
  pinMode(12, OUTPUT);
}

void loop() {
  digitalWrite(12, HIGH);
  delay(1000);
  digitalWrite(12, LOW);
  delay(1000);
}
```

If one LED works, the Arduino and basic circuit are fine.

---

## Still Stuck?

1. **Check example code** - Compare with working examples in `arduino-code/examples/`
2. **Start simpler** - Drop back to Level 1 or 2
3. **Review guide** - Reread relevant section in BEGINNER_BUILD_GUIDE.md
4. **Check wiring diagram** - Compare your build to WIRING_INSTRUCTIONS.md

---

## Common Misconceptions

**"delay() doesn't work"**
- delay() works fine for simple projects
- Use millis() for responsive programs with buttons

**"INPUT_PULLUP is backwards"**
- Correct: Button unpressed = HIGH, pressed = LOW
- This is intentional Arduino design

**"Code uploads but nothing happens"**
- Check you're looking at right LED
- Verify USB provides power (should see onboard LED)
- Try uploading test blink code first

---

**→ [Return to Quest Hub](START_HERE.md)**

**→ [Back to Tutorial](BEGINNER_BUILD_GUIDE.md)**