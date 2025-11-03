# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -O3

# Source files
HASHING_SRCS = hashing.cpp hashing_test.cpp ../t

# Object files (one for each source file)
HASHING_OBJS = $(HASHING_SRCS:.cpp=.o)

# Executable name
HASHING_EXEC = hashing_test

# Default target
all: $(HASHING_EXEC)

# Link object files to create the executable
$(HASHING_EXEC): $(HASHING_OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(HASHING_OBJS) $(HASHING_EXEC)

# Phony targets
.PHONY: all clean
