# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -O3


# Source files
CLEQUE_SRCS = cleque_ptr.c cleque_test.c ../time_bench/test_timing.c

# Object files (one for each source file)
CLEQUE_OBJS = $(CLEQUE_SRCS:.c=.o)

# Executable name
CLEQUE_EXEC = cleque_test

# Default target
all: $(CLEQUE_EXEC) 


# Link object files to create the executable
$(CLEQUE_EXEC): $(CLEQUE_OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean: 
	rm -f $(CLEQUE_OBJS) $(CLEQUE_EXEC) 

# Phony targets
.PHONY: all clean

