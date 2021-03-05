/*
** EPITECH PROJECT, 2020
** my_world
** File description:
** map_modify
*/

#include <map.h>

static void tile_modify(map_t *map, int i, int j)
{
    sfVector3f p3d = {(j - map->size.x / 2) * TILE_SIZE.x,
                        (i - map->size.y / 2) * TILE_SIZE.y,
                        map->map_2d[i][j]};

    map->map_iso[i][j] = point_to_2d(map->matrix, p3d);
    sfConvexShape_setPoint(map->convexes[i][j], 0, map->map_iso[i][j]);
    p3d.x += TILE_SIZE.x;
    p3d.z = map->map_2d[i][j + 1];
    map->map_iso[i][j + 1] = point_to_2d(map->matrix, p3d);
    sfConvexShape_setPoint(map->convexes[i][j], 1, map->map_iso[i][j + 1]);
    p3d.y += TILE_SIZE.y;
    p3d.z = map->map_2d[i + 1][j + 1];
    map->map_iso[i + 1][j + 1] = point_to_2d(map->matrix, p3d);
    sfConvexShape_setPoint(map->convexes[i][j], 2, map->map_iso[i + 1][j + 1]);
    p3d.x -= TILE_SIZE.x;
    p3d.z = map->map_2d[i + 1][j];
    map->map_iso[i + 1][j] = point_to_2d(map->matrix, p3d);
    sfConvexShape_setPoint(map->convexes[i][j], 3, map->map_iso[i + 1][j]);
}

void map_modify(map_t *map)
{
    map_water_modify(map);
    for (int i = 0; i < map->size.y; i++)
        for (int j = 0; j < map->size.x; j++)
            tile_modify(map, i, j);
    map_ground_modify(map);
}
