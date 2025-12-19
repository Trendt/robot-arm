#include "../hardware/PWMLimits.h"
#include "../joints/joint_limits.h"

constexpr PWMLimits   servo1_pwm_limits   {460, 2540};
constexpr JointLimits servo1_joint_limits {45.0, 135.0};

constexpr PWMLimits   servo2_pwm_limits   {460, 2540};
constexpr JointLimits servo2_joint_limits {20.0, 160.0};

constexpr PWMLimits   servo3_pwm_limits   {460, 2540};
constexpr JointLimits servo3_joint_limits {0.0, 125.0};

constexpr PWMLimits   servo4_pwm_limits   {460, 2540};
constexpr JointLimits servo4_joint_limits {0.0, 180.0};
