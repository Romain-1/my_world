/*
** EPITECH PROJECT, 2020
** my_world
** File description:
** animation_perlin
*/

#include <world.h>
#include <my_rand.h>

static void modify_points(world_t *world, unsigned int perm[256],
                            float res, sfVector2i *pos)
{
    float height = 0;

    for (int i = 0; i < 600.0f / world->fps->nb; i++) {
        if (pos->x > world->map->size.x)
            break;
        height = (perlin((sfVector2f){pos->x, pos->y}, res, perm));
        if (height > 0)
            height *= world->biome->upper_factor;
        else
            height *= world->biome->lower_factor;
        world->map->map_2d[pos->y][pos->x] = height +
            world->biome->ground_height;
        pos->x++;
    }
    if (pos->x > world->map->size.x) {
        pos->x = 0;
        pos->y++;
    }
}

static void permutation_table_reset(unsigned int perm[256], int seed)
{
    int j = 0;

    srand(seed);
    for (int i = 0; i < 256; i++)
        perm[i] = i;
    for (int k = 0; k < 5; k++)
        for (int i = 256; i >= 0; i--) {
            j = rand() % 256;
            perm[i] += perm[j];
            perm[j] = perm[i] - perm[j];
            perm[i] -= perm[j];
        }
}

void animation_perlin(void *w)
{
    world_t *world = w;
    static float resolution = 0;
    static unsigned int perm[256] = {0};
    static sfVector2i pos = {0, 0};

    if (!(world->animations >> PERLIN & 1)) {
        world->animations ^= 1 << PERLIN;
        pos = (sfVector2i){0, 0};
        permutation_table_reset(perm, world->map->seed);
        resolution = world->biome->resolution;
        return;
    }
    modify_points(world, perm, resolution, &pos);
    world->map->is_modified = true;
    if (pos.y > world->map->size.y)
        world->animations ^= 1 << PERLIN;
}
