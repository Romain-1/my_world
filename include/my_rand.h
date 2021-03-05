/*
** EPITECH PROJECT, 2020
** my_rand
** File description:
** my_rand_h
*/

#ifndef _RAND_H_
#define _RAND_H_

#include <SFML/System/Vector2.h>

int rand_range(int, int);
float frand_range(int, int);
int rand_choose(int, int);
float perlin(sfVector2f, float, unsigned int [256]);

#endif /* _RAND_H_ */
