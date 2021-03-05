/*
** EPITECH PROJECT, 2020
** my_world
** File description:
** world_destroy
*/

#include <world.h>

void world_destroy(world_t *world)
{
    map_destroy(world->map);
    sound_effects_destroy(world->sound_effects);
    sfView_destroy(world->view_ui);
    sfView_destroy(world->view_map);
    sfRenderWindow_destroy(world->window);
    free(world);
}
