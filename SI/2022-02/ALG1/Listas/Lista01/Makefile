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

$(OBJ_DIR)/1a.o: ./src/1a.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(INCLUDE) -g -o $@ -c ./src/1a.cpp

$(OBJ_DIR)/1b.o: ./src/1b.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(INCLUDE) -g -o $@ -c ./src/1b.cpp

$(OBJ_DIR)/1c.o: ./src/1c.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(INCLUDE) -g -o $@ -c ./src/1c.cpp

build:
	@mkdir -p $(APP_DIR)
	@mkdir -p $(OBJ_DIR)

1a: $(OBJ_DIR)/1a.o
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(INCLUDE) -g -o $(APP_DIR)/$@ ./objects/1a.o $(LDFLAGS)

1b: $(OBJ_DIR)/1b.o
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(INCLUDE) -g -o $(APP_DIR)/$@ ./objects/1b.o $(LDFLAGS)

1c: $(OBJ_DIR)/1c.o
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(INCLUDE) -g -o $(APP_DIR)/$@ ./objects/1c.o $(LDFLAGS)

teste: $(OBJ_DIR)/teste.o
	$(CXX) $(CXXFLAGS) $(INCLUDE) -g -o $(APP_DIR)/$@ ./objects/teste.o $(LDFLAGS)

all: build 1a 1b teste