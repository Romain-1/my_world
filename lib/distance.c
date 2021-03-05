/*
** EPITECH PROJECT, 2020
** csfml
** File description:
** dist
*/

#include <distance.h>

float dist(sfVector2f a, sfVector2f b)
{
    return (sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2)));
}
