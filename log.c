#include <stdio.h>
#include <time.h>
#include "log.h"

// A static file pointer ensures it's only accessible within this module.
static FILE* log_file = NULL;

// Initializes the logger by opening a file in append mode.
int log_init(const char* filename) {
    // "a" creates the file if it doesn't exist, and appends if it does.
    log_file = fopen(filename, "a");
    if (log_file == NULL) {
        perror("Error: Could not open log file");
        return -1; // Return an error code on failure.
    }
    fprintf(log_file, "\n--- ADAS Log Session Started at %s ---\n", __TIME__);
    fflush(log_file); // Ensure the init message is written to disk immediately.
    return 0; // Success.
}

// Appends a formatted, timestamped event message to the open log file.
void log_event(const char* message) {
    if (log_file == NULL) {
        return; // Fail silently if the logger was not initialized.
    }

    // Get the current system time.
    time_t now = time(NULL);
    struct tm* t = localtime(&now);

    // Format the time into a [HH:MM:SS] string.
    char time_buffer[16];
    strftime(time_buffer, sizeof(time_buffer), "[%H:%M:%S]", t);

    // Write the timestamp and the message to the log file.
    fprintf(log_file, "%s %s\n", time_buffer, message);
    
    // Flush the buffer to ensure the log entry is written immediately.
    fflush(log_file);
}

// Closes the log file if it's open. Should be called on program exit.
void log_close(void) {
    if (log_file != NULL) {
        fprintf(log_file, "--- Log Session Ended ---\n");
        fclose(log_file);
        log_file = NULL; // Prevent dangling pointer issues.
    }
}