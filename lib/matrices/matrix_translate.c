/*
** EPITECH PROJECT, 2020
** matrices
** File description:
** translate
*/

#include <matrix.h>

void matrix_translate(matrix_t *matrix, sfVector3f translation)
{
    float matrix_translation[4][4] = {{1, 0, 0, translation.x},
                                        {0, 1, 0, translation.y},
                                        {0, 0, 1, translation.z},
                                        {0, 0, 0, 1}};

    matrix_multiply(matrix, matrix_translation);
}
