#include "I2CDevice.h"
#include "RobotArm.h"

#include <exception>
#include <iostream>
#include <unistd.h>

const int I2C_ADDRESS = 0x40;

int main() {
  try {
    I2CDevice servoController("/dev/i2c-1", I2C_ADDRESS);
    RobotArm arm(servoController);

    arm.home();
    sleep(1);
    for (double i = 0.0; i <= 1.0; i += 0.1) {
      double angle = i * 180.0;
      arm.servo1.setAngle(angle);
      usleep(500000);
    }

    arm.home();
    sleep(1);
    for (double i = 0.0; i <= 1.0; i += 0.1) {
      double angle = i * 180.0;
      arm.servo2.setAngle(angle);
      usleep(500000);
    }

    arm.home();
    sleep(1);
    for (double i = 0.0; i <= 1.0; i += 0.1) {
      double angle = i * 180.0;
      arm.servo3.setAngle(angle);
      usleep(500000);
    }

    arm.home();
    sleep(1);
    arm.unstiff();
  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}
