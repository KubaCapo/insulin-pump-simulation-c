# Insulin Pump Control System Simulation (C)

A console-based C application simulating blood glucose monitoring and automated insulin pump activation. Built as an academic Computer Science project at UKSW to practice structured programming, custom data structures, and pointer-based state manipulation.

## How It Works
1. **Sensor Simulation:** Generates randomized blood glucose (`72.0 – 199.0 mg/dL`) and insulin (`40.0 – 300.0 pmol/L`) levels.
2. **Measurement Conversion:** Converts raw floating-point blood values into discrete integer sensor readings (`struct Measurement`).
3. **Threshold Evaluation:** Evaluates whether glucose exceeds the `126 mg/dL` threshold.
4. **Pointer-Based Pump Actuation:** When triggered, updates the `Blood` state directly via pointers—delivering an insulin dose (`+30.0 pmol/L`) and stabilizing glucose (`100.0 mg/dL`).

## Technologies & Concepts Used
- **Language:** C (C11 standard)
- **Core Concepts:** `struct` modeling, pass-by-value vs. pass-by-pointer (`*`), `const` pointer safety, pseudo-random number generation (`rand`/`srand`)

## Build & Run
```bash
gcc -Wall -Wextra main.c -o insulin_pump
./insulin_pump
