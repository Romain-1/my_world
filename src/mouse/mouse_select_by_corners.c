/*
** EPITECH PROJECT, 2020
** my_world
** File description:
** mouse_select_by_corners
*/

#include <mouse.h>
#include <world.h>
#include <distance.h>

static sfVector2i find_corner(map_t *map, sfVector2f mouse)
{
    sfVector2f pos = {mouse.x, mouse.y};
    sfVector2i tile = {-1, -1};
    float record = 50;
    float distance = 0.0f;

    for (int i = map->size.y; i >= 0; i--)
        for (int j = map->size.x; j >= 0; j--) {
            distance = dist(pos, map->map_iso[i][j]);
            if (record > distance) {
                record = distance;
                tile.x = j;
                tile.y = i;
            }
        }
    return (tile);
}

static void move_corner(map_t *map, sfVector2i corner, float move)
{
    map->map_2d[corner.y][corner.x] += move;
    map->is_modified = true;
}

void mouse_select_by_corners(world_t *world, sfVector2f mouse, float movement)
{
    sfVector2i corner = find_corner(world->map, mouse);

    world->map->selection_size = -1;
    if (corner.x == -1) {
        sfCircleShape_setFillColor(world->corner, sfTransparent);
        return;
    }
    mouse_hover_corner(world, corner);
    if (sfMouse_isButtonPressed(sfMouseLeft))
        move_corner(world->map, corner, movement);
    if (sfMouse_isButtonPressed(sfMouseRight))
        move_corner(world->map, corner, -movement);

}
