#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Platform-specific includes for sleep functionality
#ifdef _WIN32
#include <windows.h> // For Sleep() on Windows
#else
#include <unistd.h> // For sleep() on Unix-like systems
#endif

#include "sensor_simulation.h"
#include "blind_spot.h"
#include "lane_detection.h"
#include "alert.h"
#include "log.h"
#include "terminal_colors.h"

// --- Function Prototypes ---
void run_simulation_cycle(void);
void platform_sleep(unsigned int seconds);

// Main entry point: initializes subsystems and runs the core simulation loop.
int main() {
    // Seed the random number generator once at startup for unique simulation runs.
    srand(time(NULL));

    // Initialize the event logger.
    log_init("log.txt");
    printf(COLOR_GREEN "ADAS Simulator Initialized. Press Ctrl+C to exit.\n" COLOR_NORMAL);
    printf("---------------------------------------------------\n");

    // Main simulation loop mimics a real-time OS scheduler executing periodic tasks.
    while (1) {
        run_simulation_cycle();
        platform_sleep(1); // Execute the simulation cycle every 1 second.
    }

    // Unreachable in this design, but good practice for completeness.
    log_close();
    return 0;
}

// Executes one full cycle of sensor reading, data processing, and alert generation.
void run_simulation_cycle(void) {
    // 1. Simulate Sensor Data Acquisition
    int left_sensor_dist = get_random_distance();
    int right_sensor_dist = get_random_distance();
    LanePosition lane_pos = get_lane_position();

    // 2. Process Data and Check for Events
    BlindSpotAlert bsd_alert = check_blind_spot(left_sensor_dist, right_sensor_dist);
    LaneDepartureAlert ld_alert = check_lane_departure(lane_pos);

    // 3. Display Current System Status to the console.
    const char* lane_status_str[] = {"CENTER", "LEFT_DRIFT", "RIGHT_DRIFT"};
    printf(COLOR_CYAN "[OK] " COLOR_NORMAL "Lane: %-12s| Left: %3d cm | Right: %3d cm\n",
           lane_status_str[lane_pos], left_sensor_dist, right_sensor_dist);

    // 4. Generate Alerts based on detected events.
    if (bsd_alert != BSD_ALERT_NONE) {
        generate_blind_spot_alert(bsd_alert, (bsd_alert == BSD_ALERT_LEFT) ? left_sensor_dist : right_sensor_dist);
    }

    if (ld_alert != LD_ALERT_NONE) {
        generate_lane_departure_alert(ld_alert);
    }
}

// Provides a cross-platform method to pause execution for a specified duration.
void platform_sleep(unsigned int seconds) {
    #ifdef _WIN32
        Sleep(seconds * 1000); // Sleep takes milliseconds on Windows.
    #else
        sleep(seconds);        // sleep takes seconds on Unix-like systems.
    #endif
}