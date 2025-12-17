#include <fcntl.h>
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>
#include <unistd.h>

namespace servo_hat {
    const int I2C_ADDRESS = 0x40;

    const int PWM_FREQUENCY = 50;

    const int BASE_START_ADDRESS = 0x06;
    const int BASE_STOP_ADDRESS = 0x40;

    const int START_OFFSET = sizeof(char) * 4;
    const int STOP_OFFSET = sizeof(char) * 4;

    /**
     * @return i2c file descriptor
     */
    int setup_i2c(char *filename);
    void write_pwm_register(int i2c_fd, int channel, int stop_time);
} // namespace servo_hat

