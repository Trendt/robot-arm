#include "I2CDevice.h"
#include "RobotArm.h"

#include <cstdlib>
#include <exception>
#include <iostream>
#include <ostream>

const int I2C_ADDRESS = 0x40;
const int PWM_FREQUENCY = 50;

int main() {
  try {
    I2CDevice servoController("/dev/i2c-1", I2C_ADDRESS);
    RobotArm arm(servoController);

    arm.home();

    sleep(3);
    arm.setPWM(1500, 1250, 1500);
    sleep(3);

    arm.home();

    arm.unstiff();
  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}
