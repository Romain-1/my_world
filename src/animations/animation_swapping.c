/*
** EPITECH PROJECT, 2020
** my_world
** File description:
** animation_valley
*/

#include <animations.h>
#include <world.h>
#include <map.h>

static int sign(float nb)
{
    return ((nb > 0) - (nb < 0));
}

static bool point_calculate(map_t *map, int i, int j, float time)
{
    float n = 2;
    float y = 0;
    float y2 = 0;
    sfVector2f pos;
    float result;

    pos.y = (float)(i - map->size.y / 2) / time * 10;
    pos.x = (float)(j - map->size.x / 2) / time * 10;
    y = sin(n * pos.x);
    y2 = cos(n * pos.y);
    map->map_2d[i][j] = (sign(y) + sign(y2)) * time;
}

static int points_modify(map_t *map, float time)
{
    for (int i = 0; i <= map->size.y; i++)
        for (int j = 0; j <= map->size.x; j++)
            point_calculate(map, i, j, time);
    return (time > 100);
}

void animation_swapping(void *w)
{
    world_t *world = w;
    static time_t prev_t = 0;
    time_t t = 0;

    if (!(world->animations >> SWAPPING & 1)) {
        world->animations ^= 1 << SWAPPING;
        prev_t = sfClock_getElapsedTime(world->fps->clock).microseconds;
    }
    t = sfClock_getElapsedTime(world->fps->clock).microseconds;
    if (points_modify(world->map, (float)(t - prev_t) / 50000.0f))
        world->animations ^= 1 << SWAPPING;
}
