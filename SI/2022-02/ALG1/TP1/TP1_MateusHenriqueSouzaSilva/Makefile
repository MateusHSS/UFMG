CXX      := -g++
# CXXFLAGS := -Wall -Wextra -Werror
LDFLAGS  := -lstdc++ -lm
BUILD    := ./
OBJ_DIR  := $(BUILD)/objects
APP_DIR  := ./
TARGET   := tp1
INCLUDE  := -Iinclude/
SRC      :=  $(wildcard src/*.cpp)


OBJECTS := $(SRC:%.cpp=$(OBJ_DIR)/%.o)

all: build $(APP_DIR)/$(TARGET)

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(INCLUDE) -g -o $@ -c $<

$(APP_DIR)/$(TARGET): $(OBJECTS)
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(INCLUDE) -g -o $(APP_DIR)/$(TARGET) $(OBJECTS) $(LDFLAGS)

build:
	@mkdir -p $(APP_DIR)
	@mkdir -p $(OBJ_DIR)

run:
	./$(BUILD)/$(TARGET) < teste.txt

r: all run