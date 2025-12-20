#include "LinearAlgebra.h"

inline float angle_to_radians(float angle) {
    return (3.1415 / 180.0) * angle;
};

void Vector2f::add(const Vector2f &vec) {
  x += vec.x;
  y += vec.y;
};

void Vector2f::norm() { scale(1.0 / abs()); };

float Vector2f::abs() { return sqrt(x * x + y * y); };

void Vector2f::rotate(float angle) {
  angle = angle_to_radians(angle);
  Matrix2x2f rotation = {
    std::cos(angle), -std::sin(angle),
    std::sin(angle), std::cos(angle),
  };

  transform(rotation);
};

void Vector2f::scale(float scalar) {
  x *= scalar;
  y *= scalar;
};

void Vector2f::transform(const Matrix2x2f &transformation) {
    float new_x = transformation.m00 * x + transformation.m01 * y;
    float new_y = transformation.m10 * x + transformation.m11 * y;

    x = new_x;
    y = new_y;
};

void Vector3f::add(const Vector3f &vec) {
  x += vec.x;
  y += vec.y;
  z += vec.z;
};

void Vector3f::norm() { scale(1.0 / abs()); };

float Vector3f::abs() { return sqrt(x * x + y * y + z * z); };

void Vector3f::rotate(float angle) {
  angle = angle_to_radians(angle);

  // TODO: figure out rotation matrix for 3D
  Matrix3x3f rotation = {
    1, 0, 0,
    0, 1, 0,
    0, 0, 1,
  };

  transform(rotation);
};

void Vector3f::scale(float scalar) {
  x *= scalar;
  y *= scalar;
  z *= scalar;
};

void Vector3f::transform(const Matrix3x3f &transformation) {
    float new_x = transformation.m00 * x + transformation.m01 * y + transformation.m02 * z;
    float new_y = transformation.m10 * x + transformation.m11 * y + transformation.m12 * z;
    float new_z = transformation.m20 * x + transformation.m21 * y + transformation.m22 * z;

    x = new_x;
    y= new_y;
    z= new_z;
};
