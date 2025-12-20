#include "RobotArm.h"
#include "hardware/I2CDevice.h"
#include <exception>
#include <iostream>
#include <unistd.h>

const int I2C_ADDRESS = 0x40;

int main() {
  try {
    I2CDevice i2c_device("/dev/i2c-1", I2C_ADDRESS);
    PWMController pwm_controller(i2c_device);
    RobotArm arm(pwm_controller);

    arm.home();
    arm.update(0.0);

    sleep(1);
    for (double i = 0.0; i <= 1.0; i += 0.1) {
      double angle = i * 180.0;
      arm.servo1.setAngle(angle);
      arm.update(0.0);
      usleep(500000);
    }

    arm.home();
    sleep(1);
    for (double i = 0.0; i <= 1.0; i += 0.1) {
      double angle = i * 180.0;
      arm.servo2.setAngle(angle);
      arm.update(0.0);
      usleep(500000);
    }

    arm.home();
    sleep(1);
    for (double i = 0.0; i <= 1.0; i += 0.1) {
      double angle = i * 180.0;
      arm.servo3.setAngle(angle);
      arm.update(0.0);
      usleep(500000);
    }

    arm.home();
    arm.update(0.0);
    sleep(1);
    arm.unstiff();
  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}
