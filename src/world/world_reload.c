/*
** EPITECH PROJECT, 2020
** my_world
** File description:
** world_reload
*/

#include <world.h>
#include <saved.h>

void world_reload(void *w)
{
    world_t **world = w;
    world_t *new = NULL;
    char *map = NULL;

    map = load_loop();
    if (!map)
        return;
    world_destroy(*world);
    new = world_create(map);
    *world = new;
}
