/*
** EPITECH PROJECT, 2020
** my_world
** File description:
** map_copy
*/

#include <map.h>

float **map_copy(map_t *map)
{
    float **new = malloc(sizeof(float *) * map->size.y);

    if (!new)
        return (NULL);
    for (int i = 0; i < map->size.y; i++) {
        new[i] = malloc(sizeof(float) * map->size.x);
        for (int j = 0; j < map->size.x; j++)
            new[i][j] = map->map_2d[i][j];
    }
    return (new);
}
