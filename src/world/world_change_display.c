/*
** EPITECH PROJECT, 2020
** my_world
** File description:
** world_change_display
*/

#include <world.h>
#include <map.h>

void world_change_colors(void *w)
{
    world_t *world = w;

    world->map->mask ^= 1 << COLORS;
    if (world->map->mask >> COLORS & 1) {
        for (int i = 0; i < 5; i++)
            sfConvexShape_setFillColor(world->map->ground[i], DIRT_COLOR);
    } else if (world->map->mask >> TEXTURES & 1) {
        for (int i = 0; i < 5; i++)
            sfConvexShape_setFillColor(world->map->ground[i], sfWhite);
    } else {
        for (int i = 0; i < 5; i++)
            sfConvexShape_setFillColor(world->map->ground[i], sfTransparent);
    }
}

void world_change_textures(void *w)
{
    world_t *world = w;

    world->map->mask ^= 1 << TEXTURES;
    if (world->map->mask >> TEXTURES & 1) {
        for (int i = 0; i < 5; i++)
            sfConvexShape_setTexture(world->map->ground[i],
                                    world->map->texture[DIRT], sfTrue);
    } else {
        for (int i = 0; i < 5; i++)
            sfConvexShape_setTexture(world->map->ground[i], NULL, sfTrue);
    }
    world->map->mask ^= 1 << COLORS;
    world_change_colors(world);
}

void world_change_water(void *w)
{
    world_t *world = w;

    world->map->mask ^= 1 << WATER;
    if (world->map->mask >> WATER & 1) {
        for (int i = 0; i < 5; i++) {
            sfConvexShape_setFillColor(world->map->water[i], sfTransparent);
            sfConvexShape_setOutlineColor(world->map->water[i], sfTransparent);
        }
    } else {
        for (int i = 0; i < 5; i++) {
            sfConvexShape_setFillColor(world->map->water[i], WATER_COLOR);
            sfConvexShape_setOutlineColor(world->map->water[i],
                                            WATER_OUT_COLOR);
        }
    }
}
