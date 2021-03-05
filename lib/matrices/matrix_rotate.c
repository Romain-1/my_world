/*
** EPITECH PROJECT, 2020
** matrices
** File description:
** rotate
*/

#include <matrix.h>

void matrix_rotateX(matrix_t *matrix, float ang)
{
    float matriceX[4][4] = {{1, 0, 0, 0},
                            {0, cos(DEG_TO_RAD(ang)), -sin(DEG_TO_RAD(ang)), 0},
                            {0, sin(DEG_TO_RAD(ang)), cos(DEG_TO_RAD(ang)), 0},
                            {0, 0, 0, 1}};

    matrix_multiply(matrix, matriceX);
}

void matrix_rotateY(matrix_t *matrix, float ang)
{
    float matriceX[4][4] = {{cos(DEG_TO_RAD(ang)), 0, sin(DEG_TO_RAD(ang)), 0},
                            {0, 1, 0, 0},
                            {-sin(DEG_TO_RAD(ang)), 0, cos(DEG_TO_RAD(ang)), 0},
                            {0, 0, 0, 1}};

    matrix_multiply(matrix, matriceX);
}

void matrix_rotateZ(matrix_t *matrix, float ang)
{
    float matriceX[4][4] = {{cos(DEG_TO_RAD(ang)), -sin(DEG_TO_RAD(ang)), 0, 0},
                            {sin(DEG_TO_RAD(ang)), cos(DEG_TO_RAD(ang)), 0, 0},
                            {0, 0, 1, 0},
                            {0, 0, 0, 1}};

    matrix_multiply(matrix, matriceX);
}
