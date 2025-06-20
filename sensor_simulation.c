#include <stdlib.h>
#include "sensor_simulation.h"

// Defines the realistic operational range for the simulated sensor.
#define MIN_DISTANCE 50  // 50 cm
#define MAX_DISTANCE 200 // 200 cm

// Generates a pseudo-random distance within a realistic range.
int get_random_distance(void) {
    return MIN_DISTANCE + rand() % (MAX_DISTANCE - MIN_DISTANCE + 1);
}

// Generates a pseudo-random lane position.
LanePosition get_lane_position(void) {
    // Randomly returns 0, 1, or 2, which maps to the LanePosition enum.
    return (LanePosition)(rand() % 3);
}