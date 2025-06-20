#ifndef LANE_DETECTION_H
#define LANE_DETECTION_H

#include "sensor_simulation.h" // Requires the LanePosition enum definition.

// Defines the status of the lane departure warning system.
typedef enum {
    LD_ALERT_NONE,             // Vehicle is centered in the lane.
    LD_ALERT_LEFT_DEPARTURE,   // Vehicle is drifting to the left.
    LD_ALERT_RIGHT_DEPARTURE   // Vehicle is drifting to the right.
} LaneDepartureAlert;

// Determines if the vehicle has drifted from its lane based on camera input.
LaneDepartureAlert check_lane_departure(LanePosition current_pos);

#endif // LANE_DETECTION_H