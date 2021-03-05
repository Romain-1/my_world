/*
** EPITECH PROJECT, 2020
** my_world
** File description:
** world_modify_size
*/

#include <world.h>

void world_modify_size(void *w)
{
    world_t *world = w;
    float **prev_map = map_copy(world->map);
    sfVector2i prev_size = world->map->size;
    sfVector2i new_size = world->menu->map_size->size;
    map_t *new = map_create(new_size);
    int seed = world->map->seed;

    for (size_t i = 0; i < prev_size.y && i < new_size.y; i++) {
        for (size_t j = 0; j < prev_size.x && j < new_size.x; j++)
            new->map_2d[i][j] = prev_map[i][j];
        free(prev_map[i]);
    }
    free(prev_map);
    map_destroy(world->map);
    new->seed = seed;
    world->map = new;
}
