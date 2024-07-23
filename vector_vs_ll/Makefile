# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -O3


# Source files
TEST_SRCS = main.cpp ../time_bench/test_timing.c

# Object files (one for each source file)
TEST_OBJS = $(TEST_SRCS:.c=.o)

# Executable name
TEST_EXEC = test_test

# Default target
all: $(TEST_EXEC) 


# Link object files to create the executable
$(TEST_EXEC): $(TEST_OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean: 
	rm -f $(TEST_OBJS) $(TEST_EXEC) 

# Phony targets
.PHONY: all clean

