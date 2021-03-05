/*
** EPITECH PROJECT, 2020
** matrices
** File description:
** matrice_init
*/

#include <matrix.h>

matrix_t *matrix_create(void)
{
    matrix_t *new = malloc(sizeof(matrix_t));

    if (!new)
        return (NULL);
    new->lines = 4;
    new->columns = 4;
    for (size_t i = 0; i < 4; i++) {
        for (size_t j = 0; j < 4; j++)
            new->array[i][j] = (float)(i == j);
    }
    return (new);
}
