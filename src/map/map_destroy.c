/*
** EPITECH PROJECT, 2020
** my_world
** File description:
** map_destroy
*/

#include <map.h>

void map_destroy(map_t *map)
{
    free(map->matrix);
    for (int i = 0; i <= map->size.y; i++) {
        free(map->map_2d[i]);
        free(map->map_iso[i]);
    }
    free(map->map_2d);
    free(map->map_iso);
    for (int i = 0; i < map->size.y; i++) {
        for (int j = 0; j < map->size.x; j++)
            sfConvexShape_destroy(map->convexes[i][j]);
        free(map->convexes[i]);
    }
    for (int i = 0; i < 3; i++)
        sfTexture_destroy(map->texture[i]);
    for (int i = 0; i < 5; i++) {
        sfConvexShape_destroy(map->ground[i]);
        sfConvexShape_destroy(map->water[i]);
    }
    free(map->convexes);
    free(map);
}
