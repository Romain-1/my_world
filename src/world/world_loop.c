/*
** EPITECH PROJECT, 2020
** my_world
** File description:
** world_loop
*/

#include <world.h>
#include <saved.h>

int world_loop(char const *file)
{
    world_t *world = world_create(file ? file : load_loop());

    if (!world)
        return (84);
    if (world->sound_effects && world->sound_effects->music)
        sfMusic_play(world->sound_effects->music);
    while (sfRenderWindow_isOpen(world->window)) {
        if (sfRenderWindow_hasFocus(world->window)) {
            world_draw(world);
            map_colors(world->map);
            world_events(&world);
        }
    }
    world_destroy(world);
    return (0);
}
