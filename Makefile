# CXX = arm-linux-gnueabihf-g++
CXX = g++
CXXFLAGS = -Wall -Wextra

BUILD_DIR=build

SRC = $(wildcard src/*.cpp)
HEADERS = $(wildcard src/*.h)
TARGET = $(BUILD_DIR)/robot_arm_bin

USER = robot
HOST = 192.168.0.194
DEST_DIR = /home/robot/robot-arm/

.PHONY=all clean upload

all: $(SRC) $(TARGET)

$(TARGET): $(BUILD_DIR) $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

clean:
	rm -rf $(BUILD_DIR)

build: upload
	ssh $(USER)@$(HOST) "cd $(DEST_DIR) && make all"

run: all
	"./$(TARGET)"

upload: $(SRC) $(HEADERS) Makefile
	rsync -avz --progress src/ Makefile $(USER)@$(HOST):$(DEST_DIR)/src

uploadrun: upload
	ssh $(USER)@$(HOST) "cd $(DEST_DIR) && make run"
