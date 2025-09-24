# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Project Overview

This is an Arduino-based traffic light controller implementing UK traffic light standards with pedestrian crossing functionality. The project includes comprehensive ontological analysis and formal safety verification.

## Key Architecture Components

### Core Implementation
- **Main Code**: `arduino-code/traffic-lights-arduino-clean.c` - Single clean implementation file
- **State Machine**: 5 states (RED, RED_AMBER, GREEN, AMBER, PEDESTRIAN_CROSSING)
- **Safety System**: Real-time verification of 4 formal safety invariants
- **Non-blocking Design**: Uses millis() for timing, no delay() calls

### Pin Configuration (UK Standard)
```
Pin 13: Pedestrian Button (INPUT_PULLUP)
Pin 12: Red Traffic LED
Pin 11: Amber Traffic LED
Pin 10: Green Traffic LED
Pin 9:  Pedestrian Red LED
Pin 8:  Pedestrian Green LED
```

### Safety Invariants (Formally Verified)
1. **Mutual Exclusion**: Traffic and pedestrian greens never simultaneous
2. **Progressive Warning**: All green→red transitions through amber
3. **Minimum Time**: 3-second minimum green before interruption
4. **Deadlock Freedom**: System always progresses

## Development Commands

### Arduino IDE Compilation
```bash
# For physical Arduino
arduino-cli compile --fqbn arduino:avr:uno arduino-code/traffic-lights-arduino-clean.c
arduino-cli upload -p /dev/ttyUSB0 --fqbn arduino:avr:uno arduino-code/

# Monitor serial output
arduino-cli monitor -p /dev/ttyUSB0 --config baudrate=9600
```

### Tinkercad Simulation
1. Copy code from `arduino-code/traffic-lights-arduino-clean.c`
2. Create circuit with components per pin configuration
3. Use 330Ω resistors for all LEDs
4. Run simulation - system starts in RED state

## Project Structure

- `arduino-code/` - Arduino C implementation
- `ontological-analysis/` - N3 format philosophical and formal analysis files
- `documentation/` - Wiring instructions, pinout docs, FSA analysis

## Key Technical Details

- **Timing Constants**: Defined at lines 43-49 in main code
- **State Management**: Global state variables at lines 66-74
- **Safety Verification**: Functions at lines 85-114 verify invariants
- **Button Debouncing**: 200ms debounce implemented
- **Current Usage**: ~6-9mA per LED (safe within 40mA pin limit)

## Important Notes for Modifications

1. **Safety First**: Any changes must maintain the 4 safety invariants
2. **UK Standards**: Maintain RED+AMBER phase before GREEN
3. **Timing**: Don't reduce GREEN_MINIMUM_DURATION below 3000ms
4. **State Transitions**: Never allow direct GREEN→RED transitions
5. **Verification**: Safety checks run continuously in main loop

## Testing Approach

The system is designed for:
- Tinkercad simulation (primary testing environment)
- Physical Arduino Uno deployment
- Serial monitor debugging (9600 baud)

No automated test suite exists - testing is done via simulation or physical deployment with manual verification of state transitions and safety properties.