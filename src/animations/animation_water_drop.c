/*
** EPITECH PROJECT, 2020
** my_world
** File description:
** animation_water_drop
*/

#include <world.h>
#include <animations.h>

static void points_modify(map_t *map, float time)
{
    float radius = 0;
    sfVector2f pos;

    for (int i = 0; i <= map->size.y; i++) {
        for (int j = 0; j <= map->size.x; j++) {
            pos.x = (float)(j - map->size.x / 2) / time;
            pos.y = (float)(i - map->size.y / 2) / time;
            radius = pow((pos.x * pos.x + pos.y * pos.y), 0.5f);
            map->map_2d[i][j] = exp(-radius / 4) * sin(3 * radius) * 100;
        }
    }
}

void animation_water_drop(void *w)
{
    world_t *world = w;
    static time_t prev_t = 0;
    time_t t = 0;

    if (!(world->animations >> WATER_DROP & 1)) {
        prev_t = sfClock_getElapsedTime(world->fps->clock).microseconds;
        world->animations ^= 1 << WATER_DROP;
    }
    world->map->is_modified = true;
    t = sfClock_getElapsedTime(world->fps->clock).microseconds;
    points_modify(world->map, (float)(t - prev_t) / 100000.0f);
    if ((float)(t - prev_t) / 100000.0f > 45) {
        world->animations ^= 1 << WATER_DROP;
    }
}
