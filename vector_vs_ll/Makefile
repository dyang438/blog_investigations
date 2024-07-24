# Compilation currently doesn't work on windows for me, OpenSUSE and Arch work currently though.
# The C compilation is only needed if you would like to see how my C deque (implemented in std::list style) performs

# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -Wextra -O3

CC = gcc
CFLAGS = -Wall -std=c99 -O3

#Source Files
CXX_SRCS = main.cpp ../time_bench/cpp_test.cpp 
C_SRCS = ../deque_cache/deque.c

# Object files (one for each source file)
CXX_OBJS = $(CXX_SRCS:.cpp=.o)
C_OBJS = $(C_SRCS:.c=.o)
OBJS = $(CXX_OBJS) $(C_OBJS)

# Executable name
EXEC = target

# Default target
all: $(EXEC) 

# Link object files to create the executable
$(EXEC): $(OBJS)
	$(CXX) $(OBJS) -o $(EXEC)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean: 
	rm -f $(OBJS) $(EXEC) 

# Phony targets
.PHONY: all clean

