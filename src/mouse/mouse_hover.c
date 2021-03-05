/*
** EPITECH PROJECT, 2020
** my_world
** File description:
** mouse_hover$
*/

#include <world.h>

void mouse_hover_corner(world_t *world, sfVector2i pos)
{
    sfCircleShape_setPosition(world->corner, world->map->map_iso[pos.y][pos.x]);
    sfCircleShape_setFillColor(world->corner, sfWhite);
}

void mouse_hover_tile(map_t *map, sfVector2i tile)
{
    int i = tile.y - map->selection_size / 2;
    int j = 0;
    sfColor color = {200, 200, 200, 100};

    for (; i <= tile.y + map->selection_size / 2; i++) {
        j = tile.x - map->selection_size / 2;
        for (; j <= tile.x + map->selection_size / 2; j++)
            if (i >= 0 && j >= 0 && i < map->size.y && j < map->size.x)
                sfConvexShape_setFillColor(map->convexes[i][j], color);
    }
}
