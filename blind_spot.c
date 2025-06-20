#include "blind_spot.h"

// The distance threshold in centimeters for triggering a blind spot alert.
#define BLIND_SPOT_THRESHOLD_CM 100

// Returns an alert if either sensor reading is below the defined safety threshold.
BlindSpotAlert check_blind_spot(int left_distance_cm, int right_distance_cm) {
    // Prioritize the left side if both are triggered.
    if (left_distance_cm < BLIND_SPOT_THRESHOLD_CM) {
        return BSD_ALERT_LEFT;
    }
    if (right_distance_cm < BLIND_SPOT_THRESHOLD_CM) {
        return BSD_ALERT_RIGHT;
    }
    return BSD_ALERT_NONE; // Return no alert if no objects are within the threshold.
}