# Traffic Light System: Finite State Automaton Analysis

## I. Finite State Automaton Definition

### State Space (Q)
```
Q = {RED, RED_AMBER, GREEN, AMBER, PED_CROSSING}
```

### Alphabet (Σ) - Input Events
```
Σ = {
  timeout_red,           // Red duration elapsed
  timeout_red_amber,     // Red+Amber duration elapsed
  timeout_green,         // Full green duration elapsed
  timeout_green_min,     // Minimum green duration elapsed
  timeout_amber,         // Amber duration elapsed
  timeout_ped_crossing,  // Pedestrian crossing duration elapsed
  button_press,          // Pedestrian button pressed
  button_press_early     // Button pressed before min green time
}
```

### Extended State Variables
```
pedestrianRequested : Boolean
pedestrianWaiting : Boolean
greenStartTime : Timestamp
currentTime : Timestamp
```

### Transition Function (δ)
```
δ: Q × Σ × Conditions → Q

δ(RED, timeout_red, true) = RED_AMBER
δ(RED_AMBER, timeout_red_amber, true) = GREEN
δ(GREEN, timeout_green, true) = AMBER
δ(GREEN, timeout_green_min ∧ pedestrianRequested, true) = AMBER
δ(GREEN, button_press ∧ (currentTime - greenStartTime ≥ GREEN_MIN), true) = AMBER
δ(GREEN, button_press ∧ (currentTime - greenStartTime < GREEN_MIN), pedestrianWaiting := true) = GREEN
δ(AMBER, timeout_amber ∧ pedestrianRequested, true) = PED_CROSSING
δ(AMBER, timeout_amber ∧ pedestrianWaiting, true) = PED_CROSSING
δ(AMBER, timeout_amber ∧ ¬pedestrianRequested ∧ ¬pedestrianWaiting, true) = RED
δ(PED_CROSSING, timeout_ped_crossing, pedestrianRequested := false ∧ pedestrianWaiting := false) = RED
```

### Initial State (q₀)
```
q₀ = RED with pedestrianRequested = false, pedestrianWaiting = false
```

### Accepting States (F)
```
F = Q  // All states are accepting (system runs continuously)
```

---

## II. Kripke Model Analysis - Modal Logic Perspective

### Kripke Structure K = (W, R, V)

#### Possible Worlds (W)
```
W = {
  w₀: (RED, ¬pedReq, ¬pedWait),
  w₁: (RED_AMBER, ¬pedReq, ¬pedWait),
  w₂: (GREEN, ¬pedReq, ¬pedWait),
  w₃: (GREEN, ¬pedReq, pedWait),
  w₄: (GREEN, pedReq, ¬pedWait),
  w₅: (AMBER, ¬pedReq, ¬pedWait),
  w₆: (AMBER, pedReq, ¬pedWait),
  w₇: (AMBER, ¬pedReq, pedWait),
  w₈: (PED_CROSSING, ¬pedReq, ¬pedWait)
}
```

#### Accessibility Relation (R)
```
R = {
  (w₀, w₁),    // RED → RED_AMBER (always)
  (w₁, w₂),    // RED_AMBER → GREEN (always)
  (w₂, w₃),    // GREEN → GREEN (early button press)
  (w₂, w₄),    // GREEN → GREEN (late button press)
  (w₂, w₅),    // GREEN → AMBER (timeout, no ped)
  (w₃, w₄),    // GREEN(waiting) → GREEN(requested) after min time
  (w₃, w₇),    // GREEN(waiting) → AMBER(waiting)
  (w₄, w₆),    // GREEN(requested) → AMBER(requested)
  (w₅, w₀),    // AMBER → RED (no pedestrian)
  (w₆, w₈),    // AMBER(requested) → PED_CROSSING
  (w₇, w₈),    // AMBER(waiting) → PED_CROSSING
  (w₈, w₀)     // PED_CROSSING → RED
}
```

#### Valuation Function (V)
```
V(trafficRed) = {w₀, w₈}
V(trafficAmber) = {w₁, w₅, w₆, w₇}
V(trafficGreen) = {w₂, w₃, w₄}
V(pedGreen) = {w₈}
V(pedRed) = {w₀, w₁, w₂, w₃, w₄, w₅, w₆, w₇}
V(pedRequested) = {w₄, w₆}
V(pedWaiting) = {w₃, w₇}
V(safeToWalk) = {w₈}
V(trafficCanGo) = {w₂, w₃, w₄}
```

