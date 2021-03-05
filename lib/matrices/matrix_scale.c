/*
** EPITECH PROJECT, 2020
** matrices
** File description:
** scale
*/

#include <matrix.h>

void matrix_scale(matrix_t *matrix, sfVector3f scale)
{
    float matrix_scale[4][4] = {{scale.x, 0, 0, 0},
                                {0, scale.y, 0, 0},
                                {0, 0, scale.z, 0},
                                {0, 0, 0, 1}};

    matrix_multiply(matrix, matrix_scale);
}
