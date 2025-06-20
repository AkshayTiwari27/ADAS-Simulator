#ifndef ALERT_H
#define ALERT_H

#include "blind_spot.h"
#include "lane_detection.h"

// Generates and displays a blind spot alert.
void generate_blind_spot_alert(BlindSpotAlert alert_type, int distance_cm);

// Generates and displays a lane departure alert.
void generate_lane_departure_alert(LaneDepartureAlert alert_type);

#endif // ALERT_H