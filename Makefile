# Makefile for ADAS Simulator Project

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -g

# Source files
SRCS = main.c sensor_simulation.c blind_spot.c lane_detection.c alert.c log.c

# Object files
OBJS = $(SRCS:.c=.o)

# Executable name
TARGET = adas

# Default target
all: $(TARGET)

# Link object files to create the executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Compile source files into object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up build files
clean:
	rm -f $(OBJS) $(TARGET) log.txt

# Phony targets
.PHONY: all clean

