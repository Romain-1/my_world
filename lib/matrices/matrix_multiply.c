/*
** EPITECH PROJECT, 2020
** matrices
** File description:
** matrix_mutltiply
*/

#include <matrix.h>

sfVector3f matrix_multiply_point(matrix_t *m, sfVector3f p)
{
    float point[4] = {p.x, p.y, p.z, 1};
    float result[4] = {0, 0, 0, 0};

    for (size_t i = 0; i < 4; i++)
        for (size_t j = 0; j < 4; j++)
            result[i] += m->array[i][j] * point[j];
    p.x = result[0];
    p.y = result[1];
    p.z = result[2];
    return (p);
}

void matrix_multiply_line(matrix_t *m1, float m2[4][4],
    float result[4][4], size_t i)
{
    for (size_t j = 0; j < 4; j++)
        for (size_t k = 0; k < 4; k++)
            result[i][j] += m1->array[i][k] * m2[k][j];
}

void matrix_multiply(matrix_t *m1, float m2[4][4])
{
    float result[4][4] = {{0, 0, 0, 0},
                            {0, 0, 0, 0},
                            {0, 0, 0, 0},
                            {0, 0, 0, 0}};

    for (size_t i = 0; i < 4; i++)
        matrix_multiply_line(m1, m2, result, i);
    for (size_t i = 0; i < 4; i++)
        for (size_t j = 0; j < 4; j++)
            m1->array[i][j] = result[i][j];
}
