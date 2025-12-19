#ifndef I2CDEVICE_H_
#define I2CDEVICE_H_

#include <cstddef>
#include <cstdint>
#include <fcntl.h>
#include <linux/i2c-dev.h>
#include <stdexcept>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <unistd.h>

class I2CDevice {
public:
  I2CDevice(const char *device, uint8_t address);
  ~I2CDevice();

  void writeValue(uint8_t reg, uint8_t value);
  void writeValue(uint8_t reg, uint16_t value);
  void writeBuffer(uint8_t buffer[], ssize_t buffer_size);

  void setFlag(uint8_t reg, uint8_t flag);
  void unsetFlag(uint8_t reg, uint8_t flag);

  uint8_t readRegister(uint8_t reg);

private:
  int i2c_fd;
};

#endif // !I2CDEVICE_H_
