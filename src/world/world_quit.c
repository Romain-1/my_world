/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** world quit
*/

#include <world.h>

void world_quit(void *w)
{
    world_t *world = w;

    world_save(world);
    sfRenderWindow_close(world->window);
}
