#include "ForwardKinematics.h"

Pose Pose::zero() {
  return (Pose) {
    .position = {0.0, 0.0, 0.0},
    .rotation = {
      0.0, 0.0, 0.0,
      0.0, 0.0, 0.0,
      0.0, 0.0, 0.0,
    }
  };
}

Pose operator*(const Pose &a, const Pose &b) {
  return (Pose){
    .position = a.position + (b.position * b.rotation),
    .rotation = a.rotation * b.rotation,
  };
};

// TODO: implement
Pose ForwardKinematics::compute() {
  Pose base = Pose::zero();
  for (KinematicJoint joint : kinematicJoints) {
  }
  return base;
};
