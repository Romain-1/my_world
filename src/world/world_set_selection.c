/*
** EPITECH PROJECT, 2020
** my_world
** File description:
** world_set_selection
*/

#include <world.h>

void world_set_select_corner(void *w)
{
    world_t *world = w;

    world->map->selection_size = -1;
}

void world_set_select_tiles(void *w)
{
    world_t *world = w;

    world->map->selection_size = 3;
}
