/*
** EPITECH PROJECT, 2020
** my_world
** File description:
** animation_valley
*/

#include <animations.h>
#include <world.h>

static void points_modify(map_t *map, float time)
{
    float r = 0;
    sfVector2f pos;

    for (int i = 0; i <= map->size.y; i++)
        for (int j = 0; j <= map->size.x; j++) {
            pos.y = (float)(i - map->size.y / 2) / time;
            pos.x = (float)(j - map->size.x / 2) / time;
            r = pow((pos.x * pos.x + pos.y * pos.y), 0.5);
            map->map_2d[i][j] = (-1.0f / (pos.x * pos.x + 1.0f) +
                                2.0f / (pos.y * pos.y + 1) +
                                0.5f * sin(5 * r) / (r ? r : 1)) * -200;
        }
}

void animation_valley(void *w)
{
    world_t *world = w;
    static time_t prev_t = 0;
    time_t t = 0;

    if (!(world->animations >> VALLEY & 1)) {
        world->animations ^= 1 << VALLEY;
        prev_t = sfClock_getElapsedTime(world->fps->clock).microseconds;
    }
    t = sfClock_getElapsedTime(world->fps->clock).microseconds;
    points_modify(world->map, (float)(t - prev_t) / 1000000.0f);
    if ((float)(t - prev_t) / 1000000.0f > 10) {
        world->animations ^= 1 << VALLEY;
        world->animations |= 1 << RESET;
    }
}
