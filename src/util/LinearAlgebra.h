#ifndef LINEAR_ALGEBRA_H_
#define LINEAR_ALGEBRA_H_

#include <cmath>

struct Matrix2x2f {
  float m[2][2];
  // float m00, m01;
  // float m10, m11;
};

struct Matrix3x3f {
  float m[3][3];
  // float m00, m01, m02;
  // float m10, m11, m12;
  // float m20, m21, m22;
};

Matrix3x3f operator*(const Matrix3x3f &a, const Matrix3x3f &b);

struct Vector2f {
  float x, y;

  void add(const Vector2f &vec);
  void rotate(float angle);
  void scale(float scalar);
  void norm();
  float abs();
  void transform(const Matrix2x2f &transformation);
};

struct Vector3f {
  float x, y, z;

  void add(const Vector3f &vec);
  void rotate(float angle);
  void scale(float scalar);
  void norm();
  float abs();
  void transform(const Matrix3x3f &transformation);
};

Vector3f operator+(const Vector3f &a, const Vector3f &b);
Vector3f operator*(const Vector3f &a, const Matrix3x3f &M);

#endif // !LINEAR_ALGEBRA_H_
