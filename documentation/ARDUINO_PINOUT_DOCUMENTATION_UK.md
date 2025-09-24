# Arduino Uno R3 Pinout Documentation - UK Traffic Light Controller

## Board Overview
This document provides detailed pinout information for the UK Traffic Light Controller project using Arduino Uno R3.

## Arduino Uno R3 Pin Assignments

### Digital Pins (Used)
| Pin | Function | Component | Direction | Description |
|-----|----------|-----------|-----------|-------------|
| 8   | OUTPUT   | Pedestrian Green LED | OUTPUT | White/Blue LED for pedestrian GO signal |
| 9   | OUTPUT   | Pedestrian Red LED | OUTPUT | Red LED for pedestrian STOP signal |
| 10  | OUTPUT   | Green Traffic LED | OUTPUT | Green LED for traffic GO signal |
| 11  | OUTPUT   | Amber Traffic LED | OUTPUT | Amber/Yellow LED for traffic CAUTION signal |
| 12  | OUTPUT   | Red Traffic LED | OUTPUT | Red LED for traffic STOP signal |
| 13  | INPUT    | Pedestrian Button | INPUT_PULLUP | Momentary push button for pedestrian crossing request |

### Digital Pins (Unused but Available)
| Pin Range | Status | Notes |
|-----------|--------|-------|
| 0-1 | Reserved | Used for USB Serial communication (RX/TX) |
| 2-7 | Available | Can be used for expansion (additional buttons, sensors, etc.) |

### Power Pins
| Pin | Function | Usage | Notes |
|-----|----------|-------|-------|
| 5V  | Power Supply | Connected to breadboard positive rail | Powers external components if needed |
| 3.3V | Power Supply | Not used in this project | Available for 3.3V components |
| GND | Ground | Connected to breadboard negative rail | Common ground for all components |
| VIN | External Power | Not used | Can power Arduino from external source (7-12V) |

### Analog Pins (All Available)
| Pin Range | Status | Potential Use |
|-----------|--------|---------------|
| A0-A5 | Available | Light sensors, potentiometers, additional inputs |

## Component Connection Details

### LED Connections (All Output Pins)
```
Arduino Pin → 220Ω Resistor → LED Anode (+) → LED Cathode (-) → GND
```

| LED Color | Arduino Pin | Current Limiting Resistor | Voltage Drop | Current |
|-----------|-------------|---------------------------|--------------|---------|
| Red Traffic | 12 | 220Ω | ~2.0V | ~13.6mA |
| Amber Traffic | 11 | 220Ω | ~2.1V | ~13.2mA |
| Green Traffic | 10 | 220Ω | ~2.2V | ~12.7mA |
| Pedestrian Red | 9 | 220Ω | ~2.0V | ~13.6mA |
| Pedestrian Green | 8 | 220Ω | ~3.0V | ~9.1mA |

### Button Connection (Input Pin)
```
Arduino Pin 13 → Push Button → GND
```
- **Pull-up**: Internal (INPUT_PULLUP mode)
- **Logic**: LOW when pressed, HIGH when released
- **Debounce**: Software debouncing (50ms delay)

## Pin State Logic

### Output Pins (LEDs)
| State | Voltage | LED Status |
|-------|---------|------------|
| HIGH | 5V | LED ON |
| LOW | 0V | LED OFF |

### Input Pin (Button)
| Button State | Pin Reading | Logic Level |
|--------------|-------------|-------------|
| Not Pressed | HIGH (5V) | digitalRead() = HIGH |
| Pressed | LOW (0V) | digitalRead() = LOW |

## Electrical Specifications

### Current Consumption
| Component | Current Draw | Notes |
|-----------|--------------|-------|
| Arduino Uno R3 | ~50mA | Base consumption |
| Red Traffic LED | ~13.6mA | When active |
| Amber Traffic LED | ~13.2mA | When active |
| Green Traffic LED | ~12.7mA | When active |
| Pedestrian Red LED | ~13.6mA | When active |
| Pedestrian Green LED | ~9.1mA | When active |
| **Total Max** | **~113.2mA** | All LEDs on simultaneously |

### Voltage Levels
| Signal | Voltage | Tolerance |
|--------|---------|-----------|
| Logic HIGH | 5V | 4.5V - 5.5V |
| Logic LOW | 0V | 0V - 0.8V |
| Input Threshold | 2.5V | Switching point |

## Pin Usage Map (Visual Reference)

```
        Arduino Uno R3 Pinout
                 USB
              ┌─────────┐
         IOREF │1      30│ VIN
         RESET │2      29│ GND
          3.3V │3      28│ GND
            5V │4      27│ VIN
           GND │5      26│ A5
           GND │6      25│ A4
           VIN │7      24│ A3
              │         23│ A2
         A0    │8      22│ A1
         A1    │9      21│ A0
         A2    │10     20│ AREF
         A3    │11     19│ GND
         A4    │12     18│ 13 ◄── Pedestrian Button
         A5    │13     17│ 12 ◄── Red Traffic LED
              │14     16│ 11 ◄── Amber Traffic LED
         GND   │15      15│ 10 ◄── Green Traffic LED
              └─────────┘
                Power    9 ◄── Pedestrian Red LED
                        8 ◄── Pedestrian Green LED
                        7
                        6
                        5
                        4
                        3
                        2
                        1 (TX)
                        0 (RX)
```

## Expansion Possibilities

### Available Resources
| Resource | Count | Potential Use |
|----------|-------|---------------|
| Digital Pins | 7 (pins 2-7) | Additional buttons, sensors, displays |
| Analog Pins | 6 (A0-A5) | Light sensors, potentiometers, analog inputs |
| PWM Pins | 4 (3,5,6) | Brightness control, motor speed, servos (pins 9,10,11 used) |

### Suggested Expansions
1. **Light Sensor (A0)**: Automatic day/night mode
2. **Buzzer (Pin 7)**: Audio signals for pedestrian crossing
3. **Emergency Button (Pin 6)**: Override to flash red
4. **LCD Display (Pins 2-5)**: Show countdown timers
5. **WiFi Module (Pins 2-3)**: Remote monitoring/control

## Safety and Design Notes

### Electrical Safety
- All LEDs protected by current-limiting resistors
- Input pin uses internal pull-up (no external resistor needed)
- Total current draw well within Arduino USB power limits
- No high-voltage or high-current components

### Code Safety Features
- Button debouncing prevents false triggers
- State machine ensures proper traffic light sequences
- Serial monitoring for debugging
- Non-blocking timing (no delay() in main loop)

### Pin Protection
- Digital pins can source/sink 20mA safely
- Total pin current limited to 200mA across all pins
- Current design uses ~63mA maximum (well within limits)

## UK Traffic Light Sequence

### Standard Operation
1. **Red** (5 seconds) + Pedestrian Red
2. **Red + Amber** (2 seconds) + Pedestrian Red
3. **Green** (6 seconds) + Pedestrian Red
4. **Amber** (3 seconds) + Pedestrian Red
5. Back to Red

### Pedestrian Crossing Operation
- Button press during Green phase requests crossing
- After Amber phase: Red Traffic + Pedestrian Green (8 seconds)
- Returns to normal Red phase