# Compiler settings
CXX = c++
CXXFLAGS = -std=c++17 -Wall -O2
DEBUG_FLAGS = -g -fsanitize=address

# Directories
BIN_DIR = bin

# Source files
SOURCES = allocator_struct.cpp allocator_bitarr.cpp allocator_vector.cpp

# Executable names (in bin directory)
EXECUTABLES = $(BIN_DIR)/allocator_struct $(BIN_DIR)/allocator_bitarr $(BIN_DIR)/allocator_vector

# Header dependencies
HEADERS = ParentClass.h ChildClass.h benchmark.h config.h

# Default target: build all executables
all: $(BIN_DIR) $(EXECUTABLES)

# Create bin directory
$(BIN_DIR):
	mkdir -p $(BIN_DIR)

# Pattern rule: compile each .cpp file to executable in bin/
$(BIN_DIR)/%: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) $< -o $@

# Debug builds with sanitizer
debug: CXXFLAGS += $(DEBUG_FLAGS)
debug: clean all

# Run all benchmarks
bench: all
	@echo "Running all benchmarks...\n"
	@$(BIN_DIR)/allocator_struct
	@echo ""
	@$(BIN_DIR)/allocator_bitarr
	@echo ""
	@$(BIN_DIR)/allocator_vector

# Clean build artifacts
clean:
	rm -rf $(BIN_DIR)

# Rebuild everything
rebuild: clean all

.PHONY: all debug bench clean rebuild
