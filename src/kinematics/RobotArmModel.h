#include "ForwardKinematics.h"

// TODO: measure position & rotation offsets
// TODO: Export into config somewhere smh
constexpr KinematicJoint servo1_kinematic_joint {
  .rotationAxis = { 0.0, 0.0, 1.0 },
  .parentToJoint = {
    .position = { 0.0, 0.0, 0.0 },
    .rotation = {
      0.0, 0.0, 0.0,
      0.0, 0.0, 0.0,
      0.0, 0.0, 0.0
    },
  }
};

constexpr KinematicJoint servo2_kinematic_joint {
  .rotationAxis = { 0.0, 1.0, 0.0 },
  .parentToJoint = {
    .position = { 0.0, 0.0, 0.0 },
    .rotation = {
      0.0, 0.0, 0.0,
      0.0, 0.0, 0.0,
      0.0, 0.0, 0.0
    },
  }
};

constexpr KinematicJoint servo3_kinematic_joint {
  .rotationAxis = { 0.0, -1.0, 0.0 },
  .parentToJoint = {
    .position = { 0.0, 0.0, 0.0 },
    .rotation = {
      0.0, 0.0, 0.0,
      0.0, 0.0, 0.0,
      0.0, 0.0, 0.0
    },
  }
};

// constexpr KinematicJoint servo4_kinematic_joint {
//   .rotationAxis = { 0.0, 0.0, 0.0 },
//   .parentToJoint = {
//     .position = { 0.0, 0.0, 0.0 },
//     .rotation = {
//       0.0, 0.0, 0.0,
//       0.0, 0.0, 0.0,
//       0.0, 0.0, 0.0
//     },
//   }
// };
