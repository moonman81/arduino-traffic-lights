# Arduino Uno R3 Pinout Documentation - UK Traffic Light Controller

## Board Overview
This document provides detailed pinout information for the Traffic Light Controller project using Arduino Uno R3.

## Arduino Uno R3 Pin Assignments

### Digital Pins (Used)
| Pin | Function | Component | Direction | Description |
|-----|----------|-----------|-----------|-------------|
| 9   | INPUT    | Pedestrian Button | INPUT_PULLUP | Momentary push button for pedestrian crossing request |
| 10  | OUTPUT   | Pedestrian LED | OUTPUT | White/Blue LED indicating pedestrian crossing phase |
| 11  | OUTPUT   | Green Traffic LED | OUTPUT | Green LED for GO signal |
| 12  | OUTPUT   | Orange Traffic LED | OUTPUT | Orange/Yellow LED for CAUTION signal |
| 13  | OUTPUT   | Red Traffic LED | OUTPUT | Red LED for STOP signal (also onboard LED) |

### Digital Pins (Unused but Available)
| Pin Range | Status | Notes |
|-----------|--------|-------|
| 0-1 | Reserved | Used for USB Serial communication (RX/TX) |
| 2-8 | Available | Can be used for expansion (additional buttons, sensors, etc.) |

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
| Red | 13 | 220Ω | ~2.0V | ~13.6mA |
| Orange | 12 | 220Ω | ~2.1V | ~13.2mA |
| Green | 11 | 220Ω | ~2.2V | ~12.7mA |
| White/Blue | 10 | 220Ω | ~3.0V | ~9.1mA |

### Button Connection (Input Pin)
```
Arduino Pin 9 → Push Button → GND
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
| Red LED | ~13.6mA | When active |
| Orange LED | ~13.2mA | When active |
| Green LED | ~12.7mA | When active |
| Pedestrian LED | ~9.1mA | When active |
| **Total Max** | **~98.6mA** | All LEDs on simultaneously |

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
         A4    │12     18│ 13 ◄── Red LED
         A5    │13     17│ 12 ◄── Orange LED
              │14     16│ 11 ◄── Green LED
         GND   │15      15│ 10 ◄── Pedestrian LED
              └─────────┘
                Power    9 ◄── Pedestrian Button
                        8
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
| Digital Pins | 8 (pins 2-8) | Additional buttons, sensors, displays |
| Analog Pins | 6 (A0-A5) | Light sensors, potentiometers, analog inputs |
| PWM Pins | 6 (3,5,6,9,10,11) | Brightness control, motor speed, servos |

### Suggested Expansions
1. **Light Sensor (A0)**: Automatic day/night mode
2. **Buzzer (Pin 8)**: Audio signals for pedestrian crossing
3. **Emergency Button (Pin 7)**: Override to flash red
4. **LCD Display (Pins 2-6)**: Show countdown timers
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
- Current design uses ~49mA maximum (well within limits)