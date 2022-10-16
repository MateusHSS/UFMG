CXX      := -g++
# CXXFLAGS := -Wall -Wextra -Werror
LDFLAGS  := -lstdc++ -lm
BUILD    := ./
OBJ_DIR  := $(BUILD)objects
APP_DIR  := ./
TARGET   := tp1
INCLUDE  := -Iinclude/

$(OBJ_DIR)/teste.o: ./src/teste.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(INCLUDE) -g -o $@ -c ./src/teste.cpp

build:
	@mkdir -p $(APP_DIR)
	@mkdir -p $(OBJ_DIR)

1b:
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(INCLUDE) -g -o $(APP_DIR)/$@ ./objects/1b.o $(LDFLAGS)

teste: $(OBJ_DIR)/teste.o
	$(CXX) $(CXXFLAGS) $(INCLUDE) -g -o $(APP_DIR)/$@ ./objects/teste.o $(LDFLAGS)

all: build 1b teste