/*
** EPITECH PROJECT, 2020
** my_world
** File description:
** animation_hole
*/

#include <world.h>
#include <animations.h>

static bool point_calculate(map_t *map, int i, int j, float fps)
{
    double result = 0;
    sfVector2f pos;

    pos.x = (float)(j - map->size.x / 2) / 200.0f;
    pos.y = (float)(i - map->size.y / 2) / 200.0f;
    if (pos.x || pos.y)
        result = -1.0f / (pos.x * pos.x + pos.y * pos.y);
    else
        result = -100000.0f;
    if (map->map_2d[i][j] < result - 50.0f
        || map->map_2d[i][j] > result + 50.0f) {
        map->map_2d[i][j] += ((result - map->map_2d[i][j]) / fps);
        return (true);
    }
    return (false);
}

static bool points_modify(map_t *map, float fps)
{
    bool is_finished = true;

    for (int i = 0; i <= map->size.y; i++)
        for (int j = 0; j <= map->size.x; j++) {
            if (point_calculate(map, i, j, fps))
                is_finished = false;
        }
    return (is_finished);
}

void animation_hole(void *w)
{
    world_t *world = w;

    if (!(world->animations >> HOLE & 1)) {
        world->animations ^= 1 << HOLE;
    }
    if (points_modify(world->map, world->fps->nb)
        && (world->animations >> HOLE & 1)) {
        world->animations ^= 1 << HOLE;
    }
}
