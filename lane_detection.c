#include "lane_detection.h"

// Translates the vehicle's lane position into a specific departure alert.
LaneDepartureAlert check_lane_departure(LanePosition current_pos) {
    switch (current_pos) {
        case LEFT_DRIFT:
            return LD_ALERT_LEFT_DEPARTURE;
        case RIGHT_DRIFT:
            return LD_ALERT_RIGHT_DEPARTURE;
        case CENTER:
        default:
            return LD_ALERT_NONE; // No alert if centered.
    }
}