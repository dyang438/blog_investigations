# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -O3


# Source files
CLEQUE_SRCS = cleque_ptr.c cleque_test.c test_timing.c
DEQUE_NORMAL_SRCS = deque.c deque_normal.c test_timing.c
DEQUE_MOV_SRCS = deque.c deque_test_moving.c test_timing.c
DEQUE_PERF_SRCS = deque.c deque_perf.c
DEQUE_FRAG_SRCS = deque.c deque_frag.c test_timing.c

# Object files (one for each source file)
CLEQUE_OBJS = $(CLEQUE_SRCS:.c=.o)
DEQUE_NORMAL_OBJS = $(DEQUE_NORMAL_SRCS:.c=.o)
DEQUE_MOV_OBJS = $(DEQUE_MOV_SRCS:.c=.o)
DEQUE_PERF_OBJS = $(DEQUE_PERF_SRCS:.c=.o)
DEQUE_FRAG_OBJS = $(DEQUE_FRAG_SRCS:.c=.o)

# Executable name
CLEQUE_EXEC = cleque_test
DEQUE_NORMAL_EXEC = deque_normal
DEQUE_MOV_EXEC = deque_test_moving
DEQUE_PERF_EXEC = deque_perf
DEQUE_FRAG_EXEC = deque_frag

# Default target
all: $(CLEQUE_EXEC) $(DEQUE_NORMAL_EXEC) $(DEQUE_MOV_EXEC) $(DEQUE_PERF_EXEC) $(DEQUE_FRAG_EXEC)

# Link object files to create the executable
$(CLEQUE_EXEC): $(CLEQUE_OBJS)
	$(CC) $(CFLAGS) -o $@ $^

$(DEQUE_NORMAL_EXEC): $(DEQUE_NORMAL_OBJS)
	$(CC) $(CFLAGS) -o $@ $^

$(DEQUE_MOV_EXEC): $(DEQUE_MOV_OBJS)
	$(CC) $(CFLAGS) -o $@ $^
	
$(DEQUE_PERF_EXEC): $(DEQUE_PERF_OBJS)
	$(CC) $(CFLAGS) -o $@ $^

$(DEQUE_FRAG_EXEC): $(DEQUE_FRAG_OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Compile source files to object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean target to remove compiled files
clean:
	rm -f $(CLEQUE_OBJS) $(CLEQUE_EXEC) $(DEQUE_NORMAL_OBJS) $(DEQUE_NORMAL_EXEC) $(DEQUE_MOV_OBJS) $(DEQUE_MOV_EXEC) $(DEQUE_PERF_OBJS) $(DEQUE_PERF_EXEC) $(DEQUE_FRAG_OBJS) $(DEQUE_FRAG_EXEC)

# Phony targets
.PHONY: all clean

