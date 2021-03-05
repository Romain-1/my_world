/*
** EPITECH PROJECT, 2020
** my_world
** File description:
** map_create
*/

#include <map.h>
#include <SFML/Graphics.h>
#include <my_rand.h>

static int convexes_create(map_t *map)
{
    map->convexes = malloc(sizeof(sfConvexShape **) * map->size.y);
    if (!map->convexes)
        return (1);
    for (size_t i = 0; i < map->size.y; i++) {
        map->convexes[i] = malloc(sizeof(sfConvexShape *) * map->size.x);
        if (!map->convexes[i])
            return (1);
        for (size_t j = 0; j < map->size.x; j++) {
            map->convexes[i][j] = sfConvexShape_create();
            if (!map->convexes[i][j])
                return (1);
            sfConvexShape_setPointCount(map->convexes[i][j], 4);
            sfConvexShape_setOutlineThickness(map->convexes[i][j], 1);
            sfConvexShape_setOutlineColor(map->convexes[i][j],
                                        (sfColor){220, 220, 220, 150});
        }
    }
    return (0);
}

static int map_2d_create(map_t *map)
{
    map->texture[GRASS] = sfTexture_createFromFile
        ("resources/textures/grass.png", NULL);
    map->texture[SNOW] = sfTexture_createFromFile
        ("resources/textures/snow.jpg", NULL);
    map->texture[DIRT] = sfTexture_createFromFile
        ("resources/textures/dirt.png", NULL);
    map->map_2d = malloc(sizeof(float *) * (map->size.y + 1));
    map->map_iso = malloc(sizeof(sfVector2f *) * (map->size.y + 1));
    if (!map->map_2d || !map->map_iso)
        return (1);
    for (size_t i = 0; i <= map->size.y; i++) {
        map->map_2d[i] = malloc(sizeof(float) * (map->size.x + 1));
        map->map_iso[i] = malloc(sizeof(sfVector2f) * (map->size.x + 1));
        if (!map->map_2d[i] || !map->map_iso[i])
            return (1);
        for (size_t j = 0; j <= map->size.x; j++)
            map->map_2d[i][j] = 0;
    }
    return (0);
}

static void map_water_create(map_t *map)
{
    for (int i = 0; i < 5; i++) {
        map->water[i] = sfConvexShape_create();
        sfConvexShape_setPointCount(map->water[i], 4);
        sfConvexShape_setFillColor(map->water[i], WATER_COLOR);
        sfConvexShape_setOutlineColor(map->water[i], WATER_OUT_COLOR);
        sfConvexShape_setOutlineThickness(map->water[i], 1);
    }
}

static void map_ground_create(map_t *map)
{
    sfColor color1 = {110, 44, 0, 255};
    sfColor color2 = {120, 54, 0, 255};
    sfColor outline = {220, 220, 220, 150};

    for (int i = 0; i < 2; i++) {
        map->ground[i * 2] = sfConvexShape_create();
        sfConvexShape_setPointCount(map->ground[i * 2], map->size.x + 3);
        sfConvexShape_setFillColor(map->ground[i * 2], color1);
        map->ground[i * 2 + 1] = sfConvexShape_create();
        sfConvexShape_setPointCount(map->ground[i * 2 + 1], map->size.y + 3);
        sfConvexShape_setFillColor(map->ground[i * 2 + 1], color2);
    }
    map->ground[4] = sfConvexShape_create();
    sfConvexShape_setPointCount(map->ground[4], 4);
    sfConvexShape_setFillColor(map->ground[4], DIRT_COLOR);
    for (int i = 0; i < 5; i++) {
        sfConvexShape_setOutlineThickness(map->ground[i], 1);
        sfConvexShape_setOutlineColor(map->ground[i], outline);
        sfConvexShape_setTexture(map->ground[i], map->texture[DIRT], sfTrue);
    }
}

map_t *map_create(sfVector2i map_size)
{
    map_t *map = malloc(sizeof(map_t));

    if (!map)
        return (NULL);
    map->mask = 0b11;
    map->seed = rand();
    map->selection_size = 3;
    map->size = map_size;
    map->is_modified = false;
    if (map_2d_create(map))
        return (NULL);
    if (convexes_create(map))
        return (NULL);
    map->matrix = matrix_create();
    if (!map->map_2d || !map->matrix)
        return (NULL);
    map_water_create(map);
    map_ground_create(map);
    return (map);
}
