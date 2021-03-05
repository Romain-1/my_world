/*
** EPITECH PROJECT, 2020
** my_world
** File description:
** map_change_color
*/

#include <map.h>

void change_color_by_grass(map_t *map, size_t i, size_t j)
{
    sfColor grass = GRASS_COLOR;

    if (grass.g - map->map_2d[i][j] / 10.0f < 0) {
        grass.g = 0;
    } else
        grass.g -= map->map_2d[i][j] / 10.0f;
    if (map->mask >> COLORS & 1) {
        sfConvexShape_setFillColor(map->convexes[i][j], grass);
    } else if (map->mask >> TEXTURES & 1) {
        sfConvexShape_setFillColor(map->convexes[i][j], sfWhite);
    } else
        sfConvexShape_setFillColor(map->convexes[i][j], sfTransparent);
    if (map->mask >> TEXTURES & 1) {
        sfConvexShape_setTexture(map->convexes[i][j],
                                map->texture[GRASS], sfTrue);
    } else
        sfConvexShape_setTexture(map->convexes[i][j],
                                map->texture[SNOW], sfFalse);
}

void change_color_by_dirt(map_t *map, size_t i, size_t j)
{
    sfColor dirt = DIRT_COLOR;

    if (dirt.g + map->map_2d[i][j] / 3.0f < 0) {
        dirt.g = 0;
    } else
        dirt.g += map->map_2d[i][j] / 3.0f;
    if (map->mask >> COLORS & 1) {
        sfConvexShape_setFillColor(map->convexes[i][j], dirt);
    } else if (map->mask >> TEXTURES & 1) {
        sfConvexShape_setFillColor(map->convexes[i][j], sfWhite);
    } else
        sfConvexShape_setFillColor(map->convexes[i][j], sfTransparent);
    if (map->mask >> TEXTURES & 1) {
        sfConvexShape_setTexture(map->convexes[i][j],
                                map->texture[DIRT], sfTrue);
    } else
        sfConvexShape_setTexture(map->convexes[i][j],
                                map->texture[SNOW], sfFalse);
}

void change_color_by_snow(map_t *map, size_t i, size_t j)
{
    sfColor snow = SNOW_COLOR;

    if (snow.r - (map->map_2d[i][j] - SNOW_LEVEL) / 10.0f < 0) {
        snow = (sfColor){0, 0, snow.b, 255};
    } else {
        snow.r -= (map->map_2d[i][j] - SNOW_LEVEL) / 10.0f;
        snow.g -= (map->map_2d[i][j] - SNOW_LEVEL) / 10.0f;
    }
    if (map->mask >> COLORS & 1) {
        sfConvexShape_setFillColor(map->convexes[i][j], snow);
    } else if (map->mask >> TEXTURES & 1) {
        sfConvexShape_setFillColor(map->convexes[i][j], sfWhite);
    } else
        sfConvexShape_setFillColor(map->convexes[i][j], sfTransparent);
    if (map->mask >> TEXTURES & 1) {
        sfConvexShape_setTexture(map->convexes[i][j],
                                map->texture[SNOW], sfTrue);
    } else
        sfConvexShape_setTexture(map->convexes[i][j],
                                map->texture[SNOW], sfFalse);
}
