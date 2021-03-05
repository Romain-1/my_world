/*
** EPITECH PROJECT, 2020
** matrix
** File description:
** matrix.h
*/

#ifndef _MATRIX_H_
#define _MATRIX_H_

#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SFML/System/Vector2.h>
#include <SFML/System/Vector3.h>

#define DEG_TO_RAD(nb) (nb * M_PI / 180.0f)

typedef struct matrix_s {
    size_t lines;
    size_t columns;
    float array[4][4];
} matrix_t;

matrix_t *matrix_create(void);
void matrix_reset(matrix_t *);
void matrix_multiply(matrix_t *, float [4][4]);
sfVector3f matrix_multiply_point(matrix_t *, sfVector3f);
void matrix_translate(matrix_t *, sfVector3f);
void matrix_scale(matrix_t *, sfVector3f);
void matrix_rotateX(matrix_t *, float);
void matrix_rotateY(matrix_t *, float);
void matrix_rotateZ(matrix_t *, float);
void matrix_destroy(matrix_t *);
sfVector2f iso_point(sfVector3f);
sfVector2f point_to_2d(matrix_t *, sfVector3f);

#endif /* _MATRIX_H_ */
