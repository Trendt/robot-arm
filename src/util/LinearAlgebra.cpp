#include "LinearAlgebra.h"

// TODO: cleanup

inline float angle_to_radians(float angle) {
    return (3.1415 / 180.0) * angle;
};

Matrix3x3f operator*(const Matrix3x3f &a, const Matrix3x3f &b) {
  Matrix3x3f result;

  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      result.m[i][j] =
          a.m[i][0] * b.m[0][j] +
          a.m[i][1] * b.m[1][j] +
          a.m[i][2] * b.m[2][j];
    }
  }

  return result;
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
    float new_x = transformation.m[0][0] * x + transformation.m[0][1] * y;
    float new_y = transformation.m[1][0] * x + transformation.m[1][1] * y;

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
    float new_x = transformation.m[0][0] * x + transformation.m[0][1] * y + transformation.m[0][2] * z;
    float new_y = transformation.m[1][0] * x + transformation.m[1][1] * y + transformation.m[1][2] * z;
    float new_z = transformation.m[2][0] * x + transformation.m[2][1] * y + transformation.m[2][2] * z;

    x = new_x;
    y= new_y;
    z= new_z;
};

Vector3f operator+(const Vector3f &a, const Vector3f &b) {
  return (Vector3f){a.x + b.x, a.y + b.y, a.z + b.z};
};

Vector3f operator*(const Vector3f &a, const Matrix3x3f &M) {
  Vector3f result = {a.x, a.y, a.z};
  result.transform(M);

  return result;
};
