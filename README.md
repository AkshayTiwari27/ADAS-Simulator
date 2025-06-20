🚗 ADAS Simulator – Blind Spot & Lane Detection
This project simulates an Advanced Driver Assistance System (ADAS) in C, mimicking radar-based blind spot detection and lane drift alerts. Built without any hardware, it demonstrates key embedded C programming skills, modular design, and real-time logic relevant to automotive systems.

🎯 Features
Simulated Radar Sensors: Generates random distance data for left and right blind spots.

Blind Spot Detection: Triggers an alert if an object is detected within a 100 cm threshold.

Simulated Lane Camera: Simulates vehicle drifting to the left or right of the lane center.

Lane Departure Warning: Triggers an alert if the vehicle's position deviates from the center.

Real-Time Alert Generation: Displays alerts on the terminal as events occur.

Persistent Event Logging: Logs all alerts with a timestamp to log.txt for later review.

🧠 Technologies & Skills Demonstrated
Embedded C: Clean, modular, and efficient C code.

RTOS-style Task Simulation: The main loop mimics a scheduler running periodic tasks.

Modular Architecture: Code is separated into logical units (sensors, detection, alerts, logging) with clear interfaces (.h files).

File I/O: Demonstrates writing to the filesystem for logging purposes.

Real-time Behavior Simulation: The system responds to simulated events as they happen.

⚙️ How to Compile and Run
A Makefile is provided for convenience on Linux, macOS, or Windows with make installed.

Using Makefile (Recommended)
Simply run make:

make

This will compile all .c files and create an executable named adas.

Manual Compilation (Linux/macOS)
If you prefer to compile manually, you can use gcc:

gcc main.c sensor_simulation.c blind_spot.c lane_detection.c alert.c log.c -o adas

Manual Compilation (Windows with MinGW/MSVC)
Using GCC (via MinGW or TDM-GCC):

gcc main.c sensor_simulation.c blind_spot.c lane_detection.c alert.c log.c -o adas.exe

Running the Simulator
Once compiled, run the executable from your terminal:

./adas

or on Windows:

.\adas.exe

The simulation will start and print status updates and alerts to the terminal. Press Ctrl+C to stop it.

📂 Output Example
Terminal Output
The terminal will show a continuous stream of status updates and occasional alerts.

[✓] Lane: CENTER       | Left: 185 cm | Right: 130 cm
[✓] Lane: CENTER       | Left: 120 cm | Right:  80 cm
[!] ALERT: Blind Spot Alert: Object on RIGHT, Distance = 80cm
[✓] Lane: RIGHT_DRIFT  | Left: 155 cm | Right: 195 cm
[!] ALERT: Lane Drift Alert: Drifting RIGHT

Log File Output (log.txt)
A log.txt file will be created in the same directory, containing a history of all alerts.

--- ADAS Log Session Started at 14:35:01 --- Blind Spot Alert: Object on RIGHT, Distance = 80cm Lane Drift Alert: Drifting RIGHT
--- Log Session Ended ---
