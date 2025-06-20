#ifndef BLIND_SPOT_H
#define BLIND_SPOT_H

// Defines the status of the blind spot detection system.
typedef enum {
    BSD_ALERT_NONE,  // No object detected.
    BSD_ALERT_LEFT,  // Object detected in the left blind spot.
    BSD_ALERT_RIGHT  // Object detected in the right blind spot.
} BlindSpotAlert;

// Checks sensor data against a threshold to detect objects in blind spots.
BlindSpotAlert check_blind_spot(int left_distance_cm, int right_distance_cm);

#endif // BLIND_SPOT_H