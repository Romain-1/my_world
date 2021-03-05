/*
** EPITECH PROJECT, 2020
** my_world
** File description:
** map_water_modify
*/

#include <map.h>

static void water_borders2(map_t *map, sfVector3f p3d)
{
    sfConvexShape_setPoint(map->water[2], 2, point_to_2d(map->matrix, p3d));
    sfConvexShape_setPoint(map->water[3], 3, point_to_2d(map->matrix, p3d));
    p3d.z = -1.0f;
    sfConvexShape_setPoint(map->water[2], 1, point_to_2d(map->matrix, p3d));
    sfConvexShape_setPoint(map->water[3], 0, point_to_2d(map->matrix, p3d));
    p3d.x += map->size.x * TILE_SIZE.x;
    sfConvexShape_setPoint(map->water[3], 1, point_to_2d(map->matrix, p3d));
    sfConvexShape_setPoint(map->water[4], 0, point_to_2d(map->matrix, p3d));
    p3d.z = -1000.0f;
    sfConvexShape_setPoint(map->water[3], 2, point_to_2d(map->matrix, p3d));
    sfConvexShape_setPoint(map->water[4], 3, point_to_2d(map->matrix, p3d));
}

static void water_borders1(map_t *map)
{
    sfVector3f p3d = {(-map->size.x / 2) * TILE_SIZE.x,
                        (-map->size.y / 2) * TILE_SIZE.y, -1};

    sfConvexShape_setPoint(map->water[1], 0, point_to_2d(map->matrix, p3d));
    sfConvexShape_setPoint(map->water[2], 0, point_to_2d(map->matrix, p3d));
    p3d.x += map->size.x * TILE_SIZE.x;
    sfConvexShape_setPoint(map->water[1], 1, point_to_2d(map->matrix, p3d));
    sfConvexShape_setPoint(map->water[4], 1, point_to_2d(map->matrix, p3d));
    p3d.z = -1000.0f;
    sfConvexShape_setPoint(map->water[1], 2, point_to_2d(map->matrix, p3d));
    sfConvexShape_setPoint(map->water[4], 2, point_to_2d(map->matrix, p3d));
    p3d.x -= map->size.x * TILE_SIZE.x;
    sfConvexShape_setPoint(map->water[1], 3, point_to_2d(map->matrix, p3d));
    sfConvexShape_setPoint(map->water[2], 3, point_to_2d(map->matrix, p3d));
    p3d.y += map->size.y * TILE_SIZE.y;
    water_borders2(map, p3d);
}

void map_water_modify(map_t *map)
{
    sfVector3f p3d = {(-map->size.x / 2) * TILE_SIZE.x,
                        (-map->size.y / 2) * TILE_SIZE.y, -1};

    sfConvexShape_setPoint(map->water[0], 0, point_to_2d(map->matrix, p3d));
    p3d.x += map->size.x * TILE_SIZE.x;
    sfConvexShape_setPoint(map->water[0], 1, point_to_2d(map->matrix, p3d));
    p3d.y += map->size.y * TILE_SIZE.y;
    sfConvexShape_setPoint(map->water[0], 2, point_to_2d(map->matrix, p3d));
    p3d.x -= map->size.x * TILE_SIZE.x;
    sfConvexShape_setPoint(map->water[0], 3, point_to_2d(map->matrix, p3d));
    water_borders1(map);
}
