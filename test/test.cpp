#include "../src/util/LinearAlgebra.h"

#include <cstdio>

inline void print(Vector2f vec) { printf("(%f, %f), mag=%f\n", vec.x, vec.y, vec.abs()); };

int main () {
    Vector2f i = {1.0, 0.0};
    Vector2f j = {0.0, 1.0};

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
