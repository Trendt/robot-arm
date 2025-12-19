#include "I2CDevice.h"

I2CDevice::I2CDevice(const char *device, uint8_t address) {
  i2c_fd = open(device, O_RDWR);

  if (i2c_fd < 0)
    throw std::runtime_error("Failed to open I2C device");

  if (ioctl(i2c_fd, I2C_SLAVE, address) < 0) {
    close(i2c_fd);
    throw std::runtime_error("Failed to set I2C address");
  }
}

I2CDevice::~I2CDevice() { close(i2c_fd); }

void I2CDevice::writeValue(uint8_t reg, uint16_t value) {
  uint8_t data[3] = {
      reg,
      (uint8_t)(value & 0xff),
      (uint8_t)((value >> 8) & 0xff),
  };

  if (write(i2c_fd, data, 3) != 3) {
    throw std::runtime_error("Failed to write to I2C device");
  }
}

void I2CDevice::writeValue(uint8_t reg, uint8_t value) {
  uint8_t data[2] = {reg, value};
  if (write(i2c_fd, data, 2) != 2) {
    throw std::runtime_error("Failed to write to I2C device");
  }
}

void I2CDevice::writeBuffer(uint8_t buffer[], ssize_t buffer_size) {
  if (write(i2c_fd, buffer, buffer_size) != buffer_size) {
    throw std::runtime_error("Failed to write to I2C device");
  }
}

void I2CDevice::setFlag(uint8_t reg, uint8_t flag) {
  uint8_t old = readRegister(reg);

  uint8_t data[2] = {reg, static_cast<uint8_t>(old | flag)};
  if (write(i2c_fd, data, 2) != 2) {
    throw std::runtime_error("Failed to write to I2C device");
  }
}

// todo: check
void I2CDevice::unsetFlag(uint8_t reg, uint8_t flag) {
  uint8_t old = readRegister(reg);

  uint8_t data[2] = {reg, static_cast<uint8_t>(old & ~flag)};
  if (write(i2c_fd, data, 2) != 2) {
    throw std::runtime_error("Failed to write to I2C device");
  }
}

uint8_t I2CDevice::readRegister(uint8_t reg) {
  if (write(i2c_fd, &reg, 1) != 1) {
    throw std::runtime_error("Failed to get register");
  }

  uint8_t value;
  if (read(i2c_fd, &value, 1) != 1) {
    throw std::runtime_error("Failed to read data from register");
  }

  return value;
};
