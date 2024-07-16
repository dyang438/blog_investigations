# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c99


# Source files
CLEQUE_SRCS = cleque_ptr.c cleque_test.c test_timing.c
DEQUE_SRCS = deque.c deque_test.c test_timing.c

# Object files (one for each source file)
CLEQUE_OBJS = $(CLEQUE_SRCS:.c=.o)
DEQUE_OBJS = $(DEQUE_SRCS:.c=.o)

# Executable name
CLEQUE_EXEC = cleque_test
DEQUE_EXEC = deque_test

# Default target
all: $(CLEQUE_EXEC) $(DEQUE_EXEC)

# Link object files to create the executable
$(CLEQUE_EXEC): $(CLEQUE_OBJS)
	$(CC) $(CFLAGS) -o $@ $^

$(DEQUE_EXEC): $(DEQUE_OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Compile source files to object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean target to remove compiled files
clean:
	rm -f $(CLEQUE_OBJS) $(CLEQUE_EXEC) $(DEQUE_OBJS) $(DEQUE_EXEC)

# Phony targets
.PHONY: all clean

