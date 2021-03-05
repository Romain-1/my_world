/*
** EPITECH PROJECT, 2020
** my_world
** File description:
** ground_modify
*/

#include <map.h>

static void ground_follow_map(map_t *map, sfVector2i s)
{
    for (int i = 0; i <= map->size.x; i++) {
        sfConvexShape_setPoint(map->ground[0], i, map->map_iso[0][i]);
        sfConvexShape_setPoint(map->ground[2], i, map->map_iso[s.y][i]);
    }
    for (int i = 0; i <= map->size.y; i++) {
        sfConvexShape_setPoint(map->ground[1], i, map->map_iso[i][0]);
        sfConvexShape_setPoint(map->ground[3], i, map->map_iso[i][s.x]);
    }
}

static void ground_borders(map_t *map)
{
    sfVector3f p3d = {(0 - map->size.x / 2) * TILE_SIZE.x,
                        (0 - map->size.y / 2) * TILE_SIZE.y, -1000};
    sfVector2i s = map->size;
    matrix_t *m = map->matrix;

    ground_follow_map(map, s);
    sfConvexShape_setPoint(map->ground[0], s.x + 2, point_to_2d(m, p3d));
    sfConvexShape_setPoint(map->ground[1], s.y + 2, point_to_2d(m, p3d));
    p3d.x += map->size.x * TILE_SIZE.x;
    sfConvexShape_setPoint(map->ground[0], s.x + 1, point_to_2d(m, p3d));
    sfConvexShape_setPoint(map->ground[3], s.y + 2, point_to_2d(m, p3d));
    p3d.y += map->size.y * TILE_SIZE.y;
    sfConvexShape_setPoint(map->ground[2], s.x + 1, point_to_2d(m, p3d));
    sfConvexShape_setPoint(map->ground[3], s.y + 1, point_to_2d(m, p3d));
    p3d.x -= map->size.x * TILE_SIZE.x;
    sfConvexShape_setPoint(map->ground[2], s.x + 2, point_to_2d(m, p3d));
    sfConvexShape_setPoint(map->ground[1], s.y + 1, point_to_2d(m, p3d));
}

void map_ground_modify(map_t *map)
{
    sfVector3f p3d = {(0 - map->size.x / 2) * TILE_SIZE.x,
                        (0 - map->size.y / 2) * TILE_SIZE.y, -1000};

    sfConvexShape_setPoint(map->ground[4], 0, point_to_2d(map->matrix, p3d));
    p3d.x += map->size.x * TILE_SIZE.x;
    sfConvexShape_setPoint(map->ground[4], 1, point_to_2d(map->matrix, p3d));
    p3d.y += map->size.y * TILE_SIZE.y;
    sfConvexShape_setPoint(map->ground[4], 2, point_to_2d(map->matrix, p3d));
    p3d.x -= map->size.x * TILE_SIZE.x;
    sfConvexShape_setPoint(map->ground[4], 3, point_to_2d(map->matrix, p3d));
    ground_borders(map);
}
