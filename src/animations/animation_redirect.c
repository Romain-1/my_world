/*
** EPITECH PROJECT, 2020
** my_world
** File description:
** animation_redirect
*/

#include <animations.h>
#include <world.h>

void animation_redirect(world_t *world)
{
    if (world->animations >> VALLEY & 1)
        return (animation_valley(world));
    if (world->animations >> SWAPPING & 1)
        return (animation_swapping(world));
    if (world->animations >> WATER_DROP & 1)
        return (animation_water_drop(world));
    if (world->animations >> TWISTED & 1)
        return (animation_twisted(world));
    if (world->animations >> HOLE & 1)
        return (animation_hole(world));
    if (world->animations >> RESET & 1)
        return (animation_reset(world));
    if (world->animations >> PERLIN & 1)
        return (animation_perlin(world));
}
