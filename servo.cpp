#include "servo.h"

void servo_hat::write_pwm_register(int i2c_fd, int channel, int pulse_width) {
  char buffer[3];

  // write start time
  buffer[0] = 0x06 << channel*START_OFFSET;
  buffer[1] = 0;
  buffer[2] = 0;
  write(i2c_fd, buffer, 3);

  // write stop time
  buffer[0] = 0x08 << channel*START_OFFSET;
  buffer[1] = (char)(pulse_width & 0xff);
  buffer[2] = (char)((pulse_width >> 8) & 0xff);
  write(i2c_fd, buffer, 3);
}

int servo_hat::setup_i2c(char *filename) {
  int i2c_fd;
  i2c_fd = open(filename, O_RDWR);
  if (i2c_fd < 0) {
    return -1;
  }

  ioctl(i2c_fd, I2C_SLAVE, servo_hat::I2C_ADDRESS);

  char buffer[5];

  // enable chip
  buffer[0] = 0;
  buffer[1] = 0x20;
  write(i2c_fd, buffer, 2);

  // enable multi-byte writing
  buffer[0] = 0xfe;
  buffer[1] = 0x1e;
  write(i2c_fd, buffer, 2);

  return i2c_fd;
}
