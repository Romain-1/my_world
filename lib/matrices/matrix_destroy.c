/*
** EPITECH PROJECT, 2020
** my_world
** File description:
** matrix_destroy
*/

#include <matrix.h>

void matrix_destroy(matrix_t *matrix)
{
    for (int i = 0; i < 4; i++)
        free(matrix->array[i]);
    free(matrix->array);
    free(matrix);
}
