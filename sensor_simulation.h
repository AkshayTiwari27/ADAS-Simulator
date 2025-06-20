#ifndef SENSOR_SIMULATION_H
#define SENSOR_SIMULATION_H

// Represents the vehicle's position relative to the lane center.
typedef enum {
    CENTER,
    LEFT_DRIFT,
    RIGHT_DRIFT
} LanePosition;

// Simulates a reading from a distance sensor (e.g., radar, ultrasonic).
int get_random_distance(void);

// Simulates a reading from a lane-tracking camera.
LanePosition get_lane_position(void);

#endif // SENSOR_SIMULATION_H