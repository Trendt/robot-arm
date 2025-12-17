#include "servo.h"

#include <cstdlib>
#include <unistd.h>

int main(int argc, char *argv[]) {
  int i2c_fd;
  char *filename = (char *)"/dev/i2c-1";

  i2c_fd = servo_hat::setup_i2c(filename);
  while (true) {
    servo_hat::write_pwm_register(i2c_fd, 0, 1000);
    sleep(3);
    servo_hat::write_pwm_register(i2c_fd, 0, 2000);
    sleep(3);
  }

  return EXIT_SUCCESS;
}
