#include <stdio.h>
#include "alert.h"
#include "log.h"
#include "terminal_colors.h"

// Formats and prints a blind spot warning to the console and logs the event.
void generate_blind_spot_alert(BlindSpotAlert alert_type, int distance_cm) {
    char alert_msg[100];
    const char* side = (alert_type == BSD_ALERT_LEFT) ? "LEFT" : "RIGHT";

    // Format the alert message.
    snprintf(alert_msg, sizeof(alert_msg), "Blind Spot Alert: Object on %s, Distance = %dcm", side, distance_cm);
    
    // Print the alert to the console in yellow.
    printf(COLOR_YELLOW "[!!] %s\n" COLOR_NORMAL, alert_msg);
    
    // Log the event to a file (without color codes).
    log_event(alert_msg);
}

// Formats and prints a lane departure warning to the console and logs the event.
void generate_lane_departure_alert(LaneDepartureAlert alert_type) {
    char alert_msg[100];
    const char* direction = (alert_type == LD_ALERT_LEFT_DEPARTURE) ? "LEFT" : "RIGHT";

    // Format the alert message.
    snprintf(alert_msg, sizeof(alert_msg), "Lane Drift Alert: Drifting %s", direction);

    // Print the alert to the console in red.
    printf(COLOR_RED "[!!] %s\n" COLOR_NORMAL, alert_msg);

    // Log the event to a file (without color codes).
    log_event(alert_msg);
}