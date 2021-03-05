/*
** EPITECH PROJECT, 2020
** matrices
** File description:
** matrix_reset
*/

#include <matrix.h>

void matrix_reset(matrix_t *matrix)
{
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            matrix->array[i][j] = (i == j);
}
