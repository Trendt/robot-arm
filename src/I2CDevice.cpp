#include "I2CDevice.h"

I2CDevice::I2CDevice(const char *device, uint8_t address){
    i2c_fd = open(device, O_RDWR);

    if (i2c_fd < 0) throw std::runtime_error("Failed to open I2C device");

    if (ioctl(i2c_fd, I2C_SLAVE, address) < 0) {
        close(i2c_fd);
        throw std::runtime_error("Failed to set I2C address");
    }

    uint8_t buffer[2];
    // enable chip
    buffer[0] = 0;
    buffer[1] = 0x20;
    write(i2c_fd, buffer, 2);

    // enable multi-byte writing
    buffer[0] = 0xfe;
    buffer[1] = 0x1e;
    write(i2c_fd, buffer, 2);
}

I2CDevice::~I2CDevice(){
    // disable chip
    uint8_t buffer[2];
    buffer[0] = 0;
    buffer[1] = 0;
    write(i2c_fd, buffer, 2);

    close(i2c_fd);
}

void I2CDevice::writeByte(uint8_t reg, uint8_t value){
  uint8_t data[2] = { reg, value };
  if (write(i2c_fd, data, 2) != 2) {
      throw std::runtime_error("Failed to write to I2C device");
  }
}

void I2CDevice::writeBuffer(uint8_t buffer[], ssize_t buffer_size) {
  if (write(i2c_fd, buffer, buffer_size) != buffer_size) {
    throw std::runtime_error("Failed to write to I2C device");
  }
}
