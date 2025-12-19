#ifndef JOINT_H_
#define JOINT_H_

class Joint {
public:
  virtual void setAngle(float angle) = 0;
  virtual float position() = 0;
  virtual void update(float dt) = 0;
  virtual void unstiff() = 0;
  virtual ~Joint() = default;
};

#endif // !JOINT_H_
