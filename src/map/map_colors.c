/*
** EPITECH PROJECT, 2020
** my_world
** File description:
** map_colors
*/

#include <map.h>

static bool tile_compare(float **map_2d, size_t i, size_t j, float height)
{
    return (map_2d[i][j] > height
            && map_2d[i][j + 1] > height
            && map_2d[i + 1][j + 1] > height
            && map_2d[i + 1][j] > height);
}

static void change_tile_color(map_t *map, size_t i, size_t j)
{
    if (tile_compare(map->map_2d, i, j, SNOW_LEVEL)) {
        change_color_by_snow(map, i, j);
    } else if (!tile_compare(map->map_2d, i, j, -11.0f)) {
        change_color_by_dirt(map, i, j);
    } else {
        change_color_by_grass(map, i, j);
    }
}

void map_colors(map_t *map)
{
    float height = 0;

    for (size_t i = 0; i < map->size.y; i++)
        for (size_t j = 0; j < map->size.x; j++) {
            change_tile_color(map, i, j);
        }
}
