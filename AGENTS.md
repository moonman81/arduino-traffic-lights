# Agent Configuration for Arduino Traffic Light Controller

## Build/Lint/Test Commands

### Build Commands
- **Arduino IDE**: Open `arduino-code/traffic-lights-arduino-clean.c` in Arduino IDE and upload to Arduino Uno
- **Tinkercad**: Copy code from `arduino-code/traffic-lights-arduino-clean.c` to Tinkercad Circuits simulation

### Test Commands
- **Manual Testing**: Open Serial Monitor at 9600 baud, observe state transitions and safety verification messages
- **Safety Verification**: Monitor serial output for "✓" safety invariant confirmations and absence of "ERROR" messages
- **Hardware Testing**: Press pedestrian button during green phase to verify interrupt behavior

### Single Test Execution
- **Safety Test**: Run system and verify mutual exclusion invariant: `grep "mutual exclusion" serial_output.log`
- **State Transition Test**: Monitor serial for proper RED→RED+AMBER→GREEN→AMBER→RED cycle

## Code Style Guidelines

### Language and Environment
- **Language**: Arduino C/C++ (extension of C++ with Arduino-specific functions)
- **IDE**: Arduino IDE or compatible editors (VS Code with Arduino extension)
- **Compilation**: Arduino compiler toolchain (handles `bool`, `digitalRead`, etc.)

### Naming Conventions
- **Constants**: `UPPER_SNAKE_CASE` with `#define` (e.g., `RED_DURATION`, `STATE_RED`)
- **Functions**: `camelCase` with descriptive names (e.g., `verifyMutualExclusion`, `processPedestrianButton`)
- **Variables**: `camelCase` with descriptive prefixes (e.g., `pedestrianRequested`, `currentTrafficState`)
- **Comments**: Philosophical/descriptive style explaining purpose and safety implications

### Code Structure
- **Header Comments**: Extensive file header with ontological context and pin configuration
- **Section Organization**: Code divided into logical sections with `// ===` separators
- **Function Comments**: Each function has detailed comment explaining formal verification and natural language purpose
- **Safety Verification**: Dedicated functions for each safety invariant with formal mathematical notation

### Error Handling
- **Safety Violations**: Immediate emergency stop with LED shutdown and serial error reporting
- **State Validation**: Pre/post-transition verification prevents unsafe state changes
- **Debouncing**: 200ms temporal filtering for button inputs
- **Default Cases**: Error handling in switch statements with safe state reset

### Imports and Dependencies
- **Arduino Standard**: Uses only standard Arduino functions (`digitalRead`, `digitalWrite`, `millis`, `Serial`, `pinMode`)
- **No External Libraries**: Self-contained implementation with no additional dependencies
- **Pin Definitions**: All hardware pins defined as constants at file top

### Types and Safety
- **Arduino Types**: Uses `bool` for boolean flags, `int` for states, `unsigned long` for timing
- **Type Consistency**: All state parameters use `int` type for Arduino compatibility
- **Safety Verification**: Runtime checking of safety invariants with continuous monitoring
- **Temporal Safety**: Minimum time guarantees enforced programmatically