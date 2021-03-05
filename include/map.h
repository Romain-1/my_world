/*
** EPITECH PROJECT, 2020
** my_world
** File description:
** map.h
*/

#ifndef _MAP_H_
#define _MAP_H_

#include <SFML/Graphics.h>
#include <matrix.h>
#include <stdbool.h>

#ifndef ABS
#define ABS(nb) ((nb < 0) ? (nb * -1) : (nb))
#endif /* ABS */

typedef struct map_s {
    bool is_modified;
    int selection_size;
    int seed;
    int mask;
    sfVector2i size;
    matrix_t *matrix;
    float **map_2d;
    sfVector2f **map_iso;
    sfTexture *texture[3];
    sfConvexShape ***convexes;
    sfConvexShape *ground[5];
    sfConvexShape *water[5];
} map_t;

enum mask {TEXTURES, COLORS, WATER};
enum textures {SNOW, GRASS, DIRT};

static const float SLOPE = 100.0f;
static const float SNOW_LEVEL = 1000.0f;
static const sfVector2i TILE_SIZE = {30, 30};
static const sfColor GRASS_COLOR = {57, 122, 41, 255};
static const sfColor STONE_COLOR = {158, 158, 158, 255};
static const sfColor SNOW_COLOR = {200, 200, 200, 255};
static const sfColor DIRT_COLOR = {147, 81, 22, 255};
static const sfColor WATER_COLOR = {31, 97, 141, 150};
static const sfColor WATER_OUT_COLOR = {31, 57, 80, 255};

map_t *map_load(char const *);
map_t *map_create(sfVector2i);
float **map_copy(map_t *);
void map_draw(sfRenderWindow *, map_t *);
void map_destroy(map_t *);
void map_modify(map_t *);
void map_colors(map_t *);
void map_ground_modify(map_t *);
void map_water_modify(map_t *);
void change_color_by_grass(map_t *, size_t, size_t);
void change_color_by_snow(map_t *, size_t, size_t);
void change_color_by_dirt(map_t *, size_t, size_t);

#endif /* _MAP_H_ */
