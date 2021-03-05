/*
** EPITECH PROJECT, 2020
** my_world
** File description:
** animation_reset
*/

#include <world.h>
#include <animations.h>
#include <distance.h>

static bool points_reset(map_t *map, size_t fps)
{
    float d = 0;
    bool is_finished = true;

    map->is_modified = true;
    for (size_t i = 0; i <= map->size.y; i++) {
        for (size_t j = 0; j <= map->size.x; j++) {
            d = dist(iso_point((sfVector3f){j, i, map->map_2d[i][j]}),
                    iso_point((sfVector3f){j, i, 0}));
            if (d > 0.5f)
                is_finished = false;
            if (map->map_2d[i][j] < 0)
                map->map_2d[i][j] += ((d * 2) / (float)fps);
            if (map->map_2d[i][j] > 0)
                map->map_2d[i][j] -= ((d * 2) / (float)fps);
        }
    }
    return (is_finished);
}

void animation_reset(void *w)
{
    world_t *world = w;

    if (!(world->animations >> RESET & 1)) {
        world->animations ^= 1 << RESET;
        return;
    }
    world->map->is_modified = true;
    if (points_reset(world->map, world->fps->nb))
        world->animations ^= 1 << RESET;
}
