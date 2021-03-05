/*
** EPITECH PROJECT, 2020
** my_world
** File description:
** animation_twisted
*/

#include <world.h>
#include <animations.h>

static void points_modify(map_t *map, float time)
{
    sfVector2f pos;
    float r = 0;

    for (int i = 0; i <= map->size.y; i++)
        for (int j = 0; j <= map->size.x; j++) {
            pos.x = (j - map->size.x / 2) / (time) / 2;
            pos.y = (i - map->size.y / 2) / (time) / 2;
            r = pow((pos.x * pos.x + pos.y * pos.y), 0.5f);
            map->map_2d[i][j] = 1.0f / (1.0f + r) *
                (pos.x * sin(4 * r) + pos.y * cos(4 * r)) * 100;
        }
}

void animation_twisted(void *w)
{
    world_t *world = w;
    static time_t prev_t = 0;
    time_t t = 0;

    if (!(world->animations >> TWISTED & 1)) {
        world->animations ^= 1 << TWISTED;
        prev_t = sfClock_getElapsedTime(world->fps->clock).microseconds;
    }
    t = sfClock_getElapsedTime(world->fps->clock).microseconds;
    points_modify(world->map, (float)(t - prev_t) / 500000.0f);
    if ((float)(t - prev_t) / 500000.0f > 17.0f) {
        world->animations ^= 1 << TWISTED;
        world->animations |= 1 << RESET;
    }
}
