# Compiler & Flags
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -Iinclude

# Sources
SRCS = main.cpp src/shell.cpp src/terminal.cpp src/alias.cpp

# Object files (auto .cpp to .o)
OBJS = $(SRCS:.cpp=.o)

# Output binary
TARGET = app

# Default target
all: $(TARGET)

# Link objects to binary
$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET)

# Compile .cpp → .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean build
clean:
	rm -f $(OBJS) $(TARGET)
