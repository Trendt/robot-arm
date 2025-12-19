# TODO: cross-compile
# CXX = arm-linux-gnueabihf-g++
CXX = g++
CXXFLAGS = -Wall -Wextra

BUILD_DIR=build

SRC = \
	$(wildcard src/*.cpp) \
	$(wildcard src/hardware/*.cpp) \
	$(wildcard src/joints/*.cpp) \
	$(wildcard src/kinematics/*.cpp)
HEADERS = \
	$(wildcard src/*.h) \
	$(wildcard src/hardware/*.h) \
	$(wildcard src/joints/*.h) \
	$(wildcard src/kinematics/*.h)
TARGET = $(BUILD_DIR)/robot_arm_bin

INCLUDES := \
	-Isrc \
	-Isrc/hardware \
	-Isrc/joints \
	-Isrc/kinematics \
	-Isrc/motion \

CXXFLAGS += $(INCLUDES)

USER = robot
HOST = 192.168.0.194
DEST_DIR = /home/robot/robot-arm/

.PHONY=all clean upload

all: $(SRC) $(TARGET)

$(TARGET): build_dir $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

build_dir:
	mkdir -p $(BUILD_DIR)

clean:
	rm -rf $(BUILD_DIR)

build: upload
	ssh $(USER)@$(HOST) "cd $(DEST_DIR) && make all"

run: all
	"./$(TARGET)"

upload: $(SRC) $(HEADERS) Makefile
	rsync -avz --progress Makefile $(USER)@$(HOST):$(DEST_DIR)
	rsync -avz --progress src/ $(USER)@$(HOST):$(DEST_DIR)/src

uploadrun: upload
	ssh $(USER)@$(HOST) "cd $(DEST_DIR) && make run"
