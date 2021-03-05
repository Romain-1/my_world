/*
** EPITECH PROJECT, 2020
** my_world
** File description:
** mouse
*/

#ifndef _MOUSE_H_
#define _MOUSE_H_

#include <world.h>
#include <stdbool.h>
#include <map.h>

#define ZOOM(delta) ((delta > 0) ? (0.9f) : (1.1f))

void mouse_hover_tile(map_t *, sfVector2i);
void mouse_hover_corner(world_t *, sfVector2i);
void mouse_events(world_t *);
void mouse_move_view(sfVector2i, sfView *, float);
void mouse_select_by_tiles(world_t *, sfVector2f, float);
void mouse_select_by_corners(world_t *, sfVector2f, float);
bool line_intersection(sfVector2f, sfVector2f, sfVector2f, sfVector2f);

#endif /* _MOUSE_H_ */
