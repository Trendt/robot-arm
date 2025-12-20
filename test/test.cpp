#include "../src/util/LinearAlgebra.h"

#include <cstdio>

inline void print(Vector2f vec) { printf("(%f, %f), mag=%f\n", vec.x, vec.y, vec.abs()); };
inline void print(Vector3f vec) { printf("(%f, %f, %f), mag=%f\n", vec.x, vec.y, vec.z, vec.abs()); };

// TODO: test math stuff 'properly'

int main () {
    Vector2f i = {1.0, 0.0};
    Vector3f j = {0.0, 1.0};

    i.scale(3.591);
    j.scale(591.123981);

    printf("i_hat: ");
    print(i);
    printf("j_hat: ");
    print(j);

    i.rotate(90.0);
    j.rotate(90.0);

    printf("i_hat rotated: ");
    print(i);
    printf("j_hat rotated: ");
    print(j);
    printf("j_hat rotated + (20.0, 5.0, 0.0): ");
    Vector3f test = (Vector3f){20.0, 5.0, 0.0};
    Vector3f n = j + test;
    print(n);

    i.norm();
    j.norm();

    i.rotate(45.0);
    j.rotate(45.0);

    printf("i_hat norm: ");
    print(i);
    printf("j_hat norm: ");
    print(j);

    return 0;
}