### Modal Logic Properties

#### Safety Properties (□)
```
□(pedGreen → trafficRed)           // Pedestrian green implies traffic red
□(trafficGreen → pedRed)           // Traffic green implies pedestrian red
□¬(trafficGreen ∧ pedGreen)        // Never both green simultaneously
```

#### Liveness Properties (◊)
```
□(pedRequested → ◊safeToWalk)      // Every pedestrian request eventually satisfied
□◊trafficCanGo                     // Traffic eventually gets green
□(pedWaiting → ◊pedRequested)      // Waiting pedestrians eventually get request activated
```

#### Temporal Properties (Until/Since)
```
(pedRequested ∧ trafficGreen) → (trafficGreen U trafficAmber)  // Green until amber when ped requested
(pedWaiting ∧ greenStarted) → (pedWaiting U (minTimeElapsed ∧ pedRequested))  // Wait until min time
```

---

## III. Tarski Semantic Analysis - Truth and Satisfaction

### First-Order Logic Structure M = (D, I)

#### Domain (D)
```
D = {
  States: {RED, RED_AMBER, GREEN, AMBER, PED_CROSSING},
  Booleans: {true, false},
  Times: ℕ (natural numbers representing milliseconds),
  Events: {timeout, button_press, state_change}
}
```

#### Interpretation Function (I)
```
I(currentState) : States
I(pedestrianRequested) : Booleans
I(pedestrianWaiting) : Booleans
I(elapsedTime) : Times
I(minGreenTime) : Times = 3000
I(fullGreenTime) : Times = 6000

// Predicates
I(Safe)(s₁, s₂) ↔ ¬(s₁ = GREEN_TRAFFIC ∧ s₂ = GREEN_PED)
I(Reachable)(s₁, s₂) ↔ ∃ path in transition graph from s₁ to s₂
I(ValidTransition)(s₁, e, s₂) ↔ δ(s₁, e) = s₂
```

### Tarski Truth Conditions

#### Atomic Formulas
```
M ⊨ currentState = RED iff I(currentState) = RED
M ⊨ pedestrianRequested iff I(pedestrianRequested) = true
M ⊨ elapsedTime > minGreenTime iff I(elapsedTime) > I(minGreenTime)
```

#### Complex Formulas
```
M ⊨ ∀s₁,s₂ (Safe(s₁,s₂)) iff for all state pairs, safety condition holds
M ⊨ ∃t (ValidTransition(GREEN, button_press, t)) iff there exists valid transition from GREEN on button press
M ⊨ ∀t (t ≥ minGreenTime → CanInterrupt(t)) iff pedestrian can interrupt after minimum time
```

### Semantic Equivalences
```
(pedestrianRequested ∧ inGreenState ∧ elapsedTime ≥ minGreenTime) ≡ CanTransitionToAmber
(¬pedestrianRequested ∧ ¬pedestrianWaiting) ≡ NormalCycle
(pedestrianWaiting ∧ elapsedTime < minGreenTime) ≡ MustWaitForMinTime
```

---

## IV. Grothendieck Perspective - Categorical Structures

### Category Theory Framework

#### Objects (Ob(𝒞))
```
States as Objects: RED, RED_AMBER, GREEN, AMBER, PED_CROSSING
Extended States: (State × Boolean × Boolean × Time)
```

#### Morphisms (Hom(𝒞))
```
Transitions as Morphisms:
f₁: RED → RED_AMBER (timeout)
f₂: RED_AMBER → GREEN (timeout)
f₃: GREEN → AMBER (timeout OR pedRequested)
f₄: GREEN → GREEN (button_press_early, state transformation)
f₅: AMBER → RED (timeout, ¬pedRequested)
f₆: AMBER → PED_CROSSING (timeout, pedRequested)
f₇: PED_CROSSING → RED (timeout)
```

#### Composition
```
f₂ ∘ f₁: RED → GREEN (red-amber-green sequence)
f₅ ∘ f₃ ∘ f₂ ∘ f₁: RED → RED (normal cycle without pedestrian)
f₇ ∘ f₆ ∘ f₃ ∘ f₂ ∘ f₁: RED → RED (cycle with pedestrian crossing)
```

### Grothendieck Fibration

