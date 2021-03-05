/*
** EPITECH PROJECT, 2020
** my_world
** File description:
** mouse_events
*/

#include <stdbool.h>
#include <mouse.h>

void mouse_events(world_t *world)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(world->window);
    sfVector2f world_pos = sfRenderWindow_mapPixelToCoords(world->window, mouse,
                                                            world->view_map);
    float movement = 200.0f / world->fps->nb;

    mouse_move_view(mouse, world->view_map, world->fps->nb);
    if (sfKeyboard_isKeyPressed(sfKeyLShift))
        movement *= 5;
    if (world->map->selection_size > 0) {
        mouse_select_by_tiles(world, world_pos, movement);
    } else
        mouse_select_by_corners(world, world_pos, movement);
}
