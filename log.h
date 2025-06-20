#ifndef LOG_H
#define LOG_H

// Opens the specified log file for writing; must be called first.
int log_init(const char* filename);

// Writes a timestamped message to the initialized log file.
void log_event(const char* message);

// Closes the log file, releasing system resources.
void log_close(void);

#endif // LOG_H