#### Base Category (ℬ)
```
Objects: Time intervals [0, RED_DURATION], [RED_DURATION, RED_DURATION + RED_AMBER_DURATION], ...
Morphisms: Temporal inclusions and progressions
```

#### Fiber Categories (E_b for b ∈ ℬ)
```
For each time interval b:
E_b = Category of possible system states during interval b
Objects in E_b: Valid states reachable during time interval b
Morphisms in E_b: State transitions possible within time constraints of b
```

#### Projection Functor (π: E → ℬ)
```
π(state, time) = time_interval_containing(time)
π(state_transition) = temporal_progression
```

### Topos Structure

#### Subobject Classifier (Ω)
```
Ω classifies safety properties:
true ↦ Safe state configurations
false ↦ Unsafe state configurations

χ_Safe: StateSpace → Ω
χ_Safe(s) = true iff s satisfies safety invariants
```

#### Power Object (P(X))
```
P(StateSpace) = Set of all possible state subsets
Includes: {reachable_states, safe_states, deadlock_states, live_states}
```

### Sheaf Conditions

#### Local Consistency
```
For overlapping time intervals, state transitions must be consistent:
If state s is valid in interval I₁ and interval I₂ overlaps I₁,
then s must remain valid in the overlap I₁ ∩ I₂
```

#### Global Gluing
```
Local state transitions can be glued together to form global system behavior:
Individual FSA transitions → Complete system execution traces
```

---

## V. Execution Trace Analysis

### Sample Execution Through Multiple Lenses

#### Trace: Button pressed at t=1000ms during GREEN state

**FSA Perspective:**
```
t=0:    State = RED
t=5000: State = RED_AMBER (timeout_red)
t=7000: State = GREEN (timeout_red_amber)
t=8000: button_press → pedestrianWaiting = true (t < GREEN_MIN)
t=10000: pedestrianRequested = true, pedestrianWaiting = false (t ≥ GREEN_MIN)
t=10000: State = AMBER (pedestrian interrupt)
t=13000: State = PED_CROSSING (timeout_amber + pedestrianRequested)
t=21000: State = RED (timeout_ped_crossing)
```

**Kripke Model Path:**
```
w₀ → w₁ → w₂ → w₃ → w₄ → w₆ → w₈ → w₀
```

**Modal Logic Validation:**
```
At w₃: pedWaiting ∧ trafficGreen ∧ ¬(elapsedTime ≥ minGreenTime)
At w₄: pedRequested ∧ trafficGreen ∧ (elapsedTime ≥ minGreenTime)
At w₈: safeToWalk ∧ trafficRed ∧ pedGreen
```

**Tarski Satisfaction:**
```
M ⊨ ∀t((t ≥ 10000) → (pedestrianRequested = true))
M ⊨ ∃t((8000 ≤ t < 10000) → (pedestrianWaiting = true))
M ⊨ □(pedGreen → trafficRed) [satisfied at t=13000-21000]
```

**Grothendieck Fiber Analysis:**
```
Time fiber [8000, 10000]: Contains waiting state transformation
Time fiber [10000, 13000]: Contains request activation and amber transition
Time fiber [13000, 21000]: Contains pedestrian crossing state
Sheaf condition: State consistency maintained across fiber boundaries
```

### Dimensional Analysis

#### State Space Dimensions
```
Dimension 1: Traffic Light States (5 discrete values)
Dimension 2: Pedestrian Request Status (3 discrete values: none, waiting, active)
Dimension 3: Temporal Constraints (continuous time domain)
Dimension 4: Safety Properties (boolean satisfaction domain)
```

#### Phase Space Trajectories
```
Normal Cycle: (RED, none, t₀) → (RED_AMBER, none, t₁) → (GREEN, none, t₂) → (AMBER, none, t₃) → (RED, none, t₄)
Interrupted Cycle: (GREEN, none, t₂) → (GREEN, waiting, t₂') → (GREEN, active, t₂'') → (AMBER, active, t₃) → (PED_CROSSING, none, t₄) → (RED, none, t₅)
```

#### Attractors and Fixed Points
```
Limit Cycle: Normal traffic operation without pedestrian intervention
Strange Attractor: Pedestrian-interrupted cycles with varying timing
Fixed Point: System always returns to RED state after any sequence
```

This comprehensive analysis reveals the traffic light system as a rich mathematical object that can be understood through multiple formal lenses, each revealing different aspects of its structure and behavior.