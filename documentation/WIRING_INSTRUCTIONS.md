# UK Traffic Light Controller - Wiring Instructions

## Components Required
- Arduino Uno R3
- 5x LEDs (Red, Amber/Yellow, Green, Red for pedestrian, Green for pedestrian)
- 5x 220Ω resistors (for LEDs)
- 1x Push button (momentary)
- Breadboard
- Jumper wires (male-to-male)

## Pin Assignments - UK Configuration
| Component | Arduino Pin | Wire Color (Suggested) |
|-----------|-------------|------------------------|
| Pedestrian Button | Digital Pin 13 | Purple |
| Red Traffic LED | Digital Pin 12 | Red |
| Amber Traffic LED | Digital Pin 11 | Orange/Yellow |
| Green Traffic LED | Digital Pin 10 | Green |
| Pedestrian Red LED | Digital Pin 9 | Pink/Red |
| Pedestrian Green LED | Digital Pin 8 | White/Blue |
| Ground (GND) | GND | Black |
| Power (5V) | 5V | Red |

## Step-by-Step Wiring Instructions

### Step 1: Prepare the Breadboard
1. Place the breadboard next to your Arduino Uno
2. Connect Arduino **GND** to the **negative rail** of the breadboard (black wire)
3. Connect Arduino **5V** to the **positive rail** of the breadboard (red wire)

### Step 2: Wire the Traffic Light LEDs

#### Red Traffic LED (Pin 12)
1. Insert Red LED into breadboard
   - **Long leg (anode)** goes to a numbered row
   - **Short leg (cathode)** goes to the negative rail
2. Connect a **220Ω resistor** between the anode row and another row
3. Connect a **red jumper wire** from Pin 12 to the resistor's free end

#### Amber Traffic LED (Pin 11)
1. Insert Amber/Yellow LED into breadboard
   - **Long leg (anode)** goes to a numbered row
   - **Short leg (cathode)** goes to the negative rail
2. Connect a **220Ω resistor** between the anode row and another row
3. Connect an **orange/yellow jumper wire** from Pin 11 to the resistor's free end

#### Green Traffic LED (Pin 10)
1. Insert Green LED into breadboard
   - **Long leg (anode)** goes to a numbered row
   - **Short leg (cathode)** goes to the negative rail
2. Connect a **220Ω resistor** between the anode row and another row
3. Connect a **green jumper wire** from Pin 10 to the resistor's free end

#### Pedestrian Red LED (Pin 9)
1. Insert Red LED into breadboard
   - **Long leg (anode)** goes to a numbered row
   - **Short leg (cathode)** goes to the negative rail
2. Connect a **220Ω resistor** between the anode row and another row
3. Connect a **pink/red jumper wire** from Pin 9 to the resistor's free end

#### Pedestrian Green LED (Pin 8)
1. Insert White/Blue LED into breadboard
   - **Long leg (anode)** goes to a numbered row
   - **Short leg (cathode)** goes to the negative rail
2. Connect a **220Ω resistor** between the anode row and another row
3. Connect a **white/blue jumper wire** from Pin 8 to the resistor's free end

### Step 3: Wire the Pedestrian Button

#### Push Button (Pin 13)
1. Insert the **push button** into the breadboard
   - Place it across the center gap of the breadboard
2. Connect one side of the button to the **negative rail (GND)**
3. Connect the other side of the button to Pin 13 with a **purple jumper wire**

**Note:** We don't need an external pull-up resistor because the code uses `INPUT_PULLUP`

## Circuit Diagram (Text Representation)

```
Arduino Uno R3
                     Breadboard
Pin 13 ---- Button ---- GND Rail

Pin 12 ----[220Ω]---- LED(Red) ----+
                                   |
Pin 11 ----[220Ω]---- LED(Amber) --+
                                   |
Pin 10 ----[220Ω]---- LED(Green) --+---- GND Rail
                                   |
Pin 9  ----[220Ω]---- LED(Ped Red) +
                                   |
Pin 8  ----[220Ω]---- LED(Ped Grn) +

GND ---- GND Rail
5V  ---- +5V Rail (not used in this circuit)
```

## Safety Checks Before Powering On

1. ✅ **LED Polarity**: Verify all LEDs have long legs (anodes) connected through resistors to Arduino pins
2. ✅ **Resistor Values**: Confirm all LED resistors are 220Ω (Red-Red-Brown-Gold bands)
3. ✅ **Button Wiring**: One side to GND, other side to Pin 9
4. ✅ **No Short Circuits**: Ensure no wires are touching that shouldn't be
5. ✅ **Secure Connections**: All wires firmly inserted into breadboard and Arduino

## Testing the Circuit

1. **Upload the code** to your Arduino Uno
2. **Open Serial Monitor** (Tools → Serial Monitor, set to 9600 baud)
3. **Expected behavior**:
   - Red LED should light up first
   - After 5 seconds: Red + Orange together
   - After 2 more seconds: Green only
   - After 6 seconds: Orange only
   - Back to Red and repeat
4. **Test pedestrian button**: Press during green phase to trigger pedestrian crossing

## Troubleshooting

| Problem | Solution |
|---------|----------|
| LED not lighting | Check polarity (long leg = anode), verify resistor connection |
| Button not working | Ensure one side connected to GND, other to Pin 9 |
| Multiple LEDs on | Check for wire shorts, verify pin assignments |
| No serial output | Check USB connection, verify baud rate (9600) |
| Erratic behavior | Check power connections, ensure stable breadboard connections |

## Physical Layout Suggestion

```
    [Arduino Uno R3]
         |
    [Breadboard Layout]

Row 1:  Red Traffic LED + Resistor
Row 5:  Amber Traffic LED + Resistor
Row 9:  Green Traffic LED + Resistor
Row 13: Pedestrian Red LED + Resistor
Row 17: Pedestrian Green LED + Resistor
Row 21: Push Button

Left side: Arduino connections
Right side: GND rail connections
```

**Note**: This layout keeps components organized and easy to troubleshoot. Adjust row numbers based on your breadboard size.