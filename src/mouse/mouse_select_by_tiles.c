/*
** EPITECH PROJECT, 2020
** my_world
** File description:
** mouse_select_by_tiles
*/

#include <stdbool.h>
#include <mouse.h>

static bool is_in_tile(map_t *map, sfVector2f mouse, int i, int j)
{
    sfVector2f target = {mouse.x + 20, mouse.y};
    int counter = 0;

    if (line_intersection(map->map_iso[i][j], map->map_iso[i][j + 1],
                            mouse, target))
        counter++;
    if (line_intersection(map->map_iso[i][j + 1], map->map_iso[i + 1][j + 1],
                            mouse, target))
        counter++;
    if (line_intersection(map->map_iso[i + 1][j + 1], map->map_iso[i + 1][j],
                            mouse, target))
        counter++;
    if (line_intersection(map->map_iso[i + 1][j], map->map_iso[i][j],
                            mouse, target))
        counter++;
    return (counter & 1 && counter > 0);
}

static sfVector2i find_tile(map_t *map, sfVector2f mouse)
{
    for (int i = map->size.y - 1; i >= 0; i--)
        for (int j = map->size.x - 1; j >= 0; j--)
            if (is_in_tile(map, mouse, i, j))
                return ((sfVector2i){j, i});
    return ((sfVector2i){-1, -1});
}

static void move_tiles(map_t *map, sfVector2i pos, float move)
{
    int i = pos.y - map->selection_size / 2;
    int j = 0;

    for (; i <= pos.y + map->selection_size / 2 + 1; i++) {
        j = pos.x - map->selection_size / 2;
        for (; j <= pos.x + map->selection_size / 2 + 1; j++) {
            if (i >= 0 && j >= 0 && i <= map->size.y && j <= map->size.x)
                map->map_2d[i][j] += move;
            else
                continue;
            if (map->map_2d[i][j] < -1000.0f)
                map->map_2d[i][j] = -1000.0f;
        }
    }
}

void mouse_select_by_tiles(world_t *world, sfVector2f mouse, float movement)
{
    sfVector2i tile = find_tile(world->map, mouse);

    if (tile.x == -1)
        return;
    mouse_hover_tile(world->map, tile);
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        move_tiles(world->map, tile, movement);
        sfSound_play(world->sound_effects->sound[PLACED]);
        world->map->is_modified = true;
    }
    if (sfMouse_isButtonPressed(sfMouseRight)) {
        move_tiles(world->map, tile, -movement);
        sfSound_play(world->sound_effects->sound[PLACED]);
        world->map->is_modified = true;
    }
}
