CXX = arm-linux-gnueabihf-g++
CXXFLAGS = -Wall -Wextra

SOURCES = main.cpp servo.cpp
TARGET = robot_arm_bin

all: $(TARGET)

$(TARGET): $(SOURCES)
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $(TARGET)

clean:
	rm -f $(TARGET)

copy: $(TARGET)
	scp $(TARGET) robot@192.168.0.194:/home/robot/$(TARGET)
