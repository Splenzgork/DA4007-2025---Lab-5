# Compiler
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2

# Executable name
TARGET = slm

# Source files
SRC = main.cpp slm.cpp rng.cpp

# Object files
OBJ = $(SRC:.cpp=.o)

# Default rule
all: $(TARGET)

# Link object files into the final executable
$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compile .cpp files into .o files
%.o: %.cpp %.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up
clean:
	rm -f $(OBJ) $(TARGET)

.PHONY: all clean