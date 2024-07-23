# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -Wextra -O3

CC = gcc
CFLAGS = -Wall -Wextra -O3

#Source Files
SRCS = main.cpp ../time_bench/cpp_test.cpp ../deque_cache/deque.c

# Object files (one for each source file)
OBJS = $(SRCS:.cpp=.o) $(SRCS:.c=.o)

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

