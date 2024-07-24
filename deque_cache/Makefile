# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -O3


# Source files
DEQUE_NORMAL_SRCS = deque.c deque_normal.c ../time_bench/test_timing.c
DEQUE_MOV_SRCS = deque.c deque_test_moving.c ../time_bench/test_timing.c
DEQUE_FRAG_SRCS = deque.c deque_frag.c ../time_bench/test_timing.c

# Object files (one for each source file)
DEQUE_NORMAL_OBJS = $(DEQUE_NORMAL_SRCS:.c=.o)
DEQUE_MOV_OBJS = $(DEQUE_MOV_SRCS:.c=.o)
DEQUE_FRAG_OBJS = $(DEQUE_FRAG_SRCS:.c=.o)

# Executable name
DEQUE_NORMAL_EXEC = deque_normal
DEQUE_MOV_EXEC = deque_test_moving
DEQUE_FRAG_EXEC = deque_frag

# Default target
all: $(DEQUE_NORMAL_EXEC) $(DEQUE_MOV_EXEC) $(DEQUE_FRAG_EXEC)

# Link object files to create the executable
$(DEQUE_NORMAL_EXEC): $(DEQUE_NORMAL_OBJS)
	$(CC) $(CFLAGS) -o $@ $^

$(DEQUE_MOV_EXEC): $(DEQUE_MOV_OBJS)
	$(CC) $(CFLAGS) -o $@ $^
	
$(DEQUE_FRAG_EXEC): $(DEQUE_FRAG_OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Compile source files to object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean target to remove compiled files
clean:
	rm -f $(DEQUE_NORMAL_OBJS) $(DEQUE_NORMAL_EXEC) $(DEQUE_MOV_OBJS) $(DEQUE_MOV_EXEC) $(DEQUE_FRAG_OBJS) $(DEQUE_FRAG_EXEC)

# Phony targets
.PHONY: all clean

