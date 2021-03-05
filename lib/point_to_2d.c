/*
** EPITECH PROJECT, 2020
** my_world
** File description:
** 3d_to_2d
*/

#include <matrix.h>

sfVector2f point_to_2d(matrix_t *matrix, sfVector3f point)
{
    return (iso_point(matrix_multiply_point(matrix, point)));
}
