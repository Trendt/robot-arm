#ifndef FORWARD_KINEMATICS_H_
#define FORWARD_KINEMATICS_H_

#include "../joints/Joint.h"
#include "../util/LinearAlgebra.h"
#include <vector>

struct Pose {
  Vector3f position;
  Matrix3x3f rotation;

  static Pose zero();
};

Pose operator*(const Pose &a, const Pose &b);

struct KinematicJoint {
  Vector3f rotationAxis;
  Pose parentToJoint;
};

class ForwardKinematics {
public:
  ForwardKinematics(const std::vector<KinematicJoint> &kinematicJoints)
      : kinematicJoints(kinematicJoints) {};

  Pose compute();

private:
  const std::vector<KinematicJoint> &kinematicJoints;
};

#endif // !FORWARD_KINEMATICS_H_
