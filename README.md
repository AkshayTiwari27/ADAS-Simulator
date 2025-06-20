# ADAS Core Logic Simulator

## Table of Contents

  - [Project Overview](https://www.google.com/search?q=%23project-overview)
  - [System Architecture](https://www.google.com/search?q=%23system-architecture)
      - [Design Philosophy](https://www.google.com/search?q=%23design-philosophy)
      - [Data Flow](https://www.google.com/search?q=%23data-flow)
      - [Module Descriptions](https://www.google.com/search?q=%23module-descriptions)
  - [Key Features](https://www.google.com/search?q=%23key-features)
  - [Code Documentation](https://www.google.com/search?q=%23code-documentation)
  - [Build and Execute](https://www.google.com/search?q=%23build-and-execute)
      - [Prerequisites](https://www.google.com/search?q=%23prerequisites)
      - [Using Makefile (Recommended)](https://www.google.com/search?q=%23using-makefile-recommended)
      - [Manual Compilation](https://www.google.com/search?q=%23manual-compilation)
  - [Example Simulation Output](https://www.google.com/search?q=%23example-simulation-output)
      - [Terminal Output](https://www.google.com/search?q=%23terminal-output)
      - [Log File Output](https://www.google.com/search?q=%23log-file-output)

## Project Overview

This project is a hardware-independent simulator for an Advanced Driver Assistance System (ADAS), written entirely in C. It models the core decision-making logic for two critical safety features: **Blind Spot Detection (BSD)** and **Lane Departure Warning (LDW)**.

The primary goal is to demonstrate robust embedded C programming practices, including a modular and portable architecture, real-time system simulation, and hardware abstraction—all without requiring physical sensors or microcontrollers.

## System Architecture

### Design Philosophy

The simulator is built on a **modular, decoupled architecture**. Each core component (sensor simulation, detection logic, alerting, logging) is isolated in its own module with a clean interface exposed via a header file (`.h`). This approach yields several key engineering benefits:

  * **Portability**: The core logic is completely independent of the underlying hardware (or in this case, the simulation environment).
  * **Testability**: Each module can be unit-tested in isolation.
  * **Scalability**: New features (e.g., Adaptive Cruise Control) can be integrated as new modules with minimal impact on existing code.
  * **Maintainability**: Clear separation of concerns makes the codebase easier to understand and debug.

### Data Flow

The system operates in a continuous loop that mimics a real-time operating system (RTOS) scheduler running periodic tasks.

`[Sensor Simulation] -> [Detection Logic (BSD & LDW)] -> [Alert Generation] -> [Console UI & File Logger]`

### Module Descriptions

The codebase is organized into the following logical units:

| Module             | Responsibility                                                                    | Files                                   |
| ------------------ | --------------------------------------------------------------------------------- | --------------------------------------- |
| `main`             | Main application driver. Initializes all subsystems and runs the simulation loop. | `main.c`                                |
| `sensor_simulation`| Abstracts sensor hardware by providing simulated distance and lane position data.   | `sensor_simulation.c/h`                 |
| `blind_spot`       | Encapsulates the algorithm for detecting objects in blind spots.                  | `blind_spot.c/h`                        |
| `lane_detection`   | Encapsulates the algorithm for detecting lane drift.                              | `lane_detection.c/h`                    |
| `alert`            | Manages the formatting and presentation of alerts to the user console.            | `alert.c/h`                             |
| `log`              | Handles persistent, timestamped event logging to the filesystem.                  | `log.c/h`                               |
| `terminal_colors`  | Provides ANSI escape codes for colorized, human-readable console output.          | `terminal_colors.h`                     |

## Key Features

  * **Hardware-Abstracted Sensor Simulation**: Generates randomized, yet plausible, data for radar sensors and a lane-tracking camera.
  * **Configurable Threshold-Based Blind Spot Detection**: Triggers an alert if a simulated object is detected within a 100 cm safety threshold.
  * **State-Based Lane Departure Warning**: Issues a warning if the vehicle's simulated position deviates from the lane center.
  * **Real-Time Alert Generation**: Displays critical alerts on the terminal as events are detected in the simulation cycle.
  * **Persistent Event Logging**: Logs all generated alerts with a timestamp to `log.txt` for auditing and post-simulation analysis.

## Code Documentation

The source code is internally documented using Doxygen-style comments in all header (`.h`) files. This documentation clarifies the purpose, parameters, and return values for every public function, adhering to industry best practices for code clarity and maintainability.

## Build and Execute

### Prerequisites

  * A C compiler (e.g., GCC)
  * `make` (for the recommended build method)

### Using Makefile (Recommended)

A `Makefile` is provided for a one-step compilation process on Linux, macOS, or Windows (with `make` installed).

```sh
# This will compile all source files and create the 'adas' executable.
make
```

### Manual Compilation

If you prefer to compile manually, use the following `gcc` command.

**Linux/macOS:**

```sh
gcc main.c sensor_simulation.c blind_spot.c lane_detection.c alert.c log.c -o adas
```

**Windows (with MinGW/TDM-GCC):**

```sh
gcc main.c sensor_simulation.c blind_spot.c lane_detection.c alert.c log.c -o adas.exe
```

### Running the Simulator

Execute the compiled application from your terminal. Press `Ctrl+C` to stop the simulation.

**Linux/macOS:**

```sh
./adas
```

**Windows:**

```sh
.\adas.exe
```

## Example Simulation Output

### Terminal Output

The terminal displays a continuous stream of system status updates, interspersed with real-time alerts.

```
[OK] Lane: CENTER       | Left: 185 cm | Right: 130 cm
[OK] Lane: CENTER       | Left: 120 cm | Right:  80 cm
[!!] Blind Spot Alert: Object on RIGHT, Distance = 80cm
[OK] Lane: RIGHT_DRIFT  | Left: 155 cm | Right: 195 cm
[!!] Lane Drift Alert: Drifting RIGHT
```

### Log File Output

A `log.txt` file is created or appended in the same directory, containing a history of all triggered alerts.

```
--- ADAS Log Session Started at 19:30:11 ---
[19:31:29] Blind Spot Alert: Object on LEFT, Distance = 54cm
[19:31:29] Lane Drift Alert: Drifting RIGHT
[19:31:30] Blind Spot Alert: Object on LEFT, Distance = 51cm
```
