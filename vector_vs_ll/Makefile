# The C compilation is only needed if you would like to see how my C deque (implemented in std::list style) performs

# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -Wextra -O3 -std=c++11

CC = gcc
CFLAGS = -Wall -std=c99 -O3

#Source Files
VIR_SRCS = virtual_main.cpp ../time_bench/cpp_test.cpp

CXX_SRCS = main.cpp ../time_bench/cpp_test.cpp 
C_SRCS = ../deque_cache/deque.c

# Object files (one for each source file)
VIR_OBJS = $(VIR_SRCS:.cpp=.o)

CXX_OBJS = $(CXX_SRCS:.cpp=.o)
C_OBJS = $(C_SRCS:.c=.o)
OBJS = $(CXX_OBJS) $(C_OBJS)

# Executable name
VIR_EXEC = vir_target
EXEC = target

# Default target
all: $(EXEC) $(VIR_EXEC)

# Link object files to create the executable
$(EXEC): $(OBJS)
	$(CXX) $(OBJS) -o $(EXEC)

$(VIR_EXEC): $(VIR_OBJS)
	$(CXX) $(VIR_OBJS) -o $(VIR_EXEC)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean: 
	rm -f $(OBJS) $(EXEC) $(VIR_EXEC) $(VIR_OBJS)

# Phony targets
.PHONY: all clean

