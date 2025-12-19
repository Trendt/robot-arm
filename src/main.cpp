#include "I2CDevice.h"
#include "RobotArm.h"

#include <cstdint>
#include <iostream>
#include <unistd.h>

const int I2C_ADDRESS = 0x40;

int main() {
  try {
    I2CDevice servoController("/dev/i2c-1", I2C_ADDRESS);
    RobotArm arm(servoController);
    arm.unstiff();

    while (true) {
      arm.servo4.setAngle(0.0);
      usleep(750000);

      arm.servo4.setAngle(90.0);
      usleep(750000);

      arm.servo4.setAngle(180.0);
      usleep(750000);
    }

    // arm.home();
    // sleep(1);

    // for (double i = 0.0; i <= 180.0; i+= 10.0) {
    //     arm.setAngles(90.0, 90.0, 90.0, i);
    //     sleep(1);
    // }
    // arm.home();
    // sleep(1);
  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}
